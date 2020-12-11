#include <iostream>
using namespace std;


class Sector
{
	protected:
		int id;
		string name;
		int loc;
		int mid;
		
	public:
		Sector()
		{
			
		}
		Sector(int a,string n,int l,int m)
		{
			id=a;
			name=n;
			loc=l;
			mid=m;
		}
		virtual void display()
		{
			
			cout<<"\n\nSector ID : "<<id<<endl;
			cout<<"Sector Name : "<<name<<endl;
			cout<<"Sector Location(floor Number) : "<<loc<<endl;
			cout<<"Sector Manager ID : "<<mid<<endl;
		}
};

class Security:public Sector
{
	public:
		Security(int x,string y,int z,int w):Sector(x,y,z,w)
		{
			
		}
		void func()
		{
			cout<<"FOR MALL SECURITY"<<endl;
		}
	
};

class Maintenance:public Sector
{
	public:
		Maintenance(int x,string y,int z,int w):Sector(x,y,z,w)
		{
		
		}
		void action()
		{
			cout<<"FOR MALL MAINTENANCE-CLEANING,PLUMBING AND MORE"<<endl;
		}		
};

class HelpLine:public Sector
{
	public:
		HelpLine(int x,string y,int z,int w):Sector(x,y,z,w)
		{
			
		}
		
		void helpCustomer()
		{
			cout<<"Dear customer,thank you for consulting us.We will get back to you once the issue is resolved.We seriously regret the inconvenience."<<endl;
		}
};

class Shop:public Sector
{
	protected:
		float shopID;
	
	public:
	Shop()
	{
		
	}
	Shop(int x,string y,int z,int w):Sector(x,y,z,w)
	{
		
			
	}
	
	Shop(float id)
	{
		shopID=id;
	}
	
	void info()
	{
		cout<<"\n\nShops are in 3 floors in the shopping mall"<<endl;
		cout<<"Sector ID : "<<id<<endl;
		cout<<"Sector Name : "<<name<<endl;		
	}
	
	//override display()
	void display()
	{
		cout<<"\n\nSector Location(floor Number) : "<<loc<<endl;
		cout<<"Sector Manager ID : "<<mid<<endl;	
	}	
	
	
};

