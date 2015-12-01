package game;
import java.util.Random;

public class Die {

	private int faceValue;

	public void roll() {
		Random random = new Random();
		faceValue = 1 + random.nextInt(6);
	}

	public int getFaceValue() {
		return faceValue;
	}

}
