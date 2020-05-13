#include <bits/stdc++.h>
using namespace std;

class MinMaxStack
{
  // Vector of x, min, max.
  vector<tuple<int, int, int>> st;

public:
  int peek()
  {
    if (st.size() > 0)
      return get<0>(st.back());
    return -1;
  }

  int pop()
  {
    if (st.size() > 0)
    {
      int ans = get<0>(st.back());
      st.pop_back();
      return ans;
    }

    return -1;
  }

  void push(int num)
  {
    if (st.empty())
    {
      st.push_back(tuple<int, int, int>(num, num, num));
      return;
    }

    st.push_back(tuple<int, int, int>(num, min(this->getMin(), num),
                                      max(num, this->getMax())));
  }

  int getMin()
  {
    if (st.size() > 0)
      return get<1>(st.back());
    return -1;
  }

  int getMax()
  {
    if (st.size() > 0)
      return get<2>(st.back());
    return -1;
  }
};
