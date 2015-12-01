package firstgen.domain;

/** 
 * Describes an item in the store's inventory,
 * including ID (such as ERN code), a description, and unit price.
 *
 * @author Dilbert
 */
public class Product implements Comparable<Product> {
	protected String productId;
	protected String description;
	protected double price;
	
	/** Default constructor for product description,
     * needed for instantiation by persistence framework.
	 */
	public Product( ) {
		this.productId = null;
		this.description = "";
	}
        
	/** Create a new item description.
	 * @param productId the ID of item, e.g. EAN code
	 * @param description is a description of this product
	 * @param price is the selling price of the product
	 * @prerequisite price is non-negative and itemID is not null
	 */
	public Product(String productId, String description, double price) {
		super(); // Eclipse added this
		assert productId != null : this.getClass().getName() + ": creating new item with null itemID";
		this.productId = (productId==null)?"":productId.trim();
		this.description = (description==null)?"":description.trim();
		this.price = price;
	}
	
	/** Create a new line item as a copy of another line item.
	 * @param other is the line item to make copy of
	 */
	public Product( Product other ) {
		this.productId = other.productId;
		this.description = other.description;
		this.price = other.price;
	}
	
	/** compare two line items using itemID.
	 * @param other is the other item for comparison with this one.
	 * @return < 0 if this item is first, 0 if equal, > 0 if this item comes later.
	 * @see java.lang.Comparable#compareTo(java.lang.Object)
	 */
	public int compareTo( Product other ) {
		if ( other == null ) return -1;
		return productId.compareToIgnoreCase( other.productId );
	}
	
	/** compare two line items using itemID.
	 * @param other is the other item for comparison with this one.
	 * @return true of both items have the same ID
	 * @see java.lang.Comparable#compareTo(java.lang.Object)
	 */
	public boolean equals( Product other ) {
		if ( other == null ) return false;
		return productId.equalsIgnoreCase( other.productId );
	}
	
	/** Get the item's description
	 * @return the description
	 */
	public String getDescription() { return description; }

	/** Get the item's ID string
	 * @return the itemID
	 */
	public String getProductId() { return productId; }

	/** Get the item's unit price
	 * @return the price
	 */
	public double getPrice() { return price; }
	
	public String toString() { 
		return String.format("%s @ %.2f", description, price); 
	}

	/**
	 * set the unit price of this item
	 * @param price is the item's price
	 */
    protected void setPrice(double price) {
        this.price = price;
    }

	/**
	 * set the id of this item
	 * @param id is the product's ID
	 */
    protected void setItemId(String id) {
        this.productId = id;
    }

	/**
	 * set the description of this item
	 * @param description the item's description
	 */
    protected void setDescription(String description) {
        this.description = description;
    }
}
