#include <iostream>
#include <string>
#include <experimental/source_location>
#include "learn/learn.hpp"
#include <iterator>
#include <sstream>
#include <set>
#include <vector>
#include "learn/prettyprint.hpp"

void log(std::string_view message,
         const std::experimental::source_location& location = std::experimental::source_location::current()) {
    std::cout << "info:"
              << location.file_name() << ":"
              << location.line() << " "
              << message << '\n';
}

std::ostream& operator<<(std::ostream& out, const person& p) {
    return out << "(person [" << p.name << "," << p.age << "])";
}

[[maybe_unused]] void designated_initializers() {
    std::cout << "-- designated initializer for Person" << std::endl;
    auto p = person{.name ="bingo", .age = 23};
    std::cout << p << std::endl;
}

[[maybe_unused]] void source_location() {
    log("Logging Hello world!");
}

[[maybe_unused]] void set_remove_dups_demo() {
    using namespace std;
    string const input{"a a a b c foo bar foobar foo bar bar"};
    set<string> s1;
    std::istringstream instream(input);
    istream_iterator<string> it1 {cin};
    istream_iterator<string> end;
    copy(it1, end, inserter(s1, s1.end()));
}


void vector_remove_erase_idiom() {
    using namespace std;
    vector<int> v {1, 2, 3, 2, 5, 2, 6, 2, 4, 8};
    cout << "Original      : " << v << endl;
    const auto new_end = remove(begin(v), end(v), 2);
    cout << "After Remove  : " << v << endl;
    v.erase(new_end, end(v));
    cout << "After Erase   : " << v << endl;
    const auto is_odd = [](int i) { return i % 2 != 0; };
    v.erase(remove_if(begin(v), end(v), is_odd), end(v));
    cout << "After Odd Del : " << v << endl;

}

int main() {
//    designated_initializers();
//    set_remove_dups_demo();
    vector_remove_erase_idiom();
    return 0;
}


