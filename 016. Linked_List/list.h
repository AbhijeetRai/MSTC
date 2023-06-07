//to be used in prg8.c
#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h>


typedef int data_t; 
typedef struct node {
    data_t data; 
    struct node* previous; 
    struct node* next;
}node;
typedef node*   node_pointer; 
typedef node*   head_pointer;
typedef node**  pointer_to_node_pointer;
typedef node**  pointer_to_head_pointer;


head_pointer get_list();
void show_list(head_pointer list);
int get_length(head_pointer list);
int remove_end(head_pointer list);
int remove_start(head_pointer list);
int is_not_empty(head_pointer list);
node_pointer get_node(data_t put_data_in_node);
int get_end(head_pointer list, data_t* data_ptr);
int pop_end(head_pointer list, data_t* data_ptr);
int get_start(head_pointer list, data_t* data_ptr);
int pop_start(head_pointer list, data_t* data_ptr);
void destroy_list(pointer_to_head_pointer pp_head);
int delete_data(head_pointer list, data_t data_to_delete);
void insert_beg(head_pointer list, data_t data_to_be_inserted);
void insert_end(head_pointer list, data_t data_to_be_inserted);
head_pointer merge_lists(head_pointer list1, head_pointer list2);
int insert_after(head_pointer list, data_t e_data, data_t data_to_be_inserted);
int insert_before(head_pointer list, data_t e_data, data_t data_to_be_inserted);
int get_node_with_data(head_pointer list, data_t data_to_search, pointer_to_node_pointer pp_node);

void generic_delete(node_pointer delete_node);
void generic_insert(node_pointer beg, node_pointer mid, node_pointer end); 


#define     NODE_WITH_GIVEN_DATA_FOUND          1
#define     NODE_WITH_GIVEN_DATA_NOT_FOUND      0
#define     INSERT_SUCCESSFUL                   1 
#define     INSERT_FAILED                       0
#define     DELETE_SUCCESSFUL                   1 
#define     DELETE_FAILED                       0
#define     LIST_NOT_EMPTY                      1
#define     LIST_EMPTY                          0
#define     SUCCESS                             1 
#define     FAILED                              0