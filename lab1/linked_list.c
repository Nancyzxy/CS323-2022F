#include "linked_list.h"

node *linked_list_init(){
    node *head = (node*)malloc(sizeof(node));
    head->count = 0;
    head->next = NULL;
    return head;
}

void linked_list_free(node *head){
    node *cur = head;
    node *last;
    while(cur != NULL){
        last = cur;
        cur = cur->next;
        free(last);
    }
}

char linked_list_string[0x10000];

char *linked_list_tostring(node *head){
    node *cur = head->next;
    char *position;
    int length = 0;
    while(cur != NULL){
        position = linked_list_string + length;
        length += sprintf(position, "%d", cur->value);
        cur = cur->next;
        if(cur != NULL){
            position = linked_list_string + length;
            length += sprintf(position, "->");
        }
    }
    position = linked_list_string + length;
    length += sprintf(position, "%c", '\0');
    return linked_list_string;
}

int linked_list_size(node *head){
    return head->count;
}

void linked_list_append(node *head, int val){
    node *cur = head;
    node *new_node;
    while(cur->next != NULL){
        cur = cur->next;
    }
    new_node = (node*)malloc(sizeof(node));
    new_node->value = val;
    new_node->next = NULL;
    cur->next = new_node;
    head->count++;
}

/* your implementation goes here */

void linked_list_insert(node *head, int val, int index)
{
    if ((index>head->count) || index<0)
    {
        return;
    }
    int id = 0;
    node *before = head;
    node *current = head;
    while (id <= index)
    {
        before = current;
        current = current->next;
        id++;
    }
    node *new_node = (node *)malloc(sizeof(node));
    new_node->value = val;
    new_node->next = current;
    before->next = new_node;
    head->count++;
}

void linked_list_delete(node *head, int index)
{
    if ((index>=head->count) || index<0)
    {
        return;
    }
    int id = 0;
    node *before = head;
    node *current = head->next;
    while (id < index)
    {
        before = current;
        current = current->next;
        id++;
    }
    before->next = current->next;
    head->count--;
}

void linked_list_remove(node *head, int val)
{
    node *before = head;
    node *current = head->next;
    while (current->value != val)
    {
        before = current;
        if (current->next==NULL)
        {
           return;
        }
        current = current->next;
    }

    before->next = current->next;
    head->count--;
}

void linked_list_remove_all(node *head, int val)
{
    node *before = head;
    node *current = head->next;
    while (1)
    {
        if(current->value==val){
            before->next = current->next;
            current = current->next;
            head->count--;
        }
        else{
            before = current;
            if (current->next==NULL)
            {
                return;
            }
            current = current->next;
        }
    }
}

int linked_list_get(node *head, int index){
    int id = 0;
    node *before = head;
    node *current = head->next;
    if (index >= head->count)
    {
        return -0x80000000;
    }
    
    while (id<index)
    {
        before = current;
        current = current->next;
        id++;
    }
    return current->value;
}

int linked_list_search(node *head, int val){
    int id = 0;
    node *before = head;
    node *current = head->next;

    while (current->value!=val)
    {
        before=current;
        if (current->next==NULL)
        {
            return -1;
        }
        current = current->next;
        id++;
    }
    return id;
    
}

node *linked_list_search_all(node *head, int val){
    int id=0;
    node *before = head;
    node *current = head->next;
    node *result_head = linked_list_init();
    while (1)
    {
        if (current->value==val)
        {
            linked_list_append(result_head,id);
        }
        before = current;
        if (current->next==NULL)
        {
            break;
        }
        current = current->next;
        id++;
    }
    return result_head;
}
