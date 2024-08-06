class Solution {
public:
    int minimumBuckets(string h) {
        if (h.size()==1&&h[0]=='H') return -1;
        if (h.size()==1&&h[0]!='H') return 0;
        if (h[0]=='H'&&h[1]=='H') return -1;
        if (h[h.size()-1]=='H'&&h[h.size()-2]=='H') return -1;
        if (h.size()==2&&h[0]=='H'&&h[1]=='H') return -1;
        if (h.size()==2&&(h[0]=='H'||h[1]=='H')) return 1;
        if (h.size()==2) return 0;
        int ans=0;
        for (int i=1; i<h.size()-1; i++)
        {
            if (h[i-1]=='H'&&h[i]=='H'&&h[i+1]=='H') return -1;
        }
        for (int i=1; i<h.size()-1; i++)
        {
                 if (h[i-1]=='.'&&h[i]=='H'&&h[i+1]=='H') {h[i-1]='b'; h[i]='.';}
            else if (h[i-1]=='H'&&h[i]=='.'&&h[i+1]=='H') {h[i]='b'; h[i+1]='.';}
            else if (h[i-1]=='H'&&h[i]=='H'&&h[i+1]=='.') {h[i+1]='b';}
            else if (h[i-1]=='H'&&h[i]=='.'&&h[i+1]=='.') {h[i]='b';}
        }
        for (int i=0; i<h.size(); i++)
        {
            if (h[i]=='b') ans++;
        }
        if (h[h.size()-1]=='H'&&h[h.size()-2]=='.') ans++;
        if (h[h.size()-2]=='H'&&h[h.size()-1]=='.') ans++;
        return ans;
    }
};