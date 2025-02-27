#include <stdio.h>
#include <stdbool.h>
#include <climits>

#define MAX_SIZE 100 // 根据需要自行定义

// 顺序存储的二叉树结构
typedef struct {
    int SqBiTNode[MAX_SIZE]; // 保存二叉树节点值的数组
    int ElemNum;             // 实际占用的数组元素个数
} SqBiTree;


// 判定函数的实现
bool isBST(SqBiTree* tree, int i, int* cur_max) {
    if(i < tree->ElemNum && tree->SqBiTNode[i] != -1) {
        // 左树不是BST，整个树就不是
        if(isBST(tree, i * 2 + 1, cur_max) == false) return false;

        // 更新遍历的最大值，当前节点应该小于左子树的最大值
        if(!(*cur_max < tree->SqBiTNode[i])) return false;

        // 更新最大值
        *cur_max = tree->SqBiTNode[i];

        // 遍历右子树
        if(isBST(tree, i * 2 + 2, cur_max) == false) return false;
    }

    return true;

}

// 主函数
int main() {
    // 示例：构造二叉树 T1
    SqBiTree T1 = {
        .SqBiTNode = {40, 25, 60, -1, 30, -1, 80, -1, -1, 27},
        .ElemNum = 10
    };

    // 示例：构造二叉树 T2
    SqBiTree T2 = {
        .SqBiTNode = {40, 50, 60, -1, 30, -1, -1, -1, -1, -1, 35},
        .ElemNum = 11
    };

    int* max = new int(INT_MIN);
    // 调用判定函数
    printf("T1 is %s BST\n", isBST(&T1, 0, max) ? "a" : "not a");
    printf("T2 is %s BST\n", isBST(&T2, 0, max) ? "a" : "not a");

    return 0;
}


