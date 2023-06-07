#include <stdio.h> 
#include <stdlib.h> 

typedef struct node {
    
    struct node* previous;
    int data;
    struct node* next;
}node; 

typedef node* node_t; 
typedef node* head_t;

head_t get_list();
node_t get_node(int data);
void show_list(head_t list);
void insert_beg(head_t list, int data); 
void insert_end(head_t list, int data);
void generic_insert(node_t beg, node_t mid, node_t end); 

int main(void) {

    head_t list = get_list();
    
    insert_beg(list, 20);
    insert_beg(list, 10);
    insert_end(list, 30);
    insert_end(list, 40);
    show_list(list);

    return 0;
}

head_t get_list() {

    node_t node = get_node(-1);
    node -> previous = node; 
    node -> next = node; 

    return node;
}

node_t get_node(int data) {

    node_t node = NULL;
    node = (node_t)calloc(1, sizeof(node));

    if(node == NULL) {
        printf("fatal: calloc: out of memory"); 
        exit(EXIT_FAILURE);
    }

    node -> previous = NULL;
    node -> data = data; 
    node -> next = NULL;

    return node;
}

void show_list(head_t list) {

    node_t p_run = list -> next;

    while(p_run -> data != -1) {
        printf("%d\n", p_run -> data); 
        p_run = p_run -> next;
    }
}

void insert_beg(head_t list, int data) {

    node_t node = get_node(data);
    generic_insert(list, node, list -> next);
}

void generic_insert(node_t beg, node_t mid, node_t end) {

    mid -> next = end; 
    mid -> previous = beg;

    end -> previous = mid;
    beg -> next = mid;
}

void insert_end(head_t list, int data) {

    node_t node = get_node(data);
    generic_insert(list -> previous, node, list);
}

/*
 * Reminder: If I am not mistaken, today is mstc session 100
 * Previously, You asked us to remind you say some appreciative words
 * xd, lol, (humor)
*/