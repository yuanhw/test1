//
//  test1.c
//  XcodeTest1
//
//  Created by macpros on 2019/1/20.
//  Copyright © 2019年 macpros. All rights reserved.
//

#include <stdio.h>
#include <unistd.h>

#include "test1.h"

/**
 * 逆序对
 */
void test1_0120() {
//    int n = 8;
//    int data[8] = {2, 22, 14, 20, 24, 13, 6, 10};
    int n = 6;
    int data[6] = {6, 5, 4, 3, 2, 1};
    int i = 0, j = 0;
    int count = 0;
    for (; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (data[i] > data[j]) {
                printf("(%d, %d)\n", data[i], data[j]);
                count++;
            }
        }
    }
    printf("count = %d", count);
}

void test1_0123() {
    int money = 100;
    int n1 = money / 5;
    int n2 = money / 3;
    for (int i = 0; i <= n1; i++) {
        for (int j = 0; j <= n2; j++) {
            int k = 100 - i - j;
            int needMoney = i * 5 + j * 3 + k / 3;
            if (k % 3 == 0 && needMoney == 100) {
                printf("公鸡 = %d, 母鸡 = %d, 小鸡 = %d\n", i, j, k);
            }
        }
    }
}

void test1_2019032001() {
    int fd[2];
    char str[9];
    pid_t pid;
    
    // f[0]是读，f[1]是写
    if (pipe(fd) < 0) {
        printf("创建管道失败.\n");
        return;
    }
    
    if ((pid = fork()) < 0) {
        printf("创建子进程失败.\n");
        return;
    } else if (pid > 0) {
        printf("创建子进程成功.\n");
        
        // 关闭读
        close(fd[0]);
        // 向管道写，由子进程读取
        write(fd[1], "i am wyh.", 9);
    } else if (pid == 0) {
        printf("子进程执行.\n");
        
        // 关闭写
        close(fd[1]);
        // 子进程从管道读取
        read(fd[0], str, 9);
        
        printf("子进程读取数据：%s\n", str);
    }
    
    printf("end...\n");
}

void test1_2019032002() {
    int fd[2];
    char str[9];
    pid_t pid;
    pid_t pid1;
    
    // f[0]是读，f[1]是写
    if (pipe(fd) < 0) {
        printf("创建管道失败.\n");
        return;
    }
    
    // 创建子进程，子进程从这里开始执行
    pid = fork();
    printf("pid = %d\n", pid);
    
    if (pid < 0) {
        printf("创建子进程失败.\n");
        return;
    } else if (pid > 0) {
        printf("创建子进程成功.\n");
        
        // 关闭写
        // close(fd[1]);
        // 父进程从管道读取
        read(fd[0], str, 9);
        
        printf("父进程读取数据：%s\n", str);
    } else if (pid == 0) {
        printf("子进程执行.\n");
        
        printf("sub_pid = %d\n", fork());
        // 关闭读
        // close(fd[0]);
        // 向管道写，由父进程读取
        write(fd[1], "i am zjc.", 9);
    }
    
    printf("end...\n");
}

