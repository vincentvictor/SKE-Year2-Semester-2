package game;
public class DiceGame {

	private Die die1 = new Die();
	private Die die2 = new Die();

	public void play() {
		die1.roll();
		int fv1 = die1.getFaceValue();
		die2.roll();
		int fv2 = die2.getFaceValue();
		int sum = fv1 + fv2;
		if (sum == 7) {
			System.out.println("The sum is 7, you win.");
		} else {
			System.out.println("The sum is " + sum + ", you lose.");
		}
	}
	
	public static void main(String[] args) {
		DiceGame game = new DiceGame();
		game.play();
	}

}
