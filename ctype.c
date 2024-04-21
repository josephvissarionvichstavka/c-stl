//
// Created by father on 2024/4/21.
//

#include "ctype.h"
int isalnum(int c){
    return (_CType[c] & ( _DI | _LO | _UP | _XA));
}
int isalpha(int c){
    return (_CType[c] & (_LO | _UP | _XA));
}
int iscntrl(int c){
    return (_CType[c] & (_BB | _CN));
}
int isdigit(int c){
    return (_CType[c] & _DI);
}
int isgraph(int c){
    return (_CType[c] & (_DI | _LO | _PU | _UP | _XA));
}
int islower(int c){
    return (_CType[c] & _LO);
}
int isprint(int c){
    return (_CType[c] & (_DI | _LO | _PU | _SP | _UP | _XA));
}
int ispunct(int c){
    return (_CType[c] & _PU);
}
int isspace(int c){
    return (_CType[c] & (_CN | _SP | _XS));
}
int isupper(int c){
    return (_CType[c] & _UP);
}
int isxdigit(int c){
    return (_CType[c] & _XD);
}
int tolower(int c){
    return (_ToLower[c]);
}
int toupper(int c){
    return (_ToUpper[c]);
}