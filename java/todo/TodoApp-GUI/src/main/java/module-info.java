module org.example.todoappgui {
    requires javafx.controls;
    requires javafx.fxml;
    requires java.sql;

    opens org.example.todoappgui to javafx.fxml;
    exports org.example.todoappgui;
    exports org.example.todoappgui.controllers;
    opens org.example.todoappgui.controllers to javafx.fxml;
}