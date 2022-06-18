#include <bits/stdc++.h>
using namespace std;


struct DLinkedNode {
    int key;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode(): key(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key): key(_key), prev(nullptr), next(nullptr) {}
};
void addToHead(DLinkedNode* node,DLinkedNode* head) {
    node->prev = head;
    node->next = head->next;
    head->next->prev = node;
    head->next = node;
}

void removeNode(DLinkedNode* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
}

void moveToHead(DLinkedNode* node,DLinkedNode* head) {
    removeNode(node);
    addToHead(node,head);
}

DLinkedNode* removeTail(DLinkedNode* tail) {
    DLinkedNode* node = tail->prev;
    removeNode(node);
    return node;
}
int stat_hit_count(vector<int>& R, int N){
    unordered_map<int, DLinkedNode*> cache;
    
    DLinkedNode* head = new DLinkedNode();
    DLinkedNode* tail = new DLinkedNode();
    head->next = tail;
    tail->prev = head;
    int size = 0;
    int ans = 0;
    for(int i = 0; i < R.size(); i++){
        int tmp = R[i];
        if (!cache.count(tmp)) {

            DLinkedNode* node = new DLinkedNode(tmp);
            cache[tmp] = node;
            addToHead(node, head);
            ++size;
            if (size > N) {
                // 如果超出容量，删除双向链表的尾部节点
                DLinkedNode* removed = removeTail(tail);
                // 删除哈希表中对应的项
                cache.erase(removed->key);
                // 防止内存泄漏
                delete removed;
                --size;
            }
        }
        else {
            DLinkedNode* node = cache[tmp];
            moveToHead(node,head);
            ans++;
        }
    }
    return ans;
}

int main(){
    vector<int> A = {1,2,1,2,2};
    cout<<stat_hit_count(A,2);

    return 0;
}