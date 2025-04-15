class Spreadsheet {
public:
    unordered_map<string, int> m;
    int maxrow;
    Spreadsheet(int rows) {
        maxrow = rows;
        return;
    }
    
    void setCell(string cell, int value) {
        m[cell] = value;
    }
    
    void resetCell(string cell) {
        m[cell] = 0;
    }
    
    int getValue(string f) {
        string a, b;
        bool isp = 0;
        for (int i=1; i<f.size(); i++)
        {
            if (f[i] != '+' && isp == 0) a += f[i];
            else if (f[i] != '+' && isp == 1) b += f[i];
            else if (f[i] == '+') isp = 1;
        }
        int ans = 0;
        if ( a[0] >= 'A' && a[0] <= 'Z' ) ans +=m[a];
        else
        {
            int add = 0;
            for (int i=0; i<a.size(); i++)
            {
                add *= 10;
                add += a[i] - '0';
            }
            ans += add;
        }
        if ( b[0] >= 'A' && b[0] <= 'Z' ) ans +=m[b];
        else
        {
            int add = 0;
            for (int i=0; i<b.size(); i++)
            {
                add *= 10;
                add += b[i] - '0';
            }
            ans += add;
        }
        return ans;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */