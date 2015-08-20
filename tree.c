#include "tree.h"
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
typedef struct node node;

struct node
{
    int key;
    int value;
    int count;
    node *left;
    node *right;
};

node *root = NULL;

/*
void specialput(char* key, int value)
{
    root = specput(root,key,value);
}

static node* specput( node* p , char *key, int value)
{
    if(p == NULL)
    {
        p = (node*)malloc(sizeof(node));
        p -> key = key;
        p -> value = value;
        p -> left = NULL;
        p -> right = NULL;
        return p;
    }
    //else if(p -> key > key)
    else if(strcmp(ptr->key,key) > 0)
        p -> left = specput(p -> left, key,value);
    else if(strcmp(ptr->key,key) < 0)
        p -> right = specput(p -> right, key, value);
    else
        p -> value = value;
    return p;
}
*/
       
static node* makenode()
{
    node *t;
    t = (node *)malloc(sizeof(node));
    t -> left = NULL;
    t -> right = NULL;
    t -> count = 1;
    return t;
}
void inorder(node *r)
{
    if(r == NULL)
        return;
    inorder(r->left);
    printf("%d",r -> key);
    inorder(r -> right);
}
void print()
{
    inorder(root);
}
void put( int key, int value)
{
    node *ptr, *save, *n;

    if(root == NULL)
    {
       root = makenode();
       root -> key = key;
       root -> value = value;
       return;
    }
    else
    {
       ptr = root;

       while(ptr != NULL)
       {
           if(ptr -> key > key)
           {
                save = ptr;
                save -> count += 1;
                ptr = (node*)ptr -> left;
           }
           else{
               save = ptr;
               save -> count += 1;
               ptr = (node*)ptr -> right;
           }
       }
       
       n = makenode();
       n -> key = key;
       n -> value = value;
      
       if(save -> key < key)
            save -> right = (struct node*)n;
       else
            save -> left = (struct node*)n;
    }        
}    

int get(int key)
{
    node *ptr;

    if(root == NULL)
        return -1;
    else
    {
        ptr = root;
        while(ptr != NULL)
        {
            if(ptr -> key == key)
            {
               // ptr -> value += 1;
                return ptr -> value;
            }
            else if(ptr -> key > key)
                ptr = (node*) ptr -> left;
            else
                ptr = (node*)ptr -> right;
        }
        
    }
    return -1;
}
static node* mini(node* r)
{
   if(r == NULL)
       return NULL;
   else if(r -> left == NULL)
       return r;
   else
      return  mini(r->left);
}
     
int getmin()
{
   node *r;
   r = mini(root);
   return r -> key;
}

static node* max(node* r)
{
    if(r == NULL)
        return NULL;
    else if(r -> right == NULL)
        return r;
    else
        return max(r -> right);
}
 
int getmax()
{
    node *r;
    r = max(root);
    return r -> key;
} 


static node* ff(node* r, int key)
{
    node *c;
    if(r == NULL)
        return NULL;
    if(r -> key == key)
        return r;
    if(r -> key > key)
        return ff(r -> left, key);
    if(r -> key < key){
        c = ff(r -> right, key);
        if(c == NULL)
           return r;
        else
           return c;
    }
}
int flooring(int key)
{
    node *r = ff(root,key);
    return r->key;
}    

static node* delma(node *r)
{
   if(r == NULL)
       return r;
   if(r->right == NULL)
       return r -> left;
   else
       r -> right = delma(r->right);
   return r;
}
void delmax()
{
    root = delma(root);
}

static node* cc(node *r, int key)
{
    if(r == NULL)
        return NULL;
    if(r -> key == key)
         return r;
    if(r -> key < key)
         return cc(r -> right,key);
    if(r -> key > key)
    {
        node* c = cc(r -> left,key);
        if(c == NULL)
            return r;
        else
            return c;
    }
}

int ceiling(int key)
{
    node *r = cc(root,key);
    return r->key;
} 

int size(node *r)
{
    if(r == NULL)
        return 0;
    return r->count;
}

int ranking(node *r, int key)
{
    int p = 0;

    if(r -> key == key)
    {
         if(r -> left != NULL)
         { 
             printf(" count is %d of %d for %d",size(r->left),r->left->key,r->key); 
             return  r -> left -> count;
         }
         else
             return 0;
    }
     
    if(r -> key > key)
         return ranking(r -> left, key);
    else
    {
         return 1 + ranking(r, r -> key) + ranking(r -> right , key);

    }    
}

int rank(int key)
{
    return ranking(root,key);
}

/*
int geti(char *key)
{
    node *ptr;

    if(root == NULL)
        return -1;
    else
    {
        ptr = root;
        while(ptr != NULL)
        {
            if(strcmp(ptr->key,key) == 0)
            {
                ptr -> value += 1;
                return ptr -> value;
            }
            else if(strcmp(ptr->key,key) > 0)
                ptr = (node*) ptr -> left;
            else
                ptr = (node*)ptr -> right;
        }
        
    }
    return -1;
}*/
