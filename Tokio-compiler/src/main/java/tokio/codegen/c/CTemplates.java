package tokio.codegen.c;

public class CTemplates {

    public static String mainFunctionTemplate(String body) {
        return "#include <stdio.h>\n\nint main() {\n" + indent(body) + "\n    return 0;\n}";
    }

    public static String functionTemplate(String returnType, String name, String params, String body) {
        return mapType(returnType) + " " + name + "(" + params + ") {\n" + indent(body) + "\n}";
    }

    public static String variableTemplate(String type, String name, String value) {
        if (value == null || value.isEmpty()) {
            return mapType(type) + " " + name + ";";
        }
        return mapType(type) + " " + name + " = " + value + ";";
    }

    public static String printTemplate(String value) {
        return "printf(\"%s\\n\", " + value + ");";
    }

    public static String ifTemplate(String condition, String body) {
        return "if (" + condition + ") {\n" + indent(body) + "\n}";
    }

    public static String whileTemplate(String condition, String body) {
        return "while (" + condition + ") {\n" + indent(body) + "\n}";
    }

    public static String forTemplate(String init, String condition, String update, String body) {
        return "for (" + init + "; " + condition + "; " + update + ") {\n" + indent(body) + "\n}";
    }

    public static String returnTemplate(String value) {
        return "return " + value + ";";
    }

    private static String indent(String code) {
        return "    " + code.replaceAll("\n", "\n    ");
    }

    private static String mapType(String type) {
        switch (type) {
            case "int":
                return "int";
            case "float":
                return "float";
            case "string":
                return "char*";
            case "void":
            default:
                return "void";
        }
    }
}
