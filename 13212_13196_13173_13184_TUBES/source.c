#include "header.h"

//Fungsi Pembantu

	//Parent
void inisialisasi(addrParent *first){
	*first=NULL;
}

bool isEmpty(addrParent first){
	return first==NULL;
}

bool haveChild(addrParent P){
	return P!=NULL && P->firstChild!=NULL;
}

addrParent alokasiParent(dataParent DataParent){
	addrParent P;
	P=(addrParent)malloc(sizeof(Parent));
	P->DataParent=DataParent;
	P->firstChild=NULL;
	P->nextParent=NULL;
	return P;
}

addrParent findParent(addrParent first, string NIP){
	if(isEmpty(first)){
		return NULL;
	}
	else if(strcmp(first->DataParent.NIP, NIP)==0){
		return first;
	}
	else{
		return findParent(first->nextParent, NIP);
	}
}

bool isParentValid(addrParent first, dataParent DataParent){
	if(first==NULL){
		return true;
	}
	else if(strcmp(first->DataParent.NIP, DataParent.NIP)==0 || strcmp(first->DataParent.telepon, DataParent.telepon)==0){
		return false;
	}
	else{
		return isParentValid(first->nextParent, DataParent);
	}
}
int countParent(addrParent first){
	if(first==NULL){
		return 0;
	}
	else{
		return 1 + countParent(first->nextParent);
	}
}
int countChild(addrChild C){
	if(C==NULL){
		return 0;
	}
	else{
		return 1 + countChild(C->nextChild);
	}
}

bool isTeleponUsed(addrParent first, addrParent Target, string telepon){
	if(first==NULL){
		return false;
	}
	else if(first!=Target){
		if(strcmp(first->DataParent.telepon, telepon)==0){
			return true;
		}
		else{
			return isTeleponUsed(first->nextParent, Target, telepon);
		}
	}
	else{
		return isTeleponUsed(first->nextParent,Target, telepon);
	}
}

void relokasiChild(addrParent Asal, addrParent Tujuan, addrParent first){
	if(!haveChild(Asal) || first->nextParent == NULL){
		return;
	}
	else if(Tujuan==NULL){
		relokasiChild(Asal, first, first);
		return;
	}
	else if(Asal==Tujuan){
		relokasiChild(Asal, Tujuan->nextParent, first);
		return;
	}
	addrChild Pindah=Asal->firstChild;
	Asal->firstChild=Pindah->nextChild;
	Pindah->nextChild=NULL;
	
	if(!haveChild(Tujuan)){
		Tujuan->firstChild=Pindah;
	}
	else{
		addrChild C= findLastChild(Tujuan->firstChild);
		C->nextChild=Pindah;
	}
	relokasiChild(Asal, Tujuan->nextParent, first);
}

bool isAllAngka(string str, int index){
	if(str == NULL || str[0] == '\0'){
		return false;
	}
	if(str[index] == '\0'){
		return true;
	}
	if(str[index] < '0' || str[index] > '9'){
		return false;
	}
	return isAllAngka(str, index+1);
}

	//Child
addrChild alokasiChild(dataChild DataChild){
	addrChild C;
	C=(addrChild)malloc(sizeof(Child));
	C->DataChild=DataChild;
	C->nextChild=NULL;
	return C;
}
addrChild findChild(addrChild C, int nomor){
	if(C==NULL){
		return NULL;
	}
	else if(C->DataChild.nomor==nomor){
		return C;
	}
	else{
		return findChild(C->nextChild, nomor);
	}
}

int countChildByJenis(addrParent first, string jenis){
	if(first==NULL){
		return 0;
	}
	return countChildByJenis(first->nextParent, jenis) + countChildByJenisPerParent(first->firstChild, jenis);
}

int countChildByJenisPerParent(addrChild C, string jenis){
	if(C==NULL){
		return 0;
	}
	else if(strcmpi(C->DataChild.jenis, jenis)==0){
		return 1+countChildByJenisPerParent(C->nextChild, jenis);
	}
	else{
		return 0+countChildByJenisPerParent(C->nextChild, jenis);
	}
}
bool isJenisValid(string jenis){
	return (strcmpi(jenis, "tanah")== 0 || strcmpi(jenis, "rumah")== 0);
}

addrChild findLastChild(addrChild C){
	if(C->nextChild==NULL){
		return C;
	}
	else{
		return findLastChild(C->nextChild);
	}
}

//Fungsi Create

	//Parent
void insertLastParent(addrParent *first, dataParent DataParent){
	if(*first==NULL){
		*first=alokasiParent(DataParent);
	}
	else{
		insertLastParent(&(*first)->nextParent, DataParent);
	}
}
	//Child
void insertLastChild(addrChild *C, dataChild DataChild){
	if(*C==NULL){
		*C=alokasiChild(DataChild);
	}
	else{
		insertLastChild(&(*C)->nextChild, DataChild);
	}
}
//Fungsi Read
void printNamaSales(addrParent first, int index){
	if(first==NULL){
		return;
	}
	else{
		printf("%d. %s\n", index, first->DataParent.nama);
		printNamaSales(first->nextParent, index+1);
	}
}

void printChildByJenis(addrChild C, string jenis, int index){
	if(C==NULL){
		return;
	}
	else if(strcmpi(C->DataChild.jenis, jenis)==0){
		printf("%d. nomor: %d || alamat: %s || Harga: %lf\n",index, C->DataChild.nomor, C->DataChild.alamat, C->DataChild.harga);
		printChildByJenis(C->nextChild, jenis, index+1);
	}
	else{
		printChildByJenis(C->nextChild, jenis, index);
	}
}

void printDetailParent(addrParent P){
	printf("NIP: %s\n",P->DataParent.NIP);
	printf("Nama: %s\n",P->DataParent.nama);
	printf("Nomor telepon: %s\n",P->DataParent.telepon);
	printf("Total penjualan: %lf\n",P->DataParent.totalPenjualan);
}

void printDetailChild(addrChild C){
	printf("Nomor: %d\n",C->DataChild.nomor);
	printf("Jenis: %s\n",C->DataChild.jenis);
	printf("Alamat: %s\n",C->DataChild.alamat);
	printf("Harga: %lf\n",C->DataChild.harga);
}

void printAllParent(addrParent first){
	if(first==NULL){
		return;
	}
	printDetailParent(first);
	printAllChild(first->firstChild);
	printAllParent(first->nextParent);
}

void printAllChild(addrChild firstChild){
	if(firstChild==NULL){
		return;
	}
	else{
		printDetailChild(firstChild);
		printAllChild(firstChild->nextChild);
	}
}

//Fungsi Update
void updateParent(addrParent P, string nama, string telepon){
	if(P!=NULL){
		strcpy(P->DataParent.nama, nama);
		strcpy(P->DataParent.telepon, telepon);
	}
}

void updateChild(addrChild C, string jenis, string alamat, double harga){
	if(C!=NULL){
		strcpy(C->DataChild.alamat , alamat);
		strcpy(C->DataChild.jenis ,jenis);
		C->DataChild.harga=harga;
	}
}


//Fungsi Delete
void deleteAtChild(addrChild *C, addrParent P, int nomor){
	if(*C==NULL){
		return;
	}
	else if((*C)->DataChild.nomor==nomor){
		addrChild temp =*C;
		*C=temp->nextChild;
		P->DataParent.totalPenjualan+=temp->DataChild.harga;
		free(temp);
	}
	else{
		deleteAtChild(&(*C)->nextChild, P, nomor);
	}
}

void deleteAtParent(addrParent *search, addrParent first, string NIP){
	if(*search==NULL){
		return;
	}
	else if(strcmp((*search)->DataParent.NIP, NIP)==0){
		relokasiChild(*search, first, first);
		deleteAllChild(&(*search)->firstChild, *search);
		addrParent temp =*search;
		*search=temp->nextParent;
		free(temp);
	}
	else{
		deleteAtParent(&(*search)->nextParent, first, NIP);
	}
}

void deleteAllChild(addrChild *C, addrParent P){
	if(*C==NULL){
		return;
	}
	else{
		deleteAtChild(C, P, (*C)->DataChild.nomor);
		deleteAllChild(C, P);
	}
}
void deleteAllParent(addrParent *first){
	if(isEmpty(*first)){
		return;
	}
	else{
		addrParent temp = *first;
        *first = temp->nextParent;
        deleteAllChild(&temp->firstChild, temp);
        free(temp);
        deleteAllParent(first);
	}
}

int mainMenu() {
	int selected = 1;
	int key;
	
	while (1) {
		CLEAR
		NEW_LEFT_MARGIN printf(BACK_WHITE"                                             "END);
		NEW_LEFT_MARGIN printf(BACK_WHITE"        Sistem Informasi RealEstateXYZ       "END);
		NEW_LEFT_MARGIN printf(BACK_WHITE"                PRO MAX 6000                 "END);
		NEW_LEFT_MARGIN printf(BACK_WHITE"                                             "END);
		NEW_LINE
		
		if (selected == 1) {
			NEW_LEFT_MARGIN printf(BACK_BRIGHT_BLACK"> Kontrak Sales Baru "END);
		} else {
			NEW_LEFT_MARGIN printf("  Kontrak Sales Baru ");
		}
		if (selected == 2) {
			NEW_LEFT_MARGIN printf(BACK_BRIGHT_BLACK"> Tambah Properti ke Sales "END);
		} else {
			NEW_LEFT_MARGIN printf("  Tambah Properti ke Sales ");
		}
		if (selected == 3) {
			NEW_LEFT_MARGIN printf(BACK_BRIGHT_BLACK"> Penjualan Properti "END);
		} else {
			NEW_LEFT_MARGIN printf("  Penjualan Properti ");
		}
		if (selected == 4) {
			NEW_LEFT_MARGIN printf(BACK_BRIGHT_BLACK"> Pengunduran Diri Sales "END);
		} else {
			NEW_LEFT_MARGIN printf("  Pengunduran Diri Sales ");
		}
		NEW_LINE
		if (selected == 5) {
			NEW_LEFT_MARGIN printf(BACK_BRIGHT_BLACK"> Daftar Nama Sales "END);
		} else {
			NEW_LEFT_MARGIN printf("  Daftar Nama Sales ");
		}
		if (selected == 6) {
			NEW_LEFT_MARGIN printf(BACK_BRIGHT_BLACK"> Properti Belum Terjual per Sales "END);
		} else {
			NEW_LEFT_MARGIN printf("  Properti Belum Terjual per Sales ");
		}
		if (selected == 7) {
			NEW_LEFT_MARGIN printf(BACK_BRIGHT_BLACK"> Jumlah Total Properti per Jenis "END);
		} else {
			NEW_LEFT_MARGIN printf("  Jumlah Total Properti per Jenis ");
		}
		NEW_LINE
		if (selected == 8) {
			NEW_LEFT_MARGIN printf(BACK_BRIGHT_BLACK"> Tampilan Seluruh Data "END);
		} else {
			NEW_LEFT_MARGIN printf("  Tampilan Seluruh Data ");
		}
		if (selected == 0) {
			NEW_LEFT_MARGIN printf(BACK_BRIGHT_BLACK"> Keluar "END);
		} else {
			NEW_LEFT_MARGIN printf("  Keluar ");
		}
		NEW_LINE
		key = getch();

		if (key == 224) { // kata google ini scan char arrow untuk windows 11, setelah 224 nanti difollow scan code per arrow
			key = getch();
			if (key == 72) { // panah atas
				if (selected == 1) selected = 0;
				else if (selected == 0) selected = 8;
				else selected--;
			} else if (key == 80) { // panas bawah
				if (selected == 8) selected = 0;
				else if (selected == 0) selected = 1;
				else selected++;
			}
		} else if (key == 13) { // enter
			return selected;
		}
	}
}



