#include <iostream>

class Fichier {
public:
	std::string readFile(std::string file_name) const;
	void writeFile(std::string file_name, std::string content) const;
};