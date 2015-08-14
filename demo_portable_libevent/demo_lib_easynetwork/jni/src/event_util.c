#include "event_util.h"

#include <errno.h>
#include <string.h>

#include "ndk_log.h"

#ifdef __cplusplus
extern "C" {
#endif


struct bufferevent * eu_start_tcp_client(struct event_base *base, 
    struct sockaddr * saddr,
    bufferevent_data_cb readcb, 
    bufferevent_data_cb writecb,
    bufferevent_event_cb eventcb, 
    void * cbarg)
{
	log_d(TAG_NETWORK, "Enter eu_start_tcp_client ");
	
    struct bufferevent * bev =NULL;
    do{
        bev = bufferevent_socket_new(base, -1, BEV_OPT_CLOSE_ON_FREE);
        if(NULL==bev)
        {
			log_w(TAG_NETWORK, "bufferevent_socket_new return NULL ! ");
            break;
        }

        bufferevent_setcb(bev, readcb, writecb, eventcb, cbarg);
        bufferevent_enable(bev, EV_READ|EV_WRITE);

		log_d( TAG_NETWORK, "Before bufferevent_socket_connect, errno=%d,%s.",
			errno, strerror(errno) );
        if (bufferevent_socket_connect(bev, saddr, sizeof(struct sockaddr)) < 0) 
        {
			log_w( TAG_NETWORK, "bufferevent_socket_connect return <0 ! errno=%d,%s.",
				errno, strerror(errno) );
            bufferevent_free(bev);
            bev =NULL;
			break;
        }
		
		evutil_socket_t s =bufferevent_getfd(bev);
		if(-1==s)
		{
			log_w(TAG_NETWORK, "bufferevent_getfd return -1 ! ");
			break;
		}

    }while(0);
	return bev;
}
	
  
#ifdef __cplusplus
}
#endif
