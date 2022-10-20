
#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *curr = nullptr;
    bool listordered=false;
    int count=0;
    void reorderListr(ListNode *item,int index)
    {
        index++;


        if (item->next == nullptr)
        {
            count=index;
            ListNode *temp = head->next;
            head->next = item;

            item->next = temp;
            curr = temp;
        }
        else
        {
            reorderListr(item->next,index);
            if (listordered)
                return;

            if (index<=(count+1)/2)
            {
                curr->next = nullptr;
                listordered=true;
                return;
            }
                

            ListNode *temp = curr->next;
            curr->next = item;
            item->next = temp;
            curr = temp;
        }
    }
    ListNode *head;
    void reorderList(ListNode *head_)
    {
        head = head_;
        reorderListr(head,0);
    }
};
//1,2,3,4,5
int main()
{
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
    Solution().reorderList(head);
    return 0;
}