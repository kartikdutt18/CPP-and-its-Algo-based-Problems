//https://leetcode.com/problems/implement-stack-using-queues/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class MyStack
{
    queue<int> q;
    int topValue;
public:
    /** Initialize your data structure here. */
    MyStack()
    {
    }

    /** Push element x onto stack. */
    void push(int x)
    {
        topValue = x;
        q.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        queue<int> tempQ;
        if (q.empty())
            return -1;
        int tempTopValue = -1;
        //pop except the last one
        while (q.size() > 1)
        {
            topValue = q.front();
            tempQ.push(q.front());
            q.pop();
        }
        //store the last one
        if (q.size() == 1)
            tempTopValue = q.front();
        //discard the old queue
        //top value is whatever the last value in the queue is
        q = tempQ;
        return tempTopValue;
    }

    /** Get the top element. */
    int top()
    {
        return topValue;
    }

    /** Get the top element. */
    

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return q.empty();
    }
};