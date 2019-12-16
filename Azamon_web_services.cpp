#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void sort_lex(string s,string c){
    int i=0;
    int j=0;
    bool found=false;
    bool swapped=false;
    int k=0;
    while(i<s.length() && j<c.length() && k<s.length()){
        if(s[i]<=c[j] && !found) {
            i++;
            j++;
        } 
        else if(found && s[k]<=c[j] && !swapped){
            swap(s[k],s[i]);
            swapped=true;
        }
        else if(found){
            k++;
        }
        else{
            k=i+1;
            found=true;
        } 
    }
    if(s<c) cout<<s<<endl;
    else cout<<"---"<<endl;
    
    return;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        string s,c;
        cin>>s>>c;
        sort_lex(s,c);
    }
    return 0;
}