//
// Created by father on 2024/4/21.
//

#ifndef UNTITLED_ASSERT_H
#define UNTITLED_ASSERT_H
#undef assert
void _Assert(char *); // 测试函数

#define _STR(x) _VAL(x)
#define _VAL(x) #x
#define assert(test) ((test) ? (void)0 : _Assert(__FILE__":"_STR(__LINE__)" ("#test") "))



#endif //UNTITLED_ASSERT_H
