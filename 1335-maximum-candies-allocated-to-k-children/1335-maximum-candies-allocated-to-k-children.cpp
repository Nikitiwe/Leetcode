class Solution {
public:
    int maximumCandies(vector<int>& can, long long k) {
        long long l=0, r=*max_element(can.begin(), can.end()), m=(l+r)/2, ans=0, temp;
        while (l<r)
        {
            if (m==0) m++;
            temp=0;
            for (int i=0; i!=can.size(); i++)
            {
                temp+=can[i]/m;
            }
            if (temp<k) {r=m-1;}
            else {l=m; r++;}
            m=(l+r)/2;
            //if (m==0) return 0;
        }
        return m;
    }
};