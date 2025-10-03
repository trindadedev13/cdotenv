#include <stdlib.h>

#include <cdotenv.h>

int
main (void)
{
  /** load env */
  struct cdotenv env = { 0 };
  cdotenv_load_from_file (&env, ".env");

  /** get API_KEY */
  char *API_KEY;
  cdotenv_get (&env, &API_KEY, "API_KEY");
  printf ("API_KEY=%s\n", API_KEY);

  /** get TOKEN */
  char *TOKEN;
  cdotenv_get (&env, &TOKEN, "TOKEN");
  printf ("TOKEN=%s\n", TOKEN);

  /** cleanup all variables */
  cdotenv_clean (&env);

  return 0;
}
