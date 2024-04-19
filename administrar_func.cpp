#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Definição da estrutura Funcionario
struct Funcionario {
    int prontuario;
    string nome;
    double salario;
};

// Função para verificar se um funcionário já existe na lista com base no prontuário
bool funcionarioExiste(const vector<Funcionario>& funcionarios, int prontuario) {
    for (const Funcionario& funcionario : funcionarios) {
        if (funcionario.prontuario == prontuario) {
            return true;
        }
    }
    return false;
}

// Função para incluir um novo funcionário na lista
void incluirFuncionario(vector<Funcionario>& funcionarios) {
    Funcionario novoFuncionario;
    cout << "Digite o prontuario: ";
    cin >> novoFuncionario.prontuario;
    if (funcionarioExiste(funcionarios, novoFuncionario.prontuario)) {
        cout << "Erro: funcionario com mesmo prontuario ja cadastrado." << endl;
        return;
    }
    cout << "Digite o nome: ";
    cin.ignore(); // Limpa o buffer do teclado antes de ler a string
    getline(cin, novoFuncionario.nome);
    cout << "Digite o salario: ";
    cin >> novoFuncionario.salario;
    funcionarios.push_back(novoFuncionario);
    cout << "Funcionario cadastrado com sucesso." << endl;
}

// Função para excluir um funcionário da lista
void excluirFuncionario(vector<Funcionario>& funcionarios) {
    int prontuario;
    cout << "Digite o prontuario do funcionario a ser excluido: ";
    cin >> prontuario;
    for (auto it = funcionarios.begin(); it != funcionarios.end(); ++it) {
        if (it->prontuario == prontuario) {
            funcionarios.erase(it);
            cout << "Funcionario excluido com sucesso." << endl;
            return;
        }
    }
    cout << "Funcionario nao encontrado." << endl;
}

// Função para pesquisar um funcionário na lista pelo prontuário
void pesquisarFuncionario(const vector<Funcionario>& funcionarios) {
    int prontuario;
    cout << "Digite o prontuario do funcionario a ser pesquisado: ";
    cin >> prontuario;
    for (const Funcionario& funcionario : funcionarios) {
        if (funcionario.prontuario == prontuario) {
            cout << "Prontuario: " << funcionario.prontuario << endl;
            cout << "Nome: " << funcionario.nome << endl;
            cout << "Salario: " << funcionario.salario << endl;
            return;
        }
    }
    cout << "Funcionario nao encontrado." << endl;
}

// Função para listar todos os funcionários e calcular o total dos salários
void listarFuncionarios(const vector<Funcionario>& funcionarios) {
    double totalSalarios = 0.0;
    cout << "Lista de funcionarios:" << endl;
    for (const Funcionario& funcionario : funcionarios) {
        cout << "Prontuario: " << funcionario.prontuario << ", Nome: " << funcionario.nome << ", Salario: " << funcionario.salario << endl;
        totalSalarios += funcionario.salario;
    }
    cout << "Total dos salarios: " << totalSalarios << endl;
}

int main() {
    vector<Funcionario> funcionarios;
    int opcao;
    
    do {
        cout << "\nMenu:" << endl;
        cout << "0. Sair" << endl;
        cout << "1. Incluir" << endl;
        cout << "2. Excluir" << endl;
        cout << "3. Pesquisar" << endl;
        cout << "4. Listar" << endl;
        cout << "Digite sua opcao: ";
        cin >> opcao;
        
        switch(opcao) {
            case 0:
                cout << "Saindo do programa." << endl;
                break;
            case 1:
                incluirFuncionario(funcionarios);
                break;
            case 2:
                excluirFuncionario(funcionarios);
                break;
            case 3:
                pesquisarFuncionario(funcionarios);
                break;
            case 4:
                listarFuncionarios(funcionarios);
                break;
            default:
                cout << "Opcao invalida. Tente novamente." << endl;
        }
    } while (opcao != 0);
    
    return 0;}
