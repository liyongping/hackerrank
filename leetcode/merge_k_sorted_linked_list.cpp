#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
Merge k sorted linked lists and return it as one sorted list. 
Analyze and describe its complexity. 
 */


/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
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

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        ListNode dummy(-1);
        // l1 points to l1 list's current node
        // l2 points to l2 list's current node
        // pcurr points to new list's current node
        ListNode *pcurr = &dummy;
        while(l1 && l2){
            if(l1->val < l2->val){
                pcurr->next = l1;
                l1 = l1->next;
            }else{
                pcurr->next = l2;
                l2 = l2->next;
            }
            pcurr = pcurr->next;
        }

        // if l1 goes to end node, just append l2 to new list.
        // if l2 goes to end node, just append l1 to new list.
        pcurr->next = l1 == NULL ? l2 : l1;

        return dummy.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return NULL;
        
        int end = lists.size() - 1;
        int begin = 0;

        vector<ListNode*> tmp;
        while(end > 0){
            begin = 0;
            while(end > begin){
                lists[begin] = mergeTwoLists(lists[begin],lists[end]);
                begin ++;
                end --;
            }
        }
        return lists[0];

    }
};


int main(int argc, char const *argv[])
{
    Solution s;

    ListNode *head1 = new ListNode(0); 
    ListNode *pcurr = head1;
    for(int i=2; i < 20; i+=2){
        ListNode *node = new ListNode(i);
        pcurr->next = node;
        pcurr = pcurr->next;

    }

    ListNode *head2 = new ListNode(1); 
    pcurr = head2;
    for(int i=3; i < 21; i+=2){
        ListNode *node = new ListNode(i);
        pcurr->next = node;
        pcurr = pcurr->next;

    }

    ListNode *head3 = new ListNode(-1); 
    pcurr = head3;
    for(int i=0; i < 10; i++){
        ListNode *node = new ListNode(i);
        pcurr->next = node;
        pcurr = pcurr->next;

    }
    vector<ListNode*> lists;
    lists.push_back(head1);
    lists.push_back(head2);
    lists.push_back(head3);

    printList(head1);
    printList(head2);
    printList(head3);

    printList(s.mergeKLists(lists));

    return 0;
}