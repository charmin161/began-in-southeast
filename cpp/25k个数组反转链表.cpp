#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int i): val(i), next(nullptr){};
    ListNode(): val(0), next(nullptr){};
    
};

int main(){

    ListNode* head = new ListNode(0);
    ListNode* cur = head;
    for(int i = 0; i < 10; i ++){
        cur->next = new ListNode(i);
        cur = cur->next;
    }
    ListNode* reversed = reverseKGroup(head, 5);
    cur = reversed;
    while(cur){
        cout << cur->val << endl;
        cur = cur->next；
    }
}
ListNode* reverseK(ListNode* head, int k){
        ListNode* root = new ListNode(0);
        root->next = head;
        ListNode* cur = head;
        ListNode* pre = root;
        while(k > 0){
            pre->next = cur->next;
            cur->next = cur->next->next;
            pre->next = cur;
            pre = pre->next;
            cur = cur->next;
            k--;
        }
        return root->next;
    }
    
ListNode* reverseKGroup(ListNode* head, int k){
    ListNode* root = new ListNode(0);
    root->next = head;
    ListNode* cur = head;
    ListNode* pre = root;
    while(cur){
        ListNode* firL = cur;
        int j = k;
        while(j > 0){
            firL = firL->next;
            j--;
        }
        if(j > 0) return root->next;
        pre->next = reverseK(cur, k);
        cur = cur->next;
        pre = pre->next;
    }
    



    return root->next;
}