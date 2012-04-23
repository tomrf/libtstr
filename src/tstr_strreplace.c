#include "tstr.h"

int tstr_strreplace(tstr_t *ts, const char *search, const char *replace)
{
  int   hits = 0;

  for (;;) {
    if (_tstr_strreplace(ts, search, replace))
      hits++;
    else
      break;
  }

  return hits;
}


int _tstr_strreplace(tstr_t *ts, const char *search, const char *replace)
{
  tstr_t      *ts_copy;
  tstr_len_t  offset;
  tstr_len_t  len;
  char        *ptr;

  if ((ptr = strstr(tstr_string(ts), search)) == NULL)
    return 0;

  len = tstr_strlen(ts);
  offset = ptr - tstr_string(ts);

  if (offset > len || 0 > offset)
    return -1;

  if ((ts_copy = tstr_copy(ts)) == NULL)
    return -1;

  *(ts->string + offset) = '\0';
  *(ts_copy->string + offset) = '\0';

  tstr_sprintf(ts, "%s%s%s", 
       tstr_string(ts_copy), replace, 
       tstr_string(ts_copy) + offset + strlen(search));

  tstr_free(ts_copy);

  return 1;
}

