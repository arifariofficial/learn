import java.util.ArrayList;
import java.util.Scanner;

public class ToDoApp {
    private final Scanner scanner;
    private final ArrayList<Task> tasks;

    public ToDoApp() {
        tasks = new ArrayList<>();
        scanner = new Scanner(System.in);
    }

    public static void main(String[] args) {
        ToDoApp app = new ToDoApp();
        app.start();
    }

    public void start() {
        System.out.println("Welcome to the To-Do App!");

        while (true) {
            System.out.println("\nChoose an option:");
            System.out.println("1. Add a task");
            System.out.println("2. View tasks");
            System.out.println("3. Mark a task as completed");
            System.out.println("4. Delete a task");
            System.out.println("5. Exit");

            int choice = scanner.nextInt();
            scanner.nextLine();

            switch (choice) {
                case 1:
                    addTask();
                    break;
                case 2:
                    viewTasks();
                    break;
                case 3:
                    markTaskCompleted();
                    break;
                case 4:
                    deleteTask();
                    break;
                case 5:
                    System.out.println("Goodbye!");
                    System.exit(0);
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        }
    }

    private void addTask() {
        System.out.print("Enter a task description: ");
        String description = scanner.nextLine();

        Task task = new Task(description);
        tasks.add(task);
        System.out.println("Task added successfully.");
    }

    private void viewTasks() {
        if (tasks.isEmpty()) {
            System.out.println("No tasks found.");
            return;
        }

        System.out.println("\nTasks:");
        for (Task task : tasks) {
            System.out.println(task);
        }
    }

    private void markTaskCompleted() {
        System.out.print("Enter the task number to mark as completed: ");
        int taskNumber = scanner.nextInt();
        scanner.nextLine();

        if (taskNumber <= 0 || taskNumber > tasks.size()) {
            System.out.println("Invalid task number. Please try again.");
            return;
        }

        Task task = tasks.get(taskNumber - 1);
        task.markAsCompleted();
        System.out.println("Task marked as completed.");
    }

    private void deleteTask() {
        System.out.print("Enter the task number to delete: ");
        int taskNumber = scanner.nextInt();
        scanner.nextLine();

        if (taskNumber <= 0 || taskNumber > tasks.size()) {
            System.out.println("Invalid task number. Please try again.");
            return;
        }

        tasks.remove(taskNumber - 1);
        System.out.println("Task deleted successfully.");
    }
}
