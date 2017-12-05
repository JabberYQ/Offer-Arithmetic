//
//  main.c
//  C-Demo
//
//  Created by 俞琦 on 2017/10/9.
//  Copyright © 2017年 俞琦. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

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

pNode MergeList(pNode list1, pNode list2)
{
    if (list1 == NULL) {
        return list2;
    }
    if (list2 == NULL) {
        return list1;
    }
    pNode head1 = list1;
    pNode head2 = list2;
    pNode newHead = NULL;
    if (head1 -> data > head2 -> data) {
        newHead = head2;
        newHead -> pNext = MergeList(head1, head2 -> pNext);
    } else {
        newHead = head1;
        newHead -> pNext = MergeList(head1 -> pNext, head2);
    }
    return newHead;
}

int main(int argc, const char * argv[])
{
    int count1 = 0;
    int count2 = 0;
    scanf("%d %d", &count1, &count2);
    pNode list1 = createNode(count1);
    pNode list2 = createNode(count2);
    pNode mergeList = MergeList(list1, list2);
    pNode curNode = mergeList;
    while (curNode) {
        printf("%d", curNode -> data);
        curNode = curNode -> pNext;
    }
    return 0;
}

