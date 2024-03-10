#include <iostream>
#include <vector>

using namespace std;

class Teatro {
private:
    const int fileiras = 15;
    const int poltronas_por_fileira = 40;
    vector<vector<char>> mapa_ocupacao;
    int lugares_ocupados = 0;
    double valor_bilheteria = 0;

public:
    Teatro() : mapa_ocupacao(fileiras, vector<char>(poltronas_por_fileira, '.')) {}

    void reservar_poltrona(int fileira, int poltrona) {
        if (fileira < 1 || fileira > fileiras || poltrona < 1 || poltrona > poltronas_por_fileira) {
            cout << "Fileira ou poltrona inválida." << endl;
            return;
        }
        
        char& lugar = mapa_ocupacao[fileira - 1][poltrona - 1];
        if (lugar == '#') {
            cout << "Esta poltrona já está ocupada." << endl;
        } else {
            double valor = (fileira <= 5) ? 50.0 : (fileira <= 10) ? 30.0 : 15.0;
            lugar = '#';
            lugares_ocupados++;
            valor_bilheteria += valor;
            cout << "Poltrona reservada com sucesso!" << endl;
        }
    }

    void mostrar_mapa_ocupacao() {
        cout << "Mapa de ocupação:" << endl;
        for (const auto& fileira : mapa_ocupacao) {
            for (char lugar : fileira) {
                cout << lugar << " ";
            }
            cout << endl;
        }
    }

    void mostrar_faturamento() {
        cout << "Qtde de lugares ocupados: " << lugares_ocupados << endl;
        cout << "Valor da bilheteria: R$ " << valor_bilheteria << endl;
    }
};

int main() {
    Teatro teatro;

    while (true) {
        cout << "\nSelecione uma opção:" << endl;
        cout << "0. Finalizar" << endl;
        cout << "1. Reservar poltrona" << endl;
        cout << "2. Mapa de ocupação" << endl;
        cout << "3. Faturamento" << endl;

        int opcao;
        cout << "Opção: ";
        cin >> opcao;

        switch (opcao) {
            case 0:
                cout << "Programa finalizado." << endl;
                return 0;
            case 1: {
                int fileira, poltrona;
                cout << "Digite o número da fileira: ";
                cin >> fileira;
                cout << "Digite o número da poltrona: ";
                cin >> poltrona;
                teatro.reservar_poltrona(fileira, poltrona);
                break;
            }
            case 2:
                teatro.mostrar_mapa_ocupacao();
                break;
            case 3:
                teatro.mostrar_faturamento();
                break;
            default:
                cout << "Opção inválida. Tente novamente." << endl;
                break;
        }
    }

    return 0;
}
