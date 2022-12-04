#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
#include<cmath>
#include<numeric>

// Python style modulo - Always returns positive or 0
int pmod(const int& a, const int& b){
    try {
        if (b != 0) {
            return (b + (a % b)) % b;
        } else {
            throw -1;
        }
    }
    catch(...) {
        std::cout << "Cannot divide by 0!" << std::endl;
        exit(-1);
    }
}

// Function to split string by delimiter -> returns vector of elements
template <typename T>
std::vector<T> splitString(std::string str, std::string delimiter) {
    // Remove whitespace from delimiter
    std::size_t found = delimiter.find(' ');
    while (found != std::string::npos) {
        delimiter.erase(found);
        found = delimiter.find(' ');
    }

    // Replace occurances of any remaining characters in delimiter from string with whitespace
    found = str.find_first_of(delimiter);
    while (found != std::string::npos) {
        str[found] = ' ';
        found = str.find_first_of(delimiter);
    }

    // Stream elements into e and push to result
    std::vector<T> result;
    std::istringstream is(str);
    T e;
    while (is >> e) result.push_back(e);

    return result;    
}

// Function to print vector elements on a single line, separated by whitespace
template <typename T> std::ostream& operator<<(std::ostream& os, const std::vector<T> vec) {
    for (auto element: vec) {
        os << element << " ";
    }
    return os;
}