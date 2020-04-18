package sample;

import java.io.IOException;
import java.nio.file.*;
import java.text.SimpleDateFormat;
import java.util.Date;

public class Utils {
    private static Path logPath = null;

    static void setLogPath(String path) {
            logPath = Paths.get(path);
    }

    /**
     *
     * @param value "FAIL", "FINE" or "TIMEOUT"
     */
    static void log(String value, String user) throws IOException {
        if (logPath == null)
            return;
        SimpleDateFormat df = new SimpleDateFormat("dd-M-yyyy hh:mm:ss");
        String first = "\r\n" + String.valueOf(df.format(new Date()));
        switch (value) {
            case "FAIL":
                first += " -> Attempt to login failed.";
                try {
                    Files.write(logPath, first.getBytes(), StandardOpenOption.APPEND);
                } catch (NoSuchFileException e) {
                    System.out.println("File not found. Generating one...");
                    Files.createFile(logPath);
                    Files.write(logPath, first.getBytes(), StandardOpenOption.APPEND);
                }
                break;
            case "FINE":
                first += " -> " + user + " logged successfully.";
                try {
                    Files.write(logPath, first.getBytes(), StandardOpenOption.APPEND);
                } catch (NoSuchFileException e) {
                    System.out.println("File not found. Generating one...");
                    Files.createFile(logPath);
                    Files.write(logPath, first.getBytes(), StandardOpenOption.APPEND);
                }
                break;
            case "TIMEOUT":
                first += " -> Max number of attempts reached. Stopping log.";
                try {
                    Files.write(logPath, first.getBytes(), StandardOpenOption.APPEND);
                } catch (NoSuchFileException e) {
                    System.out.println("File not found. Generating one...");
                    Files.createFile(logPath);
                    Files.write(logPath, first.getBytes(), StandardOpenOption.APPEND);
                }
                break;
            default:
                break;
        }
    }

    /**
     *
     * @param code 0 if OK, -1 if FAIL, -2 if TIMEOUT
     **/
    static void log(int code, String user) throws IOException {
        if (logPath == null)
            return;
        SimpleDateFormat df = new SimpleDateFormat("dd-M-yyyy hh:mm:ss");
        String first = "\r\n" + String.valueOf(df.format(new Date()));
        switch (code) {
            case -1:
                first += " -> Attempt to login failed.";
                try {
                    Files.write(logPath, first.getBytes(), StandardOpenOption.APPEND);
                } catch (NoSuchFileException e) {
                    System.out.println("File not found. Generating one...");
                    Files.createFile(logPath);
                    Files.write(logPath, first.getBytes(), StandardOpenOption.WRITE);
                }
                break;
            case 0:
                first += " -> " + user + " logged successfully.";
                try {
                    Files.write(logPath, first.getBytes(), StandardOpenOption.APPEND);
                } catch (NoSuchFileException e) {
                    System.out.println("File not found. Generating one...");
                    Files.createFile(logPath);
                    Files.write(logPath, first.getBytes(), StandardOpenOption.APPEND);
                }
                break;
            case -2:
                first += " -> Max number of attempts reached. Stopping log.";
                try {
                    Files.write(logPath, first.getBytes(), StandardOpenOption.APPEND);
                } catch (NoSuchFileException e) {
                    System.out.println("File not found. Generating one...");
                    Files.createFile(logPath);
                    Files.write(logPath, first.getBytes(), StandardOpenOption.APPEND);
                }
                break;
            default:
                break;
        }
    }
}