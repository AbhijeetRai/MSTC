/*
    @goal: To implemented routines of the doubly circular linked list 
    @author: Abhijeet Rai 
    @date: 20-04-2023 (Excatly 7 months after MSTC started)
*/


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


int main(void) {
    head_pointer list1 = NULL;
    head_pointer list2 = NULL;
    head_pointer merged_list = NULL; 

    list1 = get_list();
    list2 = get_list();
    for(int i = 1; i <= 3; i++) {
        insert_end(list1, i * 10);
        insert_end(list2, i * 10 + 5);
    }
    show_list(list1); 
    show_list(list2);
    merged_list = merge_lists(list1, list2);
    show_list(merged_list);

    exit(EXIT_SUCCESS);
}

head_pointer get_list() {
    head_pointer head = NULL;

    head = get_node(-1); 
    head->previous = head; 
    head->next = head; 

    return (head);
}

node_pointer get_node(data_t put_data_in_node) {
    node_pointer node = NULL;

    node = (node_pointer)calloc(1, sizeof(node));
    if(node == NULL) {
        printf("fatal: calloc: out of memory");
        exit(EXIT_FAILURE);
    }
    node->data = put_data_in_node; 
    node->previous = NULL; 
    node->next = NULL; 

    return (node);
}

void insert_beg(head_pointer list, data_t data_to_be_inserted) {
    generic_insert(list, get_node(data_to_be_inserted), list->next);
}

void insert_end(head_pointer list, data_t data_to_be_inserted) {
    generic_insert(list->previous, get_node(data_to_be_inserted), list);
}

void show_list(head_pointer list) {
    node_pointer run = NULL;

    printf("head_pointer@: %p: ", list);
    for(run = list->next; run != list; run = run->next) 
        printf("%d ", run->data); 
    printf("\n");
}

int insert_before(head_pointer list, data_t e_data, data_t data_to_be_inserted) {
    int node_found = 0;
    int insert_status = 0;
    node_pointer e_node = NULL;

    node_found = get_node_with_data(list, e_data, &e_node);
    if(node_found == NODE_WITH_GIVEN_DATA_FOUND) {
        generic_insert(e_node->previous, get_node(data_to_be_inserted), e_node);
        insert_status = INSERT_SUCCESSFUL;
    }else 
        insert_status = INSERT_FAILED;
    
    return (insert_status);
}

int insert_after(head_pointer list, data_t e_data, data_t data_to_be_inserted) {
    int node_found = 0; 
    int insert_status = 0; 
    node_pointer e_node = NULL; 

    node_found = get_node_with_data(list, e_data, &e_node); 
    if(node_found == NODE_WITH_GIVEN_DATA_FOUND) {
        generic_insert(e_node, get_node(data_to_be_inserted), e_node->next);
        insert_status = INSERT_SUCCESSFUL;
    }else 
        insert_status = INSERT_FAILED; 

    return (insert_status);
}

int get_node_with_data(head_pointer list, data_t data_to_search, pointer_to_node_pointer pp_node) {
    int flag = 0; 
    node_pointer run = NULL;
    
    flag = NODE_WITH_GIVEN_DATA_NOT_FOUND;
    run = list->next;
    while(run != list) {
        if(run->data == data_to_search) {
            flag = NODE_WITH_GIVEN_DATA_FOUND;
            *pp_node = run;
            break;
        }
        run = run->next;
    }

    return (flag);
}

int delete_data(head_pointer list, data_t data_to_delete) {
    int node_found = 0;
    int delete_status = 0;
    node_pointer e_node = NULL; 

    node_found = get_node_with_data(list, data_to_delete, &e_node);
    if(node_found == NODE_WITH_GIVEN_DATA_FOUND) {
        generic_delete(e_node);
        delete_status = DELETE_SUCCESSFUL;
    }else 
        delete_status = DELETE_FAILED;

    return (delete_status);
}

int get_length(head_pointer list) {
    int length = 0;
    node_pointer run = NULL;

    for(run = list->next; run != list; run = run->next) 
        length += 1;
    
    return (length);
}

int is_not_empty(head_pointer list) {
    int is_list_empty = 0;

    if( ((list->previous) != list) && ((list->next) != list))
        is_list_empty = LIST_NOT_EMPTY; 
    else 
        is_list_empty = LIST_EMPTY;

    return (is_list_empty);
}

int get_start(head_pointer list, data_t* data_ptr) {
    int is_list_empty = 0;
    int start_value_retrieved = 0;

    is_list_empty = is_not_empty(list);
    if(is_list_empty == LIST_NOT_EMPTY) {
        *data_ptr = list->next->data;
        start_value_retrieved = SUCCESS;
    } else 
        start_value_retrieved = FAILED;

    return (start_value_retrieved);
}

int get_end(head_pointer list, data_t* data_ptr) {
    int is_list_empty = 0; 
    int end_value_retrieved = 0;

    is_list_empty = is_not_empty(list);
    if(is_list_empty == LIST_NOT_EMPTY) {
        *data_ptr = list->previous->data; 
        end_value_retrieved = SUCCESS;
    } else
        end_value_retrieved = FAILED;

    return (end_value_retrieved); 
}

int pop_start(head_pointer list, data_t* data_ptr) {
    int start_value_retrieved = 0;
    int pop_start_successful = 0;

    start_value_retrieved = get_start(list, data_ptr);
    if(start_value_retrieved == SUCCESS) {
        generic_delete(list->next);
        pop_start_successful = SUCCESS; 
    } else 
        pop_start_successful = FAILED;

    return (pop_start_successful);
}

int pop_end(head_pointer list, data_t* data_ptr) {
    int end_value_retrieved = 0;
    int pop_end_successful = 0;

    end_value_retrieved = get_end(list, data_ptr);
    if(end_value_retrieved == SUCCESS) {
        generic_delete(list->previous); 
        pop_end_successful = SUCCESS;
    } else 
        pop_end_successful = FAILED;

    return (pop_end_successful);
}

int remove_start(head_pointer list) {
    int list_empty_status = 0;
    int delete_status = 0;

    list_empty_status = is_not_empty(list); 
    if(list_empty_status == LIST_NOT_EMPTY) {
        generic_delete(list->next);
        delete_status = DELETE_SUCCESSFUL;
    } else 
        delete_status = DELETE_FAILED; 

    return (delete_status);
}

int remove_end(head_pointer list) {
    int list_empty_status = 0;
    int delete_status = 0;

    list_empty_status = is_not_empty(list); 
    if(list_empty_status == LIST_NOT_EMPTY) {
        generic_delete(list->previous);
        delete_status = DELETE_SUCCESSFUL;
    } else 
        delete_status = DELETE_FAILED; 

    return (delete_status);
}

void destroy_list(pointer_to_head_pointer pp_head) {
    head_pointer list = NULL;
    node_pointer run = NULL;
    node_pointer run_next = NULL;

    list = *pp_head;
    run = list->next;
    while(run != list) {
        run_next = run->next;
        free(run);
        run=run_next;
    }
    free(list);
    *pp_head = NULL;
}

head_pointer merge_lists(head_pointer list1, head_pointer list2) {
    head_pointer merged_list = NULL;
    node_pointer run1 = NULL;
    node_pointer run2 = NULL;

    merged_list = get_list();
    run1 = list1->next; 
    run2 = list2->next;
    while(SUCCESS) {
        if(run1 == list1) {
            while(run2 != list2) {
                insert_end(merged_list, run2->data);
                run2 = run2->next;
            }
            break;
        }
        if(run2 == list2) {
            while(run1 != list1) {
                insert_end(merged_list, run1->data);
                run1 = run1->next;
            }
            break;
        }
        if(run1->data <= run2->data) {
            insert_end(merged_list, run1->data);
            run1 = run1->next;
        } else {
            insert_end(merged_list, run2->data); 
            run2 = run2->next;
        }
    }

    return (merged_list);
}

void generic_insert(node_pointer beg, node_pointer mid, node_pointer end) {
    beg->next = mid; 
    mid->previous = beg; 
    mid->next = end; 
    end->previous = mid;
}

void generic_delete(node_pointer delete_node) {
    delete_node->previous->next = delete_node->next; 
    delete_node->next->previous = delete_node->previous;
    free(delete_node); 
}