#ifndef TODOMANAGER_H
#define TODOMANAGER_H

#include "Todo.h"
#include <vector>
#include <string>

class TodoManager {
private:
    std::vector<Todo> todos;
    int nextId;

public:
    TodoManager(); // Constructor initializes with an empty list and ID counter

    // CRUD Operations
    void addTodo(const std::string& taskName, const std::string& category, std::time_t dueDate, int priority);
    bool deleteTodo(int id);
    bool updateTodo(int id, const std::string& taskName, const std::string& category, std::time_t dueDate, int priority, bool completed);
    Todo* getTodoById(int id);

    // Search and Filter
    std::vector<Todo> searchByKeyword(const std::string& keyword) const;
    std::vector<Todo> filterByCategory(const std::string& category) const;
    std::vector<Todo> filterByPriority(int priority) const;

    // Display Todos
    void displayAllTodos() const;

    // File Persistence
    void saveTodosToFile(const std::string& filename) const;
    void loadTodosFromFile(const std::string& filename);
};

#endif
