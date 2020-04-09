//https://codeforces.com/contest/1148/problem/A
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    long long a , b, c, ans;
    cin >> a >> b >> c;
    ans = 2 * c + min(a, b) + min(max(a,b),min(a,b)+1);
    cout << ans << endl;
    return 0;
}