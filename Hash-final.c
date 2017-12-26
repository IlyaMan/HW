#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int size;

int hash(char *str){
        int i;
        int h;
        i = 0;
        h = 0;
        for (i = 0; i <= strlen(str) - 1; i++) {
                h = ( h + str[i] * (i+1)) % size;
        }
        return h;
}

struct Node {
        int value;
        char key[256];
        struct Node *next;
};

struct Pntr {
        int len;
        struct Node *first;
};


struct Pntr* createTable(int size){
        struct Pntr *pntr = malloc(sizeof(struct Pntr) * size);
        if (!pntr) {
                printf("No memory!");
                exit(0);
        }
        return pntr;
}

void appendNode(struct Pntr *a, char *key, int value){
        struct Node *Nnode = malloc(sizeof(struct Node));
        if (!Nnode) {
                printf("No memory!");
                exit(0);
        }
        strcpy(Nnode->key, key);
        Nnode->value = value;
        Nnode->next = 0;
        if (a[hash(key)].first) {
                struct Node *node = a[hash(key)].first;
                while (1) {
                        if (!strcmp(node->key, key)) {
                                node->value = Nnode->value;
                                break;
                        }
                        if (node->next) {
                                node = node->next;
                        }
                        else{
                                node->next = Nnode;
                                a[hash(key)].len += 1;
                                break;
                        }
                }


        }
        else{
                a[hash(key)].len += 1;
                a[hash(key)].first = Nnode;


        }
}

int getValue(struct Pntr *a, char *key){
        if (a[hash(key)].first)
        {
                struct Node *node = a[hash(key)].first;
                while (1) {
                        if (!strcmp(node->key, key)) {
                                return node->value;
                        }
                        else {
                                if (node->next) {
                                        node = node->next;
                                }
                                else{
                                        break;
                                }
                        }
                }
        }
        else {
                return 0;
        }
}

void showAll(struct Pntr *a){
        int max = 0;
        char word[260];
        int i = 0;
        while (i < size) {
                if (a[i].first) {
                        printf("%s : %d\n", a[i].first->key, a[i].first->value);
                        struct Node *node = a[i].first;
                        while(1) {
                                if ((node->value > max)) {
                                        max = node->value;
                                        strcpy(word, node->key);
                                }

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
        printf("MAX: %s : %d\n", word, max);
}

void erase(struct Pntr *a){
        int i = 0;
        while(i < size) {
                if (a[i].first) {
                        struct Node *node = a[i].first;
                        a[i].first = 0;
                        while (1)
                        {
                                struct Node *tmp = node;
                                free (node);
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
        int i = 0;
        while (i < size) {
                if (a[i].len > 1) {sum += a[i].len;}
                i++;
        }
        printf("Кол-во коллизий: %d\n", sum);
}


int main(void) {
        size = 10000;
        struct Pntr *a = createTable(size);
        FILE *fp;
        fp = fopen("book1.txt", "r");
        char *str = (char *)calloc(256, sizeof(char));
        if (!str) {
                printf("No memory!");
                exit(0);
        }
        char b;
        int i = 0;
        while (1) {
                b = fgetc(fp);
                if ( feof(fp) ) break;
                if (isalpha(b)) {
                        str[i] = b;
                        i++;
                }
                else {
                        int p = getValue(a, str);
                        appendNode(a, str, p + 1);
                        for (int j = 1; j < 256; j++) {
                                str[j] = 0;
                        }
                        i = 0;
                }
        }

        showAll(a);
        stats(a);

        return 0;
}
