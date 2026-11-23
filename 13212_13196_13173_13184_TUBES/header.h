#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>


// Tipe Data
typedef char string[128];

typedef struct tChild* addrChild;
typedef struct tParent* addrParent;
typedef struct{
	int nomor;
	string jenis;
	string alamat;
	double harga;
}dataChild;
typedef struct {
	string NIP;
	string nama;
	string telepon;
	double totalPenjualan;
}dataParent;
typedef struct tChild{
	dataChild DataChild;
	addrChild nextChild;
}Child;

typedef struct tParent{
	dataParent DataParent;
	addrParent nextParent;
	addrChild firstChild;
}Parent;

//Fungsi Pembantu

	//Parent
void inisialisasi(addrParent *first);
bool isEmpty(addrParent first);
bool haveChild(addrParent P);
addrParent alokasiParent(dataParent DataParent);
addrParent findParent(addrParent first, string NIP);
bool isParentValid(addrParent first, dataParent DataParent);
int countParent(addrParent first);
int countChild(addrChild C);
bool isTeleponUsed(addrParent first,addrParent Target, string telepon);
void relokasiChild(addrParent Asal, addrParent Tujuan, addrParent first);
bool isAllAngka(string str, int index);
	//Child
addrChild alokasiChild(dataChild DataChild);
addrChild findChild(addrChild C, int nomor);
int countChildByJenis(addrParent first, string jenis);
int countChildByJenisPerParent(addrChild C, string jenis);
bool isJenisValid(string jenis);
addrChild findLastChild(addrChild C);
//Fungsi Create

	//Parent
void insertLastParent(addrParent *first, dataParent DataParent);
	//Child
void insertLastChild(addrChild *C, dataChild DataChild);
	
//Fungsi Read
void printNamaSales(addrParent first, int index);
void printChildByJenis(addrChild C, string jenis, int index);
void printDetailParent(addrParent P);
void printDetailChild(addrChild C);
void printAllParent(addrParent first);
void printAllChild(addrChild firstChild);

//Fungsi Update
void updateParent(addrParent P, string nama, string telepon);
void updateChild(addrChild C, string jenis, string alamat, double harga);

//Fungsi Delete

void deleteAtChild(addrChild *C, addrParent P, int nomor);
void deleteAtParent(addrParent *search, addrParent first, string NIP);
void deleteAllChild(addrChild *C, addrParent P);
void deleteAllParent(addrParent *first);








