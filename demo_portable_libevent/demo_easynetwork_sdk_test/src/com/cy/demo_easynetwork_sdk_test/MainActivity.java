package com.cy.demo_easynetwork_sdk_test;

import com.cy.easynetwork.EasyNetwork;
import com.cy.easynetwork.EasyNetworkEventInterface;

import android.support.v7.app.ActionBarActivity;
import android.support.v7.app.ActionBar;
import android.support.v4.app.Fragment;
import android.os.Bundle;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;
import android.os.Build;

public class MainActivity extends ActionBarActivity {

	private static EasyNetwork easyNetwork =null;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);

		if (savedInstanceState == null) {
			getSupportFragmentManager().beginTransaction()
					.add(R.id.container, new PlaceholderFragment()).commit();
		}
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {

		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}

	@Override
	public boolean onOptionsItemSelected(MenuItem item) {
		// Handle action bar item clicks here. The action bar will
		// automatically handle clicks on the Home/Up button, so long
		// as you specify a parent activity in AndroidManifest.xml.
		int id = item.getItemId();
		if (id == R.id.action_settings) {
			return true;
		}
		return super.onOptionsItemSelected(item);
	}

	/**
	 * A placeholder fragment containing a simple view.
	 */
	public static class PlaceholderFragment extends Fragment {

		private String TAG ="MainActivity";
		private EasyNetworkEvent asyNetworkEvent;

		public class EasyNetworkEvent implements EasyNetworkEventInterface {
			public void onEvent(int event_type)
			{
				Log.d(TAG, "onEvent, event_type="+event_type);
			}
		}
		
		public PlaceholderFragment() {
			asyNetworkEvent =new EasyNetworkEvent();
		}

		@Override
		public View onCreateView(LayoutInflater inflater, ViewGroup container,
				Bundle savedInstanceState) {
			View rootView = inflater.inflate(R.layout.fragment_main, container,
					false);
			
			TextView tv =(TextView)rootView.findViewById(R.id.textview1);
			if(null!=tv)
			{
				easyNetwork =new EasyNetwork(asyNetworkEvent);
				int rsl =easyNetwork.start("192.168.16.254:8018");
				tv.setText("result is: "+Integer.valueOf(rsl));
			}
			else
				System.out.println("tv is null !");
			return rootView;
		}
	}

}
