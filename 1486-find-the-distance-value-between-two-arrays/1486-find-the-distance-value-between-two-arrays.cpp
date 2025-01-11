class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int ans=0;
        for (int i=0; i!=arr1.size(); i++)
        {
            int l=0, r=arr2.size()-1, m;
            bool isit=0;
            while (l<=r)
            {
                m=(l+r)/2;
                if (abs(arr1[i]-arr2[m])<=d)
                {
                    isit=1;
                    break;
                }
                else if (arr2[m]>arr1[i]) r=m-1;
                else l=m+1;
            }
            if (isit==0) ans++;
        }
        return ans;
    }
};