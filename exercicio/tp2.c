/*--------------------------------------------------*/
/*####          PROGRAMAÇÃO EM C	       	    ####*/
/*--------------------------------------------------*/
/*$$$$ APLICACAO							    $$$$*/
/*$$$$ nome : Grupo 1.c				    	$$$$*/ 
/*--------------------------------------------------*/
/*@@@@ DIRECTIVAS DE INCLUSÃO         		    @@@@*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

/*@@@@ DIRECTIVAS DE DEFINÇÃO         			@@@@*/

/*@@@@ VARIÁVEIS GLOBAIS	         			@@@@*/

/*@@@@ DEFINIÇÃO DE TIPOS AGREGADOS		       	@@@@*/

/*@@@@ FUNÇÕES E PROCEDIMENTOS        			@@@@*/
#define N 15

typedef struct orcamento{   // Estrutura para orçamentos
	int numeroOrcamentos;
	char nomeFornecedor[30];
	char descricao[30];
	float valorOrcamento;
	int tipoEstado; // 1=por analisar ; 2=Em análise ; 3=Analisado
	int resultado; // 1 -Aprovado; 2 - Reprovado
	int userType;
}ORCAMENTO;

typedef struct utilizador{ // Estrutura para utilizadores
	char nomeUtilizador[15];
	char sobrenomeUtilizador[15];
	int numeroUtilizador;
	char password[7];
	int tipoUtilizador; // 1 - Admin; 2 - Decisor
}UTILIZADOR;


int menu();
void inserirOrcamentos(ORCAMENTO orcamento [], int *quantidadeOrcamentos, ORCAMENTO *apontador);
void alterarOrcamentos(int procuraNumero, int quantidadeOrcamentos, ORCAMENTO orcamento[], ORCAMENTO *apontador);
void listarOrcamentos(int quantidadeOrcamentos, ORCAMENTO orcamento[],ORCAMENTO *apontador);
void listarOrcamentosAcima(ORCAMENTO orcamento[], int quantidadeOrcamentos, ORCAMENTO *apontador);
void listarFornecedor(ORCAMENTO orcamento[], int quantidadeOrcamentos, ORCAMENTO *apontador);
void listarOrcamentosAnalisadosAprovados(int quantidadeOrcamentos, ORCAMENTO orcamento[]);
void inserirUtilizador(UTILIZADOR utilizador [], int *quantidadeUtilizadores, UTILIZADOR *apontador);
void listarUtilizador(int quantidadeUtilizadores, UTILIZADOR utilizador[],UTILIZADOR *apontador);
void sair (char menuGuardar, int quantidadeOrcamentos, ORCAMENTO orcamento[], ORCAMENTO *apontador, UTILIZADOR utilizador[], int quantidadeUtilizadores);
void gravarOrcamentos (ORCAMENTO orcamento [], int quantidadeOrcamentos, ORCAMENTO *apontador);
int lerOrcamentos(ORCAMENTO orcamento[], ORCAMENTO *apontador);
void gravarUtilizadores(UTILIZADOR utilizador [], int quantidadeUtilizadores, UTILIZADOR *apontador);
int lerUtilizadores(UTILIZADOR utilizador[], UTILIZADOR *apontador);

int main(void) {
    
    setlocale(LC_ALL, "Portuguese");
    system("COLOR FC");
    
    // DECLARAÇÃO DE VARIÁVEIS E DE CONSTANTES
    
    ORCAMENTO orcamento[N];
    UTILIZADOR utilizador[N];
    ORCAMENTO apontador;

	    
    int escolha, menuGuardar, procuraNumero;
    int i;
    int quantidadeOrcamentos = 0;
	int quantidadeUtilizadores = 0;
  
    ////quantidadeOrcamentos = lerOrcamentos(orcamento);       ANALISAR
    //int nOrcamentos[N]; //numero do orcamento
    //char descricao[N][30]; // descricao do orcamento
    //char fornecedor[N][30];
    //float valor[N]; //valor do orcamento
    //int estado[N];

    char procuraFornecedor[15]; //nome do fornecedor a procurar (case6)
    do {
		escolha = menu();;
	
    switch (escolha)
    {
	
	case 1: //inserir as instruções para inserir o orçamento
	    if (quantidadeOrcamentos<N){
		    inserirOrcamentos(orcamento, &quantidadeOrcamentos, &apontador);
	    } else {
		    printf("\nNão é possivel inserir mais orçamentos\n");
	    }
		break;

	case 2: //inserir as instruções para alterar o orçamento
	
	alterarOrcamentos(procuraNumero,quantidadeOrcamentos, orcamento, &apontador);
	
		break;
	
	case 3:  //inserir as instruções para listar o orçamento
	if(quantidadeOrcamentos != 0) {
		listarOrcamentos(quantidadeOrcamentos, orcamento, &apontador);
	}	else {
		printf("\n\nNao Eeistem orcamentos para procurar!!\n\n");
	}
		break;
		
	case 4:  //inserir as instruções para listar o orçamento acima de um dado valor
	
	listarOrcamentosAcima(orcamento, quantidadeOrcamentos, &apontador);
		
		break;
		
	case 5:  // Lista todos os dados do orcamento do fornecedor pretendido
		if(quantidadeOrcamentos!=0){
			listarFornecedor(orcamento,quantidadeOrcamentos, &apontador);
			
		} else {
			printf("Não Existem orcamentos para procurar!!\n\n");
		} break;

	case 6: // Listar orcamentos analisados e aprovados
		if(quantidadeOrcamentos != 0){
			listarOrcamentosAnalisadosAprovados(quantidadeOrcamentos, orcamento);
		}
		break;

	case 7:
		if (quantidadeUtilizadores<N){
		    inserirUtilizador(utilizador, &quantidadeUtilizadores, &apontador);
	    } else {
		    printf("\nNão é possivel inserir mais utilizadores\n");
	    }
		break;

	case 8:
		if(quantidadeUtilizadores != 0) {
			listarUtilizador(quantidadeUtilizadores, utilizador, &apontador);
		}else {
			printf("\n\nNao existem utilizadores para procurar!!\n\n");
		}
		break;

	case 9:
		quantidadeOrcamentos = lerOrcamentos(orcamento,&apontador); 
		break;

	case 10:
		quantidadeUtilizadores = lerUtilizadores(utilizador,&apontador);
		break;

	case 0: //inserir as instruções para sair e guardar
		sair(menuGuardar, quantidadeOrcamentos, orcamento, &apontador, quantidadeUtilizadores, utilizador);
	break;
	
	default: printf ("\n operacao invalida!! \n");
    break;
    
        }
    } while (escolha !=0);
    return 0;
}

int menu() {
	int i;

    printf("\t\t ________________________________________________\n");
	printf("\t\t|------------------------------------------------|\n");
	printf("\t\t|      	Gestao de Orcamentos                     |\n");
	printf("\t\t|------------------------------------------------|\n");
	printf("\t\t|             ADMINISTRADOR                      |\n");
	printf("\t\t| 1  - Inserir orcamentos                        |\n");
	printf("\t\t| 2  - Alterar orcamentos                        |\n");
	printf("\t\t| 3  - Listar  orcamentos                        |\n");
	printf("\t\t| 4  - Listar orcamento acima de um valor        |\n");
	printf("\t\t| 5  - Procurar orcamentos por fornecedor        |\n");
	printf("\t\t| 6  - Listar orcamentos analisados e aprovados  |\n");
	printf("\t\t| 7  - Registar Utilizador                       |\n");
	printf("\t\t| 8  - Listar Utilizador                         |\n");
	printf("\t\t| 9  - Importar Orcamentos                       |\n");
	printf("\t\t| 10  - Importar Utilizadores                    |\n");
	printf("\t\t|------------------------------------------------|\n");
	printf("\t\t| 0  - Fechar Programa e Guardar Ficheiro        |\n");
	printf("\t\t|________________________________________________|\n");
    printf("\n\t\tIntroduza uma das opcoes: ");

	do{
		fflush(stdin);
		scanf("%d",&i);
	}while(i<0 && i>10);
	return i;
}


void inserirOrcamentos(ORCAMENTO orcamento [], int *quantidadeOrcamentos, ORCAMENTO *apontador){                            // função para inserir orçamentos quando a opção 1 do menu é selecionada

int type;
	    orcamento[*quantidadeOrcamentos].numeroOrcamentos = *quantidadeOrcamentos + 1 ;
	    printf("\n Nome do fornecedor do Orçamento: ");
	    fflush(stdin);
		scanf("%[^\n]s", orcamento[*quantidadeOrcamentos].nomeFornecedor);
		printf("\n Descricao do orçamento: ");
	    fflush(stdin);
		scanf("%[^\n]s", orcamento[*quantidadeOrcamentos].descricao);
		printf("\n Valor do orçamento: ");
		scanf("%f", &(orcamento[*quantidadeOrcamentos].valorOrcamento));
		do{
		printf("\n Orcamento  criado por: : << 1 - Admin >> << 2 - Decisor >>: ");
		scanf("%d", &type);
		}while (type != 1 && type != 2);
		switch (type) {
			case 1:{   // criado por admin
				((apontador->userType)=1);
				break;
			}
			case 2:{ // criado por decisor
				((apontador->userType)=2);
		}
				break;
		}
		(apontador->tipoEstado)=1;
		
		*quantidadeOrcamentos=*quantidadeOrcamentos+1;
	
}

void alterarOrcamentos(int procuraNumero, int quantidadeOrcamentos, ORCAMENTO orcamento[], ORCAMENTO *apontador){              // função para listar orçamentos quando a opção 2 do menu é selecionada
int i;
int menuEstado;
int aprovacao;

	printf("\nQual o número do orçamento a alterar: \n");
		scanf("%d",&procuraNumero);
		//procurar se existe
		for(i=0; i < quantidadeOrcamentos; i++){
			if(orcamento[i].numeroOrcamentos == procuraNumero) break;
		}
		//se existir-->mostrar e ler novos dados
		//se nao existir, mostrar mensagem que nao existe
		if(i<quantidadeOrcamentos){
		printf("\n Nome do fornecedor do Orçamento: ");
		fflush(stdin);
		scanf("%[^\n]s", orcamento[i].nomeFornecedor);
		printf("\n Descrição do orçamento: ");
		fflush(stdin);
		scanf("%[^\n]s", orcamento[i].descricao);
		printf("\n Valor do orçamento: ");
		scanf("%f", &(orcamento[i].valorOrcamento));
		do{
		printf("\n Estado do Orçamento: << 1 - Para Analisar >> << 2 - Em análise >> << 3 - Analisado >> : ");
		scanf("%d", &menuEstado);
		}while (menuEstado != 1 && menuEstado != 2 && menuEstado != 3);
		switch (menuEstado) {
			case 1:{   // coloca o estado para analisar
				((apontador->tipoEstado)=1);
				break;
			}
			case 2:{ // colocar o estado em analise
			((apontador->tipoEstado)=2);
		}
				break;
			case 3:{ // chamar a função de estado analisado
			((apontador->tipoEstado)=3);
				break;
			}
		}
		if(apontador->userType != 1){
			do{
				printf("\n Estado do Orçamento: << 1 - Aprovado >> << 2 - Reprovado >>: ");
				scanf("%d", &aprovacao);
			}while (aprovacao != 1 && aprovacao != 2);
			switch (aprovacao) {
				case 1:{   // coloca o estado para Aprovar
					((apontador->resultado)=1);
					break;
				}
				case 2:{ // colocar o estado em Reprovado
					((apontador->resultado)=2);
				}
					break;
				}
		} else {
			printf("\n Operacao apenas para utilizadores do tipo Decisor! Um Abraço! Fica Bem! ");
		}
	} else {
	printf("\nO orçamento número %d NÃO EXISTE!!!", procuraNumero);
	}
}

void listarOrcamentos(int quantidadeOrcamentos, ORCAMENTO orcamento[],ORCAMENTO *apontador){                                
	// função para listar orçamentos quando a opção 3 do menu é selecionada
	int i;
	
	
for (i=0; i<quantidadeOrcamentos ; i++){
			printf("\n------------------------------------\n");
			printf ("\nNúmero do orçamento: %d \n", orcamento[i].numeroOrcamentos);
			printf ("\nNome do fornecedor do Orçamento: %s \n", orcamento[i].nomeFornecedor);
			printf ("\nDescrição: %s \n",orcamento[i].descricao);
			printf ("\nValor: %f \n", orcamento[i].valorOrcamento);
			if((apontador->tipoEstado)==1){
				printf("\nEstado: Por Analisar\n");
			}
			if((apontador->tipoEstado)==2){
				printf("\nEstado: Em Análise\n");
			}
			if((apontador->tipoEstado)==3){
				printf("\nEstado: Analisado\n");
			}
			}
			if((apontador->resultado) == 1){
				printf("\nResultado: Aprovado");
			}			
			if((apontador->resultado) == 2){
				printf("\nResultado: Reprovado!");
			}
			printf("\n********************************\n");
		}


void listarOrcamentosAcima(ORCAMENTO orcamento[], int quantidadeOrcamentos, ORCAMENTO *apontador){ //listar orçamentos acima de um determinado valor
	float valor;
	int i;
	
	printf("\n Insira o valor pretendido: ");
	scanf("%f", &valor);
	
	for (i=0; i<quantidadeOrcamentos ; i++){
	if (orcamento[i].valorOrcamento > valor){
		    printf ("\nNúmero do orçamento: %d \n", orcamento[i].numeroOrcamentos);
			printf ("\nNome do fornecedor do Orçamento: %s \n", orcamento[i].nomeFornecedor);
			printf ("\nDescrição: %s \n",orcamento[i].descricao);
			printf ("\nValor: %f \n", orcamento[i].valorOrcamento);
			if((apontador->tipoEstado)==1){
				printf("\nEstado: Por Analisar\n");
			}
			if((apontador->tipoEstado)==2){
				printf("\nEstado: Em Análise\n");
			}
			if((apontador->tipoEstado)==3){
				printf("\nEstado: Analisado\n");
			}
		
	} else {
		printf("\n NÂO EXISTE VALORES ACIMA DO VALOR PRETENDIDO....");
	}
}
}

void listarFornecedor(ORCAMENTO orcamento[], int quantidadeOrcamentos, ORCAMENTO *apontador){
	char procurarFornecedor[20];
	int i;
printf("\nNome do fornecedor a procurar: ");
			fflush(stdin);
			scanf("%15[^\n]s", procurarFornecedor);
			
			for(i=0;i<quantidadeOrcamentos;i++){
				if(strcmp(procurarFornecedor,orcamento[i].nomeFornecedor)==0){
					printf("\nNúmero: %d ",orcamento[i].numeroOrcamentos);
					printf("\nFornecedor: %s ",orcamento[i].nomeFornecedor);
					printf("\nDescrição: %s ",orcamento[i].descricao);
					printf("\nValor: %f ",orcamento[i].valorOrcamento);
					if((apontador->tipoEstado)==1){
				printf("\nEstado: Por Analisar\n");
			}
			if((apontador->tipoEstado)==2){
				printf("\nEstado: Em Análise\n");
			}
			if((apontador->tipoEstado)==3){
				printf("\nEstado: Analisado\n");	
			} else {
				printf("\nFORNECEDOR NÂO EXISTE....");
			}
		} 
	}
}

void listarOrcamentosAnalisadosAprovados(int quantidadeOrcamentos, ORCAMENTO orcamento[]) {     // função para listar orçamentos analisados e aprovados
	int i;	
	for (i=0; i < quantidadeOrcamentos; i++){
		if((orcamento[i].tipoEstado = 3) && (orcamento[i].resultado = 1)) {
			printf("\n********************************\n");
			printf ("\nNúmero do orçamento: %d \n", orcamento[i].numeroOrcamentos);
			printf ("\nNome do fornecedor do Orçamento: %s \n", orcamento[i].nomeFornecedor);
			printf ("\nDescrição: %s \n",orcamento[i].descricao);
			printf ("\nValor: %f \n", orcamento[i].valorOrcamento);
			printf ("\nEstado: %s \n", orcamento[i].tipoEstado);
			printf("\n********************************\n");
		} else {
			printf("\nNão existem orçamentos analisados e aprovados");
		}	
	}
}

void inserirUtilizador(UTILIZADOR utilizador [], int *quantidadeUtilizadores, UTILIZADOR *apontador){                            
	// função para inserir orçamentos quando a opção 1 do menu é selecionada

	int tipo;

	    utilizador[*quantidadeUtilizadores].numeroUtilizador = *quantidadeUtilizadores + 1;
	    printf("\n Nome do Utilizador: ");
	    fflush(stdin);
		scanf("%[^\n]s", utilizador[*quantidadeUtilizadores].nomeUtilizador);
		printf("\n Sobrenome do utilizador: ");
	    fflush(stdin);
		scanf("%[^\n]s", utilizador[*quantidadeUtilizadores].sobrenomeUtilizador);
		printf("\n Password do utilizador: ");
		scanf("%s", utilizador[*quantidadeUtilizadores].password);
		do{
		printf("\n Tipo de Utilizador: << 1 - Admin >> << 2 - Decisor >>: ");
		scanf("%d", &tipo);
		}while (tipo != 1 && tipo != 2);
		switch (tipo) {
			case 1:{   // coloca o estado para analisar
				((apontador->tipoUtilizador)=1);
				break;
			}
			case 2:{ // colocar o estado em analise
			((apontador->tipoUtilizador)=2);
		}
				break;
		}
		
		*quantidadeUtilizadores=*quantidadeUtilizadores+1;
	
}

void listarUtilizador(int quantidadeUtilizadores, UTILIZADOR utilizador[],UTILIZADOR *apontador){                                // função para listar orçamentos quando a opção 3 do menu é selecionada
	int i;
	
	
	for (i=0; i<quantidadeUtilizadores ; i++){
			printf("\n------------------------------------\n");
			printf ("\n Número do Utilizador: %d \n", utilizador[i].numeroUtilizador);
			printf ("\n Nome do Utilizador: %s \n", utilizador[i].nomeUtilizador);
			printf ("\n Sobrenome do utilizador: %s \n", utilizador[i].sobrenomeUtilizador);
			if((apontador->tipoUtilizador)==1){
				printf("\n Tipo Utilizaor: Admin\n");
			}
			if((apontador->tipoUtilizador)==2){
				printf("\n Tipo Utilizador: Decisor\n");
			}
		printf("\n********************************\n");
	}
}

int lerOrcamentos(ORCAMENTO orcamento[], ORCAMENTO *apontador ){  
	//tem como função importar os dados inseridos
	int nOrcamentosLidos = 0;
	int i;
	char importarFicheiro[50];
	
	printf ("\nIndique o nome do ficheiro que pretende importar: \n");
	scanf ("\n %s: \n", importarFicheiro);
	strcat(importarFicheiro,".dat");
	FILE* apFicheiro = fopen(importarFicheiro,"rb");
	
	
	if (apFicheiro != NULL){
		fscanf(apFicheiro,"%i", &nOrcamentosLidos);
		fgetc(apFicheiro);
	i = 0;
		while(fscanf(apFicheiro,"%i",&(orcamento[i].numeroOrcamentos) )!= EOF){
		fgetc(apFicheiro);
		fscanf(apFicheiro,"%[^\n]s",orcamento[i].nomeFornecedor);
		fgetc(apFicheiro);	
		fscanf(apFicheiro,"%[^\n]s",orcamento[i].descricao) ;
		fgetc(apFicheiro);	
		fscanf(apFicheiro,"%f",&(orcamento[i].valorOrcamento));
		fgetc(apFicheiro);	
		fscanf(apFicheiro,"%d",&(orcamento[i].tipoEstado)); 
		fgetc(apFicheiro);	
		
		i++;
		}
		fclose(apFicheiro);
	}else {
		printf("NÃO EXISTE NENHUM FICHEIRO DE ORÇAMENTOS");
		system ("Pause");
	}
	return i;
}

void sair (char menuGuardar, int quantidadeOrcamentos, ORCAMENTO orcamento[], ORCAMENTO *apontador, UTILIZADOR utilizador[], int quantidadeUtilizadores){   								
	//Função para sair e guarda o documento

do{
		printf ("\nPretende guardar os dados inseridos?  -> 1 = Sim <-  -> 0 = Não <- ");
		fflush(stdin);
		scanf("%d", &menuGuardar);
		}while (menuGuardar != 0 && menuGuardar != 1);

		if (menuGuardar == 1) {
			if(quantidadeOrcamentos != 0){
				gravarOrcamentos (orcamento, quantidadeOrcamentos, &apontador);
				gravarUtilizadores(utilizador, quantidadeUtilizadores, &apontador);
				printf("\nFicheiro guardado com sucesso! Adeus e bom trabalho");
			} else {
				printf("\n Nao existem dados para guardar!");
			}
			// if(quantidadeUtilizadores != 0) {
			// 	gravarUtilizadores(utilizador, quantidadeUtilizadores, &apontador);
			// 	printf("\nFicheiro guardado com sucesso! Adeus e bom trabalho");
			// }else{
			// 	printf("\n Nao existem utilizadores para guardar!");
			// }
		}else {
		
		printf("\nFicheiro não guardado! Um abraço!");
	}
}

void gravarOrcamentos (ORCAMENTO orcamento [], int quantidadeOrcamentos, ORCAMENTO *apontador){ 								
	//tem como função atribuir um nome a um ficheiro e exportar os dados inseridos
	char nomeFicheiro[50];

	printf("Introduza o nome do ficheiro: ");
	scanf("%s",nomeFicheiro);
	strcat(nomeFicheiro,".dat");
	FILE *apFicheiro = fopen(nomeFicheiro,"wb");
	
	int i;

	for(i = 0; i <quantidadeOrcamentos; i++){
	
		fprintf(apFicheiro, "%d\n", orcamento[i].numeroOrcamentos);
		fprintf(apFicheiro, "%s\n", orcamento[i].nomeFornecedor);
		fprintf(apFicheiro, "%s\n", orcamento[i].descricao);
		fprintf(apFicheiro, "%f\n", orcamento[i].valorOrcamento);
		if((apontador->tipoEstado)==1){
			printf("\nEstado: Por Analisar\n");
		}
		if((apontador->tipoEstado)==2){
			printf("\nEstado: Em Análise\n");
		}
		if((apontador->tipoEstado)==3){
			printf("\nEstado: Analisado\n");
		}
	}
	fclose(apFicheiro);
}

void gravarUtilizadores (UTILIZADOR utilizador [], int quantidadeUtilizadores, UTILIZADOR *apontador){ 								
	//tem como função atribuir um nome a um ficheiro e exportar os dados inseridos
	char nomeFicheiro[50];

	printf("Introduza o nome do ficheiro: ");
	scanf("%s",nomeFicheiro);
	strcat(nomeFicheiro,".dat");
	FILE *apFicheiro = fopen(nomeFicheiro,"wb");
	
	int i;

	for(i = 0; i <quantidadeUtilizadores; i++){
	
		fprintf(apFicheiro, "%d\n", utilizador[i].numeroUtilizador);
		fprintf(apFicheiro, "%s\n", utilizador[i].nomeUtilizador);
		fprintf(apFicheiro, "%s\n", utilizador[i].sobrenomeUtilizador);
		if((apontador->tipoUtilizador)==1){
			printf("\nTipo: Admin\n");
		}
		if((apontador->tipoUtilizador)==2){
			printf("\nTipo: Decisor\n");
		}
	}
	fclose(apFicheiro);
}

int lerUtilizadores(UTILIZADOR utilizador[], UTILIZADOR *apontador ){  
	//tem como função importar os dados inseridos
	int nUtilizadoresLidos = 0;
	int i;
	char importarFicheiro[50];
	
	printf ("\nIndique o nome do ficheiro que pretende importar: \n");
	scanf ("\n %s: \n", importarFicheiro);
	strcat(importarFicheiro,".dat");
	FILE* apFicheiro = fopen(importarFicheiro,"rb");
	
	
	if (apFicheiro != NULL){
		fscanf(apFicheiro,"%i", &nUtilizadoresLidos);
		fgetc(apFicheiro);
	i = 0;
		while(fscanf(apFicheiro,"%i",&(utilizador[i].numeroUtilizador) )!= EOF){
		fgetc(apFicheiro);
		fscanf(apFicheiro,"%[^\n]s",utilizador[i].nomeUtilizador);
		fgetc(apFicheiro);	
		fscanf(apFicheiro,"%[^\n]s",utilizador[i].sobrenomeUtilizador) ;
		fgetc(apFicheiro);	
		fscanf(apFicheiro,"%d",&(utilizador[i].tipoUtilizador)); 
		fgetc(apFicheiro);	
		
		i++;
		}
		fclose(apFicheiro);
	}else {
		printf("NÃO EXISTE NENHUM FICHEIRO DE UTILIZADORES");
		system ("Pause");
	}
	return i;
}
