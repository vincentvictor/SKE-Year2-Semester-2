import java.util.Iterator;


public class AZCollection implements Iterable<String>{

	@Override
	public Iterator<String> iterator() {
		return new Iterator<String>() {

			private char curChar='A';
			
			@Override
			public boolean hasNext() {
				return curChar <= 'Z';
			}

			@Override
			public String next() {
				return (curChar++)+"";
			}
			
			@Override
			public void remove() {
				
			}
		};
	}

}
