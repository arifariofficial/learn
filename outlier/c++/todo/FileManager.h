#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "Todo.h"
#include <vector>
#include <string>

class FileManager {
public:
    // Save todos to a file
    void saveTodos(const std::string& filename, const std::vector<Todo>& todos) const;

    // Load todos from a file
    std::vector<Todo> loadTodos(const std::string& filename) const;
};

#endif
