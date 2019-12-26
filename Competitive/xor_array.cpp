#include<iostream>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;


void xorarray(char a1[],char a2[],int n1,int n2){
  int n=min(n1,n2);
  int n3=max(n1,n2);
  int ans[n3];
  for(int i=0;i<n;i++){
    ans[i]=(a1[i]-'0')^(a2[i]-'0');
    cout<<ans[i];
  }
  for(int i=n;i<n3;i++){
    if(n1>n2){
      ans[i]=(a1[i]-'0');
    }
    else{
      ans[i]=(a2[i]-'0');
    }
    cout<<ans[i];
  }
  return;
}
int main() {
  char s1[101];
  char s2[101];
  char a=' ';
  string s;
  int t;
  cin>>t;
  while(t--){
    s.clear();
    while(s.length()==0){getline(cin,s);}
    int j=0;
    int k=0;
    int spaceocc=0;
    for(int l=0;l<s.length();l++){
        
        if(s[l]==a){
            spaceocc++;
            l++;
        }
        if(spaceocc==0){
            s1[l]=s[l];
            j++;
        }
        else if(spaceocc!=0){
            s2[k]=s[l];
            k++;
        }
    }
    xorarray(s1,s2,j,k);
    cout<<endl;
  }
	return 0;
}