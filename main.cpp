#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
#include "Caesar.h"
#include "Linear.h"

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
	enum Cipher {CAESAR, LINEAR, VIGENERE, AUTOKEY, HILL, VERMAN, RSA, EXIT};

	//prompting the user to pick the Cipher
	system("clear");

	cout << "Choose the menu" <<  endl;
	cout << "0. Caeser Cipher" << endl;
	cout << "1. Linear Cipher" << endl;
	cout << "2. Vigenere Cipher" << endl;
	cout << "3. AutoKey Cipher" << endl;
	cout << "4. Hill Cipher" << endl;
	cout << "5. Verman Cipher" << endl;
	cout << "6. RSA Crypto System" << endl;
	cout << "7. exit" << endl;


	//boolean to determine repeating the switch statement
	bool repeat = false;
	do
	{
		//get number from the user
		cout << "Enter a Number: ";
		cin >> menu;

		switch(menu)
		{
			//num 0
			case CAESAR:{
				//initializing the Caesar Class object
				Caesar caesar1;	
			}
			break;

			//num 1
			case LINEAR:{
				//initializing the Linear Class object
				Linear linear1;	
			}
			break;
/*
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
			exit(EXIT_SUCCESS);
			break;

			//prompting the user to enter the number again
			default:
				cout << "Enter a number again: ";
				repeat = true;
				break;
		}
	} while(repeat == true); //iterates until user inputs a appropriate number

	//go back to the starting menu again	
	Start();
	
} //end of "Start"
