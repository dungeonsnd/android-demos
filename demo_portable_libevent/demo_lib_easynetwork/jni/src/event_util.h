#ifndef _HEADER_FILE_EVENT_UTIL_H_
#define _HEADER_FILE_EVENT_UTIL_H_

#include <stdio.h>

#include <event2/dns.h>
#include <event2/listener.h>
#include <event2/bufferevent.h>
#include <event2/buffer.h>


#ifdef __cplusplus
extern "C" {
#endif


struct bufferevent * eu_start_tcp_client(struct event_base *base, 
    struct sockaddr * saddr,
    bufferevent_data_cb readcb, 
    bufferevent_data_cb writecb,
    bufferevent_event_cb eventcb, 
    void * cbarg);
	
  
#ifdef __cplusplus
}
#endif

#endif // _HEADER_FILE_EVENT_UTIL_H_
