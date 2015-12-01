package firstgen;
import java.io.*;
import java.util.Properties;
import org.apache.log4j.Logger;
/**
 * Manage access to application properties.
 */
public class PropertyManager {
	
	private static String APP_PROPERTIES = "firstgen.properties";
	private static Properties properties;
	static {
		APP_PROPERTIES = System.getProperty(APP_PROPERTIES, APP_PROPERTIES);
		init();
	}
	
	// load the properties immediately
	private static void init() {
		properties = new Properties( );
		// 1) load from "current" directory using FileInputStream
		try {
			FileInputStream in = new FileInputStream(APP_PROPERTIES);
			properties.load(in);
			return;
		} catch (IOException e) {
			/* try again */
		}
		// 2) load using classloader.getResourceAsStream( )
		ClassLoader classLoader = Thread.currentThread().getContextClassLoader();
		InputStream in = classLoader.getResourceAsStream(APP_PROPERTIES);
		if (in != null) try {
			properties.load(in);
		} catch (IOException e) {
			Logger.getLogger(PropertyManager.class).error("Could not load properties from "+APP_PROPERTIES);
			System.err.println("Could not load properties");
		}
	}
	
	public static String getProperty(String name) {
		return properties.getProperty(name);
	}
	
	public static Properties getProperties() {
		return properties;
	}
}
