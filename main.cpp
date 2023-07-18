#include <iostream>
#include <vector>
#include <string>
#include "Caeser.h"

using namespace std;

void Start(); //starting fuction
/*Linear();   //planing to make them as seperate class instead of functions
Vigenere();
AutoKey();
Hill();
Verman();
Rsa(); */


int main()
{
	Start();
} //end of "main"

void Start()
{
	// intializing user's choice
	int menu = -1;

	//list of Ciphers
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

	//boolean to determine repeating the switch statement
	bool repeat = false;
	do
	{
		//get number from the user
		cin >> menu;
		
		switch(menu)
		{
			//num 0
			case CAESER:{
				//initializing the Caeser Class object
				Caeser caeser1;	

				//go back to the starting menu again
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

			//num 7 -> program terminates
			case EXIT:
			break;

			//prompting the user to enter the number again
			default:
				cout << "Enter a number again: ";
				repeat = true;
				break;
		}
	} while(repeat == true); //iterates until user inputs a appropriate number

} //end of "Start"
