#include "Rsa.hpp"
#include "Cipher.hpp"
#include <cmath>


Rsa::Rsa()
{

  Select_Encrypt();
} //end of Rsa::Rsa


void Rsa::GetPrimes()
{
  ifstream infile;
  string prime;
  vector <long long int> prime_array;
  cpp_int conv_prime;
  // int rand_index1;
  // int rand_index2;
  cpp_int long_prime;
  
  // infile.open("primes.txt");
  // if(infile.fail())
    // {
      // cout<<"ERROR...";
      // exit(EXIT_FAILURE);
    // }
  // while (infile.get(long_prime))
    // {  srand(time(0));
// 
      // conv_prime=long_prime; //opening file getting list of ormes
      // prime_array.push_back(static_cast<unsigned long long int>(conv_prime)); //assigning primes to vector array
    // }
  // srand(time(NULL));
  p = 1000000321;
  q = 1000000289;
  
  // do
    // {
      // rand_index1 = rand() % 5;
      // p = prime_array[rand_index1]; //found first prime
// 
      // rand_index2 = rand() % 5 ;
      // q = prime_array[rand_index2];
// 
    // } while (p == q or p == 0 or q == 0);
	// cout << p << endl << q << endl;
	// for(int i = 0; i <static_cast<int>( prime_array.size()); i++)
	// {
			// cout << prime_array[i] << endl;
// 
	// }
} // end of Rsa::GetPrimes



void Rsa::GetE()
{
  srand(time(0));
  do{
	  do{
			
	    e = rand() % 20;
	    t = extended_gcd( e , phi_n); // e and phi_n should be relatively prime
	  }while(get<0>(t) != 1 or e == 1);
	  cpp_int long_e = e;
	  cpp_int long_phi_n = phi_n;
	  
	  d = boost::integer::mod_inverse(long_e, long_phi_n);
  }while(d == 0);
  // d = 17820319500;
  // while (1) {
      // if ((d * e) % phi_n == 1)
          // break;
      // d++;
  // }

  
} //Rsa::GetE()



void Rsa::Select_Encrypt()
{	
	//User choosing Encrypt or Decrypt or menu
	int userNum;
	system("clear");
	cout << "0. Encrypt with rsa" << endl << endl
		 << "1. Decrypt with rsa" << endl << endl
		 << "2. Go back to menu" << endl;
		 
	do{
		cout << "Enter a number: ";
		cin >> userNum;
	} while ((userNum != 0) and (userNum != 1) and (userNum != 2)); //choosing between 0, 1, 2

	//Encrypting with rsa
	if(userNum == 0)
	{
		Encrypt_Rsa();
	}

	//Decrypting with Rsa
	else if(userNum == 1)
	{
		Decrypt_Rsa();
	}

	//Go back to menu
	else
	{
		Cipher c1;
		c1.Start();
	}
	
	
} //end of "Select_Encrypt"

void Rsa::Encrypt_Rsa()
{
  cpp_int message;
  cpp_int modMessage;

  GetPrimes();   

  n = p*q;
  phi_n = (p -1) * (q -1);
  GetE();
  
  //prompt user to input the message
  cout <<  "Enter a message you want to Encrypt(max 9letters): ";
  cin.ignore();
  getline(cin, original);
  

  message = strToInt(original);
  cout << "original int: " << message << endl;
  modMessage = message % n;
  result = modMessage;
  cpp_int result2 = exponentMod(modMessage, e, n);
    
   // for(int i = 1; i < e; ++i)
  // {
    // result = ((result * modMessage) % n) ;
	    // if(result < 0){
	    	// cout << result << " result overflow" << endl;
	    // }
    // }
   
  //result = static_cast<unsigned long long int>(pow(modMessage,  e)) % n;
  //display Encrypted message
  cout << "\n\nResult for Encrypting " << original << " with Rsa:\n\n"
  	   
       // << "Message: " << result << endl
       << "Message: " << result2 << endl
       << "public key e: " << e << endl
       << "public key n: " << n << endl
       << "private key d: " << d << endl;

  if(again())
    {
      Encrypt_Rsa();
    }
  
} 
//end of Rsa::Encrypt_Rsa

void Rsa::Decrypt_Rsa()
{

  string encrypted_message;
  string message;
  
  //prompt user to input the message
  cout <<  "Enter a message you want to decrypt: ";
  cin >> encrypted_message;

  cout <<  "Enter the public key e: ";
  cin >> e;

  cout <<  "Enter the public key n: ";
  cin >> n;

  cout <<  "Enter the private key d: ";
  cin >> d;

 
  
	cpp_int result(encrypted_message);
	cpp_int int_encrypted_message(encrypted_message);
  	result = exponentMod(int_encrypted_message, d, n);
  // for(long long int i = 1; i < d; ++i)
  // {
    // result = (result * int_encrypted_message) % n;
    // if(i % 10000000 == 0)
    // {
    	// cout << result << " i:" << i << " d:" <<d << endl;
    // }
  // }
  message = intToStr(result);

  //result = static_cast<unsigned long long int>(pow(modMessage,  e)) % n;
  //display Encrypted message
  cout << "\n\nResult for decrypting " << encrypted_message << " with Rsa:\n\n "<< endl << endl
  
  		<< "decrypted int: " << result << endl
       << "Message: " << message << endl
       << "public key e: " << e << endl
       << "public key n: " << n << endl
       << "private key d: " << d << endl;

  if(again())
    {
      Decrypt_Rsa();
    }
  
} //end of Rsa::decrypt_Rsa


cpp_int Rsa::exponentMod(cpp_int A, cpp_int B, cpp_int C) 
{ 
    // Base cases 
    if (A == 0) 
        return 0; 
    if (B == 0) 
        return 1; 
 
    // If B is even 
    cpp_int y; 
    if (B % 2 == 0) { 
        y = exponentMod(A, B / 2, C); 
        y = (y * y) % C; 
    } 
 
    // If B is odd 
    else { 
        y = A % C; 
        y = (y * exponentMod(A, B - 1, C) % C) % C; 
    } 
    return (cpp_int)((y + C) % C); 
} 
// Recursive function to demonstrate the extended Euclidean algorithm.
// It returns multiple values using tuple in C++.
tuple<int, int, int> Rsa::extended_gcd(int a, int b)
{
	if (a == 0) {
		return make_tuple(b, 0, 1);
	}

	int gcd, x, y;

	// unpack tuple returned by function into variables
	tie(gcd, x, y) = extended_gcd(b % a, a);

	return make_tuple(gcd, (y - (b/a) * x), x);
} //returniing gcd, x, y


long long int Rsa::strToInt(string str)
{
  long long int result = 0;
  int alphaVal;
  for(long unsigned int i = 0; i < str.length(); i++)
    {
    	if (str[i] == ' ')
    	{
    		alphaVal = 30;
    	}
    	else
    	{
    		alphaVal = tolower(str[i]) - 'a' +1;
    	}
      result += alphaVal * static_cast<long long int>( pow(10, 2*i));
    }
  return result;
}

string Rsa::intToStr(boost::multiprecision::cpp_int text)
{
  string result;
  int numChar = 0;
  boost::multiprecision::cpp_int temp = text;
  int alphaVal;
  
  while(temp)
    {
      temp /= 100;
      numChar++;
    }

  for(int i = 0; i < numChar; i++)
    {
 
	 alphaVal = static_cast<unsigned long long int>(text) % 100; 
       if (alphaVal == 30)
    	{
    		result.push_back(' ');
    	}
    	else
    	{
    		result.push_back('a' + alphaVal -1);
    	}
      text /= 100;
    }

  return result;
}





bool Rsa::again()
{
  char response; 
  cout << "\nDo you want to do it again?(y/n): ";
  cin >> response;
  return (tolower(response) == 'y');
}


  

