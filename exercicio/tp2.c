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
}ORCAMENTO;

typedef struct utilizador{ // Estrutura para utilizadores
	char nomeUtilizador[15];
	char sobrenomeUtilizador[15];
	char password;
	int tipoUtilizador; // Decisor ou administrador
}UTILIZADOR;


int menu();
void inserirOrcamentos(ORCAMENTO orcamento [], int *quantidadeOrcamentos, ORCAMENTO *apontador);
void alterarOrcamentos(int procuraNumero, int quantidadeOrcamentos, ORCAMENTO orcamento[], ORCAMENTO *apontador);
void listarOrcamentos(int quantidadeOrcamentos, ORCAMENTO orcamento[],ORCAMENTO *apontador);
void listarOrcamentosAcima(ORCAMENTO orcamento[], int quantidadeOrcamentos, ORCAMENTO *apontador);
void listarFornecedor(ORCAMENTO orcamento[], int quantidadeOrcamentos, ORCAMENTO *apontador);
void listarOrcamentosAnalisadosAprovados(int quantidadeOrcamentos, ORCAMENTO orcamento[]);


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
	case 0: //inserir as instruções para sair e guardar
	
	// sair(menuGuardar, quantidadeOrcamentos, orcamento,&apontador);
	 
	break;
	
	default: printf ("\nOPERAÇÃO INVÁLIDA\n");
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
	printf("\t\t|------------------------------------------------|\n");
	printf("\t\t| 0  - Fechar Program                            |\n");
	printf("\t\t|________________________________________________|\n");
    printf("\n\t\tIntroduza uma das opcoes: ");

	do{
		fflush(stdin);
		scanf("%d",&i);
	}while(i<0 && i>11);
	return i;
}


void inserirOrcamentos(ORCAMENTO orcamento [], int *quantidadeOrcamentos, ORCAMENTO *apontador){                            // função para inserir orçamentos quando a opção 1 do menu é selecionada

	    orcamento[*quantidadeOrcamentos].numeroOrcamentos = *quantidadeOrcamentos + 1 ;
	    printf("\n Nome do fornecedor do Orçamento: ");
	    fflush(stdin);
		scanf("%[^\n]s", orcamento[*quantidadeOrcamentos].nomeFornecedor);
		printf("\n Descrição do orçamento: ");
	    fflush(stdin);
		scanf("%[^\n]s", orcamento[*quantidadeOrcamentos].descricao);
		printf("\n Valor do orçamento: ");
		scanf("%f", &(orcamento[*quantidadeOrcamentos].valorOrcamento));
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
	printf("\nO orçamento número %d NÃO EXISTE!!!", procuraNumero);
	}
}

void listarOrcamentos(int quantidadeOrcamentos, ORCAMENTO orcamento[],ORCAMENTO *apontador){                                // função para listar orçamentos quando a opção 3 do menu é selecionada
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