/*
 Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

Supposed the linked list is 1 -> 2 -> 3 -> 4 
and you are given the third node with value 3, the linked list should become 1 -> 2 -> 4 after calling your function. 
 */

class Solution {
public:
    void deleteNode3(ListNode* node) {
        if(node == NULL)
            return;
        node->val = node->next->val;
        node->next = node->next->next;
    }

    void deleteNode2(ListNode* node) {
        auto next = node->next;
        *node = *next;
        delete next;
    }

    void deleteNode1(ListNode* node) {
        *node = *node->next;
    }
};