package models;

import java.io.Serializable;
import java.time.LocalDate;

public class Task implements Serializable {
    private static final long serialVersionUID = 1L;

    private int id;
    private String title;
    private String description;
    private String category;
    private LocalDate dueDate;
    private boolean isCompleted;
    private int priority;

    public Task(int id, String title, String description, String category, LocalDate dueDate, int priority) {
        this.id = id;
        this.title = title;
        this.description = description;
        this.category = category;
        this.dueDate = dueDate;
        this.priority = priority;
        this.isCompleted = false;
    }

    public int getId() {
        return id;
    }

    public String getTitle() {
        return title;
    }

    public String getDescription() {
        return description;
    }

    public String getCategory() {
        return category;
    }

    public LocalDate getDueDate() {
        return dueDate;
    }

    public boolean isCompleted() {
        return isCompleted;
    }

    public int getPriority() {
        return priority;
    }

    public void setCompleted(boolean completed) {
        isCompleted = completed;
    }

    @Override
    public String toString() {
        return "Tehtävä ID: " + id +
                "\nOtsikko: " + title +
                "\nKuvaus: " + description +
                "\nKategoria: " + category +
                "\nMääräpäivä: " + dueDate +
                "\nPrioriteetti: " + getPriorityText(priority) +
                "\nTila: " + (isCompleted ? "Valmis" : "Kesken") +
                "\n-----------------------";
    }

    private String getPriorityText(int priority) {
        switch (priority) {
            case 1:
                return "Korkea";
            case 2:
                return "Keskitaso";
            case 3:
                return "Matala";
            default:
                return "Tuntematon";
        }
    }
}
