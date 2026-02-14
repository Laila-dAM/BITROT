package tokio.utils;

import java.io.FileInputStream;
import java.io.IOException;
import java.util.Properties;
import tokio.exceptions.CompilerException;

public class Config {
    private static final Properties properties = new Properties();

    public static void load(String path) {
        try (FileInputStream fis = new FileInputStream(path)) {
            properties.load(fis);
        } catch (IOException e) {
            throw new CompilerException("Failed to load config from '" + path + "': " + e.getMessage(), e);
        }
    }

    public static String get(String key) {
        return properties.getProperty(key);
    }

    public static String getOrDefault(String key, String defaultValue) {
        return properties.getProperty(key, defaultValue);
    }

    public static boolean containsKey(String key) {
        return properties.containsKey(key);
    }
}
