#include "Xor.h"
using namespace std;

Xor::Xor(string key) {
	this->key = key;
}

string Xor::textToBinaryString(string text) const {
	string binary_string = "";
	for (int i = 0; i < text.length(); i++) {
		binary_string += bitset<7>(text[i]).to_string();
	}
	return binary_string;
}

string Xor::binaryStringToText(string binary_string) const {
	string text = "";
	for (int i = 0; i < binary_string.length(); i += 7) {
		text += char(bitset<7>(binary_string.substr(i, 7)).to_ulong());
	}
	return text;
}

string Xor::encryptDecrypt(string text) const {
	string new_text = "";
	text = textToBinaryString(text);
	int j = 0;
	for (int i = 0; i < text.length(); i++) {
		if (text[i] == this->key[j]) {
			new_text += "0";
		}
		else if (text[i] != this->key[j]) {
			new_text += "1";
		}
		j++;
		if (j == this->key.length()) {
			j = 0;
		}
	}
	return binaryStringToText(new_text);
}