class Bank {
private:
    vector<long long> nums;
public:
    Bank(vector<long long>& balance) {
        nums=balance;
    }
    
    bool transfer(int a1, int a2, long long m) {
        if (0<a1&&a1<=nums.size()&&0<a2&&a2<=nums.size()&&m<=nums[a1-1])
        {
            nums[a1-1]-=m;
            nums[a2-1]+=m;
            return 1;
        }
        else return 0;
    }
    
    bool deposit(int a, long long m) {
        if (0<a&&a<=nums.size())
        {
            nums[a-1]+=m;
            return 1;
        }
        else return 0;
    }
    
    bool withdraw(int a, long long m) {
        if (0<a&&a<=nums.size()&&m<=nums[a-1])
        {
            nums[a-1]-=m;
            return 1;
        }
        else return 0;
        
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */