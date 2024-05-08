/**
 * @brief: Broad Priority Search Algorithm
 */
#include <iostream>
#include <map>
#include <vector>
#include "com/timer.h"

struct Person {
    std::string name;
    bool is_lawyer = false;

public:
    Person(void) {
        name = "";
        is_lawyer = false;
    }

    Person(std::string name, bool flag) : name(name), is_lawyer(flag) {}

    Person(const Person& rhs) {
        name = rhs.name;
        is_lawyer = rhs.is_lawyer;
    }

    Person& operator=(const Person& rhs) {
        name = rhs.name;
        is_lawyer = rhs.is_lawyer;
        return *this;
    }
};

using FriendsList = std::vector<Person>;
std::map<std::string, FriendsList> g_relationship;

void generateData() {
    g_relationship["1"] = {{"2", false}, {"11", true}, {"12", false}, {"13", false}, {"14", false}, {"15", false}};
    g_relationship["2"] = {{"21", false}, {"22", false}, {"23", false}, {"24", false}, {"25", false}};
    g_relationship["3"] = {{"1", false}, {"11", false}, {"11", true}, {"31", false}, {"34", false}, {"35", false}};
    g_relationship["4"] = {{"3", false}, {"11", true}, {"12", false}, {"33", false}, {"41", false}, {"1", false}};

    for(auto &it : g_relationship) {
        std::cout << it.first << " : [";
        for(auto& it1 : it.second)
            std::cout << "{" << it1.name << ", " << std::boolalpha << it1.is_lawyer << "}, ";
        std::cout << "]\n";
    }
}


int main(int argc, char* argv[]) {
    generateData();
    return 0;
}
