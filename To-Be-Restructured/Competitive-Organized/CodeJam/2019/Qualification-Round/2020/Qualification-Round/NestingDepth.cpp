#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct ListNode
{
  char num;
  int val;
  int brackets;
  ListNode* prev;
  ListNode* next;
  ListNode(char num): num(num), brackets(0), prev(NULL), next(NULL){
    if (num!='(' || num!=')')
      val = num - '0';
    else
      val = INT_MAX;
  }
};

void solve()
{
  string s="";
  while(s.length()==0)
    getline(cin, s);
  ListNode* head = new ListNode(0);
  ListNode* temp = head;
  for(int i = 0; i <s.length(); i++)
  {
    ListNode* nN = new ListNode(s[i]);
    nN->prev = temp;
    temp->next= nN;
    temp = temp->next;
  }
  temp = head->next;
  while(temp)
  {
    while(temp->val!=INT_MAX && temp->brackets<temp->val)
    {
      ListNode* openBracket = new ListNode('(');
      temp->prev->next = openBracket;
      openBracket->prev=temp->prev;
      temp->prev=openBracket;
      openBracket->next = temp;
      temp->brackets++;
      ListNode* nTemp=temp;
      while(nTemp->next && (nTemp->next->val>nTemp->next->brackets))
      {
        if(nTemp->next->val != -1)
          nTemp->next->brackets++;
        nTemp = nTemp->next;
      }
      ListNode* closingNode = new ListNode(')');
      closingNode->prev=nTemp;
      closingNode->next=nTemp->next;
      nTemp->next=closingNode;
      if (closingNode->next)
        closingNode->next->prev=closingNode;
    }
    temp=temp->next;
  }
  string ans = "";
  head=head->next;
  while(head)
  {
    ans+=head->num;
    head=head->next;
  }
  cout<<ans<<endl;
}

int main() 
{
  int t;
  cin>>t;
  for(int i = 1; i <= t; i++)
  {
    cout<<"Case #"<<i<<": ";
    solve();
  }
  return 0;
}