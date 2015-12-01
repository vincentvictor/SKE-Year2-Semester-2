
public class Foo {
	private static Foo instance;
	public static Foo getInstance() {
		if (instance == null) {
			instance = new Foo();
		}
		return instance;
	}
	private Foo() {
		
	}
}
