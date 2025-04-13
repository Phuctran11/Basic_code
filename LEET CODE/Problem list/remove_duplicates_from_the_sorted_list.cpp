/*
Given the head of a sorted linked list, delete all duplicates such that each element appears only once. 
Return the linked list sorted as well.
*/

#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode * next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* deleteDuplicates(ListNode* head) {
            if (!head) return head;
            ListNode* current = head;
            while ( current->next){
                if(current->val == current->next->val){
                    ListNode* temp = current->next;
                    current->next = current->next->next;
                    delete temp;
                } else{
                    current = current->next;
                }
            }
            return head;
        }
    };

int main() {
    // Example usage
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);

    Solution solution;
    ListNode* result = solution.deleteDuplicates(head);

    // Print the result
    while (result) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;
    
    // Clean up memory
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
