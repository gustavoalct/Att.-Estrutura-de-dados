#include <stdio.h>
#include <stdlib.h>

#define MAX 1000
int vet[MAX];

struct lista {
 int info;

 struct lista* prox;
};
typedef struct lista Lista;




/* função de inicialização: retorna uma lista vazia */
Lista* inicializa (void){
 return NULL;
}

/* inserção no início: retorna a lista atualizada */
Lista* insere (Lista* l, int i){
 Lista* novo = (Lista*) malloc(sizeof(Lista));
 novo->info = i;
 novo->prox = l;
 
 return novo;
}

Lista* exercicio1(Lista* l){
	// pega dois elementos a ser alterados
	int a, b;
	printf("Digite o primeira posicao elemento: \n");
	scanf("%d", &a);
	printf("Digite o segunda posicao elemento: \n");
	scanf("%d", &b);
	int cont=0, cont2=0;
	Lista* p;
	Lista* aux;
	Lista* aux2;
	Lista* w;
	// l tam max da lista, incrementa o proximo
	for(p = l; p != NULL; p = p->prox){
		cont++; // pega tamanho maximo da struct
	}
	
	if((a<=cont) &&(b<=cont)){
		cont=0;
		
		for(p = l; p != NULL; p = p->prox){
			 cont++;// pega o indice
			if(cont==a){
				aux=p;
				printf("info2213 = %d\n", p);
				cont2=cont;// pega o indice acima do indice 1
				for(w = p; w != NULL; w = w->prox){
					cont2++;
					
					if(cont2 == b){
						aux2 = w;
						w=aux;
						
						printf("info2222 = %d\n", aux2->info);
					   
					}
				
				}
				p=aux2; 
				
			}
			
		}
	}else{
		printf("nao e possivel...\n\n");
	}
	
	
	
}



Lista* Troca(Lista* l){
	

	int p1, p2;
	printf("Digite o primeira posicao elemento: \n");
	scanf("%d", &p1);
	printf("Digite o segunda posicao elemento: \n");
	scanf("%d", &p2);
	
	int cont=1;
	Lista* aux = l->prox ;
	Lista* aux2;
	Lista* troca;
	while(aux!=NULL){
		if(cont==p1-1){
			troca=aux;
			aux2=aux;
		
			while(aux2!=NULL){
				if(cont==p2-1){
					aux->prox = aux2->prox;
					aux2->prox = troca->prox;
					troca = troca->prox;
					aux = aux->prox;
					aux2 = aux->prox;
					aux->info = aux2->info;
					aux2->info = troca->info;
				}
				cont++;
				aux2 = aux2->prox;
			}	
		}
		cont++;
		aux = aux->prox;
		
	}
	
}


// exercicio 2 calcule
void Calcula(Lista* l ){
	Lista* p;
	int par=0, cont=0, media=0,total=0,maior = l->info, menor=l->info,menorPos=1;
	for (p = l; p != NULL; p = p->prox){
		cont++;
		total+= p->info;
		if(p->info %2 ==0){ // conta quantidade de elementos par
			par++;
		}
		// pega maior elemento
		if(maior < p->info){
			maior=p->info;
		}
		
		if(menor > p->info){
			menorPos=cont;
			menor= p->info;
		}
	}
	
	
	media=total/cont;
	// resultados
	printf("Letra a - Quantidade de pares: %d \n",par);
	printf("Letra b - Media da lista: %d \n",media);
	printf("Letra c - Maior elemento %d\n",maior);
	printf("Letra d - Menor posicao %d na posicao %d \n", menor, menorPos);
	printf("Letra e - Soma dos valores %d \n", total);
}


void imprime (Lista* l)
{
 Lista* p; /* variável auxiliar para percorrer a lista */
 for (p = l; p != NULL; p = p->prox)
 printf("info = %d\n", p->info);
}


// lista 2
struct lista2 {
 int info;

 struct lista2* prox;
};
typedef struct lista2 Lista2;

Lista2* inicializa2 (void){
 return NULL;
}

Lista2* insere2 (Lista2* l2, int i){
 Lista2* novo = (Lista2*) malloc(sizeof(Lista2));
 novo->info = i;
 novo->prox = l2;
 
 return novo;
}

void imprime2 (Lista2* l2)
{
 Lista2* p; 
 for (p = l2; p != NULL; p = p->prox)
 printf("info = %d\n", p->info);
}


struct lista3 {
 int info;

 struct lista3* prox;
};
typedef struct lista3 Lista3;

Lista3* inicializa3 (void){
 return NULL;
}

Lista* Merge(Lista* l1,Lista* l2) {
  Lista* l3 = NULL;
  Lista* aux1 = l1;
  Lista* aux2 = l2;

  while(aux1 != NULL) {
    if(aux1 != NULL) {
      l3 = insere(l3, aux1->info);
      aux1 = aux1->prox;
    }

    if(aux2 != NULL) {
      l3 = insere(l3, aux2->info);
      aux2 = aux2->prox;
    }
  }

  return l3;
}

 		
void imprime3 (Lista3* l3)
{
 Lista3* p; 
 for (p = l3; p != NULL; p = p->prox)
 	printf("Merge = %d\n", p->info);
}



int main (void){
 Lista* l; /* declara uma lista não inicializada */
 l = inicializa(); /* inicializa lista como vazia */
 l = insere(l, 23); /* insere na lista o elemento 23 */
 l = insere(l, 45); /* insere na lista o elemento 45 */
l = insere(l, 50);
l = insere(l, 65);
 // imprime(l);
 
 
  Lista2* l2;
  l2 = inicializa2(); /* inicializa lista como vazia */
   /* inicializa lista como vazia */
  l2 = insere2(l2, 10); /* insere na lista o elemento 23 */
  l2 = insere2(l2, 20); /* insere na lista o elemento 45 */
  l2 = insere2(l2, 30);
  l2 = insere2(l2, 40);
//imprime2(l2);
 //exercicio1(l);
 //Troca(l);
 //exercicio 2
 //Calcula(l);
 
 // exercicio 4 
 Lista3* l3;
 l3= inicializa3(); /* inicializa lista como vazia */
 l3 = Merge(l, l2);
 
 //exercicio 3 
 //Inverter(l);
 
 printf("\n");
 // mostra resultado do merge
 imprime3(l3);
}
