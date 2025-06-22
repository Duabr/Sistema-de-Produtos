#include <stdio.h>
#include <locale>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>


struct si
{
    std::vector<int> id = {0, 1, 2, 3, 4};
    std::vector<std::string> nome = {"Arroz 1KG", "Feijão 1KG", "Leite 1L", "Pipoca 500g", "Honda Civic 2010"};
    std::vector<double> preco = {7.99, 5.99, 5.60, 4.99, 25900.0};
} si; // Produtos do Sistema Interno (SI)

struct carrinho
{
    std::vector<int> id;
    std::vector<std::string> nome;
    std::vector<double> preco;
    std::vector<int> quanti;
}carrinho; // Produtos do Carrinho
// Dica: dá pra usar a função "push_back" para adicionar um novo item ao final de uma lista (igual eu usei na função addCadastro por exemplo)

int acharMaior(std::vector<int> lista){ // Achar o maior número de uma lista (para gerar um novo id pra todo novo cadastro no SI)
    int maior=lista[0];
    for (int i=1; i<lista.size(); i++){
        if (lista[i] > maior){
            maior=lista[i];
        }
    }
    return maior;
}

int listaMenus(){ // Mostra os menus acessíveis com a opção de terminar o programa
    int escolha;
    printf("-------------------LISTA DE MENUS------------------- \n");
    printf("1. Menu do carrinho; \n");
    printf("2. Menu do Sistema Interno (SI); \n");
    printf("3. Terminar programa; \n");
    printf("Digite um número de 1 a 3: ");
    scanf("%d", &escolha);

    while (escolha<1 or escolha>3){
        printf("Valor inválido. Digite um número de 1 a 3: ");
        scanf("%d", &escolha);
    }

    printf("---------------------------------------------------- \n");
    return escolha;
}

int menuCarrinho(){ // Mostra o menu do carrinho
    int escolha;
    int n = 5;

    printf("----------------------CARRINHO---------------------- \n");
    printf("0. Acessar lista de menus; \n");
    printf("1. Adicionar produto ao carrinho \n");
    printf("2. Remover produto do carrinho \n");
    printf("3. Atualizar um dos produtos do carrinho; \n");
    printf("4. Listar todos os produtos do carrinho; \n");
    printf("5. Terminar compras (esvazia o carrinho e mostra o preço total)");
    printf("Digite um número de 0 a %d para escolher uma opção: ", n);
    scanf("%d", &escolha);

    while (escolha<0 or escolha>n){
        printf("Valor inválido. Digite um número de 0 a %d: ", n);
        scanf("%d", &escolha);
    }

    printf("---------------------------------------------------- \n");
    return escolha;
}

int menuSI(){ // Mostra o menu do SI
    int escolha;
    int n = 4;

    printf("-------------------SISTEMA INTERNO------------------ \n");
    printf("0. Acessar lista de menus; \n");
    printf("1. Cadastrar produto no SI; \n"); // SI é uma abreviação para Sistema Interno
    printf("2. Remover cadastro do SI; \n");
    printf("3. Editar cadastro do SI; \n");
    printf("4. Listar todos os cadastros do SI; \n");
    printf("Digite um número de 0 a %d para escolher uma opção: ", n);
    scanf("%d", &escolha);

    while (escolha<0 or escolha>n){
        printf("Valor inválido. Digite um número de 0 a %d: ", n);
        scanf("%d", &escolha);
    }

    printf("----------------------------------------------------- \n");
    return escolha;
}

void addCadastro(){ // Cadastra um produto no sistema
    std::string nome;
    double preco;

    while ((getchar()) != '\n'); // É necessário para limpar o buffer e o std::getline() ler corretamente o nome do produto

    std::cout << "Digite o nome do novo produto: ";
    std::getline(std::cin, nome);
    std::cout << "Digite o preço para o novo produto: ";
    std::cin >> preco;

    si.id.push_back(acharMaior(si.id)+1);
    si.nome.push_back(nome);
    si.preco.push_back(preco);

    printf("Produto cadastrado com sucesso! \n");
}

void rmvCadastro(){ // Remove um cadastro do sistema
    int id;
    int esc;

    printf("Digite o ID do produto que deseja remover: ");
    scanf("%d", &id);

    std::cout << si.nome[id] << ", R$" << si.preco[id] << ". \n";
    printf("É esse o produto que deseja remover? Digite 1 para sim: ");
    scanf("%d", &esc);

    if (esc==1){
        si.id.erase(si.id.begin() + id);
        si.nome.erase(si.nome.begin() + id);
        si.preco.erase(si.preco.begin() + id);
        for (int i=id; i<si.id.size(); i++){
            si.id[i]--;
        }
        printf("Prouduto removido com sucesso!\n");
    }
}

void attCadastro(){ // Edita um produto do sistema

}

void listarCadastros(){ // Lista todos os produtos cadastrados no sistema
    for (int i=0; i<si.id.size(); i++){
        std::cout << "Produto " << si.id[i] << ": " << si.nome[i] << ", R$";
        printf("%.2lf \n", si.preco[i]);
    }
    system("pause");
}

void addProduCarrinho(){ // Adiciona um produto ao carrinho

}

void rmvProduCarrinho(){ // Remove um produto do carrinho
    
}

void attProduCarrinho(){ // Atualiza a quantia de um dos produtos do carrinho

}

void listarCarrinho(){ // Lista todos os produtos do carrinho

}

void limparCompras(){ // Finaliza as compras, esvazia o carrinho e retorna o usuário para a lista de menus

}

int main() {
    setlocale(LC_ALL, "");
    int escolha;
    while (true){
        escolha = listaMenus();
        if (escolha==1){ // Menu do carrinho
            while (true){
                escolha = menuCarrinho();
                if (escolha==0){
                    break;
                }
            }
        }
        if (escolha==2){ // Menu do SI
            while (true){
                escolha = menuSI();
                if (escolha==0){
                    break;
                } else if (escolha==1){
                    addCadastro();
                } else if (escolha==2){
                    rmvCadastro();
                } else if (escolha==3){
                    attCadastro();
                } else if (escolha==4){
                    listarCadastros();
                }
            }
        }
        if (escolha==3){
            printf("Finalizando programa...\n");
            break;
        }
    }
}
