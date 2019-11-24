#include <iostream>
#include <stdlib.h>

using namespace std;

string pilihan[3] = { "Paket", "Makanan", "Minuman" };
string paket[9] = { "1 jam", "2 jam", "3 jam", "4 jam", "5 jam", "7 jam", "10 jam", "12 jam", "24 jam" };
int harga_paket[9] = { 5000,10000,15000,18000,20000,24000,30000,35000,70000 };
string makanan[5] = { "Indomie Goreng", "2 Indomie Goreng", "Indomie Goreng + telor", "2 Indomie Goreng + telor", "Nasi Goreng" };
int harga_makanan[5] = { 5000, 10000, 8000, 13000, 15000 };
string minuman[3] = {"Es Teh Manis", "Jus Jeruk", "Krating Daeng"};
int harga_minuman[3] = { 3000,5000,9000 };
char lagi;
int pilih_menu, pilih_paket, pilih_makanan, pilih_minuman, uang;
string nama;

int bayar(int uang, int total)
{
	int result = uang - total;
	return result;
}

void struk(string nama, string pesanan, int total, int uang)
{
	int kembalian = bayar(uang, total);
	if (kembalian < 0)
	{
		cout << "Maaf, Uang anda kurang.." << endl;
		cout << "=============================================" << endl;
		cout << "=============================================" << endl;
		cout << "Pesan Lagi ? (Y/N) :"; cin >> lagi;
	}
	else
	{
		cout << "Pesanan   : " << pesanan << endl;
		cout << "Atas Nama : " << nama << endl;
		cout << "Harga\t  :\t\t\t" << total << endl;
		cout << "Uang \t  :\t\t\t" << uang << endl;
		cout << "_________________________________________-" << endl;
		cout << "\t\t\t\t" << kembalian << endl;
		cout << "=============================================" << endl;
		cout << "=============================================" << endl;
		cout << "Pesan Lagi ? (Y/N) :"; cin >> lagi;
	}
}

void pilihan2(string pesanan, int harga_pesanan)
{
	string pesan = pesanan;
	int harga = harga_pesanan;
	cout << "Anda memesan " << pilihan[pilih_menu - 1] << " : " << pesan << " Seharga Rp " << harga << endl;
	cout << "Masukan Uang anda : "; cin >> uang;
	cout << "Atas Nama : "; cin >> nama;
	cout << "=============================================" << endl << endl;
	struk(nama, pesan, harga, uang);
}



void daftar()
{
	cout << "Apa yang akan anda Pesan ?" << endl;
	for (int x = 0; x < 3; x++)
	{
		cout << x + 1 << ". " << pilihan[x] << endl;
	}
	cout << "=============================================" << endl;
	cout << "Pilihan : "; cin >> pilih_menu;
}

void daftar_paket()
{
	for (int x = 0; x < 9; x++)
	{
		cout << x + 1 << ". " << paket[x] << endl;
	}
	cout << "Silahkan pilih paket : "; cin >> pilih_paket;
	pilihan2(paket[pilih_paket - 1], harga_paket[pilih_paket - 1]);
}

void daftar_makanan()
{
	for (int x = 0; x < 5; x++)
	{
		cout << x + 1 << ". " << makanan[x] << endl;
	}
	cout << "Silahkan pilih makanan : "; cin >> pilih_makanan;
	pilihan2(makanan[pilih_makanan - 1], harga_makanan[pilih_makanan - 1]);
}

void daftar_minuman()
{
	for (int x = 0; x < 3; x++)
	{
		cout << x + 1 << ". " << minuman[x] << endl;
	}
	cout << "Silahkan pilih minuman : "; cin >> pilih_minuman;
	pilihan2(minuman[pilih_minuman - 1], harga_minuman[pilih_minuman - 1]);
}

void pilihan1(int p)
{
	switch (p)
	{
	case 1:
		daftar_paket();
		break;
	case 2:
		daftar_makanan();
		break;
	case 3:
		daftar_minuman();
		break;
	default:
		cout << "Maaf pilihan anda tidak ada.." << endl;
		break;
	}
}

int main()
{
	do
	{	
		system("cls");
		cout << "================ I-Cafe Menu ================" << endl;
		cout << "=============================================" << endl;
		daftar();
		pilihan1(pilih_menu);
	} while ( lagi == 'y' || lagi == 'Y' );
	cout << "=============================================" << endl;
	cout << "=============================================" << endl;
}