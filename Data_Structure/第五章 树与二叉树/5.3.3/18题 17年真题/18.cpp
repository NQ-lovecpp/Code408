#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>



// 定义二叉树结点
typedef struct node {
    char data; // 存储操作数或操作符
    struct node *left, *right;
} BTree;

// 创建一个新的节点
BTree* createNode(char data) {
    BTree* newNode = (BTree*)malloc(sizeof(BTree));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 将表达式树转换为中缀表达式的递归函数
void toInfixExpression(BTree* root) {
    if(root == nullptr) return;
    if(root->left == nullptr && root->right == nullptr) {
        std::cout << root->data;
        return;
    }

    if(root->left) {
        if(root->left->left || root->left->right) std::cout << "(";
        toInfixExpression(root->left);
        if(root->left->left || root->left->right) std::cout << ")";
    }

    std::cout << root->data;

    if(root->right) {
        if(root->right->left || root->right->right) std::cout << "(";
        toInfixExpression(root->right);
        if(root->right->left || root->right->right) std::cout << ")";
    }

    return;
}

int main() {
    // 示例构造一棵表达式树
    BTree* root = createNode('*');
    root->left = createNode('+');
    root->right = createNode('*');
    root->left->left = createNode('a');
    root->left->right = createNode('b');
    root->right->left = createNode('c');
    root->right->right = createNode('-');
    root->right->right->right = createNode('d');

    toInfixExpression(root);
    // 记得释放已分配的内存...
    
    return 0;
}

