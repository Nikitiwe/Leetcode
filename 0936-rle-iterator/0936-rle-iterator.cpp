class RLEIterator {
private:
    vector<vector<int>> arr;
    int l;
public:
    RLEIterator(vector<int>& e) {
        arr.clear();
        for (int i=0; i<e.size(); i+=2) // сколько; чего
        {
            if (arr.size()==0) arr.push_back({e[i], e[i+1]});
            else
            {
                if (arr[arr.size()-1][1]==e[i+1])
                {
                    arr[arr.size()-1][0]+=e[i];
                }
                else arr.push_back({e[i], e[i+1]});
            }
        }
        l=0;
        
    }
    
    int next(int n) {
        int sum=0;
        while (sum<n)
        {
            if (l>=arr.size()) return -1;
            if (arr[l][0]>=n-sum)
            {
                arr[l][0]-=n-sum;
                sum=n;
                if (arr[l][0]==0)
                {
                    l++;
                    return arr[l-1][1];
                }
                else return arr[l][1];
            }
            else
            {
                sum+=arr[l][0];
                l++;
            }
        }
        return -1;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */