#include <bits/stdc++.h>
using namespace std;

class Time
{
  public:
  string whatTime(int timeInSec)
  {
    string s = "";
    int time  = 3600;
    for (int i = 0; i < 3; i++)
    {
      s += to_string(timeInSec / time);
      s += ":";
      time /= 60;
    }
    s.pop_back();
    return s;
  }
};