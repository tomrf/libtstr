#include "tstr.h"


void* _tstr_malloc(size_t size)
{
  void *p;

  if ((p = malloc(size)) == NULL)
    fprintf(stderr, "*** libtstr: malloc(%d) failed ***\n", size);

  return p;
}


void* _tstr_realloc(void *ptr, size_t size)
{
  void *p;

  if ((p = realloc(ptr, size)) == NULL)
    fprintf(stderr, "*** libtstr: realloc(%p, %d) failed ***\n", ptr, size);

  return p;
}
