#include <iostream>
using namespace std;


class ParkingLot
{
	private:
		static int couponNo,lotNo;
		int time;
		char vehicle_type;
		double charges;
	public:
		ParkingLot(char vehicle_type,int time)
		{
			this->vehicle_type=vehicle_type;
			this->time=time;
			
			couponNo++;
			lotNo++;
		}
		void computeParkingCharges();
		static void displayParking();
};
int ParkingLot::lotNo=0;
int ParkingLot::couponNo=0;

void ParkingLot::computeParkingCharges()
{
	double units=time/10;
	
	/*
		1.Rs.100 for every 10 minutes for two-wheelers
		2.Rs.150 for every 10 mins for 3-wheelers/autos
		3.Rs.200 for every 10 mins for cars
		4.Rs.500 for every 10 mins for lorries
	*/
	
	if(vehicle_type == 't')
		charges = units*100;		
	else if(vehicle_type=='T')
		charges = units*150;
	else if(vehicle_type=='C')
		charges = units*200;
	else
		charges = units*500;
		
	cout<<"Expected time : "<<time<<endl;
	cout<<"Parking charge for your expected time : "<<charges<<endl;
	cout<<"Enjoy your shopping.Please pay before you leave."<<endl;
}

void ParkingLot::displayParking()
{
	cout<<"\nParked your vehicle successfully:"<<endl;
	cout<<"\nYour parking details:"<<endl;
	cout<<"Coupon : "<<couponNo<<endl;
	cout<<"Lot Number : "<<lotNo<<endl;
}

