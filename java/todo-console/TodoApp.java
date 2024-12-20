import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

public class TodoApp {
    private List<Task> tasks;

    // Constructor
    public TodoApp() {
        this.tasks = new ArrayList<>();
    }

    // Method to add a task
    public void addTask(String name, String description, String category) {
        Task task = new Task(name, description, category);
        tasks.add(task);
        System.out.println("Task added: " + task);
    }

    // Method to list all tasks
// Method to list all tasks
    public List<String> listAllTasks() {
        if (tasks.isEmpty()) {
            System.out.println("No tasks available.");
            return new ArrayList<>();  // Return an empty list if no tasks
        } else {
            return tasks.stream()
                    .map(Task::toString)  // Convert each Task object to a String representation
                    .collect(Collectors.toList());
        }
    }

    // Method to list tasks by category
    public List<String> listTasksByCategory(String category) {
        List<Task> filteredTasks = tasks.stream()
                .filter(task -> task.getCategory().equalsIgnoreCase(category))
                .collect(Collectors.toList());

        if (filteredTasks.isEmpty()) {
            System.out.println("No tasks in this category.");
            return new ArrayList<>();  // Return an empty list if no tasks found
        } else {
            return filteredTasks.stream()
                    .map(Task::toString)  // Convert each filtered Task to String
                    .collect(Collectors.toList());
        }
    }

    // Method to mark a task as completed by task name
    public void markTaskAsCompleted(String taskName) {
        for (Task task : tasks) {
            if (task.getName().equalsIgnoreCase(taskName) && !task.isCompleted()) {
                task.markCompleted();
                System.out.println("Task marked as completed: " + task);
                return;
            }
        }
        System.out.println("Task not found or already completed.");
    }

    // Method to mark a task as incomplete by task name
    public void markTaskAsIncomplete(String taskName) {
        for (Task task : tasks) {
            if (task.getName().equalsIgnoreCase(taskName) && task.isCompleted()) {
                task.markIncomplete();
                System.out.println("Task marked as incomplete: " + task);
                return;
            }
        }
        System.out.println("Task not found or already incomplete.");
    }
}
