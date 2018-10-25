#include<iostream>
using namespace std;

struct toan
{
	int a; // toan hang a
	int b; // toan hang b
	char pheptinh; // toan tu pheptinh
};
typedef struct toan TOAN;

void nhap(TOAN &t)
{
	cout << "Nhap phep toan can tinh: ";
	cin >> t.a >> t.pheptinh >> t.b;
}

double tinhToan(TOAN t)
{
	t.pheptinh;
	switch(t.pheptinh)
	{
		case '+':{
			return t.a + t.b;
			break;
		}
		case '-':{
			return t.a - t.b;
			break;
		}
		case '*':{
			return t.a * t.b;
			break;
		}
		case '/':{
			if(t.b != 0)
			{
				return (float)t.a / t.b;
				break;
			}
			else
				cout << "b phai khac 0\n";
			
		}
		default:{
			cout << "Phep tinh nhap sai! Xin nhap lai.";
			break;
		}
	}
}

void lapPhepTinhKhac()
{
	char x;
	TOAN t;
	
	do{
		nhap(t); // goi ham nhap lai phep toan
		cout << tinhToan(t);
		cout << "\nBan co muon thuc hien phep tinh khac khong (y/n)? ";
		cin >> x;
	}while(x == 'y');
}

int main()
{
	lapPhepTinhKhac();
	
	return 0;
}
