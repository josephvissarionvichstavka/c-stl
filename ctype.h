//
// Created by father on 2024/4/21.
//

#ifndef UNTITLED_CTYPE_H
#define UNTITLED_CTYPE_H

int isalnum(int ); // 单词开头是否为字母或者数字
int isalpha(int ); // 单词开头是否为字母，大小写皆可
int iscntrl(int ); // 是否是特殊字符
int isdigit(int ); // 是否是数字
int isgraph(int ); // 是否可以显示
int islower(int ); // 是否是小写字母
int isprint(int ); // 是否可以打印
int ispunct(int ); // 是否是标点符号
int isspace(int ); // 是否是空格
int isupper(int ); // 是否是大写字母
int isxdigit(int ); // 是否是16进制数
int tolower(int ); // 转换为小写
int toupper(int ); // 转换为大写
extern const short int *_CType,*_ToLower,*_ToUpper;

#define _XD 0X01 // 数字  小写 大写
#define _UP 0x02 // 大写字母
#define _SP 0x04 // 空格
#define _PU 0x08 // 标点符号
#define _LO 0x10 // 小写字母
#define _DI 0x20 // 数字
#define _CN 0x40 // 特殊字符
#define _BB 0x80 //  扩展表
#define _XS 0x100
#define _XA 0x200


#endif //UNTITLED_CTYPE_H
