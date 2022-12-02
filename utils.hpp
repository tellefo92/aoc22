#include<iostream>
#include<vector>
#include<string>
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