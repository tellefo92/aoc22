#include "utils.hpp"

using namespace std;

int main() {
  int N = 9;
  vector<vector<char>> crates(N);
  string line;
  while (getline(cin, line)) {
    cout << line << endl;
    if (line[1] == '1') {
      break;
    }
    for (int i = 0; i < N; i++) {
      if (line[1 + 4 * i] != ' ') {
        crates[i].insert(crates[i].begin(), line[1 + 4 * i]);
      }
    }
  }
  getline(cin, line);
  
  vector<vector<char>> crates2 = crates;
  vector<char> tmp;
  vector<string> instructions;
  int n, F, T;
  while (getline(cin, line)) {
      instructions = splitString<string>(line, "-");
      n = stoi(instructions[1]);
      F = stoi(instructions[3]) - 1;
      T = stoi(instructions[5]) - 1;
      for (int i=0; i < n; i++) {
          tmp.push_back(crates2[F].back());
          crates2[F].pop_back();
          crates[T].push_back(crates[F].back());
          crates[F].pop_back();
      }
      for (int i=0; i<n; i++) {
          crates2[T].push_back(tmp.back());
          tmp.pop_back();
      }
  }
  for (int i=0; i<N;i++) {
      cout << crates[i].back();
  }
  cout << endl;
  for (int i=0; i<N;i++) {
      cout << crates2[i].back();
  }
  cout << endl;
}
