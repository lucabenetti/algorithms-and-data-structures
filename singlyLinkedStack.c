#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct pilha Pilha;
typedef struct no No;
 
Pilha * pilha_cria (int maxTamanho);
Pilha * pilha_copia (Pilha * p);
void pilha_libera (Pilha * p);
int pilha_insere (Pilha * p, char * elemento); // push
char * pilha_remove (Pilha * p); // pop
char * pilha_obtem_topo  (Pilha * p); // top
int pilha_obtem_tamanho  (Pilha * p);
int pilha_se_vazia (Pilha * p);
int pilha_se_cheia (Pilha * p);
char * pilha_imprime  (Pilha * p);
 
struct pilha {
    int tamanho;
    int maxTamanho;
    No *topo;
};
 
struct no {
    char *elemento;
    struct no *proximo;
};
 
Pilha * pilha_cria (int maxTamanho) {
    Pilha *q = (Pilha *) malloc (sizeof(Pilha));
    
   
    if(q != NULL) {
        q->tamanho = 0;
        q->maxTamanho = maxTamanho;
        q->topo = NULL;
    }
   
    return q;
}
 
Pilha * pilha_copia (Pilha * p){

   Pilha *q = pilha_cria(p->maxTamanho);

   Pilha *aux1 = pilha_cria(p->maxTamanho);
   Pilha *aux2 = pilha_cria(p->maxTamanho);
   
   No *aux = p->topo;
   
   int i;
  
   
   while(p->tamanho > 0) {
   		char *str = pilha_remove(p);
   		pilha_insere(aux1, str);
   }
   
   while(aux1->tamanho >0) {
  		char *str = pilha_remove(aux1);
  		pilha_insere(q, str);
  		pilha_insere(p, str);
   }
   
   return q;
 
}
 
void pilha_libera (Pilha * p) {
    No *aux = p->topo;
   
    while (aux->proximo != NULL) {
        No *q = aux;
        aux = aux->proximo;
        free(q);
    } free(p);
}
 
int pilha_insere (Pilha * p, char * elemento) {
    if(p == NULL || p->tamanho == p->maxTamanho) return -1;
 
    No *novo = malloc (sizeof(No));
   
    novo->elemento = malloc (strlen(elemento)+1);
    strcpy(novo->elemento, elemento);
 
    if(p->tamanho == 0) {  
        p->topo = novo;
        novo->proximo = NULL;
    }
   
    else {
        novo->proximo = p->topo;
        p->topo = novo;
    }
   
    p->tamanho++;
   
    return 1;
}
 
char * pilha_remove (Pilha * p) {
 
    No *aux = p->topo;
   
    p->topo = aux->proximo;
   
 
    char *str = malloc (strlen(aux->elemento)+1);
    strcpy(str, aux->elemento);
       
    free(aux);
    
    p->tamanho--;
   
    return str;
}
 
char * pilha_obtem_topo  (Pilha * p) {
    return p->topo->elemento;
}
int pilha_obtem_tamanho  (Pilha * p) {
    return p->tamanho;
}
int pilha_se_vazia (Pilha * p) {
    if(p->tamanho == 0) return 1;
    else return 0;
}
int pilha_se_cheia (Pilha * p) {
    if(p->tamanho == p->maxTamanho) return 1;
    else return 0;
}
char * pilha_imprime  (Pilha * p) {
    char *str = malloc (10000);
   
    No *aux = p->topo;
   
    int i = 0;
   
    while (aux != NULL) {
        if(i == 0) sprintf(str, "%s ", aux->elemento);
        else sprintf(str, "%s%s ", str, aux->elemento);
        aux = aux->proximo;
        i++;
    }
           
    return str;
}

int main () {

}
