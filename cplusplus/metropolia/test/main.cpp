#include <iostream>
#include <map>

int main() {
    std::map<std::string, int> myMap1;
    myMap1["kevin"] = 123;
    myMap1["john"] = 21;
    myMap1["amy"] = 23;

    std::map<std::string, int> myMap2 = {
        {"kevin", 123},
        {"john", 21},
        {"amy", 33}
    };

    for (auto &[fst, snd]: myMap1) {  // accessing key-value pairs using range-based for loop
        std::cout << fst << ":" << snd << std::endl;
    }

    int val1 = myMap1.at("kevin"); // accessing value by key

    myMap1.insert({"ari", 45}); // adding new key-value pair

    myMap2.emplace(ari, 33);    // adding new key-value pair using emplace


    return 0;
}