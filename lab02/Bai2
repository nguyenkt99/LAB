#include<iostream>
using namespace std;
struct GuiTien // Khai bao cau truc tien gui ngan hang
{
	float TienBD;
	int Nam;
	float LaiSuat;
};
typedef struct GuiTien Tien;

void nhap(Tien &t) // Ham nhap thong tin tien gui ngan hang
{
	cout << "Nhap so tien can gui: ";
	cin >> t.TienBD;
	cout << "Nhap so nam can gui: ";
	cin >> t.Nam;
	cout << "Nhap lai suat ngan hang: ";
	cin >> t.LaiSuat;
}

double tinhTien(Tien t) // Ham tinh so tien co duoc sau n nam gui
{
	
	for(int i = 1; i <= t.Nam; i++)
	{
		t.TienBD = (t.TienBD * (float)t.LaiSuat/100) + t.TienBD;
	}
	return t.TienBD;
}

int main()
{
	Tien t;	
	
	nhap(t);
	tinhTien(t);
	
	double Result = tinhTien(t);
	
	cout << "\nSo tien nhan duoc sau " << t.Nam << " la: " << Result << " dollars";
	
	
	return 0;
}
