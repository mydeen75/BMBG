#include <iostream>

using namespace std;

struct node {
	int 	data;
	node* 	next;
};

/* Function to push a node */
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node = new node();
            
    /* put in the data  */
    new_node->data  = new_data;
                
    /* link the old list off the new node */
    new_node->next = (*head_ref);    
        
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* Function to print linked list */
void printList(struct node *head)
{
    struct node *temp = head;
    while(temp != NULL)
    {
        cout << temp->data << " ";    
        temp = temp->next;  
    }
}    
 
/* Driver program to test above function*/
int main()
{
    /* Start with the empty list */
    struct node* head = NULL;
   
     push(&head, 20);
     push(&head, 4);
     push(&head, 15); 
     push(&head, 85);      
     
     cout << "Given linked list\n";
     printList(head);    
//     reverse(&head);                      
//     cout << "\nReversed Linked list \n";
//     printList(head);    

}