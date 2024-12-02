#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include<time.h>
#include <tuple>		// std::tuple, std::make_tuple, std::tie
using namespace std;

tuple<int, int, int> extended_gcd(int a, int b); //ax+by=gcd 
const int MAX_LEN = 9;

long long int strToInt(string str);
string intToStr(long long int text);

int main()
{
	ifstream infile;
	vector <int> prime_array;
	string prime;
	int conv_prime;
	int rand_index1;
	int rand_index2;
	int p; //prime 1
	int q; //prime 2
	int n; //product of p and q
	int phi_n;
	int e; //reltiely prime to p and q
	tuple <int, int, int> t;
	//all vars
	infile.open("primes.txt");
	if(infile.fail())
	{
		cout<<"ERRbool Linear::again()
{
  char response; 
  cout << "\nDo you want to do it again?(y/n): ";
  cin >> response;
  return (tolower(response) == 'y');
}
OR...";
		exit(EXIT_FAILURE);
	}
	while (infile>>prime)
	{
	
	conv_prime=stoi(prime); //opening file getting list of ormes 
	
	prime_array.push_back(conv_prime);	//assigning primes to vector array
	}
	srand(time(NULL));
	do
	{
    rand_index1 = rand() % 190;
    p = prime_array[rand_index1]; //found first prime

    rand_index2 = rand() % 195 ;
    q = prime_array[rand_index2];

    } while (p == q);  
   n = p*q;
   phi_n = (p-1) * (q-1); 

srand(time(0));
	do{
		
		e = rand() % (25-10)+10;
		t = extended_gcd( e , phi_n);
	}while(get<0>(t) != 1);	   
	cout<<e<<" "<<get<0>(t) << n << endl;

	return 0;
	
}







// Recursive function to demonstrate the extended Euclidean algorithm.
// It returns multiple values using tuple in C++.
tuple<int, int, int> extended_gcd(int a, int b)
{
	if (a == 0) {
		return make_tuple(b, 0, 1);
	}

	int gcd, x, y;

	// unpack tuple returned by function into variables
	tie(gcd, x, y) = extended_gcd(b % a, a);

	return make_tuple(gcd, (y - (b/a) * x), x);
} //returniing gcd, x, y

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
