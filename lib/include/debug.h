/*
    Author: Cai
    Data:   27Dec24
    Description:    C header of debug
*/

#ifndef _DEBUG__
#define _DEBUG__

/*==========================
    macro definition
*/

/* 0-close, 1-open */
#define DBG_ON  (1)

#if DBG_ON
/* normal debug */
#define DBG(...) do{ \
    printf("<%s, %d> - ", __func__, __LINE__);  \
    printf(__VA_ARGS__);    \
    printf("\r\n"); \
}while(0);
#else
#define DBG(...)
#endif

#endif