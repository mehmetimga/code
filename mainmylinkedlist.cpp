#include <iostream>
using namespace std;

struct Item
{
    int val = 0;
    Item *next;
    Item *prev;
    Item(int val) : val(val), next(nullptr), prev(nullptr) {}
};

class MyLinkedList
{
public:
    Item *head;
    Item *last;

    MyLinkedList()
    {
        head = nullptr;
        last = nullptr;
    }

    int get(int index)
    {
        Item *curr = head;
        int i = 0;
        while (curr)
        {
            if (i == index)
                return curr->val;
            curr = curr->next;
            i++;
        }
        return -1;
    }

    void addAtHead(int val)
    {
        Item *item = new Item(val);
        item->next = head;
        head = item;
        if (last == nullptr)
            last = item;
    }

    void addAtTail(int val)
    {
        Item *item = new Item(val);
        if (last)
        {
            last->next = item;
            last=item;
        }
        else
        {
            head=last = item;
        }
    }

    void addAtIndex(int index, int val)
    {
        if (index == 0)
        {
            addAtHead(val);
            return;
        }

        Item *curr = head;
        int i = 1;
        while (curr)
        {
            if (i == index)
                break;
            curr = curr->next;
            i++;
        }
        if (!curr)
            return;
        Item *temp = curr->next;
        curr->next = new Item(val);
        curr->next->next = temp;
        if (temp==nullptr)
            last=curr->next;
    }

    void deleteAtIndex(int index)
    {
        if (!head)
            return;
        Item *curr = head->next;
        Item *prev = head;
        if (index == 0)
        {

            if (head->next == nullptr)
            {
                delete head;
                head = last = nullptr;
            }
            else
            {
                Item *temp = head->next;
                delete head;
                head = temp;
            }

            return;
        }
        int i = 1;
        while (curr)
        {
            if (i == index)
                break;
            prev = curr;
            curr = curr->next;
            i++;
        }
        if (!curr)
            return;
        
        if (curr->next==nullptr)
            last=prev;
        prev->next = curr->next;
        delete curr;
    }
};


int main()
{


    MyLinkedList myLinkedList;
    myLinkedList.addAtHead(2);
    myLinkedList.deleteAtIndex(1);
    myLinkedList.addAtHead(2);
    myLinkedList.addAtHead(7);
    myLinkedList.addAtHead(3);
    myLinkedList.addAtHead(2);
    myLinkedList.addAtHead(5);
    myLinkedList.addAtTail(5);
    myLinkedList.get(5);
    myLinkedList.deleteAtIndex(6);
    myLinkedList.deleteAtIndex(4);


    // myLinkedList.addAtHead(1);
    // myLinkedList.addAtTail(3);
    // myLinkedList.addAtIndex(1, 2); // linked list becomes 1->2->3
    // cout << "" << myLinkedList.get(1) << endl;           // return 2
    // myLinkedList.deleteAtIndex(1); // now the linked list is 1->3
    // cout << "" <<  myLinkedList.get(1) << endl;           // return 3
}