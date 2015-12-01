package Observer;

import java.util.Observable;

public class Speaker extends Observable{

	private String name;
	
	public Speaker(String name) {
		this.name = name;
	}
	
	public void speak() {
		System.out.println("Speak!");
		setChanged();
		notifyObservers(name);
	}
	
}
