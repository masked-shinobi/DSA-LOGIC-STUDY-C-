#include <bits/stdc++.h>

using namespace std;

class ListNode{
public:
    int v;
    ListNode* next;
    ListNode(int v){
        this->v = v;
        next = nullptr;
    }
};

// first mid 
ListNode* returnfirstmid(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast->next != nullptr && fast->next->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    if(head->next->next != nullptr){ // is to bring the fast pointer to the last
        fast->next;
    }
    return slow;
}

// second mid
ListNode* returnsecondmid(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main(){

    return 0;
}