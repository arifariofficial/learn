#include <string>
#include <chrono>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <ctime>


// Luokka, joka edustaa yksittäistä tehtävää.
class Task {
private:
    std::string description;
    std::string category;
    std::chrono::system_clock::time_point creationTime;
    std::chrono::system_clock::time_point updateTime;

public:
    // Konstruktori, joka alustaa tehtävän kuvauksen, kategorian sekä luomis- ja päivitysajat.
    Task(const std::string& desc, const std::string& cat)
        : description(desc), category(cat), creationTime(std::chrono::system_clock::now()), updateTime(std::chrono::system_clock::now()) {}

    // Päivitetään tehtävän kuvaus ja tallennetaan päivitysaika.
    void updateDescription(const std::string& newDesc) {
        description = newDesc;
        updateTime = std::chrono::system_clock::now();
    }

    // Päivitetään tehtävän kategoria ja tallennetaan päivitysaika.
    void updateCategory(const std::string& newCat) {
        category = newCat;
        updateTime = std::chrono::system_clock::now();
    }

    // Palautetaan tehtävän kuvaus.
    std::string getDescription() const { return description; }

    // Palautetaan tehtävän kategoria.
    std::string getCategory() const { return category; }

    // Palautetaan tehtävän luomisaika.
    std::chrono::system_clock::time_point getCreationTime() const { return creationTime; }

    // Palautetaan tehtävän päivitysaika.
    std::chrono::system_clock::time_point getUpdateTime() const { return updateTime; }
};

// Luokka, joka hallitsee tehtävälistaa.
class TaskManager {
private:
    std::vector<Task> tasks;

public:
    // Lisää uusi tehtävä listaan.
    void addTask(const Task& task) {
        tasks.push_back(task);
    }

    // Poistaa tehtävän listasta annetun indeksin perusteella.
    void removeTask(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks.erase(tasks.begin() + index);
        } else {
            std::cout << "Invalid index.\n";
        }
    }

    // Päivittää tehtävän kuvauksen ja kategorian annetun indeksin perusteella.
    void updateTask(int index, const std::string& newDesc, const std::string& newCat) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].updateDescription(newDesc);
            tasks[index].updateCategory(newCat);
        } else {
            std::cout << "Invalid index.\n";
        }
    }

    // Näyttää kaikki tehtävät sekä niiden luomis- ja päivitysajat.
    void displayTasks() const {
        for (const auto& task : tasks) {
            std::cout << "Description: " << task.getDescription() << ", Category: " << task.getCategory() << ", ";
            std::cout << "Created: " << formatTime(task.getCreationTime()) << ", Updated: " << formatTime(task.getUpdateTime()) << "\n";
        }
    }

    // Näyttää tehtävät annetun kategorian perusteella.
    void displayTasksByCategory(const std::string& cat) const {
        for (const auto& task : tasks) {
            if (task.getCategory() == cat) {
                std::cout << "Description: " << task.getDescription() << ", Category: " << task.getCategory() << "\n";
            }
        }
    }

private:
    // Apuohjelma, joka muuntaa ajan merkkijonoksi.
    std::string formatTime(const std::chrono::system_clock::time_point& time) const {
        std::time_t timeT = std::chrono::system_clock::to_time_t(time);
        std::tm tm = *std::localtime(&timeT);
        std::ostringstream oss;
        oss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
        return oss.str();
    }
};

// Tulostaa valikon vaihtoehdot käyttäjälle.
void printMenu() {
    std::cout << "1. Add Task\n";
    std::cout << "2. Remove Task\n";
    std::cout << "3. Update Task\n";
    std::cout << "4. Display All Tasks\n";
    std::cout << "5. Display Tasks by Category\n";
    std::cout << "6. Exit\n";
}

int main() {
    TaskManager manager;
    int choice;

    while (true) {
        printMenu();

        std::cout << "Enter your choice: ";
        if (!(std::cin >> choice)) {
            std::cin.clear();  // Clear error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore invalid input
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        std::cin.ignore();  // Ignore newline characters

        switch (choice) {
            case 1: {
                // Tehtävän lisääminen
                std::string desc, cat;
                std::cout << "Enter task description: ";
                std::getline(std::cin, desc);
                std::cout << "Enter task category: ";
                std::getline(std::cin, cat);
                manager.addTask(Task(desc, cat));
                break;
            }
            case 2: {
                // Tehtävän poistaminen
                int index;
                std::cout << "Enter task index to remove: ";
                if (!(std::cin >> index)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input. Please enter a valid index.\n";
                    break;
                }
                manager.removeTask(index);
                break;
            }
            case 3: {
                // Tehtävän päivittäminen
                int index;
                std::string newDesc, newCat;
                std::cout << "Enter task index to update: ";
                if (!(std::cin >> index)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input. Please enter a valid index.\n";
                    break;
                }
                std::cin.ignore();
                std::cout << "Enter new description: ";
                std::getline(std::cin, newDesc);
                std::cout << "Enter new category: ";
                std::getline(std::cin, newCat);
                manager.updateTask(index, newDesc, newCat);
                break;
            }
            case 4:
                // Tehtävien näyttäminen
                manager.displayTasks();
                break;
            case 5: {
                // Tehtävien näyttäminen kategorian mukaan
                std::string cat;
                std::cout << "Enter category to filter by: ";
                std::getline(std::cin, cat);
                manager.displayTasksByCategory(cat);
                break;
            }
            case 6:
                return 0;  // Lopeta ohjelma
            default:
                std::cout << "Invalid choice. Please select a valid option.\n";
                break;
        }
    }

    return 0;
}