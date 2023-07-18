class Caeser
{	
	public:
		Caeser();
		void Encrypt_Caesar();
		void Decrypt_Caesar();
	private:
	int Alpha(char alpha) {return alpha - 'a';}	
	char Ascii(char alpha) {return alpha + 'a';}	
	bool Select_Encrypt();
	
	std::string original;
	std::string result;
};
