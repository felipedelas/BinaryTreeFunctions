#include "abbLista.h"


Arvore* cria_arv_vazia(void) {
    return NULL;
}

void arv_libera(Arvore* a) {
    if (a != NULL) {
        arv_libera(a->esq);
        arv_libera(a->dir);
        free(a);
    }
}

//========= Q1 - inserir
Arvore* inserir(Arvore* a, int v) {
    /* Completar */

    if (a == NULL)
    {
        a = (Arvore*)malloc(sizeof(Arvore));
        a->info = v;
        a->esq = NULL;
        a->dir = NULL;
    }
    else if (v < a->info)
    {
        a->esq = inserir(a->esq, v);
    }
    else {
        a->dir = inserir(a->dir, v);
    }

    return a;

}

//========= Q1 - remover
Arvore* remover(Arvore* a, int v) {
    if (a == NULL) {
        return NULL;
    }
    else {
        if (a->info > v)
            a->esq = remover(a->esq, v);
        else if (a->info < v)
            a->dir = remover(a->dir, v);
        else if ((a->esq == NULL) && (a->dir == NULL)) {
            free(a);
            a = NULL;
        }
        else if (a->dir == NULL) {
            Arvore* tmp = a;
            a = a->esq;
            free(tmp);
        }
        else if (a->esq == NULL) {
            Arvore* tmp = a;
            a = a->dir;
            free(tmp);
        }
        else {
            Arvore* tmp = a->esq;
            while (tmp->dir != NULL)
                tmp = tmp->dir;
            a->info = tmp->info;
            tmp->info = v;
            a->esq = remover(a->esq, v);
        }
    }
    return a;
}


//========= Q1 - busca
int buscar(Arvore* a, int v) {
    /* Completar */
    if (a == NULL) {
        return 0;
    }
    else if (v < a->info) {
        return buscar(a->esq, v);
    }
    else if (v > a->info) {
        return buscar(a->dir, v);
    }
    else {
        return 1;
    }


    return 1;

}

//========= Q2 - min =====

int minimo(Arvore* a) {
    if (a->esq != NULL) {
        return minimo(a->esq);
    }
    else {
        return a->info;
    }
}


//========= Q2 - max =====

int maximo(Arvore* a)
{

    if (a->dir != NULL)
    {
        return maximo(a->dir);
    }
    return a->info;
}

//========= Q3 - imprime_decrescente =====

void imprime_decrescente(Arvore* a)
{
    if (a != NULL)
    {
        imprime_decrescente(a->dir);
        printf("%d\n", a->info);
        imprime_decrescente(a->esq);
    }
}


//========= Q4 - maior ramo =====

int maior_ramo(Arvore* a)
{
    

    if (a != NULL)
    {
        
        int soma1 = maior_ramo(a->esq);
        int soma2 = maior_ramo(a->dir);

        if (soma1 > soma2)
        {
            return (soma1 + a->info);
        }
        else
        {
            return (soma2 + a->info);
        }

    }
   
}


void pre_order(Arvore* a) {
    if (a != NULL) {
        printf("%d ", a->info);
        pre_order(a->esq);
        pre_order(a->dir);
    }
}

int main() {





    //inserir
    //....
    srand(time(NULL));

    Arvore* a = cria_arv_vazia();

   /* a = inserir(a, 50);
    a = inserir(a, 30);
    a = inserir(a, 90);
    a = inserir(a, 20);
    a = inserir(a, 40);
    a = inserir(a, 95);
    a = inserir(a, 10);
    a = inserir(a, 35);
    a = inserir(a, 45);*/
    


    //printf("%d", maior_ramo(a));
    //teste 1
    for (int i = 0; i <= 100000; i++) {
           inserir(a, i);
         }
    if (buscar(a, 1000))
    {
        printf("O valor esta na arvore");
    }
    else {
        printf("O valor nao esta na arvore");
    }

        
    //teste 2
    /*for (int i = 0; i <= 100000; i++) {
           int valorAleatorio = (rand() % 100000);
          inserir(a, valorAleatorio);
         }
    if (buscar(a, 73821))
    {
        printf("O valor esta na arvore");
    }
    else
        printf("O valor nao esta na arvore");
        */
    

    // ====== Q5 ====

    return 0;
}
