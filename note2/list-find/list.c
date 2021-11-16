#include "list.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct ll_node {
    void *value;
    struct ll_node *next;
} ll_node;

struct ll_list {
    struct ll_node *first;
    size_t size;
};


ll_list * ll_create(void) {
    ll_list * list = malloc(sizeof(ll_list));
    list->first = NULL;
    list->size = 0;
    return list;
}

void ll_append(ll_list *list, void *value) {
    ll_node * new_element = malloc(sizeof(ll_node));
    if(new_element == NULL) {
        fprintf(stderr, "Allocation error in ll_append\n");
        exit(1);
    }
    new_element->next = NULL;
    new_element->value = value;

    list->size++;

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

void *ll_get(const ll_list *list, unsigned int value_idx) {

    ll_node *it = list->first;

    for(unsigned int i = 0; i < value_idx; i++) {
        it = it->next;
    }
    return it->value;
}

void ll_pop_first(ll_list *list){
    ll_node * second = list->first->next;
    free(list->first);
    list->first = second;
    list->size--;
}


void ll_free(ll_list *list) {
    if(list == NULL) return;

    while(list->size) {
        ll_pop_first(list);
    }
    free(list);
}


// -------- Nouvelles fonctions à implémenter --------------

void *ll_find(ll_list *list, int (*match)(void*)) {
    ll_node *it = list->first;
    while(it->next != NULL) {
        it = it->next;
        if (match(it->value)!=0){
            return it->value;
        }
    }
    return NULL;
}

int ll_match_positive_int(void *el) {
    if (*(int*)el>0)
        return 1;
    return 0;
}


void *ll_find_data(ll_list *list, int (*match)(void*,void*), void *data){
    ll_node *it = list->first;
    while(it->next != NULL) {
        it = it->next;
        if (match(it->value, data)!=0){
            return it->value;
        }
    }
    return NULL;
}

int ll_match_int_equals(void *el, void *data){
    if (*(int*)el==*(int*)data) return 1;
    return 0;
}

int ll_match_student(void *el, void *data){
    student_t stu = *(student_t*)el;
    if (stu.id==*(unsigned long long int*)data) return 1;
    return 0;
}
