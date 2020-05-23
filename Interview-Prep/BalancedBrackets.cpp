#include <bits/stdc++.h>
using namespace std;

bool balancedBrackets(string str)
{
  stack<char> st;
  unordered_map<char, char> ht;
  ht.insert({')', '('});
  ht.insert({']', '['});
  ht.insert({'}', '{'});
  for (char ch : str)
  {
    if (!ht.count(ch))
    {
      st.push(ch);
    }
    else if (ht.count(ch) && !st.empty() && st.top() == ht[ch])
    {
      st.pop();
    }
    else
      return false;
  }
  return st.empty();
}
