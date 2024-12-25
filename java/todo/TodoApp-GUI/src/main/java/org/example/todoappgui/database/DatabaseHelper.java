//src/main/java/org.example.todoappgui/database/DatabaseHelper
package org.example.todoappgui.database;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class DatabaseHelper {
    private static final String DB_URL = "jdbc:sqlite:tasks.db";

    public static Connection connect() throws SQLException {
        return DriverManager.getConnection(DB_URL);
    }

    public static void initializeDatabase() {
        String createTableSQL = """
        CREATE TABLE IF NOT EXISTS tasks (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            task TEXT NOT NULL,
            completed BOOLEAN DEFAULT FALSE,
            priority TEXT DEFAULT 'Medium'
        )
    """;

        try (Connection conn = connect();
             PreparedStatement stmt = conn.prepareStatement(createTableSQL)) {
            stmt.execute();
        } catch (SQLException e) {
            System.err.println("Database Initialization Error: " + e.getMessage());
        }
    }

    public static void addTask(String task, String priority) {
        String insertSQL = "INSERT INTO tasks (task, priority) VALUES (?, ?)";
        try (Connection conn = connect();
             PreparedStatement stmt = conn.prepareStatement(insertSQL)) {
            stmt.setString(1, task);
            stmt.setString(2, priority);
            stmt.executeUpdate();
        } catch (SQLException e) {
            System.err.println("Add Task Error: " + e.getMessage());
        }
    }




    public static void removeTask(String task) {
        String deleteSQL = "DELETE FROM tasks WHERE task = ?";
        try (Connection conn = connect();
             PreparedStatement stmt = conn.prepareStatement(deleteSQL)) {
            stmt.setString(1, task);
            stmt.executeUpdate();
        } catch (SQLException e) {
            System.err.println("Remove Task Error: " + e.getMessage());
        }
    }

    public static ResultSet getAllTasks() {
        String selectSQL = "SELECT task FROM tasks";
        try {
            Connection conn = connect();
            PreparedStatement stmt = conn.prepareStatement(selectSQL);
            return stmt.executeQuery();
        } catch (SQLException e) {
            System.err.println("Fetch Tasks Error: " + e.getMessage());
            return null;
        }
    }

    public static void markTaskCompleted(String task) {
        String updateSQL = "UPDATE tasks SET completed = TRUE WHERE task = ?";
        try (Connection conn = connect();
             PreparedStatement stmt = conn.prepareStatement(updateSQL)) {
            stmt.setString(1, task);
            stmt.executeUpdate();
        } catch (SQLException e) {
            System.err.println("Mark Task Completed Error: " + e.getMessage());
        }
    }

    public static ResultSet getFilteredTasks(String filter) {
        String selectSQL;
        switch (filter) {
            case "Completed Tasks":
                selectSQL = "SELECT task FROM tasks WHERE completed = TRUE";
                break;
            case "Pending Tasks":
                selectSQL = "SELECT task FROM tasks WHERE completed = FALSE";
                break;
            default:
                selectSQL = "SELECT task FROM tasks";
        }

        try {
            Connection conn = connect();
            PreparedStatement stmt = conn.prepareStatement(selectSQL);
            return stmt.executeQuery();
        } catch (SQLException e) {
            System.err.println("Fetch Filtered Tasks Error: " + e.getMessage());
            return null;
        }
    }

}
