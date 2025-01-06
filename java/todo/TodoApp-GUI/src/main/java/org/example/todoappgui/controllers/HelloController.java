//src/main/java/org.example.todoappgui/controller/HelloController.java
package org.example.todoappgui.controllers;

import javafx.fxml.FXML;
import javafx.scene.control.*;
import org.example.todoappgui.database.DatabaseHelper;
import java.sql.ResultSet;
import java.sql.SQLException;

public class HelloController {

    @FXML
    private ListView<String> taskListView;

    @FXML
    private TextField taskInputField;

    @FXML
    private ComboBox<String> priorityComboBox;

    @FXML
    private Button addTaskButton;

    @FXML
    private Button removeTaskButton;

    @FXML
    private Button markCompletedButton;

    @FXML
    private ComboBox<String> filterComboBox;

    @FXML
    public void initialize() {
        DatabaseHelper.initializeDatabase();
        loadTasks("All Tasks");

        addTaskButton.setOnAction(event -> addTask());
        removeTaskButton.setOnAction(event -> removeTask());
        markCompletedButton.setOnAction(event -> markTaskCompleted());
        filterComboBox.setOnAction(event -> filterTasks());

        // Set default priority
        priorityComboBox.setValue("Medium");
    }

    private void addTask() {
        String task = taskInputField.getText();
        String priority = priorityComboBox.getValue();

        if (!task.isEmpty()) {
            DatabaseHelper.addTask(task, priority);
            taskListView.getItems().add(task + " (" + priority + ")");
            taskInputField.clear();
        }
    }

    private void removeTask() {
        String selectedTask = taskListView.getSelectionModel().getSelectedItem();
        if (selectedTask != null) {
            String taskName = selectedTask.split(" \\(")[0]; // Extract task name
            DatabaseHelper.removeTask(taskName);
            taskListView.getItems().remove(selectedTask);
        }
    }

    private void markTaskCompleted() {
        String selectedTask = taskListView.getSelectionModel().getSelectedItem();
        if (selectedTask != null) {
            String taskName = selectedTask.split(" \\(")[0]; // Extract task name
            DatabaseHelper.markTaskCompleted(taskName);
            loadTasks(filterComboBox.getValue());
        }
    }

    private void filterTasks() {
        String selectedFilter = filterComboBox.getValue();
        loadTasks(selectedFilter);
    }

    private void loadTasks(String filter) {
        taskListView.getItems().clear();
        ResultSet tasks = DatabaseHelper.getFilteredTasks(filter);
        try {
            while (tasks != null && tasks.next()) {
                String task = tasks.getString("task");
                String priority = tasks.getString("priority");
                taskListView.getItems().add(task + " (" + priority + ")");
            }
        } catch (SQLException e) {
            System.err.println("Load Tasks Error: " + e.getMessage());
        }
    }
}
