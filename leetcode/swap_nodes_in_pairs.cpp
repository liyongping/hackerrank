#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. 
You may not modify the values in the list, only nodes itself can be changed. 
 */


/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL)
            return head;

        ListNode* p1 = head, 
                *p2 =head->next, 
                *newHead = head->next,
                *pre = NULL;
        while(p1 != NULL && p2 != NULL) {
            //swap p1 vs p2
            p1->next = p2->next;
            p2->next = p1;

            // after swap, append current first node to pre list.
            if(pre){
                pre->next = p2;
            }

\
            if(p1->next != NULL){
                pre = p1;
                // move p1, p2
                p1 = p1->next;
                p2 = p1->next; 
            }else{
                break;
            }
        }

        // list just has one node.
        return newHead != NULL? newHead : head;
    }

    /*
    从最后两个元素开始调换
     */
    ListNode *swapPairs2(ListNode *head) {
       if (head == NULL)
            return NULL;
       if (head -> next == NULL)
            return head;
       ListNode *tmp = head -> next;
       head -> next = swapPairs(tmp -> next);
       tmp -> next = head;
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

    for(int i=1; i< 100; i++){
        ListNode *node = new ListNode(i);
        pcurr->next = node;
        pcurr = pcurr->next;
    }
    printList(head);

    pcurr = s.swapPairs(head);
    printList(pcurr);
    printList(s.swapPairs2(pcurr));

    return 0;
}