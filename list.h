#ifndef _LIST_H_
#define _LIST_H_

#define CREATETABLE 1
#define ADDINBEGIN 2
#define ADDINEND 3
#define ADDINAFTER 4
#define DELETE 5
#define PRINT 7
#define FREE 8
#define REVERSELIST 9
#define CHECKLOOP 11
#define EXIT 0





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


struct Node* v(struct List *list, int value){
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

void interface(void){
        int n = 1;
        printf("1.  Create list\n");
        printf("2.  Insert to the beginning\n");
        printf("3.  Insert to the end\n");
        printf("4.  Insert after index\n");
        printf("5.  Delete by value\n");
        printf("6.  Delete by index\n");
        printf("7.  Print all nodes\n");
        printf("8.  Free list\n");
        printf("9.  Reverse list\n");
        printf("10. List loop check\n");
        printf("0. Exit\n\n\n");
        unsigned int command;
        int value;
        size_t index;
        LinkedList * list = NULL;
        int x;
        while (1) {
                printf("Enter command:\n");
                x = scanf("%d", &command);
                if (x && command >= 0 && command <= 12) {
                        switch (command)
                        {
                        case CREATE:
                                list = createList(n);
                        case EXIT:
                                eraseList(list);
                                free(list);
                                exit(0);
                                break;
                        default:
                                if (list) {
                                        switch (command)
                                        {
                                        case ADDINBEGIN:
                                                printf("Enter value:\n");
                                                scanf("%d", &value);
                                                if (appendToBeginingNode(list, value)) {
                                                        printf("The node was successfully added to the beginning.\n");
                                                }
                                                else {
                                                        printf("The node wasn't inserted in the beginning.\n");
                                                }
                                                break;


                                        case ADDINEND:
                                                printf("Enter value:\n");
                                                scanf("%d", &value);
                                                if (appendToEndNode(list, value)) {
                                                        printf("The node was successfully added to the end.\n");
                                                }
                                                else {
                                                        printf("The node wasn't inserted in the end.\n");
                                                }
                                                break;


                                        case INAFTER: {
                                                printf("Enter index:\n");
                                                scanf("%zu", &index);
                                                printf("Enter value:\n");
                                                scanf("%d", &value);
                                                if (appendAfter(list, after, value)) {
                                                        printf("The node was successfully inserted after %zu element.\n", index);
                                                }
                                                else {
                                                        printf("The node wasn't added to the end.\n");
                                                }
                                                break;
                                        }


                                        case DELETE:
                                                deleteElement(list, element);
                                                break;


                                        case PRINT:
                                                printLinkedList(list);
                                                break;


                                        case FREE:
                                                freeLinkedList(list);
                                                printf("List was freed.\n");
                                                break;


                                        case REVERSELIST:
                                                if (list->head) {
                                                        reverseList(list);
                                                        printf("List was reversed.\n");
                                                        break;
                                                }
                                                else {
                                                        printf("Nothing to reverse.\n");
                                                }


                                        case CHECKLOOP:
                                                if (list->head) {
                                                        printf("Enter index of beginnig of loop\n");
                                                        scanf("%zu", &index);
                                                        if (loopCheckList(list)) {
                                                                printf("Loop was created in the node with index %zu.\n", index);
                                                        }
                                                        else {
                                                                printf("Loop wasn't created.\n");
                                                        }
                                                }
                                                else {
                                                        printf("Nothing to loop");
                                                }
                                                break;


                                }
                                else {
                                        printf("You can't interact with the list if it doesn't exist. Create it for beginning.\n");
                                }
                        }
                }
                else {
                        while ((x = getchar()) != EOF && x != '\n');
                        printf("Incorrect input.\n");
                }
                printf("\n\n");
        }
}


}

#endif
