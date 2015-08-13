package com.cy.androidsdk;

public class TestSdk {

	static{
		  System.loadLibrary("TestSdk"); 
	}

	public static native int func(int a , int b);
	
	public static int sdkinterface_func(int a, int b)
	{
		int i =-1;
		try {
			i =func(a,b);
		} catch (Exception e) {
			System.out.println("exception ---->"+e);
		}
		return i;
	}
}
