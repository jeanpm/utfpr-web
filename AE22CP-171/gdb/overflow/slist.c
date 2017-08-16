#include <stdlib.h>


typedef char* Data;

typedef struct node
{
    struct node* next;
    Data value;
} Node;

typedef struct
{
   Node* head;
   Node* tail;
} List;

List* initList()
{
    List* l = malloc(sizeof(List));
    return l;
}

Node* newNode(Data d)
{
    Node* a = malloc(sizeof(Node));
    a->value = d;
    return a;
}

int main()
{

    List* l = initList();

    char* sa = malloc(sizeof(char)*10);
    char* sb = malloc(sizeof(char)*10);
    char* sc = malloc(sizeof(char)*10);

    Node* a = newNode(sa);
    Node* b = newNode(sb);
    Node* c = newNode(sc);

    a->next = b;
    b->next = c;
    c->next = NULL;

}
