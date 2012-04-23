#include "tstr.h"


void tstr_free(tstr_t *ts)
{
  free(ts->data);
  free(ts);
}
