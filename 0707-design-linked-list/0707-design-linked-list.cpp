class MyLinkedList {
public:
    list<int> ll;
    MyLinkedList() {
        
    }
    
    int get(int index) {
       if(index < 0 || index >= ll.size()) {
        return -1;
       }

       auto it = ll.begin();
       advance(it, index);
       return *it;
    }
    
    void addAtHead(int val) {
        ll.push_front(val);
    }
    
    void addAtTail(int val) {
        ll.push_back(val);
    }
    
    void addAtIndex(int index, int val) {
        if(index < 0 || index > ll.size()) {
            return;
        }
        auto it = ll.begin();
        advance(it, index);
        ll.insert(it, val);
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index >= ll.size()) {
            return;
        }
        auto it = ll.begin();
        advance(it, index);
        ll.erase(it);
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */