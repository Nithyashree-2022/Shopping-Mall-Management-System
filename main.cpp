#include <iostream>
#include "ParkingLot.cpp"
#include "Person.cpp"
#include "ProductDetails.cpp"
#include "Time.cpp"
#include "Sector.cpp"
using namespace std;

class Cuisine:public Shop,public ProductDetails
{
	
	public:
		Cuisine():Shop(),ProductDetails()
		{
			
		}
		Cuisine(float sid,double pid,string pname,int psize,string pbrand)
		:Shop(sid),ProductDetails(pid,pname,pbrand,psize)
		{
			
			
		}
		
		void displayMenu()
		{
			cout<<"\n********************WELCOME TO CUISINE!!!!!************************\n"<<endl;
			cout<<"2.11 Burger"<<endl;
			cout<<"\t\t2.111 Veggie Burger"<<endl;
			cout<<"\t\t2.112 Black Bean Burger"<<endl;
			
			cout<<"2.12 Soft Drinks"<<endl;
			cout<<"\t\t2.121 Coco-cola"<<endl;
			cout<<"\t\t2.122 Sprite"<<endl;
			
			cout<<"2.13 Icecreams"<<endl;
			cout<<"\t\t2.131 Strawberry icecream"<<endl;
			cout<<"\t\t2.132 Mango icecream"<<endl;			
		}
		
		void brandsList(double prodid)
		{
			if(prodid == (double)2.111 || prodid == (double)2.112)
				cout<<"We have two brands of burgers-\t1.McDonalds and \t2.Yummy"<<endl;
			else if(prodid == (double)2.121 || prodid == (double)2.122)
				cout<<"We have two brands of soft drinks-\t1.McCafe and \t2.Pepsi"<<endl;
			else if(prodid == (double)2.131 || prodid == (double)2.132)
				cout<<"We have two brands of icecreams-\t1.Amul and \t2.Kwality Walls"<<endl;
			else
				cout<<"Please enter a valid product ID."<<endl;
			
		}
		
		void sizeGuide(double prodid)
		{
			cout<<"\nPlease enter the size as follows:"<<endl;
			if(prodid == (double)2.111 || prodid == (double)2.112)
				cout<<"Burgers:0 for mini burger,1 for normal burger"<<endl;
			else if(prodid == (double)2.121 || prodid == (double)2.122)
				cout<<"Drinks:0 for half bottle and 1 for full bottle"<<endl;
			else if(prodid == (double)2.131 || prodid == (double)2.132)
				cout<<"Ice-creams:Enter number of scoops(minimum 2 and maximum 5)"<<endl;
			else
				cout<<"Please enter a valid product ID."<<endl;
		}
		
		int verifySize(int s,double prodid)
		{
			if(prodid == (double)2.111 || prodid == (double)2.112)
			{
				if(s!=0 && s!=1)
				{
					cout<<"Please enter a valid size.You can either order a mini-size or normal-size."<<endl;
					return 0;
				}	
				
			}
			
			else if(prodid == (double)2.121 || prodid == (double)2.122)
			{
				if(s!=0 && s!=1)
				{
					cout<<"Please enter a valid size.You can either order a half bottle or a full bottle."<<endl;
					return 0;
				}	
			}
			else if(prodid == (double)2.131 || prodid == (double)2.132)
			{
				if(s < 2)
				{
					cout<<"Please enter a valid number of scoops between 2 and 5."<<endl;
					return 0;
				}
				
				else if(s > 5)
				{
					cout<<"Please enter a valid number of scoops between 2 and 5."<<endl;
					return 0;
				}
				else
				{
					//
				}
			}
			else
			{
				cout<<"Please enter a valid product ID"<<endl;
				return 0;
			}
			return 1;
		}
		
		int verifyBrand(int bno)
		{
			if(bno!=1 && bno!=2)
			{  
				cout<<"Please enter a valid brand number and try again later."<<endl;
				return 0;
			}
			else
				return 1;
		}
		
		string getBrand(double prodid,int brandNo)
		{
			if(prodid == (double)2.111 || prodid == (double)2.112)
			{
				if(brandNo==1)
					return "McDonalds";
				else 
					return "Yummy";
			}
			else if(prodid == (double)2.121 || prodid == (double)2.122)
			{
				if(brandNo==1)
					return "McCafe";
				else 
					return "Pepsi";
				
			}
			else
			{
				if(brandNo==1)
					return "Amul";
				else 
					return "Kwality_Walls";
			}
		}

};

class MoviesNow:public Shop,public ProductDetails
{
	string genre,language;
	char restriction;  //K/U/A film?
	Time timings;
	
	public:
		MoviesNow():Shop(),ProductDetails()
		{
			
		}
		
		
		MoviesNow(Time &T,string g,string lang,char r,float sid,double pid,string pname,int duration)
		:Shop(sid),ProductDetails(pid,pname,g,duration)
		{
			timings=T;
			genre=g;
			language=lang;
			restriction=r;
		}
		
		int verifyAge(int age,char rest)
		{
			if(rest == 'A' && age<18)
			{
				cout<<"Sorry,your age violates the Community Guidelines."<<endl;
				return 0;
			}
			else if(rest == 'K' && age<8)
			{
				cout<<"Sorry,kids below 8 years are prohibited from watching this horror movie."<<endl;
				return 0;
			}
			
			else
			{
				cout<<"Congrats!!!!!!!!!!\n\nYou are eligible to watch the movie!!\nLets book the ticket now!!!"<<endl;
				return 1;
			}
		}
		
		void displayMenu()
		{
			cout<<"***************************WELCOME TO MOVIESNOW!!!!!!!!!!!******************"<<endl;
			cout<<"2.21 Laxmii"<<endl;
			cout<<"2.22 Titanic"<<endl;
			cout<<"2.23 Penguin"<<endl;
			cout<<"2.24 2 States"<<endl;
			cout<<"SLOTS:\n\t9:00\t12:00\t15:00\t18:00\t21:00"<<endl;
		}
		
		char movieInfo(double id)
		{
			/*
				K->Min age=8
				A->Min age=18
				U->all can watch
				N->Not applicable(to handle invalid movie IDs
			*/
			
			if(id==(double)2.21)
			{
				cout<<"Laxmii is a 2020 Indian Hindi-language comedy horror film written and directed by Raghava Lawrence in his first Bollywood directorial.\nA remake of his own 2011 Tamil film Kanchana, it stars Akshay Kumar and Kiara Advani in the lead roles!!!"<<endl;
				return 'K';	
			}
			else if(id==(double)2.22)
			{
				cout<<"Seventeen-year-old Rose hails from an aristocratic family and is set to be married.When she boards the Titanic, she meets Jack Dawson, an artist, and falls in love with him!!!\nIts an English romantic tragedy movie..."<<endl;
				return 'A';
			}	
				
			else if(id==(double)2.24)
			{
				cout<<"Coming from two very different cultural backgrounds, Krish and Ananya try to convince their parents to bless their relationship before they get married.\nIts a Hindi light-hearted romantic movie!!!"<<endl;
				return 'U';
			}
				
			else if(id==(double)2.23)
			{
				cout<<"Rhythm, a pregnant woman, is traumatised by nightmares about the unsolved kidnapping of her first child, Ajay. Soon, she embarks on a harrowing mission to solve the mystery of Ajay's disappearance.\nIt is a Telugu mystery movie!!!"<<endl;
				return 'U';
				
			}
			else	
			{
				cout<<"Please enter a valid movie ID."<<endl;
				return 'N';
				
			}
				
		}
		
		string findGenre(double id)
		{
			if(id==(double)2.21)
				return "horror";
			else if(id==(double)2.22)
				return "love";
			else if(id==(double)2.23)
				return "mystery";
			else 
				return "romance";
				
		}
		
		string findLang(double id)
		{
			if(id==(double)2.21)
				return "hindi";
			else if(id==(double)2.22)
				return "english";
			else if(id==(double)2.23)
				return "telugu";
			else 
				return "hindi";
		}
	
};

class ReadersDigest:public Shop,public ProductDetails
{
	int edition;
	string author,genre;
	
	public:
		ReadersDigest():Shop(),ProductDetails()
		{
			
		}		
		
		ReadersDigest(double ISBN,string book,string auth,int ed,string g,float sid,int pages):
		Shop(sid),ProductDetails(ISBN,book,g,pages)
		{
			edition=ed;
			author=auth;
			genre=g;
		}
		
		void displayMenu()
		{
			cout<<"***************************WELCOME TO READERS' DIGEST!!!!!!!!!!!******************"<<endl;
			cout<<"2.31 Intro to Probability"<<endl;
			cout<<"2.32 Pandemic 2020"<<endl;
			cout<<"2.33 The Story Of My Life"<<endl;
			cout<<"2.34 Just friends..."<<endl;
		}
		
		string getGenre(double bookid)
		{
			if(bookid==(double)2.31)
			{
				return "sci";
			}
			else if(bookid==(double)2.32)
			{
				return "awareness";
			}
			else if(bookid==(double)2.33)
			{
				return "autobio";
			}
			else if(bookid==(double)2.34)
			{
				return "love";
			}
			else
			{
				return "none";
			}
		}
	
};

class Attire:public Shop,public ProductDetails
{
	string color,sleeve,type;
	public:
		Attire():Shop(),ProductDetails()
		{
			
		}
		
		
		Attire(string c,string m,string s,float sid,double clothID,string cloth,string comp,int clothSize)
		:Shop(sid),ProductDetails(clothID,cloth,comp,clothSize)
		{
			color=c;
			type=m;  //salwar/frock/pant..
			sleeve=s;			
		}
		
		void displayMenu()
		{
			cout<<"***************************WELCOME TO ATTIRE!!!!!!!!!!!******************"<<endl;
			cout<<"2.41 Pant"<<endl;
			cout<<"2.42 Frock"<<endl;
			cout<<"2.43 Salwaar Tops"<<endl;
		}
		
		int brandsList(double cid)
		{
			if(cid==(double)2.41)
			{
				cout<<"Pants are of brand:1.Denims"<<endl;
				return 1;
			}
				
			else if(cid==(double)2.42)
			{
				cout<<"Frocks are of brand:1.Denims"<<endl;
				return 1;				
			}				
			else if(cid==(double)2.43)
			{
				cout<<"Salwars are of brand:1.Srishti"<<endl;
				return 1;
			}
				
			else
			{
				cout<<"\nInvalid cloth ID."<<endl;
				return 0;				
			}
				
		}
		
		int verifyBrands(double cid,string brand)
		{
			if(cid==(double)2.41 && brand=="Denims" )
				return 1;
			else if(cid==(double)2.42 && brand=="Denims")
				return 1;
			else if(cid==(double)2.43 && brand=="Srishti")
				return 1;
			else
				return 0;
		}
		
		int verifySize(int size)
		{
			//int sizes[]={25,32,36,40,50};
			if(size==25||size==32||size==36||size==40||size==50)
			{
				return 1;
			}
			else
				return 0;
		}
		void sizeGuide()
		{
			cout<<"Pants,frocks or salwars are available for the following sizes:\n25\n32\n36\n40\n50"<<endl;
		}
	
};



class ShoppingCart1:public Cuisine
{
	protected:
		int qty;
	public:
		ShoppingCart1(int q,float shopid,double pid,string pname,int psize,string pbrand)
		:Cuisine(shopid,pid,pname,psize,pbrand)
		{
			qty=q;
		}
		
};

class ShoppingCart2:public MoviesNow
{
	protected:
		int qty;
	public:
		ShoppingCart2(int q,Time &T,string g,string lang,char r,float sid,double pid,string pname,int duration)
		:MoviesNow(T,g,lang,r,sid,pid,pname,duration)
		{
			qty=q;
		}
};

class ShoppingCart3:public ReadersDigest
{
	protected:
		int qty;
	public:
	ShoppingCart3(int q,double ISBN,string book,string auth,int ed,string g,float sid,int pages)
	:ReadersDigest(ISBN,book,auth,ed,g,sid,pages)
	{
		qty=q;
	}
};

class ShoppingCart4:public Attire
{
	protected:
		int qty;
	public:
	ShoppingCart4(int q,string c,string m,string s,float sid,double clothID,string clothName,string comp,int clothSize)
	:Attire(c,m,s,sid,clothID,clothName,comp,clothSize)
	{
		qty=q;
	}
};


class BillingCounter1:public ShoppingCart1
{
	double price,vat,gst,discount;
	string IFSC,AccNo,bank;
	int PIN;
	static int transactionID;
	
	
	public:
		//static double total;
		
		BillingCounter1(double p,double v,double g,double d,string code,string acc,string bname,
		int pin,int q,float shopid,double pid,string pname,int psize,string pbrand)
		:ShoppingCart1(q,shopid,pid,pname,psize,pbrand)
		{
			price=p;
			vat=v;
			gst=g;
			discount=d;
			IFSC=code;
			AccNo=acc;
			bank=bname;
			PIN=pin;
			transactionID++;
		}
		
		static void transaction()
		{
			cout<<"\nTransaction ID : "<<transactionID<<endl;
		}
		
		double computeBill()
		{
			double billamt,taxes,discamt;
			taxes=(gst*100)+(vat*100);
			discamt=discount*100;
			billamt=(price*qty)+taxes-discamt;
			return billamt;			
		}
		/*
		static void computeTotal(double bill)
		{
			total+=bill;
			//print final total in main and not here...
		}*/
};
int BillingCounter1::transactionID = 0;
//double BillingCounter1::total = 0.0;

class BillingCounter2:public ShoppingCart2
{
	double price,vat,gst,discount;
	string IFSC,AccNo,bank;
	int PIN;
	static int transactionID;
	
	
	public:
		//static double total;
		
		BillingCounter2(double p,double v,double g,double d,string code,string acc,string bname,
		int pin,int q,Time &T,string gen,string lang,char r,float sid,double pid,string pname,int duration)
		:ShoppingCart2(q,T,gen,lang,r,sid,pid,pname,duration)
		{
			price=p;
			vat=v;
			gst=g;
			discount=d;
			IFSC=code;
			AccNo=acc;
			bank=bname;
			PIN=pin;
			transactionID++;
		}
		
		static void transaction()
		{
			cout<<"\nTransaction ID : "<<transactionID<<endl;
		}
		double computeBill()
		{
			double billamt,taxes,discamt;
			taxes=(gst*100)+(vat*100);
			discamt=discount*100;
			billamt=price+taxes-discamt;
			return billamt;				
		}
		/*
		static void computeTotal(double bill)
		{
			total+=bill;
			//print final total in main and not here...
		}*/
};
int BillingCounter2::transactionID = 0;
//double BillingCounter2::total = 0.0;

class BillingCounter3:public ShoppingCart3
{
	double price,vat,gst,discount;
	string IFSC,AccNo,bank;
	int PIN;
	static int transactionID;
	
	
	public:
		//static double total;
		
		BillingCounter3(double p,double v,double g,double d,string code,string acc,string bname,
		int pin,int q,double ISBN,string book,string auth,int ed,string genre,float sid,int pages)
		:ShoppingCart3(q,ISBN,book,auth,ed,genre,sid,pages)
		{
			price=p;
			vat=v;
			gst=g;
			discount=d;
			IFSC=code;
			AccNo=acc;
			bank=bname;
			PIN=pin;
			transactionID++;
		}
		
		static void transaction()
		{
			cout<<"\nTransaction ID : "<<transactionID<<endl;
		}
		
		double computeBill()
		{
			double billamt,taxes,discamt;
			taxes=(gst*100)+(vat*100);
			discamt=discount*100;
			billamt=price+taxes-discamt;
			return billamt;	
			
		}
		/*
		static void computeTotal(double bill)
		{
			total+=bill;
			//print final total in main and not here...
		}*/
};
int BillingCounter3::transactionID = 0;
//double BillingCounter3::total = 0.0;

class BillingCounter4:public ShoppingCart4
{
	double price,vat,gst,discount;
	string IFSC,AccNo,bank;
	int PIN;
	static int transactionID;
	
	
	public:
		//static double total;
		
		BillingCounter4(double p,double v,double g,double d,string code,string acc,string bname,
		int pin,int q,string c,string m,string s,float sid,double clothID,string clothname,
		string comp,int clothSize)
		:ShoppingCart4(q,c,m,s,sid,clothID,clothname,comp,clothSize)
		{
			price=p;
			vat=v;
			gst=g;
			discount=d;
			IFSC=code;
			AccNo=acc;
			bank=bname;
			PIN=pin;
			transactionID++;
		}
		
		static void transaction()
		{
			cout<<"\nTransaction ID : "<<transactionID<<endl;
		}
		
		double computeBill()
		{
			double billamt,taxes,discamt;
			taxes=(gst*100)+(vat*100);
			discamt=discount*100;
			billamt=price+taxes-discamt;
			return billamt;				
		}
		/*
		static void computeTotal(double bill)
		{
			total+=bill;
			//print final total in main and not here...
		}*/
};
int BillingCounter4::transactionID = 0;
//double BillingCounter4::total = 0.0;




main()
{
	
	
	char ch;
	int a,est,status=1;
	
	do
	{
	
		cout<<"\n\t\t\t\t\t\t\t\t\tWELCOME TO OUR SHOPPING MALL!!!!!\t\t\t\t\t\t\t\t\t\t"<<endl;
		cout<<"*************SECTORS IN OUR SHOPPING MALL**********"<<endl;
			
			
		HelpLine H(1,"Help_Line",0,11);
		H.display();
		cout<<"***********************************************************************"<<endl;
	
		Shop S1(2,"Shops",0,101);
		Shop S2(2,"Shops",1,201);
		Shop S3(2,"Shops",2,301);
		cout<<"***********************************************************************"<<endl;
	
		S1.info();
		cout<<"***********************************************************************"<<endl;
		
		S1.display();
		S2.display();
		S3.display();
		cout<<"***********************************************************************"<<endl;
		
		Security S(3,"Security",-1,12);
		S.display();
		cout<<"***********************************************************************"<<endl;
		
		Maintenance M(4,"Maintenance",-1,13);
		M.display();
		cout<<"***********************************************************************"<<endl;
	
		cout<<"\nWhere do you want to go first????"<<endl;
		cout<<"\n1.Parking Lot\n2.Sector"<<endl;
		cin>>a;
	
	
		if(a==1)
		{
			cout<<"Enter your expected time:"<<endl;
			cin>>est;
			cout<<"Vehicle type:t for two-wheeler,T for three-wheeler,C for car and A for lorries."<<endl;
			cin>>ch;
			ParkingLot pl(ch,est);
			ParkingLot::displayParking();
			pl.computeParkingCharges();
		
		}
		
		else if(a==2)
		{
			int category,id,age,sect;
			float sid;
			long mobile;
			string name,city,mailID,comp;
			char sex;
			
			cout<<"\nPlease enter your personal details as follows:\n"<<endl;
			cout<<"Name:"<<endl;
			cin>>name;
			cout<<"Sex:(Enter M for male,F for female and O for others)"<<endl;
			cin>>sex;
			cout<<"Age:"<<endl;
			cin>>age;
			
			cout<<"\nPlease enter your contact details as follows:\n"<<endl;
			cout<<"Mobile Number:"<<endl;
			cin>>mobile;
			cout<<"Email ID : "<<endl;
			cin>>mailID;
			cout<<"City:"<<endl;
			cin>>city;
			
			cout<<"Who are you?-\nPlease enter the valid option from here\n1.Employee\n2.Customer\n3.Supplier"<<endl;
			cin>>category;
			try
			{
			
			if(category==1 || category==3)
			{
				cout<<"\nPlease enter your ID:"<<endl;
				cin>>id;				
			}
			
			
			
			if(category==2)
			{
				
				cout<<"Purpose of visit:-Enter the codes as follows:\n1.HelpLine\n2.Shops\n3.Security\n4.Maintenance"<<endl;
				cin>>sect;
				
				if(sect==2)
				{
					//which shop?
					cout<<"Which shop do you wanna go to?\nEnter codes as follows:\n2.1.Cuisine\n2.2MoviesNow\n2.3ReadersDigest\n2.4Attire"<<endl;
					cin>>sid;
					
					if(sid == (float)2.1)
					{
						double pid;
						int brandNo,order;
						int size,qty,cond1,cond2;
						string pname;
						
						Cuisine C;
						C.displayMenu();
						
						cout<<"\nDear customer,please type in the product id of what you would like to order:"<<endl;
						cin>>pid;
						
						cout<<"\nHere is the list of brands available.Which brand would you like to order???"<<endl;
						C.brandsList(pid);
						cin>>brandNo;
						cond1=C.verifyBrand(brandNo);
						
						cout<<"Enter the product name:"<<endl;
						cin>>pname;
						
						C.sizeGuide(pid);
						cin>>size;
						cond2=C.verifySize(size,pid);
						
						if(cond1 && cond2)
						{
							cout<<"How many such plates would you like to order?"<<endl;
							cin>>qty;
							
							string brandName=C.getBrand(pid,brandNo);							
							
							//add to cart:
							ShoppingCart1 *SC1=new ShoppingCart1(qty,sid,pid,pname,size,brandName);
							
							cout<<"\nAre you sure of your order?Can we proceed to the billing counter?-Press 0 to cancel order,1 for billing:"<<endl;
							cin>>order;
							if(order==0)
							{
								delete SC1;
								cout<<"Your order has been cancelled."<<endl;
							}
							else if(order==1)
							{
								//billing counter1's obj:
								double mrp,gst,vat,disc;
								string ifsc,acc,bank;
								int pin;
								
								cout<<"Enter MRP,GST,VAT,DISCOUNT of product:"<<endl;
								cin>>mrp>>gst>>vat>>disc;
								cout<<"Enter payment details:IFSC Code,account number,bank name and PIN: "<<endl;
								cin>>ifsc>>acc>>bank>>pin;
								BillingCounter1 B1(mrp,vat,gst,disc,ifsc,acc,bank,pin,qty,sid,pid,pname,size,brandName);
								double billamt=B1.computeBill();
								//BillingCounter1::computeTotal(billamt);
								BillingCounter1::transaction();
								cout<<"\nBill AMT = "<<billamt<<endl;
								//cout<<"\nTotal amt = "<<BillingCounter1::total<<endl;								
								//BillingCounter1::computeTotal(billamt);
								//cout<<"Total Billamt = "<<BillingCounter1::total<<endl;
							}
						}
						else
						{
							cout<<"Please enter valid size,brand number and product ID and try again later."<<endl;
						}
						
						
						
										
					}
					else if(sid == (float)2.2)
					{
						MoviesNow M;
						M.displayMenu();
						
						double movieID;
						string movieName;
						int numOfTickets,slot,order;
						
						cout<<"\nDear customer,which movie would you like to watch?Please type in its movie ID:"<<endl;
						cin>>movieID;		
						
						char movieR=M.movieInfo(movieID);
						if(movieR!='N') 
						{
							cout<<"Enter the movie name:"<<endl;
							cin>>movieName;
							string movieGenre=M.findGenre(movieID);	//brandName
							string movieLang=M.findLang(movieID);
							int cond=M.verifyAge(age,movieR);
							if(cond==1)
							{
								cout<<"SLOTS:\n\t1.9:00\t2.12:00\t3.15:00\t5.18:00\t6.21:00"<<endl;
								cout<<"Please enter the number of the slot you wish to book:"<<endl;
								cin>>slot;
								Time t=convertToTime(slot);							
								if(t.hh!=0)
								{
									
									cout<<"How many such tickets would you like to book?"<<endl;
								cin>>numOfTickets;
								/*
								
									CODE TO FIND RUNNING TIME OF MOVIE:
										1.INPUT START AND END TIMES
										2.INVOKE OPERATOR OVERLOADED MEMBER FUNC OF TIME
										3.GET DURATION
										4.PASS DURATION AS PARAMETER TO SC2								
								*/
								
								int movieDuration;
								Time start,end;
								cout<<"Enter the movie start time:"<<endl;
								cin>>start;
								cout<<"Enter movie end time:"<<endl;
								cin>>end;
								
								movieDuration=end.operator-=(start);						
							
							//add to cart:
							ShoppingCart2 *SC2=new ShoppingCart2(numOfTickets,t,movieGenre,movieLang,movieR,sid,
							movieID,movieName,movieDuration);
							
							cout<<"\nAre you sure of your order?Can we proceed to the billing counter?-Press 0 to cancel order,1 for billing:"<<endl;
							cin>>order;
							if(order==0)
							{
								delete SC2;
								cout<<"Your movie ticket has been cancelled."<<endl;
							}
							else 
							{
								//billing counter1's obj:
								double mrp,gst,vat,disc;
								string ifsc,acc,bank;
								int pin;
								
								cout<<"Enter ticket price,GST,VAT,DISCOUNT of product:"<<endl;
								cin>>mrp>>gst>>vat>>disc;
								cout<<"Enter payment details:IFSC Code,account number,bank name and PIN: "<<endl;
								cin>>ifsc>>acc>>bank>>pin;
								BillingCounter2 B2(mrp,vat,gst,disc,ifsc,acc,bank,pin,numOfTickets,t,movieGenre
								,movieLang,movieR,sid,movieID,movieName,movieDuration);
								double billamt=B2.computeBill();
								//BillingCounter2::computeTotal(billamt);
								BillingCounter2::transaction();
								cout<<"\nBill AMT = "<<billamt<<endl;
								//cout<<"\nTotal amt = "<<BillingCounter1::total<<endl;								
								//BillingCounter1::computeTotal(billamt);
								//cout<<"Total Billamt = "<<BillingCounter1::total<<endl;
							}
						 }
						}
									
									
					   }
								
						else
						{
							cout<<"Please enter valid movieID and try again later."<<endl;
						}
							
					}							
						
						
							
						
					
					else if(sid == (float)2.3)
					{
						ReadersDigest RD;
						RD.displayMenu();
						
						int pages,copies,editionNo;
						double bookID;
						string bookName,bookGenre,authorName;
						int order;
						
						cout<<"\nDear customer,please type in the ISBN of the book you would like to order:"<<endl;
						cin>>bookID;
						
						bookGenre=RD.getGenre(bookID);
						if(bookGenre!="none")
						{
							
							cout<<"Enter the book name:"<<endl;
							cin>>bookName;
						
							cout<<"Enter number of pages in the book:"<<endl;
							cin>>pages;
							
							cout<<"How many such copies would you like to order?"<<endl;
							cin>>copies;
							
							cout<<"Enter the author name and edition number:"<<endl;
							cin>>authorName>>editionNo;
							
							
							//add to cart:
							ShoppingCart3 *SC3=new ShoppingCart3(copies,bookID,bookName,authorName,editionNo,
							bookGenre,sid,pages);
							
							cout<<"\nAre you sure of your order?Can we proceed to the billing counter?-Press 0 to cancel order,1 for billing:"<<endl;
							cin>>order;
							if(order==0)
							{
								delete SC3;
								cout<<"Your order has been cancelled."<<endl;
							}
							else if(order==1)
							{
								//billing counter3's obj:
								double mrp,gst,vat,disc;
								string ifsc,acc,bank;
								int pin;
								
								cout<<"Enter MRP,GST,VAT,DISCOUNT of book:"<<endl;
								cin>>mrp>>gst>>vat>>disc;
								cout<<"Enter payment details:IFSC Code,account number,bank name and PIN: "<<endl;
								cin>>ifsc>>acc>>bank>>pin;
								BillingCounter3 B3(mrp,vat,gst,disc,ifsc,acc,bank,pin,copies,bookID,bookName,
								authorName,editionNo,bookGenre,sid,pages);
								double billamt=B3.computeBill();
								//BillingCounter1::computeTotal(billamt);
								BillingCounter3::transaction();
								cout<<"\nBill AMT = "<<billamt<<endl;
								//cout<<"\nTotal amt = "<<BillingCounter1::total<<endl;								
								//BillingCounter1::computeTotal(billamt);
								//cout<<"Total Billamt = "<<BillingCounter1::total<<endl;
							}
						
						}
						
						else
						{
							cout<<"Please enter valid book ISBN and try again later."<<endl;
						}				
							
						
						
					}
					else if(sid == (float)2.4)
					{
						Attire A;
						A.displayMenu();
						
						double clothID;
						int cond1,cond2,qty,size,order;
						string cloth,color,material,sleeves,brand;
						
						
						cout<<"\nDear customer,please type in the cloth id of the cloth you would like to order:"<<endl;
						cin>>clothID;
						
						cout<<"\nHere is the list of brands available.Which brand would you like to order???"<<endl;
						if(A.brandsList(clothID))
						{
						
						
							cin>>brand;
						cond1=A.verifyBrands(clothID,brand);	//
						
						cout<<"Enter the cloth name:"<<endl;
						cin>>cloth;
						
						A.sizeGuide();	//
						cin>>size;
						cond2=A.verifySize(size);	//
						
						if(cond1 && cond2)
						{
							
							cout<<"Enter colour,type of material and sleeve-type of the attire:"<<endl;
							cin>>color>>material>>sleeves;
							cout<<"How many such clothes would you like to order?"<<endl;
							cin>>qty;
							
													
							
							//add to cart:
							ShoppingCart4 *SC4=new ShoppingCart4(qty,color,material,sleeves,
							sid,clothID,cloth,brand,size);
							
							
							cout<<"\nAre you sure of your order?Can we proceed to the billing counter?-Press 0 to cancel order,1 for billing:"<<endl;
							cin>>order;
							if(order==0)
							{
								delete SC4;
								cout<<"Your order has been cancelled."<<endl;
							}
							else if(order==1)
							{
								//billing counter4's obj:
								double mrp,gst,vat,disc;
								string ifsc,acc,bank;
								int pin;
								
								cout<<"Enter MRP,GST,VAT,DISCOUNT of the attire:"<<endl;
								cin>>mrp>>gst>>vat>>disc;
								cout<<"Enter payment details:IFSC Code,account number,bank name and PIN: "<<endl;
								cin>>ifsc>>acc>>bank>>pin;
								BillingCounter4  B4(mrp,vat,gst,disc,ifsc,acc,bank,pin,qty,color,material,sleeves,
								sid,clothID,cloth,brand,size);
								double billamt=B4.computeBill();
								//BillingCounter1::computeTotal(billamt);
								BillingCounter4::transaction();
								cout<<"\nBill AMT = "<<billamt<<endl;
								//cout<<"\nTotal amt = "<<BillingCounter1::total<<endl;								
								//BillingCounter1::computeTotal(billamt);
								//cout<<"Total Billamt = "<<BillingCounter1::total<<endl;
							}
						}
						else
						{
							cout<<"Please enter valid size,brand number and product ID and try again later."<<endl;
						}
					  }
				    }
					else
					{
						cout<<"Please enter a valid option"<<endl;
					}	
					
					
					Customer C(name,sex,age,mobile,mailID,city,sect,sid);
					cout<<"\n*************DETAILS***********\n"<<endl;
					cout<<"Your Customer ID : "<<Customer::custID<<endl;
					C.customerDetails();
					C.displayDetails();
				}	
				if(sect==1)
				{
					H.helpCustomer();
					Customer C(name,sex,age,mobile,mailID,city,sect);
					
					cout<<"\n*************DETAILS***********\n"<<endl;
					cout<<"Your Customer ID : "<<Customer::custID<<endl;
					C.customerDetails();
					C.displayDetails();
					
				}
				
				if(sect==4)
				{
					M.action();
					Customer C(name,sex,age,mobile,mailID,city,sect);
					
					cout<<"\n*************DETAILS***********\n"<<endl;
					cout<<"Your Customer ID : "<<Customer::custID<<endl;
					C.customerDetails();
					C.displayDetails();
					
				}
				
				if(sect==3)
				{
					S.func();
					Customer C(name,sex,age,mobile,mailID,city,sect);
					
					cout<<"\n*************DETAILS***********\n"<<endl;
					cout<<"Your Customer ID : "<<Customer::custID<<endl;
					C.customerDetails();
					C.displayDetails();
					
				}
				
				
				
			}
			
			else if(category==1)
			{
				
				
				cout<<"Which sector do you belong to?-Enter the codes as follows:\n1.HelpLine\n2.Shops\n3.Security\n4.Maintenance"<<endl;
				cin>>sect;
				
				if(sect==2)
				{
					//which shop?
					cout<<"Which shop do you belong to?\nEnter codes as follows:\n2.1.Cuisine\n2.2MoviesNow\n2.3ReadersDigest\n2.4Attire"<<endl;
					cin>>sid;
					cout<<"\n*************DETAILS***********\n"<<endl;
					Employee E(id,sect,name,sex,age,mobile,mailID,city,sid);
					E.empDetails();
					E.displayDetails();
				}
				
				else
				{
					cout<<"\n*************DETAILS***********\n"<<endl;
					Employee E(id,sect,name,sex,age,mobile,mailID,city);
					E.empDetails();
					E.displayDetails();
				}		
				
				
				
			}
			
			else if(category==3)
			{
				cout<<"Which company are you representing?"<<endl;
				cin>>comp;				
				
				cout<<"Which shop do you supply for?\nEnter codes as follows:\n2.1.Cuisine\n2.2MoviesNow\n2.3ReadersDigest\n2.4Attire"<<endl;
				cin>>sid;
				Supplier S(id,name,sex,age,mobile,mailID,city,sid,comp);
				cout<<"\n*************DETAILS***********\n"<<endl;
				S.supDetails();
				S.displayDetails();
			}
			else
			{
				throw category;
			}
			}
			catch(...)
			{
				cout<<category<<" is not a valid category.Please enter 1,2 or 3."<<endl;
			}
			
			
		}
		else
		{
			cout<<"Please enter a valid option-1 or 2."<<endl;
		}
		
		cout<<"Do you want to continue?Press 0 to exit,1 to continue."<<endl;
		cin>>status;
		
	}while(status);
	
	
	cout<<"Thanks for shopping with us!!!!Visit again!!!"<<endl;
	
	
			
}
