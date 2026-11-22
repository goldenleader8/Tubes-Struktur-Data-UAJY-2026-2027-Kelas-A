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
		return true;
	}
	else if(first!=Target){
		if(strcmp(first->DataParent.telepon, telepon)==0){
			return false;
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





