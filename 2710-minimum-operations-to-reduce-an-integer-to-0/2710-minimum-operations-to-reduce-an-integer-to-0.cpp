class Solution {
public:
    int minOperations(int n) {
        int ans=0, i=0;
        vector<int> pow;
        while (n>0)
        {
            pow.push_back(n%2);
            n/=2;
        }
        pow.push_back(0);
        pow.push_back(0);
        while (i<=pow.size()-2)
        {
            if (pow[i]==1&&pow[i+1]==0) {ans++; i++; i++;}
            else if (pow[i]==1&&pow[i+1]==1)
            {
                ans++;
                while (pow[i]==1)
                {
                    i++;
                }
                pow[i]=1;
            }
            else i++;
        }
        return ans;
    }
};