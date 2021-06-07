#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//------------------------ DEFINES -------------------------

#define lim 100

//------------------ TYPEDEF STRUCT ------------------------

typedef struct orcamento {
    char nome[lim];
    int numero;
    char descricao[lim];
    float valor_orcamento;
	char *estado[3];
} orcamento;

typedef struct user {
	char username[lim];
	char name[lim];
	char password[5];
	char *type[2];
}user;

//-------------------DECLARAÇÕES DAS FUNÇÕES ORCAMENTOS ------------------------

//função para o menu
int menu();

//função para adicionar
orcamento addOrc();

//funções para listar os dados dos orcamentos
int lista_orcamentos(orcamento Orc[], int total_orcamentos);
void printOrcamentos (orcamento listOrc);

//função para remover o orcamento da lista(não esta a funcionar)
void remove_orcamento(orcamento Orc[], int total_orcamentos);

//função para procurar pelo nome de um orcamento na lista(não está a funcionar)
int procurar_orcamento(char listOrc[], orcamento removeOrcamentoList[], int total_orcamentos);

//função para comparar strings, quando estiver a procurar pelo nome do orcamento
//faz a distinção entre maiusculas e minusculas
int compare_strings( char firstString[], char secondString[]);

//---------------UTILIZADORES---------------------------------
//funçao para adicionar utilizadores
user addUser();
int lista_utilizadores(user Users[], int total_utilizadores);
void printUtilizadores(user listUsers);
void remove_user(user Users[], int total_utilizadores);
int procurar_user(char listUsers[], user removeUserList[], int total_utilizadores);

//------------------------ MAIN -------------------------------
//inicio da função main (função cerebro do código)
int main() {
    int opcao_menu, garbage;
    char orc[lim];
	char utilizador[lim];
	//definimos que a lista começa com 0 elementos, para depois adicionar
    int total_orcamentos = 0;
	int total_utilizadores = 0;

    	do {
		printf("\n\n");
		opcao_menu = menu(); // escolher uma opção do menu

		switch (opcao_menu)
		{
		case 1:
			printf("\n\t\t|-------------------------------|\n");
			printf("\t\t|      ADICIONAR ORCAMENTO      |\n");
			printf("\t\t|-------------------------------|\n");
            orcamento Orc[lim];
            Orc[total_orcamentos] = addOrc();
            total_orcamentos++;
			break;
		
		case 2:
			lista_orcamentos(Orc,total_orcamentos);
			break;
		
		case 3:           
            printf("\n\t\t|-------------------------------|\n");
			printf("\t\t|       ALTERAR ORCAMENTO       |\n");
			printf("\t\t|-------------------------------|\n");
			break;
		
		case 4:
			remove_orcamento(Orc,total_orcamentos);
			printf("\t O orcamento selecionado foi removido com sucesso!\n\n");
			total_orcamentos--;
			break;
		
		case 5:
			printf("\n\t\t|-------------------------------|\n");
			printf("\t\t|       PROCURAR ORCAMENTO      |\n");
			printf("\t\t|-------------------------------|\n");
			printf("\n\t Insira o nome do Orcamento que pretende procurar: ");
			scanf("%s", orc);
			garbage = procurar_orcamento(orc, Orc, total_orcamentos);
			if(garbage > total_orcamentos ){
				printf("\n\t\t O nome do orcamento introduzido nao existe!\n\n");
				break;
			} else if(garbage < total_orcamentos){
				printOrcamentos(Orc[garbage]);
				break;
			}
			break;

		case 6:
			printf("\n\t\t|-----------------------------------------|\n");
			printf("\t\t|       CALCULAR MEDIA DE ORCAMENTOS      |\n");
			printf("\t\t|-----------------------------------------|\n");
			break;

		case 7:
			printf("\n\t\t|-------------------------------|\n");
			printf("\t\t|      REGISTAR UTILIZADOR      |\n");
			printf("\t\t|-------------------------------|\n");
			user Users[lim];
            Users[total_utilizadores] = addUser();
            total_utilizadores++;
			break;

		case 8:
			lista_utilizadores(Users, total_utilizadores);
			break;

		case 9:
			printf("\n\t\t|-------------------------------|\n");
			printf("\t\t|       PROCURAR UTILIZADOR      |\n");
			printf("\t\t|-------------------------------|\n");
			printf("\n\t\t Introduza o username que pretende procurar: ");
			scanf("%s",utilizador);
			garbage = procurar_user(utilizador, Users, total_utilizadores);
			if(garbage > total_utilizadores) {
				printf("\n\t\t Este username nao existe!\n\n");
				break;
			}else {
				printUtilizadores(Users[garbage]);
				break;
			}
			break;

		case 10:
			remove_user(Users, total_utilizadores);
			printf("\n\t O username selecionado foi removido com sucesso!\n\n");
			break;


		case 11:
			printf("\n\t\t|-------------------------------|\n");
			printf("\t\t|       ALTERAR UTILIZADOR      |\n");
			printf("\t\t|-------------------------------|\n");
			printf("\n\t Digite o nome do utilizador: ");
			break;

		case 0:
			printf("\n\t\tFim do programa\n\n");
			system("pause");
		  break;
		
		default:
			printf("\n\t\tOpcao invalida!!");
		}
	}while (opcao_menu!= 0);
	return 0;
}

//---------------------------FUNÇÕES-----------------------------
int menu() {
	int i;

	printf("\t\t|-------------------------------|\n");
	printf("\t\t|      Gestao de Orcamentos     |\n");
	printf("\t\t|-------------------------------|\n");
	printf("\t\t|           ORCAMENTOS          |\n");
	printf("\t\t| 1  - Adicionar orcamento      |\n");
	printf("\t\t| 2  - Listar orcamento         |\n");
	printf("\t\t| 3  - Alterar orcamentos       |\n");
	printf("\t\t| 4  - Remover orcamento        |\n");
	printf("\t\t| 5  - Procurar orcamentos      |\n");
	printf("\t\t| 6  - Calcular media orcamento |\n");
	printf("\t\t|-------------------------------|\n");
	printf("\t\t|         UTILIZADORES          |\n");
	printf("\t\t| 7  - Registar Utilizadores    |\n");
	printf("\t\t| 8  - Listar os Utilizadores   |\n");
	printf("\t\t| 9  - Procurar Utilizador      |\n");
	printf("\t\t| 10 - Remover Utilizador       |\n");
	printf("\t\t| 11 - Alterar Utilizador       |\n");
	printf("\t\t|-------------------------------|\n");
	printf("\t\t| 0  - Fechar Programa          |\n");
	printf("\t\t|_______________________________|\n");
	printf("\n\t\tIntroduza uma das opcoes: ");

	do{
		fflush(stdin);
		scanf("%d",&i);
	}while(i<0 && i>11);
	return i;
}

//----------------FUNÇÕES PARA ORCAMENTOS--------------------------
orcamento addOrc() {
    orcamento orcamentos, estado[3] = {"Para Analisar", "Em Analise", "Analisado"};
	int i;
	//char *estado[3] = {"Para Analisar", "Em Analise", "Analisado"};
    printf("\n\t\tInsira o nome do fornecedor: ");
    scanf("%s", orcamentos.nome);
    printf("\n\t\tInsira o numero do orcamento: ");
    scanf("%d", &orcamentos.numero);
    printf("\n\t\tInsira o valor total do orcamento: ");
    scanf("%f", &orcamentos.valor_orcamento);
    printf("\n\t\tInsira a descricao do orcamento: ");
    scanf("%s",orcamentos.descricao);
	printf("\n\t\tEstado do Orcamento: ");
		for (i = 1; i <= 1; i++){
			printf("%s", estado[0]);
		}
    printf("\n\n");
    return orcamentos;
}

int lista_orcamentos(orcamento Orc[], int total_orcamentos) {
    int i;
	//criamos o if para que se a lista nao tiver nenhum elemento, ele retorna ao utilizador uma mensagem de que a lista esta vazia
    if(total_orcamentos == 0) {
		printf("\n\t\t|-------------------------------|\n");
		printf("\t\t|      LISTA DOS ORCAMENTOS     |\n");
		printf("\t\t|-------------------------------|\n");
	    printf("\n\t\t Lista de orcamentos inexistente!\n\n");
	    system("pause");
	return total_orcamentos;
	}

	/*aqui foi criado um ciclo for para que, ao escolher a opção de listar os orcamentos o programa
	mostre todos os dados dos varios orcamentos criados */
    printf("\n\t\t|-------------------------------|\n");
	printf("\t\t|      LISTA DOS ORCAMENTOS     |\n");
	printf("\t\t|-------------------------------|\n");
    for(i=0; i<total_orcamentos; i++){
        //este primeiro printf vai ser o id do orcamento
        printf("\n\t\t Id: %d",i);
        printOrcamentos(Orc[i]);
        printf("\n");
    }
}

/* esta função simplesmente é um print formatado dos dados de cada orcamento
 ou seja, no ciclo for em cima, esta função print vai ser utilizado por cada orcamentos que exista na lista*/
void printOrcamentos(orcamento listOrc) {
	printf("\n\t\t NOME: %s",listOrc.nome);
	printf("\n\t\t NUMERO: %d",listOrc.numero);
	printf("\n\t\t VALOR: %.2f",listOrc.valor_orcamento);
	printf("\n\t\t DESCRICAO: %s",listOrc.descricao);
}


void remove_orcamento(orcamento Orc[], int total_orcamentos) {
	orcamento removeOrcamentoList[lim];
	char listOrc[lim];
	int nome_orcamento, i;
	printf("\n\t Introduza o nome do orcamento que pretende eliminar: ");
	scanf("%s",listOrc);
	nome_orcamento = procurar_orcamento(listOrc, Orc, total_orcamentos);
	for(i = 0; i < nome_orcamento; i++){
		removeOrcamentoList[i] = Orc[i];
	}
	for(i = nome_orcamento + 1; i <= total_orcamentos; i++){
		removeOrcamentoList[i-1] = Orc[i];
	}
	for(i = 0; i < total_orcamentos - 1; i++){
		Orc[i] = removeOrcamentoList[i];
	}
}

int procurar_orcamento(char listOrc[], orcamento removeOrcamentoList2[], int total_orcamentos){
	int nome_orcamento = total_orcamentos + 1, i;
	/* Este ciclo for, o que vai fazer é, percorrer cada nome dos orcamentos na lista
	e para isso vai utilizar a função de comparar as strings*/
	for(i = 0; i <= total_orcamentos; i++){
		if(compare_strings(listOrc, removeOrcamentoList2[i].nome) == 0){
			nome_orcamento = i;
			break;
		}
	}
	return nome_orcamento;
}

/*esta funçao simplesmente compara a string introduzida pelo utilizador 
com a string existente na lista e se forem iguais ela retorna verdadeiro se forem iguais e existirem ou retorna falso se não existir*/
int compare_strings(char firstString [], char secondString []){
	int thirdString = 0;
	while (firstString[thirdString] == secondString[thirdString] )
	{
		if(firstString[thirdString] == '\0' || secondString[thirdString] == '\0'){
			break;
			thirdString++;
		}
	}
	if(firstString[thirdString] == '\0' && secondString[thirdString] == '\0'){
		return 0;
	} else {
		return -1;
	}
	
}

// ----------- FUNÇOES PARA OS UTILIZADORES ----------------

user addUser() {
    user Users, type[2] = {"Admin","Decisor"};
	int i;
    printf("\n\t\t Insira o nome de utilizador: ");
    scanf("%s", Users.username);
	printf("\n\t\t Insira o seu nome: ");
	scanf("%s",Users.name);
    printf("\n\t\t Insira a password (obrigatorio 6 caracteres): ");
	//este ciclo for é para se quiseres, na password em vez de aparecer as letras aparecer isto *
	for(i = 0; i < 6; i++){
		Users.password[i] = getch();
		putchar('*');
	}
	scanf("%s", Users.password);
	/*
	NOTA: Depois de introduzir a password é necessario
	carregar na caracter 0 para sair do ciclo for
	*/
	printf("\n\t\t Insira o tipo de Utilizador (A = Admin) ou (D = Decisor): ");
		//este ciclo for basicamente vai estar sempre a criar utilizadores do tipo admin
		for (i = 1; i<= 1; i++){
			printf("%s", type[0]);
		}
    printf("\n\n");
    return Users;
}

int lista_utilizadores(user Users[], int total_utilizadores){
	int i;
	//criamos o if para que se a lista nao tiver nenhum elemento, ele retorna ao utilizador uma mensagem de que a lista esta vazia
    if(total_utilizadores == 0) {
		printf("\n\t\t|---------------------------------|\n");
		printf("\t\t|       LISTA DOS UTILIZADORES     |\n");
		printf("\t\t|----------------------------------|\n");
	    printf("\n\t\t Lista de utilizadores inexistente!\n\n");
	    system("pause");
	return total_utilizadores;
	}

	/*aqui foi criado um ciclo for para que, ao escolher a opção de listar os orcamentos o programa
	mostre todos os dados dos varios orcamentos criados */
    printf("\n\t\t|---------------------------------|\n");
	printf("\t\t|       LISTA DOS UTILIZADORES     |\n");
	printf("\t\t|----------------------------------|\n");
    for(i=0; i< total_utilizadores; i++){
        //este primeiro printf vai ser o id do orcamento
        printf("\n\t\t Id: %d",i);
        printUtilizadores(Users[i]);
        printf("\n");
    }
}

void printUtilizadores(user listUsers){
	printf("\n\t\t USERNAME: %s",listUsers.username);
	printf("\n\t\t NOME: %s",listUsers.name);
}

void remove_user(user Users[], int total_utilizadores) {
	user removeUserList[lim];
	char listUsers[lim];
	int nome_user, i;

	printf("\n\t Introduza o username que pretende eliminar: ");
	scanf("%s",listUsers);
	nome_user = procurar_user(listUsers, Users, total_utilizadores);
	for(i = 0; i < nome_user; i++){
		removeUserList[i] = Users[i];
	}
	for(i = nome_user + 1; i <= total_utilizadores; i++){
		removeUserList[i-1] = Users[i];
	}
	for(i = 0; i < total_utilizadores - 1; i++){
		Users[i] = removeUserList[i];
	}
}

int procurar_user(char listUsers[], user removeUserList2[], int total_utilizadores){
	int nome_utilizadores = total_utilizadores + 1, i;
	for(i = 0; i <= total_utilizadores; i++){
		if(compare_strings(listUsers, removeUserList2[i].username) == 0){
			nome_utilizadores = i;
			break;
		}
	}
	return nome_utilizadores;
}

