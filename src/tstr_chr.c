#include "tstr.h"

int tstr_chr(tstr_t *ts, tstr_off_t offset)
{
  if (offset > tstr_strlen(ts) - 1 || offset < 0)
    return -1;

  return *(ts->string + offset);
}

