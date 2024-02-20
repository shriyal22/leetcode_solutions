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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || head->next == NULL || left == right) return head;
        ListNode* dummy = new ListNode;
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* next = NULL;

        int n = right - left;
        for(int i=0;i<left-1;i++) prev=prev->next;
        
        ListNode* temp = prev->next;
        while(n--){
            next = temp->next;
            temp->next=next->next;
            next->next = prev->next;
            prev->next = next;
        }
        return dummy->next;
    }
};