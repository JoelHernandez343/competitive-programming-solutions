// Joel Hernández @ 2023
// https://leetcode.com/problems/binary-tree-level-order-traversal/description/

#include <queue>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

std::vector<std::vector<int>> level_order(TreeNode *root) {
    std::queue<TreeNode *> nodes;
    std::vector<std::vector<int>> result;

    if (root == nullptr) {
        return result;
    }

    nodes.push(root);
    result.push_back(std::vector<int>{root->val});

    while (!nodes.empty()) {
        auto current_nodes = nodes.size();
        auto current_level = std::vector<int>();

        while (current_nodes--) {
            auto node = nodes.front();
            nodes.pop();

            if (node->left != nullptr) {
                nodes.push(node->left);
                current_level.push_back(node->left->val);
            }

            if (node->right != nullptr) {
                nodes.push(node->right);
                current_level.push_back(node->right->val);
            }
        }

        if (current_level.size() > 0) {
            result.push_back(current_level);
        }
    }

    return result;
}

int main(void) { return 0; }