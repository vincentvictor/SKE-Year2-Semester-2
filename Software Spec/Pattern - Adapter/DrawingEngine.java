package adapter;

import java.util.ArrayList;
import java.util.List;

import adapter.oldcode.Line;
import adapter.oldcode.Rectangle;

public class DrawingEngine {
	public static void main(String[] args) {
		List<Shape> shapes = new ArrayList<Shape>();
		shapes.add(new Zigzag());
		shapes.add(new Curve());
		shapes.add(new Curve());
		shapes.add(new Zigzag());
		shapes.add(new LineAdapter(new Line()));
		shapes.add(new RectangleAdapter(new Rectangle()));
		
		for (Shape s : shapes) {
			s.draw(0,0,10,10);
		}
	}
}
