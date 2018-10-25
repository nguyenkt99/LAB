#include<iostream>
#include<string.h>
using namespace std;

struct phoneNumber
{
	char area[10];
	char exchange[10];
	char number[10];
};
typedef struct phoneNumber Phone;

void nhap(Phone &p)
{
	cout << "Enter your area code, exchange and number: ";
	cin >> p.area >> p.exchange >> p.number;
}

Phone YourPhone(const char areaX[], const char exchangeX[], const char numberX[])
{
	Phone x;
	strcpy(x.area, areaX);
	strcpy(x.exchange, exchangeX);
	strcpy(x.number, numberX);
	
	return x;
}

void xuat(const string str, Phone p)
{
	cout << str + "phone is: " << "(" << p.area << ") " << p.exchange << "-" << p.number << endl;
}


int main()
{	
	Phone x;
	Phone y;
	
	nhap(y); // Goi ham nhap My Phone
	
	xuat("My ", YourPhone("212", "767", "8900")); // Xuat My Phone
	xuat("Your ", y); // Xuat Your Phone
	
	return 0;
}
