#include "tstr.h"



int tstr_sprintf(tstr_t *ts, const char *format, ...)
{
  va_list   args;
  tstr_t    *ts_copy;
  int       ret;

  if ((ts_copy = tstr_copy(ts)) == NULL)
    return -1;

  va_start(args, format);
  ret = _tstr_sprintf(ts_copy, format, args);
  va_end(args);

  if (ret == -1) {
    tstr_free(ts_copy);
    return -1;
  }

  free(ts->data);
  ts->data = ts_copy->data;
  ts->data_len = ts_copy->data_len;
  _tstr_set_sptr(ts);
  _tstr_set_null(ts);
  free(ts_copy);
  
  return ret;
}

int _tstr_sprintf(tstr_t *ts, const char *format, va_list args)
{
  int       ret;

  ret = _tstr_vaprintf(ts, format, args);

  return ret;
}
