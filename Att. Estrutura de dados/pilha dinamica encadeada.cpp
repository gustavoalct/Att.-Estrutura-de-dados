#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// tipos de dados

typedef struct Item	{
	//char[] caracter;
	int item;
	struct Item *prox;
}Titem;


typedef struct Pilha{
	Titem *topo;
}TPilha;

void inicializaPilha(TPilha *pilha){
	pilha->topo=NULL; // zera a pilha 
}


void Empilha(TPilha *pilha){
	Titem *novo;
	novo = new Titem;
	
	printf("\n Digite o valor para pilha: ");
	scanf("%d",&novo->item);
	novo->prox=NULL;
	printf("\n");
	
	if(pilha->topo == NULL)	{ // indica que a pilha está vazia
		pilha->topo = novo;
	}else{
		novo->prox = pilha->topo;
		pilha->topo = novo;
	}
}

void Desempilha(TPilha *pilha){
	// desempilha sempre pelo topo
	Titem *aux;
	
	if(pilha->topo == NULL){
		printf("\n Pilha vazia..\n");
	}else{
		aux = pilha->topo;
		pilha->topo = pilha->topo->prox;
		free(aux);
	}
	
}

main(){
	int op;
	TPilha p1;
	 inicializaPilha(&p1);
	 
	 do{
	 	printf("1 - Empilhar elemento\n");
		printf("2 - Desempilha elemento\n");
		printf("3 - Apresentar pilha\n");
	 	printf("0 - sair menu\n\n");
	 	printf("Digite sua opcao:\n");
	 	scanf("%d",&op);
	 	
	 	if(op==1){ // empilhar
	 		Empilha(&p1);
	 		break;
		 }else if(op==2){
		 	Desempilha(&p1);
		 	break;
		 } else if(op == 3){
		 //	Apresentar(&p1);
		 	break;
		 }else{
		 	printf("\nOpcao invalida...\n");
		 }
	 	
	 }while(op!=0);
	 
	 
	 
	 
}
