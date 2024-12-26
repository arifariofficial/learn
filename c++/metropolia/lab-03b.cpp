/*
Write a function called backwards that takes a reference to a vector of strings as a parameter. The function
reverses all strings in the vector and then sorts the vector in descending order. Hint: algorithms: sort, reverse

Write a program that reads strings from the keyboard. There is no upper limit for the number of strings. All
strings are stored in a vector of strings. The data entry phase terminates when the user enters the “stop” string.
This termination string is not stored in the vector.
When all strings have been entered the program prints the vector elements on separate lines. Then program calls
backwards and passes the vector as parameter. After the call the program prints the vector again.
For example:
If original content of the vector is:
acb
Doom
Beast
option
dentax
After calling backwards the vector contains:
xatned
tsaeB
noitpo
mooD
bca
*/

#include <iostream>
#include <vector>
#include <algorithm>

// Function to reverse individual strings and then sort in descending order
void backwards(std::vector<std::string> &vec) {
    // Reverse each individual string
    for (auto &s: vec) {
        std::ranges::reverse(s);
    }

    // Sort the vector in descending order
    std::ranges::sort(vec, std::greater<>()); // Use transparent functor with ranges
}

int main() {
    std::vector<std::string> strings;
    std::string input;

    std::cout << "Enter strings (or 'stop' to end): ";
    while (std::cin >> input && input != "stop") {
        strings.push_back(input);
        std::cout << "Enter strings (or 'stop' to end): ";
    }

    std::cout << "Original content of the vector:" << std::endl;
    for (const auto &s: strings) {
        std::cout << s << std::endl;
    }

    backwards(strings);

    std::cout << "Content of the vector after calling backwards:" << std::endl;
    for (const auto &s: strings) {
        std::cout << s << std::endl;
    }

    return 0;
}