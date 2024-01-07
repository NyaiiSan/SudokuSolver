#include "main.h"

SquMap * createSquMap(int width){
    SquMap * head = malloc(sizeof(SquMap));
    head->origin = NULL;
    head->width = width;

    return head;
}

SquMapNode * createSquMapNode(SqMDataType val){
    SquMapNode * node = malloc(sizeof(SquMapNode));
    node->right = node->bottom = NULL;
    node->val = val;
    return node;
}

int initSquMap(SquMap * head){

    if(head == NULL){
        return 0;
    }

    SquMapNode * p = head->origin;
    SquMapNode * pr = NULL;

    for(int x=0; x<head->width; x++){

        if(p == NULL){
            head->origin = createSquMapNode(0);
            p = head->origin;
        }
        else{
            p->right = createSquMapNode(0);
            pr = p;
            p = p->right;
        }
    
        SquMapNode * q = p;
        for(int y = 1; y<head->width; y++){
            q->bottom = createSquMapNode(0);
            q = q->bottom;
            if(pr != NULL){
                pr = pr->bottom;
                pr->right = q;
            }
        }
    }
    return 1;
}

int setNodeValue(SquMap * head, int x, int y, SqMDataType val){
    SquMapNode *p = head->origin;
    for(int i=0; i<x; i++){
        if(p->right != NULL) p = p->right;
        else return 0;
    }
    for(int i=0; i<y; i++){
        if(p->bottom != NULL) p = p->bottom;
        else return 0;
    }
    p->val = val;
    return 1;
}

int getNodeValue(SquMap * head, int x, int y, SqMDataType * val){
    SquMapNode *p = head->origin;
    for(int i=0; i<x; i++){
        if(p->right != NULL) p = p->right;
        else return 0;
    }
    for(int i=0; i<y; i++){
        if(p->bottom != NULL) p = p->bottom;
        else return 0;
    }
    *val = p->val;
    return 1;
}

void printSquMap(SquMap * head){
    SquMapNode * y = head->origin;
    while(y){
        SquMapNode * x = y;
        while (x){
           printf("%d ", x->val);
           x = x->right;
        }
        puts("");
        y = y->bottom;
    }
}

void deleteSquMap(SquMap * head){
    if(head == NULL){
        return;
    }
    while(head->origin){
        SquMapNode * p = head->origin;
        head->origin = p->right;
        while(p){
            SquMapNode * q = p;
            p = p->bottom;
            free(q);
        }
    }
}

void destroySquMap(SquMap * head){
    if(head == NULL){
        return;
    }
    deleteSquMap(head);
    free(head);
}

SquMap * copySquMap(SquMap * head){
    if(head == NULL){
        return NULL;
    }
    SquMap * new_head = createSquMap(head->width);
    initSquMap(new_head);
    for(int x=0; x<head->width; x++){
        for(int y=0; y<head->width; y++){
            SqMDataType val;
            if(getNodeValue(head, x, y, &val)){
                setNodeValue(new_head, x, y, val);
            }
        }
    }
    return new_head;
}

int inputLine(SquMap * head, int y){
    if(head == NULL) return 0;

    SquMapNode * p = head->origin;
    for(int i=0; i<y; i++){
        if(p->bottom!= NULL) p = p->bottom;
        else return 0;
    }

    char * inputS = malloc(100);
    char * sp = inputS;
    gets(inputS);
    int val = 0;
    while(1){
        if(*sp >= '0' && *sp <= '9'){
            val = val * 10 + (*sp - '0');
        }
        else if(*sp == ' ' || *sp == '\t' || *sp == '\0'){
            p->val = val;
            if(p->right != NULL) p = p->right;
            else break;
            val = 0;
            if(*sp == '\0') break;
        }
        sp++;
    }
    free(inputS);
    return 1;
}

int inputLines(SquMap * head){
    if(head == NULL) return 0;
    for(int y=0; y<head->width; y++){
        printf("line %d: ", y+1);
        inputLine(head, y);
    }
    return 1;
}