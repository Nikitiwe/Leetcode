class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        int ans=-1;
        for (int i=0; i!=24; i++)
        {
            if ((arr[0]<2&&arr[2]<=5)||(arr[0]==2&&arr[1]<=3&&arr[2]<=5))
            {
                int t=arr[0]*600+arr[1]*60+arr[2]*10+arr[3];
                ans=max(ans, t);
            }
            next_permutation(arr.begin(), arr.end());
        }
        string s;
        if (ans==-1) return s;
        s+=to_string(ans/600);
        ans%=600;
        s+=to_string(ans/60);
        s+=":";
        ans%=60;
        s+=to_string(ans/10);
        ans%=10;
        s+=to_string(ans);
        return s;
    }
};