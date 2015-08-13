
#include "com_cy_androidsdk_TestSdk.h"

#include "myc.h"


#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jint JNICALL Java_com_cy_androidsdk_TestSdk_func
	(JNIEnv * env, jclass j, jint a, jint b)
{
	return func(a, b);
}

  
#ifdef __cplusplus
}
#endif
