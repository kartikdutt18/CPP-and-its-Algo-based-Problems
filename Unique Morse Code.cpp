//https://leetcode.com/problems/unique-morse-code-words

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int uniqueMorseRepresentations(vector<string>& words) {
        string lk[]={".-","-...","-.-.","-..",".","..-.","--.","....",
                    "..",".---","-.-",".-..","--","-.","---",".--.",
                    "--.-",".-.","...","-","..-","...-",".--","-..-",
                    "-.--","--.."};
        set<string> ht;
        for(auto str: words){
            string s="";
            for(auto i:str){
                s+=lk[i-'a'];
            }
            ht.insert(s);
        }
    return ht.size();}