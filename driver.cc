#include <iostream>
#include <stdlib.h>
#include <string>

/* Link list node */
typedef struct Node
{
    int data;
    struct Node* next;
}Node;

Node *newNode(int key);
int countNodesinLoop(Node*);
int countNode(Node* head);
void print_list(Node*);
int customstrstr(std::string s, std::string x);

int main(){
    struct Node *head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);
 
    /* Create a loop for testing */
    head->next->next->next->next->next = head->next;
 
    //detect loop
    std::cout<<"Count of loop: "<<countNodesinLoop(head)<<std::endl;

    //find position of substring
    std::cout<<"S: vedhas X:has "<<customstrstr("vedhas","has")<<std::endl;

    return 0;
}

void print_list(Node* head){

}

Node *newNode(int key)
{
    struct Node *temp =
        (struct Node*)malloc(sizeof(struct Node));
    temp->data = key;
    temp->next = NULL;
    return temp;
}

int countNodesinLoop(Node* head) {
    Node *slow, *fast;
    int slowcount = 1;
    int fastcount = 1;
    slow = head;
    fast = head;

    while(slow && fast && fast->next){
        slow = slow->next;
        slowcount++;
        fast = fast->next->next;
        fastcount+=2;
        
        std::cout<<"F: "<<fastcount<<"S: "<<slowcount<<std::endl;
        if (slow == fast){
            return countNode(slow);
        }
    }
    return 0;
}

int countNode(Node* head){
    Node *slow,*fast;
    int res=0;
    slow = fast = head;
    do {
        slow=slow->next;
        res++;
    }while(slow!=fast);
    return res;
}

int customstrstr(std::string s, std::string x)
{
    //Your code here
    const char* target = s.c_str();
    const char* pat = x.c_str();
    int i = 0;
    int j = 0;
    int pos = 0;
    
   while(target[i]!='\0'){
       if(target[i]==pat[j]){
           if(j==0)
               pos = i;
           i++;
           j++;
       }
       else if(pat[j]=='\0'){
           return pos;
       }
       else{
           i++;
           pos = -1;
           j = 0;
       }
   }
   
   if(pat[j]!='\0'){
       pos = -1;
   }
   return pos;
}