#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int bitPos, samesies, difffs;
vector<int>a(100);
int query(int i)
{
  int ans;
  cout<<i+1<<endl;
  cin>>ans;
  return ans;
}
void findpair(int i)
{
  a[i]=query(i);
  a[bitPos-i-1]=query(bitPos-i-1);
  if(samesies==-1 && a[i]==a[bitPos-i-1])
    samesies==i;
  if(difffs==-1 && a[i]==a[bitPos-i-1])
    difffs=i;
    return;
}

void findChange()
{
  bool comp = 0;
  if(samesies!=-1 && a[samesies]!=query(samesies))
    comp = 1;
  bool rev = comp;
  if (difffs!=-1 && a[difffs]!=query(difffs))
  {
    rev!=comp;
  }
  if(comp)
  {
    for(int i = 0; i<bitPos; i++)
    {
      a[i]=!a[i];
    }
  }
  if(rev)
    reverse(a.begin(),a.end());
  return;
}

void solve()
{
  samesies = -1;
  difffs = -1;
  int c = 0;
  for(;c<5;++c)
  {
    findpair(c);
  }
  findChange();
  while(c<bitPos/2){
    int i=0;
    for(; i<4 && c<bitPos/2; ++i, ++c)
    {
      findpair(c);
    }
    if(i==4)
      findChange();
  }
  for(int i =0; i<bitPos;i++)
  
  {
    cout<<a[i];
  }
  cout<<endl;
  char ans;

  cin>>ans;
  if(ans=='N')
    exit(0);

}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int testNum;
  cin >> testNum >> bitPos;
  for (int i = 1; i <= testNum; i++)
  {
    solve();
  }
return 0;
}