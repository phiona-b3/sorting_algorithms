#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * insertion_sort_list - sorts a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm
 * @list: double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
listint_t *head, *node, *tmp;

if (!list || !(*list))
return;
head = node = *list;
while (node)
{
if (!node->prev)
{
node = node->next;
continue;
}
else if (node->n < node->prev->n)
{
tmp = node->prev;
tmp->next = node->next;
if (node->next)
node->next->prev = tmp;
node->next = tmp;
node->prev = tmp->prev;
tmp->prev = node;
if (node->prev)
node->prev->next = node;
else
{
node->prev = NULL;
head = node;
}
print_list(head);
}
else if (node->n >= node->prev->n && !node->next)
{
*list = head;
return;
}
else
{
node = node->next;
}
}
}
