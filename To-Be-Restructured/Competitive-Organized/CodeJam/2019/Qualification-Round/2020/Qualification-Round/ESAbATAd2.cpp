#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct dataset
{
  int b;
  int same = -1;
  int diff = -1;
  int curPairs = 0;
  vector<int> v;
  void reset()
  {
    same = -1;
    diff = -1;
    curPairs = 0;
    v = vector<int>(b);
  }
  int query(int i)
  {
    int ans;
    cout << i + 1 << endl;
    cin >> ans;
    return ans;
  }
  void getPair()
  {
    v[curPairs] = query(curPairs);
    v[b - curPairs -1] = query(b - curPairs - 1);
  }
  void complement()
  {
    for(int i = 0; i <b; i++)
      v[i] = !v[i];
  }
  void print()
  {
    for(int i = 0; i < b; i++)
      cout<<v[i];
    cout<<endl;
  }
};
dataset d;

void GetPairs()
{
  d.getPair();
  if (d.same == -1 && d.v[d.curPairs] == d.v[d.b - d.curPairs - 1])
    d.same = d.curPairs;
  else if (d.diff == -1 && d.v[d.curPairs] != d.v[d.b - d.curPairs - 1])
    d.diff = d.curPairs;
}
void Modify()
{
  bool complement = 0;
  if (d.same != -1 && d.v[d.same]!=d.query(d.same))
  {
    complement = 1;
  }
  bool rev = complement;
  if (d.diff != -1 && d.v[d.diff]!=d.query(d.diff))
    rev != complement;
  if(complement&1)
  {
    d.complement();
  }
  if(rev&1)
    reverse(d.v.begin(), d.v.end());
}
void solve()
{
  for(;d.curPairs<5;++d.curPairs)
  {
    GetPairs();
  }
  Modify();
  while(d.curPairs<d.b/2)
  {
    int i =0;
    for(; i<4 && d.curPairs<d.b/2; i++, d.curPairs++)
    {
      GetPairs();
    }
    if (i==4)
      Modify();
  }
  d.print();
  char ch;
  cin>>ch;
  if (ch == 'N')
    exit(0);
}

int main()
{
  int t;
  cin >> t >> d.b;
  for (int i = 1; i <= t; i++)
  {
    d.reset();
    solve();
  }
  return 0;
}