#include "Todo.h"
#include <iostream>
#include <sstream>
#include <iomanip>

// Constructor
Todo::Todo(int id, const std::string& name, const std::string& category, std::time_t dueDate, int priority)
    : id(id), taskName(name), category(category), dueDate(dueDate), priority(priority), completed(false) {}

// Getters
int Todo::getId() const { return id; }
std::string Todo::getTaskName() const { return taskName; }
std::string Todo::getCategory() const { return category; }
std::time_t Todo::getDueDate() const { return dueDate; }
int Todo::getPriority() const { return priority; }
bool Todo::isCompleted() const { return completed; }
std::vector<std::string> Todo::getSubtasks() const { return subtasks; }

// Setters
void Todo::setTaskName(const std::string& name) { taskName = name; }
void Todo::setCategory(const std::string& category) { this->category = category; }
void Todo::setDueDate(std::time_t dueDate) { this->dueDate = dueDate; }
void Todo::setPriority(int priority) { this->priority = priority; }
void Todo::markCompleted() { completed = true; }
void Todo::addSubtask(const std::string& subtask) { subtasks.push_back(subtask); }

// Display Todo
void Todo::display() const {
    std::cout << "[" << id << "] " << taskName
              << " | Category: " << category
              << " | Due: " << std::put_time(std::localtime(&dueDate), "%Y-%m-%d %H:%M:%S")
              << " | Priority: " << (priority == 1 ? "High" : priority == 2 ? "Medium" : "Low")
              << " | Completed: " << (completed ? "Yes" : "No") << "\n";
    if (!subtasks.empty()) {
        std::cout << "  Subtasks:\n";
        for (const auto& subtask : subtasks) {
            std::cout << "    - " << subtask << "\n";
        }
    }
}

// Serialize Todo for file saving
std::string Todo::serialize() const {
    std::ostringstream oss;
    oss << id << "|" << taskName << "|" << category << "|" << dueDate << "|" << priority << "|" << completed;
    for (const auto& subtask : subtasks) {
        oss << "|" << subtask;
    }
    return oss.str();
}

// Deserialize Todo from saved string
Todo Todo::deserialize(const std::string& serializedTodo) {
    std::istringstream iss(serializedTodo);
    std::string token;
    int id, priority;
    bool completed;
    std::time_t dueDate;
    std::string taskName, category;

    std::getline(iss, token, '|'); id = std::stoi(token);
    std::getline(iss, taskName, '|');
    std::getline(iss, category, '|');
    std::getline(iss, token, '|'); dueDate = static_cast<std::time_t>(std::stoll(token));
    std::getline(iss, token, '|'); priority = std::stoi(token);
    std::getline(iss, token, '|'); completed = (token == "1");

    Todo todo(id, taskName, category, dueDate, priority);
    todo.completed = completed;

    while (std::getline(iss, token, '|')) {
        todo.addSubtask(token);
    }

    return todo;
}
