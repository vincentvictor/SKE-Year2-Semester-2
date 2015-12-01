package firstgen.domain;

/** A customer known to the store.
 *  This includes customers with store card.
 * @author James Brucker
 */
public class Customer {
	private String customerId;
	private String name;
	public CustomerType type;
	
	public Customer( String id ) {
		customerId = id;
	}
	
	public String getCustomerId() { return customerId; }
	
	public String toString() { return customerId; }

}
