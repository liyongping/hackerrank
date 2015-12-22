#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list. 

 */


/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == NULL)
            return head;

        ListNode *dummy = new ListNode(-1);
        dummy->next = head;

        ListNode *reverseHead = dummy;
        ListNode *firstListTail = NULL;
        int i = m;

        while(i-- > 0){
            firstListTail =reverseHead;
            reverseHead = reverseHead->next;
        }

        ListNode *curr = reverseHead, *tmp = NULL, *pre = NULL;
        i = n-m+1;
        while(i-- > 0){
            tmp = curr->next;
            curr->next = pre;
            pre = curr;
            curr = tmp;
        }

        reverseHead->next = curr;
        firstListTail->next = pre;

        tmp = dummy->next;
        delete dummy;

        return tmp;
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
    for(int i=1; i< 9; i++){
        ListNode *node = new ListNode(i);
        pcurr->next = node;
        pcurr = pcurr->next;
    }


    printList(head);
    //printList(s.reverseBetween(head,1,1));
    printList(s.reverseBetween(head,1,9));

    return 0;
}