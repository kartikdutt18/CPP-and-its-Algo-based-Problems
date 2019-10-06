//https://leetcode.com/problems/lru-cache/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    pair<int, int> val;
    Node *next;
    Node *prev;
    Node(pair<int, int> x) : val(x), next(NULL), prev(NULL) {}
};
class LRUCache
{
    int capacity;
    Node *head;
    Node *tail;
    map<int, Node *> ht;
    int cur_size;

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
        head = new Node({-1, -1});
        tail = new Node({-1, -1});
        head->next = tail;
        tail->prev = head;
        cur_size = 0;
    }

    int get(int key)
    {
        if (!ht.count(key))
            return -1;
        auto p = ht[key];
        p->next->prev = p->prev;
        p->prev->next = p->next;
        p->prev = head;
        p->next = head->next;
        head->next = p;
        p->next->prev = p;
        ht[key] = p;
        return p->val.second;
    }

    void put(int key, int value)
    {

        if (ht.count(key))
        {
            ht[key]->val.second = value;
            auto p = ht[key];
            p->next->prev = p->prev;
            p->prev->next = p->next;
            p->prev = head;
            p->next = head->next;
            head->next = p;
            p->next->prev = p;
            ht[key] = p;
            return;
        }
        cur_size++;
        if (cur_size > capacity)
        {
            ht.erase(tail->prev->val.first);
            auto t = tail->prev;
            tail->prev->prev->next = tail;
            tail->prev = tail->prev->prev;
            cur_size--;
            delete t;
        }

        Node *p = new Node({key, value});
        ht[key] = p;
        p->next = head->next;
        p->prev = head;
        head->next->prev = p;
        head->next = p;

        return;
    }
};