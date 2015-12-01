
package firstgen.store.impl;

/**
 * A static set of products for initializing the product catalog
 * during first iteration and for testing.  This is not for production.
 * @author Jim
 */
public enum Stock {
	GREENTEA("10", "Green Tea, 50gram", 60),
	BROWNRICE("11", "Jasmine Brown Rice, 5kg", 105),
	SOYSAUCE("12", "Light Soy Sauce", 27.5),
	COKE("13", "Coca-Cola, 1.25L", 22),
	PEPSI("14", "Pepsi Cola, 1.25L", 23),
	TOFU("15", "Medium Tofu, 250gr", 15),
	APPLE("16", "Red Medium Apple, each", 5),
	PAPAYA("17", "Whole Papaya, 1kg", 12),
	BANANACAKE("18", "Banana Cake, 250gr", 30),
	FRUITCAKE("19", "Fruit Cake, 250gr", 35),
	PEANUTS("20", "Peanuts, 100gr", 10);

	private Stock(String id, String desc, double price) {
		this.id = id;
		this.description = desc;
		this.price = price;
	}
	public final String id;
	public final String description;
	public final double price;
}
