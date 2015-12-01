package extern.tax;

/**
 * Lame tax calculator just returns the price
 * as a percentage of sale total.
 */
public class LameTax {
	private static double taxrate = 0.07;
	
	/**
	 * Get the tax on a purchase amount.
	 * @param amount the amount of purchase
	 * @return the tax
	 */
	public double getTax(double amount) {
		return taxrate * amount;
	}
	
}
