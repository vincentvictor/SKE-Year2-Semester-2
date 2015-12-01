package firstgen.pos;
import java.util.ArrayList;
import java.util.List;

import extern.tax.LameTax;
import firstgen.domain.*;
import firstgen.store.ProductCatalog;
import firstgen.store.Store;

/** 
 * The register is the external interface to the POS,
 *  as seen by the cashier.
 */
public class Register implements POSInterface {
	
	private Sale sale = null; // a Sale object records items in this sales transaction
	private Store store;
	private ProductCatalog productCatalog;
	private List<SaleViewer> saleviewers;
//TODO fix this lame code.  fix the setTaxCalculator method, too.
	private Object taxCalculator = new LameTax();

	public Register() {
		saleviewers = new ArrayList<SaleViewer>();
	}
	
	/**
	 * @see nextgen.pos.POSInterface#addItem(java.lang.String, int)
	 */
	public Product addItem(String id, int quantity) {
		// the store should be set before any sale begins
		assert store != null : "Store has not been set in Register";
		assert productCatalog != null : "ProductCatalog has not been set in Register";

		if ( sale == null ) startSale();
		Product pd = productCatalog.getProduct( id );
		if (pd == null) return null; // product not found
		sale.addItem( pd, quantity );
		return pd;
	}

	/**
	 * @see nextgen.pos.POSInterface#getSubtotal()
	 */
	public double getSubtotal() {
		if ( sale == null ) return 0.0;
		return sale.getSubtotal();
	}

	/**
	 * @see nextgen.pos.POSInterface#getTotal()
	 */
	public double getTotal() {
		if ( sale == null ) return 0.0;
		return sale.getTotal();
	}

	/**
	 * @see nextgen.pos.POSInterface#removeItem(java.lang.String, int)
	 */
	public boolean removeItem(String id, int quantity) {
		if ( sale == null ) return false;
		return sale.removeItem( id, quantity );
	}

	/**
	 * @see nextgen.pos.POSInterface#startNewSale()
	 */
	public void startSale() {
		Sale sale = new Sale();
		sale.setTaxCalculator(taxCalculator);
		setSale( sale );
	}

	/**
	 * @see nextgen.pos.POSInterface#startNewSale(java.lang.String)
	 */
	public void startSale(String customerID) {
		sale = new Sale( /*customerID*/ );
		sale.setTaxCalculator(taxCalculator);
		setSale( sale );
	}

	public void setStore( Store store ) {
		this.store = store;
		productCatalog = store.getProductCatalog();
//TODO tax calculator
	}

	/**
	 * @see nextgen.pos.POSInterface#startNewSale()
	 */
	public Sale getSale() {
		return sale;
	}

	public void addSaleViewer(SaleViewer view) {
		if ( !saleviewers.contains(view) ) {
			saleviewers.add(view);
			view.setSale(sale);
		}
	}
	
	/**
	 * internal method to set the sale also updates the sale
	 * in all saleviews. 
	 * @param sale the current sale
	 */
	private void setSale(Sale sale) {
		this.sale = sale;
		for(SaleViewer view: saleviewers ) view.setSale(sale);
	}

	public void endSale() {
		// TODO prompt for payment
	}
}