#include <iostream>
#include <bitset>

class Xor {
private:
	std::string key;
public:
	Xor(std::string key);
	std::string textToBinaryString(std::string text) const;
	std::string binaryStringToText(std::string binary_string) const;
	std::string encryptDecrypt(std::string text) const;
};

