#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

 */


/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int length = getListlen(head);
        if(length < 2){
            return head;
        }
        int realk = k % length;
        if(realk < 1)
            return head;

        int steps = length - realk -1;

        ListNode *pre  = head;
        while(steps--)
            pre = pre->next;
        // pre->next will be new heads
        ListNode * newHead = pre->next;
        pre->next = NULL;

        // re-link the tail to old head
        ListNode *tail = newHead;
        while(tail && tail->next){
            tail = tail->next;
        }
        tail->next = head;

        return newHead;
    }

    int getListlen(ListNode *head){
        ListNode* curr = head;
        int length = 0;
        while(curr){
            length ++;
            curr = curr->next;
        }
        return length;
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
    for(int i=1; i< 10; i++){
        ListNode *node = new ListNode(i);
        pcurr->next = node;
        pcurr = pcurr->next;
    }

    printList(head);
    printList(s.rotateRight(head,2));
    //cout<< <<endl;

    return 0;
}