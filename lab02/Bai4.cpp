#include<iostream>
using namespace std;

struct phanso // khai bao struct phan so gom tu so va mau so
{
	int tuso;
	int mauso;
};
typedef struct phanso PhanSo;

struct haiPhanSo // khai bao struct gom 2 phan so
{
	PhanSo A;
	PhanSo B;
	char pheptinh; // khai bao toan tu (phep tinh)
};
typedef haiPhanSo PHANSO;

void nhap(PHANSO &ps)
{
	char temp; // ki tu temp thuong nhap dau "/" de phan biet tu so va mau so
	char op = ps.pheptinh; // toan tu (phep tinh +, -, *, /)
	do{
		cout << "\nNhap phep tinh phan so can thuc hien: ";
		cin >> ps.A.tuso >> temp >> ps.A.mauso >> ps.pheptinh >> ps.B.tuso >> temp >> ps.B.mauso;
		if(ps.A.mauso == 0 || ps.B.mauso == 0)
			cout << "\nMau so nhap vao phai khac 0. Xin kiem tra lai.\n";
	}while((ps.A.mauso == 0) || (ps.B.mauso == 0));
}

int UCLN(int a, int b) // ham tim uoc chung lon nhat (ho tro rut gon phan so)
{
	if(a == 0)
		return b;
	return UCLN(b % a, a);
}

void rutGonPhanSo(PhanSo &x) // ham rut gon phan so
{
	int ucln = UCLN(x.tuso, x.mauso);
	x.tuso = x.tuso / ucln;
	x.mauso = x.mauso / ucln;
}

void TinhToan(PHANSO ps) // ham tinh toan cong, tru, nhan, chia 2 phan so
{
	PhanSo kq; // khai bao phan so ket qua
	switch(ps.pheptinh)
	{
		case '+':{
			if(ps.A.mauso == ps.B.mauso)
			{
				kq.tuso = ps.A.tuso + ps.B.tuso;
				kq.mauso = ps.A.mauso;
			}
			else
			{	
				kq.tuso = ps.A.tuso * ps.B.mauso + ps.B.tuso * ps.A.mauso;
				kq.mauso = ps.A.mauso * ps.B.mauso;
			}
			rutGonPhanSo(kq);
			cout << "Ket qua la: " << kq.tuso << "/" << kq.mauso;
			break;
		}
		case '-':{
			if(ps.A.mauso == ps.B.mauso)
			{
				kq.tuso = ps.A.tuso - ps.B.tuso;
				kq.mauso = ps.A.mauso;
			}
			else
			{	
				kq.tuso = ps.A.tuso * ps.B.mauso - ps.B.tuso * ps.A.mauso;
				kq.mauso = ps.A.mauso * ps.B.mauso;
			}
			rutGonPhanSo(kq);
			cout << "Ket qua la: " << kq.tuso << "/" << kq.mauso;
			break;
		}
		case '*':{
			kq.tuso = ps.A.tuso * ps.B.tuso;
			kq.mauso = ps.A.mauso * ps.B.mauso;
			
			rutGonPhanSo(kq);
			cout << "Ket qua la: " << kq.tuso << "/" << kq.mauso;
			break;
		}
		case '/':{
			kq.tuso = ps.A.tuso * ps.B.mauso;
			kq.mauso = ps.A.mauso * ps.B.tuso;
			cout << "Ket qua la: " << kq.tuso << "/" << kq.mauso;
			
			rutGonPhanSo(kq);
			break;
		}
		default:{
			cout << "\nPhep tinh khong hop le. Xin kiem tra lai!";
			break;
		}
	}
}

void lapTinhToan() // ham lap lai tinh toan khac
{
	PHANSO ps;
	char lapLai;
	do{
		nhap(ps);
		TinhToan(ps);
		cout << "\nDo another (y/n)? ";
		cin >> lapLai;
	}while(lapLai == 'y');
}
int main()
{
	lapTinhToan();
	
	return 0;
}
