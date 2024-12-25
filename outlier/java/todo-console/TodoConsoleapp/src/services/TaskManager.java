//src/services/TaskManager

package services;

import models.Task;

import java.time.LocalDate;
import java.util.*;
import java.util.stream.Collectors;

public class TaskManager {
    private List<Task> tasks;
    private int taskIdCounter = 1;

    public TaskManager() {
        this.tasks = FileHandler.loadTasks();
        if (!tasks.isEmpty()) {
            taskIdCounter = tasks.stream().mapToInt(Task::getId).max().orElse(0) + 1;
        }
    }

    // Add Task
    public void addTask(String title, String description, String category, LocalDate dueDate, int priority) {
        Task task = new Task(taskIdCounter++, title, description, category, dueDate, priority);
        tasks.add(task);
        System.out.println("Tehtävä lisätty onnistuneesti!\n");
    }

    // Edit Task
    public void editTask(int id, String title, String description, String category, LocalDate dueDate, int priority) {
        Optional<Task> taskOptional = findTaskById(id);
        if (taskOptional.isPresent()) {
            Task task = taskOptional.get();
            tasks.set(tasks.indexOf(task), new Task(id, title, description, category, dueDate, priority));
            System.out.println("Tehtävä päivitetty onnistuneesti!\n");
        } else {
            System.out.println("Tehtävää ei löytynyt!\n");
        }
    }

    // Delete Task
    public void deleteTask(int id) {
        Optional<Task> taskOptional = findTaskById(id);
        if (taskOptional.isPresent()) {
            tasks.remove(taskOptional.get());
            System.out.println("Tehtävä poistettu onnistuneesti!\n");
        } else {
            System.out.println("Tehtävää ei löytynyt!\n");
        }
    }

    // View All Tasks
    public void viewTasks() {
        if (tasks.isEmpty()) {
            System.out.println("Ei tehtäviä saatavilla!\n");
        } else {
            tasks.forEach(System.out::println);
        }
    }

    // Mark Task as Completed
    public void markTaskAsCompleted(int id) {
        Optional<Task> taskOptional = findTaskById(id);
        if (taskOptional.isPresent()) {
            taskOptional.get().setCompleted(true);
            System.out.println("Tehtävä merkitty valmiiksi!\n");
        } else {
            System.out.println("Tehtävää ei löytynyt!\n");
        }
    }

    // Search Task by Title or Description
    public void searchTasks(String keyword) {
        List<Task> result = tasks.stream()
                .filter(task -> task.getTitle().toLowerCase().contains(keyword.toLowerCase()) ||
                        task.getDescription().toLowerCase().contains(keyword.toLowerCase()))
                .collect(Collectors.toList());

        if (result.isEmpty()) {
            System.out.println("Hakusanalla ei löytynyt yhtään tehtävää.\n");
        } else {
            result.forEach(System.out::println);
        }
    }

    // Filter Tasks by Priority
    public void filterByPriority(int priority) {
        List<Task> result = tasks.stream()
                .filter(task -> task.getPriority() == priority)
                .collect(Collectors.toList());

        if (result.isEmpty()) {
            System.out.println("Valitulla prioriteetilla ei löytynyt tehtäviä.\n");
        } else {
            result.forEach(System.out::println);
        }

        tasks = result;

        if (result.isEmpty()) {
            System.out.println("Valitulla prioriteetilla ei löytynyt tehtäviä.\n");
        } else {
            result.forEach(System.out::println);
        }
    }

    // Filter Tasks by Category
    public void filterByCategory(String category) {
        List<Task> result = tasks.stream()
                .filter(task -> task.getCategory().equalsIgnoreCase(category))
                .collect(Collectors.toList());

        if (result.isEmpty()) {
            System.out.println("Valitulla kategorialla ei löytynyt tehtäviä.\n");
        } else {
            result.forEach(System.out::println);
        }
    }

    // Filter Tasks by Completion Status
    public void filterByStatus(boolean isCompleted) {
        List<Task> result = tasks.stream()
                .filter(task -> task.isCompleted() == isCompleted)
                .collect(Collectors.toList());

        if (result.isEmpty()) {
            System.out.println("Valitulla tilalla ei löytynyt tehtäviä.\n");
        } else {
            result.forEach(System.out::println);
        }
    }

    // Save Tasks to File
    public void saveTasks() {
        FileHandler.saveTasks(tasks);
    }

    // Find Task by ID
    private Optional<Task> findTaskById(int id) {
        return tasks.stream().filter(task -> task.getId() == id).findFirst();
    }
}
