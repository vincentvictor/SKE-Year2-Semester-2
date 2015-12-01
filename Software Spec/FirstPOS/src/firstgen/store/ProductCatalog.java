package firstgen.store;

import java.util.List;

import firstgen.domain.Product;

/**
 * The Product Catalog contains the kinds of Products 
 * sold by the store.  There may be multiple implementations
 * of this interface.
 * 
 * @author jim
 */
public interface ProductCatalog {

	/** Return a Product that matches the given product id.
	 * @param productId is the Product ID string of the product to get.
	 * @return a Product having the given id.
	 *        If the item ID is not found in the Store's inventory,
	 *        then a null value is returned.
	 */
	public abstract Product getProduct(String productId);

	/**
	 * Add a product description to catalog.
	 * @param pd is the product description to add. Must not be null
	 *       and must have a non-null, non-empty itemId.
	 * @return true if operation succeeds, false if this ID already in catalog.
	 * @throws IllegalArgumentException if parameter value is not valid.
	 */
	public abstract boolean addProduct(Product pd);

	/**
	 * Search for products containing a given string in their description
	 * @param match the string to search for, case insensitive
	 * @return List of matching products.  Empty list if no matches.
	 */
	public abstract List<Product> findProduct(String match);

}