//https://leetcode.com/problems/serialize-and-deserialize-n-ary-tree/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val = NULL;
    vector<Node *> children;

    Node() {}

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Codec
{
public:
    // Encodes a tree to a single string.

    string serialize(Node *root)
    {
        if (!root)
            return "";
        if (root->children.size() == 0)
            return to_string(root->val) + " ";
        string res = to_string(root->val) + "[";

        for (auto c : root->children)
        {
            res += serialize(c);
        }
        res += ']';
        return res;
    }

    // Decodes your encoded data to tree.
    Node *deserialize(string data)
    {
        stack<Node *> s;
        int len = data.length();
        int i = 0;
        Node *root = NULL;
        while (i < len)
        {

            Node *cur;
            if (data[i] == '[')
            {
                i++;
            }
            else if (data[i] == ']' || data[i] == ' ')
            {
                if (!s.empty())
                    s.pop();
                i++;
            }
            else
            {
                int num = 0;
                while (i < len && data[i] >= '0' && data[i] <= '9')
                {
                    num = num * 10 + data[i] - '0';
                    i++;
                }
                cur = new Node(num);
                if (!s.empty())
                {
                    (s.top()->children).push_back(cur);
                }
                else
                {
                    root = cur;
                }

                s.push(cur);
            }
        }
        return root;
    }
};