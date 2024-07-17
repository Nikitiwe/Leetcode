class Solution {
public:
    string countAndSay(int n) {
        string prev="1", next;
        int count;
        if (n==1) return "1";
        else if (n==2) return "11";
        else {
        for (int i=0; i!=n-1; i++)
        {
            count=1;
            for (int j=0; j<prev.size()-1; j++)
            {
                if (prev[j]==prev[j+1]) {count++;}
                else
                {
                    next+=to_string(count);
                    next+=prev[j];
                    count=1;
                }
            }
            next+=to_string(count);
            next+=prev[prev.size()-1];
            prev=next;
            next.clear();
        }   }
        return prev;
    }
};