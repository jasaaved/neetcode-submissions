class MyCircularQueue {
public:
    MyCircularQueue(int k) : q(k) {
        front = 0;
        rear = 0;
        size = 0;
        capacity = k;
    }
    
    bool enQueue(int value) {
        if(isFull()){
            return false;
        }

        q[rear] = value;
        ++size;
        
        rear = (rear + 1) % capacity;

        return true;
    }
    
    bool deQueue() {
        if(isEmpty()){
            return false;
        }

        --size;
        front = (front + 1) % capacity;
        
        return true;
    }
    
    int Front() {
        return size == 0 ? -1 : q[front];
    }
    
    int Rear() {
        return size == 0 ? -1 : q[(rear - 1 + capacity) % capacity];
    }
    
    bool isEmpty() {
        return !size;
    }
    
    bool isFull() {
        return size == capacity;
    }

private:
    vector<int> q;
    int front;
    int rear;
    int size;
    int capacity;
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