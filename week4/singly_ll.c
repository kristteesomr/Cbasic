#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head_node = NULL;
int *length = 0;
void deleteNode(struct node **head_ref, int position)
{
    if (*head_ref == NULL)
        return;
    struct node *temp = *head_ref;
    if (position == 0)
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    for (int i = 0; temp != NULL && i < position - 1; i++)
        temp = temp->next;
    if (temp == NULL || temp->next == NULL)
        return;
    struct node *next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

struct node *append(int new_data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = NULL;
    if (head_node == NULL)
    {
        head_node = new_node;
        return head_node;
    }
    new_node->next = head_node;
    head_node = new_node;
    *length++;
    return head_node;
}
struct node *unshift(int new_data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = NULL;
    struct node *current_node = head_node;
    while (current_node->next != NULL)
    {
        current_node = current_node->next;
    }
    current_node->next = new_node;
    new_node = current_node;
    return head_node;
}
struct node *shift()
{
    struct node *current_node = head_node;
    while (current_node->next->next != NULL)
    {
        current_node = current_node->next;
    }
    current_node->next = NULL;
    length++;
    return head_node;
}
struct node *pop()
{
    struct node *current_node = head_node;
    head_node = head_node->next;
    free(current_node);
    return head_node;
}
struct node *addToPos(int new_data, int pos)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (pos == 0)
    {
        append(new_data);
        return head_node;
    }
    if (pos == 5)
    {
        unshift(new_data);
        return head_node;
    }
    new_node->data = new_data;
    new_node->next = NULL;
    struct node *prev_node = head_node;
    struct node *next_node = next_node;
    while (pos != 1)
    {
        prev_node = prev_node->next;
        pos--;
    }
    next_node = prev_node->next;
    new_node->next = next_node;
    prev_node->next = new_node;
    return head_node;
}
void printList()
{
    while (head_node != NULL)
    {
        printf("%d ", head_node->data);
        head_node = head_node->next;
    }
    printf("\n");
}
int main()
{
    head_node = append(3);
    head_node = append(4);
    head_node = append(5);
    head_node = addToPos(7, 5);
    head_node = unshift(2);
    printList();
}