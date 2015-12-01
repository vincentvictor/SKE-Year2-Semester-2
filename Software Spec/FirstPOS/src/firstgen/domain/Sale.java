package firstgen.domain;
import java.util.*;
import extern.tax.*;

import org.apache.log4j.Logger;

/** A Sale contains information about a sales transaction,
 *  including customer, date, list of items purchased, tax,
 *  and discounts.
 *  It has methods to compute and return the total price.
 *  
 * @author James Brucker
 */
public class Sale extends Observable implements Iterable<LineItem> {
	private long id;  // id of this sale
	private Calendar date; // date of the sale
	private List<LineItem> items; // items in the sale
//TODO fix this
	private Object taxCalculator;

	private static Logger logger = Logger.getLogger( Sale.class );
		
	/** create a new sale with unknown customer */
	public Sale( ) {
		items = new ArrayList<LineItem>( );
		date = Calendar.getInstance(); // maybe updated when the sale ends?
		id = 0;
	}
	
	/**
	 * Set the tax calculator.
	 * @param calculator is the tax calculator to use
	 */
	public void setTaxCalculator(Object calculator) {
		this.taxCalculator = calculator;
	}
	
	
	/** Get the tax on the sale so far.
	 * @return tax applicable to the sales items.
	 */
	public double getTax( ) {
		double tax = 0;
		if ( taxCalculator instanceof TurboTax ) {
			TurboTax calc = (TurboTax) taxCalculator;
			tax = calc.getTax( items );
		}
		else if ( taxCalculator instanceof LameTax ) {
			LameTax calc = (LameTax) taxCalculator;
			// subtotal does not include tax
			tax = calc.getTax( this.getSubtotal() );
		}
		else logger.error("Unknown Tax Calculator type " + taxCalculator);
		return tax;
	}
	
	
	/** End a sale.  
	 * Apply any logic that should be performed at end of a Sale,
	 * such as applying discounts.
	 */
	public void endSale( ) {
		// do anything required at end of sale, such as applying discounts.
	}
	
	/** add an item to the current sale.
	 * @param pd is the description of the item to add
	 * @param quantity is the quantity of the item to add
	 * @return true if item added successfully to sale.
	 */
	public boolean addItem( Product pd, int quantity ) {
		logger.debug("adding item = " + pd);
		if ( pd == null ) {
			logger.warn("attempt to add null item to sale");
			return false;
		}
		if ( quantity == 0 ) {
			logger.warn("attempt to add item with quantity 0");
			return false;
		}
		if ( quantity < 0 ) {
			logger.error("attempt to add item with quantity < 0");
			return false;
		}
		
		// if Product is already a LineItem, then just add to quantity
		for( int k = items.size()-1; k >= 0; k--) {
			LineItem lineItem = items.get(k);
			final String itemId = lineItem.getProductId();
			if ( pd.productId.equals( itemId ) )
			{
				lineItem.setQuantity( lineItem.getQuantity() + quantity );
				setChangedAndNotifyObservers();
				return true;
			}
		}
		// if you get here, then this product is not in sale yet.
		LineItem saleItem = new LineItem( pd, quantity );
		// this should always succeed (true)
		boolean result = items.add( saleItem );

		setChangedAndNotifyObservers();
		return result;
	}
	
	/** delete an item from the current sale.
	 * @param itemId is the ID of the item to delete
	 * @param quantity is the quantity of the item to delete
	 * @return true if the item was deleted from the sale
	 * @precondition itemID is not null
	 */
	public boolean removeItem( String itemId, int quantity ) {
		assert itemId != null : "Null itemID in removeItem";
		if ( quantity <= 0 ) {
			logger.error("Attempt to remove quantity = "+quantity);
			// could be simple UI problem, so return normally
			return false;
		}
		// count how many units of this item are in the sale
		int count = 0;
		for( LineItem sli : items ) 
			if ( itemId.equals( sli.getProductId() ) ) count += sli.getQuantity();
		if ( count < quantity ) return false; // not enough units to delete
		// now work backwards through the list deleting units.
		for( int k = items.size()-1; k >= 0; k--) {
			LineItem sli = items.get(k);
			if ( !  itemId.equals( sli.getProductId() ) ) continue;
			if ( sli.getQuantity() <= quantity ) {
				// this salesLineItem has fewer units than we need to delete,
				// so delete the entire item!
				quantity -= sli.getQuantity();
				items.remove(k);
				if ( quantity <= 0 ) break;
			}
			else {
				// this salesLineItem has more units than we need to delete,
				// so just reduce the quantity.  Then break out of loop.
				sli.setQuantity( sli.getQuantity() - quantity );
				quantity = 0;
				break;
			}
		}
		setChangedAndNotifyObservers();
 		return true; // return true so cashier knows its OK to remove 
 					 // these items from the sales basket.
	}
	
	/** get the total value of the sale so far, without tax or discount.
	 * @return gross sale total so far, without tax or discount.
	 */
	public double getSubtotal( ) {
		double subtotal = 0;
		for( LineItem item : items ) subtotal += item.getTotal();
		return subtotal;
	}

	
	/** get the total value of the sale, net of tax and discount.
	 * @return gross sale total so far, with tax or discount.
	 */
	public double getTotal( ) {
		double subtotal = getSubtotal();
		double tax = getTax();
		return (subtotal + tax);
	}

	/** Create and return an iterator of the sale items.
	 * Note that if the contents of the sale change after creating
	 * an iterator that the Iterator will probably be invalid and
	 * may throw exception if used. 
	 * @return an Iterator of items in this sale
	 */
	public Iterator<LineItem> iterator() {
		return items.iterator();
	}
	/** Return the number of items in the sale.
	 * @return number of items in the sale.
	 */
	public int size() {
		return items.size();
	}
	/**
	 * Get the k-th item in the list of sale items
	 * @param k is index of item to get
	 * @return the k-th item in this Sale
	 */
	public LineItem getLineItem(int k) {
		if ( k >= 0 && k < items.size() ) return items.get(k);
		else return null;
	}

	/**
	 * Get the date that the sale was made.  This is the date that the
	 * sale object was created.
	 * @return the date of this sale
	 */
	public Calendar getDate() {
		return date;
	}
	
	private void setChangedAndNotifyObservers() {
		super.setChanged();
		super.notifyObservers();
	}

	/**
	 * Get the id of this sale.
	 * @return the id
	 */
	public long getId() {
		return id;
	}

	/**
	 * Set the id of this sale.
	 * @param id the id for this sale
	 */
	public void setId(long id) {
		this.id = id;
	}
}
