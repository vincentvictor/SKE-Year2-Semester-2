package firstgen.store.impl;

import org.apache.log4j.Logger;

import firstgen.domain.*;
import firstgen.store.ProductCatalog;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

/** 
 * The ProductCatalog contains information about items for sale.
 * It has a method to find any item by ID string.
 * Use dependency injection or a service locator (e.g. store)
 * to manage creation of product catalog.
 * For testability, we don't make this a singleton
 * @author James Brucker
 */
public class MemoryProductCatalog implements ProductCatalog {
	/** Logger for this class */
	private static final Logger logger = Logger.getLogger(MemoryProductCatalog.class);

	/** a map from item id to product description */
	private HashMap<String,Product> products;
	
	/** constructor initializes data for catalog */
	public MemoryProductCatalog( ) {
		logger.info("Creating a mock product catalog from Stock enum");
		products = new HashMap<String,Product>( );
		for(Stock stock : Stock.values() ) {
			addProduct( new Product(stock.id, stock.description, stock.price) );
			String s = String.format("add to catalog: id %s %s", stock.id, stock.description);
			logger.info( s );
		}
		logger.info("Catalog contains "+products.size()+" items");
	}

	
	/**
	 * @see firstgen.store.ProductCatalog#getItem(java.lang.String)
	 */
	@Override
	public Product getProduct( String id ) {
		logger.info("looking for item "+id);
		Product item;
		try {
			item = products.get( id );
		} catch ( RuntimeException e ) {
			logger.error("inventory threw exception "+e.getMessage());
			return null;
		}
		
		if ( item == null ) {
			logger.info("Item id "+ id + " not found in catalog");
		}
		else logger.info("found "+id );
		return item;
	}

	/**
	 * @see firstgen.store.ProductCatalog#addItem(firstgen.domain.Product)
	 */
	@Override
	public boolean addProduct( Product pd ) {
		String id = pd.getProductId();
		if (id == null || id.isEmpty()) {
			logger.error("Adding Product without an itemId: "+pd);
			throw new IllegalArgumentException("Product does not have itemId");
		}
		products.put(id, pd);
		return true;
	}

	/**
	 * @see firstgen.store.ProductCatalog#findProduct(java.lang.String)
	 */
	@Override
	public List<Product> findProduct(String match) {
		match = match.toLowerCase();
		List<Product> list = new ArrayList<Product>();
		for(Product pd : products.values() ) {
			if ( pd.getDescription().toLowerCase().contains(match) ) list.add(pd);
		}
		return list;
	}
}