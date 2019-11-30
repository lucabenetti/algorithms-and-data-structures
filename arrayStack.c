#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct pilha Pilha;
 
Pilha * pilha_cria (int maxTamanho);
Pilha * pilha_copia (Pilha * p);
void pilha_libera (Pilha * p);
int pilha_insere (Pilha * p, char * elemento); // push
char * pilha_remove (Pilha * p); // pop
char * pilha_obtem_topo (Pilha * p); // top
int pilha_obtem_tamanho (Pilha * p);
int pilha_se_vazia (Pilha * p);
int pilha_se_cheia (Pilha * p);
char * pilha_imprime (Pilha * p);
 
struct pilha {
    int tamanho;
    int maxTamanho;
    char ** elementos;
};
 
Pilha * pilha_cria (int maxTamanho) {
    Pilha * q = (Pilha *) malloc(sizeof(Pilha));
    if (q!=NULL) {
        q->tamanho = 0;
        q->maxTamanho = maxTamanho;
        q->elementos = (char **) malloc(sizeof(char *) * maxTamanho);
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
    free(p->elementos);
    free(p);
}
int pilha_insere (Pilha * p, char * elemento) {
    if(p==NULL)return 0;
    if(pilha_se_cheia(p))return 0;
    p->elementos[p->tamanho]=(char *) malloc((strlen(elemento)+1)*sizeof(char));
    strcpy(p->elementos[p->tamanho],elemento);
    p->tamanho++;
    return 1; // insercao com sucesso    
}
char * pilha_remove (Pilha * p) {
    
    if(p==NULL || p->tamanho==0) return 0;
    char *temp = (char*)malloc((strlen(p->elementos[p->tamanho-1])+1)*sizeof(char));
    strcpy(temp,p->elementos[p->tamanho-1]);
    p->tamanho--;
    return temp;
}
char * pilha_obtem_topo  (Pilha * p) {
    if(p==NULL || p->tamanho==0)return "\0";
    return p->elementos[p->tamanho-1];
}
int pilha_obtem_tamanho  (Pilha * p) {
    if(p==NULL) return -1;
    return p->tamanho;
}
int pilha_se_vazia (Pilha * p) {
    if(p==NULL)return -1;
    return (p->tamanho==0);
}
int pilha_se_cheia (Pilha * p) {
    if(p==NULL)return -1;
    return (p->tamanho==p->maxTamanho);    
}
char * pilha_imprime  (Pilha * p) {
    char * aux = (char *) malloc(sizeof(char)*10*p->maxTamanho);
    aux [0] = '\0';
    int i;
    for (i=p->tamanho-1; i>=0; i--) {
        strcat(aux, p->elementos[i]);
        strcat(aux, " ");
    }
    aux = realloc(aux, strlen(aux)+1);
    return aux;
}
