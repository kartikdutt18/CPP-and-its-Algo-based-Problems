#include <string>
using namespace std;

string caesarCypherEncryptor(string str, int key)
{
  for (int i = 0; i < str.length(); i++)
  {
    char newChar = (((str[i] - 'a') + key) % 26) + 'a';
    str[i] = newChar;
  }
  return str;
}
