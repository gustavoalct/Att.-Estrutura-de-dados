#include <stdio.h>
#include <stdlib.h>

typedef struct TipoCelula *TipoApontador;

struct TipoCelula{
	int item;
	TipoApontador prox;
};

typedef struct{
	TipoApontador topo,fundo;
	int tamanho;
}TipoPilha;

void FPVazia(TipoPilha *pilha){
	pilha->topo = (TipoApontador) malloc(sizeof(TipoCelula));
	pilha->fundo = pilha->topo;
	pilha->topo->prox = NULL;
	pilha->tamanho = 0;
}

int Vazia(TipoPilha pilha){
	return (pilha.tamanho == 0);
}

void Empilha(TipoPilha *pilha, int item){
	TipoApontador aux;
	aux = (TipoApontador) malloc(sizeof(TipoCelula));
	pilha->topo->item = item;
	aux->prox = pilha->topo;
	pilha->topo = aux;
	pilha->tamanho++;
}

void Desempilha(TipoPilha *pilha, int *item){
	TipoApontador q;
	
	if (Vazia(*pilha)){
		printf("Erro: Pilha Vazia.\n");
	}else{
		q = pilha->topo;
		pilha->topo = q->prox;
		*item = q->prox->item;
		free(q);
		pilha->tamanho--;
	}
}

TipoPilha inverte(TipoPilha p) {
	TipoPilha pilhaInvertida;
	FPVazia(&pilhaInvertida);

  int aux;

	printf("Pilha normal\n");
	while(!Vazia(p)) {
		Desempilha(&p, &aux);
		printf("Posicao %d: %d\n", pilhaInvertida.tamanho + 1, aux);
		Empilha(&pilhaInvertida, aux);
	}

	return pilhaInvertida;
  
}


int main(){
	TipoPilha p1;
	int item;
	FPVazia(&p1);
	int op = -1;
	
	
	item = 1; Empilha(&p1,item);
	item = 2; Empilha(&p1,item);
	item = 3; Empilha(&p1,item);
	item = 4; Empilha(&p1,item);

	TipoPilha pilhaInvertida = inverte(p1);
	// Pilha Invertida
	printf("\nPilha invertida\n");
	while(!Vazia(pilhaInvertida)) {
		int valor;
		Desempilha(&pilhaInvertida, &valor);
		printf("Posicao %d: %d\n", pilhaInvertida.tamanho + 1, valor);
	}
	return 1;
}
