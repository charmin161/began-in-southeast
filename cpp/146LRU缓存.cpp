#include <iostream>
#include <unordered_map>

using namespace std;

// struct ListNode{
//     int key;
//     int value;
//     ListNode* next;
//     ListNode* before;
//     ListNode(): key(0), value(0), next(nullptr), before(nullptr){};
//     ListNode(int i, int j): key(i), value(j), next(nullptr), before(nullptr){};
    

// };

// class LRUcache{
// private:
//     int cap;
//     int siz;
//     unordered_map<int, ListNode*> myMap;
//     ListNode* head;
//     ListNode* tail;

// public:
//     LRUcache(int capacity){
//         this->cap = capacity;
//         this->siz = 0;
//         head = new ListNode();
//         tail = new ListNode();
//         head->next = tail;
//         tail->before = head; 
//     }
//     int deleteKey(){
//         ListNode* tmp = tail->before;
//         tail->before = tmp->before;
//         tmp->before->next = tail;
//         return tmp->key;
//     }
//     void addnewKey(ListNode* newL){
//         newL->before = head;
//         newL->next = head->next;
//         head->next->before = newL;  
//         head->next = newL;
//     }
//     void moveTohead(ListNode* node){
//         node->before->next = node->next;
//         node->next->before = node->before;
//         head->next->before = node;
//         node->next = head->next;
//         head->next = node;
//         node->before = head;
        
//     }
//     void put(int key, int value){
        
//         if(! myMap.count(key) && siz == cap){
//             int delk = deleteKey();
//             myMap.erase(delk);
//             ListNode* nodeNew = new ListNode(key, value);
//             addnewKey(nodeNew);
//             myMap[key] = nodeNew;


//         }
//         else{
//             myMap[key]->value = value;
//             moveTohead(myMap[key]);
//         }


//     }

//     int get(int key){

//         if(!myMap.count(key)) return -1;
//         else{
//             moveTohead(myMap[key]);
//             return myMap[key]->value;

//         }
//     }
    


// };


class LRUCache {
private:
    struct ListNode1{
    int key;
    int value;
    ListNode1* next;
    ListNode1* before;
    ListNode1(): key(0), value(0), next(nullptr), before(nullptr){};
    ListNode1(int i, int j): key(i), value(j), next(nullptr), before(nullptr){};
    

    };
    const int cap;
    int siz;
    unordered_map<int, ListNode1*> myMap;
    ListNode1* head;
    ListNode1* tail;

public:
    LRUCache(int capacity): cap(capacity){
        this->siz = 0;
        head = new ListNode1();
        tail = new ListNode1();
        head->next = tail;
        tail->before = head; 
    }
    int deleteKey(){
        ListNode1* tmp = tail->before;
        tail->before = tmp->before;
        tmp->before->next = tail;
        return tmp->key;
    }
    void addnewKey(ListNode1* newL){
        newL->before = head;
        newL->next = head->next;
        head->next->before = newL;  
        head->next = newL;
    }
    void moveTohead(ListNode1* node){
        node->before->next = node->next;
        node->next->before = node->before;
        head->next->before = node;
        node->next = head->next;
        head->next = node;
        node->before = head;
        
    }
    void put(int key, int value){
        
        if(!myMap.count(key)){
            
            ListNode1* nodeNew = new ListNode1(key, value);
            addnewKey(nodeNew);
            myMap[key] = nodeNew;
            siz ++;


        }
        else {
            myMap[key]->value = value;
            moveTohead(myMap[key]);
        }
        if(siz > cap){
            int delk = deleteKey();
            myMap.erase(delk);
            siz--;
        }


    }

    int get(int key){

        if(!myMap.count(key)) return -1;

        else{
            moveTohead(myMap[key]);
            return myMap[key]->value;
        }
    }
    
};

int main(){
    LRUCache* ca1 = new LRUCache(5);
    ca1->put(1, 5);
    ca1->put(2,6);
    ca1->put(2, 5);
    ca1->put(3,6);
    ca1->put(5, 5);
    ca1->put(7,6);
    for(int i = 1; i < 6; i++){
        cout<<ca1->get(i)<<endl;

    }


return 0;

}