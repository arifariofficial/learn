#include "FileManager.h"
#include <fstream>
#include <iostream>
#include <sstream>

// Save todos to a file
void FileManager::saveTodos(const std::string& filename, const std::vector<Todo>& todos) const {
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Error: Unable to open file for writing: " << filename << "\n";
        return;
    }

    for (const auto& todo : todos) {
        outFile << todo.serialize() << "\n"; // Write each Todo in serialized format
    }

    outFile.close();
    if (outFile.good()) {
        std::cout << "Todos successfully saved to " << filename << "\n";
    } else {
        std::cerr << "Error: Failed to save todos to " << filename << "\n";
    }
}

// Load todos from a file
std::vector<Todo> FileManager::loadTodos(const std::string& filename) const {
    std::vector<Todo> todos;
    std::ifstream inFile(filename);

    if (!inFile) {
        std::cerr << "Warning: Unable to open file for reading: " << filename << "\n";
        return todos; // Return empty vector if file not found
    }

    std::string line;
    while (std::getline(inFile, line)) {
        if (!line.empty()) {
            try {
                todos.push_back(Todo::deserialize(line)); // Deserialize each line into a Todo
            } catch (const std::exception& e) {
                std::cerr << "Error: Failed to deserialize line: " << line << "\n";
            }
        }
    }

    inFile.close();
    return todos;
}
