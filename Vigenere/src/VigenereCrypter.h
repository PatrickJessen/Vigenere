#pragma once
#include <string>

class VigenereCrypter
{
public:
	VigenereCrypter();
	~VigenereCrypter();

public:
	std::string Encrypt(const std::string& text, const std::string& key);
	std::string Decrypt(const std::string& text, const std::string& key);

	char** GetBoard() { return board; }
	const int& GetSize() { return size; }

private:
	void InitBoard();
	std::string ShiftString(int offset);
	const int& GetKeyOffsetForEncrypt(const int& size, int& iterator, const std::string& key);
	const int& GetTextOffsetForEncrypt(const int& size, const int& i, const std::string& text);
	const int& GetKeyOffsetForDecrypt(const int& size, int& iterator, const std::string& key);
	const int& GetTextOffsetForDecrypt(const int& size, const int& i, const std::string& text, int keyOffset);
private:
	char** board = nullptr;
	int size = 0;
	std::string alphabet = "abcdefghijklmnopqrstuvwxyz_";
};