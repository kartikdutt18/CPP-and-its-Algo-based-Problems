//https://hack.codingblocks.com/practice/p/390/88

#include<iostream>
#include<vector>
using namespace std;
#include<iostream>
#include<vector>
using namespace std;
int searchs(vector<int> arr,int n,int k){
    if(n<0) {
        cout<<"-1"<<endl;
        return -1;}
    if(arr[n]==k) {cout<<n<<endl;
    return n;}
    
    searchs(arr,n-1,k);
}
int main(){
    int n,k;
    cin>>n;
    vector<int> v(n+1,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
        
    }
    cin>>k;

    searchs(v,n-1,k);
    
    return 0;
}
