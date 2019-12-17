//
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int maxConsecZero = 1 - v[0];
    int curConsecZero=1-v[0];
    int initOnes=0;
    for(int i=1;i<n;i++){
        if(v[i]==0){
            curConsecZero++;
            maxConsecZero=max(maxConsecZero,curConsecZero);
        }
        else
        {
            curConsecZero = 0;
            initOnes++;
        }
            
        
    }
    cout<<maxConsecZero+initOnes<<endl;
    return 0;

}