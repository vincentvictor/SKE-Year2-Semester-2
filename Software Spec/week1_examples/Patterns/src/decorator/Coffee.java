package decorator;

public abstract class Coffee {

	public abstract double getCost();
	public abstract String getIngredients();
	
	public String toString() {
		return "Cost: " + getCost() + ", Ingredients: " + getIngredients();
	}
	
}

class BaseCoffee extends Coffee {

	@Override
	public double getCost() {
		return 40;
	}

	@Override
	public String getIngredients() {
		return "[Water] [Coffee]";
	}
	
	
	
}

abstract class CoffeeDecorator extends Coffee {
	
	private Coffee coffee;
	
	public CoffeeDecorator(Coffee coffee) {
		this.coffee = coffee;
	}
	
	public double getCost() {
		return coffee.getCost();
	}

	@Override
	public String getIngredients() {
		return coffee.getIngredients();
	}	
	
}

class MilkedCoffee extends CoffeeDecorator {

	public MilkedCoffee(Coffee coffee) {
		super(coffee);
	}
	
	@Override
	public double getCost() {
		return super.getCost() + 10;
	}
	
	@Override
	public String getIngredients() {
		return super.getIngredients() + " [Milk]";
	}
	
}

class WhipedCoffee extends CoffeeDecorator {

	public WhipedCoffee(Coffee coffee) {
		super(coffee);
	}
	
	@Override
	public double getCost() {
		return super.getCost() + 15;
	}
	
	@Override
	public String getIngredients() {
		return super.getIngredients() + " [Whip]";
	}
	
}