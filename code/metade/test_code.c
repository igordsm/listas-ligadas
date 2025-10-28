#include "llist.h"
#include <check.h>
#include <stdlib.h>

LList *prepend(LList *l, int val) {
  // cria novo nó
  LList *new_node = malloc(sizeof(LList));
  new_node->val = val;
  // aponta para o resto da lista
  new_node->next = l;
  return new_node;
}

LList *metade(LList *l);

START_TEST(test_vazio_um_elemento) {
  ck_assert_ptr_null(metade(NULL));

  LList *sozinho = prepend(NULL, 5);
  ck_assert_ptr_eq(metade(sozinho), sozinho);

  free(sozinho);
}
END_TEST

START_TEST(test_tamanho_impar1) {
  LList *inicio = prepend(NULL, 5);
  inicio = prepend(inicio, 10);
  inicio = prepend(inicio, 22);

  LList *m = metade(inicio);
  ck_assert_ptr_nonnull(m);
  ck_assert_ptr_eq(m, inicio->next);

  while (inicio != NULL) {
    LList *temp = inicio;
    inicio = inicio->next;
    free(temp);
  }
}
END_TEST

START_TEST(test_tamanho_impar2) {
  LList *inicio = prepend(NULL, 5);
  inicio = prepend(inicio, 10);
  inicio = prepend(inicio, 15);
  inicio = prepend(inicio, 11);
  inicio = prepend(inicio, 22);

  LList *m = metade(inicio);
  ck_assert_ptr_nonnull(m);
  ck_assert_ptr_eq(m, inicio->next->next);

  while (inicio != NULL) {
    LList *temp = inicio;
    inicio = inicio->next;
    free(temp);
  }
}
END_TEST

START_TEST(test_tamanho_par1) {
  LList *inicio = prepend(NULL, 5);
  inicio = prepend(inicio, 15);
  inicio = prepend(inicio, 22);
  inicio = prepend(inicio, 28);

  LList *m = metade(inicio);
  ck_assert_ptr_nonnull(m);
  ck_assert_ptr_eq(m, inicio->next->next);

  while (inicio != NULL) {
    LList *temp = inicio;
    inicio = inicio->next;
    free(temp);
  }
}
END_TEST

START_TEST(test_tamanho_par2) {
  LList *inicio = prepend(NULL, 5);
  inicio = prepend(inicio, 11);
  inicio = prepend(inicio, 19);
  inicio = prepend(inicio, 16);
  inicio = prepend(inicio, 22);
  inicio = prepend(inicio, 28);

  LList *m = metade(inicio);
  ck_assert_ptr_nonnull(m);
  ck_assert_ptr_eq(m, inicio->next->next->next);

  while (inicio != NULL) {
    LList *temp = inicio;
    inicio = inicio->next;
    free(temp);
  }
}
END_TEST

int main() {

  Suite *s = suite_create("Lista Ligada - prepend");
  TCase *t = tcase_create("prepend");
  suite_add_tcase(s, t);
  tcase_add_test(t, test_vazio_um_elemento);
  tcase_add_test(t, test_tamanho_impar1);
  tcase_add_test(t, test_tamanho_impar2);
  tcase_add_test(t, test_tamanho_par1);
  tcase_add_test(t, test_tamanho_par2);

  SRunner *sr = srunner_create(s);

  srunner_run_all(sr, CK_VERBOSE);
  int num_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return num_failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
