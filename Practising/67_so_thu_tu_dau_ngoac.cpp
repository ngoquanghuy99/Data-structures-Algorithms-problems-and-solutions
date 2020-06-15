#include <bits/stdc++.h>
using namespace std;

void process(string s) {
  int Count = 1;
  stack<int> st;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '(') {
      cout << Count << " ";
      st.push(Count);
      Count++;
    } else if (s[i] == ')') {
      cout << st.top() << " ";
      st.pop();
    }
  }
  cout << endl;
}

int main() {
  string s;
  while (cin >> s) {
    process(s);
  }
  return 0;
}
