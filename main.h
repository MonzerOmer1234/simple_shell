#ifndef MAIN_H
#define MAIN_H





#define UNUSABLE(y) (void)(y)

#define SPLT_ERROR -1



#define END_OF_THE_FILE -2

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>





extern char **env;
extern char *prog_name;
extern int his;
extern int stat;
extern char *promp;
extern int promp_size;

/**
 * struct Nod- A struct that defines a new node inthe linked list
 
 * @dr: A directory path abbreviation name.
 *
 *
 *
 *
 *
 * @next: A pointer to another struct Node.
 */
struct Node
{
	char *dir;
	struct Node *next;
};
typedef struct No

/**
 *
 *
 *
 *
 *
 *
 * struct Builtinside - A struct that defines builtinside command.
 *
 *
 *
 *
 * @n:  The name of the builtinside command.
 *
 *
 *
 *
 *
 *
 *
 * @function: A function pointer to the builtinside  command's function.
 */
struct Builtinside
{
	char *n;
	int (*function)(char **arguments);
};
typedef struct Builtinside Builtinside ;


/* main functions */




int execute_arguments(char **arguments);


void free_arguments (char ***arguments);


int run_arguments(char ***arguments);


void get_arguments(char ***arguments);


/* functions to handle signals */






void handle_copy(int signumber);


/* helpers for string */







char *_sconcatenate(char *destination, const char *source);


char *_strconcatenate(char *destination, const char *source, int x);


int _scompare(const char *str1, const char *str2);


int _strcmp(const char *str1, const char *str2, int x);


int _stringlength(const char *str);


char *_stringchar(char *str, char chr);


char *_stringcopy(char *destination , const char *source);


char *_strcopy(char *destination , const char *src , int x);


char *_stringstring(char *hystack, char *need);


char **stringsplit (char *s , char *delim);


char *_stringdup(char *s);


/* helpers functions */


int number_length(int x);

char trans_str_to_int( char *s);


char *integer_to_string(int x);





/* Memory functions  */


void *_realoc(void *potr, unsigned int past_s, unsigned int new_s);


/* Environment functions */


char **_getenviro(char *n);



/*int _unsetenviro(char *n);*/


/* Linked list functions */


Nod *add_node_in_end(Nod **h, char *dr);


void free_array(Nod *h);


Nod *build_path_for_drs(char *pths);


/* evaluate Location */



char *get_loc(char *cmd);


/* Errors functions */
int write_err(char **arguments, int e);


char *err_126(char **arguments);


char *err_127(char **arguments);

char *err_env (char **arguments);


char *err_2(char **arguments);


/* Builtins functions */

int fsh_setenviroment(char **args);

int fsh_enviroment(char **arguments);

int fsh_exit(char **arguments);


int (*get_builtins(char *cmd))(char **arguments);



#endif
