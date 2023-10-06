#include <iostream>
#include <vector>

using namespace std;

struct Passagem {
    string passageiroNome;
    string passageiroCpf;
    int passageiroIdade;

    int assento;
    string tipoViagem;

    int dataDia;
    int dataMes;
    int hora;
};

int main() {

    vector<Passagem> viagens;
    Passagem novaPassagem;

    bool continuar = true;
    string tempString;
    int somaIdades = 0;  
    int numeroPassageiros = 0;  
    int horarioMaisRentavel = 0;
    int maxPassagens = 0;
    int contagemHorario[5] = {0};

    while (continuar) {
        cout << "Informe o tipo de viagem (ida/volta): ";
        getline(cin, novaPassagem.tipoViagem);

        cout << "Informe o mes da viagem (1-12): ";
        cin >> novaPassagem.dataMes;

        cout << "Informe o dia da viagem (1-30): ";
        cin >> novaPassagem.dataDia;

        cout << "Informe a hora da viagem (08, 10, 13, 15, 20): ";
        cin >> novaPassagem.hora;

        cout << "Informe o número da poltrona (1-40): ";
        cin >> novaPassagem.assento;

        cout << "Informe o nome do passageiro: ";
        getline(cin >> ws, novaPassagem.passageiroNome);

        cout << "Informe o CPF do passageiro: ";
        getline(cin >> ws, novaPassagem.passageiroCpf);

        cout << "Informe a idade do passageiro: ";
        cin >> novaPassagem.passageiroIdade;

        somaIdades += novaPassagem.passageiroIdade;  
        numeroPassageiros++; 

        viagens.push_back(novaPassagem);
        novaPassagem = {};

        cout << "Deseja vender mais uma passagem (s/n)? ";
        getline(cin >> ws, tempString);
        continuar = (tempString == "s" || tempString == "S") ? true : false;

    }

    float mediaIdade = static_cast<float>(somaIdades) / numeroPassageiros;

    for (auto it = viagens.begin(); it != viagens.end(); it++) {
        contagemHorario[it->hora / 5]++;  
    }

    for (int i = 0; i < 5; i++) {
        if (contagemHorario[i] > maxPassagens) {
            maxPassagens = contagemHorario[i];
            horarioMaisRentavel = i;
        }
    }

    cout << "\nInformações das Passagens:\n";

    for (auto it = viagens.begin(); it != viagens.end(); it++) {
        
        cout << "Nome: " << it->passageiroNome << " CPF: " << it->passageiroCpf
             << " Assento: " << it->assento << " Horario: " 
             << it->hora << endl;

    }

    cout << "\nMedia de Idade dos Passageiros: " << mediaIdade 
    << " anos" << endl;
    cout << "Horario de viagem mais barato: " << (horarioMaisRentavel * 5) 
    << " h" << endl;

return 0;
}
