#include <bits/stdc++.h>

using namespace std;

class ListNode{
public:
    int value;
    ListNode* next;
    ListNode(int value){
        this->value = value;
        next = nullptr;
    }
};

ListNode* reverse(ListNode* head){
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while(curr != nullptr){
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    } // prev will have the new head
    return prev;
}

int main() {

    return 0;
}