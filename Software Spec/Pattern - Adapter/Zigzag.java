package adapter;

public class Zigzag implements Shape{

	@Override
	public void draw(int x1, int y1, int x2, int y2) {
		String s = String.format("Zigzag from %d, %d to %d, %d", x1, y1, x2, y2);
		System.out.println(s);
	}

}
