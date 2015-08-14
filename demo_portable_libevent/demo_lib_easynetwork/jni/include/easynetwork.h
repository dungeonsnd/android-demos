#ifndef _HEADER_FILE_LIBNETWORK_H_
#define _HEADER_FILE_LIBNETWORK_H_

#include <string>

#ifdef __cplusplus
extern "C" {
#endif

// 底层的回调函数.
typedef void (*pfunc_on_eventcb_cli)(int event_type, void * user_cb_arg);

int en_init();
int en_final();

int en_start(const std::string & ip_port, 
	pfunc_on_eventcb_cli on_eventcb_cli_func, void * user_cb_arg);
	
int en_stop();

  
#ifdef __cplusplus
}
#endif

#endif //__GOOD_LUCK_H__
