
class Caesar
{	
	public:
		Caesar();
		void Encrypt_Caesar(); //Encrypting with Caesar Cipher
		void Decrypt_Caesar(); //Decrypting with Caesar Cipher
		int Alpha(char alpha) {return alpha - 'a';}	  //changing Ascii value to 0~26 
		char Ascii(char alpha) {return alpha + 'a';}  //changing 0~26 to Ascii Value
		bool again();           //asks the user for repeating
	private:
		void Select_Encrypt();  //prompts the user to choose between Encrypt/Decrypt
		std::string original;   //string of original text from user input  
		std::string result;     //string of Encrypted or Decrypted result text
};
