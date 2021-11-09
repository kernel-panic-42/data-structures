#include <stdio.h>
#include <stdlib.h>

struct Element {
    int data;
    struct Element* next;
};

typedef struct Element* element;
element head, tail;

element createElement(int value) {
    element e;
    e = (element)malloc(sizeof(struct Element));
    if (e) {
        e->data = value;
        e->next = NULL;
    }
    return e;
}

void enqueue(int value) {
    element e = createElement(value);
    if (tail == NULL)
        head = e;
    else
        tail->next = e;
    tail = e;
}

element dequeue(void) {
    element e = head;
    if (e != NULL) {
        head = head->next;
        e->next = NULL;
    }
    return e;
}

element peek(void) {
    return head;
}

void queueInit(void) {
    head = NULL;
    tail = NULL;
}

/**
 *
 *  Test it
 *
 * */
int main(void) {
    queueInit();

    for (int i = 10; i <= 15; i++) {
        enqueue(i);
        printf("enqueue '%d'\n", i);
    }
    printf("\n");

    element e;

    while (1) {
        e = peek();
        if (e == NULL) {
            printf("\nempty queue\n");
            break;
        }

        printf("peek '%d'\n", e->data);

        e = dequeue();
        printf("dequeue  '%d'\n", e->data);
    }
    return EXIT_SUCCESS;
}