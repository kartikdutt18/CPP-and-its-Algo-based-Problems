#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

double samePos = 0.0;
double possibilities = 0.0;
void solve(int i, const string& actual,
    const string& recieved, int curPos = 0,
    int actualPos = 0)
{
  if (i >= actual.length() && curPos == actualPos)
  {
    samePos++;
    possibilities++;
    return;
  }
  if (i >= actual.length())
  {
    possibilities++;
    return;
  }

  actualPos += actual[i] == '+' ? 1 : -1;
  if (recieved[i] == '?')
  {
    solve(i+1, actual, recieved, curPos + 1, actualPos);
    solve(i + 1, actual, recieved, curPos - 1, actualPos);
  }
  else
  {
    curPos += recieved[i] == '+' ? 1 : -1;
    solve(i + 1, actual, recieved, curPos, actualPos);
  }
  return;
}
void fill(string& s)
{
  s.clear();
  while(s.length() == 0)
    getline(cin, s);
}
int main()
{
  string actual, recieved;
  fill(actual); fill(recieved);
  solve(0, actual, recieved);
  double ans = ((double)1.0 * samePos) / ((double)1.0 * possibilities);
  cout << setprecision(11) << ans << endl;
  return 0;
}