#include "utils.hpp"

using namespace std;

/*
Other ideas:
sum += [x = (b-'X') - (a-'A'), y = b-'W']() {return y + [x=x]() {return 6 - (6>>max(0,pmod(x, 3)-1);}();}();
*/

int main() {
    char a, b;
    int sum = 0, sum2 = 0;
    auto outcome = [&] (char& a, char& b) {
        int res = (b-'X') - (a-'A');
        return res == 1 || res == -2 ? 6 : res == 0 ? 3 : 0;
    };
    auto shape = [&] (char& a, char& b) {
        int res = a-'@' + b-'Y';
        return res == 0 ? 3 : res == 4 ? 1 : res;
    };
    while (cin >> a >> b) {
        sum += b-'W' + outcome(a, b);
        sum2 += (b-'X') * 3 + shape(a, b);
    }
    cout << sum << endl;
    cout << sum2 << endl;
}