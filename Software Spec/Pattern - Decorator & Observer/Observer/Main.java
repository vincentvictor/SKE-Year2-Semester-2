package Observer;

public class Main {
	public static void main(String[] args) {
		Speaker speaker = new Speaker("Jim");
		Listener listener = new Listener();
		speaker.addObserver(listener);
		speaker.speak();
	}
}
