#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
string S;

int eval() {
  if ('a' <= S[N] and S[N] <= 'j') {
    int p = N++;  // a
    return (M>>(S[p] - 'a'))&1;
  }
  if (S[N] == '!') {
    ++N;  // !
    return 1 - eval();
  }
  // S[N] == '('
  ++N;  // (
  int tmp = eval();
  int res = 0;
  while (S[N] != ')') {
    if (S[N] == '|') {
      ++N;  // |
      res |= tmp;
      tmp = eval();
    }
    else {  // S[N] == '&'
      ++N;  // &
      tmp &= eval();
    }
  }
  ++N;  // )
  res |= tmp;
  return res;
}

int main() {
  int tcas;
  cin >> tcas;
  for (int cas = 1; cas <= tcas; ++cas) {
    string a, b;
    cin >> a >> b;

    a = "(" + a + ")";
    b = "(" + b + ")";

    bool ok = true;
    for (M = 0; M < (1<<10); ++M) {
      swap(S, a);
      N = 0;
      int ta = eval();
      swap(S, a);

      swap(S, b);
      N = 0;
      int tb = eval();
      swap(S, b);

      if (ta != tb) {
        ok = false;
        break;
      }
    }

    cout << "Case " << cas << ": ";
    if (ok) cout << "Equivalent" << endl;
    else cout << "Not Equivalent" << endl;
  }
}
