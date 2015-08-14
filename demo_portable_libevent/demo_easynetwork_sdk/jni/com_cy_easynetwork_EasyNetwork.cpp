
#include <jni.h>
#include <unistd.h>
#include <pthread.h>
#include "easynetwork.h"
#include <string>

#ifdef __cplusplus
extern "C" {
#endif

//// 全局变量
static JavaVM * g_javaVM =NULL;
static jobject g_javaObj =NULL;
static volatile int g_isExit =0;
std::string g_serverAddr;

//// 底层的回调函数参数.
typedef struct _tagUserCbArg
{
	JNIEnv * env;
	jmethodID javaCallback;
}UserCbArg;
  
//// 底层的回调函数.
static void on_eventcb_cli(int event_type, void * user_cb_arg)
{
	do{
		UserCbArg * userCbArg =(UserCbArg*)user_cb_arg;
		if(NULL==userCbArg)
			break;
		
		JNIEnv * env =userCbArg->env;
		jmethodID javaCallback =userCbArg->javaCallback;
		env->CallVoidMethod(g_javaObj, javaCallback, event_type);		
	}while(0);
}

  
//// 线程函数定义
static void * native_thread_proc(void * arg)
{
	JNIEnv * env =NULL;
	if(0!=g_javaVM->AttachCurrentThread((JNIEnv **)(&env), NULL))
	{
		return NULL;
	}
	
	do{
		// 获取java层对应的类
		jclass javaClass =env->GetObjectClass(g_javaObj);
		if(NULL==javaClass) break;
		
		// 获取java层函数
		jmethodID javaCallback =env->GetMethodID(javaClass, "en_event", "(I)V");
		if(NULL==javaCallback) break;
		
		// 设置事件回调函数的参数.
		UserCbArg user_cb_arg;
		user_cb_arg.env =env;
		user_cb_arg.javaCallback =javaCallback;
		
		while(0==g_isExit)
		{
			en_start(g_serverAddr.c_str(), on_eventcb_cli,&user_cb_arg);
			usleep(3*1000*1000);
		}
	}while(0);
	
	g_javaVM->DetachCurrentThread();	
}


//// jni函数定义
JNIEXPORT jint JNICALL Java_com_cy_easynetwork_EasyNetwork_en_1init
  (JNIEnv * env, jclass thiz)
  {
	  env->GetJavaVM(&g_javaVM);
	  g_javaObj =env->NewGlobalRef(thiz);
	  return en_init();
  }

JNIEXPORT jint JNICALL Java_com_cy_easynetwork_EasyNetwork_en_1final
  (JNIEnv * env, jclass thiz)
  {
	return en_final();
  }

JNIEXPORT jint JNICALL Java_com_cy_easynetwork_EasyNetwork_en_1start
  (JNIEnv * env, jclass thiz, jstring parm)
  {
	  jsize parm_len =env->GetStringUTFLength(parm);
	  const char *str =env->GetStringUTFChars(parm, NULL);
	  g_serverAddr.assign(str, parm_len);
	  env->ReleaseStringUTFChars(parm, str);
	  
	  pthread_t tid;
	  if( 0!=pthread_create(&tid, NULL, native_thread_proc, NULL) )
	  {
		  return -1;
	  }
	  return 0;
  }

JNIEXPORT jint JNICALL Java_com_cy_easynetwork_EasyNetwork_en_1stop
  (JNIEnv * env, jclass thiz)
  {
	g_isExit =1;
	return en_stop();
  }


  
#ifdef __cplusplus
}
#endif
