//CTCI 3.6

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Animal{
    string type;
};
class Stack{
    stack<pair<Animal,int>> cats;
    stack<pair<Animal, int>> dogs;
    int last_age;
    public:
    Stack(){last_age=0;}
    void push(Animal a){
        a.type=="Cats"?cats.push({a,last_age++}):dogs.push({a,last_age++});
    }
    void pop(){
        if(cats.empty())    dogs.pop();
        if (dogs.empty())   cats.pop();
        if(cats.empty() && dogs.empty()) return;
        cats.top().second>dogs.top().second?cats.pop():dogs.pop();
        return;
    }
    void pop_dogs(){
        if (!dogs.empty()) dogs.pop();
    }
    void pop_cats(){
        if (!cats.empty())  cats.pop();
    }
};