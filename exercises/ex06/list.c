/*
 * Author: Sarah Walters
 * Based on Exercises in C scaffolding, copyright Allen Downey
 *
 * Linked list implementation
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} Node;


/* Makes a new node structure.
 *
 * val: value to store in the node.
 * next: pointer to the next node
 *
 * returns: pointer to a new node
 */
Node *make_node(int val, Node *next) {
    Node *node = malloc(sizeof(Node));
    node->val = val;
    node->next = next;
    return node;
}


/* Prints the values in a list.
 *
 * list: pointer to pointer to Node
 */
void print_list(Node **list) {
    Node *current = *list;

    printf("[ ");
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("]\n");
}


/* Removes and returns the first element of a list.
 *
 * list: pointer to pointer to Node
 *
 * returns: int or -1 if the list is empty
 */
int pop(Node **list) {
    Node *head = *list;

    // Handle thes empty list case
    if (head == NULL) {
        return -1;
    }

    *list = head->next;
    return head->val;
}


/* Adds a new element to the beginning of the list.
 *
 * list: pointer to pointer to Node
 * val: value to add
 */
void push(Node **list, int val) {
    Node *new_head = make_node(val, NULL);
    new_head->next = *list;
    *list = new_head;
}


/* Removes the first element with the given value
 *
 * Frees the removed node.
 *
 * list: pointer to pointer to Node
 * val: value to remove
 *
 * returns: number of nodes removed
 */
int remove_by_value(Node **list, int val) {
    Node *previous;
    Node *current = *list;

    // Handle the empty list case
    if (current == NULL) {
        return 0;
    }

    // Check the first node
    if (current->val == val) {
        *list = current->next;
        return 1;
    }

    // Check the middle of the list
    while (current->next != NULL) {
        if (current->next->val == val) {
            current->next = current->next->next;
            return 1;
        }
        previous = current;
        current = current->next;
    }

    // Check the last node
    if (current->val == val) {
        if (previous != NULL) {
            previous->next = NULL;
        } else {
            *list = NULL;
        }
    }

    return 0;
}


/* Reverses the elements of the list.
 *
 * Does not allocate or free nodes.
 *
 * list: pointer to pointer to Node
 */
void reverse(Node **list) {
    Node *previous = NULL;
    Node *current = *list;
    Node *temp;

    // Handle the empty and single-element list cases
    if (current == NULL || current->next == NULL) {
        return;
    }

    while (current != NULL) {
        // save "next" to be the new current
        temp = current->next;

        // point current's next backwards
        current->next = previous;

        // update running pointers
        previous = current;
        current = temp;
    }

    // update list pointer
    *list = previous;
}

int main() {
    Node *head = make_node(1, NULL);
    head->next = make_node(2, NULL);
    head->next->next = make_node(3, NULL);
    head->next->next->next = make_node(4, NULL);

    Node **list = &head;
    print_list(list);

    int retval = pop(list);
    print_list(list);

    push(list, retval+10);
    print_list(list);

    remove_by_value(list, 3);
    print_list(list);

    remove_by_value(list, 7);
    print_list(list);

    reverse(list);
    print_list(list);
}
