class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans=0;
        for (int i=0; i!=nums.size(); i++)
        {
            int t=nums[i], s=1, l=2;
            vector<int> arr;
            while (t>=l)
            {
                if (t%l==0)
                {
                    arr.push_back(l);
                    s+=l;
                    t/=l;
                }
                else l++;
                if (arr.size()>3) break;
            }
            if (arr.size()==2&&arr[0]!=arr[1]) ans+=s+arr[0]*arr[1];
            else if (arr.size()==3&&arr[0]==arr[1]&&arr[1]==arr[2]) ans+=1+arr[0]*(1+arr[0]*(1+arr[0]));
        }
        return ans;
    }
};