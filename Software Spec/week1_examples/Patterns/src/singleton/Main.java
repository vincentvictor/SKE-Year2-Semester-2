package singleton;
import java.io.IOException;


public class Main {

	public static void main(String[] args) {
		Runtime runtime = Runtime.getRuntime();
		try {
			runtime.exec("open /Applications/Firefox.app");
		} catch (IOException e) {
			System.err.println("Failed to open firefox");
			e.printStackTrace();
		}
	}
	
}
