/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class comp{
    public : 
    bool operator()( ListNode* a , ListNode* b )
    {
        return a->val > b->val ;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue< ListNode* , vector<ListNode*> , comp> minHeap ;
        for( int i = 0 ; i < lists.size() ; i++ )
        {
            if(lists[i] != NULL )
                minHeap.push(lists[i]) ; 
        }
        ListNode* head = NULL ,*tail = NULL ;
        while(!minHeap.empty())
        {
            ListNode* node = minHeap.top() ;
            minHeap.pop() ;
            
            if( node->next != NULL )
                minHeap.push(node->next) ;
            
            if(head == NULL )
            {
                head = node ;
                tail = node ;
            }
            else 
            {
                tail->next = node ;
                tail = node ;
            }
        }
        return head ;
        
    }
};