#include "Fichier.h"
#include "CaesarCipher.h"
#include "Xor.h"
using namespace std;


int main() {
	cout << "Bonjour, quelle action souhaitez-vos réaliser ?"<< endl << "1. Chiffrer un fichier" << endl << "2. Déchiffrer un fichier" << endl;
	int choice;
	cin >> choice;
	if (choice == 1 || choice == 2) {
		cout << "Quel type de chiffrement souhaitez-vous utiliser ?" << endl << "1. César" << endl << "2. XOR" << endl << "3. Les deux" << endl;
		int choice2;
		cin >> choice2;
		if (choice2 == 1 || choice2 == 2 || choice2 == 3) {
			cout << "Quel est le chemin du fichier à chiffrer / déchiffrer ?" << endl;
			string path;
			cin >> path;
			cout << "Quel est le chemin du fichier de sortie ?" << endl;
			string path2;
			cin >> path2;
			Fichier file;
			string content = file.readFile(path);
			if (choice2 == 1) {
				cout << "Quel est le décalage voulu ?" << endl;
				int offset;
				cin >> offset;
				CaesarCipher caesar(offset);
				if (choice == 1) {
					content = caesar.encrypt(content);
				}
				else if (choice == 2) {
					content = caesar.decrypt(content);
				}
			}
			else if (choice2 == 2) {
				cout << "Quelle est la clé de chiffrement ?" << endl;
				string key;
				cin >> key;
				Xor xorCypher(key);
				content = xorCypher.encryptDecrypt(content);
			}
			else if (choice2 == 3) {
				cout << "Quel est le décalage voulu ?" << endl;
				int offset;
				cin >> offset;
				cout << "Quelle est la clé de chiffrement ?" << endl;
				string key;
				cin >> key;
				Xor xorCypher(key);
				CaesarCipher caesar(offset);
				if (choice == 1) {
					content = caesar.encrypt(content);
					content = xorCypher.encryptDecrypt(content);
				}
				else if (choice == 2) {
					content = xorCypher.encryptDecrypt(content);
					content = caesar.decrypt(content);
				}
			}
			file.writeFile(path2, content);
		}
		else {
			return 0;
		}
	}
	else {
		return 0;
	}
	
	return 0;
}