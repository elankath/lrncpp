#include <iostream>
#include <string>
#include <set>
#include "basic/app.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    auto p = person{.name ="bingo", .age = 23};
    std::cout << p.name << std::endl;
    return 0;
}


