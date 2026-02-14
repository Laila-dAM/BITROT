package tokio;

import tokio.cli.CompilerCLI;
import tokio.utils.Config;

public class Main {
    public static void main(String[] args) {
        try {
            Config.load("src/main/resources/config.properties");
            CompilerCLI cli = new CompilerCLI();
            cli.run(args);
        } catch (Exception e) {
            System.err.println("[FATAL] Failed to start Tokio Compiler: " + e.getMessage());
            e.printStackTrace();
        }
    }
}
