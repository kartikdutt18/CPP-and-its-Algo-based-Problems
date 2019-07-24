//https: //practice.geeksforgeeks.org/problems/implement-stack-using-linked-list/1
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct StackNode
{
    int data;
    StackNode *next;
    StackNode(int a)
    {
        data = a;
        next = NULL;
    }
};

class MyStack
{
private:
    StackNode *top;

public:
    void push(int);
    int pop();
    MyStack()
    {
        top = NULL;
    }
};

void MyStack ::push(int x)
{
    if(top==NULL){
        top=new StackNode(x);
    }
    else{
        StackNode* newhead=new StackNode(x);
        newhead->next=top;
        top=newhead;
    }
}

int MyStack ::pop()
{
    if(top==NULL) return -1;
    int temp=top->data;
    top=top->next;
    return temp;
}

