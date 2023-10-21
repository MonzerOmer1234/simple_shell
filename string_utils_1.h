#ifndef STRING_UTILS_I
#define STRING_UTILS_I

int length(const char* s);

char* concatenate(char* dest, const char* src);

char* concatenateUpTo(char* dest, const char* src, int n);

int compare(const char* s1, const char* s2);

int compareUpTo(const char* s1, const char* s2, int n);

#endif

