package firstgen.store;

import java.util.ArrayList;
import java.util.List;

import firstgen.domain.Sale;

/**
 * The sale ledger records Sales.
 * @author Dilbert
 */
public class SaleLedger {
	// this is a memory based ledger
	private List<Sale> sales;
	// max id of all sales recorded so far, used to assign new sale IDs
	long maxId = 0;
	
	public SaleLedger() {
		sales = new ArrayList<Sale>();
	}
	
	/**
	 * Record a sale in the ledger.
	 * If the sales does not have an id (id == 0)
	 * then assign an id.
	 * @param sale the sale to record. Must not be null.
	 * @return the id of this sale, as recorded
	 */
	public Long recordSale( Sale sale ) {
		if (sale.getId() <= 0) makeSaleId(sale);
		// check if this sale is already in the List
		// this linear search is inefficient, 
		// in production code we'd use something better, like a database query.
		for(Sale s: sales) if (s == sale) return sale.getId();
		sales.add(sale);
		// in case the sale has set its own id outside this class
		if (sale.getId() > maxId) maxId = sale.getId(); 
		return sale.getId();
	}
	
	/**
	 * find a sale by its ID number
	 * @param id the id number of sale to look up
	 * @return sale with requested id, or null if no such sale
	 */
	public Sale findById(long id) {
		for(Sale s: sales) if (s.getId() == id) return s;
		return null;
	}
	
	private void makeSaleId(Sale sale) {
		sale.setId(++maxId);
	}
}
