#include "tstr.h"


void* _tstr_str_resize(tstr_t *ts, tstr_len_t size)
{
  if ((ts->data = _tstr_realloc(ts->data, size + 2)) == NULL)
    return NULL;
  
  ts->data_len = size + 2;

  _tstr_set_sptr(ts); 
  _tstr_set_null(ts);

  return ts;
}
