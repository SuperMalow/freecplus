//
//  main.cpp
//  freeplus
//
//  本程序是实现利用终端命令来实现文件夹的复制
//
//  Created by 圣文 on 2021/7/12.
//

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
    
    if (argc != 3)
    {
        printf("\n本程序的功能是实现文件之间的复制\n");
        printf("\n本程序的操作方式是: xxx.exe 源文件 目标文件\n");
        printf("\n例如: ccopy.exe resource.txt destsource.txt\n");
    }
    
    FILE *res, *dst;
    
    // 先进行源文件的读取
    if ((res = fopen(argv[1], "r")) == 0)
    {
        printf("\n fopen(%s) failed. \n", argv[1]);
        return -1;
    }
    // 再进行目标文件的写入
    if ((dst = fopen(argv[2], "w")) == 0)
    {
        printf("\n fopen(%s) failend. \n", argv[2]);
        return -1;
    }
    int readn;
    int *buf = (int *)malloc(100);
    
    while (1)
    {
        if ((readn = fread(buf, 1, 100, res)) == 0) {
            break;
        }
        fwrite(buf, 1, readn, dst);
    }
    fclose(res);
    fclose(dst);
    free(buf);
    
    return  0;
}
