import java.time.LocalDateTime;

public class Task {
    private String name;
    private String description;
    private boolean completed;
    private String category;
    private LocalDateTime createdTime;
    private LocalDateTime updatedTime;

    // Constructor
    public Task(String name, String description, String category) {
        this.name = name;
        this.description = description;
        this.category = category;
        this.completed = false;
        this.createdTime = LocalDateTime.now(); // Set creation time
        this.updatedTime = LocalDateTime.now(); // Set updated time to creation time
    }

    // Getters and setters
    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
        updateTime(); // Update the updated time whenever task is modified
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
        updateTime(); // Update the updated time whenever task is modified
    }

    public boolean isCompleted() {
        return completed;
    }

    public void markCompleted() {
        this.completed = true;
        updateTime(); // Update the updated time whenever task is marked as completed
    }

    public void markIncomplete() {
        this.completed = false;
        updateTime(); // Update the updated time whenever task is marked as incomplete
    }

    public String getCategory() {
        return category;
    }

    public void setCategory(String category) {
        this.category = category;
        updateTime(); // Update the updated time whenever category is changed
    }

    // Method to update the updatedTime
    private void updateTime() {
        this.updatedTime = LocalDateTime.now();
    }

    // String representation of the task
    @Override
    public String toString() {
        return String.format("%s - %s (Category: %s) %s\nCreated: %s, Updated: %s",
                name, description, category, completed ? "(Completed)" : "(Incomplete)",
                createdTime, updatedTime);
    }
}
