class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        vector<int> arr(5, 0);
        for (int i=0; i!=croakOfFrogs.size(); i++)
        {
            if (croakOfFrogs[i]=='c') arr[0]++;
            else if (croakOfFrogs[i]=='r') arr[1]++;
            else if (croakOfFrogs[i]=='o') arr[2]++;
            else if (croakOfFrogs[i]=='a') arr[3]++;
            else arr[4]++;
        }
        if (arr[0]!=arr[1]||arr[0]!=arr[2]||arr[0]!=arr[3]||arr[0]!=arr[4]) return -1;
        int c=0, r=0, o=0, a=0, k=0, ans=0, f=0;
        for (int i=0; i!=croakOfFrogs.size(); i++)
        {
            if (croakOfFrogs[i]=='c')
            {
                c++;
                if (f>0) {ans++; f--;}
            }
            else if (croakOfFrogs[i]=='r')
            {
                r++;
                if (r>c) return -1;
            }
            else if (croakOfFrogs[i]=='o')
            {
                o++;
                if (o>r) return -1;
            }
            else if (croakOfFrogs[i]=='a')
            {
                a++;
                if (a>o) return -1;
            }
            else
            {
                k++;
                if (k>a) return -1;
                f++;
            }
        }
        return arr[0]-ans;
    }
};