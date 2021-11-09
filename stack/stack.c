#include <stdio.h>
#include <stdlib.h>

struct Element {
    int data;
    struct Element* next;
};

typedef struct Element* element;
element top;

element createElement(int value) {
    element e;
    e = (element)malloc(sizeof(struct Element));
    if (e) {
        e->data = value;
        e->next = NULL;
    }
    return e;
}

void push(int value) {
    element e = createElement(value);
    if (top != NULL)
        e->next = top;
    top = e;
}

element pop(void) {
    element e = top;
    if (e != NULL) {
        top = top->next;
        e->next = NULL;
    }
    return e;
}

element peek(void) {
    return top;
}

void stackInit(void) {
    top = NULL;
}

/**
 *
 *  Test it
 *
 * */
int main(void) {
    stackInit();

    for (int i = 10; i <= 15; i++) {
        push(i);
        printf("push '%d'\n", i);
    }

    element e;  // = top;
    printf("\n");

    while (1) {
        e = peek();
        if (e == NULL) {
            printf("\nempty stack\n");
            break;
        }

        printf("peek '%d'\n", e->data);

        e = pop();
        printf("pop  '%d'\n", e->data);
    }
    return EXIT_SUCCESS;
}