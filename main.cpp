#include <stdio.h>
#include <locale>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>


struct si
{
    std::vector<int> id = {1, 2, 3, 4, 5}; 
    std::vector<std::string> nome = {};
    std::vector<double> preco = {};
} si; // Produtos do Sistema Interno (SI)

struct carrinho
{
    std::vector<int> id;
    std::vector<std::string> nome;
    std::vector<double> preco;
    std::vector<int> quanti;
}carrinho; // Produtos do Carrinho

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
    int n = 4;
    printf("----------------------CARRINHO---------------------- \n");
    printf("0. Acessar lista de menus; \n");
    printf("1. Adicionar produto ao carrinho \n");
    printf("2. Remover produto do carrinho \n");
    printf("3. Atualizar um dos produtos do carrinho; \n");
    printf("4. Listar todos os produtos do carrinho; \n");
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

void addCadastro(std::string nome, int preco){ // Cadastra um produto no sistema
    si.id.push_back(acharMaior(si.id));


}



void attCadastro(){ // Atualiza um produto do sistema

}

void rmvCadastro(){ // Remove um cadastro do sistema

}

void listarCadastros(){ // Lista todos os produtos cadastrados no sistema

}

void addProduCarrinho(){ // Adiciona um produto ao carrinho

}

void attProduCarrinho(){ // Atualiza a quantia de um dos produtos do carrinho

}

void rmvProduCarrinho(){ // Remove um produto do carrinho
    
}

void listarCarrinho(){ // Lista todos os produtos do carrinho

}

void limparCompras(){ // Finaliza as compras e esvazia o carrinho

}

int main() {
    setlocale(LC_ALL, "");
    int escolha;
    while (true){
        escolha = listaMenus();
        if (escolha==1){ // Menu do carrinho
            while (true){
                escolha=menuCarrinho();
                if (escolha==0){
                    break;
                }
            }
        }
        if (escolha==2){ // Menu do SI
            while (true){
                escolha=menuSI();
                if (escolha==0){
                    break;
                }
            }
        }
        if (escolha==3){
            printf("Finalizando programa...\n");
            break;
        }
    }
}
