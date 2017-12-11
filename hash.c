#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int size;

int hash(char *str){
        int i;
        int h;
        i = 0;
        h = 0;
        for (i = 0; i < strlen(str); i++) {
                h = ( h + str[i] * i) % size;
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
        Nnode->next = 0;
        a[hash(key)].len += 1;
        if (a[hash(key)].first) {
                struct Node *node = a[hash(key)].first;
                while (1) {
                        if (node->key == key) {
                                node->value = Nnode->value;
                        }
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
        struct Node *node = a[hash(key)].first;
        while (1) {
                if (node->key == key) {
                        return node->value;
                        break;
                }
                else{
                        if (node->next) {
                                node = node->next;
                        }
                }
        }
}

void showAll(struct Pntr *a){
        int i = 0;
        while(i < size) {
                if (a[i].first) {
                        struct Node *node = a[i].first;
                        while(1) {
                                printf("%s : ", node->key);
                                printf("%d\n", node->value);
                                if (node->next) {
                                        node = node->next;
                                }
                                else{
                                        break;
                                }

                        }

                }
                i++;
        }
}

void erase(struct Pntr *a){
        int i = 0;
        while(i < size) {
                if (a[i].first) {
                        while (1)
                        {
                                struct Node *node = a[i].first;
                                struct Node *tmp = node;
                                free (node);
                                a[i].first = 0;
                                node = tmp;
                                if (node->next) {
                                        node = node->next;
                                }
                                else {
                                        break;
                                }
                        }
                }
                i++;
        }
}

void stats(struct Pntr *a){
  int sum = 0; 
}


int main(void) {
        size = 1000;
        struct Pntr *a = createTable(size);
        char str[256];
        appendNode(a, "ZZ", 11);
        appendNode(a, "Zzzz", 121);
        showAll(a);
        erase(a);
        showAll(a);
        return 0;
}
