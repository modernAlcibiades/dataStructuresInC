/* Linked List structure
 * Head -> value1 -> value2 -> value3
 * Head value is useless, only there to access and change the first element
 */

#include<stdio.h>
#include<malloc.h>
#include<limits.h>

struct node {
  int val;
  struct node* next;
};
typedef struct node Node;

Node* create_node(int val){
  Node* ret = (Node*) malloc(sizeof(Node));
  ret->val = val;
  ret->next = NULL;
  printf("Created %d\n", ret->val);
  return ret;
}

void insert_next(Node* prev, int val){
  Node* temp = prev->next;
  prev->next = create_node(val);
  prev->next->next = temp;
}

Node* insert_node(Node* head, int val){
  if (head == NULL) {
    head = create_node(INT_MIN);
    head->next = create_node(val);
  }
  else{
    Node* iter = head;
    while (iter->next !=NULL && iter->next->val >=val){
      iter = iter->next;
      printf("%d ->", iter->val);
    }
    insert_next(iter,val);
  }
  return head;
}

void delete_cur(Node* node){
  Node* temp = node->next;
  free(node);
  *node = *temp;
}

Node* delete_node(Node* head, int val){
  Node* iter = head;
  while(iter->next !=NULL){
    iter = iter->next;
    if(iter->val == val){
      delete_cur(iter);
      break;
    }
  }
  return head;
}

Node* create_list(int arr[], int len){
  Node* head = create_node(INT_MIN);
  int i = 0;
  for (i =0; i<len; i++){
    insert_node(head, arr[i]);
  }
  return head;
}

void print_list(Node* head){
  Node* iter = head;
  printf("Linked list = ");
  while(iter->next !=NULL){
    iter = iter->next;
    printf("%d -> ", iter->val);
  }
  printf("\n");
}

int main(int argc, char** argv){
  int arr[10] = {5, 10, 11, 2, 13, -1, 100, 7, 1, 1};
  Node* head = create_list(arr, 10);
  print_list(head);
  delete_node(head,7);
  print_list(head);
}
