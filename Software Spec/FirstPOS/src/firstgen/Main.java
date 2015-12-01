package firstgen;
import javax.swing.SwingUtilities;
import javax.swing.UIManager;
import firstgen.pos.*;
import firstgen.store.*;
import firstgen.ui.*;

import org.apache.log4j.*;
/**
 * This class creates an instance of the desktop POS
 * and invokes it.
 */
public class Main {
	private static Logger logger;
	/** use console UI or Graphical UI? */
	private static final boolean USE_CONSOLE = false;

	/** Initialize log4j.
	 *  @param debug if true, then initialize level to debug before starting.
	 *  This enables you to see the log4j initialization messages.
	 *  Normally the logging level is set in the file log4j.properties.
	 */
	public static void initLog4j( boolean debug ) {
		
		// for "debug" level, also show log4j initialization
			
		if ( debug ) System.setProperty("log4j.debug", "true" );
			
		// For a basic default configuration that logs to console, 
		// and does not require a log4j.properties file, 
		// use this: 
		// org.apache.log4j.BasicConfigurator.configure();

		// Otherwise, the first call to getRootLogger() initializes log4j
	}
	
	private static Logger getLogger() {
		if ( logger == null ) logger = Logger.getLogger(Main.class);
		return logger;
	}
	
	/**
	 * If using Java Swing interface, set Look & Feel to
	 * native Look and Feel so the window looks like a native app.
	 */
	public static void setLookAndFeel() {
		try {
			UIManager.setLookAndFeel(
					UIManager.getSystemLookAndFeelClassName() );
		} catch (Exception ex) {
			getLogger().error( ex );
			// then use the default L&F
		} 
	}

	/**
	 * Initialize controller and UI, and display them.
	 * @param args not used.
	 */
	public static void main(String[] args) {		
		// initLog4j( true );
//TODO access the store as a singleton
		Store store = new Store();
		Register register = new Register( );
		register.setStore(store);
		
		// run boring Console UI
		if (USE_CONSOLE) {
			ConsoleUI ui = new ConsoleUI(register);
			register.addSaleViewer(ui);
			ui.run();
		}
		else {
			// run Swing GUI
			setLookAndFeel();
			POSUI gui = new POSUI(register);
			register.addSaleViewer(gui);
			SwingUtilities.invokeLater( gui );
		}
	}
}
