// Aluno: Gabriel Lando

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

HASH_NODE * Table[HASH_SIZE];

void HashInit(void) {
    int i;
    for (i = 0; i < HASH_SIZE; ++i)
        Table[i] = 0;
}

int HashAddress(char * text) {
    int i;
    int address = 1;
    for (i = 0; i < strlen(text); ++i)
        address = (address * text[i]) % HASH_SIZE + 1;
    return address - 1;
}

HASH_NODE * HashInsert(char * text, int type) {
  HASH_NODE * newnode;
  int address = HashAddress(text);

  if ((newnode = HashFind(text)) != 0)
    return newnode;

  newnode = (HASH_NODE * ) calloc(1, sizeof(HASH_NODE));
  newnode->type = type;
  newnode->text = (char * ) calloc(strlen(text) + 1, sizeof(char));
  strcpy(newnode -> text, text);
  newnode->next = Table[address];
  Table[address] = newnode;
  return newnode;
}

HASH_NODE * HashFind(char * text) {
    HASH_NODE * node;
    int address = HashAddress(text);

    for (node = Table[address]; node; node = node->next)
        if (!strcmp(text, node -> text))
            return node;
    return 0;
}

void HashPrint(void) {
    HASH_NODE * node;

    for (int i = 0; i < HASH_SIZE; ++i){
        node = Table[i];
        if(node == NULL) continue;

        do {
            fprintf(stderr, "Table [%3d]: [Type %d] %s \n", i, node->type, node->text);
            node = node->next;
        } while(node != NULL);
    }
}