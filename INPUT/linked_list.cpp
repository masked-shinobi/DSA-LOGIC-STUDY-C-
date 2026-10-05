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

ListNode* creation(vector<int> arr){
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for( int i = 0; i < arr.size(); i++){
        ListNode* node = new ListNode(arr[i]);
        if(head == nullptr){
            head = node;
            tail = node;
        }else{
            tail->next = node;
            tail = tail->next;
        }
    }
    return head;
}

int main() {
    /*
    input taken as vector
    worked on it by passing this vector
    */
    vector<int> arr = {1,2,3,4,5,6};
    ListNode* head = creation(arr);
    return 0;
}