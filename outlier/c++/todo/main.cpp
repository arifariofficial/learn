#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <sstream>

#include "TodoManager.h"

void printMainMenu() {
    std::cout << "\n--- Todo Application ---\n";
    std::cout << "1. Add Todo\n";
    std::cout << "2. Delete Todo\n";
    std::cout << "3. Update Todo\n";
    std::cout << "4. Display All Todos\n";
    std::cout << "5. Search Todos by Keyword\n";
    std::cout << "6. Filter Todos by Category\n";
    std::cout << "7. Filter Todos by Priority\n";
    std::cout << "8. Mark Todo as Completed\n";
    std::cout << "9. Save Todos to File\n";
    std::cout << "10. Load Todos from File\n";
    std::cout << "0. Exit\n";
    std::cout << "Enter your choice: ";
}

// Helper function to input a date in the format YYYY-MM-DD
std::time_t inputDate() {
    std::tm tm = {};
    std::cout << "Enter due date (YYYY-MM-DD): ";
    std::string date;
    std::cin >> date;

    std::istringstream ss(date);
    ss >> std::get_time(&tm, "%Y-%m-%d");
    if (ss.fail()) {
        std::cerr << "Invalid date format. Using today's date as default.\n";
        return std::time(nullptr); // Return current date
    }

    return std::mktime(&tm);
}

int main() {
    TodoManager manager;
    const std::string filename = "todos.txt";
    bool running = true;

    // Load todos from file at startup
    manager.loadTodosFromFile(filename);

    while (running) {
        printMainMenu();

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: { // Add Todo
                std::cin.ignore(); // Ignore leftover newline
                std::string taskName, category;
                int priority;

                std::cout << "Enter task name: ";
                std::getline(std::cin, taskName);

                std::cout << "Enter category: ";
                std::getline(std::cin, category);

                std::cout << "Enter priority (1 = High, 2 = Medium, 3 = Low): ";
                std::cin >> priority;

                std::time_t dueDate = inputDate();

                manager.addTodo(taskName, category, dueDate, priority);
                break;
            }
            case 2: { // Delete Todo
                int id;
                std::cout << "Enter Todo ID to delete: ";
                std::cin >> id;

                manager.deleteTodo(id);
                break;
            }
            case 3: { // Update Todo
                int id, priority;
                std::cin.ignore(); // Ignore leftover newline
                std::string taskName, category;
                bool completed;

                std::cout << "Enter Todo ID to update: ";
                std::cin >> id;

                std::cin.ignore(); // Ignore leftover newline
                std::cout << "Enter new task name: ";
                std::getline(std::cin, taskName);

                std::cout << "Enter new category: ";
                std::getline(std::cin, category);

                std::cout << "Enter new priority (1 = High, 2 = Medium, 3 = Low): ";
                std::cin >> priority;

                std::time_t dueDate = inputDate();

                std::cout << "Mark as completed? (1 = Yes, 0 = No): ";
                std::cin >> completed;

                manager.updateTodo(id, taskName, category, dueDate, priority, completed);
                break;
            }
            case 4: { // Display All Todos
                manager.displayAllTodos();
                break;
            }
            case 5: { // Search Todos by Keyword
                std::cin.ignore(); // Ignore leftover newline
                std::string keyword;

                std::cout << "Enter keyword to search: ";
                std::getline(std::cin, keyword);

                auto results = manager.searchByKeyword(keyword);
                if (results.empty()) {
                    std::cout << "No todos found matching the keyword.\n";
                } else {
                    for (const auto& todo : results) {
                        todo.display();
                    }
                }
                break;
            }
            case 6: { // Filter Todos by Category
                std::cin.ignore(); // Ignore leftover newline
                std::string category;

                std::cout << "Enter category to filter: ";
                std::getline(std::cin, category);

                auto results = manager.filterByCategory(category);
                if (results.empty()) {
                    std::cout << "No todos found in this category.\n";
                } else {
                    for (const auto& todo : results) {
                        todo.display();
                    }
                }
                break;
            }
            case 7: { // Filter Todos by Priority
                int priority;
                std::cout << "Enter priority to filter (1 = High, 2 = Medium, 3 = Low): ";
                std::cin >> priority;

                auto results = manager.filterByPriority(priority);
                if (results.empty()) {
                    std::cout << "No todos found with this priority.\n";
                } else {
                    for (const auto& todo : results) {
                        todo.display();
                    }
                }
                break;
            }
            case 8: { // Mark Todo as Completed
                int id;
                std::cout << "Enter Todo ID to mark as completed: ";
                std::cin >> id;

                Todo* todo = manager.getTodoById(id);
                if (todo) {
                    todo->markCompleted();
                    std::cout << "Todo marked as completed.\n";
                } else {
                    std::cout << "Todo not found.\n";
                }
                break;
            }
            case 9: { // Save Todos to File
                manager.saveTodosToFile(filename);
                break;
            }
            case 10: { // Load Todos from File
                manager.loadTodosFromFile(filename);
                break;
            }
            case 0: { // Exit
                running = false;
                manager.saveTodosToFile(filename); // Save todos before exiting
                std::cout << "Exiting Todo Application. Goodbye!\n";
                break;
            }
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
