#ifdef BACKSTAGE_EXPORTS
#define BACKSTAGE_API __declspec(dllexport)
#else
#define BACKSTAGE_API __declspec(dllimport)
#endif


// ��ʼ��
EXTERN_C BACKSTAGE_API int WINAPI Initialize(const bool);
// ��ֹ
EXTERN_C BACKSTAGE_API int WINAPI Terminate();
