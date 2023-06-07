#include <stdio.h> 
#include <stdlib.h> 

struct node {
    struct node* next;
    int data; 
    struct node* previous;
};

typedef struct node node_t; 
typedef struct node head_t;

int main(void) {

    head_t* ptr; 
    node_t* ptr;
    exit(EXIT_SUCCESS);
}