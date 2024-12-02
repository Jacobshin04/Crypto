#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include<time.h>
#include <tuple> // std::tuple, std::make_tuple, std::tie
#include <cctype>
#include <cmath>
#include <boost/integer/mod_inverse.hpp>

using namespace std;

const int MAX_LEN = 9;


class Rsa
{	
public:
  Rsa();
  void GetPrimes();
  void GetE();
  void Encrypt_Rsa(); //Encrypting with Rsa
  void Decrypt_Rsa(); //Decrypting with Rsa
  int Alpha(char alpha) {return alpha - 'a';}	  //changing Ascii value to 0~26 
  char Ascii(char alpha) {return alpha + 'a';}  //changing 0~26 to Ascii Value
  bool again();           //asks the user for repeating
  tuple<int, int, int> extended_gcd(int a, int b); //ax+by=gcd
  long long int strToInt(string str); //english to int
  string intToStr(long long int text); //int to english
  



private:
  void Select_Encrypt();	//prompts the user to choose between Encrypt/Decrypt
  std::string original;   //string of original text from user input  
  unsigned long long int result;     //string of Encrypted or Decrypted result text
  int p; //prime 1
  int q; //prime 2
  int n; //product of p and q, public key
  int phi_n;
  int e; //reltiely prime to p and q, public key
  int d; //private key
  tuple <int, int, int> t;
  
};
