package tokio.utils;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;

import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import tokio.ast.ProgramNode;
import tokio.exceptions.CompilerException;

public class FileUtils {

    public static String readFile(String path) {
        try {
            return new String(Files.readAllBytes(Paths.get(path)));
        } catch (IOException e) {
            throw new CompilerException("Failed to read file: " + path, e);
        }
    }

    public static void writeFile(String path, String content) {
        try {
            Files.write(Paths.get(path), content.getBytes());
        } catch (IOException e) {
            throw new CompilerException("Failed to write file: " + path, e);
        }
    }

    public static boolean exists(String path) {
        return Files.exists(Paths.get(path));
    }

    public static void createDirectories(String path) {
        try {
            Files.createDirectories(Paths.get(path));
        } catch (IOException e) {
            throw new CompilerException("Failed to create directories: " + path, e);
        }
    }

    // ---------- Novos métodos -----------

    // Lê o arquivo e retorna um ProgramNode (AST)
    public static ProgramNode loadProgram(String path) {
        String source = readFile(path);
        // Aqui você pode chamar o Parser real
        try {
            return new tokio.parser.Parser(source).parse();
        } catch (Exception e) {
            throw new CompilerException("Failed to parse program: " + path, e);
        }
    }

    // Salva uma string em arquivo
    public static void saveToFile(String path, String content) {
        writeFile(path, content);
    }

    // Salva a AST em JSON
    public static void saveToJson(ProgramNode program, String path) {
        Gson gson = new GsonBuilder().setPrettyPrinting().create();
        String json = gson.toJson(program);
        writeFile(path, json);
    }
}
