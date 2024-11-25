class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int s=0;
        for (int i=0; i!=arr.size(); i++) s+=arr[i];
        if (s%3!=0) return 0;
        s/=3;
        int l=1, r=arr.size()-2, sl=arr[0], sr=arr[arr.size()-1];
        while (l<arr.size()&&sl!=s)
        {
            sl+=arr[l];
            l++;
        }
        if (l==arr.size()||sl!=s) return 0;
        l--;
        while (r>=0&&sr!=s)
        {
            sr+=arr[r];
            r--;
        }
        r++;
        if (r==0||sr!=s) return 0;
        if (l>=r-1) return 0;
        return 1;
    }
};