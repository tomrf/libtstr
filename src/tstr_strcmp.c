#include "tstr.h"

int tstr_strcmp(tstr_t *ts1, tstr_t *ts2)
{
  return strcmp(tstr_string(ts1), tstr_string(ts2));
}


int tstr_strncmp(tstr_t *ts1, tstr_t *ts2, size_t n)
{
  return strncmp(tstr_string(ts1), tstr_string(ts2), n);
}


int tstr_strcasecmp(tstr_t *ts1, tstr_t *ts2)
{
  return strcasecmp(tstr_string(ts1), tstr_string(ts2));
}

int tstr_strncasecmp(tstr_t *ts1, tstr_t *ts2, size_t n)
{
  return strncasecmp(tstr_string(ts1), tstr_string(ts2), n);
}
