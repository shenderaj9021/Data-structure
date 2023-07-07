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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* d1 = headA;
        ListNode* d2 = headB;
        while(d1!=NULL && d2!=NULL){
            d1=d1->next;
            d2 = d2->next;
        }
        if(d1==NULL){
            d1 = headB;
        }else if(d2==NULL){
            d2 = headA;
        }
        while(d1!=NULL && d2!=NULL){
            d1 = d1->next;
            d2 = d2->next;
        }
        if(d2==NULL){
            d2 = headA;

        }else if(d1==NULL){
            d1 = headB;
        }
        while(d1!=NULL && d2!=NULL){
            if(d1==d2){
                return d1;
            }
            d1 = d1->next;
            d2 = d2->next;
        }
        return NULL;

    }
};