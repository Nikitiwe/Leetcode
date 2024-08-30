class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long ans;
        long long l=0, r=100000000000000, m=(l+r)/2;
        while (l<r)
        {
            ans=0;
            for (int i=0; i!=time.size(); i++)
            {
                ans+=m/time[i];
            }
            if (ans>totalTrips) {r=m-1; m=(l+r)/2;}
            else {l=m+1; m=(l+r)/2;}
        }
        ans=0;
        for (int i=0; i!=time.size(); i++)
        {
            ans+=m/time[i];
        }
        while (ans>=totalTrips&&m>1)
        {
            m--;
            ans=0;
            for (int i=0; i!=time.size(); i++)
            {
                ans+=m/time[i];
            }
        }
        int ans1=0;
        for (int i=0; i!=time.size(); i++)
        {
            ans1+=(m+1)/time[i];
        }
        if (ans1>=totalTrips&&ans<totalTrips) return m+1;
        else return m;
    }
};