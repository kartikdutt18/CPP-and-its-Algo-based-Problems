//https://leetcode.com/problems/palindrome-number/submissions/
#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool isPalindrome(int x)
{
    string t = to_string(x);
    reverse(t.begin(), t.end());
    return to_string(x) == t;
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<isPalindrome(x)<<endl;
    }
    return 0;
}