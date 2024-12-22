module org.example.todoapp {
    requires javafx.controls;
    requires javafx.fxml;

    opens org.example.todoapp.application to javafx.fxml;
    opens org.example.todoapp.controllers to javafx.fxml;

    exports org.example.todoapp.application;
    exports org.example.todoapp.controllers;
}
