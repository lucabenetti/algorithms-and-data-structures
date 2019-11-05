#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

struct elemento {
	int elemento;
	struct elemento * proximo;
};

struct lista {
	struct elemento * cabeca;
	int tamanho;
};

Lista * lista_cria () {
	Lista * q = (Lista *) malloc(sizeof(Lista));
	if (q!=NULL) {
		q->cabeca = NULL;
		q->tamanho = 0;
	}
	return q;
}
Lista * lista_copia (Lista * p) {
	Lista * q = (Lista *) malloc(sizeof(Lista));
	if (q!=NULL) {
		if (p->tamanho == 0)
			q->cabeca == NULL;
		else {
			q->cabeca = (struct elemento *) malloc(sizeof(struct elemento));
			struct elemento * p_elem;
			struct elemento * q_elem;
			p_elem = p->cabeca;
			q_elem = q->cabeca;
			while (p_elem != NULL) {
				q_elem->elemento = p_elem->elemento;
				if (p_elem->proximo == NULL)
					q_elem->proximo = NULL;
				else
					q_elem->proximo = (struct elemento *) malloc(sizeof(struct elemento));
				q_elem = q_elem->proximo;
				p_elem = p_elem->proximo;
			}
		}
		q->tamanho = p->tamanho;
	}
	return q;
}
void lista_libera (Lista * p) {
	struct elemento * q = p->cabeca;
	while (q != NULL) {
		struct elemento * aux = q->proximo;
		free(q);
		q = aux;
	}
	free(p);
}
int lista_insere_inicio (Lista * p, int elemento) {
	struct elemento * q = malloc(sizeof(struct elemento));
	if (q!=NULL) {
		q->elemento = elemento;
		q->proximo  = p->cabeca;
		p->cabeca   = q;
		p->tamanho  = p->tamanho + 1;
		return 1; // insercao com sucesso
	}
	return 0; // erro na insercao
}
int lista_insere_final (Lista * p, int elemento) {
	struct elemento * q = malloc(sizeof(elemento));
	q->elemento = elemento;
	q->proximo = NULL;
	if (p->tamanho == 0)
		p->cabeca = q;
	else {
		struct elemento * aux = p->cabeca;
		while (aux->proximo != NULL)
			aux = aux->proximo;
		aux->proximo = q;
	}
	p->tamanho = p->tamanho+1;	
	return 1; // insercao com sucesso	
}
int lista_insere_posicao (Lista * p, int elemento, int posicao) {
	if (posicao < 1)
		return 0; // insercao sem sucesso, alem do inicio da lista
	if (posicao > p->tamanho+1)
		return 0; // insercao sem sucesso, alem do final da lista
	struct elemento * q = malloc(sizeof(struct elemento));
	q->elemento = elemento;
	if (posicao == 1) {
		if (p->tamanho == 0)
			q->proximo = NULL;
		else
			q->proximo = p->cabeca;
		p->cabeca = q;
	} else {
		struct elemento * aux = p->cabeca;
		while (posicao>2) {
			aux = aux->proximo;
			posicao--;
		}
		q->proximo = aux->proximo;
		aux->proximo = q;
	}
	p->tamanho = p->tamanho+1;	
	return 1; // inserção com sucesso
}
int lista_remove_inicio (Lista * p) {
	lista_remove_posicao(p, 1);
}
int lista_remove_final  (Lista * p) {
	lista_remove_posicao(p, lista_obtem_tamanho(p));
}
int lista_remove_posicao (Lista * p, int posicao) {
	if (posicao < 1 || posicao > p->tamanho) return 0;
	
	struct elemento * aux = p->cabeca;

	if(posicao == 1) {
		p->cabeca = aux->proximo;
		aux->proximo = NULL;
	} 

	else {
		int i = 1;
		while(i != posicao) {
			aux = aux->proximo;
			i++;
		}

		struct elemento * prox = aux->proximo;

		for(i = i; i < p->tamanho; i++) {
			aux->elemento = prox->elemento;
			aux->proximo = prox->proximo;
		}
	}

}
int lista_obtem_elemento  (Lista * p, int posicao) {
	if ((posicao<1)||(posicao>p->tamanho))
		return -1;
	struct elemento * q = p->cabeca;
	int i;
	for (i=0; i<posicao-1; i++)
		q = q->proximo;
	return q->elemento;
}
int lista_se_presente  (Lista * p, int elemento) {
	int i;
	struct elemento * aux = p->cabeca;

	for(i = 1; i <= p->tamanho; i++) {
		if(elemento == aux->elemento) return i;
		aux = aux->proximo;
	}

	return 0;
}
int lista_obtem_tamanho  (Lista * p) {
	return p->tamanho;
}
char * lista_imprime  (Lista * p) {
	char * imprime = (char *) malloc(1);
	imprime[0] = '\0';
	int tamanho = 1;
	struct elemento * q = p->cabeca;
	int i;
	for (i=0; i < p->tamanho; i++) {
		char aux[10];
		int j, tam_aux;
		if (i==0)
			sprintf(aux, "%d" , q->elemento);
		else
			sprintf(aux, " %d", q->elemento);
		for (tam_aux=0; aux[tam_aux] != '\0'; tam_aux++)
			;
		imprime = realloc(imprime, tamanho + tam_aux);
		for (j=0; j<tam_aux; j++)
			imprime[tamanho+j-1] = aux[j];
		tamanho = tamanho + tam_aux;
		imprime[tamanho-1] = '\0';
		q = q->proximo;
	}
	return imprime;
}
int lista_compara_elemento (int elemento1, int elemento2) {
	if(elemento1 == elemento2) return 1;
	else return 0;
}
void lista_ordena (Lista * p) {
	;
}
