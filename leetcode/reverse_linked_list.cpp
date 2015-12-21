#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
Reverse a singly linked list.

click to show more hints.
Hint:

A linked list can be reversed either iteratively or recursively. Could you implement both?


 */


/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // iteractively
    ListNode* reverseList(ListNode* head) {
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

    // recursion
    ListNode* reverseList2(ListNode* head) {
        if(head ==NULL){
            return NULL;
        }

        if(head->next == NULL)
            return head;

        ListNode * curr = head->next;

        //here will return new head node.
        ListNode * newHead = reverseList2(curr);

        // reverse next pointer
        curr->next = head;

        head->next = NULL;
        
        return newHead;
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

    ListNode* newHead = s.reverseList(head);
    printList(newHead);

    printList(s.reverseList2(newHead));

    return 0;
}