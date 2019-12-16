#include <iostream>
#include<bits/stdc++.h>
using namespace std;
inline bool ends_with(string const & value, string const & ending)
{
    if (ending.size() > value.size()) return false;
    return equal(ending.rbegin(), ending.rend(), value.rbegin());
}
int main() {
    int t;
    cin>>t;
    while(t--){
        string s;
        while(s.length()==0)
            getline(cin,s);
        if(ends_with(s,"po"))
            cout<<"FILIPINO"<<endl;
        else if(ends_with(s,"desu") || ends_with(s,"masu"))
            cout<<"JAPANESE"<<endl;
        else if(ends_with(s,"mnida"))
            cout<<"KOREAN"<<endl;
    }
    return 0;
}
