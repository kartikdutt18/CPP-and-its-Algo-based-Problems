#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int query(int i)
{
  int val;
  cout << i + 1<<endl;
  cin>>val;
  return val;
}
void FindPair(vector<int> &v, pair<int, int> &determiningPair, int curIndex)
{
  v[curIndex] = query(curIndex);
  v[v.size() - curIndex - 1] = query(v.size() - curIndex - 1);
  if (determiningPair.first == -1 && v[curIndex] == v[v.size() - curIndex - 1])
    determiningPair.first = curIndex;
  if (determiningPair.second == -1 && v[curIndex] != v[v.size() - curIndex - 1])
    determiningPair.second = curIndex;
}

void Modify(vector<int> &v, pair<int, int> determiningPair)
{
  bool complement(false), reverseArr(false);
  if (determiningPair.first != -1 && query(determiningPair.first)!=v[determiningPair.first])
  {
    complement = true;
  }
  reverseArr = complement;
  if (determiningPair.second != -1 && query(determiningPair.second)!= v[determiningPair.second])
  {
    reverseArr = !complement;
  }
  if (complement)
  {
    for(int j = 0; j<v.size();j++)
      v[j]=!v[j];
  }
  if (reverseArr)
    reverse(v.begin(), v.end());
}

bool solve(int b)
{
  vector<int> v(b);
  pair<int, int> determiningPair(-1, -1);
  int pairCount = 0;
  for(;pairCount<5;++pairCount)
  {
    FindPair(v, determiningPair, pairCount);
  }
  Modify(v, determiningPair);
  while (pairCount < b / 2)
  {
    int i = 0;
    for (; i < 4 && pairCount < b / 2; ++i, ++pairCount)
    {
      FindPair(v, determiningPair, pairCount);
    }
    if (pairCount != b/2)
    {
      Modify(v, determiningPair);
    }
  }

  for (auto i : v)
    cout << i;
  cout << endl;
  char ch;
  cin >> ch;
  if(ch=='N')
    exit(1);
  return true;
}
int main()
{

  int t, b;
  cin >> t >> b;
  for (int i = 1; i <= t; i++)
  {
    bool solved = solve(b);
    
  }
  return 0;
}