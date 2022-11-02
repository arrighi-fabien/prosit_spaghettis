#include "CaesarCipher.h"
using namespace std;


CaesarCipher::CaesarCipher(int key) {
	this->key = key;
}

string CaesarCipher::encrypt(string text) const {
	string encrypted_text = "";
	for (int i = 0; i < text.length(); i++) {
		if ((text[i] + this->key) > 127) {
			encrypted_text += char((text[i] + this->key) - 128);
		}
		else {
			encrypted_text += char(text[i] + this->key);
		}
	}
	return encrypted_text;
}

string CaesarCipher::decrypt(string text) const {
	string decrypted_text = "";
	for (int i = 0; i < text.length(); i++) {
		if ((text[i] - this->key) < 0) {
			decrypted_text += char((text[i] - this->key) + 128);
		}
		else {
			decrypted_text += char(text[i] - this->key);
		}
	}
	return decrypted_text;
}