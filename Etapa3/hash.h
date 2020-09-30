// Aluno: Gabriel Lando

#ifndef __HASH__
#define __HASH__

#define HASH_SIZE 997
#define STRING_SIZE 100

typedef struct hash_node {
    int type;
    char * text;
    struct hash_node * next;
} HASH_NODE;

void HashInit(void);
int HashAddress(char * text);
HASH_NODE * HashInsert(char * text, int type);
HASH_NODE * HashFind(char * text);
void HashPrint(void);

#endif