#include <iostream>
#include <queue>
using namespace std;
typedef struct BitreeNode
{
    int val;
    struct BitreeNode *lc, *rc;
} BitreeNode;
//先序遍历
void PreOder(BitreeNode *tree)
{
    if (tree != NULL)
    {
        cout << tree->val << " ";
        PreOder(tree->lc);
        PreOder(tree->rc);
    }
}
//中序遍历
void InOder(BitreeNode *tree)
{
    if (tree != NULL)
    {
        InOder(tree->lc);
        cout << tree->val << " ";
        InOder(tree->rc);
    }
}
//后序遍历
void AfOder(BitreeNode *tree)
{
    if (tree != NULL)
    {
        AfOder(tree->lc);
        AfOder(tree->rc);
        cout << tree->val << " ";
    }
}
//层序遍历
void LevelOrder(BitreeNode *tree)
{
    queue<BitreeNode*>q;
    q.push(tree);
    while (!q.empty())
    {
        BitreeNode* temp=q.front();
        q.pop();
        cout<<temp->val<<endl;
        if (temp->lc!=NULL)
        {
           q.push(temp->lc);
        }
        if (temp->rc!=NULL)
        {
            q.push(temp->rc);
        }
    }
}
int main()
{
    system("pause");
    return 0;
}