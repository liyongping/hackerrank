#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
1.Given a linked list, determine if it has a cycle in it. 
2.Get the cycle length
3.如何找到环中第一个节点
4. 如何将有环的链表变成单链表（解除环）？
5. 如何判断两个单链表是否有交点？
先判断两个链表是否有环，如果一个有环一个没环，肯定不相交；
如果两个都没有环，判断两个列表的尾部是否相等；
如果两个都有环，判断一个链表上的Z点是否在另一个链表上。
 */


/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {

        ListNode * twostep = head;
        ListNode * onestep = head;
        // 因为fast指针比slow指针走得快，所以只要判断fast指针是否为空就好
        while(twostep !=NULL && twostep->next != NULL){
            twostep = twostep->next->next;
            onestep = onestep->next;
            // if they meet at same node, it's an cycle linked list.
            if(onestep == twostep){
                return true;
            }
        }
        return false;
    }
    /*
    第一次相遇后，让fast停着不走了，slow继续走，记录到下次相遇时循环了几次, 就是cycle的长度
     */
    int getCycleLength1(ListNode *head) {
        int steps = 0;
        bool hadMet = false;

        ListNode * twostep = head;
        ListNode * onestep = head;
        // 因为fast指针比slow指针走得快，所以只要判断fast指针是否为空就好
        while(twostep !=NULL && twostep->next != NULL){
            //第一次相遇后，让fast停着不走了，slow继续走，记录到下次相遇时循环了几次
            if (!hadMet)
            {
                twostep = twostep->next->next;
            }else{
                steps ++;
            }
            onestep = onestep->next;
            // if they meet at same node, it's an cycle linked list.
            if(onestep == twostep){
                if(hadMet == false)
                    hadMet = true;
                else{
                    return steps;
                }
            }
        }
        return steps;
    }

    int getCycleLength2(ListNode *head) {
        int steps = 0;
        bool hadMet = false;

        ListNode * twostep = head;
        ListNode * onestep = head;
        // 因为fast指针比slow指针走得快，所以只要判断fast指针是否为空就好
        while(twostep !=NULL && twostep->next != NULL){
            //第一次相遇后，让fast停着不走了，slow继续走，记录到下次相遇时循环了几次
            if (hadMet){
                steps ++;
            }
            twostep = twostep->next->next;
            onestep = onestep->next;
            // if they meet at same node, it's an cycle linked list.
            if(onestep == twostep){
                if(hadMet == false)
                    hadMet = true;
                else{
                    return steps;
                }
            }
        }
        return steps;
    }
};


int main(int argc, char const *argv[])
{
    Solution s;
    /*
    0 --> 1 --> 2 --> 3 --> 4 --> 5
                      |           |
                      |           |
                      8 <-- 7 <-- 6
     */
    // 2 4 6 8 4 6 8 4 6 8
    // 1 2 3 4 5 6 
    ListNode *head = new ListNode(0); 
    ListNode *pcurr = head;
    ListNode *px = NULL;
    int j = 7;
    for(int i=1; i< 9; i++){
        ListNode *node = new ListNode(i);
        pcurr->next = node;
        pcurr = pcurr->next;

        if(i == j){
            px = pcurr;
        }
    }

    pcurr->next = px;
/*
    ListNode *l1 = new ListNode(1); head->next = l1;
    ListNode *l2 = new ListNode(2); l1->next = l2;
    ListNode *l3 = new ListNode(3); l2->next = l3;
    ListNode *l4 = new ListNode(4); l3->next = l4;
    ListNode *l5 = new ListNode(5); l4->next = l5;
    ListNode *l6 = new ListNode(6); l5->next = l6;
    ListNode *l7 = new ListNode(7); l6->next = l7;
    ListNode *l83 = new ListNode(8); l7->next = l83;
    l83->next = l3;
*/
    cout<<s.hasCycle(head)<< endl;
    cout<<s.getCycleLength1(head)<< endl;
    cout<<s.getCycleLength2(head)<< endl;
    /* code */
    return 0;
}