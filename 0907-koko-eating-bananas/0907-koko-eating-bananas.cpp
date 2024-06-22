class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int k=1;
        long long time=0;
        for (k; k!=2147483646; k=k+100)
        {
            time=0;
            for (int i=0; i!=piles.size(); i++)
            {
                if(piles[i]%k!=0) {time=time+piles[i]/k+1;}
                else {time=time+piles[i]/k;}
            }
            if (time<=h) break;
        }
        for (k=max(k-100,1); k!=2147483646; k=k+1)
        {
            time=0;
            for (int i=0; i!=piles.size(); i++)
            {
                if(piles[i]%k!=0) {time=time+piles[i]/k+1;}
                else {time=time+piles[i]/k;}
            }
            if (time<=h) break;
        }        
        return k;
    }

/*        while (time<h)
        {
            for (int i=0; i!=piles.size(); i++)
            {
                if(piles[i]%k!=0) {time=time+piles[i]/k+1;}
                else {time=time+piles[i]/k;}
            }
            k=k+100;
        }
        while (time>=h)
        {
            for (int i=0; i!=piles.size(); i++)
            {
                if(piles[i]%k!=0) {time=time+piles[i]/k+1;}
                else {time=time+piles[i]/k;}
            }
            if (k>1) {k=k--;}
            else return 1;
        }
        if (k>1) return k+1;
        else return 1;
    }*/

/*        int k=1, kmax=2147483646, kold=0;
        long long time=0;
        while (k!=kold)
        {
            for (int i=0; i!=piles.size(); i++)
            {
                if(piles[i]%k!=0) {time=time+piles[i]/k+1;}
                else {time=time+piles[i]/k;}
            }
            if (time>h) {kold=k; k=(k+kmax)/2;}
            else if (time<h) {kold=k; kmax=k; k=k/2;}
            else if (time==h) {if (k>0) {kold=k; k=k-1;}}
            time=0;
            if (abs(kold-k)<2)
            {
                for (int j=max(k,kold); j!=0; j--)
                {
                    time=0;
                    for (int i=0; i!=piles.size(); i++)
                    {
                    if(piles[i]%j!=0) {time=time+piles[i]/j+1;}
                    else {time=time+piles[i]/j;}
                    }
                    if (time<h) return j+1;
                }
                return 1;
            }
        }
        return 1;
    }*/
};