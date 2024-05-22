//
// Created by father on 2024/5/21.
//

#ifndef STRING_MY_STRING_H
#define STRING_MY_STRING_H
#include <stddef.h>
typedef const char * string;
// 复制
char * str_copy(const char * src,char * dest){
    char * s = dest;
    for (;(*s ++ = *src++) != '\0';)
        ;
    return dest;
}
// 复制带长度
char * str_n_copy(const char * src,char * dest,size_t n){
    char * s = dest;
    for (;0 < n && (*s ++ = *src++) != '\0';--n)
        ;
    for (;0 < n;--n)
        *s++ = '\0';
    return dest;
}
// 拼接字符串
char * str_cat(char * dest,const char * src){
    char * s;
    for (s = dest;*s != '\0';++s)
        ;
    for (;(*s++ = *src++) != '\0';)
        ;
    return dest;
}
char * str_n_cat(char * dest,const char * src,size_t n){
    char * s;
    for (s = dest;*s != '\0';++s)
        ;
    for (;0 < n && *src != '\0';--n)
        *s++ = *src++;
    *s = '\0';
    return dest;
}
// 判断字符串是否相等
int str_cmp(const char * src,const char * dest){
    for (; *src == *dest;++src,++dest)
        if (*src == '\0')
            return 0;
    return (*src - *dest) > 0 ? 1 : -1;
}
int str_n_cmp(const char * src,const char * dest,size_t n){
    for (;0 < n;--n,++src,++dest)
        if (*src != *dest)
            return (*src - *dest) > 0 ? 1 : -1;
        else if (*src == '\0')
            return 0;
    return 0;
}
// 字符串长度
size_t str_len(const char * str){
    int len = 0;
    do
        len++;
    while (str[len] != '\0');
    return len;
}
// 匹配的相同字符数
size_t str_spn(const char * src,const char * tag){
    const char * ax, * bx;
    for (ax = src;*ax != '\0';++ax)
        for (bx = tag; ;++bx)
           if (*bx == '\0')
               return (ax - src);
           else if (*bx == *ax)
               break;
    return (ax - src);
}
// 第一次匹配到的字符串的位置
size_t str_c_spn(const char * src,const char * tag){
    const char * ax, * bx;
    for (ax = src;*ax != '\0';++ax)
        for (bx = tag;*bx != '\0';++bx)
            if (*ax == *bx)
                return (ax - src);
    return (ax - src);
}
// 输出第一次匹配字符串的字符地址
char * str_p_brk(const char * src,const char * tag){
    const char * ax, * bx;
    for (ax = src;*ax != '\0';++ax)
        for (bx = tag;*bx != '\0';++bx)
            if (*ax == *bx)
                return ((char *)ax);
    return ((void *)0);
}
// 查找字符串中第一次出现的位置的地址
char * str_chr(const char * str,int c){
    const char * s = str;
    for (;*s != c;++s)
        if (* s == '\0')
            return ((void *)0);
    return ((void *)s);
}
// 查找字符串中最后一次出现的位置的地址
char * str_r_chr(const char * str,int c){
    const char * sc = (void *)0;
    do {
        if (*str == c)
            sc = str;
        if (*str == '\0')
            return (char *)sc;
        ++str;
    } while (1);
}
// 查找字符串
char * str_str(const char * src,const char * tag){
    if (*tag == '\0')
        return (char *)src;
    for (;(src = str_chr(src,*tag)) != 0;++src){
        const char * ax = src,* bx = tag;
       for (;;){
           if (*++bx == '\0')
               return (char *)src;
           else if (*++ax != *bx)
               break;
       }
    }
    return (void *)0;
}
// 字符串拆分函数
char * str_tok (char * str,const char * tag){
    static char * last;
    if (str == 0)
        str = last;
    if (str == 0)
        return 0;
    char * token = str_p_brk(str,tag);
    if (*token != '\0'){
        last = str + 1;
        *token = '\0';
    } else
        last = 0;
    return str;
}
// 替换指定位置指定长度的字符串
char * replace(char * dest,const char * src,int pos,int count){
    for (;0 < pos;--pos,++dest)
        ;
    for (;0 < count;--count,++dest,++src)
        *dest = *src;
    return dest;
}
// 返回指定位置的字符串
char * sub_str(char * dest,const char * src,int pos,int count){
    for (;0 < pos;--pos,++src)
        ;
    str_n_copy(src,dest,count);
    return dest;
}
// 一段地址置
void * mem_set(void * str,int c,size_t n){
    char * s = str;
    for (;0 < n;++s,--n)
        *s = (char) c;
    return str;
}
// 拷贝一段地址数据
void * mem_cpy(void * dest,const void * str,size_t n){
    const char * s1 = str;
    char * s2 = dest;
    do
        *s2++ = *s1++;
    while ( n-- > 0);
    return dest;
}
// 查看地址区域内第一次出现数字的位置
void * mem_chr(const void * str,int c,size_t n){
    const char * s = str;
    for (;0 < n;++s,--n)
        if (* s == c)
            return ((void *)s);
    return ((void *)0);
}
// 比较两段地址的大小
int mem_cmp(const void * str,const void * dest,size_t n){
    const char * s1 = str;
    const char * s2 = dest;
    do {
        if (*s1 != *s2)
            return (*s1 > *s2) ? 1 : -1;
        s1++;
        s2++;
    } while ( n-- > 0);
    return 0;
}
// 移动拷贝函数  不会被覆盖
void * mem_move(void * dest,const void * src,size_t n){
    const char * s1 = src;
    char * s2 = dest;
    if (s1 < s2 && s2 < s1 + n)
        for (s1 += n,s2 += n;0 < n;--n)
            *--s2 = *--s1;
    else
        do
            *s2++ = *s1++;
        while ( n-- > 0);
    return dest;
}

#endif //STRING_MY_STRING_H
