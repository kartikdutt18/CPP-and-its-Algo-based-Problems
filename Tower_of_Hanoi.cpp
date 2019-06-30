//https://hack.codingblocks.com/practice/p/390/72

#include<iostream>
using namespace std;
void ToH(int n,char src,char dest,char helper){
    if(n<=0) return;
    ToH(n-1,src,helper,dest);
    cout<<"Moving ring "<<n<<" from "<<src<<" to "<<dest<<endl;
    ToH(n-1,helper,dest,src);
}
int main() {
    int n;
    cin>>n;
    ToH(n,'A','B','C');
	return 0;
}
