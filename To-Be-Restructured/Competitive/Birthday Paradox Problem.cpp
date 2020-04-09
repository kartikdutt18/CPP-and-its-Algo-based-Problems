#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    long double p=1;
    int cnt=1;
    while(p>00.1){
        p*=(365.0-cnt)/365;
        cnt++;
        cout<<"The Probability equal to "<<(1-p)<<" for n people to have same birthday should have atleast "<<cnt<<" no. of people"<<endl;
        
        
    }
    return 0;
}

