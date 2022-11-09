#include <iostream>
#include "VigenereCrypter.h"

int main()
{
	VigenereCrypter vigenere;

	std::string text = "this_is_a_test";
	std::string key = "secret_key_that_no_one_knows";
	std::string encryptedString = vigenere.Encrypt(text, key);
	std::string decryptedString = vigenere.Decrypt(encryptedString, key);

	std::cout << encryptedString << "\n";
	std::cout << decryptedString << "\n";
	
	int size = vigenere.GetSize();
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			std::cout << vigenere.GetBoard()[j][i] << " ";
		}
		std::cout << "\n";
	}

	return 0;
}