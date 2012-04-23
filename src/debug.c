#include "tstr.h"

void __tstr_debug_pinfo(tstr_t *ts)
{
  char  *ptr;
  int   i;

  ptr = ts->data;

  printf("__tstr_debug_pinfo(%p): %p %p [", ts, ts->data, ts->string);

  for (i = 0; i < ts->data_len; i++) {
    if (isprint(*(ts->data+i)))
      printf("%c", *(ts->data+i));
    else
      printf("<%02x>", *(ts->data+i));
  }

  printf("] %d %d\n", ts->data_len, tstr_strlen(ts));
}
