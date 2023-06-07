//Singly linked list
#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h>

typedef struct node {

    int data; 
    struct node* next;
}node;

typedef node* head_t; 
typedef node* node_t;

head_t get_list();
node_t get_node(int data_param); 
void insert_beg(head_t list, int data); 
void insert_end(head_t list, int data);
int insert_before(head_t list, int e_data, int data);
void generic_insert(node_t beg, node_t mid, node_t end); 
void show_list(head_t list);
void destroy_list(head_t* head_pointer);
int get_node_from_list(head_t list, int data, node_t* node_ptr);

int delete(head_t list, int data_to_be_deleted);
void generic_delete(node_t prev_node, node_t delete_node);
int get_start(head_t list, int *data_ptr);
int get_end(head_t list, int *data_ptr);
int pop_start(head_t list, int* data_ptr);


#define     DATA_DOES_NOT_EXIST     0
#define     INSERT_SUCCESSFUL       1
#define     DELETE_SUCCESSFUL       1
#define     LIST_EMPTY              0 
#define     SUCCESS                 1

int main(void) {

    head_t list1 = get_list();
    head_t list2 = get_list();

    insert_end(list1, 10);
    insert_end(list1, 20);
    insert_end(list1, 30);
    insert_end(list1, 40);
    show_list(list1);

    return 0;
}

head_t get_list() {

    head_t list = get_node(-1);
    list -> next = NULL; 
    return list;
}

node_t get_node(int data_param) {

    node_t node = NULL;
    node = (node_t)calloc(1, sizeof(node));

    if(node == NULL) {
        printf("fatal: calloc: out of memory\n"); 
        exit(EXIT_FAILURE);
    }

    node -> data = data_param; 
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
    mid -> next = end;
}

void show_list(head_t list) {

    node_t run = list -> next;
    printf("Head pointer @%p: ", list);
    while(run != NULL) {
        printf("%d ", run -> data);
        run = run -> next;
    }
    printf("\n");
}

void destroy_list(head_t* head_pointer) {

    head_t list = *head_pointer;

    node_t run = list -> next;
    node_t next_run = NULL;

    while(run != NULL) {
        next_run = run -> next; 
        free(run);
        run = next_run;
    }

    free(list);
    *head_pointer = NULL;
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
        return DATA_DOES_NOT_EXIST;

    node_t run = list; 
    while(run -> next != e_node)
        run = run -> next;

    generic_insert(run, get_node(data), e_node);
    return INSERT_SUCCESSFUL;
}

int insert_after(head_t list, int e_data, int data) {

    node_t e_node = NULL;
    int result = get_node_from_list(list, e_data, &e_node);

    if(result == 0) 
        return DATA_DOES_NOT_EXIST;

    generic_insert(e_node, get_node(data), e_node -> next);
    return INSERT_SUCCESSFUL;
}

int delete(head_t list, int data_to_be_deleted) {

    node_t e_node = NULL;
    int result = get_node_from_list(list, data_to_be_deleted, &e_node);

    if(result == 0) 
        return DATA_DOES_NOT_EXIST;

    node_t run = list; 
    while(run -> next != e_node)
        run = run -> next;

    generic_delete(run, e_node);
    return DELETE_SUCCESSFUL;
}

void generic_delete(node_t prev_node, node_t delete_node) {

    prev_node -> next = delete_node -> next;
    free(delete_node);
}

int get_start(head_t list, int *data_ptr){

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

    //means the list is not empty
    if(result)
        generic_delete(list, list -> next);

    return result;
}

int pop_end(head_t list, int* data_ptr) {

    int result = get_end(list, data_ptr);

    if(result)
        delete(list, *data_ptr);

    return result;
}