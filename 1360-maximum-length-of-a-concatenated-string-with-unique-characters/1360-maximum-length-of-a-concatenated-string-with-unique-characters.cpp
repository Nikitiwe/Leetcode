class Solution {
public:
    int maxLength(vector<string>& arr) {
        //if (arr.size()==1) return arr[0].size();
        int ans=0, n=arr.size(), a=2;
        while (n>1)
        {
            a*=2;
            n--;
        }
        for (int k=1; k<a; k++)
        {
            vector<int> nums(26, 0), temp, zero=nums;
            int i=k, l=0, d=0;
            bool isit=1;
            while (i>0&&isit==1)
            {
                if (i%2==1)
                {
                    temp=zero;
                    d+=arr[l].size();
                    for (int j=0; j!=arr[l].size(); j++)
                    {
                        temp[arr[l][j]-'a']++;
                    }
                    for (int j=0; j!=26; j++)
                    {
                        if (temp[j]==1) nums[j]++;
                        else if (temp[j]>1)
                        {
                            isit=0;
                            break;
                        }
                    }
                    if (isit==0) break;
                }
                l++;
                i/=2;
            }
            for (int j=0; j!=26; j++)
            {
                if (nums[j]>1)
                {
                    isit=0;
                    break;
                }
            }
            if (isit==1) ans=max(ans, d);
        }
        return ans;
    }
};