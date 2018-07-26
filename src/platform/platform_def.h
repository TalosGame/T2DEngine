/*!
 * Filename: 	platform_def.h
 * Copyright:   TalosGame Studio Co., Ltd.
 * Data:	    2018/07/08 0:20
 * Author 		miller
 * Description: 
 */

#ifndef __T2D_ENGINE_PLATFORM_DEF_H__
#define __T2D_ENGINE_PLATFORM_DEF_H__

typedef unsigned char       uint8;
typedef unsigned short      uint16;
typedef unsigned int        uint32;
typedef unsigned long long  uint64;

// esCreateWindow flag - RGB color buffer
#define ES_WINDOW_RGB           0
// esCreateWindow flag - ALPHA color buffer
#define ES_WINDOW_ALPHA         1
// esCreateWindow flag - depth buffer
#define ES_WINDOW_DEPTH         2
// esCreateWindow flag - stencil buffer
#define ES_WINDOW_STENCIL       4
// esCreateWindow flat - multi-sample buffer
#define ES_WINDOW_MULTISAMPLE   8

//
//  Global extern.  The application must declare this function
//  that runs the application.
//
extern int game_entry(void *device);

#endif //__T2D_ENGINE_PLATFORM_DEF_H__
