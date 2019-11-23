#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* TAD.h */

typedef struct fila Fila;
typedef struct elemento Elemento;
Fila * fila_cria (int maxTamanho);
Fila * fila_copia (Fila * p);
void fila_libera (Fila * p);
int fila_insere (Fila * p, char * elemento);
char * fila_remove (Fila * p);
char * fila_obtem_primeiro (Fila * p);
int fila_obtem_tamanho (Fila * p);
int fila_se_vazia (Fila * p);
int fila_se_cheia (Fila * p);
char * fila_imprime (Fila * p);

/* TAD.c */

struct elemento {
	char *elementos;
	Elemento *proximo;
};

struct fila{
    Elemento *inicio;
	 Elemento *final;
    int tamanho;
};

Fila * fila_cria (int maxTamanho){
    Fila * p = (Fila *) malloc(sizeof(Fila));
    if(p != NULL){
        p->inicio = NULL;
        p->final = NULL;
        p->tamanho = 0;
       
    }
    return p;
}
 
Fila * fila_copia (Fila * p){
	Fila *q = malloc (sizeof(Fila));
	
	if(q != NULL) {
		q->inicio = malloc(sizeof(Elemento));
		q->tamanho = p->tamanho;
	}
	
	Elemento *auxP = p->inicio;
	Elemento *auxQ = q->inicio;
	int i;

	for(i = 0; i < p->tamanho; i++) {
		auxQ->elementos = malloc (strlen(auxP->elementos)+1);
		strcpy(auxQ->elementos, auxP->elementos);
		auxQ->proximo = malloc(sizeof(Elemento));
		if(i != p->tamanho-1) {
			auxQ = auxQ->proximo;
			auxP = auxP->proximo;
		}
	} q->final = auxQ;
		
	return q;
}
 
void fila_libera (Fila * p){
    if(p != NULL){
        Elemento * no;
        while(p->inicio != NULL){
            no = p->inicio;
            p->inicio = p->inicio->proximo;
            free(no);
        }
        free(p);
    }
}
 
int fila_insere (Fila * p, char * elemento){
   if(p == NULL)
		return 0;

	Elemento *no = malloc(sizeof(Elemento));

	if(no == NULL)
		return 0;

	no->elementos = malloc (strlen(elemento)+1);

	strcpy(no->elementos, elemento);

	no->proximo = NULL;

	if(p->final == NULL)
		p->inicio = no;

	else 
		p->final->proximo = no;

	p->final = no;
	p->tamanho++;
	
	return 1;
}
 
char * fila_remove (Fila * p){
	if(p == NULL)
		return 0;
	
	if(p->inicio == NULL)
		return 0;

	Elemento *no = p->inicio;
	p->inicio = p->inicio->proximo;

	if(p->inicio == NULL)
		p->final = NULL;

	char *aux = (char*) malloc (strlen(no->elementos)+1);
	strcpy(aux, no->elementos);
	
	free(no);
	p->tamanho--;
	return aux;
}
 
char * fila_obtem_primeiro (Fila * p){
    return p->inicio->elementos;
}
 
int fila_obtem_tamanho (Fila * p){
    if(p == NULL)
        return -1;
   
    return p->tamanho;
}
 
int fila_se_vazia (Fila * p){
	if(p == NULL || p->inicio == NULL)
		return 1;

	return 0;		
}
 
int fila_se_cheia (Fila * p){
    return 0;
}
 
char * fila_imprime (Fila * p){
	char *aux = malloc (100000);
	aux[0] = '\0';

	if(p->tamanho == 0)
		return aux;

	Elemento *q = p->inicio;

	int i;
	
	for(i = 0; i < p->tamanho; i++) {
		if (i == 0)
			sprintf(aux, "%s ", q->elementos);
		else 
			sprintf(aux, "%s%s ", aux, q->elementos);
		q = q->proximo;
	}	

	return aux;
}

/* meuprograma.c */

int main () {
	return 0;
}
