//https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef pair<int, pair<int, int>> ppi;

vector<int> mergeKArrays(vector<vector<int>> arr)
{
    vector<int> output;
    priority_queue<ppi, vector<ppi>, greater<ppi>> pq;

    for (int i = 0; i < arr.size(); i++)
        pq.push({arr[i][0], {i, 0}});

    while (pq.empty() == false)
    {
        ppi curr = pq.top();
        pq.pop();
        // i ==> Array Number
        // j ==> Index in the array number
        int i = curr.second.first;
        int j = curr.second.second;

        output.push_back(curr.first);

        // The next element belongs to same array as
        // current.
        if (j + 1 < arr[i].size())
            pq.push({arr[i][j + 1], {i, j + 1}});
    }

    return output;
}
