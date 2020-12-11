#include <iostream>
using namespace std;



class ProductDetails
{
	protected:
		double prodID;
		string name;
		string brand;
		int size;
	public:
		ProductDetails()
		{
			
		}
		ProductDetails(int id,string n,string b,int s)
		{
			prodID=id;
			name=n;
			brand=b;
			size=s;
		}
};
