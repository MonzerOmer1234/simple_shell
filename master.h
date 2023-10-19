#ifndef MASTER__H
#define MASTER__H

#define UNUSED(x) (void)(x)

#define SPLT_ERR -1
#define END_OF_FILE -2

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

extern char **environ;
extern char *program_name;
extern int history;
extern int status;
extern char *prompt;
extern int prompt_size;

/**
 * struct Node - A new struct type defining a node in a linked list.
 *
 * @dir: A directory path.
 * @next: A pointer to another struct Node.
 */
struct Node
{
	char *dir;
	struct Node *next;
};
typedef struct Node Node;

/**
 * struct Builtin - A new struct type defining a builtin command.
 *
 * @name: The name of the builtin command.
 * @func: A function pointer to the builtin command's function.
 */
struct Builtin
{
	char *name;
	int (*func)(char **args);
};
typedef struct Builtin Builtin;


/* Main */
int execute(char **args);
int get_args(char ***args);
int run_args(char ***args);
void free_args(char **args);


/* Signal handlers */
void handle_ctrl_c(int signum);


/* String helpers */
int _strlen(const char *s);
char *_strcat(char *dest, const char *src);
char *_strncat(char *dest, const char *src, int n);
int _strcmp(const char *s1, const char *s2);
int _strncmp(const char *s1, const char *s2, int n);

char *_strchr(char *s, char c);
char *_strstr(char *haystack, char *needle);
char *_strcpy(char *dest, const char *src);
char *_strncpy(char *dest, const char *src, int n);
char *_strdup(char *str);

char **strsplit(char *str, char *delimiter);


/* Helpers */
int num_len(int n);
char *int_to_str(int n);
int str_to_int(char *str);


/* Memory */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);


/* Environment */
char **_getenv(char *name);
/*int _unsetenv(char *name);*/


/* Linked list */
Node *add_node_end(Node **head, char *dir);
void free_list(Node *head);
Node *build_path_dirs(char *paths);


/* Get Location */
char *get_location(char *command);


/* Errors */
int write_error(char **args, int err);

char *error_126(char **args);
char *error_127(char **args);
char *error_2(char **args);
char *error_env(char **args);


/* Builtins */
int (*get_builtin(char *command))(char **args);
int fshell_exit(char **args);
int fshell_env(char **args);
int fshell_setenv(char **args);


#endif
