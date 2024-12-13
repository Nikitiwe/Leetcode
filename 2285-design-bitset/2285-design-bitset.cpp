class Bitset {
private:
    vector<int> arr, arn;
    int s, isa;
public:
    Bitset(int n) {
        vector<int> t(n, 0), r(n, 1);
        arr=t;
        arn=r;
        s=0;
        isa=1;
    }
    
    void fix(int idx) {
        if (isa==1&&arr[idx]==0)
        {
            arr[idx]++;
            arn[idx]--;
            s++;
        }
        else if (isa==0&&arn[idx]==0)
        {
            arn[idx]++;
            arr[idx]--;
            s++;
        }
    }
    
    void unfix(int idx) {
        if (isa==1&&arr[idx]==1)
        {
            arr[idx]--;
            arn[idx]++;
            s--;
        }
        else if (isa==0&&arn[idx]==1)
        {
            arr[idx]++;
            arn[idx]--;
            s--;
        }
    }
    
    void flip() {
        s=arr.size()-s;
        isa=1-isa;
    }
    
    bool all() {
        if (s==arr.size()) return 1;
        else return 0;
    }
    
    bool one() {
        if (s>=1) return 1;
        else return 0;
    }
    
    int count() {
        return s;        
    }
    
    string toString() {
        string ans;
        if (isa==1) for (int i=0; i!=arr.size(); i++)
        {
            if (arr[i]==1) ans+='1';
            else ans+='0';
        }
        else for (int i=0; i!=arr.size(); i++)
        {
            if (arn[i]==1) ans+='1';
            else ans+='0';
        }
        return ans;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */