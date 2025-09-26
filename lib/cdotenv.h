#ifndef __cdotenv_h__
#define __cdotenv_h__

#include <stdint.h>

#ifndef K_MAX
#define K_MAX 128
#endif
#ifndef V_MAX
#define V_MAX 128
#endif

struct cdotenv
{
  char **vars;
  size_t count;
};

/** Loads the environment variables from filename */
int8_t cdotenv_load_from_file (struct cdotenv *, const char *);

/** Loads the environment variables from src code */
int8_t cdotenv_load_from_src (struct cdotenv *, const char *);

/** Returns the environment variable from name */
int8_t cdotenv_get (struct cdotenv *, char **, const char *);

/** Cleanup resources used in the env */
void cdotenv_clean (struct cdotenv *);

#endif