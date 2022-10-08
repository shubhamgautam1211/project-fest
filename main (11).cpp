//reversing the linked list

#include <iostream>

using namespace std;

#include <iostream>
using namespace std;
 
 
struct Node {
    int data;
    struct Node* next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
 
struct LinkedList {
    Node* head;
    LinkedList()
    { 
        head = NULL; 
        
    }

void reverse()
{
        Node* current = head;
        Node *prev = NULL, *next = NULL;
 
        while (current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
    
void removeDuplicates(struct Node* head)
{
    struct Node *ptr1, *ptr2, *dup;
    ptr1 = head;
 
    while (ptr1 != NULL && ptr1->next != NULL) {
        ptr2 = ptr1;
 
        while (ptr2->next != NULL) {
            
            if (ptr1->data == ptr2->next->data) {
                
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete (dup);
            }
            else
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}
 
    void print()
    {
        struct Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
 
    void push(int data)
    {
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
    }
};

int main()
{
    LinkedList a1;
    int n;
    int b;
    cout<<"enter the number of elements to be added "<<endl;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>b;
        a1.push(b);
    }
    cout<<"elements added"<<endl;
    a1.print();
    cout<<endl;
    
    cout<<"Linked List reversed"<<endl;
    a1.reverse();
    a1.print();
    cout<<endl;
    
    cout<<"duplicate elements removes"<<endl;
    //struct Node* start = Node(10);
    a1.removeDuplicates();
    

    

    return 0;
}
