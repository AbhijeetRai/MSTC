//Doubly linked list
#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h>

typedef struct node {

    struct node* previous; 
    int data; 
    struct node* next;
}node;

typedef node* node_t; 
typedef node* head_t;

#define NO_SUCH_DATA    0
#define INSERT_SUCCESS  1
#define LIST_EMPTY      0 
#define SUCCESS         1
#define DELETE_SUCCESS  1

head_t get_list(); 
node_t get_node(int data);
void insert_beg(head_t list, int data);
void generic_insert(node_t beg, node_t mid, node_t end);
void show_list(head_t list);
void insert_end(head_t list, int data);
int insert_after(head_t list, int e_data, int data);
int insert_before(head_t list, int e_data, int data);
void destroy_list(head_t* head_ptr);
int remove_data(head_t list, int data);
void generic_delete(node_t beg, node_t mid, node_t end);
int get_length(head_t list);
int is_empty(head_t list);
int find_data(head_t list, int data);
int get_start(head_t list, int* data_ptr);
int get_end(head_t list, int *data_ptr);
int pop_start(head_t list, int* data_ptr); 
int pop_end(head_t list, int* data_ptr);
int remove_start(head_t list);
int remove_end(head_t list); 


int main(void) {

    head_t list = get_list();

    insert_end(list, 10);
    insert_end(list, 20);
    insert_end(list, 30);

    
    show_list(list);

    destroy_list(&list);
    assert(list == NULL);

    return 0;
}

head_t get_list() {

    head_t head = get_node(-1); 
    return head;
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

void insert_beg(head_t list, int data) {

    node_t node = get_node(data);
    generic_insert(list, node, list -> next);
}

void insert_end(head_t list, int data) {
    node_t node = get_node(data);

    node_t run = list; 
    while(run -> next != NULL)
        run = run -> next;

    generic_insert(run, node, run -> next);
}

void generic_insert(node_t beg, node_t mid, node_t end) {

    beg -> next = mid; 
    mid -> previous = beg; 

    mid -> next = end;
    if(end != NULL)
        end -> previous = mid; 
}

void show_list(head_t list) {

    node_t run = list -> next;

    while(run != NULL) {
        printf("%d ", run -> data); 
        run = run -> next;
    }
    printf("\n");
}

int insert_after(head_t list, int e_data, int data) {

    node_t e_node = NULL;
    int result = get_node_from_list(list, e_data, &e_node);

    if(result == 0)
        return NO_SUCH_DATA;

    generic_insert(e_node, get_node(data), e_node -> next);
    return INSERT_SUCCESS;
}

int get_node_from_list(head_t list, int data, node_t* node_ptr) {

    int flag = 0;
    node_t run = list -> next;

    while(run != NULL) {
        if(run -> data == data) {
            flag = 1;
            *node_ptr = run;
            break;
        }
        run = run -> next;
    }
    return flag;
}

int insert_before(head_t list, int e_data, int data) {

    node_t e_node = NULL;
    int result = get_node_from_list(list, e_data, &e_node);

    if(result == 0)
        return NO_SUCH_DATA;

    generic_insert(e_node -> previous, get_node(data), e_node);
    return INSERT_SUCCESS;
}

void destroy_list(head_t* head_ptr) {

    head_t head = *head_ptr;
    node_t run = head -> next; 
    node_t run_next = NULL;

    while(run != NULL) {
        run_next = run -> next;
        free(run);
        run = run_next;
    }

    free(head);
    *head_ptr = NULL;
}

int remove_data(head_t list, int data) {

    node_t e_node = NULL;
    int result = get_node_from_list(list, data, &e_node);

    if(result)
        generic_delete(e_node -> previous, e_node, e_node -> next); 

    return result; 
}

void generic_delete(node_t beg, node_t mid, node_t end) {

    beg -> next = end;
    free(mid);
    if(end != NULL)
        end -> previous = beg;
}

int get_length(head_t list) {

    int length = 0;
    node_t run = list -> next;

    while(run != NULL) {
        length += 1;
        run = run -> next;
    }

    return length;
}

int is_empty(head_t list) {

    return (NULL == list -> next);
}

int find_data(head_t list, int data) {

    int flag = 0;
    node_t run = list -> next;

    while(run != NULL) {
        if(run -> data == data) {
            flag = 1;
            break;
        }
        run = run -> next;
    }
    return flag;
}

int get_start(head_t list, int* data_ptr) {

    node_t run = list -> next;
    
    if(run == NULL) 
        return LIST_EMPTY;
    
    *data_ptr = run -> data; 
    return SUCCESS;
}

int get_end(head_t list, int *data_ptr) {

    node_t run = list -> next;
    
    if(run == NULL) 
        return LIST_EMPTY;
    
    while(run -> next != NULL) 
        run = run -> next; 
        
    *data_ptr = run -> data; 
    return SUCCESS;
}

int pop_start(head_t list, int* data_ptr) {

    int result = get_start(list, data_ptr);

    if(result)
        generic_delete(list, list -> next, list -> next -> next); 
    
    return result;
}

int pop_end(head_t list, int* data_ptr) {

    int result = get_end(list, data_ptr);

    if(result) {
        node_t run = list -> next;
        
        while(run -> next != NULL) 
            run = run -> next; 

        generic_delete(run -> previous, run, run -> next);
    }

    return result;
}

int remove_start(head_t list) {

    node_t run = list -> next;
    
    if(run == NULL) 
        return LIST_EMPTY;

    generic_delete(list, list -> next, list -> next -> next);
    return DELETE_SUCCESS;
}

int remove_end(head_t list) {

    node_t run = list -> next;
    
    if(run == NULL) 
        return LIST_EMPTY;
        
    while(run -> next != NULL) 
        run = run -> next; 

    generic_delete(run -> previous, run, run -> next);
    return DELETE_SUCCESS;
}