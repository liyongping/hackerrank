#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5. 

思路：其实很简单，遍历一遍链表，把小于x的都挂到head1后，
把大于等于x的都放到head2后，
最后再把大于等于的链表挂到小于链表的后面就可以了。

 */


/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL)
            return head;

        ListNode *smallH = new ListNode(-1);
        ListNode *greaterH = new ListNode(-1);

        ListNode *sp = smallH, *gp = greaterH, *curr = head;
        while(curr){
            if(curr->val < x){
                sp->next = curr;
                sp = sp->next;
            }else{
                gp->next = curr;
                gp = gp->next;
            }

            curr = curr->next;
        }

        sp->next = greaterH->next;
        gp->next = NULL;

        delete greaterH;
        sp = smallH->next;
        delete smallH;

        return sp;//smallH->next;
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

    for(int i=10; i>0; i--){
        ListNode *node = new ListNode(i);
        pcurr->next = node;
        pcurr = pcurr->next;
    }


    printList(head);
    //printList(s.reverseBetween(head,1,1));
    printList(s.partition(head,5));

    return 0;
}