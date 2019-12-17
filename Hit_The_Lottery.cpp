//https://codeforces.com/problemset/problem/996/A
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void div_by(long long &coins, long long &n, int num)
{
    coins += n / num;
    n %= num;
    return;
}
int main()
{
    long long n;
    cin >> n;
    long long coins = 0;
    div_by(coins, n, 100);
    div_by(coins, n, 20);
    div_by(coins, n, 10);
    div_by(coins, n, 5);
    div_by(coins, n, 1);
    cout << coins << endl;
    return 0;
}