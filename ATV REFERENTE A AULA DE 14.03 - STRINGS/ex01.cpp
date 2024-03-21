#include <iostream>
#include <string>
#include <windows.h>

int main() {
    std::string mensagem;
    std::cout << "Digite uma mensagem: ";
    std::getline(std::cin, mensagem);

    int terminal_width = 80;
    int padding = (terminal_width - mensagem.size()) / 2;

    for (int i = 0; i < 4; i++) {
        std::cout << std::endl;
    }

    for (int i = 0; i < padding; i++) {
        std::cout << " ";
    }

    std::cout << mensagem << std::endl;

    for (int i = 5; i < 20; i++) {
        Sleep(1000);
        for (int j = 0; j < padding; j++) {
            std::cout << " ";
        }
        std::cout << mensagem << std::endl;
    }

    return 0;
}