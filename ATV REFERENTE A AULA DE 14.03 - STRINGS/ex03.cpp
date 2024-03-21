#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main() {
    std::ifstream file("C:/Users/User/Desktop/IFSP-PROGRAMACAO-C/c++program/texto.txt");
    if (!file) {
    std::cerr << "Erro ao abrir o arquivo nomes.txt\n";
    return 1;
	}
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string nome, sobrenome;
        while (iss >> nome) {
            sobrenome = nome;
        }
        std::cout << sobrenome << ", " << line.substr(0, line.rfind(sobrenome)) << std::endl;
    }
    return 0;
}