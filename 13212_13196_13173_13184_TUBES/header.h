#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
	// shortcut & organization
#define PAUSE system("pause");
#define CLEAR system("cls");
#define FLUSH fflush(stdin);
#define ERROR printf("\n\t[!] ");
#define SUC_ADD printf("\n\t[+] ");
#define SUC_RM printf("\n\t[-] ");
#define NEW_LEFT_MARGIN printf("\n\t");
#define NEW_LINE printf("\n");
#define LEFT_MARGIN printf("\t");
	// sigma color
#define END "\x1b[0m"
#define FORE_BLACK "\x1b[30m"
#define FORE_RED "\x1b[31m"
#define FORE_GREEN "\x1b[32m"
#define FORE_YELLOW "\x1b[33m"
#define FORE_BLUE "\x1b[34m"
#define FORE_MAGENTA "\x1b[35m"
#define FORE_CYAN "\x1b[36m"
#define FORE_WHITE "\x1b[37m"
#define FORE_BRIGHT_BLACK "\x1b[90m"
#define FORE_BRIGHT_RED "\x1b[91m"
#define FORE_BRIGHT_GREEN "\x1b[92m"
#define FORE_BRIGHT_YELLOW "\x1b[93m"
#define FORE_BRIGHT_BLUE "\x1b[94m"
#define FORE_BRIGHT_MAGENTA "\x1b[95m"
#define FORE_BRIGHT_CYAN "\x1b[96m"
#define FORE_BRIGHT_WHITE "\x1b[97m"
#define BACK_BLACK "\x1b[40m"
#define BACK_RED "\x1b[41m"
#define BACK_GREEN "\x1b[42m"
#define BACK_YELLOW "\x1b[43m"
#define BACK_BLUE "\x1b[44m"
#define BACK_MAGENTA "\x1b[45m"
#define BACK_CYAN "\x1b[46m"
#define BACK_WHITE "\x1b[47m"
#define BACK_BRIGHT_BLACK "\x1b[100m"
#define BACK_BRIGHT_RED "\x1b[101m"
#define BACK_BRIGHT_GREEN "\x1b[102m"
#define BACK_BRIGHT_YELLOW "\x1b[103m"
#define BACK_BRIGHT_BLUE "\x1b[104m"
#define BACK_BRIGHT_MAGENTA "\x1b[105m"
#define BACK_BRIGHT_CYAN "\x1b[106m"
#define BACK_BRIGHT_WHITE "\x1b[107m"

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

// Main
int mainMenu();
