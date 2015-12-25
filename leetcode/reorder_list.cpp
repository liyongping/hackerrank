#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}. 

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

    void reorderList(ListNode* head) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *fast = &dummy, *slow = &dummy;

        // find mid node by slow and fast pointer
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }

        //slow->next will be the head of second list.
        ListNode *list2 = slow->next;
        slow->next = NULL;

        list2 = reverseList(list2);

        // p1 points to l1 list's current node
        // p2 points to l2 list's current node
        ListNode* p1 = dummy.next, *p2 = list2;
        while(p1 && p2){
                ListNode *tmp = p2->next;
                p2->next = p1->next;
                p1->next = p2;

                p1 = p2->next;
                p2 = tmp;
        }
        head = dummy.next;
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
    s.reorderList(head);
    printList(head);

    return 0;
}