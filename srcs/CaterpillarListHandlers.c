
#include "../push_swap.h"

// Inserts a new node at the end of the list.
void insert_node(t_data **lst, t_data *new_node) {
    if (!lst || !new_node) {
        return;
    }

    if (!*lst) {
        *lst = new_node;
        return;
    }

    t_data *current = *lst;
    while (current->next) {
        current = current->next;
    }
    current->next = new_node;
}

// Deletes a list and frees its contents.
void delete_lst(t_data **lst, void (*del_func)(void *)) {
    if (!lst || !*lst || !del_func) {
        return;
    }

    t_data *current;
    while (*lst) {
        current = *lst;
        *lst = current->next;

        del_func(current->content);
        free(current);
    }
}

// Returns the size of the list.
int get_size(t_data *lst) {
    int count = 0;
    t_data *current = lst;

    while (current) {
        count++;
        current = current->next;
    }
    return count;
}

// Creates a new node with given content.
t_data *create_node(void *content) {
    t_data *new_node = (t_data *)malloc(sizeof(t_data));
    if (!new_node) {
        return NULL;
    }

    new_node->content = content;
    new_node->next = NULL;
    return new_node;
}
