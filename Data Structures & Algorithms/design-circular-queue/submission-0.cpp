struct ListNode {
    int val;
    ListNode* next;
};

class MyCircularQueue {
    const int cap;
    int sz;
    ListNode* head;
    ListNode* tail;

public:
    MyCircularQueue(int k): cap(k), sz(0), head(nullptr), tail(nullptr) {}
    
    bool enQueue(int value) {
        if (sz == cap) return false;
        ListNode* node  = new ListNode{ value, nullptr };
        if (sz == 0) head = tail = node;
        else {
            tail->next = node;
            tail = node;
        }
        ++sz;
        return true;
    }
    
    bool deQueue() {
        if (sz == 0) return false;
        ListNode* old = head;
        head = head->next;
        delete old;
        if (--sz == 0) tail = nullptr;
        return true;
    }
    
    int Front() {
        return sz ? head->val : -1;
    }
    
    int Rear() {
        return sz ? tail->val : -1;
    }
    
    bool isEmpty() {
        return sz == 0 ? true : false;
    }
    
    bool isFull() {
        return sz == cap ? true : false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */