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
  vector <int> prime_array;
  int conv_prime;
  int rand_index1;
  int rand_index2;
  
  infile.open("primes.txt");
  if(infile.fail())
    {
      cout<<"ERROR...";
      exit(EXIT_FAILURE);
    }
  while (infile>>prime)
    {  srand(time(0));

	
      conv_prime=stoi(prime); //opening file getting list of ormes 
	
      prime_array.push_back(conv_prime); //assigning primes to vector array
    }
  srand(time(NULL));
  do
    {
      rand_index1 = rand() % 5;
      p = prime_array[rand_index1]; //found first prime

      rand_index2 = rand() % 5 ;
      q = prime_array[rand_index2];

    } while (p == q or p == 0 or q == 0);
  
} // end of Rsa::GetPrimes



void Rsa::GetE()
{
  
  srand(time(0));
  do{
		
    e = rand() % 8;
    t = extended_gcd( e , phi_n); // e and phi_n should be relatively prime
  }while(get<0>(t) != 1 or e == 1);

  d = boost::integer::mod_inverse(e, phi_n);
  
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
  unsigned long long int message;
  unsigned long long int modMessage;

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
   for(int i = 1; i < e; ++i)
  {
    result = static_cast<unsigned long long int>((result * modMessage) % n) ;
    }
  //result = static_cast<unsigned long long int>(pow(modMessage,  e)) % n;
  //display Encrypted message
  cout << "\n\nResult for Encrypting " << original << " with Rsa:\n\n"
  	   
       << "Message: " << result << endl
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

  GetPrimes();
  n = p*q;
  phi_n = (p -1) * (q -1);
  GetE();
  int e;
  int n;
  int d;
  unsigned long long int encrypted_meassage;
  string message;
  
  //prompt user to input the message
  cout <<  "Enter a message you want to decrypt: ";
  cin >> encrypted_meassage;

  cout <<  "Enter the public key e: ";
  cin >> e;

  cout <<  "Enter the public key n: ";
  cin >> n;

  cout <<  "Enter the public key d: ";
  cin >> d;

 
  result = static_cast<unsigned long long int>(pow(encrypted_meassage, d)) % n;
  message = intToStr(result);

  //result = static_cast<unsigned long long int>(pow(modMessage,  e)) % n;
  //display Encrypted message
  cout << "\n\nResult for decrypting " << encrypted_meassage << " with Rsa:\n\n "<< endl << endl
  	  
       << "Message: " << message << endl
       << "public key e: " << e << endl
       << "public key n: " << n << endl
       << "private key d: " << d << endl;

  if(again())
    {
      Decrypt_Rsa();
    }
  
} //end of Rsa::decrypt_Rsa

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
      alphaVal = tolower(str[i]) - 'a' +1;
      result += alphaVal * static_cast<long long int>( pow(10, 2*i));
    }
  return result;
}

string Rsa::intToStr(long long int text)
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





bool Rsa::again()
{
  char response; 
  cout << "\nDo you want to do it again?(y/n): ";
  cin >> response;
  return (tolower(response) == 'y');
}


  

