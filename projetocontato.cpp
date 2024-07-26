#include <iostream>
#include <string>
#include <iomanip> 
#include <vector>

//jackson de lima gregório CB3013189

class Data {
private:
    int dia;
    int mes;
    int ano;

public:
     Data() {}

    Data(int dia, int mes, int ano) {
        this->dia = dia;
        this->mes = mes;
        this->ano = ano;
    }

    int getDia() const {
        return dia;
    }

    void setDia(int dia) {
        this->dia = dia;
    }

    int getMes() const {
        return mes;
    }

    void setMes(int mes) {
        this->mes = mes;
    }

    int getAno() const {
        return ano;
    }

    void setAno(int ano) {
        this->ano = ano;
    }
};

class Contato {
private:
    std::string email;
    std::string nome;
    std::string telefone;
    Data dtnasc;

public:
    Contato(const std::string& email, const std::string& nome, const std::string& telefone, const Data& dtnasc) {
        this->email = email;
        this->nome = nome;
        this->telefone = telefone;
        this->dtnasc = dtnasc;
    }

    std::string getEmail() const {
        return email;
    }

    void setEmail(const std::string& email) {
        this->email = email;
    }

    std::string getNome() const {
        return nome;
    }

    void setNome(const std::string& nome) {
        this->nome = nome;
    }

    std::string getTelefone() const {
        return telefone;
    }

    void setTelefone(const std::string& telefone) {
        this->telefone = telefone;
    }

    Data getDtnasc() const {
        return dtnasc;
    }

    void setDtnasc(const Data& dtnasc) {
        this->dtnasc = dtnasc;
    }

    int idade() const {
        
        int currentYear = 2024;
        return currentYear - dtnasc.getAno();
    }
};

void printData(const Data& data) {
    std::cout << "---------------------\n";
    std::cout << "| Data              |\n";
    std::cout << "|-------------------|\n";
    std::cout << "| - dia: " << data.getDia() << " | \n";
    std::cout << "| - mes: " << data.getMes() << " | \n";
    std::cout << "| - ano: " << data.getAno() << " | \n";
    std::cout << "---------------------\n";
}

void printContato(const Contato& contato) {
	printData(contato.getDtnasc());
    std::cout << "---------------------------------------\n";
    std::cout << "| Contato                             |\n";
    std::cout << "|-------------------------------------|\n";
	std::cout << "| - email: " << contato.getEmail() << " | \n";	
    std::cout << "| - nome: " << contato.getNome() << " | \n";
    std::cout << "| - telefone: " << contato.getTelefone() << " | \n";	
    std::cout << "| - dtnasc:"  << contato.getDtnasc().getDia() << " | \n";
    std::cout << "|-------------------------------------|\n";
    std::cout << "| + idade(): " << contato.idade() << " | \n";
    std::cout << "---------------------------------------\n";
}


int main() {
    std::vector<Contato> contatos;
    int numContatos;

    std::cout << "Digite o número de contatos (1-5): ";
    std::cin >> numContatos;

    for (int i = 0; i < numContatos; i++) {
        std::string email, nome, telefone;
        int dia, mes, ano;

        std::cout << "Digite o email do contato " << i+1 << ": ";
        std::cin >> email;
        std::cout << "Digite o nome do contato " << i+1 << ": ";
        std::cin >> nome;
        std::cout << "Digite o telefone do contato " << i+1 << ": ";
        std::cin >> telefone;
        std::cout << "Digite o dia de nascimento do contato " << i+1 << ": ";
        std::cin >> dia;
        std::cout << "Digite o mês de nascimento do contato " << i+1 << ": ";
        std::cin >> mes;
        std::cout << "Digite o ano de nascimento do contato " << i+1 << ": ";
        std::cin >> ano;

        contatos.push_back(Contato(email, nome, telefone, Data(dia, mes, ano)));
    }

    for (int i = 0; i < numContatos; i++) {
        printContato(contatos[i]);
    }

    return 0;
