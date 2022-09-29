/*
 * @Author: devilwzx
 * @Date: 2022-09-28 18:59:41
 * @FilePath: \6.18\main.c
 * @Description: 主文件
 * @Function: int main(void) 主函数
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include "six.h"

int main(void) {
    /*此处不能写a[5],因为12345不是占5个字节，而是占6个字节，因为后面还有一个\0 位 ，不然会造成数组越界，导致数据不对*/
    char a[10] = "123456";
    char b[10] = "ll";
    reverse_string( a );
    printf("%s",a);
    return 0;
}

