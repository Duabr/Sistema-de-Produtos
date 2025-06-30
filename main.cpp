#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

int linhaAtual = 1; // Variável global para controlar a linha atual do arquivo

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

std::string lerLinha(int numeroLinha) { // Lê e retorna o conteúdo de uma linha específica do arquivo sem a quebra de linha
    FILE *arq;
    char Linha[100]; // Variável para armazenar o conteúdo de uma linha
    arq = fopen("dados.txt", "rt");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo dados.txt \n");
        return "";
    }

    int i = 1;
    std::string conteudo = "";
    while (fgets(Linha, sizeof(Linha), arq)) {
        if (i == numeroLinha) {
            conteudo = Linha;
            if (!conteudo.empty() && conteudo.back() == '\n') { // Remove a quebra de linha, se existir
                conteudo.pop_back();
            }
            break;
        }
        i++;
    }
    fclose(arq);
    if (conteudo.empty()) {
        printf("Linha %d não encontrada no arquivo.\n", numeroLinha);
        return "";
    }
    std::cout << conteudo << std::endl; // Mostra o conteúdo lido
    return conteudo;
}

double stringParaDouble(const std::string& str) {
    return std::stod(str);
}

int acharMaior(std::vector<int> lista){ // Achar o maior número de uma lista (para gerar um novo id pra todo novo cadastro no SI)
    int maior=lista[0];
    for (int i=1; i<lista.size(); i++){
        if (lista[i] > maior){
            maior=lista[i];
        }
    }
    return maior;
}

int listaMenus(int linhaEscolha){ // Mostra os menus acessíveis com a opção de terminar o programa
    int escolha;
    printf("-------------------LISTA DE MENUS------------------- \n");
    printf("1. Menu do carrinho; \n");
    printf("2. Menu do Sistema Interno (SI); \n");
    printf("3. Terminar programa; \n");
    printf("Digite um número de 1 a 3: ");
    escolha = lerLinha(linhaEscolha)[0] - '0';
    linhaAtual++;

    while (escolha<1 || escolha>3){
        printf("Valor inválido. Digite um número de 1 a 3: \n");
        scanf("%d", &escolha);
    }

    printf("---------------------------------------------------- \n");
    return escolha;
}

int menuCarrinho(int linhaEscolha){ // Mostra o menu do carrinho
    int escolha;
    int n = 5;

    printf("----------------------CARRINHO---------------------- \n");
    printf("0. Acessar lista de menus; \n");
    printf("1. Adicionar produto ao carrinho \n");
    printf("2. Remover produto do carrinho \n");
    printf("3. Atualizar um dos produtos do carrinho; \n");
    printf("4. Listar todos os produtos do carrinho; \n");
    printf("5. Terminar compras (esvazia o carrinho e mostra o preço total) \n");
    printf("Digite um número de 0 a %d para escolher uma opção: ", n);
    escolha = lerLinha(linhaEscolha)[0] - '0';
    linhaAtual++;
    while (escolha<0 || escolha>n){
        printf("Valor inválido. Digite um número de 0 a %d: ", n);
        scanf("%d", &escolha);
    }

    printf("---------------------------------------------------- \n");
    return escolha;
}

int menuSI(int linhaEscolha){ // Mostra o menu do SI
    int escolha;
    int n = 4;

    printf("-------------------SISTEMA INTERNO------------------ \n");
    printf("0. Acessar lista de menus; \n");
    printf("1. Cadastrar produto no SI; \n"); // SI é uma abreviação para Sistema Interno
    printf("2. Remover cadastro do SI; \n");
    printf("3. Editar cadastro do SI; \n");
    printf("4. Listar todos os cadastros do SI; \n");
    printf("Digite um número de 0 a %d para escolher uma opção: ", n);
    escolha = lerLinha(linhaEscolha)[0] - '0';
    linhaAtual++;

    while (escolha<0 || escolha>n){
        printf("Valor inválido. Digite um número de 0 a %d: ", n);
        scanf("%d", &escolha);
    }

    printf("----------------------------------------------------- \n");
    return escolha;
}

void addCadastro(int linhaEscolha){ // Cadastra um produto no sistema
    std::string nome;
    double preco;

    std::cout << "Digite o nome do novo produto: ";
    nome = lerLinha(linhaEscolha);
    linhaAtual++;
    if (nome.empty()) {
        printf("Nome inválido. Processo cancelado.\n");
        system("pause");
        return;
    }

    std::cout << "Digite o preço para o novo produto: ";
    std::string precoStr = lerLinha(linhaEscolha+1);
    linhaAtual++;
    try {
        preco = stringParaDouble(precoStr);
    } catch (const std::invalid_argument&) {
        printf("Preço inválido. Processo cancelado.\n");
        system("pause");
        return;
    } catch (const std::out_of_range&) {
        printf("Preço fora do intervalo permitido. Processo cancelado.\n");
        system("pause");
        return;
    }

    si.id.push_back(acharMaior(si.id)+1);
    si.nome.push_back(nome);
    si.preco.push_back(preco);

    printf("Produto cadastrado com sucesso! \n");
    system("pause");
}

void rmvCadastro(int linhaEscolha){ // Remove um cadastro do sistema
    int id, esc;

    printf("Digite o ID do produto que deseja remover: ");
    id = lerLinha(linhaEscolha)[0] - '0';
    linhaAtual++;
    while (id>=si.id.size() || id<0){
        printf("ID inválido. Digite um ID existente: ");
        scanf("%d", &id);
    }

    std::cout << si.nome[id] << ", R$" << si.preco[id] << ". \n";
    printf("É esse o produto que deseja remover? Digite 1 para sim: ");
    esc = lerLinha(linhaEscolha+1)[0] - '0';
    linhaAtual++;

    if (esc==1){
        si.id.erase(si.id.begin() + id);
        si.nome.erase(si.nome.begin() + id);
        si.preco.erase(si.preco.begin() + id);
        for (int i=id; i<si.id.size(); i++){
            si.id[i]--;
        }
        printf("Produto removido com sucesso!\n");
        system("pause");
    } else {
        printf("Processo Cancelado. \n");
        system("pause");
    }
}

void attCadastro(int linhaEscolha){ // Edita um produto do sistema
    int id, esc;

    printf("Digite o ID do produto que deseja atualizar: ");
    id = lerLinha(linhaEscolha)[0] - '0';
    linhaAtual++;
    while (id>=si.id.size() || id<0){
        printf("ID inválido. Digite um ID existente: ");
        scanf("%d", &id);
    }

    std::cout << si.nome[id] << ", R$" << si.preco[id] << ". \n";
    printf("É esse o produto que deseja atualizar? Digite 1 para sim: ");
    esc = lerLinha(linhaEscolha+1)[0] - '0';
    linhaAtual++;
    
    if (esc==1){
        std::string novoNome;
        double novoPreco;
        
        std::cout << "Digite o nome do novo produto: ";
        novoNome = lerLinha(linhaEscolha+2);
        linhaAtual++;
        if (novoNome.empty()) {
            printf("Nome inválido. Processo cancelado.\n");
            system("pause");
            return;
        }
        std::cout << "Digite o preço para o novo produto: ";
        novoPreco = stringParaDouble(lerLinha(linhaEscolha+3));
        linhaAtual++;

        si.nome[id] = novoNome;
        si.preco[id] = novoPreco;
        printf("Dados atualizados!\n");
        system("pause");
    } else {
        printf("Processo cancelado. \n");
        system("pause");
    }
}

void listarCadastros(){ // Lista todos os produtos cadastrados no sistema
    for (int i=0; i<si.id.size(); i++){
        std::cout << "Produto " << si.id[i] << ": " << si.nome[i] << ", R$";
        printf("%.2lf \n", si.preco[i]);
    }
    system("pause");
}

void addProduCarrinho(int linhaEscolha){ // Adiciona um produto ao carrinho
    int id;
    int quanti;

    printf("Digite o ID do produto que deseja adicionar ao carrinho: ");
    id = lerLinha(linhaEscolha)[0] - '0';
    linhaAtual++;

    if (id < 0 || id >= si.id.size()) {
        printf("ID inválido.\n");
        return;
    }

    printf("Digite a quantidade desejada: ");
    quanti = lerLinha(linhaEscolha+1)[0] - '0';
    linhaAtual++;

    if (quanti <= 0) {
        printf("Quantidade inválida.\n");
        return;
    }
    
    for (int i = 0; i < carrinho.id.size(); i++) {
        if (carrinho.id[i] == id) {
            carrinho.quanti[i] += quanti;
            printf("Quantidade atualizada no carrinho.\n");
            return;
        }
    }

    carrinho.id.push_back(id);
    carrinho.nome.push_back(si.nome[id]);
    carrinho.preco.push_back(si.preco[id]);
    carrinho.quanti.push_back(quanti);

    printf("Produto adicionado ao carrinho!\n");
}

void rmvProduCarrinho(int linhaEscolha){ // Remove um produto do carrinho
    int id;
    printf("Digite o ID do produto que deseja remover do carrinho: ");
    id = lerLinha(linhaEscolha)[0] - '0';
    linhaAtual++;

    for (int i = 0; i < carrinho.id.size(); i++) {
        if (carrinho.id[i] == id) {
            carrinho.id.erase(carrinho.id.begin() + i);
            carrinho.nome.erase(carrinho.nome.begin() + i);
            carrinho.preco.erase(carrinho.preco.begin() + i);
            carrinho.quanti.erase(carrinho.quanti.begin() + i);
            printf("Produto removido do carrinho.\n");
            return;
        }
    }
    printf("Produto não encontrado no carrinho.\n");
}

void attProduCarrinho(int linhaEscolha){ // Atualiza a quantia de um dos produtos do carrinho
    int id;
    int novaQuantidade;
    printf("Digite o ID do produto no carrinho que deseja atualizar: ");
    id = lerLinha(linhaEscolha)[0] - '0';
    linhaAtual++;

    for (int i = 0; i < carrinho.id.size(); i++) {
        if (carrinho.id[i] == id) {
            printf("Digite a nova quantidade: ");
            novaQuantidade = lerLinha(linhaEscolha+1)[0] - '0';
            linhaAtual++;

            if (novaQuantidade <= 0) {
                printf("Quantidade inválida.\n");
                return;
            }

            carrinho.quanti[i] = novaQuantidade;
            printf("Quantidade atualizada!\n");
            return;
        }
    }
    printf("Produto não encontrado no carrinho.\n");
}

void listarCarrinho(){ // Lista todos os produtos do carrinho
    if (carrinho.id.empty()) {
        printf("Carrinho vazio.\n");
        return;
    }

    double total = 0.0;
    printf("Produtos no carrinho:\n");
    for (int i = 0; i < carrinho.id.size(); i++) {
        std::cout << "Produto: " << carrinho.nome[i] 
                  << " | Preço: R$" << carrinho.preco[i] 
                  << " | Quantidade: " << carrinho.quanti[i]
                  << " | Subtotal: R$" << carrinho.preco[i] * carrinho.quanti[i] << "\n";
        total += carrinho.preco[i] * carrinho.quanti[i];
    }
    printf("Total: R$%.2lf\n", total);
}

void limparCompras(){ // Finaliza as compras, esvazia o carrinho e retorna o usuário para a lista de menus
    if (carrinho.id.empty()) {
        printf("Carrinho já está vazio.\n");
        return;
    }

    listarCarrinho();

    printf("Finalizando compras...\n");
    carrinho.id.clear();
    carrinho.nome.clear();
    carrinho.preco.clear();
    carrinho.quanti.clear();

    printf("Compra finalizada e carrinho esvaziado.\n");
}

int main() {
    setlocale(LC_ALL, "");
    int escolha;
    while (true){
        escolha = listaMenus(linhaAtual);
        if (escolha==1){ // Menu do carrinho
            while (true){
                escolha = menuCarrinho(linhaAtual);
                if (escolha==0){
                    break;
                } else if (escolha==1){ 
                    addProduCarrinho(linhaAtual);
                } else if (escolha==2){
                    rmvProduCarrinho(linhaAtual);
                } else if (escolha==3){
                    attProduCarrinho(linhaAtual);
                } else if (escolha==4){
                    listarCarrinho();
                } else if (escolha==5){
                    limparCompras();
                }
            }
        }

        
        if (escolha==2){ // Menu do SI
            while (true){
                escolha = menuSI(linhaAtual);
                if (escolha==0){
                    break;
                } else if (escolha==1){
                    addCadastro(linhaAtual);
                } else if (escolha==2){
                    rmvCadastro(linhaAtual);
                } else if (escolha==3){
                    attCadastro(linhaAtual);
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
