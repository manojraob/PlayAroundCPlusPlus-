/* C++ Implementation of Linked List based on Generics with methods for printing, inserting (front) and deleting(front) data from the linked list */
template <class T>
class List
{
    private:
            T data;
            List* next;
    public:
            void printList(List* head)
            {
                while(head != nullptr)
                {
                    cout << head->data << " ";
                    head = head->next;
                }
                cout << endl;
            }
            
            List* pushFront(List* head, T data)
            {
                List* newHead = new List();
                newHead->data = data;
                newHead->next = head;
                head = newHead;
                return head;
            }
            
            List* deleteFront(List* head)
            {
                List* t = head;
                head = head->next;
                delete t;
                return head;
            }
};

int main() 
{   
  // Creating a head of the linked list.
  List < string > * head = nullptr;

  // Creating a Linked List.
  List < string > myList;

  head = myList.pushFront(head, "A");
  head = myList.pushFront(head, "B");
  head = myList.pushFront(head, "C");
  head = myList.pushFront(head, "D");
  head = myList.deleteFront(head);

  myList.printList(head);    
}
