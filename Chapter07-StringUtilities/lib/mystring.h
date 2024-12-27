/* mystring library header file */
/* 26 December 2024 */
/* Dalton Ricker */

#define mystring_version "1.0"
#define mystring_version_major 1
#define mystring_version_minor 0

char* left(const char* input_string, const int length);
char* mid(const char* input_string, const int offset, const int length);
char* right(const char* input_string, const int length);
void strcaps(char* s);
char* strinsert(const char* original_string, char* insert_string, int offset);
void strlower(char* s);
char* strrev(const char* s);
int strsplit(const char* input_string, const int offset, char** side1, char** side2);
void strtabs(const char* s, const int tab);
void strupper(char* s);
int strwordcount(char* s);
