#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<numeric>

using namespace std;

int main() {
    string s;
    int sum = 0;
    vector<int> p;
    while (getline(cin, s)) {
        sum += s != "" ? stoi(s) : 0;
        if (cin.eof() && sum > 0 || s == "") {
            p.push_back(sum);
            sum = 0;
        }
    }
    sort(p.begin(), p.end());
    cout << p.back() << endl;
    cout << reduce(p.end()-3, p.end()) << endl;
}