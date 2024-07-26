//Por Eduardo Barbosa Rodrigues e Vinicius Pontes Oliva

#include <iostream>
#include <vector>
using namespace std;

// Definição da estrutura do nó da fila
struct No {
    int dado; // Dado armazenado no nó
    No *prox; // Ponteiro para o próximo nó na fila
};

// Definição da estrutura da fila
struct Fila {
    No *ini; // Ponteiro para o primeiro nó da fila
    No *fim; // Ponteiro para o último nó da fila
};

// Definição da estrutura do guichê
struct Guiche {
    int id; // Identificador do guichê
    Fila *senhasAtendidas; // Fila de senhas atendidas pelo guichê
};

// Função para inicializar a fila
Fila* iniciarFila() {
    Fila *f = new Fila; // Aloca memória para a fila
    f->ini = NULL; // Inicializa o ponteiro de início com null
    f->fim = NULL; // Inicializa o ponteiro de fim com null
    return f; // Retorna a fila inicializada
}

// Função para verificar se a fila está vazia
bool filaVazia(Fila *f) {
    return (f->ini == NULL); // Retorna verdadeiro se o ponteiro de início for null
}

// Função para enfileirar um elemento na fila
void enfileirar(Fila *f, int valor) {
    No *novoNo = new No; // Cria um novo nó
    novoNo->dado = valor; // Atribui o valor ao dado do nó
    novoNo->prox = NULL; // Inicializa o próximo do nó como null

    if (filaVazia(f)) { // Se a fila estiver vazia
        f->ini = novoNo; // O início da fila aponta para o novo nó
    } else {
        f->fim->prox = novoNo; // Caso contrário, o próximo do último nó aponta para o novo nó
    }
    f->fim = novoNo; // Atualiza o fim da fila para o novo nó
}

// Função para desenfileirar um elemento da fila
int desenfileirar(Fila *f) {
    if (filaVazia(f)) { // Verifica se a fila está vazia
        return -1; // Retorna -1 se a fila estiver vazia
    } else {
        No *primeiroNo = f->ini; // Obtém o primeiro nó da fila
        int dadoRetornado = primeiroNo->dado; // Obtém o dado do primeiro nó
        f->ini = primeiroNo->prox; // Atualiza o início da fila para o próximo nó
        if (f->ini == NULL) { // Se o início se tornar nulo (fila ficar vazia)
            f->fim = NULL; // Atualiza o fim da fila para nulo também
        }
        delete primeiroNo; // Libera a memória do nó desenfileirado
        return dadoRetornado; // Retorna o dado do nó desenfileirado
    }
}

// Função para contar o número de elementos na fila
int contarElementos(Fila *f) {
    int quantidade = 0; // Inicializa a variável para contar os elementos
    No *noAtual = f->ini; // Começa do início da fila

    while (noAtual != NULL) { // Percorre todos os nós da fila
        quantidade++; // Incrementa o contador
        noAtual = noAtual->prox; // Move para o próximo nó
    }
    return quantidade; // Retorna a quantidade de elementos na fila
}

// Função para listar as senhas atendidas por um guichê
void listarSenhasAtendidas(Fila *f) {
    if (filaVazia(f)) {
        cout << "Nenhuma senha foi atendida ainda.\n";
        return;
    }

    No *noAtual = f->ini; // Começa do início da fila
    cout << "Senhas atendidas:\n";
    while (noAtual != NULL) { // Percorre todos os nós da fila
        cout << noAtual->dado << " "; // Imprime o dado de cada nó
        noAtual = noAtual->prox; // Move para o próximo nó
    }
    cout << "\n";
}

// Função para liberar a memória alocada para a fila
void liberarFila(Fila *f) {
    No *noAtual = f->ini; // Começa do início da fila

    while (noAtual != NULL) { // Enquanto houver nós na fila
        No *proximoNo = noAtual->prox; // Guarda o próximo nó
        delete noAtual; // Libera a memória do nó atual
        noAtual = proximoNo; // Move para o próximo nó
    }
    delete f; // Libera a memória da estrutura da fila
}

// Função principal
int main() {
    Fila *filaSenhasGeradas = iniciarFila(); // Inicializa a fila de senhas geradas
    vector<Guiche> guiches; // Vetor de guichês
    int opcao; // Variável para armazenar a opção do usuário
    int proximaSenha = 0; // Variável para controlar o número da próxima senha a ser gerada

    do {
        // Menu de opções
        cout << "Selecione uma opcao:\n";
        cout << "0. Sair\n";
        cout << "1. Gerar senha\n";
        cout << "2. Abrir guiche\n";
        cout << "3. Realizar atendimento\n";
        cout << "4. Listar senhas atendidas\n";
        cout << "Senhas aguardando atendimento: " << contarElementos(filaSenhasGeradas) << "\n"; // Exibe a quantidade de senhas na fila de geradas
        cout << "Guiches abertos: " << guiches.size() << "\n"; // Exibe a quantidade de guichês abertos
        cin >> opcao; // Lê a opção do usuário

        switch(opcao) {
            case 0:
                if (!filaVazia(filaSenhasGeradas)) { // Verifica se há senhas aguardando atendimento
                    cout << "Ainda existem senhas aguardando atendimento. Continue o atendimento antes de sair.\n"; // Mensagem de aviso
                    opcao = -1; // Para evitar sair do loop se houver senhas aguardando
                } else {
                    int totalSenhasAtendidas = 0;
                    for (const Guiche &g : guiches) {
                        totalSenhasAtendidas += contarElementos(g.senhasAtendidas);
                    }
                    cout << "Quantidade de senhas atendidas: " << totalSenhasAtendidas << "\n"; // Exibe a quantidade de senhas atendidas ao sair
                }
                break;
            case 1:
                proximaSenha++; // Incrementa o número da senha atual
                enfileirar(filaSenhasGeradas, proximaSenha); // Enfileira a nova senha gerada
                cout << "Senha gerada: " << proximaSenha << "\n"; // Exibe a senha gerada
                break;
            case 2: {
                int idGuiche;
                cout << "Digite o ID do novo guiche: ";
                cin >> idGuiche;
                Guiche novoGuiche;
                novoGuiche.id = idGuiche;
                novoGuiche.senhasAtendidas = iniciarFila();
                guiches.push_back(novoGuiche);
                cout << "Guiche " << idGuiche << " aberto.\n";
                break;
            }
            case 3: {
                if (filaVazia(filaSenhasGeradas)) {
                    cout << "Nao ha senhas para atendimento.\n";
                } else {
                    int idGuiche;
                    cout << "Digite o ID do guiche: ";
                    cin >> idGuiche;
                    bool guicheEncontrado = false;
                    for (Guiche &g : guiches) {
                        if (g.id == idGuiche) {
                            int senhaAtendida = desenfileirar(filaSenhasGeradas);
                            enfileirar(g.senhasAtendidas, senhaAtendida);
                            cout << "Guiche " << idGuiche << " atendendo senha: " << senhaAtendida << "\n";
                            guicheEncontrado = true;
                            break;
                        }
                    }
                    if (!guicheEncontrado) {
                        cout << "Guiche " << idGuiche << " nao encontrado.\n";
                    }
                }
                break;
            }
            case 4: {
                int idGuiche;
                cout << "Digite o ID do guiche: ";
                cin >> idGuiche;
                bool guicheEncontrado = false;
                for (const Guiche &g : guiches) {
                    if (g.id == idGuiche) {
                        listarSenhasAtendidas(g.senhasAtendidas);
                        guicheEncontrado = true;
                        break;
                    }
                }
                if (!guicheEncontrado) {
                    cout << "Guiche " << idGuiche << " nao encontrado.\n";
                }
                break;
            }
            default:
                cout << "Opcao invalida. Tente novamente.\n"; // Mensagem de opção inválida
                break;
        }
    } while (opcao != 0); // Continua o loop até o usuário escolher sair

    liberarFila(filaSenhasGeradas); // Libera a memória da fila de senhas geradas
    for (Guiche &g : guiches) {
        liberarFila(g.senhasAtendidas); // Libera a memória das filas de senhas atendidas dos guichês
    }

    return 0; // Retorna 0 para indicar que o programa terminou com sucesso
}
