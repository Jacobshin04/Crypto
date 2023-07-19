class Linear
{	
	public:
		Linear();
		void Encrypt_Linear(); //Encrypting with Linear Cipher
		void Select_Decrypt_Linear(); //Decrypting with Linear Cipher
		void Decrypt_Linear_withKey();
		void Decrypt_Linear_withoutKey();
		void Decrypt_Linear_findKey();
		int Alpha(char alpha) {return alpha - 'a';}	  //changing Ascii value to 0~26 
		char Ascii(char alpha) {return alpha + 'a';}  //changing 0~26 to Ascii Value
		bool again();           //asks the user for repeating


	private:
		bool Select_Encrypt();	//prompts the user to choose between Encrypt/Decrypt
		std::string original;   //string of original text from user input  
		std::string result;     //string of Encrypted or Decrypted result text
};
