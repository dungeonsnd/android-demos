package com.cy.easynetwork;

public class EasyNetwork {
	
	private EasyNetworkEventInterface easyNetworkEvent =null;
	
	public EasyNetwork(EasyNetworkEventInterface ev) {
		easyNetworkEvent =ev;
	}
	
	public native int en_init();
	public native int en_final();	
	public native int en_start(String parm);
	public native int en_stop();
	
	public void en_event(int event_type)
	{
		easyNetworkEvent.onEvent(event_type);
	}
	
	public int start(String parm)
	{
		int rt =-1;
		try {
			rt =en_init();
			rt =en_start(parm);
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
