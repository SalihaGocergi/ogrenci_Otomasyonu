#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>


typedef struct Ders
{
    int dersKodu;
    char dersAdi[50];
    int dersKredisi;
}dersler;

typedef struct Ogrenci
{
    int OgrenciNo;
    char OgrenciAd[50];
    char OgrenciSoyad[50];
    int dersSayisi;
    dersler *Dersler;
}ogrenci;

void OgrenciAdArama(ogrenci *Ogr,int ogrSayisi,int dSayisi)
{
    int i,j,cntrl;
    char arananIsim[20];

    printf("Aramak istediginiz Ogrencinin Adini Giriniz: ");
    scanf("%s",arananIsim);
    printf("------------------------------------------------------\n");

    for(i=0;i<ogrSayisi;i++)
    {
            cntrl=strcmp(arananIsim,(Ogr+i)->OgrenciAd);
            if(cntrl==0)
            {
                printf(" Ogrenci No:%d\n Ogrenci Adi:%s\n Ogrenci Soyadi:%s\n",(Ogr+i)->OgrenciNo,(Ogr+i)->OgrenciAd,(Ogr+i)->OgrenciSoyad);
                printf("-->Ogrencinin Ders Bilgisi\n");
                for(j=0;j<dSayisi;j++)
                {

                printf("Dersin Kodu:%d  Adi:%s  Kredisi:%d\n",((Ogr+i)->Dersler+j)->dersKodu,((Ogr+i)->Dersler+j)->dersAdi,((Ogr+i)->Dersler+j)->dersKredisi);
                }
                printf("------------------------------------------------------\n");
            }
    }
}
void OgrenciSoyadArama(ogrenci *Ogr,int ogrSayisi,int dSayisi)
{
    int i,j,cntrl1;
    char arananSoyad[20];
    printf("Aramak istediginiz Ogrencinin Soyadini giriniz:");
    scanf("%s",arananSoyad);
    printf("------------------------------------------------------\n");

    for(i=0;i<ogrSayisi;i++)
    {
        cntrl1=strcmp(arananSoyad,(Ogr+i)->OgrenciSoyad);
        if(cntrl1==0)
        {
            printf(" Ogrenci No:%d\n Ogrenci Adi:%s\n Ogrenci Soyadi:%s\n",(Ogr+i)->OgrenciNo,(Ogr+i)->OgrenciAd,(Ogr+i)->OgrenciSoyad);
            printf("-->Ogrencinin Ders Bilgisi\n");
            for(j=0; j<dSayisi; j++)
            {
             printf("Dersin Kodu:%d  Adi:%s  Kredisi:%d\n",((Ogr+i)->Dersler+j)->dersKodu,((Ogr+i)->Dersler+j)->dersAdi,((Ogr+i)->Dersler+j)->dersKredisi);
            }
            printf("------------------------------------------------------\n");
        }

    }
}

void DersKodArama(ogrenci *Ogr,int ogrSayisi,int dSayisi)
{
    int i,j,cntrl2,arananKod[20];
    printf("Aramak istediginiz Ogrencinin Aldigi Dersin Kodu: ");
    scanf("%d",&arananKod);

    for(i=0;i<ogrSayisi;i++)
    {
        for(j=0;j<dSayisi;j++)
        {
            if((((Ogr+i)->Dersler+j)->dersKodu) == arananKod)
            {
               printf(" Ogrenci No:%d\n Ogrenci Adi:%s\n Ogrenci Soyadi:%s\n",(Ogr+i)->OgrenciNo,(Ogr+i)->OgrenciAd,(Ogr+i)->OgrenciSoyad);
            }
        }
    }
}

void OgrenciEkleme(ogrenci *Ogr,int ogrSayisi)
{
    int i,j,dSayisi;
                    Ogr =(ogrenci*)malloc(ogrSayisi*sizeof(ogrenci));
                    for(i=0;i<ogrSayisi;i++)
                        {
                            printf("+++++++++++++++++++++++++++++\n");
                            printf("%d. Ogrencinin Numarasi:",i+1);
                            scanf("%d",&(Ogr+i)->OgrenciNo);
                            printf("%d. Ogrencinin Adi:",i+1);
                            scanf("%s",(Ogr+i)->OgrenciAd);
                            printf("%d. Ogrencinin Soyadi:",i+1);
                            scanf("%s",(Ogr+i)->OgrenciSoyad);
                            printf("%d. Ogrenci icin kac adet ders girilecek: ",i+1);
                            scanf("%d", &dSayisi);


                            (Ogr+i)-> dersSayisi=dSayisi;
                            (Ogr+i)->Dersler=(dersler*)malloc(dSayisi*sizeof(dersler));

                            for(j=0;j<dSayisi;j++)
                            {
                                printf("\n");
                                printf("%d. Ogrencinin %d. Dersin Kodu: ",i+1,j+1);
                                scanf("%d",&((Ogr+i)->Dersler+j)->dersKodu);
                                printf("%d. Ogrencinin %d. Dersin Adi: ",i+1,j+1);
                                scanf("%s",((Ogr+i)->Dersler+j)->dersAdi);
                                printf("%d. Ogrencinin %d. Dersin Kredisi: ",i+1,j+1);
                                scanf("%d",&((Ogr+i)->Dersler+j)->dersKredisi);
                            }

                            printf("%d. Ogrenciye ait Isleminiz Bitmistir.",i+1);
                    printf("\n");
                        }
                        main(Ogr,ogrSayisi,dSayisi);
}

int main(ogrenci *Ogr,int ogrSayisi,int dSayisi)
{

    //ogrenci *Ogr;
    int secim=1;

    while(secim !=5)
    {
        printf("\t\t++++++++OGRENCI OTOMASYONU++++++++\n");
        printf("\t+++++++++++++++++++++++++++++\n");
        printf("\tOgrenci Eklemek Icin--> 1\n");
        printf("\tDers Koduna Gore Arama--> 2\n");
        printf("\tOgrenci Adina Gore Arama--> 3\n");
        printf("\tOgrenci Soyadina Gore Arama--> 4\n");
        printf("\tProgrami Sonlandirmak Icin--> 5\n");
        printf("\t+++++++++++++++++++++++++++++\n");
        printf("Seciminiz:");
        scanf("%d", &secim);

        switch(secim)
        {
        case 1:
                    printf("\nKac adet ogrenci girmek istiyorsunuz: ");
                    scanf("%d",&ogrSayisi);
                    OgrenciEkleme(Ogr,ogrSayisi);

        break;
        case 2:
            printf("%d",dSayisi);
            DersKodArama(Ogr,ogrSayisi,dSayisi);
        break;
        case 3:
            OgrenciAdArama(Ogr,ogrSayisi,dSayisi);
        break;
        case 4:
            OgrenciSoyadArama(Ogr,ogrSayisi,dSayisi);
        break;
        case 5:
            exit(1);
        break;
        default:
                printf("Yanlis secim. [1],[2],[3],[4] veya [5] numaralarini seciniz.");
        }


    }



    return 0;
}
