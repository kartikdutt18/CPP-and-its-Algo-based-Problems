#include <bits/stdc++.h>
int Solution::coverPoints(vector<int> &x, vector<int> &y) {
    int steps = 0;
    for(int i = 0; i < x.size() - 1; i++)
    {
        int diagSteps = min(abs(x[i+1]-x[i]), abs(y[i+1]-y[i]));
        int newX = x[i], newY = y[i];
        newX = x[i + 1] < x[i] ? newX - diagSteps : newX + diagSteps;
        newY = y[i + 1] < y[i] ? newY - diagSteps : newY + diagSteps;
        int indivSteps = abs(x[i + 1] - newX) + abs(y[i + 1] - newY);
        steps = steps + diagSteps + indivSteps;
    }
    return steps;
}
