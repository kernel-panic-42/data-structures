
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

    if (value < root->data)
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

/***
 *
 * Test it
 *
 *
 * */
int main(void) {
    int array[] = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29,
                   31, 37, 41, 43, 47, 53, 59, 61, 67, 71};

    int len = sizeof(array) / (sizeof(array[0]));

    node root;
    root = buildTopDown(array, 0, len - 1);

    printf("value 53 found: %s\n", search(root, 53) ? "true" : "false");
    printf("value 47 found: %s\n", search(root, 47) ? "true" : "false");
    printf("value 69 found: %s\n", search(root, 69) ? "true" : "false");
    printf("value 2 found: %s\n", search(root, 2) ? "true" : "false");
    printf("value 71 found: %s\n", search(root, 71) ? "true" : "false");
    printf("value 73 found: %s\n", search(root, 73) ? "true" : "false");
    printf("value 1 found: %s\n", search(root, 1) ? "true" : "false");

    return EXIT_SUCCESS;
}