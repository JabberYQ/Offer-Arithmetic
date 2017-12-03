//
//  code.c
//  C-Demo
//
//  Created by 俞琦 on 2017/10/13.
//  Copyright © 2017年 俞琦. All rights reserved.
//

// 输入一个递增排序的数组和一个数字S，在数组中查找两个数，是的他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
/*
 void getTwoNum1(int *a, int length, int n, int *x, int *y)
 {
     if (length < 2 || a == NULL) {
         return;
     }
     int left = 0;
     int right = length - 1;
     for (int i = 0; i < length; i++) {
         if (a[left] >= n || left == right) {
             break;
         } else {
             if (a[left] + a[right] > n) {
             right --;
             } else if (a[left] + a[right] < n) {
                 left ++;
             } else {
                 *x = a[left];
                 *y = a[right];
             }
         }
     }
 }
 */

// 输入一个无序的非负的数组和一个数字S，在数组中查找两个数，是的他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
/*
void getTwoNum2(int *a, int length, int n, int *x, int *y)
{
    if(a == NULL || length < 2)
        return;
    int *b = (int*)calloc(n,sizeof(int));
    int mul = -1;
    for (int i = 0; i<length; i++) {
        int left = a[i];
        if (b[left] == 1) { // 找到了
            if (mul < 0) {
                mul = (n - left) * left;
                *x = n - left;
                *y = left;
            } else {
                if (mul > (n - left) * left) {
                    mul = (n - left) * left;
                    *x = n - left;
                    *y = left;
                }
            }
        }
        if (left >= n) {
            continue;
        } else {
            b[n - left] = 1;
        }
    }
    free(b);
    b = NULL;
}
*/

// 在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
/*
int find(int *matrix, int m, int n, int t) // m行 n列
{
    if (m <= 0 || n <= 0 || matrix == NULL) {
        return 0;
    }
    int i = 0;
    int row = 0;
    int col = n - 1;
    for (; i < m + n; i ++) {
        if (matrix[row * n + col] == t) { // 相等
            return 1;
        } else if (matrix[row * i + col] > t) { // 删除列
            col--;
        } else {
            row++;
        }
    }
    return 0;
    
 
     1 2 3 4  ==> 需要判断的元素 row * n + col
     4 5 6 12
 
}
*/

// 请实现一个函数，将一个字符串中的空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
/*
char* ReplaceBlank(char *str)
{
    if (str == NULL) {
        return str;
    }
    long strLen = strlen(str);
    long blankCount = 0;
    if (strLen == 0) {
        return str;
    }
    for (int i = 0; i < strLen; i ++) { // 获得空白的字符的数量
        if (str[i] == ' ') {
            blankCount ++;
        }
    }
    if (blankCount == 0) {
        return str;
    }
    long newStrLen = strLen + blankCount;
    long newStrLast = newStrLen - 1;
    long strLast = strLen - 1;
    while (blankCount > 0 && strLast >= 0) {
        if (str[strLast] != ' ') { // 如果不是空白
            str[newStrLast--] = str[strLast--];
        } else { // 空白
            str[newStrLast--] = '2';
            str[newStrLast--] = '%';
            strLast--;
            blankCount--;
        }
    }
    return str;
}
*/

// 输入一个链表，从尾到头打印链表每个节点的值。
/*
typedef struct Node // 初始化结构体
{
    int data;
    struct Node *next;
}Node, *pNode;

pNode createList()
{
    int n = 0;
    pNode pHead = NULL;
    pNode pCur = NULL;
    while (n != -1) {
        scanf("%d", &n);
        if (n == -1) {
            break;
        }
        pNode pNew = (pNode)malloc(sizeof(pNode));
        pNew -> data = n;
        pNew -> next = NULL;
        
        if (pHead == NULL) {
            pHead = pNew;
            pCur = pNew;
        } else {
            pCur -> next = pNew;
            pCur = pNew;
        }
    }
    return pHead;
}

void destoryList(pNode pHead)
{
    if (pHead == NULL) {
        return;
    }
    pNode p = NULL;
    while (pHead) {
        p = pHead -> next;
        free(pHead);
        pHead = p;
    }
}

void printfListReverse(pNode pHead)
{
    if (pHead == NULL) {
        return;
    }
    if (pHead -> next != NULL) {
        printfListReverse(pHead -> next);
    }
    printf("%d ", pHead -> data);
}
*/
