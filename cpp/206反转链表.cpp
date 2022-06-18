#include <iostream>
#include <vector>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr){};
    ListNode(int i): val(i), next(nullptr){};
    ListNode(int i, ListNode* nxt): val(i), next(nxt){};
};

class Solution1 {
public:
    ListNode* reverseList(ListNode* head){
        if(head == nullptr || head->next == nullptr) return head;
        
        ListNode* pre = head;
        ListNode* cur = head->next;
        while(cur){
            pre->next = cur->next;
            cur->next = head;
            head = cur;
            cur = pre->next;

        }
        return head;


        
    }

};

int main(){

    ListNode *head1 = new ListNode(0);
    //head1 0->1->2-> .... ->9
    ListNode *cur =  head1;
    for (int i = 1; i < 10; i++){
        cur->next = new ListNode(i);
        cur = cur->next;
    }
    Solution1 solu1;
    ListNode *head2 = solu1.reverseList(head1);
    while(head2 != nullptr){
        cout<<head2->val<<endl;
        head2 = head2->next;
    } 


    return 0;
}