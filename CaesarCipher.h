#include <iostream>

class CaesarCipher {
private:
	int key;
public:
	CaesarCipher(int key);
	std::string encrypt(std::string text) const;
	std::string decrypt(std::string text) const;
};

