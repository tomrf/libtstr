#include "tstr.h"

int _tstr_vaprintf(tstr_t *ts, const char *format, va_list args)
{
  tstr_len_t  data_len;
  tstr_len_t  string_len;
  va_list     args_copy;
  int         ret;

  if (ts->data_len <= 2) {
    if (_tstr_str_resize(ts, 16) == NULL)
      return -1;
  }

  data_len = ts->data_len;
  string_len = data_len - 1;


  while (1) {

    va_copy(args_copy, args);
    ret = vsnprintf(ts->string, string_len, format, args_copy);
    va_end(args_copy);

    if (ret < string_len && ret > -1)
      break;
    if (ret > -1)
      string_len = ret + 1;
    else
      string_len *= 2;

    if (_tstr_str_resize(ts, string_len) == NULL)
      return -1;

  }

  /* trim the size down if needed */
  string_len = tstr_strlen(ts);
  if (ts->data_len > (string_len + 2)) {
    if (_tstr_str_resize(ts, string_len) == NULL)
      return -1;
  }

  return tstr_strlen(ts);
}
