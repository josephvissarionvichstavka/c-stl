//
// Created by father on 2024/4/21.
//

#include "ctype.h"


#define XDI (_DI | _XD)
#define XLO (_LO | _XD)
#define XUP (_UP | _XD)

static const short ctype_tab[257] = {0,//-1
                                     _BB,_BB,_BB,_BB,_BB,_BB,_BB,_BB,// 8
                                     _BB,_CN,_CN,_CN,_CN,_CN,_BB,_BB,//16
                                     _BB,_BB,_BB,_BB,_BB,_BB,_BB,_BB,//24
                                     _BB,_BB,_BB,_BB,_BB,_BB,_BB,_BB,//32
                                     _SP,_PU,_PU,_PU,_PU,_PU,_PU,_PU,//40
                                     _PU,_PU,_PU,_PU,_PU,_PU,_PU,_PU,//48
                                     XDI,XDI,XDI,XDI,XDI,XDI,XDI,XDI,//56
                                     XDI,XDI,_PU,_PU,_PU,_PU,_PU,_PU,//64
                                     _PU,XUP,XUP,XUP,XUP,XUP,XUP,_UP,//80
                                     _UP,_UP,_UP,_UP,_UP,_UP,_UP,_UP,//88
                                     _UP,_UP,_UP,_UP,_UP,_UP,_UP,_UP,//96
                                     _UP,_UP,_UP,_PU,_PU,_PU,_PU,_PU,//104
                                     _PU,XLO,XLO,XLO,XLO,XLO,XLO,_LO,//112
                                     _LO,_LO,_LO,_LO,_LO,_LO,_LO,_LO,//120
                                     _LO,_LO,_LO,_LO,_LO,_LO,_LO,_LO,//128
                                     _LO,_LO,_LO,_PU,_PU,_PU,_PU,_BB,//136
                                     };

const short *_CType = &ctype_tab[1];