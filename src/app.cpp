#include <iostream>
#include <string>
#include <set>
#include <experimental/source_location>
#include "basic/app.h"

void log(std::string_view message,
         const std::experimental::source_location& location = std::experimental::source_location::current()) {
    std::cout << "info:"
              << location.file_name() << ":"
              << location.line() << " "
              << message << '\n';
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    auto p = person{.name ="bingo", .age = 23};
    std::cout << "P.name = " << p.name << std::endl;
    log("Logging Hello world!");
    return 0;
}


