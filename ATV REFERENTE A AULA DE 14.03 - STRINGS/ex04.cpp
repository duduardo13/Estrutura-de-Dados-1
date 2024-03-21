#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main() {
    std::ifstream file("C:/Users/User/Desktop/IFSP-PROGRAMACAO-C/c++program/texto.txt");
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string nome, sobrenome;
        while (iss >> nome) {
            sobrenome = nome;
        }
        std::string iniciais;
        std::istringstream iss2(line.substr(0, line.rfind(sobrenome)));
        while (iss2 >> nome) {
            iniciais += nome[0];
            iniciais += ". ";
        }
        std::cout << sobrenome << ", " << iniciais << std::endl;
    }
    return 0;
}