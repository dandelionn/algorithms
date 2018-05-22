#include <iostream>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  }a;
int max(int x,int y)
    {if(x>=y)
      return x;
    else
      return y;}

int maxDepth(TreeNode *root) {
    if( root->left==NULL && root->right==NULL )
           return 0;
    else
          if( root->left!=NULL && root->right!=NULL )
              return max(1+maxDepth(root->left),1+maxDepth(root->right));
          else
             if( root->left!=NULL )
                 return 1+maxDepth(root->left);
             else
                 return 1+maxDepth(root->right);
    }
int main()
{
    cout<<maxDepth(a);
}
