class MyCircularQueue {
private:
        vector<int> arr;       
        int l, r, size;
public:
    MyCircularQueue(int k) {
        arr.clear();
        for (int i=0; i!=k; i++)
            arr.push_back(0);
        size=k;
        l=-1;
        r=-1;
    }
    
    bool enQueue(int value) {
        if ((r+1)%size==l) return 0;
        else
        {
            if (l==-1)
            {
                l=0;
                r=0;
                arr[r]=value;
            }
            else {
            r=(r+1)%size;
            arr[r]=value;
            }
            return 1;
        }
    }
    
    bool deQueue() {
        if (l==-1) return 0;
        if (l==r) {r=-1; l=-1;}
        else l=(l+1)%size;
        return 1;
    }
    
    int Front() {
        if (l==-1) return -1;
        else return arr[l];
        
    }
    
    int Rear() {
        if (l==-1) return -1;
        else return arr[r];
        
    }
    
    bool isEmpty() {
        if (l==-1) return 1;
        else return 0;        
    }
    
    bool isFull() {
        if ((r+1)%size==l) return 1;
        else return 0;
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