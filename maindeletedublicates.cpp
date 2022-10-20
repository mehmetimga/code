
#include <iostream>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* prev= new ListNode(0,head);
        ListNode* prevOrg=prev;
        while(head)
        {
            if (head->next!=nullptr && head->val==head->next->val)
            {
                while(head->next!=nullptr && head->val == head->next->val)
                {
                    head=head->next;
                }
                prev->next=head->next;
            }
            else
            {
                prev=prev->next;
            }
            head=head->next;
        }
        return prevOrg->next;
    }
};

int main()
{
    ListNode* node=new ListNode(10);
    node->next==new ListNode(5);
    node->next->next==new ListNode(70);
    node->next->next->next==new ListNode(7);
    cout << "" << Solution().deleteDuplicates(node);
}