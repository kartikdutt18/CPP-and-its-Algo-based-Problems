#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int totalXor = 0;
	for (int j = 0; j < n - 1; j++)
	{
		int temp;
		cin >> temp;
		totalXor = totalXor ^ (j + 1) ^ (temp);
	}
	cout << (totalXor ^ n) << endl;
	return 0;
}