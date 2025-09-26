#include "cdotenv.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int8_t
cdotenv_load_from_file (struct cdotenv *self, const char *filename)
{
  FILE *f = fopen (filename, "r");
  if (!f)
    {
      perror ("cdotenv_load_from_file");
      return -1;
    }

  fseek (f, 0, SEEK_END);
  size_t size = ftell (f);
  fseek (f, 0, SEEK_SET);

  char *src = malloc ((size + 1) * sizeof (char));
  if (src == NULL)
    {
      fclose (f);
      perror ("cdotenv_load_from_file");
      return -1;
    }

  size_t bytes = fread (src, sizeof (char), size, f);
  if (bytes < 0)
    {
      free (src);
      fclose (f);
      perror ("cdotenv_load_from_file");
      return -1;
    }
  src[bytes] = '\0';

  if (src == NULL)
    {
      free (src);
      fclose (f);
      perror ("cdotenv_load_from_file");
      return -1;
    }

  int8_t result = cdotenv_load_from_src (self, src);
  if (result != 0)
    {
      free (src);
      fclose (f);
      return result;
    }

  free (src);
  fclose (f);
  return 0;
}

int8_t
cdotenv_load_from_src (struct cdotenv *self, const char *src)
{
  char *token = strtok ((char *)src, "\n");

  size_t capacity = 8;
  size_t i = 0;

  self->vars = malloc (capacity * sizeof (char *));

  while (token != NULL)
    {
      char k[K_MAX];
      char v[V_MAX];
      if (sscanf (token, "%49[^=]=%49s", k, v) == 2)
        {
          if (i + 2 > capacity)
            {
              capacity *= 2;
              self->vars = realloc (self->vars, capacity * sizeof (char *));
            }
          self->vars[i++] = strdup (k);
          self->vars[i++] = strdup (v);
        }
      token = strtok (NULL, "\n");
    }
  self->count = i;
  return 0;
}

int8_t
cdotenv_get (struct cdotenv *self, char **dest, const char *name)
{
  size_t i;
  for (i = 0; i < self->count; ++i)
    {
      if (strcmp (self->vars[i], name) == 0)
        {
          *dest = self->vars[++i];
          break;
        }
    }
  return 0;
}

void
cdotenv_clean (struct cdotenv *self)
{
  size_t i;
  for (i = 0; i < self->count; ++i)
    {
      free (self->vars[i]);
    }
  free (self->vars);
  self->count = 0;
}