#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int hash(char *str){
        int i;
        int h;
        i = 0;
        h = 0;
        for (i == 0; i < strlen(str); i++) {
                h = ( h + str[i] * i) % 10000;
        }
        return h;
}

struct Node {
        int value;
        char *key;
        struct Node *next;
};

struct Pntr {
        int len;
        struct Node *first;
};


struct Pntr* createTable(int size){
        struct Pntr *pntr = malloc(sizeof(struct Pntr) * size);
        return pntr;
}

void appendNode(struct Pntr *a, char *key, int value){
        struct Node *Nnode = malloc(sizeof(struct Node));
        Nnode->key = key;
        Nnode->value = value;
        if (a[hash(key)].first) {
                struct Node *node = a[hash(key)].first;
                while (1) {
                        if (node->next) {
                                node = node->next;
                        }
                        else{
                                node->next = Nnode;
                                break;
                        }
                }


        }
        else{
                a[hash(key)].first = Nnode;

        }
}

int getValue(struct Pntr *a, char *key){


}

int main() {
        struct Pntr *a = createTable(100);
        char str[256];
        scanf("%s", str);
        printf("%d\n", hash(str));
        appendNode(a, "ZZ", 12);
        appendNode(a, "ZZ", 12);
        appendNode(a, "ZZ", 12);

        return 0;
}
