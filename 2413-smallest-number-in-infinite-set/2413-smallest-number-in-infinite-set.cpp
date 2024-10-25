class SmallestInfiniteSet {
private:
    vector<int> arr;
    int l;
public:
    SmallestInfiniteSet() {
        vector<int> t(1001, 1);
        arr=t;
        arr[0]=0;
        l=0;
    }
    
    int popSmallest() {
        while (arr[l]==0) l++;
        arr[l]=0;
        return l;
    }
    
    void addBack(int num) {
        arr[num]=1;
        l=min(l, num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */