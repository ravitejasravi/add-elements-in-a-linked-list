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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum, carry=0;
        ListNode* sum_list = new ListNode(-1);
        ListNode* cur = sum_list;
        
        
        while(l1 != NULL || l2 != NULL)
        {
            if(l1 == NULL)
            {
                sum = (l2 -> val) + carry; 
            }
            else if (l2 == NULL)
            {
                sum = (l1 -> val) + carry;
            }
            else
            {
                 sum = (l1 -> val) + (l2 -> val) + carry;
            }
           
            carry = 0;
            if(sum >= 10)
            {
                carry = 1;
                sum = sum % 10;
            }
        
            cur -> next = new ListNode(sum);
            cur = cur -> next;
            
            if(l1 != NULL)
            l1 = l1 -> next;
            if(l2 != NULL)
            l2 = l2 -> next;
        }
        if(carry > 0)
        {
            cur -> next = new ListNode(carry);
            cur = cur -> next; 
        }
        return sum_list -> next;
    }
};