//src/main/java/org.example.todoappgui/HelloApplication

package org.example.todoappgui;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.io.IOException;
import java.net.URL;

public class HelloApplication extends Application {
    @Override
    public void start(Stage stage) throws IOException {
        URL fxmlUrl = getClass().getResource("/views/main-view.fxml");
        if (fxmlUrl == null) {
            throw new IllegalStateException("FXML file not found! Check the path: /views/main-view.fxml");
        } else {
            System.out.println("FXML loaded successfully: " + fxmlUrl);
        }

        FXMLLoader fxmlLoader = new FXMLLoader(fxmlUrl);
        Scene scene = new Scene(fxmlLoader.load(), 600, 400);
        stage.setTitle("Todo App");
        stage.setScene(scene);
        stage.show();
    }

    public static void main(String[] args) {
        launch();
    }
}
