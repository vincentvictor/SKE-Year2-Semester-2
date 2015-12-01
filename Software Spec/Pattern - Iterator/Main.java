import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;


public class Main {
	public static void main(String[] args) {
		AZCollection az = new AZCollection();
		Iterator<String> itr = az.iterator();
		while(itr.hasNext()) {
			System.out.print(itr.next());
		}
	}
}
