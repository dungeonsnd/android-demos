
#include <jni.h>
#include <pthread.h>
#include "easynetwork.h"

#ifdef __cplusplus
extern "C" {
#endif

//// 全局变量
static JavaVM * g_javaVM =NULL;
static jobject g_javaObj =NULL;
static volatile int _isExit =0;
int _port;

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
		(*env)->CallVoidMethod(env, _javaObj, javaCallback, event_type);		
	}while(0);
}

  
//// 线程函数定义
static void * native_thread_proc(void * arg)
{
	JNIEnv * env =NULL;
	(*_javaVM)->AttachCurrentThread(_javaVM, &env, NULL);
	
	do{
		// 获取java层对应的类
		jclass javaClass =(*env)->GetObjectClass(env, _javaObj);
		if(NULL==javaClass) break;
		
		// 获取java层函数
		jmethodID javaCallback =(*env)->GetMethodID(env, javaClass, "en_event", "(I)V");
		if(NULL==javaCallback) break;
		
		// 设置事件回调函数的参数.
		UserCbArg user_cb_arg;
		user_cb_arg.env =env;
		user_cb_arg.javaCallback =javaCallback;
		
		while(0==_isExit)
		{
			en_start("192.168.16.254:8018", on_eventcb_cli,&user_cb_arg);
			usleep(6*1000*1000);
		}
	}while(0);
	
	(*_javaVM)->DetachCurrentThread(_javaVM);	
}


//// jni函数定义
JNIEXPORT jint JNICALL Java_com_cy_easynetwork_EasyNetwork_en_1init
  (JNIEnv * env, jclass thiz)
  {
	  (*env)->GetJavaVM(env, &_javaVM);
	  _javaObj =(*env)->NewGlobalRef(env,thiz);
	  return en_init();
  }

JNIEXPORT jint JNICALL Java_com_cy_easynetwork_EasyNetwork_en_1final
  (JNIEnv * env, jclass thiz)
  {
	return en_final();
  }

JNIEXPORT jint JNICALL Java_com_cy_easynetwork_EasyNetwork_en_1start
  (JNIEnv * env, jclass thiz, jint port)
  {
	  _port =port;
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
	_isExit =1;
	return en_stop();
  }


  
#ifdef __cplusplus
}
#endif
