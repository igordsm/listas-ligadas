#include "llist.h"

LList *prepend(LList *l, int val) {
  // cria novo nó
  LList *new_node = malloc(sizeof(LList));
  new_node->val = val;
  // aponta para o resto da lista
  new_node->next = l;
  return new_node;
}

LList *insere1() {
  // Use a função prepend acima para criar uma lista ligada
  // com os valores (nessa ordem)
  // 1, 5, 8, 22, 5
  //
  // Sua função deve devolver a lista criada.
  // DICA: comece inserindo na lista vazia
  
  return NULL;
}
