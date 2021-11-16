
#ifndef LIST_HEADER_GUARD
#define LIST_HEADER_GUARD

struct ll_list;
typedef struct ll_list ll_list;

// Cette structure n'a rien à faire là normalement, 
// mais je m'en sert pour cet exercice!
typedef struct student_t {
    unsigned long long id;
    char *name;
    int birthYear;
} student_t;

/**
 * create a node with the given value
 * 
 */
ll_list * ll_create(void);

/** 
 * append an element to the list with the 
 * given value
 */
void ll_append(ll_list *list, void *value);

/** 
 * remove the first element of the list.
 * The behavior is undefined if the list is empty
 */
void ll_pop_first(ll_list *list);


/** 
 * return the value at index i from the list. 
 * The behavior is undefined if there are less
 * than i+1 elements in the list.
 */
void * ll_get(const ll_list *list, unsigned int i);



/** free the list
 */
void ll_free(ll_list *list);


// -------- Nouvelles fonctions --------------



void *ll_find(ll_list *list, int (*match)(void*));

int ll_match_positive_int(void *el);

void *ll_find_data(ll_list *list, int (*match)(void*,void*), void *data);

int ll_match_int_equals(void *el, void *data);

int ll_match_student(void *el, void *data);

#endif