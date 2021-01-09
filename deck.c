#include "deck.h"

Deck* createDeck () {
  return NULL;
}

Point getFront (Deck *d) {


   if(d != NULL){

    return d->p;

   }
   else
    exit(1);
}

Point getRear (Deck *d) {

   Deck* test = d;

   while(test->next != NULL){

        test = test->next;

   }
   return test->p;
}

Deck* insertFront (Deck *d, Point p, char field[][SIZE]) {

    Deck* novo = (Deck*) malloc (sizeof(Deck));
    novo->prev = NULL;
    novo->next = d;
    novo->p = p;


    if(d != NULL){//caso nao for o primeiro da lista

        d->prev = novo;
    }

    field[p.x][p.y] = '*'; /*Ponto inserido faz parte do corpo da Snake!*/

    return novo;
}

Deck* insertRear (Deck *d, Point p, char field[][SIZE]) {

    Deck* novo = (Deck*) malloc (sizeof(Deck));
    novo->next = NULL;
    novo->prev = NULL;
    novo->p = p;

    Deck* test = d;

    if(d != NULL){
    while(test->next != NULL){

        test = test->next;

    }

    novo->prev = test; //quando for encontrado o final da fila
    test->next = novo;

    field[p.x][p.y] = '*'; /*Ponto inserido faz parte do corpo da Snake!*/

    return d;

    }
    else
        return novo;


}

Deck* deleteFront (Deck *d, char field[][SIZE]) {

    if(d != NULL){
        Deck *aux = d;

        if(aux->next != NULL){

            aux->next->prev = NULL;
        }

        d = d->next;
        field[aux->p.x][aux->p.y] = ' ';
        free(aux);
        return d;

    }
    else
        return NULL;

}

Deck* deleteRear (Deck *d, char field[][SIZE]) {

    if(d != NULL){

        Deck* aux = d;

        while(aux->next != NULL){

            aux = aux->next;

        }
        field[aux->p.x][aux->p.y] = ' ';
        aux->prev->next = NULL;
        free(aux);
        return d;

    }
    else
        return NULL;
}


