#include <iostream>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
     TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 

class Solution {
public:
    
    int maxlength=0;
    int diameterOfBinaryTree(TreeNode* root) {
        depthOfBinaryTree(root);
        return maxlength;
    }
    
    int depthOfBinaryTree(TreeNode* node) {
        if (node == nullptr)
            return 0;
        int left=depthOfBinaryTree(node->left);
        int right=depthOfBinaryTree(node->right);
        maxlength=max(maxlength,left+right);
        return max(left,right)+1;
        
    }
};

int main()
{
    TreeNode* root=new TreeNode(1,new TreeNode(2,new TreeNode(4),new TreeNode(5)),new TreeNode(3));
    int value= Solution().diameterOfBinaryTree(root);
    cout << "value="<< value<<endl;
    return 0;

}