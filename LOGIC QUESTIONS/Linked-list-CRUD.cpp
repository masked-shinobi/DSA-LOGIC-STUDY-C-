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

// OP - insert - start, mid, end  - delete - start, mid, end
ListNode* insertatstart(ListNode* head, int value) {
    ListNode* newNode = new ListNode(value);
    newNode->next = head;
    return newNode;
}

ListNode* deleteatstart(ListNode* head) {
    if (head == nullptr)
        return nullptr;

    ListNode* curr = head;
    head = head->next;

    delete curr;

    return head;
}

ListNode* insertatend(ListNode*head, int value){
    if(head == nullptr){
        return insertatstart(head, value);
    }
    ListNode* tail = head;
    while(tail->next != nullptr){
        tail = tail->next;
    }
    ListNode* newNode = new ListNode(value);
    tail->next = newNode;

    return head;
}

ListNode* deleteatend(ListNode* head) {
    if (head == nullptr) {
        return nullptr;
    }

    // Only one node
    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }

    ListNode* curr = head;

    // Reach second-last node
    while (curr->next->next != nullptr) {
        curr = curr->next;
    }

    delete curr->next;
    curr->next = nullptr;

    return head;
}

ListNode* insertatposition(ListNode* head, int value, int pos) {
    ListNode* newNode = new ListNode(value);

    // Insert at beginning
    if (pos == 1) {
        newNode->next = head;
        return newNode;
    }

    ListNode* curr = head;

    // Reach node before the position
    for (int i = 1; i < pos - 1 && curr != nullptr; i++) {
        curr = curr->next;
    }

    // Invalid position
    if (curr == nullptr) {
        delete newNode;
        return head;
    }

    newNode->next = curr->next;
    curr->next = newNode;

    return head;
}

ListNode* deleteatposition(ListNode* head, int pos) {
    if (head == nullptr) {
        return nullptr;
    }

    // Delete first node
    if (pos == 1) {
        ListNode* curr = head;
        head = head->next;
        delete curr;
        return head;
    }

    ListNode* curr = head;

    // Reach node before the position
    for (int i = 1; i < pos - 1 && curr != nullptr; i++) {
        curr = curr->next;
    }

    // Invalid position
    if (curr == nullptr || curr->next == nullptr) {
        return head;
    }

    ListNode* temp = curr->next;
    curr->next = temp->next;
    delete temp;

    return head;
}

int main(){

    return 0;
}