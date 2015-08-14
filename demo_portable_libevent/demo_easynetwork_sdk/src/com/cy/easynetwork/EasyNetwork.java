package com.cy.easynetwork;



public class EasyNetwork {
	
	public native int en_init();
	public native int en_final();	
	public native int en_start(int port);
	public native int en_stop();
	
	public void en_event(int event_type)
	{
		System.out.printf("en_event, event_type="+event_type);
	}
	
	public int start(int port)
	{
		int rt =-1;
		try {
			rt =en_init();
			rt =en_start(port);
		} catch (Exception e) {
			System.out.println("exception ---->"+e);
		}
		return rt;
	}

	public int stop()
	{
		int rt =-1;
		try {
			rt =en_stop();
			rt =en_final();
		} catch (Exception e) {
			System.out.println("exception ---->"+e);
		}
		return rt;
	}


	static {
		System.loadLibrary("easynetwork4j");
	}
}
