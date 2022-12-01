#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<numeric>

using namespace std;

int main() {
    string s;
    vector<int> p;
    vector<vector<int>> X;
    while (getline(cin, s)) {
        if (s == "") {
            X.push_back(p);
            p.clear();
        } else {
            p.push_back(stoi(s));
        }
        if (cin.eof() && p.size() > 0) X.push_back(p);
    }
    auto sp = [](vector<int> p) {
        return reduce(p.begin(), p.end());
    };
    p.clear();
    for (int i=0; i < X.size(); i++) {
        p.push_back(sp(X[i]));
    }
    sort(p.begin(), p.end());
    cout << p.back() << endl;
    cout << reduce(p.end()-3, p.end()) << endl;
}