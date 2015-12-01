package firstgen.domain;

import java.io.Serializable;

/** 
 * LineItem is an item included in a sales transaction.
 * It contains a Product and a quantity.
 */
public class LineItem implements Serializable {
	private static final long serialVersionUID = 1L;
	/** quantity of the LineItem in this sale */
	protected int quantity;
	/** the line item */
	protected Product product;

	/** Create a new LineItem for buying 1 unit of a Product
	 * @param pd is the Product that is being purchased
	 */
	public LineItem(Product pd) {
		this( pd, 1);
	}

	/** Create a new LineItem for buying a quantity of a product.
	 * @param pd is the Product that is being purchased
	 * @param quantity is the number of units of the Product in purchase
	 */
	public LineItem(Product pd, int quantity) {
		this.product = pd;
		this.quantity = quantity;
	}
	
	/** Return the gross price of this LineItem.
	 * This is the quantity times the price of the LineItem.
	 * @return the gross price of this LineItem, without tax or discount.
	 */
	public double getTotal() {
		return quantity * product.getPrice();
	}

	/** Get the number of units of the LineItem in this sales item.
	 * @return the number of units of the LineItem in this sales item.
	 */
	public int getQuantity() {
		return quantity;
	}

	/** Set the number of units of the LineItem in this sales item.
	 * @param quantity the new number of LineItem units in this sales item.
	 * @prerequisite the quantity is not negative
	 */
	public void setQuantity(int quantity) {
		this.quantity = quantity;
	}
	
	/** compare two SalesLineItems.  They are equal only if the LineItem AND quantity
	 *  are the same.
	 *  @param obj is another LineItem to compare to this one
	 */
	public boolean equals( Object obj ) {
		if ( !( obj instanceof LineItem ) ) return false;
		LineItem other = (LineItem)obj;
		return quantity == other.getQuantity() && product.equals(other.getProduct());
	}
	/** 
	 * Get description of this LineItem.
	 * Normally this is the description of the product.
	 * @return description of the item
	 */
	public String getDescription() {
		return product.getDescription();
	}
	
	/**
	 * Get the unit price of products in this LineItem.
	 * The unit price is the base price, before applying discounts.
	 * @return unit price of product in this LineItem
	 */
	public double getUnitPrice() {
		return product.getPrice();
	}

	/** Get string description of the item in this SalesLineItem
	 * @return the item
	 */
	public String toString() {
		return product.getDescription();
	}

	/**
	 * Get a reference to the item descriptor of this LineIitem
	 * @return Item descriptor of this line item
	 */
	protected Product getProduct() {
		return product;
	}
	
	protected void setProduct(Product pd) {
		this.product = pd;
	}
	
	/**
	 * Get the id of the product represented by this lineitem.
	 * @return product ID of product for this line item
	 */
	public String getProductId() {
		return product.getProductId();
	}
}
