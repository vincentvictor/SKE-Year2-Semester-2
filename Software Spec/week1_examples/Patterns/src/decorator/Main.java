package decorator;

public class Main {

	public static void main(String[] args) {
		Coffee coffee = new BaseCoffee();
		System.out.println(coffee);
		
		MilkedCoffee milkedCoffee = new MilkedCoffee(coffee);
		System.out.println(milkedCoffee);
		
		MilkedCoffee doubleMilkedCoffee = new MilkedCoffee(milkedCoffee);
		System.out.println(doubleMilkedCoffee);
		
		WhipedCoffee doubleMiledWhipedCoffee = new WhipedCoffee(doubleMilkedCoffee);
		System.out.println(doubleMiledWhipedCoffee);
		
	}

}
