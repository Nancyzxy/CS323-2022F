#include "symtab_bt.h"



// ************************************************************
//    Your implementation goes here
// ************************************************************
symtab * find_min(symtab * root){
    while(root!=NULL && root->left!=NULL){
        root = root->left;
    }
    return root;
}

symtab *symtab_init(){
    symtab *self = malloc(sizeof(symtab));
    memset(self, '\0', sizeof(symtab));
    self->left = NULL;
    self->right = NULL;
    return self;
}

int symtab_insert(symtab *self, char *key, VAL_T value){
    if (!&self->entry)
    {
        entry_init(&self->entry,key,value);
        return 1;
    }
    else if (strcmp(key,self->entry.key)>0)
    {   
        if (self->right == NULL)
        {
            symtab *node = malloc(sizeof(symtab));
            entry_init(&node->entry, key, value);
            node->left = NULL;
            node->right = NULL;
            self->right = node;
            return 1;
        }
        return symtab_insert(self->right,key,value);
    } else if (strcmp(key,self->entry.key)<0)
    {
         if (self->left == NULL)
        {
            symtab *node = malloc(sizeof(symtab));
            entry_init(&node->entry, key, value);
            node->left = NULL;
            node->right = NULL;
            self->left = node;
            return 1;
        }
        return symtab_insert(self->left,key,value);
    } else{
        // already have keys in the tree
        return 0;
    }  
}

VAL_T symtab_lookup(symtab *self, char *key){
    if (!&self->entry || self==NULL)
    {
        return -1;
    }
    if (strcmp(key,self->entry.key)==0)
    {
       return self->entry.value;
    }
    else if (strcmp(key,self->entry.key)>0)
    {
        return symtab_lookup(self->right,key);
    } else if (strcmp(key,self->entry.key)<0)
    {
        return symtab_lookup(self->left,key);
    }    
}

symtab * parent = NULL;
int isLeft = 0;
int flag = 1;
int symtab_remove(symtab *self, char *key){
    if (self == NULL || !&self->entry )
    {   
        return 0;
    }
    if (strcmp(key,self->entry.key)>0)
    {
        parent = self;
        isLeft = 0;
        return symtab_remove(self->right,key);
    }
    else if (strcmp(key,self->entry.key)<0)
    {
        parent = self;
        isLeft = 1;
        return symtab_remove(self->left,key);
    }
    else{
        if (self->left==NULL)
        {
            switch (isLeft)
            {
            case 0:
                parent->right = self->right;
                break;
            default:
                parent->left = self->right;
                break;
            }
            return 1;
        }
        else if (self->right==NULL)
        {
            switch (isLeft)
            {
            case 0:
                parent->right = self->left;
                break;
            default:
                parent->left = self->left;
                break;
            }
            return 1;
        }
        symtab * min = find_min(self->right);
        symtab_remove(self,min->entry.key);
        self->entry = min->entry;  
        return 1;
    }
}
