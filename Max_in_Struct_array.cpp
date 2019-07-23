//https://practice.geeksforgeeks.org/problems/maximum-in-struct-array/1
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Height {
	int feet;
	int inches;
};
int findMax(Height arr[], int n)
{
    int ans=0;
  
    for(int j=0;j<n;j++){
        Height i=arr[j];
        ans=max(ans,i.feet*12+i.inches);
    }
    return ans;
}