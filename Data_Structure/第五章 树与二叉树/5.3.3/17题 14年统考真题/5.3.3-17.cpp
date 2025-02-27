#include <iostream>
#include <queue>


using namespace std;

struct BinaryListNode {
    unsigned int weight;
    BinaryListNode* left;
    BinaryListNode* right;
};

// 计算二叉树带权路径长度
// 就是所有叶节点的带权路径长度之和

int WPL(BinaryListNode* root, int cur_depth)
{
    // 如果当前节点为空，则返回0，表示这里没有WPL
    if(root == nullptr) {
        return 0;
    }

    // 如果当前节点是叶子节点
    if(root->left == nullptr && root->right == nullptr) {
        return cur_depth * root->weight;
    } 
    // 不是叶节点
    else {
        return WPL(root->left, cur_depth + 1) + WPL(root->right, cur_depth + 1);
    }
}

// 二叉树的WPL = 树中所有非叶子节点的权值之和
int WPL2(BinaryListNode* root)
{
    // 判空
    if(root == nullptr) {
        return 0;
    }

    // 如果是叶子节点，把它当作0，不加入计算
    if(root->left == nullptr && root->right == nullptr) {
        return 0;
    }

    // 其余情况，递归左子树的WPL，和右子树的WPL，和当前节点的权重加在一起
    int left = WPL2(root->left);
    int right = WPL2(root->right);
    root->weight = root->left->weight + root->right->weight;
    return left + right + root->weight;
}

std::queue<BinaryListNode*> node_queue;

void Sequence_traversal(BinaryListNode* root)
{
    if (root == nullptr)
    {
        return;
    }

    std::queue<BinaryListNode*> current_level;
    std::queue<BinaryListNode*> next_level;
    current_level.push(root);

    while (!current_level.empty())
    {
        while (!current_level.empty())
        {
            BinaryListNode* node = current_level.front();
            current_level.pop();

            std::cout << node->weight << " ";

            if (node->left != nullptr)
            {
                next_level.push(node->left);
            }
            if (node->right != nullptr)
            {
                next_level.push(node->right);
            }
        }
        std::cout << std::endl;

        while (!next_level.empty())
        {
            BinaryListNode* node = next_level.front();
            next_level.pop();

            if (node->left != nullptr || node->right != nullptr)
            {
                if (node->left != nullptr)
                {
                    std::cout << "/";
                }
                else
                {
                    std::cout << " ";
                }

                if (node->right != nullptr)
                {
                    std::cout << " \\";
                }
                else
                {
                    std::cout << "  ";
                }
            }
            std::cout << " ";
            current_level.push(node);
        }
        std::cout << std::endl;
    }
}

int main()
{
    // create a tree
    //           1
    //        /     \
    //      2         3
    //    /   \     /   \
    //   4     5   6     7
    //  / \   /
    // 8   9 10
    BinaryListNode* root = new BinaryListNode();
    root->weight = 1;
    root->left = new BinaryListNode();
    root->left->weight = 2;
    root->right = new BinaryListNode();
    root->right->weight = 3;
    root->left->left = new BinaryListNode();
    root->left->left->weight = 4;
    root->left->right = new BinaryListNode();
    root->left->right->weight = 5;
    root->right->left = new BinaryListNode();
    root->right->left->weight = 6;
    root->right->right = new BinaryListNode();
    root->right->right->weight = 7;
    root->left->left->left = new BinaryListNode();
    root->left->left->left->weight = 8;
    root->left->left->right = new BinaryListNode();
    root->left->left->right->weight = 9;
    root->left->right->left = new BinaryListNode();
    root->left->right->left->weight = 10;
    
    Sequence_traversal(root);

    std::cout << std::endl << WPL2(root) << std::endl;


    return 0;
}