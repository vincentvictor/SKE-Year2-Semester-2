package Observer;

import java.util.Observable;
import java.util.Observer;

public class Listener implements Observer{

	public void heardSomething(String name) {
		System.out.println("I heard "+name+" something.");
	}

	public void update(Observable o, Object arg) {
		// TODO Auto-generated method stub
		heardSomething((String) arg);
	}
	
}
