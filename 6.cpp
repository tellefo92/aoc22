#include "utils.hpp"

using namespace std;

int main() {
    string line;
    cin >> line;
    set<char> sc;
    for (size_t i = 0; i < line.length() - 3; i++) {
        for (size_t j=i; j<min(size_t(i+4), line.length()); j++) {
            sc.insert(line[j]);
        }
        if (sc.size() == 4) {
            cout << i+4 << endl;
            break;
        }
        sc.clear();
    }
    sc.clear();
    for (size_t i = 0; i < line.length() - 13; i++) {
        for (size_t j=i; j<min(size_t(i+14), line.length()); j++) {
            sc.insert(line[j]);
        }
        if (sc.size() == 14) {
            cout << i+14 << endl;
            sc.clear();
            break;
        }
        sc.clear();
    }
}
