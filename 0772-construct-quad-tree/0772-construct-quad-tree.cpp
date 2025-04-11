/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* f(vector<vector<int>>& g, int x, int xx, int y, int yy)
    {
        Node* root = new Node;
        int v = g[x][y];
        bool iseq = 1;
        for (int i=x; i<xx; i++)
        {
            for (int j=y; j<yy; j++)
            {
                if (g[i][j] != v)
                {
                    iseq = 0;
                    break;
                }
            }
        }
        if (iseq == 1)
        {
            root->val = v;
            root->isLeaf = 1;
        }
        else
        {
            root->val = v;
            root->isLeaf = 0;
            root->topLeft = f(g, x, (x+xx)/2, y, (y+yy)/2);
            root->topRight = f(g, x, (x+xx)/2, (y+yy)/2, yy);
            root->bottomLeft = f(g, (x+xx)/2, xx, y, (y+yy)/2);
            root->bottomRight = f(g, (x+xx)/2, xx, (y+yy)/2, yy);
        }
        return root;
    }

    Node* construct(vector<vector<int>>& g) {
        return f(g, 0, g.size(), 0, g[0].size());
    }
};