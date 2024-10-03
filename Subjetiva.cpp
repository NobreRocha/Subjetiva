#include <iostream>
#include <array>
#include <cctype> // Para tolower

using namespace std;

const int LIN = 10;
const int COL = 6;

using Reservations = array<array<bool, COL>, LIN>;

void mostrarPoltronas(const Reservations& reservas) {
    cout << "\n\t\t\t\t[A] [B] [C]  [D] [E] [F]\n"; // Cabeçalho das poltronas com colchetes e espaço entre C e D
    for (int l = 0; l < LIN; l++) {
        cout << "\n\t\t\t" << (l + 1 < 10 ? "0" : "") << (l + 1) << "\t"; // Adiciona zero antes da numeração
        for (int c = 0; c < COL; c++) {
            cout << (reservas[l][c] ? "[X]" : "[O]") << " "; // '[X]' para reservado, '[O]' para disponível
            if (c == 2) cout << " "; // Adiciona um espaço extra entre C e D
        }
        cout << "\n";
    }
}

int selecionarPoltrona(char poltrona) {
    poltrona = tolower(poltrona); // Converte para minúscula
    switch (poltrona) {
        case 'a': return 0;
        case 'b': return 1;
        case 'c': return 2;
        case 'd': return 3;
        case 'e': return 4;
        case 'f': return 5;
        default: return -1; // Retorna -1 se a poltrona não for válida
    }
}

bool verificarDisponibilidade(const Reservations& reservas, int lin, int col) {
    return !reservas[lin][col];
}

void reservarPoltrona(Reservations& reservas, int lin, int col) {
    reservas[lin][col] = true; // Marca a poltrona como reservada
}

void reservarComboFamilia(Reservations& reservas, int numPessoas) {
    int lin, col;
    char poltrona;

    for (int i = 0; i < numPessoas; i++) {
        cout << "Selecione a fileira (1 a 10) para a pessoa " << (i + 1) << ": ";
        cin >> lin;

        while (lin < 1 || lin > 10) {
            cout << "Fileira inválida. Selecione uma fileira (1 a 10) para a pessoa " << (i + 1) << ": ";
            cin >> lin;
        }
        lin -= 1; // Ajusta para índice baseado em zero

        do {
            cout << "Selecione a poltrona (B, C, D ou E) para a pessoa " << (i + 1) << ": ";
            cin >> poltrona;
            col = selecionarPoltrona(poltrona);

            if (col == -1 || poltrona == 'a' || poltrona == 'f' || poltrona == 'A' || poltrona == 'F') {
                cout << "Somente as poltronas B, C, D ou E estão disponíveis para o Combo Família.\n";
            }
        } while (col == -1 || poltrona == 'a' || poltrona == 'f' || poltrona == 'A' || poltrona == 'F');

        if (verificarDisponibilidade(reservas, lin, col)) {
            reservarPoltrona(reservas, lin, col);
            cout << "Poltrona reservada com sucesso para a pessoa " << (i + 1) << "!\n";
        } else {
            cout << "Poltrona já ocupada. Escolha outra.\n";
            i--; // Refazer a reserva para essa pessoa
        }
    }
}

void reservarComboCasal(Reservations& reservas) {
    int lin, col;
    char poltrona;

    for (int i = 0; i < 2; i++) {
        cout << "Selecione a fileira (1 a 10) para a pessoa " << (i + 1) << ": ";
        cin >> lin;

        while (lin < 1 || lin > 10) {
            cout << "Fileira inválida. Selecione uma fileira (1 a 10) para a pessoa " << (i + 1) << ": ";
            cin >> lin;
        }
        lin -= 1; // Ajusta para índice baseado em zero

        do {
            cout << "Selecione a poltrona (B, C, D ou E) para a pessoa " << (i + 1) << ": ";
            cin >> poltrona;
            col = selecionarPoltrona(poltrona);

            if (col == -1 || poltrona == 'a' || poltrona == 'f' || poltrona == 'A' || poltrona == 'F') {
                cout << "Somente as poltronas B, C, D ou E estão disponíveis para o Combo Casal.\n";
            }
        } while (col == -1 || poltrona == 'a' || poltrona == 'f' || poltrona == 'A' || poltrona == 'F');

        if (verificarDisponibilidade(reservas, lin, col)) {
            reservarPoltrona(reservas, lin, col);
            cout << "Poltrona reservada com sucesso para a pessoa " << (i + 1) << "!\n";
        } else {
            cout << "Poltrona já ocupada. Escolha outra.\n";
            i--; // Refazer a reserva para essa pessoa
        }
    }
}

void reservarPassagemVIP(Reservations& reservas) {
    int lin, col;
    char poltrona;

    cout << "Selecione a fileira (1 a 10): ";
    cin >> lin;
    while (lin < 1 || lin > 10) {
        cout << "Fileira inválida. Selecione a fileira (1 a 10): ";
        cin >> lin;
    }
    lin -= 1; // Ajusta para índice baseado em zero

    cout << "Selecione a poltrona (A a F): ";
    cin >> poltrona;
    col = selecionarPoltrona(poltrona);

    if (verificarDisponibilidade(reservas, lin, col)) {
        reservarPoltrona(reservas, lin, col);
        cout << "Poltrona VIP reservada com sucesso!\n";
    } else {
        cout << "Poltrona já ocupada. Escolha outra.\n";
    }
}

void reservarPassagemEconomica(Reservations& reservas) {
    int lin, col;
    char poltrona;

    cout << "Selecione a fileira (1 a 10): ";
    cin >> lin;
    while (lin < 1 || lin > 10) {
        cout << "Fileira inválida. Selecione a fileira (1 a 10): ";
        cin >> lin;
    }
    lin -= 1; // Ajusta para índice baseado em zero

    do {
        cout << "Selecione a poltrona (B, C, D ou E): ";
        cin >> poltrona;
        col = selecionarPoltrona(poltrona);

        if (col == -1 || poltrona == 'a' || poltrona == 'f' || poltrona == 'A' || poltrona == 'F') {
            cout << "Somente as poltronas B, C, D ou E estão disponíveis para Passagem Econômica.\n";
        }
    } while (col == -1 || poltrona == 'a' || poltrona == 'f' || poltrona == 'A' || poltrona == 'F');

    if (verificarDisponibilidade(reservas, lin, col)) {
        reservarPoltrona(reservas, lin, col);
        cout << "Poltrona Econômica reservada com sucesso!\n";
    } else {
        cout << "Poltrona já ocupada. Escolha outra.\n";
    }
}

int main() {
    Reservations reservas = {};

    int escolha;
    do {
        cout << "Bem-vindo ao sistema de reservas de passagens!\n";
        cout << "1. Combo Família (3 ou mais pessoas, sem assentos A e F)\n";
        cout << "2. Combo Casal (2 pessoas, sem assentos A e F)\n";
        cout << "3. Passagem VIP (escolha qualquer poltrona, incluindo A e F)\n";
        cout << "4. Passagem Econômica (1 pessoa, sem assentos A e F)\n";
        cout << "5. Mostrar poltronas\n";
        cout << "6. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> escolha;

        switch (escolha) {
            case 1: {
                int numPessoas;
                cout << "Quantas pessoas (3 ou mais)? ";
                cin >> numPessoas;
                if (numPessoas >= 3) {
                    reservarComboFamilia(reservas, numPessoas);
                } else {
                    cout << "O Combo Família exige no mínimo 3 pessoas.\n";
                }
                break;
            }
            case 2:
                reservarComboCasal(reservas);
                break;
            case 3:
                reservarPassagemVIP(reservas);
                break;
            case 4:
                reservarPassagemEconomica(reservas);
                break;
            case 5:
                mostrarPoltronas(reservas);
                break;
            case 6:
                cout << "Encerrando o sistema.\n";
                break;
            default:
                cout << "Opção inválida. Tente novamente.\n";
                break;
        }
    } while (escolha != 6);

    return 0;
}
