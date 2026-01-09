class Solution {
public:
    int depth(TreeNode* root) {
        if(root == NULL) return 0;
        return 1 + max(depth(root->left), depth(root->right));
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(root == NULL) return NULL;

        int leftDepth = depth(root->left);
        int rightDepth = depth(root->right);

        if(leftDepth == rightDepth)
            return root;
        else if(leftDepth > rightDepth)
            return subtreeWithAllDeepest(root->left);
        else
            return subtreeWithAllDeepest(root->right);
    }
};
