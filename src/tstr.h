#ifndef __TSTR_H
#define __TSTR_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/*
 *  tstr->data: [<\0>[string]<\0>]
 *                   ^-- *string
 *               ^------ *data 
 */

typedef size_t tstr_len_t;
typedef off_t tstr_off_t;

typedef struct _tstr_element {
  char         *data;
  char         *string;
  tstr_len_t   data_len;
} tstr_t;


/* debug.c */
void __tstr_debug_pinfo(tstr_t *ts);

/* wrappers.c */
void* _tstr_malloc(size_t size);
void* _tstr_realloc(void *ptr, size_t size);

/* tstr_create.c */
tstr_t* tstr_create(const char *format, ...);
void _tstr_set_sptr(tstr_t *ts);
void _tstr_set_null(tstr_t *ts);

/* tstr_free.c */
void tstr_free(tstr_t *ts);

/* tstr_strlen.c */
tstr_len_t tstr_strlen(tstr_t *ts);

/* tstr_vaprintf.c */
int _tstr_vaprintf(tstr_t *ts, const char *format, va_list args);

/* tstr_resize.c */
void* _tstr_str_resize(tstr_t *ts, tstr_len_t size);

/* tstr_string.c */
char* tstr_string(tstr_t *ts);

/* tstr_sprintf.c */
int tstr_sprintf(tstr_t *ts, const char *format, ...);
int _tstr_sprintf(tstr_t *ts, const char *format, va_list args);

/* tstr_copy.c */
tstr_t* tstr_copy(tstr_t *ts);

/* tstr_strcmp.c */
int tstr_strcmp(tstr_t *ts1, tstr_t *ts2);
int tstr_strncmp(tstr_t *ts1, tstr_t *ts2, size_t n);
int tstr_strcasecmp(tstr_t *ts1, tstr_t *ts2);
int tstr_strncasecmp(tstr_t *ts1, tstr_t *ts2, size_t n);

/* tstr_strreplace.c */
int tstr_strreplace(tstr_t *ts, const char *search, const char *replace);
int _tstr_strreplace(tstr_t *ts, const char *search, const char *replace);

/* tstr_chr.c */
int tstr_chr(tstr_t *ts, tstr_off_t offset);

#endif
