#ifndef ERRORS
#define ERRORS

char* errorPermissionDenied(char** args);

char* errorCommandNotFound(char** args);

char* errorIllegalNumberOfArguments(char** args);

char* errorEnvironmentAddRemoveFailed(char** args);

int printErrorMessage(char** args, int err);

#endif

