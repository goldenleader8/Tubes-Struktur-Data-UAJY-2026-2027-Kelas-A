#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char string[100];

typedef struct tParrent *addrParrent;
typedef struct tChild *addrChild;

typedef struct{
    int NIP;
    int nomorTelepon;
    float totalPenjualan;
    string nama;
}dataParrent;

typedef struct tParrent{
    dataParrent dataSales;
    addrParrent nextAdr;
    addrChild firstChild;
}NodeParrent;

int isEmpty(addrParrent Sales);
void createEmpty(addrParrent *Sales);
addrParrent allocateSales(dataParrent dataSales);
addrParrent findParrent(addrParrent L, int NIP);
void insertFirstParrent(addrParrent *L, addrParrent new);
void insertAfterParrent(addrParrent prevAddress, addrParrent newAddress);
void deleteFirstParrent(addrParrent *L);
void deleteAtParrent(addrParrent *L, addrParrent delNode);
void updateDataParrent(addrParrent *L, addrParrent updNode);
addrParrent findNodeParrent(addrParrent L, int NIP);