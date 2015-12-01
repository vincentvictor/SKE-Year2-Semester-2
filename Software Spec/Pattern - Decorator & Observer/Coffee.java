
public abstract class Coffee {
	public abstract double getPrice();
	public abstract String getIngredients();
}

class BaseCoffee extends Coffee {

	public double getPrice() {
		// TODO Auto-generated method stub
		return 60;
	}

	public String getIngredients() {
		// TODO Auto-generated method stub
		return "[Water] [Coffee]";
	}

}

abstract class CoffeeDecorator extends Coffee{

	private Coffee coffee;

	public CoffeeDecorator(Coffee coffee) {
		this.coffee = coffee;
	}

	public double getPrice() {
		// TODO Auto-generated method stub
		return coffee.getPrice();
	}	
}

class MilkedCoffee extends CoffeeDecorator{

	public MilkedCoffee(Coffee coffee) {
		super(coffee);
	}

	public double getPrice() {
		// TODO Auto-generated method stub
		return super.coffee.getPrice()+10;
	}

	public String getIngredients() {
		// TODO Auto-generated method stub
		return super.coffee.getIngredients()+" [Milk]";
	}
}
