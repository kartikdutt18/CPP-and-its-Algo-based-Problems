using namespace std;

int getNthFib(int n)
{
  int a = 0;
  int b = 1;
  while (--n)
  {
    int t = a;
    a = b;
    b += t;
  }
  return a;
}
