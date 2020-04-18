import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.text.SimpleDateFormat;
import java.util.Date;

public class Try {
    public static void main(String[] args) throws IOException {
        SimpleDateFormat DateFor = new SimpleDateFormat("dd-M-yyyy hh:mm:ss");
        String text = "\r\n" + String.valueOf(DateFor.format(new Date()));

        Path path = Paths.get("/home/kyogre/hello.txt");
        Files.write(path, text.getBytes(), StandardOpenOption.APPEND);
    }
}
