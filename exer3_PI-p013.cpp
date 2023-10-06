#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

struct Produto {
    string codigo;
    string nome;
    double preco;
};

void InserirProduto(vector<Produto>& produtos) {

    if (produtos.size() >= 300) {
        cout << "Erro: Limite de 300 produtos no sistema.\n";
        return;

    }

    Produto novoProduto;
    
    cout << "Informe o codigo do produto (13 numeros): ";
    cin >> novoProduto.codigo;

    auto itCodigo = find_if(produtos.begin(), produtos.end(),
                            [novoProduto](const Produto& p) {
                            return p.codigo == novoProduto.codigo;
                            });

    if (itCodigo != produtos.end()) {
        cout << "Produto com codigo ja cadastrado.\n";
        return;

    }

    cout << "Informe o nome do produto (ate 20 caracteres): ";
    cin.ignore();  
    getline(cin, novoProduto.nome);

    auto itNome = find_if(produtos.begin(), produtos.end(),
                          [novoProduto](const Produto& p) {
                              return p.nome == novoProduto.nome;
                          });

    if (itNome != produtos.end()) {
        cout << "Produto ja cadastrado.\n";
        return;

    }

    cout << "Informe o preco do produto: ";
    cin >> novoProduto.preco;

    produtos.push_back(novoProduto);
    cout << "Produto cadastrado com sucesso.\n";
}

void ExcluirProduto(vector<Produto>& produtos) {
    string codigoExcluir;
    
    cout << "Informe o codigo do produto a ser excluido: ";
    cin >> codigoExcluir;

    auto it = find_if(produtos.begin(), produtos.end(),
                      [codigoExcluir](const Produto& p) {
                          return p.codigo == codigoExcluir;
                      });

    if (it != produtos.end()) {
        produtos.erase(it);
        cout << "Produto excluido com sucesso.\n";
    } 
    else {
        cout << "Produto nao encontrado.\n";
    }
}

void ListarProdutos(const vector<Produto>& produtos) {
    cout << "Lista de Produtos:\n";
    for (const auto& produto : produtos) {
        cout << "Codigo: " << produto.codigo << " | Nome: " << produto.nome
             << " | Preco: " << fixed << setprecision(2) 
             << produto.preco << "\n";
    }
}

void ConsultarPreco(const vector<Produto>& produtos) {
    string codigoConsultar;

    cout << "Informe o codigo do produto para consulta: ";
    cin >> codigoConsultar;

    auto it = find_if(produtos.begin(), produtos.end(),
                      [codigoConsultar](const Produto& p) {
                          return p.codigo == codigoConsultar;
                      });

    if (it != produtos.end()) {
        cout << "Preco do produto " << it->nome << ": "
             << fixed << setprecision(2) << it->preco << "\n";
    } 
    else {
        cout << "Produto nao encontrado.\n";

    }
}

int main() {

    vector<Produto> produtos;

    int opcao;

    do {
        cout << "\n|---------Menu---------|\n";
        cout << "___Escolha uma opcao___\n";
        cout << "1. Inserir novo produto.\n";
        cout << "2. Excluir produto.\n";
        cout << "3. Listar produtos.\n";
        cout << "4. Consultar preco por codigo.\n";
        cout << "5. Sair.\n";

        cin >> opcao;

        switch (opcao) {

            case 1:
                InserirProduto(produtos);
                break;

            case 2:
                ExcluirProduto(produtos);
                break;

            case 3:
                ListarProdutos(produtos);
                break;

            case 4:
                ConsultarPreco(produtos);
                break;

            case 5:
                cout << "Saindo do programa.\n";
                break;

            default:
                cout << "Opcao invalida.\n";

        }

    } 

    while (opcao != 5);

    return 0;
}

