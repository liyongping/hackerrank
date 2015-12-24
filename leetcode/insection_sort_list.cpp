#include <iostream>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;


/*
Sort a linked list using insertion sort.
插入排序

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
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(INT_MIN);

        //关键，其实我们是在构建新的链表，这样可以简化操作，只是移动原来链表上的节点到新的dummy链表上
        //dummy->next = head;

        ListNode *icurr = head, *jcurr = NULL, *tmp = NULL,
                    *insertNode = &dummy;
        while(icurr){
            // find insert position, we will insert one node after it
            jcurr = &dummy;
            while(jcurr && jcurr->val < icurr->val){
                insertNode = jcurr;
                jcurr = jcurr->next;
            }

            tmp = icurr->next;
            icurr->next = insertNode->next;
            insertNode->next = icurr;

            icurr = tmp;
        }

        return dummy.next;
    }

    // will implement a better solution 24ms: like https://leetcode.com/discuss/37574/explained-c-solution-24ms
    ListNode* insertionSortList2(ListNode* head) {
        ListNode dummy(INT_MIN);
        dummy.next = head;

        ListNode *icurr = head, *jcurr = NULL, *tmp = NULL,
                    *insertNode = &dummy;
        while(icurr && icurr->next){
            // find insert position, we will insert one node after it
            jcurr = &dummy;
            while(jcurr && jcurr->val < icurr->next->val){
                insertNode = jcurr;
                jcurr = jcurr->next;
            }
            if(insertNode == icurr){ // don't find insert position, don't need to move it
                icurr = icurr->next;
            }else{
                tmp = icurr->next->next;
                icurr->next->next = insertNode->next;
                insertNode->next = icurr->next;
                icurr->next = tmp;
            }
        }

        return dummy.next;
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

    ListNode *head = new ListNode(-2147483647); 
    ListNode *pcurr = head;

    for(int i=1; i>0; i--){
        ListNode *node = new ListNode(-2147483648);
        pcurr->next = node;
        pcurr = pcurr->next;
    }

    cout<< INT_MIN << endl;
    printList(head);
    //printList(s.reverseBetween(head,1,1));
    printList(s.insertionSortList(head));

    return 0;
}