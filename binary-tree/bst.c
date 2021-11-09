
/***
 *
 *
 * Generate a Balanced Sorted Tree from a sorted array.  Top Down
 *
 *
 *
 *
 * */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

typedef struct Node* node;

node newNode(int value) {
    node n = (node)malloc(sizeof(struct Node));
    if (n != NULL) {
        n->data = value;
        n->left = NULL;
        n->right = NULL;
        return n;
    }
    return NULL;
}

bool search(node root, int value) {
    if (root == NULL)
        return false;

    if (root->data == value)
        return true;

    if (root->data < value)
        return search(root->left, value);
    else
        return search(root->right, value);
}

node buildTopDown(int* array, int lr, int rr) {
    if (lr > rr)
        return NULL;

    int mid = (lr + rr) / 2;
    node rt = newNode(array[mid]);

    rt->left = buildTopDown(array, lr, mid - 1);
    rt->right = buildTopDown(array, mid + 1, rr);

    return rt;
}

int main(void) {
    int array[] = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29,
                   31, 37, 41, 43, 47, 53, 59, 61, 67, 71};

    int len = 20;  // sizeof(array) / sizeof(int);
    node root;
    root = buildTopDown(array, 0, len - 1);

    printf("value 53 found: %s\n", search(root, 53) == true ? "true" : "false");
    printf("value 69 found: %s\n", search(root, 69) == true ? "true" : "false");

    return EXIT_SUCCESS;
}