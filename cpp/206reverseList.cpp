#include <bits/stdc++.h>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode (): val(0), next(nullptr){}
    ListNode (int v): val(v), next(nullptr){}
    ListNode (int v, ListNode* n): val(v), next(nullptr){}


};
//双指针

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head ||!head->next) return head;


        ListNode* pre = nullptr;
        ListNode* cur = head;
        while(cur){
            ListNode* nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }

};

int main(){
    ListNode *root = new ListNode();
    ListNode *cur = root;
    for(int i = 0; i < 10; i++){
        cur->next = new ListNode(i);
        cur = cur->next;
    }

    Solution sol1;
    root = sol1.reverseList2(root);
    cur = root;
    while(cur){
        cout<<cur->val<<endl;
        cur = cur->next;
    }
    return 0;
}