//https://codeforces.com/contest/1256/problem/B
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void smallest_num(vector<int> &nums,vector<int>min_no,int n,int k){
    for(int i=0;i<n && nums!=min_no && k>0;i++){
        int index=find(nums.begin(),nums.end(),i+1)-nums.begin();
        while(index!=i && k>0 && index>0 && i!=n-1 && index<n){
            
            swap(nums[index],nums[index-1]);
            index=index-1;
            k--;
        }
    }

}
int main(){
    int q;
    cin>>q;
    while(q--){
        int n;
        cin>>n;
        vector<int> nums(n);
        vector<int> min_nos(n);
        for(int i=0;i<n;i++){
            cin>>nums[i];
            min_nos[i]=i+1;
        }
        smallest_num(nums,min_nos,n,n-1);
        for(auto i: nums) cout<<i<<" "; 
        cout<<endl;
    }
}