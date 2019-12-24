//
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int balance(vector<int> v){
    int midLeft=v.size()/2-1;
    int midRight=v.size()/2;
    int berry=0;
    int jam=0;
    int berrymidLeft=0;
    int berrymidRight=0;
    int jammidLeft=0;
    int jammidRight=0;
    for(int i=0;i<v.size();i++){
        if(i<v.size()/2){
            if (v[i] == 1)
                berrymidLeft++;
            else
                jammidLeft++;
        }
        else{
            if (v[i] == 1)
                berrymidRight++;
            else
                jammidRight++;
        }
    }
    berry=berrymidLeft+berrymidRight;
    jam=jammidLeft+jammidRight;
    while(berry!=jam){
        if(berry>jam){
            if(berrymidLeft>berrymidRight && midLeft>0){
                if(v[midLeft]==1){
                    berrymidLeft--;
                    midLeft--;
                }
                else{
                    jammidLeft--;
                    midLeft--;
                }
            }
            else{
                if(v[midRight]==1){
                    berrymidRight--;
                    midRight++;
                }
                else{
                    jammidRight--;
                    midRight++;
                }
            }
        }
        else{
            if(jammidLeft>jammidRight && midLeft>0){
                if (v[midLeft] == 1)
                {
                    berrymidLeft--;
                    midLeft--;
                }
                else
                {
                    jammidLeft--;
                    midLeft--;
                }
            }
            else{
                if (v[midRight] == 1)
                {
                    berrymidRight--;
                    midRight++;
                }
                else
                {
                    jammidRight--;
                    midRight++;
                }
            }
        }
        berry = berrymidLeft + berrymidRight;
        jam = jammidLeft + jammidRight;
    }
    return v.size()-berry-jam;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n,0);
        for(int i=0;i<n;i++)cin>>v[i];
        cout<<balance(v)<<endl;
    }
    return 0;
}