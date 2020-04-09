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
    Node *connect_to_head(Node *p)
    {
        p->prev = head;
        p->next = head->next;
        head->next = p;
        p->next->prev = p;
        return p;
    }
    Node *move_to_head(Node *p)
    {
        p->next->prev = p->prev;
        p->prev->next = p->next;
        p = connect_to_head(p);
        return p;
    }
    int get(int key)
    {
        if (!ht.count(key))
            return -1;
        auto p = ht[key];
        p = move_to_head(p);
        ht[key] = p;
        return p->val.second;
    }
    void delete_last_node()
    {
        ht.erase(tail->prev->val.first);
        auto t = tail->prev;
        tail->prev->prev->next = tail;
        tail->prev = tail->prev->prev;
        cur_size--;
        delete t;
    }
    void put(int key, int value)
    {

        if (ht.count(key))
        {
            ht[key]->val.second = value;
            move_to_head(ht[key]);
            return;
        }
        cur_size++;
        if (cur_size > capacity)
        {
            delete_last_node();
        }

        Node *p = new Node({key, value});
        ht[key] = p;
        connect_to_head(p);

        return;
    }
};