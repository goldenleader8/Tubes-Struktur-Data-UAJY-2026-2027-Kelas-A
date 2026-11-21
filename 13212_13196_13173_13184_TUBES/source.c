#include "header.h"
//=============================================================================================================
//                                           SALES
//=============================================================================================================
int isEmpty(addrParrent Sales){
    return (Sales == NULL) ? 1 : 0;
}

void createEmpty(addrParrent *Sales){
    *Sales = NULL;
}

addrParrent allocateSales(dataParrent dataSales){
    addrParrent newAddress = (addrParrent)malloc(sizeof(NodeParrent));

    newAddress->dataSales = dataSales;
    newAddress->nextAdr = NULL;
    newAddress->firstChild = NULL;
    return newAddress;
}

addrParrent findParrent(addrParrent L, int NIP){
    if(isEmpty){
        return NULL;
    }

    if(L->dataSales.NIP == NIP){
        return L;
    }

    return findParrent(L->nextAdr, NIP);
}

void insertFirstParrent(addrParrent *L, addrParrent new){
     new->nextAdr = *L;
     *L = new;
}


void insertAfterParrent(addrParrent prevAddress, addrParrent newAddress){
    if(isEmpty(prevAddress)){
        return;
    }
    newAddress->nextAdr = prevAddress->nextAdr;
    prevAddress->nextAdr = newAddress;
}

void deleteFirstParrent(addrParrent *L){
    if(isEmpty(*L)){
        printf("\n[!] Belum ada Sales");
        return;
    }
    addrParrent temp = *L;
    *L = (*L)->nextAdr;
    free(temp);
}

void deleteAtParrent(addrParrent *L, addrParrent delNode){
    if(isEmpty(*L)){
        printf("\n[!] Belum ada Sales");
        return;
    }
    if(*L == delNode){
        deleteFirstParrent(L);
        return;
    }
    deleteAt(&(*L)->nextAdr, delNode);
}

void updateDataParrent(addrParrent *L, addrParrent updNode){
    if(isEmpty(*L)){
        printf("\n[!] Belum ada Sales");
        return;
    }

    if(updNode == NULL){
        return;
    }
    
    printf("\nNIP Baru : "); scanf("%d", &updNode->dataSales.NIP);
    printf("Nama Baru  : "); fflush(stdin); gets(updNode->dataSales.nama);
    printf("Nomor Baru : "); scanf("%d", &updNode->dataSales.nomorTelepon);
}

addrParrent findNodeParrent(addrParrent L, int NIP){
    if(isEmpty(L)){
        return NULL;
    }
    if(L->dataSales.NIP == NIP){
        return L;
    }

    return findNodeParrent(L->nextAdr, NIP);
}