#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include<time.h>
#include <tuple>		// std::tuple, std::make_tuple, std::tie
using namespace std;

tuple<int, int, int> extended_gcd(int a, int b); //ax+by=gcd 

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
		cout<<"ERROR...";
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
cout<<e<<" "<<get<0>(t);

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

