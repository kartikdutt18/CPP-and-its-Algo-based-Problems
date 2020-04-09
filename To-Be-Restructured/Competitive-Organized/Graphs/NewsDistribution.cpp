//https://codeforces.com/problemset/problem/1167/C
#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct Node
{
    int data;
    int rank;
    Node* parent;
    Node(int data)
    {
        this->data=data;
        rank=0;
        parent=this;
    }
};
class DisjointSet
{
    public:
    map<int,Node*> adjList;
    int n;
    
    DisjointSet(int n)
    {
        this->n=n;
        for(int i=0;i<n;i++)
        {
            makeSet(i+1);
        }
    }
    DisjointSet()
    {

    }
    void makeSet(int data)
    {
        Node* node = new Node(data);
        adjList[data]=node;
    }
    void unions(int data1,int data2)
    {
        Node* node1 = adjList[data1];
        Node* node2 = adjList[data2];
        Node* parent1 = findSet(node1);
        Node* parent2 = findSet(node2);
        if(parent1->data == parent2->data)
        {
            return;
        }
        if(parent1->rank>=parent2->rank)
        {
            parent1->rank = parent1->rank==parent2->rank?parent1->rank+1:parent1->rank;
            parent2->parent = parent1;
        }
        else
        {
            parent1->parent= parent2;
        }
        return;
    }
    Node* findSet(Node *node)
    {
        if(node->parent==node)
        {
            return node;
        }
        return findSet(node->parent);   
    }
};

class Solution
{
    DisjointSet d;
    int n;
    int k;
    public:
    Solution()
    {
        cin>>n>>k;
        d=DisjointSet(n);
        for(int i=0;i<k;i++)
        {
            int len;
            cin>>len;
            vector<int> v(len);
            for(int j=0;j<len;j++)
            {
                cin>>v[j];
                if(j>0)
                {
                    d.unions(v[j-1],v[j]);
                }
            }
        }
    }
    void Solve()
    {
        map<int,int> indegree;
        for(int i=0;i<n;i++)
        {
            Node* parent=d.findSet(d.adjList[i+1]);
            indegree[parent->data]+=1;
            
        }
        for(int i=0;i<n;i++)
        {
            cout<<indegree[d.adjList[i+1]->parent->data]<<" ";
        }
    }
};
int main()
{
    Solution s;
    s.Solve();
    return 0;
}
