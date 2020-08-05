#include<iostream>
#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

struct Fraction
{
  int sign;
  int numerator;
  int denominator;
};

class Solution
{
  void Evaluate(stack<Fraction> &st)
  {
    if (st.size() < 2)
      return;

    while (st.size() >= 2)
    {
      Fraction f1 = st.top();
      st.pop();
      Fraction f2 = st.top();
      st.pop();
      Fraction f3({0, 0, 0});
      f3.numerator = f1.numerator * f1.sign * f2.denominator + f2.numerator * f2.sign * f1.denominator;
      f3.denominator = f1.denominator * f2.denominator;
      f3.sign = 1.0;
      if (f3.numerator < 0)
      {
        f3.sign = -1;
        f3.numerator = abs(f3.numerator);
      }

      int divisor = gcd(f3.numerator, f3.denominator);
      f3.numerator /= divisor;
      f3.denominator /= divisor;
      st.push(f3);
    }
  }

public:
  string fractionAddition(string expression)
  {
    stack<Fraction> st;
    int i = 0;
    while (i < expression.length())
    {
      Fraction fraction({1, 0, 0});
      if (expression[i] == '-' || expression[i] == '+')
      {
        fraction.sign = (expression[i] == '-') ? -1 : 1;
        i++;
      }

      while (isdigit(expression[i]))
      {
        fraction.numerator = fraction.numerator * 10 + (expression[i] - '0');
        i++;
      }

      // Skip division sign.
      i++;

      while (isdigit(expression[i]))
      {
        fraction.denominator = fraction.denominator * 10 + (expression[i] - '0');
        i++;
      }

      st.push(fraction);
    }
    if (st.size() >= 2)
    {
      Evaluate(st);
    }
    string ans = st.top().sign == 1 ? "" : "-";
    ans = ans + to_string(st.top().numerator) + "/" + to_string(st.top().denominator);
    return ans;
  }
};

int main()
{
  ios::sync_with_stdio(false);
  return 0;
}