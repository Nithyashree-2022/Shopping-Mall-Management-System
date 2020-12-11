#include <iostream>
#include <math.h>
using namespace std;

class Time
{
	
	
	public:
		int hh,mm;
		int operator-=(Time &T2)
		{
			
			int mins;
			
			hh-=T2.hh;
			mm-=T2.mm;
			
			mins=hh*60+mm;
			return mins;
			
			
		}
		friend istream& operator>>(istream &input,Time &T);
		
		
};

istream& operator>>(istream &input,Time &T)
{
	input>>T.hh;
	input>>T.mm;
	return input;
}

Time& convertToTime(int slot)
{
	Time t;
	if(slot==1)
	{
		t.hh=9;
		t.mm=0;
		
	}
	else if(slot==2)
	{
		t.hh=12;
		t.mm=0;
		
	}
	else if(slot==3)
	{
		t.hh=15;
		t.mm=0;
		
	}
	else if(slot==4)
	{
		t.hh=18;
		t.mm=0;
		
	}	
	else if(slot==5)
	{
		t.hh=21;
		t.mm=0;
		
	}
	else
	{
		t.hh=0;
		t.mm=0;
	}	
	return t;			
}
