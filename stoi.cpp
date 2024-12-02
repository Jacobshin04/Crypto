#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <cmath>

using namespace std;
const int MAX_LEN = 9;

long long int strToInt(string str);
string intToStr(long long int text);

int main(void)
{
  long long int test =  9 * pow(10, 2 * 8);

  cout << test << endl;
  string userText(MAX_LEN, ' ');
  getline(cin, userText);
  userText = userText.substr(0,9);
  
  cout << strToInt(userText) << endl;
  cout << intToStr(strToInt(userText)) << endl;
}

long long int strToInt(string str)
{
  long long int result = 0;
  int alphaVal;
  for(int i = 0; i < str.length(); i++)
    {
      alphaVal = tolower(str[i]) - 'a' +1;
      result += alphaVal * static_cast<long long int>( pow(10, 2*i));
    }
  return result;
}

string intToStr(long long int text)
{
  string result;
  int numChar = 0;
  long long int temp = text;
  int alphaVal;
  
  while(temp)
    {
      temp /= 100;
      numChar++;
    }

  for(int i = 0; i < numChar; i++)
    {
      alphaVal = text % 100; 
      result.push_back('a' + alphaVal -1);
      text /= 100;
    }

  return result;
}
