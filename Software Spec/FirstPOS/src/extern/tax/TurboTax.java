package extern.tax;

import java.util.List;

import firstgen.domain.LineItem;

/**
 * A tax calculator that accepts a list of LineItems
 * and examines each item for tax.
 * It then returns the total tax.
 */
public class TurboTax {
	private static final double taxrate = 0.07;
	
	public double getTax(List<LineItem> items) {
		// stupid example: if the last digit of product code (EAN) 
		// is zero then its tax exempt!
		// more realistic usage is some categories have different tax rates,
		// such as alcohol and tobacco.
		double taxableAmount = 0.0;
		for(LineItem item: items) {
			if (item.getProductId().endsWith("0")) /* no tax */;
			else taxableAmount += item.getTotal();
		}
		return taxableAmount * taxrate;
	}

}
