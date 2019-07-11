//https://leetcode.com/problems/implement-queue-using-stacks/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class MyQueue
{
    stack<int> s1, s2;
    int tp;

public:
    /** Initialize your data structure here. */
    MyQueue()
    {
        
    }

    /** Push element x to the back of queue. */
    void push(int x)
    {   if(s1.empty()){
        tp=x;
    }
        s1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int ans=s2.top();
        s2.pop();
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return ans;
    }

    /** Get the front element. */
    int peek()
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        int ans = s2.top();

        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return ans;
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return s1.empty();
    }
};