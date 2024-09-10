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
    int gcd(int a , int b){
        while(b!=0){
            int temp=b;
            b=a%b;
            a=temp;
        }
        return a;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp=head;
        while(temp!=NULL&&temp->next!=NULL){
            int hcf=gcd(temp->val,temp->next->val);
            ListNode* newNode=new ListNode(hcf);
            ListNode* nextNode=temp->next;
            temp->next=newNode;
            newNode->next=nextNode;
            temp=temp->next->next;
        }
        return head;
    }
};