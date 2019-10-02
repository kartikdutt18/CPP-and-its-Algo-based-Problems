//CTCI Q1.1
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool unique_chars(string s){
    set<char> ht;
    for(auto i:s){
        if(ht.count(i)) return false;
        ht.insert(i);
    }
    return true;
}