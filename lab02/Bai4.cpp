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
	cout << "\nNhap phep tinh phan so can thuc hien: ";
	cin >> ps.A.tuso >> temp >> ps.A.mauso >> ps.pheptinh >> ps.B.tuso >> temp >> ps.B.mauso;
}

void TinhToan(PHANSO ps) // ham tinh toan cong, tru, nhan, chia 2 phan so
{
	PhanSo kq; // khai bao phan so ket qua
	switch(ps.pheptinh)
	{
		case '+':{
			kq.tuso = ps.A.tuso * ps.B.mauso + ps.B.tuso * ps.A.mauso;
			kq.mauso = ps.A.mauso * ps.B.mauso;
			cout << "Ket qua la: " << kq.tuso << "/" << kq.mauso;
			break;
		}
		case '-':{
			kq.tuso = ps.A.tuso * ps.B.mauso - ps.B.tuso * ps.A.mauso;
			kq.mauso = ps.A.mauso * ps.B.mauso;
			cout << "Ket qua la: " << kq.tuso << "/" << kq.mauso;
			break;
		}
		case '*':{
			kq.tuso = ps.A.tuso * ps.B.tuso;
			kq.mauso = ps.A.mauso * ps.B.mauso;
			cout << "Ket qua la: " << kq.tuso << "/" << kq.mauso;
			break;
		}
		case '/':{
			kq.tuso = ps.A.tuso * ps.B.mauso;
			kq.mauso = ps.A.mauso * ps.B.tuso;
			cout << "Ket qua la: " << kq.tuso << "/" << kq.mauso;
			break;
		}
		default:{
			cout << "\nPhep tinh nhap vao khong hop le. Xin kiem tra lai!";
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
