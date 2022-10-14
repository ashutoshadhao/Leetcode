/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode() : val(0), next(nullptr) {}
 *    ListNode(int x) : val(x), next(nullptr) {}
 *    ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* deleteMiddle(ListNode *head)
        {
            ListNode *slow = head;
            ListNode *fast = head;
            if(fast->next == NULL )
            {
                return NULL ;
            }
            if( fast->next->next == NULL ) 
            {
                slow->next = NULL ;
                return slow ;
            }
            while (fast->next and fast->next->next)
            {
                slow = slow->next;
                fast = fast->next->next;
                if (fast->next != NULL and fast->next->next == NULL)
                    slow = slow->next;
            }
            slow->val = slow->next->val;
            slow->next = slow->next->next;
            return head; 
        }
};