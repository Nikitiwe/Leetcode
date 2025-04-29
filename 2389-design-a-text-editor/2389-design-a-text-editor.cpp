class TextEditor {
public:
    stack<char> l, r;
    int i;
    TextEditor() {
        i = 0;
        return;
    }
    
    void addText(string s) {
        for (int i=0; i!=s.size(); i++) l.push(s[i]);
    }
    
    int deleteText(int k) {
        int ans = 0;
        while (l.size() > 0)
        {
            l.pop();
            ans++;
            if (ans == k) break;
        }
        return ans;
    }
    
    string cursorLeft(int k) {
        int c = 0;
        while (l.size() > 0)
        {
            r.push(l.top());
            l.pop();
            c++;
            if (c == k) break;
        }
        string ans;
        while (l.size() > 0)
        {
            ans += l.top();
            l.pop();
            if (ans.size() == 10) break;
        }
        reverse(ans.begin(), ans.end());
        addText(ans);
        return ans;
    }
    
    string cursorRight(int k) {
        int c = 0;
        while (r.size() > 0)
        {
            l.push(r.top());
            r.pop();
            c++;
            if (c == k) break;
        }
        string ans;
        while (l.size() > 0)
        {
            ans += l.top();
            l.pop();
            if (ans.size() == 10) break;
        }
        reverse(ans.begin(), ans.end());
        addText(ans);
        return ans;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */