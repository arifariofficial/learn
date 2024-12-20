#ifndef TODO_H
#define TODO_H

#include <string>
#include <ctime>
#include <vector>

class Todo {
private:
    int id;
    std::string taskName;
    std::string category;
    std::time_t dueDate; // Store as time_t for date/time operations
    int priority;        // 1 = High, 2 = Medium, 3 = Low
    bool completed;
    std::vector<std::string> subtasks;

public:
    // Constructors
    Todo(int id, const std::string& name, const std::string& category, std::time_t dueDate, int priority);

    // Getters
    int getId() const;
    std::string getTaskName() const;
    std::string getCategory() const;
    std::time_t getDueDate() const;
    int getPriority() const;
    bool isCompleted() const;
    std::vector<std::string> getSubtasks() const;

    // Setters
    void setTaskName(const std::string& name);
    void setCategory(const std::string& category);
    void setDueDate(std::time_t dueDate);
    void setPriority(int priority);
    void markCompleted();
    void addSubtask(const std::string& subtask);

    // Display
    void display() const;

    // Serialize/Deserialize (for file saving/loading)
    std::string serialize() const;          // Convert to a string for saving
    static Todo deserialize(const std::string& serializedTodo); // Convert back to Todo
};

#endif
