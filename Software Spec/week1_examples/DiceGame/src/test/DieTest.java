/**
 * 
 */
package test;

import static org.junit.Assert.*;
import game.Die;

import org.junit.BeforeClass;
import org.junit.Test;

/**
 * @author geeskeiup
 *
 */
public class DieTest {

	/**
	 * @throws java.lang.Exception
	 */
	@BeforeClass
	public static void setUpBeforeClass() throws Exception {
		// something to do each time this test is run
		// but do it only once 
	}

	/**
	 * Test method for {@link game.Die#roll()}.
	 */
	@Test
	public void testRoll() {
		Die die = new Die();
		die.roll();
		int value = die.getFaceValue();
		assertTrue(  value > 0 && value <= 6 );
		// test that the value is consistent
		assertEquals("shouldn't change", value, die.getFaceValue());
	}

}
