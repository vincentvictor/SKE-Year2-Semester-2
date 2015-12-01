package firstgen.store;

import org.apache.log4j.Logger;

import firstgen.domain.Sale;
import firstgen.store.impl.MemoryProductCatalog;

/** 
 * The store acts as a provider for ProductCatalog and other 
 * components that belong to a Store.
 * 
 * TODO 
 * Make the Store be a singleton with lazy instantiation.  
 * The singleton accessor method name is getInstance().
 * It should be impossible for other classes to invoke "new Store()".
 */
public class Store {
	/** Logger for this class */
	private static Logger logger = Logger.getLogger(Store.class);

	/** Services provided by the store. */
	private ProductCatalog productCatalog;
	private SaleLedger saleLedger;
	
	/** constructor initializes data for items in the store */
	public Store( ) {
		productCatalog = new MemoryProductCatalog();
		saleLedger = new SaleLedger();
	}
	
	public ProductCatalog getProductCatalog() {
		return productCatalog;
	}
	
	/**
	 * Record a sale in sale ledger
	 * @param sale the sale to record
	 * @return
	 */
	public boolean recordSale(Sale sale) {
		saleLedger.recordSale(sale);
		getLogger().info( String.format("Recorded sale #%d", sale.getId()) );
		return true;
	}
	
	/**
	 * Get a Sale from the Sale Ledger by id
	 * @param id the ID of the sale to retrieve
	 * @return the sale with requested id or null if no sale with that id
	 */
	public Sale getSale(long id) {
		return saleLedger.findById(id);
	}
	
	
	
	
	private static Logger getLogger() {
		return logger;
	}
}
		
		
		
		

			