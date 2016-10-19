#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5 
 */


/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode *head);

class Solution {
public:
    // iteractively
    ListNode* reverseList(ListNode* head, int k) {
        if(head ==NULL){
            return NULL;
        }

        ListNode *pre= NULL, *curr=head;
        ListNode * saveNext = NULL;
        while(curr){
            saveNext = curr->next;
            curr->next = pre;
            pre = curr;
            curr = saveNext;
        }

        return pre;
    }


    ListNode *reverseKGroup3(ListNode *head, int k) {
        if (!head || k == 1) return head;
        int listLen = 0;
        ListNode preHead(0);
        preHead.next = head;
        ListNode* cur = &preHead, *pre = &preHead, *next = NULL;
        while (cur = cur -> next) listLen++;
        while (listLen >= k) {
            cur = pre -> next;
            next = cur -> next;
            for (int i = 0; i < k - 1; i++) {
                cur -> next = next -> next;
                next -> next = pre -> next;
                pre -> next = next;
                next = cur -> next;
            }
            pre = cur;
            listLen -= k;
        }
        return preHead.next;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        //if (!hasKNodes(head, k)) return head;
        ListNode* new_head = new ListNode(0);
        new_head -> next = head;
        ListNode* pre = new_head;
        ListNode* cur = head;
        while (hasKNodes(cur, k)) {
            for (int i = 0; i < k - 1; i++) {
                ListNode* temp = pre -> next;
                pre -> next = cur -> next;
                cur -> next = cur -> next -> next;
                pre -> next -> next = temp; 
            }
            pre = cur;
            cur = pre -> next;
        }
        return new_head -> next;
    }
private:
    // try to find if there are k nodes, and move node pointer to end
    bool hasKNodes(ListNode* node, int k) {
        int cnt = 0;
        while (node) {
            cnt++;
            if (cnt >= k) return true;
            node = node -> next;
        }
        return false; 
    }
};

void printList(ListNode *head){
    if(head == NULL)
        return ;

    ListNode *curr = head;
    while(curr != NULL){
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    Solution s;

    ListNode *head = new ListNode(0); 
    ListNode *pcurr = head;
    for(int i=1; i< 10000000; i++){
        ListNode *node = new ListNode(i);
        pcurr->next = node;
        pcurr = pcurr->next;
    }


    //printList(head);
    s.reverseKGroup(head,3);
    //printList(head);

    return 0;
}