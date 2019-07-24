//https://practice.geeksforgeeks.org/problems/sort-in-specific-order/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;


bool compare(int a, int b)
{
    if (a % 2 && b % 2)
        return a > b;
    if (a % 2 || b % 2)
        return a & 1;
    return a < b;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        sort(v.begin(), v.end(), compare);
        for (auto i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}