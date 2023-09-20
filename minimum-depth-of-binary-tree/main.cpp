// Joel Hernández @ 2023
// https://leetcode.com/problems/minimum-depth-of-binary-tree/description/

#include <iostream>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int min_depth(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }

    auto left_depth = min_depth(root->left);
    auto right_depth = min_depth(root->right);

    if (left_depth == 0) {
        return 1 + right_depth;
    } else if (right_depth == 0) {
        return 1 + left_depth;
    }

    return 1 + std::min(left_depth, right_depth);
}

int min_depth_no_recurse(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }

    std::queue<TreeNode *> queue;
    queue.push(root);

    int min_height = 0;

    while (!queue.empty()) {
        min_height++;
        auto current_nodes = queue.size();

        while (current_nodes--) {
            auto node = queue.front();

            if (node->left == nullptr && node->right == nullptr) {
                return min_height;
            }
            if (node->left) {
                queue.push(node->left);
            }
            if (node->right) {
                queue.push(node->right);
            }

            queue.pop();
        }
    }

    return min_height;
}

int main(void) { return 0; }