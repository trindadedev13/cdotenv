# Cdotenv
- Simple library for C Dot Env

## Usage
 - Load  
 ```c
  int8_t status;

  struct cdotenv env = { 0 };

  /** load from .env file */
  status = cdotenv_load_from_file (&env, ".env");
  /** if the status is not 0, so error. */

  /** load from .env src */
  status = cdotenv_load_from_src (&env, "/** src here */");
  /** if the status is not 0, so error. */
 ```

 - Get  
 ```c
  struct cdotenv env = { 0 };
  /** ... */
  int8_t status;
  char *API_KEY;
  status = cdotenv_get (&env, &API_KEY, "API_KEY");
  /** if the status is not 0, so error. */
 ```

  - Clean  
  ```c
  struct cdotenv env = { 0 };
  /** ... */
  cdotenv_clean (&env);
  ```