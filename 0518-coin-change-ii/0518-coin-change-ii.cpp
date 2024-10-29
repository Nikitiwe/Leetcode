class Solution {
public:
    int change(int s, vector<int>& c) {
        vector<long> arr(s+1, 0);
        arr[0]=1;
        for(int i=0; i!=c.size(); i++)
        {
            for (int j=0; j!=arr.size(); j++)
            {
                if ((long)c[i]+j<arr.size()) 
                {
                    arr[(long)c[i]+j]+=arr[j];
                    if (arr[(long)c[i]+j]>10000000000) return 0;
                }
            }
        }
        return arr[s];
    }
};