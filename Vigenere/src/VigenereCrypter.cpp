#include "VigenereCrypter.h"

VigenereCrypter::VigenereCrypter()
{
	size = alphabet.size();
	InitBoard();
}

VigenereCrypter::~VigenereCrypter()
{

}

std::string VigenereCrypter::Encrypt(const std::string& text, const std::string& key)
{
	std::string cryptedString = "";
	int textOffset = 0;
	int keyOffset = 0;
	int keyIterator = 0;
	for (int i = 0; i < text.size(); i++) {
		textOffset = GetTextOffsetForEncrypt(size, i, text);
		keyOffset = GetKeyOffsetForEncrypt(size, keyIterator, key);
		cryptedString += board[keyOffset][textOffset];
	}

	return cryptedString;
}

std::string VigenereCrypter::Decrypt(const std::string& text, const std::string& key)
{
	std::string decryptedString = "";
	int textOffset = 0;
	int keyOffset = 0;
	int keyIterator = 0;
	for (int i = 0; i < text.size(); i++) {
		keyOffset = GetKeyOffsetForDecrypt(size, keyIterator, key);
		textOffset = GetTextOffsetForDecrypt(size, i, text, keyOffset);
		decryptedString += board[0][textOffset];
	}

	return decryptedString;
}

void VigenereCrypter::InitBoard()
{
	std::string temp = alphabet;
	board = new char* [size];
	for (int i = 0; i < size; i++) {
		board[i] = new char[size];
	}

	for (int i = 0; i < size; i++) {
		board[0][i] = alphabet[i];
		for (int j = 0; j < size; j++) {
			board[j][0] = alphabet[j];
		}
	}

	for (int i = 0; i < size; i++) {
		temp = ShiftString(i);
		for (int j = 0; j < size; j++) {
			char f = temp[j];
			board[j][i] = temp[j];
		}
	}
}

std::string VigenereCrypter::ShiftString(int offset)
{
	std::string temp = alphabet;
	for (int i = 0; i < offset; i++) {
		char ch = temp[0];
		for (int j = 0; j < temp.size(); j++) {
			temp[j] = temp[j + 1];
		}
		temp[temp.size() - 1] = ch;
	}
	return temp;
}

const int& VigenereCrypter::GetKeyOffsetForEncrypt(const int& size, int& iterator, const std::string& key)
{
	for (int j = iterator; j < key.size(); j++) {
		for (int k = 0; k < size; k++) {
			if (board[k][0] == key[j]) {
				iterator++;
				if (iterator == key.size()) {
					iterator = 0;
				}
				return k;
			}
		}
	}
}

const int& VigenereCrypter::GetTextOffsetForEncrypt(const int& size, const int& i, const std::string& text)
{
	for (int j = 0; j < size; j++) {
		if (board[0][j] == text[i]) {
			return j;
		}
	}
}

const int& VigenereCrypter::GetKeyOffsetForDecrypt(const int& size, int& iterator, const std::string& key)
{
	for (int j = iterator; j < key.size(); j++) {
		for (int k = 0; k < size; k++) {
			if (board[k][0] == key[j]) {
				char f = board[k][0];
				iterator++;
				if (iterator == key.size()) {
					iterator = 0;
				}
				return k;
			}
		}
	}
}

const int& VigenereCrypter::GetTextOffsetForDecrypt(const int& size, const int& i, const std::string& text, int keyOffset)
{
	for (int j = 0; j < size; j++) {
		if (board[keyOffset][j] == text[i]) {
			char f = board[keyOffset][j];
			return j;
		}
	}
}
