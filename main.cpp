#include <iostream>
#include <vector>
#include <string>
#include "Caeser.h"

using namespace std;

void Start();
/*Linear();
Vigenere();
AutoKey();
Hill();
Verman();
Rsa(); */
bool Select_Encypt();


int main()
{
	Start();
}

void Start()
{
	int menu = -1;
	enum Cipher {CAESER, LINEAR, VIGENERE, AUTOKEY, HILL, VERMAN, RSA, EXIT};

	//prompting the user to pick the Cipher
	cout << "Choose the menu" <<  endl;
	cout << "0. Caeser Cipher" << endl;
	cout << "1. Linear Cipher" << endl;
	cout << "2. Vigenere Cipher" << endl;
	cout << "3. AutoKey Cipher" << endl;
	cout << "4. Hill Cipher" << endl;
	cout << "5. Verman Cipher" << endl;
	cout << "6. RSA Crypto System" << endl;
	cout << "7. exit" << endl;
	cout << "(Enter a number): ";
	bool repeat = false;
	do
	{
		cin >> menu;
		
		switch(menu)
		{
			case CAESER:{
				Caeser caeser1;	
				Start();
			}
				break;

		/*	case LINEAR:
			Linear();
			break;

			case VIGENERE:
			Vigenere();
			break;
			
			case AUTOKEY:
			AutoKey();
			break;
			
			case HILL:
			Hill();
			break;
			
			case VERMAN:
			Verman();
			break;

			case RSA:
			Rsa();
			break;	
			*/

			case EXIT:
			break;
			
			default:
				cout << "Enter a number again: ";
				repeat = true;
				break;
		}
	} while(repeat == true);

}
