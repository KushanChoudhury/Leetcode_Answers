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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set numsset(nums.begin(),nums.end());
        while(head!=NULL&&numsset.find(head->val)!=numsset.end()){
            ListNode *temp=head;
            head=head->next;
            delete(temp);
        }
        ListNode* currNode=head;
        while(currNode!=NULL&&currNode->next!=NULL){
            if(numsset.find(currNode->next->val)!=numsset.end()){
            ListNode *temp=currNode->next;
            currNode->next=currNode->next->next;
            delete(temp);
            }
            else{
                currNode=currNode->next;
            }
        }
        return head;
    }
};