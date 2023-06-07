//Same as prg7.c but with documentation
/*
    @goal: To implemented routines of the doubly circular linked list 
    @author: Abhijeet Rai 
    @date: 20-04-2023 (Excatly 7 months after MSTC started)
*/


#include "list.h"

/*
 * main() - Entry point function for runtime library 
*/
int main(void) {
    int i = 0;
    head_pointer list1 = NULL;
    head_pointer list2 = NULL;
    head_pointer merged_list = NULL; 

    list1 = get_list();
    list2 = get_list();
    for(i = 1; i <= 3; i++) {
        insert_end(list1, i * 10);
        insert_end(list2, i * 10 + 5);
    }
    show_list(list1); 
    show_list(list2);
    merged_list = merge_lists(list1, list2);
    show_list(merged_list);

    exit(EXIT_SUCCESS);
}

/*
 * get_list() - Used to create list. 
 *
 * The function fetches a node from get_node and treats it as head of list.
 * Head of list is treated as dummy node. Puts -1 in data field of the dummy node.
 * Dummy node's next and previous fields point to itself.
 * 
 * Return: Address of the dummy node (list) is returned to the caller.
*/
head_pointer get_list() {
    head_pointer head = NULL;

    head = get_node(-1); 
    head->previous = head; 
    head->next = head; 

    return (head);
}

/*
 * get_node() - Used to map or spawn a node on the heap. 
 * @put_data_in_node: Data which will be put in the node, once node is created. 
 * 
 * Context: Can be repeatedly (reusable) to create node and put data in it. 
 * Used by create_list to create dummy node or insert routines.
 * 
 * Return: Address of the node which is created.  
*/
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

/*
 * insert_beg() - Used to insert data in beginning of the list. 
 * @list: list in which data is to be inserted. 
 * @data_to_be_inserted: data which is to be inserted in the list. 
 * 
 * Context: Levrages generic_insert for insertion.
*/
void insert_beg(head_pointer list, data_t data_to_be_inserted) {
    generic_insert(list, get_node(data_to_be_inserted), list->next);
}

/*
 * insert_end() - Used to insert data in end of the list. 
 * @list: list in which data is to be inserted. 
 * @data_to_be_inserted: data which is to be inserted in the list. 
 * 
 * Context: Levrages generic_insert for insertion
*/
void insert_end(head_pointer list, data_t data_to_be_inserted) {
    generic_insert(list->previous, get_node(data_to_be_inserted), list);
}

/*
 * show_list() - shows the data present in the list. 
 * @list: list which is to be shown.
 * 
 * Data is preceded by the address of head pointer address of the list.
*/
void show_list(head_pointer list) {
    node_pointer run = NULL;

    printf("head_pointer@: %p: ", list);
    for(run = list->next; run != list; run = run->next) 
        printf("%d ", run->data); 
    printf("\n");
}

/*
 * insert_before() - inserts data in the list, before a node with certain data 
 * @list: list in which data is to be inserted 
 * @e_data: existing data in the list, before which some data will be inserted. 
 * @data_to_be_inserted: data to be inserted in the list. 
 * 
 * Tries to find a node having e_data from the list. If such node with given data (e_data) 
 * exists. Gets stored address of that node in e_node variable. Then levrages routine generic_insert. 
 * to insert data_to_be_inserted before e_node. Set insert_status to successful and return it.
 * 
 * If no such node exists, set insert_status to failure and return it.
 * 
 * Return: Whether insert was successful or failure in the form of insert_status variable or state.
*/
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

/*
 * insert_after() - inserts data in the list, after a node with certain data. 
 * @list: list in which data is to be inserted.
 * @e_data: existing data in the list, after which some data will be inserted. 
 * @data_to_be_inserted: data to be inserted in the list. 
 * 
 * Tries to find a node having e_data from the list. If such node with given data (e_data) 
 * exists. Gets stored address of that node in e_node variable. Then levrages routine generic_insert 
 * to insert data_to_be_inserted after e_node. Set insert_status to successful and return it. 
 * 
 * If no such node exists, set insert_status to failure and return it.
 * 
 * Return: Whether insert was successful or failure in the form of insert_status variable or state.
*/
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

/**
 * get_node_with_data() - Stores address of node with required data in output parameter. 
 * @list: list in which data is to be searched. 
 * @data_to_search: data to be search in the list.
 * @pp_node: This is output parameter, carries address of a node pointer, this node pointer is set to NULL by default. 
 * 
 * Iterates through the list and tries to find a node which has specific data. If such node is found 
 * stores address of that node in output parameter pp_node. Sets flag to such node found and returns flag 
 * If such node is not found, flag is already set to node not found and flag is returned 
 * 
 * Return: Status whether node was found or not
*/
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

/**
 * delete_data() - used to delete some data from the list
 * @list: list from which, data is to be deleted 
 * @data_to_delete: data which is to be deleted from the list 
 * 
 * Tries to find a node with data_to_delete variable. If such node is found 
 * deletes it levraging the routine generic_delete, sets delete_status to successful 
 * and returns it. If node with required data is not found, 
 * set delete_status to failure and return it 
 * 
 * Return: Status whether data was deleted from the list or not
*/
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

/**
 * get_length() - returns the length or number of elements in the list 
 * @list: list whose length is to be retrieved 
 * 
 * Return: length of the list
*/
int get_length(head_pointer list) {
    int length = 0;
    node_pointer run = NULL;

    for(run = list->next; run != list; run = run->next) 
        length += 1;
    
    return (length);
}

/**
 * is_not_empty() - Checks whether the list is not empty
 * @list: list which is to be checked if it is empty 
 * 
 * Context: Used by lot many functions like get_start, get_end, remove_start and remove_end
 * 
 * Return: LIST_NOT_EMPTY(1) is list is not empty, LIST_EMPTY(0) if list is empty
*/
int is_not_empty(head_pointer list) {
    int is_list_empty = 0;

    if( ((list->previous) != list) && ((list->next) != list))
        is_list_empty = LIST_NOT_EMPTY; 
    else 
        is_list_empty = LIST_EMPTY;

    return (is_list_empty);
}

/**
 * get_start() - fetches the data in the first node of the list
 * @list: list from which first element or data is to be retrieved 
 * @data_ptr: output parameter which will store first element
*/
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