#include "tstr.h"


tstr_t* tstr_create(const char *format, ...)
{
  tstr_t      *ts;
  va_list     args;
  int         ret;

  if ((ts = _tstr_malloc(sizeof (tstr_t))) == NULL)
    return NULL;

  if ((ts->data = _tstr_malloc(2)) == NULL) {
    free(ts);
    return NULL;
  }

  ts->data_len = 2;
  _tstr_set_sptr(ts);
  _tstr_set_null(ts);

  if (format) {
    va_start(args, format);
    ret = _tstr_vaprintf(ts, format, args);
    va_end(args);

    if (ret == -1) {
      tstr_free(ts);
      return NULL;
    }

  }

  return ts;
}  


void _tstr_set_sptr(tstr_t *ts)
{
  ts->string = ts->data + 1;
}


void _tstr_set_null(tstr_t *ts)
{
  *(ts->data) = '\0';
  *(ts->data + ts->data_len - 1) = '\0';
}

