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
EXTERN_C BACKSTAGE_API int WINAPI GetAxisHomePars(char* ,double*,double*,double*);
//����HomePars
EXTERN_C BACKSTAGE_API int WINAPI SetAxisHomePars(char*, double,double,double);
//ȡMotionPars
EXTERN_C BACKSTAGE_API int WINAPI GetAxisMotionPars(char*, double*,double*,double*);
//����MotionPars
EXTERN_C BACKSTAGE_API int WINAPI SetAxisMotionPars(char*, double,double,double);
//ȡStopPars
EXTERN_C BACKSTAGE_API int WINAPI GetAxisStopPars(char*, double*);
//����StopPars
EXTERN_C BACKSTAGE_API int WINAPI SetAxisStopPars(char*, double);
//��ò岹�ֶ�
EXTERN_C BACKSTAGE_API int WINAPI GetInSeg_Circle(const double *dCurX, const double *dCurY, const double *dRadius,IN_SED_PRT const pSegments,const int *segSum);
//�岹�˶�
EXTERN_C BACKSTAGE_API int WINAPI MoveInterpolating(IN_SED_PRT pSegments,const int iSum,const bool bAbsolute);