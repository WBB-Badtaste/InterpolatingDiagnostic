#pragma once

#ifdef BACKSTAGE_EXPORTS
#define BACKSTAGE_API __declspec(dllexport)
#else
#define BACKSTAGE_API __declspec(dllimport)
#endif



// 初始化
EXTERN_C BACKSTAGE_API int WINAPI Initialize(const bool* const);
// 终止
EXTERN_C BACKSTAGE_API int WINAPI Terminate();
//添加node
EXTERN_C BACKSTAGE_API int WINAPI AddNode(char*);
//添加axis
EXTERN_C BACKSTAGE_API int WINAPI AddAxis(char*, char*);
//axis寻相
EXTERN_C BACKSTAGE_API int WINAPI AlignAxis(char*);
//axis回零
EXTERN_C BACKSTAGE_API int WINAPI HomeAxis(char*);
//axis复位
EXTERN_C BACKSTAGE_API int WINAPI ResetAxis(char*);
//取axis位置
EXTERN_C BACKSTAGE_API int WINAPI GetAxisPosition(char*,double *value);
//取axis状态
EXTERN_C BACKSTAGE_API int WINAPI GetAxisStatus(char*,char* pState);
//取HomePars
EXTERN_C BACKSTAGE_API int WINAPI GetAxisHomePars(double*,double*,double*);
//设置HomePars
EXTERN_C BACKSTAGE_API int WINAPI SetAxisHomePars(double,double,double);
//插补运动
EXTERN_C BACKSTAGE_API int WINAPI MoveInterpolating(const double *dCurX, const double *dCurY, const double *dRadius,IN_SED_PRT const pSegments,const int *segSum);
