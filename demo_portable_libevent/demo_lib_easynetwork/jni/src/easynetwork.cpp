#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <string>

#include <event2/dns.h>
#include <event2/listener.h>
#include <event2/bufferevent.h>
#include <event2/buffer.h>

#include "easynetwork.h"
#include "event_util.h"
#include "ndk_log.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _tagEasyNetworkContext
{
	int stopped;
	struct event_base * base;
	struct bufferevent * bev;
	pfunc_on_eventcb_cli on_eventcb_cli_func;
	void * user_cb_arg;
} EasyNetworkContext;

static EasyNetworkContext _ctx;


static void readcb_cli(struct bufferevent *bev, void *cbarg)
{
}

static void writecb_cli(struct bufferevent *bev, void *cbarg)
{
}

static void eventcb_cli(struct bufferevent *bev, short events, void *cbarg)
{
	do{
		int err = EVUTIL_SOCKET_ERROR();
		evutil_socket_t sock =bufferevent_getfd(bev);
		printf("eventcb_cli, socket=%d \n", sock);
			
		int need_close =1;
		if (events & BEV_EVENT_CONNECTED) {
			need_close =0;
			printf("Server connected! \n");
		} 
		else if (events & BEV_EVENT_EOF) {
			printf("BEV_EVENT_EOF, %s ! \n", evutil_socket_error_to_string(err));
		}
		else if (events & BEV_EVENT_ERROR) {
			printf("BEV_EVENT_ERROR, %s ! \n", evutil_socket_error_to_string(err));
            int errs = bufferevent_socket_get_dns_error(bev);
			if (errs)
				printf("DNS error: %s ! \n", evutil_gai_strerror(errs));
		}
		else if (events & BEV_EVENT_TIMEOUT) {
			printf("BEV_EVENT_TIMEOUT  \n");
		}
		else{
			printf("Other ERROR: %s ! \n", evutil_socket_error_to_string(err));
		}

		if(need_close)
		{	
		}
		
		if(_ctx.on_eventcb_cli_func)
		{
			_ctx.on_eventcb_cli_func(events, _ctx.user_cb_arg);
		}
		
	}while(0);
}

static void timercb_cli(evutil_socket_t ss, short events, void * cbarg) 
{
}

int en_init()
{
	log_t(TAG_NETWORK, "Enter en_init ");
	int rt =-1;
	do{
		_ctx.base = event_base_new();
		if(NULL==_ctx.base)
		{
			log_w(TAG_NETWORK, "event_base_new return NULL ! ");
			break;			
		}
		
		rt =0;
	}while(0);
	return rt;	
}
int en_final()
{
	log_t(TAG_NETWORK, "Enter en_final ");
	int rt =-1;
	do{
		if(_ctx.base)
		{
			log_d(TAG_NETWORK, "en_final, try event_base_free. ");
			event_base_free(_ctx.base);
			_ctx.base =NULL;
		}
		rt =0;
	}while(0);
	return rt;	
}
int en_stop()
{
	log_t(TAG_NETWORK, "Enter en_stop ");
	int rt =-1;
	do{
		if(_ctx.base)
		{
			log_d(TAG_NETWORK, "en_stop, try event_base_loopbreak. ");
			event_base_loopbreak(_ctx.base);
		}
		_ctx.stopped =1;
		rt =0;
	}while(0);
	return rt;	
}

int en_start(const std::string & ip_port, 
	pfunc_on_eventcb_cli on_eventcb_cli_func, void * user_cb_arg)
{
	log_d(TAG_NETWORK, "Enter en_start, ip_port=%s ", ip_port.c_str());

	struct sockaddr saddr;
	int saddr_len =sizeof(saddr);
	
	int rt =-1;
	do{
		_ctx.on_eventcb_cli_func =on_eventcb_cli_func;
		_ctx.user_cb_arg =user_cb_arg;
		
		if(NULL==_ctx.base)
		{
			log_w(TAG_NETWORK, "en_init not correctly ! Must init first. ");
			break;
		}
		
		if(0!=evutil_parse_sockaddr_port(ip_port.c_str(), &saddr, &saddr_len))
		{
			log_w(TAG_NETWORK, "evutil_parse_sockaddr_port return not 0 ! ");
			break;
		}
		
		_ctx.bev =eu_start_tcp_client(_ctx.base, 
			&saddr, readcb_cli, writecb_cli, eventcb_cli, &_ctx);
		if(NULL==_ctx.bev)
		{
			log_w(TAG_NETWORK, "eu_start_tcp_client return NULL ! ");
			break;
		}
		
		log_i(TAG_NETWORK, "Before event_base_dispatch. ");
		event_base_dispatch(_ctx.base);
		log_i(TAG_NETWORK, "After event_base_dispatch. ");
		
		rt =0;
	}while(0);
	return rt;
		
}

  
#ifdef __cplusplus
}
#endif
