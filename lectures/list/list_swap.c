#include <stdio.h>
#include <stdlib.h>

struct Node{
  int n;
  struct Node *next;
};

typedef struct Node Node;

Node* createNode(int n, Node *next){
  Node *node = malloc(sizeof(Node));
  node->n = n;
  node->next = next;
  return node;
}

void swap_p(Node **a, Node **b){
  Node *tmp = *a;
  *a = *b;
  *b = tmp;
}

void swap_nodes(Node *a_pred, Node *b_pred){
  if(a_pred == b_pred)
    return;
  Node *a = a_pred->next;
  Node *b = b_pred->next;
  if(b->next == a){ // if a > b in order
    swap_p(&a, &b);
    swap_p(&a_pred, &b_pred);
  }
  if(a->next == b){
    a_pred->next = b;
    a->next = b->next;
    b->next = a;
    return;
  }
  swap_p(&(a->next), &(b->next));
    swap_p(&(a_pred->next), &(b_pred->next));
}

void swap_any_nodes(Node ** root, Node *a_pred, Node *b_pred){

}

void printList(Node *root){
  printf("[");
  while (root) {
    printf("%d", root->n);
    root = root->next;
    if(root)
      printf(", ");
  }
  printf("]\n");
}

void max_to_top(Node* root){
  Node* pred = root;
  Node *a = pred->next;
  if(a==NULL)
    return;
  Node *b = a->next;
  while(b){
    if(a->n > b->n){
      swap_nodes(pred, a);
    }
    pred = a;
    a = b;
    b = b->next;
  }
}

int main(){
  Node * a = createNode(50, NULL);
  Node * b = createNode(400, a);
  Node * c = createNode(30, b);
  Node * d = createNode(20, c);
  Node * e = createNode(60, d);
  Node *root = createNode(0,e);
  printList(root);
  //swap_nodes(c,b);
  max_to_top(root);
  printList(root);
  return 0;
}
