package firstgen.domain;
/**
 * Categories of customers.
 */
public enum CustomerType {
	RETAIL(0.0),
	MEMBER(0.02),
	BUSINESS(0.05);
	/** percent discount on purchases */
	public final double discount;
	private CustomerType(double disc) {
		this.discount = disc;
	}
}
