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
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;
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
  string intToStr(boost::multiprecision::cpp_int text); //int to english
  cpp_int exponentMod(cpp_int A, cpp_int B, cpp_int C);



private:
  void Select_Encrypt();	//prompts the user to choose between Encrypt/Decrypt
  std::string original;   //string of original text from user input  
  cpp_int result;     //string of Encrypted or Decrypted result text
  unsigned long long int p; //prime 1
  unsigned long long int q; //prime 2
  long long int n; //product of p and q, public key
  long long int phi_n;
  long long int e; //reltiely prime to p and q, public key
  cpp_int d; //private key
  tuple <unsigned long long int, unsigned long long int, unsigned long long int> t;
  
};
