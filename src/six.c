/*
 * @Author: devilwzx
 * @Date: 2022-09-29 19:35:58
 * @FilePath: \6.18\src\six.c
 * @Description: C和C指针第六章习题
 * 
 */


#include <stdio.h>
/**
 * @description: 反转字符串
 * @param {char} *string 需要反转的字符串
 * @return {*} 无
 */
void reverse_string( char *string )
{
    char *last_char=NULL;

    for(last_char = string;*last_char != '\0';last_char++)
        ;
    last_char--;
    while(string < last_char)
    {
        int temp;
        temp = *string;
        *string++ = *last_char;
        *last_char-- = temp; 
    }

}

/**
 * @description: 在字符串中查找相同的字符串
 * @param *source   被查找的字符串
 * @param *chars    要查找的字符串
 * @return {*}  返回第一个查找到的字符串
 */
char *find_char( char const *source,const char  *chars )
{ 
    /*不能把const删除，不然会造成类型不对*/
    const char *ps = source;
    const char *pc = chars;  
    while (ps != NULL || pc != NULL) {
           while ( *ps != '\0' ){
            while( *pc != '\0')
            {
                if(*pc == *ps)
                {
                    return (char *)pc;
                }
                pc++;
            }
            /*重新fuzhi*/
            pc = chars;
            ps++;
        }
    return NULL;
    }
}

/**
 * @description: 这是一个删除字符串的函数,即在str中搜索,当遇到和substr一模一样的字符串时,就会删除它
 * @param {char} *str   删除的字符串数组
 * @param {char} *substr    要查询删除的字符串
 * @return {*}  1 删除成功  0 删除失败
 */
int del_substr( char *str, char const *substr )
{
    //两个临时的指针,p1用于临时存储子串地址,p2用于临时指向查找到子串的首字母位置
    const char *p1 = NULL;
    char *p2 = NULL;
    char *pstr =str; 
    const char *psubstr=  substr;


    while(pstr != NULL && psubstr != NULL)
    {
        while(*psubstr != '\0')
        {
            while(*pstr != '\0')
            {
                if(*pstr == *psubstr)
                {
                    //临时存储地址,若后面的都相等,则没有作用,若不相等,则将psubstr、pstr地址置换回来
                    p1 = psubstr;
                    p2 = pstr;
                    while (*psubstr != '\0')
                        {
                            //如果不相等的话,即str和substr的下一位不相等,那么把刚刚的临时指针赋给它两,然后跳出
                            if(*psubstr != *pstr)
                            {
                                psubstr = p1;
                                pstr = p2;
                                break;
                            }
                            psubstr++;
                            pstr++;
                        }
                }
                //psbustr指针跳到了NUL,说明是sbustr正常跳完了,即石头人里有一连串的sbustr
                if(*psubstr == '\0')
                {
                    //将str后面的一个个赋值
                    while(*p2 != '\0')
                    {
                        *p2 = *pstr;
                        pstr++;
                        p2++;
                    }
                    return 1;
                }
                pstr++;
            }
            psubstr++;
        }
            return 0;
    }

}