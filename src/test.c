#include "tstr.h"


int main(void)
{
  tstr_t *ts[10];

  printf("======= tstr_create() ===================\n");

  ts[0] = tstr_create(NULL); __tstr_debug_pinfo(ts[0]); tstr_free(ts[0]);
  ts[0] = tstr_create("Test"); __tstr_debug_pinfo(ts[0]); tstr_free(ts[0]);
  ts[0] = tstr_create("%s%c%d", "varlist", '-', 1234); __tstr_debug_pinfo(ts[0]); tstr_free(ts[0]);


  printf("\n======= tstr_copy() =====================\n");
  
  ts[0] = tstr_create("copyme");
  ts[1] = tstr_copy(ts[0]);
  __tstr_debug_pinfo(ts[0]);
  __tstr_debug_pinfo(ts[1]);
  tstr_free(ts[0]);  tstr_free(ts[1]);


  printf("\n======= tstr_sprintf() ==================\n");
  
  ts[0] = tstr_create(NULL);
  tstr_sprintf(ts[0], "%s%c%d", "ab", 'c', 1234);
  __tstr_debug_pinfo(ts[0]);
  
  ts[1] = tstr_create(NULL);
  tstr_sprintf(ts[1], "TEST-%s-", tstr_string(ts[0]));
  __tstr_debug_pinfo(ts[1]);

  tstr_sprintf(ts[1], "%s", tstr_string(ts[1]));
  __tstr_debug_pinfo(ts[1]);

  tstr_sprintf(ts[1], "%s%s", tstr_string(ts[1]), tstr_string(ts[1]));
  __tstr_debug_pinfo(ts[1]);

  tstr_free(ts[0]);  tstr_free(ts[1]);


  printf("\n======= tstr_strcmp() ===================\n");

  ts[0] = tstr_create("abcdef");
  ts[1] = tstr_create("abcdeg");

  printf("tstr_strcmp(\"%s\", \"%s\"): %d\n", 
         tstr_string(ts[0]), tstr_string(ts[1]), tstr_strcmp(ts[0], ts[1]));

  printf("tstr_strncmp(\"%s\", \"%s\", 5): %d\n", 
         tstr_string(ts[0]), tstr_string(ts[1]), tstr_strncmp(ts[0], ts[1], 5));

  tstr_free(ts[0]);  tstr_free(ts[1]);


  printf("\n======= tstr_strreplace() ===============\n");

  ts[0] = tstr_create("Banana, aa ba ca");
  __tstr_debug_pinfo(ts[0]);
  printf("tstr_strreplace(\"Banana, aa, ba, ca\", \"a\", \"X\"): %d\n",
       tstr_strreplace(ts[0], "a", "X"));
  __tstr_debug_pinfo(ts[0]);
  
  tstr_free(ts[0]);  


  printf("\n======= tstr_chr() ======================\n");

  ts[0] = tstr_create("abc");
  printf("tstr_chr(\"%s\", 0): %d %c\n", tstr_string(ts[0]), tstr_chr(ts[0], 0), tstr_chr(ts[0], 0));
  printf("tstr_chr(\"%s\", 1): %d %c\n", tstr_string(ts[0]), tstr_chr(ts[0], 1), tstr_chr(ts[0], 1));
  printf("tstr_chr(\"%s\", 2): %d %c\n", tstr_string(ts[0]), tstr_chr(ts[0], 2), tstr_chr(ts[0], 2));
  printf("tstr_chr(\"%s\", 3): %d %c\n", tstr_string(ts[0]), tstr_chr(ts[0], 3), tstr_chr(ts[0], 3));



  return 0;
}

