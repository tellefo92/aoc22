#include "utils.hpp"

using namespace std;

int main() {
    int sum=0, sum2=0, counter=0;
    string elf, ls, rs;
    vector<string> elves;
    auto priority = [](char c) {return int(c) >= 97 ? int(c)-96 : int(c)-64+26;};
    while (cin >> elf) {
        elves.push_back(elf);
        // Split string into two halves
        ls = elf.substr(0, elf.length()/2);
        rs = elf.substr(elf.length()/2);
        // Find shared item type
        for (auto& c: ls) {
            if (rs.find(c) != string::npos) {
                sum += priority(c);
                break;
            }
        }
        // Group is done
        if (counter == 2) {
            // Sort string vector such that the longest string is at the front
            sort(elves.begin(), elves.end(), [](const auto& a, const auto& b) {return a.size() > b.size();});
            // Find badge
            for (size_t idx=0; idx<elves[0].length(); idx++) {
                char c = elves[0][idx];
                if (elves[1].find(c) != string::npos && elves[2].find(c) != string::npos) {
                    sum2 += priority(c);
                    break;
                }
            }
            // Clear vector and reset counter
            elves.clear();
            counter = 0;
        } else {
            ++counter;
        }
    }
    cout << sum << endl;
    cout << sum2 << endl;
}