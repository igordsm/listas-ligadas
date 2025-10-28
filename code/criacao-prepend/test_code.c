#include <check.h>
#include <stdlib.h>
#include "llist.h"

LList *insere1();

START_TEST(test_insere1) {
  // 1, 5, 8, 22, 5
  LList *inicio;
  LList *l = inicio = insere1();
  ck_assert_ptr_nonnull(l);
  ck_assert_int_eq(l->val, 1);

  l = l->next;
  ck_assert_ptr_nonnull(l);
  ck_assert_int_eq(l->val, 5);

  l = l->next;
  ck_assert_ptr_nonnull(l);
  ck_assert_int_eq(l->val, 8);
  
  l = l->next;
  ck_assert_ptr_nonnull(l);
  ck_assert_int_eq(l->val, 22);
  
  l = l->next;
  ck_assert_ptr_nonnull(l);
  ck_assert_int_eq(l->val, 5);

  l = l->next;
  ck_assert_ptr_null(l);

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
  tcase_add_test(t, test_insere1);

  SRunner *sr = srunner_create(s);

  srunner_run_all(sr, CK_VERBOSE);
  int num_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return num_failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
