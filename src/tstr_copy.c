#include "tstr.h"

tstr_t* tstr_copy(tstr_t *ts)
{
  return tstr_create(tstr_string(ts));
}
