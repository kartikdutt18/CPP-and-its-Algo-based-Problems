//https://leetcode.com/contest/biweekly-contest-19/problems/angle-between-hands-of-a-clock/
#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
class Solution
{
public:
  double angleClock(int h, int m)
  {
    double hAngle = 0.5 * (h * 60 + m);
    double mAngle = 6 * m;
    double angle = abs(hAngle - mAngle);
    angle = angle < (360 - angle) ? angle : (360 - angle);
    return angle;
  }
};
int main() {

return 0;
}