#include <stdio.h>
#include <stdlib.h>

struct LinkedList {
    int data;
    struct LinkedList* next;
};

typedef struct LinkedList* node;

node createNode(int value) {
    node n;
    n = (node)malloc(sizeof(struct LinkedList));
    n->data = value;
    n->next = NULL;
    return n;
}

void addNode(node* head, int value) {
    node tmp;
    node n;

    tmp = createNode(value);

    if (*head == NULL) {
        *head = tmp;
        return;
    }

    n = *head;
    while (n->next) {
        n = n->next;
    }
    n->next = tmp;
}

int main(void) {
    node head = NULL;

    for (size_t i = 2; i < 16; i += 2) {
        addNode(&head, i);
    }

    /* traverse the list */
    node n = head;
    while (n->next != NULL) {
        printf("- %d - ", n->data);
        n = n->next;
    }

    return EXIT_SUCCESS;
}