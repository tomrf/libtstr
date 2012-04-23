#include "tstr.h"


tstr_len_t tstr_strlen(tstr_t *ts)
{
  tstr_len_t  len = 0;
  char        *ptr;

  ptr = ts->string;

  while(*ptr++)
    len++;

  return len;
}
