#include "linked-list.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct ll_node {
    int value;
    struct ll_node *next;
} ll_node;

struct ll_list {
    struct ll_node *first;
    size_t size;
};


ll_list * ll_create(void) {
    ll_list * list = malloc(sizeof(ll_list));
    if (list==NULL)
        return NULL;
    list->first = NULL;
    list->size=0;
    return list;
}

void ll_append(ll_list *list, int value) {
    ll_node * new_element = malloc(sizeof(ll_node));
    if(new_element == NULL) {
        fprintf(stderr, "Allocation error in ll_append\n");
        exit(1);
    }
    new_element->next = NULL;
    new_element->value = value;
    list->size+=1;

    if(list->first == NULL) {
        list->first = new_element;
        return;
    }

    ll_node *it = list->first;
    while(it->next != NULL) {
        it = it->next;
    }
    it->next = new_element;
}

int ll_get(const ll_list *list, unsigned int value_idx) {

    ll_node *it = list->first;

    for(unsigned int i = 0; i < value_idx; i++) {
        it = it->next;
    }
    return it->value;
}

void ll_free(ll_list *list) {
    if (list == NULL){
        return ;
    }
    else if (list->first == NULL){
        free(list);
        return ;
    }
    else {
    ll_node *it = list->first;
    ll_node *it2;
    while (it->next != NULL){
        it2 = it;
        it = it->next;
        free(it2);
    }
    free(it);
    free(list);
    }  
}

/** 
 * prepend an element to the list with the 
 * given value
 */

void ll_prepend(ll_list *list, int value){
    ll_node * new_element = malloc(sizeof(ll_node));
    if(new_element == NULL) {
        fprintf(stderr, "Allocation error in ll_append\n");
        exit(1);
    }
    new_element->next = list->first;
    new_element->value = value;
    list->first = new_element;
    list->size+=1;
}


/** 
 * return 1 if the function succeed
 * 0 if there is an error
 */

int ll_get_safe(const ll_list *list, unsigned int i, int *value){
    return 1;
}


/** return the first value
 */

int ll_first(ll_list *list){
    ll_node *it = list->first;
    return it->value;
}

/** return the last value
 */

int ll_last(ll_list *list){
    ll_node *it = list->first;
    while(it->next != NULL) {
        it = it->next;
    }
    //printf("%i\n", it->value);
    return it->value;
}

/**
 * return  the size of the list
 */

size_t ll_size(ll_list*list){
    /*size_t count = 1;
    ll_node *it = list->first;
    while(it->next != NULL) {
        it = it->next;
        count+=1;
    }
    //printf("%li", count);
    return count;*/
    return list->size;
}

/**
 * remove the last element
 */

void ll_pop_last(ll_list*list){
    ll_node *it = list->first;
    while(it->next->next != NULL){
        it=it->next;
    }
    ll_node *noeud = it->next;
    it->next=NULL;
    list->size-=1;  
    free(noeud);
}

/**
 * remove the first element
 */

void ll_pop_first(ll_list*list){
    ll_node *it = list->first;
    list->first=it->next;
    list->size-=1;
    free(it);     
}