
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

class Solution {
public:
    void swapPairs1(ListNode* item) {
        if (item==nullptr || item->next==nullptr )
            return;

        
        ListNode* temp1=item->next->next;
        item->next->next=item;
        item->next=temp1;
        swapPairs1(temp1);
    }
    ListNode* swapPairs(ListNode* head) {
        
        ListNode* newhead=head->next;
        swapPairs1(head);
        
        return newhead;
    }
};

int main()
{
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
    ListNode *headtemp= Solution().swapPairs(head);
    return 0;
}