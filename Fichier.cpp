#include "Fichier.h"
#include <fstream>
using namespace std;

string Fichier::readFile(string file_name) const {
	ifstream file(file_name);
	if (file.is_open()) {
		string content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
		return content;
	}
	else {
		cout << "Impossible d'ouvrir le fichier pour le lire" << endl;
	}
}

void Fichier::writeFile(string file_name, string content) const {
	ofstream file(file_name);
	if (file.is_open()) {
		file << content;
	}
	else {
		cout << "Impossible d'ouvrir le fichier pour le modifier" << endl;
	}
}