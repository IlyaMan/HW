#ifndef _LIST_H_
#define _LIST_H_

#include <stdio.h>
#include <stdlib.h>


#typedef struct  {
int value;
struct Node *next;
} Node;

#typedef struct {
struct Node *first;
} List;


struct Node* createNode(int value){
        struct Node *node = malloc(sizeof(struct Node));
        node->value = value;
        node->next = 0;
}

struct List* createList(int value) {
        struct List *list = malloc(sizeof(struct List));
        list->first = createNode(value);
}


struct Node* appendToBeginingNode(struct List *list, int value){
        struct Node *node = malloc(sizeof(struct Node));
        node->value = value;
        node->next = list->first;
        list->first = node;
}

struct Node* appendToEndNode(struct List *list, int value){
        struct Node *node = list->first;
        while (1) {
                if (node->next) {
                        node = node->next;
                }
                else{
                        struct Node *newNode = createNode(value);
                        node->next = newNode;
                        break;
                }
        }
}

struct Node* appendAfter(struct List *list, int after,int value){
        struct Node *node = list->first;
        while (1) {
                if (node->value == after) {
                        struct Node *newNode = createNode(value);
                        newNode->next = node->next;
                        node->next = newNode;
                        break;
                }
                if (node->next) {
                        node = node->next;
                }
                else{
                        break;
                }
        }
}



void deleteElement(struct List *list, int element){
        struct Node *node = list->first;
        while (1) {
                if (node->next->value == element) {
                        struct Node *tmp = node->next->next;
                        free(node->next);
                        node->next = tmp;
                        break;
                }
                if (node->next) {
                        node = node->next;
                }
                else{
                        break;
                }
        }

}

void eraseList(struct List *list){
        struct Node *node = list->first;
        while (1) {
                struct Node *tmp = node->next;
                free(node);
                if (tmp) {
                        node = tmp;
                }
                else{
                        break;
                }
        }
        list->first = 0;

}


void printList(struct List *list){
        if (list->first) {
                struct Node *node = list->first;
                while (1) {
                        printf("%d ", node->value);
                        if (node->next) {
                                node = node->next;
                        }
                        else{
                                break;
                        }
                }
                printf("\n");
        }
        else{
                printf("LIST DOESN'T EXIST! ");
        }

}

void reverseList(struct List *list){
        struct Node *previous = list->first;
        struct Node *node = list->first->next;
        list->first->next = 0;

        while (1) {
                struct Node *tmp = node->next;

                node->next = previous;
                previous = node;
                list->first = node;
                if (tmp) {
                        node = tmp;
                }
                else{
                        break;
                }
        }
}

void loopReverseList(struct List *list){
        struct Node *previous = list->first;
        struct Node *node = list->first->next;

        while (1) {
                struct Node *tmp = node->next;

                node->next = previous;
                previous = node;
                list->first = node;
                if (tmp) {
                        node = tmp;
                }
                else{
                        break;
                }
        }
}


int loopCheckList(struct List *list){
        struct Node *ptr1 = list->first;
        struct Node *ptr2 = list->first;
        while (1) {
                if ((ptr1->next == 0) || (ptr2->next->next == 0)) {
                        return 0;
                }
                ptr1 = ptr1->next;
                ptr2 = ptr2->next->next;
                if (ptr1 == ptr2) {
                        return 1;
                }


        }


}

#endif
