#include <stdio.h>
#include <locale>
#include <stdlib.h>
#include <iostream>

#define MAX 99

struct
{
    int* id = (int*) malloc(sizeof(int)*MAX);
    int* nome = (int*) malloc(sizeof(int)*MAX);
    int* preco = (int*) malloc(sizeof(int)*MAX);
} SI;

struct
{
    int* id = (int*) malloc(sizeof(int)*MAX);
    int* nome = (int*) malloc(sizeof(int)*MAX);
    int* preco = (int*) malloc(sizeof(int)*MAX);
}carrinho;



int listaMenus(){
    int escolha;
    printf("-------------------LISTA DE MENUS------------------- \n");
    printf("1. Menu do carrinho; \n");
    printf("2. Menu do Sistema Interno (SI); \n");
    printf("3. Terminar programa; \n");
    printf("Digite um número de 1 a 3: ");
    scanf("%d", &escolha);
    while (escolha<1 or escolha>2){
        printf("Valor inválido. Digite um número de 1 a 3: ");
        scanf("%d", &escolha);
    }
    printf("---------------------------------------------------- \n");
    return escolha;
}

int menuCarrinho(){ // Mostra o menu de escolhas, lendo e retornando a escolha do usuário
    int escolha;
    int n = 4;
    printf("----------------------CARRINHO---------------------- \n");
    printf("0. Acessar lista de menus; \n");
    printf("1. Adicionar produto ao carrinho \n");
    printf("2. Remover produto do carrinho \n");
    printf("3. Atualizar um dos produtos do carrinho; \n");
    printf("4. Listar todos os produtos do carrinho; \n");
    printf("Digite um número de 0 a %d para escolher uma opção: \n", n);
    scanf("%d", &escolha);
    while (escolha<0 or escolha>n){
        printf("Valor inválido. Digite um número de 0 a %d: ", n);
        scanf("%d", &escolha);
    }
    printf("---------------------------------------------------- \n");
    return escolha;
}

int menuSI(){
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
    int escolha=0;
    while (escolha!=3){
        escolha = listaMenus();
        while (escolha=1){
            escolha=menuCarrinho();
        }
    }
}
