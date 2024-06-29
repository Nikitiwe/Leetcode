class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int sum=0, count=0, i=0, l, r, e, isit=1;
        vector<int> a, b(2, -1), c{0,2};
        for (i=0; i!=arr.size(); i++) {if (arr[i]==1) sum++;}
        if (sum%3!=0) return b;
        if (sum==0) return c;
        sum=sum/3;
        int sum2=2*sum, sum3=3*sum;
        i=0;
        for (i=0; i!=arr.size(); i++)
        {
            if (arr[i]==1)
            {
                count++;
                if (count==sum) l=i;
                if (count==sum2) r=i;
                if (count==sum3) {e=i; break;}
            }
        }
        i=0; count=0;
        while (count<sum)
        {
            if (arr[l-i]==arr[r-i]&&arr[r-i]==arr[e-i]) {i++; if (arr[l]==1) count++;}
            else {isit=0; break;}
        }
        int j=1;
        if (isit==1)
        {
            while (e+j<arr.size())
            {
                if (arr[l+j]==0&&arr[r+j]==0&&arr[e+j]==0) j++;
                else {isit=0; break;}
            }
        }
        if (isit==1) {a.push_back(l+j-1); a.push_back(r+j); return a;}
        else return b;
    }
};