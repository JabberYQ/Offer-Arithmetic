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
typedef struct Node
{
    int data;
    struct Node *next;
}Node, *pNode;

pNode createList()
{
    pNode pHead = NULL;
    pNode pCur = NULL;
    int n = 0;
    while (n != -1) {
        scanf("%d", &n);
        if (n == -1) {
            break;
        }
        pNode pNew = (pNode)malloc(sizeof(Node));
        pNew -> data = n;
        pNew -> next = NULL;
        
        if (pHead == NULL) { // 如果头为空，设置头和当前的节点 都为 新节点
            pHead = pNew;
            pCur = pHead;
        } else {
            pCur -> next = pNew; // 把当前的节点的下一个赋值为新节点
            pCur = pNew; // 赋值完后 把当前的节点设置为新节点
        }
    }
    return pHead;
}

void destroyList(pNode pHead)
{
    if(pHead == NULL)
        return;
    pNode p = NULL;
    while(pHead != NULL) {
        p = pHead->next;
        free(pHead);
        pHead = p;
    }
}

void printfReverseList(pNode pHead)
{
    if(pHead == NULL)
        return;
    if(pHead->next != NULL)
        printfReverseList(pHead->next);
    printf("%d ",pHead->data);
}
*/

//输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字
/*
typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}*pTree;

int isTree;

void rebuildTree(int len, int *pre, int *in, pTree *tree)
{
    if (pre == NULL || in == NULL) {
        isTree = 0;
        return;
    }
    
    if (len < 1) {
        return;
    }
    
    int head = pre[0]; // 获得头
    int i;
    for (i = 0; i < len; i++) {
        if (head == in[i]) {
            break;
        }
    }
    if (i >= len) {
        isTree = 0;
        return;
    }
    *tree = (pTree)malloc(sizeof(pTree));
    (*tree)->data = head;
    (*tree)->left = NULL;
    (*tree)->right = NULL;
    rebuildTree(i, pre + 1, in, &((*tree)->left));
    rebuildTree(len - i - 1, pre + i + 1, in + i + 1, &((*tree)->right));
}

void BehTraverse(pTree tree)
{
    if (tree -> left != NULL) {
        BehTraverse(tree->left);
    }
    if (tree -> right != NULL) {
        BehTraverse(tree->right);
    }
    printf("%d ", tree -> data);
}

void destory(pTree tree)
{
    if (tree -> left != NULL) {
        destory(tree->left);
    }
    if (tree -> right != NULL) {
        destory(tree->right);
    }
    free(tree);
}
*/

//用两个栈来实现一个队列，完成队列的Push和Pop操作。
/*
typedef struct Node
{
    int data;
    struct Node *next;
}*pNode;

typedef struct Stack
{
    pNode top;
    pNode bottom;
}*pStack;


pStack createStack()
{
    pStack stack = (pStack)malloc(sizeof(pStack));
    pNode node = (pNode)malloc(sizeof(pNode));
    stack -> top = node;
    stack -> bottom = stack -> top;
    stack -> bottom -> next = NULL;
    return stack;
}

void pushStack(pStack stack, int value)
{
    pNode node = (pNode)malloc(sizeof(pNode));
    node -> data = value;
    node-> next = stack -> top;
    stack -> top = node;
}

int isEmptyStack(pStack stack)
{
    if (stack -> top == stack -> bottom) {
        return 1;
    } else {
        return 0;
    }
}

int popStack(pStack stack, int *value)
{
    if (isEmptyStack(stack)) {
        return 0;
    } else {
        pNode node = stack -> top;
        *value = node -> data;
        stack -> top = node -> next;
        free(node);
        return 1;
    }
}

void clearStack(pStack stack)
{
    if(isEmptyStack(stack))
        return ;
    else {
        pNode p = stack -> top;
        pNode r = NULL;
        while(p != stack -> bottom)
        {
            r = p -> next;
            free(p);
            p = r;
        }
        stack -> top = stack -> bottom;
    }
}

void inQueue(pStack stack1, pStack stack2, int value) // 进队列
{
    pushStack(stack1, value);
}

int outQueue(pStack stack1, pStack stack2, int* value)
{
    if (isEmptyStack(stack1) && isEmptyStack(stack2)) { //都为空
        return 0;
    }
    
    if (isEmptyStack(stack2)) { // 把1的给2
        int v = 0;
        while (!isEmptyStack(stack1)) {
            popStack(stack1, &v);
            pushStack(stack2, v);
        }
    }
    popStack(stack2, value);
    return 1;
}
*/

//用两个队列模拟一个栈
/*
typedef struct Node
{
    int data;
    struct Node *next;
}*pNode;

typedef struct Queue
{
    pNode front;  //队头指针
    pNode rear;   //队尾指针
}*pQueue;

pQueue createQueue()
{
    pQueue queue = (pQueue)malloc(sizeof(pQueue));
    pNode node = (pNode)malloc(sizeof(pNode));
    queue -> front = node;
    queue -> rear = node;
    queue -> front -> next = NULL;
    return queue;
}

int isEmptyQueue(pQueue queue)
{
    if (queue -> front == queue -> rear) {
        return 1;
    } else {
        return 0;
    }
}

void inQueue(pQueue queue, int value)
{
    if (queue == NULL) {
        return;
    }
    pNode node = (pNode)malloc(sizeof(pNode));
    node -> data = value;
    node -> next = NULL;
    queue -> rear -> next = node;
    queue -> rear = node;
}

int deQueue(pQueue queue, int* value)
{
    if (queue == NULL) {
        return 0;
    }
    if (isEmptyQueue(queue)) {
        return 0;
    } else {
        pNode head = queue -> front -> next;
        *value = head -> data;
        queue -> front -> next = head -> next;
        if (queue -> rear == head) // 删除的那个是最后一个
            queue -> rear = queue -> front;
        free(head);
        return 1;
    }
}

int queueLen(pQueue queue)
{
    int len = 0;
    pNode pCurrent = queue -> front -> next;
    while (pCurrent) {
        pCurrent = pCurrent -> next;
        len ++;
    }
    return len;
}

void push(pQueue queue1, pQueue queue2, int value)
{
    if (isEmptyQueue(queue2)) { // 2为空
        inQueue(queue1, value);
    } else { // 1为空
        inQueue(queue2, value);
    }
}


int pop(pQueue queue1, pQueue queue2, int* value)
{
    if (isEmptyQueue(queue1) && isEmptyQueue(queue2)) {
        return 0;
    }
    if (isEmptyQueue(queue2) && queueLen(queue1) == 1) { // 2为空 且1刚好一个
        deQueue(queue1, value);
    } else if (isEmptyQueue(queue2) && queueLen(queue1) != 1) { // 2为空 1有多个
        int tmp = 0;
        while (queueLen(queue1) != 1) {
            deQueue(queue1, &tmp);
            inQueue(queue2, tmp);
        }
        deQueue(queue1, value);
    } else if (isEmptyQueue(queue1) && queueLen(queue2) == 1) { // 1为空 且2刚好一个
        deQueue(queue2, value);
    } else {
        int tmp = 0;
        while (queueLen(queue2) != 1) {
            deQueue(queue2, &tmp);
            inQueue(queue1, tmp);
        }
        deQueue(queue2, value);
    }
    return 1;
}
*/

// 年龄排序
/*
void sortAge(int *ages, int count)
{
    int timesOfAge[100];
    memset(timesOfAge, 0, sizeof(timesOfAge));
    for (int i = 0; i<count; i++) {
        timesOfAge[ages[i]] ++ ;
    }
    int index = 0;
    for (int j = 0; j<100; j++) {
        int ageCount = timesOfAge[j];
        while (ageCount != 0) {
            ages[index] = j;
            index ++;
            ageCount --;
        }
    }
}
*/

// 斐波那契序列与跳台阶
/*
long long Fibonacci(unsigned int n)
{
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    long long a0 = 0;
    long long a1 = 1;
    long long an = 0;
    for (int i = 2; i<=n; i++) {
        an = a0 + a1;
        a0 = a1;
        a1 = an;
    }
    return an;
}
*/

// 输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
/*
int numOfOne(int n)
{
    int count = 0;
    while (n) {
        n = n & (n - 1);
        count ++;
    }
    return count;
}
*/

// 给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
/*
int flag = 1;

double powerAbs(double base, int absExp) // 递归
{
    if (absExp == 0) {
        return 1;
    }
    if (absExp == 1) {
        return base;
    }
    //    //递归求次方
    //    double result = powerAbs(base,absExp>>1);
    //    result *= result;
    //    //判断奇偶性
    //    if((absExp&1) == 1)
    //        result *= base;
    
    if (absExp%2 == 1) {
        return powerAbs(base,((absExp-1)/2)) * powerAbs(base,((absExp-1)/2)) * base;
    } else {
        return powerAbs(base,(absExp/2)) * powerAbs(base,(absExp/2));
    }
    
}

double power(double base, int exp) // 先判断
{
    if (exp <= 0 && base <= 0) {
        flag = 0;
        return 0;
    }
    
    if (exp < 0) { //负数
        flag = 1;
        return 1.0/powerAbs(base, -exp);
    } else {
        flag = 1;
        return powerAbs(base, exp);
    }
}

int main()
{
    int nums = 0;
    scanf("%d", &nums);
    double base = 0;
    int exp = 0;
    for (int i = 0; i < nums; i ++) {
        scanf("%lf", &base);
        scanf("%d", &exp);
        double result = power(base,exp);
        if (flag == 1) {
            printf("%.2ef\n",result);
        } else {
            printf("INF\n");
        }
    }
    return 0;
}
*/

// 输入一个链表，输出该链表中倒数第k个结点。
/*
typedef struct Node {
    int data;
    struct Node *pNext;
}*pNode;

pNode createNode(int count)
{
    pNode list = (pNode)malloc(sizeof(pNode));
    pNode current = list;
    for (int i = 0; i < count; i ++) {
        int value;
        scanf("%d", &value);
        current -> data = value;
        if (i == count - 1) {
            current -> pNext = NULL;
        } else {
            pNode next = (pNode)malloc(sizeof(pNode));
            current -> pNext = next;
            current = next;
        }
    }
    return list;
}

pNode FindKthToLast(pNode list, int k, int count)
{
    if (list == NULL || k < 1 || k > count) {
        return NULL;
    }
    int index = count - k + 1; // 正数第index个
    pNode current = list;
    for (int i = 1; i < index; i ++) {
        current = current -> pNext;
    }
    return current;
}
*/
