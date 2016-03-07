#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int value;
  struct node * next;
} node_t;

void print_list(node_t * head)
{
  node_t * current = head;
 
  while(current != NULL)
  {
    printf("%d, ", current->value);
    current = current->next;
  }
}

void add_first(node_t ** head, int value)
{
  node_t * new_node;
  new_node = malloc(sizeof(node_t));

  new_node->value = value;
  new_node->next = *head;
  *head = new_node;
}

void add_last(node_t * head, int value)
{
  node_t * current = head;
  while(current->next != NULL)
  {
    current = current->next;
  }

  current->next = malloc(sizeof(node_t));
  current->next->value = value;
}


int remove_first(node_t ** head)
{
  if(*head == NULL) return -1;
 
  int value = (*head)->value;
  node_t * next_node = (*head)->next;
  free(*head);
  *head = next_node;

  return value;
}

int remove_last(node_t * head)
{
  node_t * current = head;
  node_t * previous;
  
  while(current->next != NULL)
  {
    previous = current;
    current = current->next;
  }

  int value = current->value;
  free(previous->next);
  previous->next = NULL;
  return value;
}

int remove_by_value(node_t ** head, int value)
{
  node_t * current = *head;
  node_t * previous;

  if (*head == NULL) return -1;
  if ((*head)->value == value) return remove_first(head);

  while(current != NULL)
  {
    if(current->value == value)
    {
      previous->next = current->next;
      free(current);
      return value;
    }
    previous = current;
    current = current->next;
  }
  return -1;
}

int main()
{
  // declare list
  node_t * list = malloc(sizeof(node_t));
  list->value = 1;
  list->next = NULL;
  
  // manipulate list
  add_first(&list, 0);
  add_last(list, 2);
  add_last(list, 3);
  add_last(list, 4);
  printf("%d\n", remove_first(&list));
  printf("%d\n", remove_last(list));
  printf("%d\n", remove_by_value(&list, 1));

  // print list
  print_list(list);
  printf("\n");
}
