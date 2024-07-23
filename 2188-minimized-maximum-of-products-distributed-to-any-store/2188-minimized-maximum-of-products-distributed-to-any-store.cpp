class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        long long sum=0;
        for (int i=0; i!=quantities.size(); i++)
        {
            sum+=quantities[i];
        }
        long long l=sum/n, ans=l, temp=n, r=2*ans+2*quantities.size();
        if (ans==0) return 1;
        if (sum%n>0) ans++;
        while (l<r-1)
        {
            temp=n;
            for (int i=0; i!=quantities.size(); i++)
            {
                temp-=(quantities[i]/ans);
                if (quantities[i]%ans>0) temp--;
            }
            if (temp>=0) {ans=(ans+l)/2; r=(l+r)/2;}
            else {l=ans; ans=(ans+r)/2;}
        }
        temp=n;
            for (int i=0; i!=quantities.size(); i++)
            {
                temp-=(quantities[i]/ans);
                if (quantities[i]%ans>0) temp--;
            }
        if (temp>=0) return ans;
        else ans++;
        return ans;
    }
};