//https://leetcode.com/problems/lemonade-change/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool lemonadeChange(vector<int>& bills) {
    int five=0;
    int ten=0;
    for(auto i:bills){
        if(i==5){
            five++;
        }
        if(i==10){
            if(five==0) return false;
            five--;
            ten++;
        }
        if(i==20){
            if(ten>=1 and five>=1){
                ten--;five--;
            }
            else if(five>=3){
                five-=3;
            }
            else{
                return false;
            }
        }
    }        
return true;}