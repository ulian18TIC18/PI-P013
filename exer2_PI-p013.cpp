#include <iostream>
#include <string>

using namespace std;

struct Empregado {
    string nome;
    string sobrenome;
    int anoNascimento;
    string RG;
    int anoAdmissao;
    float salario;
};

void Reajusta_dez_porcento(Empregado empregados[], int qtd) {

    for (int i = 0; i < qtd; ++i) {
        empregados[i].salario *= 1.10;  

    }
}

int main() {

    int capacidade = 50;
    Empregado empregados[capacidade];

    int qtd;

    cout << "Informe o numero de empregados (maximo 50): ";
    cin >> qtd;

    qtd = min(qtd, capacidade);

    for (int i = 0; i < qtd; ++i) {
        cout << "Informe os dados para o empregado " << i + 1 << ":\n";
        cout << "Nome: ";
        cin >> empregados[i].nome;

        cout << "Sobrenome: ";
        cin >> empregados[i].sobrenome;

        cout << "Ano de Nascimento: ";
        cin >> empregados[i].anoNascimento;

        cout << "RG: ";
        cin >> empregados[i].RG;

        cout << "Ano de Admissao: ";
        cin >> empregados[i].anoAdmissao;

        cout << "Salario: ";
        cin >> empregados[i].salario;

        cout << "\n";
    }

    Reajusta_dez_porcento(empregados, qtd);

    cout << "Dados dos empregados após o reajuste:\n";
    for (int i = 0; i < qtd; ++i) {
        cout << "Empregado " << i + 1 << ":\n";
        cout << "Nome: " << empregados[i].nome << " " << empregados[i].sobrenome << "\n";
        cout << "Ano de nascimento: " << empregados[i].anoNascimento << "\n";
        cout << "RG: " << empregados[i].RG << "\n";
        cout << "Ano de contratacao: " << empregados[i].anoAdmissao << "\n";
        cout << "Salario apos reajuste: " << empregados[i].salario << "\n\n";
    }

    return 0;
}