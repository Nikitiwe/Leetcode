class MyCircularDeque {
private:
    vector<int> arr;
    int l, r, s, k;
public:
    MyCircularDeque(int kk) {
        l=0; r=0; s=0; k=kk;
        for (int i=0; i!=k; i++) arr.push_back(0);
    }
    
    bool insertFront(int v) {
        if (s==0)
        {
            arr[l]=v;
            s++;
            return 1;
        }
        else if (s==k) return 0;
        else
        {
            l=(l-1+k)%k;
            arr[l]=v;
            s++;
            return 1;
        }
    }
    
    bool insertLast(int v) {
        if (s==0)
        {
            arr[r]=v;
            s++;
            return 1;
        }
        else if (s==k) return 0;
        else
        {
            r=(r+1)%k;
            arr[r]=v;
            s++;
            return 1;
        }
        
    }
    
    bool deleteFront() {
        if (s==0) return 0;
        else if (s==1)
        {
            s--;
            return 1;
        }
        else
        {
            l=(l+1)%k;
            s--;
            return 1;
        }
    }
    
    bool deleteLast() {
        if (s==0) return 0;
        else if (s==1)
        {
            s--;
            return 1;
        }
        else
        {
            r=(r-1+k)%k;
            s--;
            return 1;
        }
    }
    
    int getFront() {
        if (s==0) return -1;
        else return arr[l];
    }
    
    int getRear() {
        if (s==0) return -1;
        else return arr[r];
    }
    
    bool isEmpty() {
        if (s==0) return 1;
        else return 0;
    }
    
    bool isFull() {
        if (s==k) return 1;
        else return 0;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */