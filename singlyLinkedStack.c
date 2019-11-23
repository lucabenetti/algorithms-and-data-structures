#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct pilha Pilha;
 
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
    char **elementos;
};
 
Pilha *pilha_cria(int maxTamanho) {
    Pilha *q = malloc (sizeof(Pilha));
   
    if(q != NULL) {
        q->elementos = malloc (sizeof(char *) * maxTamanho);
        q->tamanho = 0;
        q->maxTamanho = maxTamanho;
    }
 
    return q;
}
 
Pilha * pilha_copia (Pilha * p) {
    Pilha *q = pilha_cria(p->maxTamanho);
   
    int i;
   
    for(i = 0; i < p->tamanho; i++) {
        q->elementos[i] = malloc (strlen(p->elementos[i])+1);
        strcpy(q->elementos[i], p->elementos[i]);
    }
   
    q->tamanho = p->tamanho;
   
    return q;
}
 
void pilha_libera (Pilha * p) {
    int i;
   
    for(i = 0; i < p->tamanho; i++) {
        free(p->elementos[i]);
    }
   
    free(p);
}
 
int pilha_insere (Pilha * p, char * elemento) {
    if(pilha_se_cheia(p) || p == NULL) return 0;
       
    p->elementos[p->tamanho] = malloc (strlen(elemento)+1);
 
    strcpy(p->elementos[p->tamanho], elemento);
 
    p->tamanho++;  
   
    return 1;
}
 
char * pilha_remove (Pilha * p) {
    char *aux = malloc (strlen(p->elementos[p->tamanho-1])+1);
   
    p->elementos[p->tamanho-1] = NULL;
   
    p->tamanho--;
   
    return aux;
}
 
char * pilha_obtem_topo  (Pilha * p) {
    if(p == NULL || p->tamanho == 0) return '\0';
    return p->elementos[p->tamanho-1];
}
int pilha_obtem_tamanho  (Pilha * p) {
    if (p == NULL) return -1;
   
    return p->tamanho;
}
int pilha_se_vazia (Pilha * p) {
    if(p == NULL) return -1;
   
    if(p->tamanho == 0) return 1;
}
int pilha_se_cheia (Pilha * p) {
    if(p == NULL) return -1;
   
    else if(p->tamanho == p->maxTamanho) return 1;
 
    else return 0;
}
char * pilha_imprime  (Pilha * p) {
    char *aux = malloc (10000);
    aux[0] = '\0';
 
    if(p->tamanho == 0 || p == NULL) return aux;
 
    int i;
 
    for(i = 0; i < p->tamanho; i++) {
        if(i == 0) sprintf(aux, "%s ", p->elementos[i]);
        else sprintf(aux, "%s%s ", aux, p->elementos[i]);
    }              
                   
                   
    return aux;
}
 
 
int main () {
	return 0;
}


