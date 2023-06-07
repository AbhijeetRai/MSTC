//Singly circular linked list

#include <stdio.h> 
#include <stdlib.h>
#include <assert.h>

typedef struct node {

    int data; 
    struct node* next;
}node;

typedef node* node_ptr; 
typedef node* head_ptr; 

head_ptr get_list();
node_ptr get_node(int data);
void insert_beg(head_ptr head, int data);
void generic_insert(node_ptr beg, node_ptr mid, node_ptr end);
void show_list(head_ptr head);
node_ptr get_last_node(head_ptr head);
void insert_end(head_ptr head, int data);
int insert_after(head_ptr list, int e_data, int data);
int insert_before(head_ptr list, int e_data, int data);
int search_data_node(head_ptr list, int data, node_ptr* ptr_to_node_ptr);
void destroy_list(head_ptr* ptr_to_head_ptr);
void generic_delete(node_ptr prev_node, node_ptr node);
int delete_data(head_ptr list, int data);
int get_length(head_ptr list);
int is_empty(head_ptr list);
int find_data(head_ptr list, int data);
int get_start(head_ptr list, int* data_ptr);
int get_end(head_ptr list, int* data_ptr);
int pop_start(head_ptr list, int* data_ptr);
int remove_start(head_ptr list);
int remove_end(head_ptr list); 

#define LIST_EMPTY          0
#define SUCCESS             1
#define DELETE_SUCCESS      1

int main(void) {

    head_ptr list = get_list();

    insert_end(list, 10);
    insert_end(list, 20);
    insert_end(list, 30);
    show_list(list);

    destroy_list(&list);
    assert(list == NULL);

    return 0;
}

head_ptr get_list() {
    
    head_ptr head = get_node(-1);
    head -> next = head;
    return head;
}

node_ptr get_node(int data) {

    node_ptr node = NULL;
    node = (node_ptr)calloc(1, sizeof(node));

    if(node == NULL) {
        printf("fatal: calloc: out of memory");
        exit(EXIT_FAILURE);
    }

    node -> data = data; 
    node -> next = NULL; 

    return node;
}

void insert_beg(head_ptr head, int data) {

    node_ptr node = get_node(data); 
    generic_insert(head, node, head -> next);
}

node_ptr get_last_node(head_ptr head) {

    node_ptr run = head -> next;

    while(run -> next -> data != -1) 
        run = run -> next;

    return run;
}

void insert_end(head_ptr head, int data) {

    generic_insert(get_last_node(head), get_node(data), head);
}

void generic_insert(node_ptr beg, node_ptr mid, node_ptr end) {

    beg -> next = mid;
    mid -> next = end;
}

void show_list(head_ptr head) {

    node_ptr run = head -> next; 

    while(run -> data != -1) {
        printf("%d ", run -> data); 
        run = run -> next;
    }
    printf("\n");
}

int search_data_node(head_ptr list, int data, node_ptr* ptr_to_node_ptr) {

    node_ptr run = list -> next; 
    int flag = 0;

    while(run -> data != -1) {
        if(run -> data == data) {
            flag = 1; 
            *ptr_to_node_ptr = run;
            break;
        }
        run = run -> next;
    }

    return flag;
}

int insert_after(head_ptr list, int e_data, int data) {

    node_ptr e_node = NULL;
    int result = search_data_node(list, e_data, &e_node);

    if(result != 0)
        generic_insert(e_node, get_node(data), e_node -> next);

    return result;
}

int insert_before(head_ptr list, int e_data, int data) {

    node_ptr e_node = NULL;
    int result = search_data_node(list, e_data, &e_node);

    if(result != 0) {
        
        node_ptr run = list;
        while(run -> next != e_node)
            run = run -> next;
        
        generic_insert(run, get_node(data), e_node);
    }

    return result;
}

void destroy_list(head_ptr* ptr_to_head_ptr) {

    head_ptr head = *ptr_to_head_ptr;
    node_ptr run = head -> next;
    node_ptr next_run = NULL;

    while(run != head) {
        next_run = run -> next;
        free(run);
        run = next_run;
    }

    free(head);
    *ptr_to_head_ptr = NULL;
}

void generic_delete(node_ptr prev_node, node_ptr node) {

    prev_node -> next = node -> next;
    free(node);
}

int delete_data(head_ptr list, int data) {

    node_ptr e_node = NULL;
    int result = search_data_node(list, data, &e_node);

    if(result) {
        node_ptr run = list;
        while(run -> next != e_node)
            run = run -> next;
        
        generic_delete(run, e_node);
    }

    return result;
}

int get_length(head_ptr list) {

    int length = 0;
    node_ptr run = list -> next;

    while(run != list) {
        length += 1;
        run = run -> next;
    }

    return length;
}

int is_empty(head_ptr list) {

    return (list == list -> next);
}

int find_data(head_ptr list, int data) {

    int flag = 0;
    node_ptr run = list -> next;

    while(run != list) {
        if(run -> data == data) {
            flag = 1;
            break;
        }
        run = run -> next;
    }
    return flag;
}

int get_start(head_ptr list, int* data_ptr) {

    if(list -> next == list)
        return LIST_EMPTY;

    *data_ptr = list -> next -> data;
    return SUCCESS;
}

int get_end(head_ptr list, int* data_ptr) {

    if(list -> next == list)
        return LIST_EMPTY;

    node_ptr last_node = get_last_node(list);
    *data_ptr = last_node -> data;

    return SUCCESS;
}

int pop_start(head_ptr list, int* data_ptr) {

    int result = get_start(list, data_ptr);

    if(result)
        generic_delete(list, list -> next);

    return result;
}

int pop_end(head_ptr list, int* data_ptr) {

    int result = get_end(list, data_ptr);

    if(result) {
        node_ptr last_node = get_last_node(list);
        
        node_ptr run = list;
        while(run -> next != last_node)
            run = run -> next;

        generic_delete(run, last_node);
    }
    return result;
}

int remove_start(head_ptr list) {

    if(list -> next==list) 
        return LIST_EMPTY;

    generic_delete(list, list -> next);
    return DELETE_SUCCESS;
}

int remove_end(head_ptr list) {

    if(list -> next==list) 
        return LIST_EMPTY;

    node_ptr last_node = get_last_node(list);
        
    node_ptr run = list;
    while(run -> next != last_node)
        run = run -> next;
    generic_delete(run, last_node);

    return DELETE_SUCCESS;
}

/**
 * Incorpoted yesterday's input
 * Implemented 22 routines(some generic) in 90 minutes. But made some mistakes and have questions
 * MISTAKE1: Iterated run to check if data is not equal -1, could have checked if it is list (comparison with address than data) 
 * MISTAKE2: Could have written a routine to fetch a node and its prev_node, have written only to fetch node 
 * 
 * QUESTION1: I am not able to recall use of xmalloc we used to write previously in generic functions 
*/