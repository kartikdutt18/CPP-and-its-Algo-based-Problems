// Q 17.1
// DP
// EPI

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        cout<<countCombinations(n)<<endl;
    }
    return 0;
}