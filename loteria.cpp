#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

const int MEGA = 1;
const int QUINA = 2;
const int LOTOMANIA = 3;
const int LOTOFACIL = 4;

vector<int> sorteie(int param_numero_dezenas, int param_limite);

void jogar(int jogo, vector<int> regras);

void mostra_sorteados(vector<int> sorteados);

int escolha_de_jogo();

float calcula_preco (int jogo, int dezenas);

int main() {
    vector <int> regras;
    vector <int> precos;
    int opcao;
    opcao = escolha_de_jogo();
    do {
        switch (opcao) {
            case 1 :
                regras = {6, 15, 60};
                cout << "MEGA!" << endl;
                jogar(MEGA, regras);
                break;

            case 2:
                regras = {5, 12, 80};
                cout << "QUINA!" << endl;
                jogar(QUINA, regras);
                break;

            case 3:
                regras = {50, 50, 100};
                cout << "LOTOMANIA!" << endl;
                jogar(LOTOMANIA, regras);
                break;
            case 4:
                regras = {15, 18, 25};
                cout << "LOTOFACIL!" << endl;
                jogar(LOTOFACIL, regras);
                break;
            }
            opcao = escolha_de_jogo();
        }while(opcao != 0);
    return 0;
}

int escolha_de_jogo() {
    int jogo;

    cout << "\n**********************ESCOLHA UM JOGO**********************\n";
    cout << "[1] Mega-Sena\n";
    cout << "[2] Quina\n";
    cout << "[3] Lotomania\n";
    cout << "[4] Lotofacil\n";
    cout << "[0] Sair\n";
    cout << "***********************************************************\n";

    cin >> jogo;

    return jogo;
}

void jogar(int jogo, vector<int> regras) {

    vector<int> sorteados;
    int dezenas;
    int rodadas;

    cout << "Informe o numero de rodadas:";
    cin >> rodadas;

    do {
        cout << "Informe um numero valido de dezenas entre " << regras[0] << " e " << regras[1] << ": ";
        cin >> dezenas;
    } while(dezenas < regras[0] || dezenas > regras[1]);


    for (int i = 0; i < rodadas; i++) {
        sorteados = sorteie(dezenas, regras[2]);
       mostra_sorteados(sorteados);
        cout << "\n\n";
    }

    float preco = calcula_preco(jogo, dezenas);

    system("cls");

    cout << fixed << setprecision(2) << "O valor que deve-se pagar eh R$" << preco * rodadas << endl;

}

float calcula_preco (int jogo, int dezenas){
    float valor;
    map <int, float> mega = {{6, 4.5}, {7, 31.5}, {8, 126}, {9, 378}, {10, 945}, {11, 2079}, {12, 4158}, {13, 7722}, {14, 13513.5}, {15, 22522.5}};
    map <int, float> quina = {{5, 2}, {6, 12}, {7, 42}, {8, 112}, {9, 252}, {10, 504}, {11, 924}, {12, 1584}, {13, 2574}, {14, 4004}, {15, 6006}};
    float lotofacil[] = {2.5, 40, 340, 2040};
    
    switch(jogo){
        case 1: // MEGA-SENA
            valor = mega[dezenas];
            break;
        case 2: // QUINA
            valor = quina[dezenas];
            break;
        case 3: // LOTOMANIA
            valor = 2.5;
            break;
        case 4: // LOTOFACIL
            valor = lotofacil[dezenas-15];
            break;
        default:
            cout << "INVALIDA\n";
            break;
    }

    return valor;
}

vector<int> sorteie(int param_numero_dezenas, int param_limite) {

    vector<int> lista_sorteados;
    bool nao_repetido = true;

    while (lista_sorteados.size() < param_numero_dezenas) {
        int sorteado;
        sorteado = rand() % param_limite + 1;

        /*a cada numero sorteado, percorre a lista procurando um repetido*/
        for (int lista_sorteado : lista_sorteados) {

            if (sorteado == lista_sorteado) {
                nao_repetido = false;
                break;
            }
        }

        if (nao_repetido == true) {
            lista_sorteados.push_back(sorteado);
        } else {
            nao_repetido = true;
        }
    }

    return lista_sorteados;
}

void mostra_sorteados(vector<int> param_sorteados) {
    sort(param_sorteados.begin(), param_sorteados.end());

    for (int num: param_sorteados) {
        cout << num << "  ";
    }
}
