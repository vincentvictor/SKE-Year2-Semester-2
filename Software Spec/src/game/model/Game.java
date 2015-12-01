package game.model;

/**
 * Game model which acts as a controller. I knows about everything inside the
 * game such as Board, Die, Player1, Player2 and delegates most of the work to
 * those objects.
 * 
 * @author Keeratipong <kee@fameworks.co>
 * 
 */
public class Game {

	// TODO: Declare all you models here

	public Game() {
		// TODO : Initialize all objects here
	}

	/**
	 * Make the current player take his/her turn Taking turn can be roll a dice
	 * + move to that square
	 */
	public void currentPlayerTakeTurn() {
		// TODO: Implement this
	}

	/**
	 * Change the state of the game to the next turn
	 */
	public void nextTurn() {
		// TODO: Implement this
	}

	/**
	 * Return total number of squares in the board
	 * 
	 * @return the number of squares
	 */
	public int getBoardSize() {
		// TODO: Replace this dummy return value with actual implementation
		return 64;
	}

	/**
	 * Return the name of the square
	 * 
	 * @param i
	 *            The index of the square in board's collection
	 * @return The name of the square
	 */
	public String getSquareNameAtIndex(int i) {
		// TODO: Replace this dummy return value with actual implementation
		return "?";
	}

	public int getSquareColorCodeAtIndex(int i) {
		return -16777216;
	}

	/**
	 * Return the index of the square that player1 is on
	 * 
	 * @return The index of the square
	 */
	public int getPlayer1SquareIndex() {
		// TODO: Replace this dummy return value with actual implementation
		return 0;
	}

	/**
	 * Return the name of the square that the player1 is on
	 * 
	 * @return The index of the square
	 */
	public String getPlayer1SquareName() {
		// TODO: Replace this dummy return value with actual implementation
		return "?";
	}

	/**
	 * Return the index of the square that player2 is on
	 * 
	 * @return The index of the square
	 */
	public int getPlayer2SquareIndex() {
		// TODO: Replace this dummy return value with actual implementation
		return 0;
	}

	/**
	 * Return the name of the square that the player1 is on
	 * 
	 * @return The index of the square
	 */
	public String getPlayer2SquareName() {
		// TODO: Replace this dummy return value with actual implementation
		return "?";
	}

	/**
	 * Return the face value of a die
	 * 
	 * @return Die value
	 */
	public int getDieValue() {
		// TODO: Replace this dummy return value with actual implementation
		return 6;
	}

	/**
	 * Return the name of the current player who is in this turn
	 * 
	 * @return The name of the current player
	 */
	public String getCurrentPlayerName() {
		// TODO: Replace this dummy return value with actual implementation
		return "Player-1";
	}

	/**
	 * Return the name of the square that the current player is on
	 * 
	 * @return The name of the square that the player is on
	 */
	public String getCurrentPlayerSquareName() {
		// TODO: Replace this dummy return value with actual implementation
		return "?";
	}

}
