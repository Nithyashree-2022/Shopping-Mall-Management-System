#include <iostream>
using namespace std;

class Person
{
	protected:
		string name;
		char sex;
		int age;
		long mobNo;
		string email;
		string address;
		
		
	public:
		Person(string n,char s,int a,long mob,string mail,string add)
		{
			name=n;
			sex=s;
			age=a;
			mob=mobNo;
			email=mail;
			address=add;
		}
		
		void displayDetails()
		{
			
			cout<<"Name : "<<name<<endl;
			cout<<"Sex : "<<sex<<endl;
			cout<<"Age : "<<age<<endl;
			cout<<"Mobile No. : "<<mobNo<<endl;
			cout<<"Email-ID : "<<email<<endl;
			cout<<"City : "<<address<<endl;
		}
};

class Customer:public Person
{
	
	int sectID;
	float shid;
	
	public:
		
		static int custID;
		
		
		Customer(string n,char s,int a,long mob,string mail,string add,int sid,float shopID=0.0):Person(n,s,a,mob,mail,add)
		{
			name=n;
			sex=s;
			age=a;
			mobNo=mob;
			email=mail;
			address=add;
			sectID=sid;
			shid=shopID;
		
			custID++;
		}
		void customerDetails()
		{
			
			cout<<"Customer goes to sector : "<<sectID<<endl;
			if(shid!=0.0)
				cout<<"Customer visits the shop : "<<shid<<endl;
		}
};

int Customer::custID = 0;


class Employee:public Person
{
	int empID,sectID;
	float shid;
	
	public:
		Employee(int eid,int sid,string n,char s,int a,long mob,string mail,string add,float shopID=0.0):Person(n,s,a,mob,mail,add)
		{
			empID=eid;
			sectID=sid;
			shid=shopID;
			
			name=n;
			sex=s;
			age=a;
			mobNo=mob;
			email=mail;
			address=add;		
		}
		void empDetails()
		{
			cout<<"Employee-ID : "<<empID<<endl;
			cout<<"Employee works for sector : "<<sectID<<endl;
			if(shid!=0.0)
				cout<<"Employee works for the shop : "<<shid<<endl;
		}
};


class Supplier:public Person
{
	int supID;
	float shopID;
	string company;
	
	public:
		Supplier(int id,string n,char s,int a,long mob,string mail,string add,float shid,string comp):Person(n,s,a,mob,mail,add)
		{
			supID=id;
			shopID=shid;
			company=comp;
			
			name=n;
			sex=s;
			age=a;
			mobNo=mob;
			email=mail;
			address=add;		
		}
		
		void supDetails()
		{
			cout<<"Supplier-ID : "<<supID<<endl;
			cout<<"Shop-ID : "<<shopID<<endl;
			cout<<"Company Name : "<<company<<endl;
		}
};


