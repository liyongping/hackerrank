#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3

begin to intersect at node c1.

Notes:

    If the two linked lists have no intersection at all, return null.
    The linked lists must retain their original structure after the function returns.
    You may assume there are no cycles anywhere in the entire linked structure.
    Your code should preferably run in O(n) time and use only O(1) memory.
 */


/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /*
    Two pointer solution (O(n+m) running time, O(1) memory):
    Maintain two pointers pA and pB initialized at the head of A and B, respectively. 
    Then let them both traverse through the lists, one node at a time.
    When pA reaches the end of a list, then redirect it to the head of B (yes, B, that's right.); 
    similarly when pB reaches the end of a list, redirect it the head of A.
    If at any point pA meets pB, then pA/pB is the intersection node.
    To see why the above trick would work, consider the following two lists: A = {1,3,5,7,9,11} and B = {2,4,9,11}, 
    which are intersected at node '9'. Since B.length (=4) < A.length (=6), 
    pB would reach the end of the merged list first, 
    because pB traverses exactly 2 nodes less than pA does. By redirecting pB to head A, and pA to head B, 
    we now ask pB to travel exactly 2 more nodes than pA would. 
    So in the second iteration, they are guaranteed to reach the intersection node at the same time.
    If two lists have intersection, then their last nodes must be the same one. So when pA/pB reaches the end of a list, record the last element of A/B respectively. If the two last elements are not the same one, then the two lists have no intersections.
    
    假设headA的链表长度是LA，headB的长度是LB，交接点对于headA来说在第3个位置，对于headB来说是第1个位置
    那么有：
    PA走过的路程= LA+ 1  ==  LB + 3 PB走过的路程
    */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL)
            return NULL;

        ListNode *pa =headA, *pb = headB;
        ListNode *tailA =NULL, *tailB = NULL;

        while(true){
            if(pa == NULL)
                pa = headB;
            if(pb == NULL)
                pb = headA;

            if(pa->next == NULL)
                tailA = pa;
            if(pb->next == NULL)
                tailB = pb;

            if(tailA != NULL && tailB!= NULL && tailA != tailB)
                return NULL;

            if(pa == pb)
                return pa;

            pa = pa->next;
            pb = pb->next;
        }

        return NULL;
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
    ListNode *px = NULL;
    int j = 5;
    for(int i=1; i< 9; i++){
        ListNode *node = new ListNode(i);
        pcurr->next = node;
        pcurr = pcurr->next;

        if(i == j){
            px = pcurr;
        }
    }

    ListNode *head2 = new ListNode(11);
    head2->next = px;

    printList(head);
    printList(head2);

    cout<<s.getIntersectionNode(head,head2)->val <<endl;

    return 0;
}