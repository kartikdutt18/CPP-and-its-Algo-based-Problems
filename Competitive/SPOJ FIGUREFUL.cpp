#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){
    typedef pair<int,int> cd;
    typedef string Name;
    
    map <cd,Name> table;
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cd code;
        Name name;
        cin>>code.first>>code.second>>name;
        table[code]=name;
        
        
    }
    cin>>n;
    for(int i=0;i<n;++i){
        cd code_1;
        cin>>code_1.first>>code_1.second;
        cout<<table[code_1]<<endl;
    }
    return 0;
}
