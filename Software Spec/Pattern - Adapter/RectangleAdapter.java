package adapter;

import adapter.oldcode.Rectangle;

public class RectangleAdapter implements Shape{
	private Rectangle adaptee;
	
	public RectangleAdapter(Rectangle rectangle) {
		this.adaptee = rectangle;
	}
	
	@Override
	public void draw(int x1, int y1, int x2, int y2) {
		adaptee.draw(x1, y1, Math.abs(x2 - x1), Math.abs(y2 - y1));
		
	}
}
