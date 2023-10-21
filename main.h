#ifndef MAIN_H
#define MAIN_H

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

#include "builtins.h"
#include "environment.h"
#include "errors.h"
#include "handlers.h"
#include "list.h"
#include "path.h"
#include "string_utils.h"
#include "utils.h"

extern char** environ;
extern char* program_name;
extern int history;
extern int status;
extern char* prompt;
extern int prompt_size;

#define UNUSED(x) (void)(x)

#define SPLIT_ERROR -1
#define END_OF_FILE -2

int execCommand(char** args);

int getArgs(char*** args);

int runArgs(char*** args);

void deallocateArgs(char** args);


#endif

