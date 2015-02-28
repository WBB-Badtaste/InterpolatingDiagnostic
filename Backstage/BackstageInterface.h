#pragma once

#ifdef BACKSTAGE_EXPORTS
#define BACKSTAGE_API __declspec(dllexport)
#else
#define BACKSTAGE_API __declspec(dllimport)
#endif



// ��ʼ��
EXTERN_C BACKSTAGE_API int WINAPI Initialize(const bool* const);
// ��ֹ
EXTERN_C BACKSTAGE_API int WINAPI Terminate();
//���node
EXTERN_C BACKSTAGE_API int WINAPI AddNode(char*);
//���axis
EXTERN_C BACKSTAGE_API int WINAPI AddAxis(char*, char*);
//axisѰ��
EXTERN_C BACKSTAGE_API int WINAPI AlignAxis(char*);
//axis����
EXTERN_C BACKSTAGE_API int WINAPI HomeAxis(char*);
//axis��λ
EXTERN_C BACKSTAGE_API int WINAPI ResetAxis(char*);
//ȡaxisλ��
EXTERN_C BACKSTAGE_API int WINAPI GetAxisPosition(char*,double *value);
//ȡaxis״̬
EXTERN_C BACKSTAGE_API int WINAPI GetAxisStatus(char*,char* pState);
//ȡHomePars
EXTERN_C BACKSTAGE_API int WINAPI GetAxisHomePars(double*,double*,double*);
//����HomePars
EXTERN_C BACKSTAGE_API int WINAPI SetAxisHomePars(double,double,double);
//�岹�˶�
EXTERN_C BACKSTAGE_API int WINAPI MoveInterpolating(const double *dCurX, const double *dCurY, const double *dRadius,IN_SED_PRT const pSegments,const int *segSum);
