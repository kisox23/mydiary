package sample;

import javafx.application.Platform;
import javafx.fxml.Initializable;
import javafx.scene.control.*;
import javax.management.Query;
import javax.swing.*;
import java.awt.event.ActionEvent;
import java.io.IOException;
import java.net.URL;
import java.util.ArrayList;
import java.sql.*;
import java.util.ResourceBundle;

public class LoginController implements Initializable {
    private static final ArrayList<String> usersList = new ArrayList<String>();
    private static final ArrayList<String> passwList = new ArrayList<String>();
    public TextField user;
    public PasswordField passwd;
    public CheckBox checker;
    public Label lbl;
    private byte attempts = 3;
    boolean isTimeoutLogged = false;

    public void loginAttempt() throws IOException {
        String ptemp = passwd.getText();
        String utemp = user.getText();

        if (attempts <= 0) {
            if (!isTimeoutLogged)
                Utils.log(-2, ptemp);
            lbl.setText("You cannot try anymore!");
            isTimeoutLogged = true;
            return;
        }

        if (usersList.contains(utemp)) {
            if (ptemp.equals(passwList.get(usersList.indexOf(utemp)))) {
                lbl.setText("Login successful!");
                Utils.log(0, utemp);
            } else if (ptemp.equals("")) {
                lbl.setText("Fill the fields!");
            } else {
                lbl.setText("Wrong password! " + attempts + " attempts left.");
                Utils.log(-1, utemp);
                attempts --;
            }
        } else {
            if (ptemp.equals("")) {
                lbl.setText("Fill the fields!");
            } else if (!ptemp.equals("") && !utemp.equals("")) {
                lbl.setText("User not found!");
            } else {
                lbl.setText("Fill the fields!");
            }
        }
    }

    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {
        System.out.println("Initializing...");
        Utils.setLogPath("/home/kyogre/mainlog.log");
        try {
            String driver = "com.mysql.cj.jdbc.Driver";
            String myurl = "jdbc:mysql://localhost/MAIN?serverTimezone=UTC";
            Class.forName(driver);
            Connection connection = DriverManager.getConnection(myurl, "fab", "define");

            String query = "SELECT * FROM main_creds";
            Statement st = connection.createStatement();
            ResultSet set = st.executeQuery(query);

            while (set.next()) {
                usersList.add(set.getString("user"));
                passwList.add(set.getString("pass"));
            }
        } catch (SQLException e) {
            System.out.println("Could not connect to MySql database.");
            lbl.setText("An error occurred! Restart!");
        } catch (ClassNotFoundException e) {
            System.out.println("Could not find the driver.");
            lbl.setText("An error occurred! Restart!");
        }
        Platform.runLater(new Runnable() {
            @Override
            public void run() {
                user.requestFocus();
            }
        });
    }
}
