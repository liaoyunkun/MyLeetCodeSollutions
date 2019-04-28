/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p1=head;
        ListNode* p2=head;
        for(auto i=0;i<n;i++){
            p2 = p2->next;
        }
        while(p2 && p2->next){
            p2 = p2->next;
            p1 = p1->next;
        }
        if(p2){
            ListNode* target = p1->next;
            p1->next = target->next;
            delete target;
            return head; 
        }else{
            ListNode* target = head;
            head = head->next;
            delete target;
            return head;
        }
        
    }
};