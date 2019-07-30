//
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Triplet
{
public:
    int first_seen;
    int last_seen;
    int frequency;
    Triplet(int i): first_seen(i),last_seen(i),frequency(1) {}
};
int findShortestSubArray(vector<int> &nums)
{
    map<int, Triplet> ht;
    int max_freq_element=-1;
    int max_Freq=0;
    for(int i=0;i<nums.size();i++){
        if(ht.count(nums[i])){
            ht[nums[i]].last_seen=i;
            ht[nums[i]].frequency++;
        }
        else{
            Triplet t(i);
            ht.insert({nums[i],t});
        }
        if(ht[nums[i]].frequency>max_Freq){
            max_freq_element=nums[i];
            max_Freq = ht[nums[i]].frequency;
        }
    }
    return ht[max_freq_element].last_seen - ht[max_freq_element].first_seen;
}