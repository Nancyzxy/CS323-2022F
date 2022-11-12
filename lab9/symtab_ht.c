#include "symtab_ht.h"


#define TABLE_SIZE 0x1003


// ************************************************************
//    Your implementation goes here
// ************************************************************

unsigned int PJWHash(char* str, int length) {
	const unsigned int BitsInUnsignedInt = (unsigned int)(sizeof(unsigned int) * 8);
	const unsigned int ThreeQuarters = (unsigned int)((BitsInUnsignedInt * 3) / 4);
	const unsigned int OneEighth = (unsigned int)(BitsInUnsignedInt / 8);
	const unsigned int HighBits = (unsigned int)(0xFFFFFFFF) << (BitsInUnsignedInt - OneEighth);
	unsigned int hash = 0;
	unsigned int test = 0;
	unsigned int i = 0;

	for (i = 0; i < length; str++, i++)
	{
		hash = (hash << OneEighth) + (*str);

		if ((test = hash & HighBits) != 0)
		{
			hash = ((hash ^ (test >> ThreeQuarters)) & (~HighBits));
		}
	}

	return hash;
}

symtab *symtab_init(){
    symtab * ptr = malloc(sizeof(symtab)*TABLE_SIZE);
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        ptr[i] = malloc(sizeof(struct _node));
        memset(ptr[i], '\0', sizeof(struct _node));
        ptr[i]->next = NULL;
    }
    return ptr;
}

int symtab_insert(symtab *self, char *key, VAL_T value){
    int hashValue = PJWHash(key,strlen(key));
    int index = hashValue % TABLE_SIZE;
    for (int i = 0; i < index; i++)
    {
        self++;
    }
    while ((*self)->next!=NULL)
    {
        if (strcmp((*self)->next->entry.key,key)==0)
        {
            return 0;
        }
        self = &((*self)->next);

    }
    symtab node = malloc(sizeof(struct _node));
    memset(node, '\0', sizeof(struct _node));
    entry_init(&node->entry, key, value);
    node->next =NULL;
    (*self)->next = node;
    return 1;
}

VAL_T symtab_lookup(symtab *self, char *key){
    int hashValue = PJWHash(key,strlen(key));
    int index = hashValue % TABLE_SIZE;
    for (int i = 0; i < index; i++)
    {
        self++;
    }

    while ((*self)->next!=NULL)
    {
        if (strcmp((*self)->next->entry.key,key)==0)
        {
            return (*self)->next->entry.value;
        }
        self = &((*self)->next);
    }    
    return -1;
}

int symtab_remove(symtab *self, char *key){
    int hashValue = PJWHash(key,strlen(key));
    int index = hashValue % TABLE_SIZE;
    for (int i = 0; i < index; i++)
    {
        self++;
    }

    while ((*self)->next!=NULL)
    {
        if (strcmp((*self)->next->entry.key,key)==0)
        {
            (*self)->next = (*self)->next->next;
            return 1;
        }
        self = &((*self)->next);
    }
    return 0;
}
