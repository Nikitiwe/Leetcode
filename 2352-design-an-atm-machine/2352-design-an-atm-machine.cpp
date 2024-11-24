class ATM {
private:
    vector<int> arr, a;
public:
    ATM() {
        for (int i=0; i!=5; i++) arr.push_back(0);
        a.push_back(20);
        a.push_back(50);
        a.push_back(100);
        a.push_back(200);
        a.push_back(500);
    }
    
    void deposit(vector<int> nums) {
        for (int i=0; i!=5; i++) arr[i]+=nums[i];
    }
    
    vector<int> withdraw(int n) {
        vector<int> d(5, 0);
        for (int i=4; i>=0; i--)
        {
            if (arr[i]>0&&n>=a[i])
            {
                d[i]=min(n/a[i], arr[i]);
                n-=d[i]*a[i];
            }
        }
        if (n==0)
        {
            for (int i=0; i!=5; i++) arr[i]-=d[i];
            return d;
        }
        else return {-1};
        
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */