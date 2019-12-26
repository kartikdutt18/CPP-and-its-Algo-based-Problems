#include<iostream>
#include<bits/stdc++.h>
using namespace std;

set<vector<string>> sentences;
void backtrack(map<string,string> ht,int i,vector<string> words){
    if(i>=words.size()) return;
    sentences.insert(words);
    for(int j=i;j<words.size();j++){
        if(ht.count(words[j])){
            string t=words[j];
            words[j]=ht[words[j]];
            backtrack(ht,j+1,words);
            words[j]=t;
        }
    }
    return;
}

vector<string> generateSentences(vector<vector<string>> &synonyms, string text)
{
    map<string,string> ht;
    for(auto i:synonyms){
        ht[i[0]]=i[1];
    }
    vector<string> v;
    istringstream ss(text);
    do{
        string words;
        ss>>words;
        v.push_back(words);
    }while(ss.good);
    vector<string> ans;
    for(auto i:sentences){
        string t="";
        for(auto j:i){
            t+=j;
            t+=" ";
        }
        t.pop_back();
        ans.push_back(t);
    }
    return ans;
}