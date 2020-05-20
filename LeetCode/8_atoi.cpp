#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

class Solution
{
public:
  int ATOI(string str, int mult, int i)
  {
    long long ans = 0;
    for (int j = i; j < str.length(); j++)
    {
      if (!isdigit(str[j]))
        break;
      ans = ans * 10 + str[j] - '0';
      if (ans > INT_MAX)
        return mult * ans < INT_MIN ? INT_MIN : (mult * ans > INT_MAX ? INT_MAX : ans * mult);
    }
    return mult * ans < INT_MIN ? INT_MIN : (mult * ans > INT_MAX ? INT_MAX : ans * mult);
  }
  int myAtoi(string str)
  {
    if (str[0] != ' ' && str[0] != '-' && str[0] != '+' && !isdigit(str[0]))
    {

      return 0;
    }

    int i = 0;
    while (str[i] == ' ')
      i++;

    if (str[i] == '-')
    {
      return ATOI(str, -1, i + 1);
    }
    else if (str[i] == '+')
      return ATOI(str, 1, i + 1);
    return ATOI(str, 1, i);
  }
};

int main() {

  return 0;
}
