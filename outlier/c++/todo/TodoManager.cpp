#include "TodoManager.h"
#include "FileManager.h" // We will implement this later for file persistence
#include <iostream>
#include <algorithm>

// Constructor
TodoManager::TodoManager() : nextId(1) {}

// Add a new todo
void TodoManager::addTodo(const std::string& taskName, const std::string& category, std::time_t dueDate, int priority) {
    Todo newTodo(nextId++, taskName, category, dueDate, priority);
    todos.push_back(newTodo);
    std::cout << "Todo added successfully with ID: " << newTodo.getId() << "\n";
}

// Delete a todo by ID
bool TodoManager::deleteTodo(int id) {
    auto it = std::remove_if(todos.begin(), todos.end(), [id](const Todo& todo) {
        return todo.getId() == id;
    });

    if (it != todos.end()) {
        todos.erase(it, todos.end());
        std::cout << "Todo with ID " << id << " deleted successfully.\n";
        return true;
    } else {
        std::cout << "Todo with ID " << id << " not found.\n";
        return false;
    }
}

// Update an existing todo
bool TodoManager::updateTodo(int id, const std::string& taskName, const std::string& category, std::time_t dueDate, int priority, bool completed) {
    for (auto& todo : todos) {
        if (todo.getId() == id) {
            todo.setTaskName(taskName);
            todo.setCategory(category);
            todo.setDueDate(dueDate);
            todo.setPriority(priority);
            if (completed) todo.markCompleted();
            std::cout << "Todo with ID " << id << " updated successfully.\n";
            return true;
        }
    }
    std::cout << "Todo with ID " << id << " not found.\n";
    return false;
}

// Get a todo by ID
Todo* TodoManager::getTodoById(int id) {
    for (auto& todo : todos) {
        if (todo.getId() == id) {
            return &todo;
        }
    }
    return nullptr;
}

// Search todos by keyword
std::vector<Todo> TodoManager::searchByKeyword(const std::string& keyword) const {
    std::vector<Todo> results;
    for (const auto& todo : todos) {
        if (todo.getTaskName().find(keyword) != std::string::npos || todo.getCategory().find(keyword) != std::string::npos) {
            results.push_back(todo);
        }
    }
    return results;
}

// Filter todos by category
std::vector<Todo> TodoManager::filterByCategory(const std::string& category) const {
    std::vector<Todo> results;
    for (const auto& todo : todos) {
        if (todo.getCategory() == category) {
            results.push_back(todo);
        }
    }
    return results;
}

// Filter todos by priority
std::vector<Todo> TodoManager::filterByPriority(int priority) const {
    std::vector<Todo> results;
    for (const auto& todo : todos) {
        if (todo.getPriority() == priority) {
            results.push_back(todo);
        }
    }
    return results;
}

// Display all todos
void TodoManager::displayAllTodos() const {
    if (todos.empty()) {
        std::cout << "No todos available.\n";
        return;
    }

    std::cout << "\n--- All Todos ---\n";
    for (const auto& todo : todos) {
        todo.display();
    }
}

// Save todos to file
void TodoManager::saveTodosToFile(const std::string& filename) const {
    FileManager fileManager;
    fileManager.saveTodos(filename, todos);
    std::cout << "Todos saved to file: " << filename << "\n";
}

// Load todos from file
void TodoManager::loadTodosFromFile(const std::string& filename) {
    FileManager fileManager;
    todos = fileManager.loadTodos(filename);
    nextId = todos.empty() ? 1 : todos.back().getId() + 1;
    std::cout << "Todos loaded from file: " << filename << "\n";
}
