#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string mensagem;
    std::cout << "Digite uma mensagem: ";
    std::getline(std::cin, mensagem);

    mensagem.erase(std::remove(mensagem.begin(), mensagem.end(), ' '), mensagem.end());
    std::string reversed = mensagem;
    std::reverse(reversed.begin(), reversed.end());

    if (mensagem == reversed) {
        std::cout << "A mensagem um palindromo." << std::endl;
    } else {
        std::cout << "A mensagem nao um palindromo." << std::endl;
    }

    return 0;
}