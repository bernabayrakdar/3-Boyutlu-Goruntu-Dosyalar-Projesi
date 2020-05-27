#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <math.h>

struct Noktalar
{
    float x;
    float y;
    float z;

};

struct Renkli
{
    int r;
    int g;
    int b;

};

struct Binary
{
    float x;
    float y;
    float z;
};

int main()
{
    DIR *klasor=opendir("C:\\Users\\pc\\Desktop\\pro lab\\prolab1_1");
    struct dirent *dosyalar;

    char dosya2[200] = ".nkt";
    struct Binary veri;
    struct Noktalar nokta;
    struct Renkli renk;
    char data[100];
    char aciklama[100];
    char yer[100];
    char yer1[100];
    int yer_no;
    char alanlar[100];
    char noktalar1[100];
    char noktalar[100];
    char satir[100];
    char kontrol[100];
    char icerdeki_noktalar[100];
    char dosya_isimler[100][100];
    char isimler[100];
    char DataA[100] = "DATA ascii";
    char DataB[100] = "DATA binary";
    char RenkliDosya[100] = "ALANLAR x y z r g b";
    char RenksizDosya[100]= "ALANLAR x y z";
    int secim;
    char *arama;
    int nokta_sayisi;
    int index;
    int i =0,j=0,k=0,s=0,syc=0;
    int sayac=0;
    int hata_kontrol = 0;

    FILE *sonuc = fopen("output.nkt","w");
    if(sonuc == NULL)
    {
        printf("dosya acilamadi");
        exit(1);
    }
    fclose(sonuc);


    if(klasor==NULL)
    {
        printf("Klasor acilamadi \n");
    }
    if(klasor != NULL)
    {
        while((dosyalar = readdir(klasor)) != NULL)
        {
            strcpy(kontrol,dosyalar->d_name);

            arama=strstr(kontrol,".nkt");

            if(arama!=NULL)
            {

                strcpy(dosya_isimler[s],kontrol);
                //printf("%s\n",dosya_isimler[i]);
                s++;
            }
        }

        for(index=0; index<s; index++)
        {

            FILE *dosya = fopen(dosya_isimler[index],"r");

            fgets(aciklama,100,dosya);

            fgets(yer,100,dosya);

            fgets(alanlar,100,dosya);

            fgets(noktalar,100,dosya);

            fgets(data,100,dosya);


            if(strstr(data,DataA))
            {

                sscanf(noktalar,"%s %d",noktalar1,&nokta_sayisi);
                sscanf(yer,"%s %d",yer1,&yer_no);

                float Noktalar[nokta_sayisi][3];
                int Renkler[nokta_sayisi][3];



                if(strstr(alanlar,RenkliDosya))
                {

                    while(fgets(satir,100,dosya)!= NULL)
                    {

                        renk.g = -1;
                        renk.g = -1;
                        renk.b = -1;

                        sscanf(satir,"%f %f %f %d %d %d",&nokta.x,&nokta.y,&nokta.z,&renk.r,&renk.g,&renk.b);
                        //printf("%f %f %f %d %d %d\n",nokta.x,nokta.y,nokta.z,renk.r,renk.g,renk.b);

                        Noktalar[i][j] = nokta.x;
                        //printf("%f ",Noktalar[i][j]);
                        j++;
                        Noktalar[i][j] = nokta.y;
                        // printf("%f ",Noktalar[i][j]);
                        j++;
                        Noktalar[i][j] = nokta.z;
                        // printf("%f ",Noktalar[i][j]);
                        j=0;
                        Renkler[i][j] = renk.r;
                        //  printf("%d ",Renkler[i][j]);
                        j++;
                        Renkler[i][j] = renk.g;
                        // printf("%d ",Renkler[i][j]);
                        j++;
                        Renkler[i][j] = renk.b;
                        // printf("%d ",Renkler[i][j]);
                        // printf("\n");
                        sayac++;
                        j=0;
                        i++;

                    }

                }

                else if(strstr(alanlar,RenksizDosya))
                {
                    // printf("Renksiz dosya\n");

                    while(fgets(satir,100,dosya) != NULL)
                    {


                        sscanf(satir,"%f %f %f",&nokta.x,&nokta.y,&nokta.z); // noktalarý floata çevirdik.
                        //printf("%f %f %f\n",nokta.x,nokta.y,nokta.z);

                        Noktalar[i][j] = nokta.x;
                        //  printf("%f ",Noktalar[i][j]);
                        j++;
                        Noktalar[i][j] = nokta.y;
                        //  printf("%f ",Noktalar[i][j]);
                        j++;
                        Noktalar[i][j] = nokta.z;
                        // printf("%f ",Noktalar[i][j]);
                        //printf("\n");
                        sayac++;
                        j=0;
                        i++;
                    }
                }

                while(1)
                {
                    if(yer_no != 1)
                    {
                        hata_kontrol = -1;
                    }
                    if( sayac != nokta_sayisi )
                    {
                        hata_kontrol = -1;
                    }
                    for(i=0; i<nokta_sayisi; i++)
                    {

                        if(Renkler[i][0] == -1 || Renkler[i][1] == -1 || Renkler[i][2] == -1)
                        {
                            hata_kontrol = -1;
                        }
                    }

                    if (strstr(alanlar,"rg b") || strstr(alanlar,"rgb") || strstr(alanlar,"r gb") || strstr(alanlar,"ALANLAR r g b"))
                    {

                        hata_kontrol = -1;
                    }
                    if(strstr(alanlar,"xyz") || strstr(alanlar,"x yz") || strstr(alanlar,"xy z"))
                    {

                        hata_kontrol = -1;
                    }

                    printf("-------------------\n");
                    printf("\n\n1: DOSYA KONTROLU. \n");
                    printf("2: DOSYADAKI EN YAKIN VE EN UZAK NOKTALAR. \n");
                    printf("3: DOSYADAKI NOKTALARI KAPSAYAN EN KUCUK KUP. \n");
                    printf("4: GIRILEN KOORDINATLARA GORE DOSYADAKI NOKTALARI ICINE ALAN KURE. \n");
                    printf("5: DOSYADAKI NOKTALARIN BIRBIRLERINE OLAN UZAKLIKLARININ ORTALAMASI. \n");
                    printf("6: CIKIS. \n\n");
                    printf("-------------------\n");

                    printf("\n");
                    printf("secim:");

                    scanf("%d",&secim);
                    printf("\n");

                    if(secim == 6)
                    {
                        break;
                    }

                    switch(secim)
                    {
                    case 1:
                    {
                        FILE *sonuc = fopen("output.nkt","a");

                        if(syc == 0)
                        {
                            fprintf(sonuc,"%s\n",dosya_isimler[index]);
                            syc++;
                        }

                        fprintf(sonuc,"SECIM 1\n");

                        if(yer_no != 1)
                        {
                            printf("Dosya versiyonu hatali!\n");
                            fprintf(sonuc,"Dosya versiyonu hatali!\n");
                            hata_kontrol = -1;
                        }
                        if( sayac != nokta_sayisi )
                        {
                            printf("%s dosyasindaki nokta sayisi esit degil.\n",dosya_isimler[index]);
                            fprintf(sonuc,"%s dosyasindaki nokta sayisi esit degil.\n",dosya_isimler[index]);
                            hata_kontrol = -1;
                        }
                        for(i=0; i<nokta_sayisi; i++)
                        {

                            if(Renkler[i][0] == -1 || Renkler[i][1] == -1 || Renkler[i][2] == -1)
                            {
                                printf("%d. noktanin rgb bilgileri eksik girilmistir.\n",i+1);
                                fprintf(sonuc,"%d. noktanin rgb bilgileri eksik girilmistir.\n",i+1);
                                hata_kontrol = -1;
                            }
                        }

                        if (strstr(alanlar,"rg b") || strstr(alanlar,"rgb") || strstr(alanlar,"r gb") || strstr(alanlar,"ALANLAR r g b"))
                        {
                            printf("Alan bilgisi hatali\n");
                            fprintf(sonuc,"Alan bilgisi hatali\n");
                            hata_kontrol = -1;
                        }

                        if(strstr(alanlar,"xyz") || strstr(alanlar,"x yz") || strstr(alanlar,"xy z"))
                        {
                            printf("Alan bilgisi hatali\n");
                            fprintf(sonuc,"Alan bilgisi hatali\n");
                            hata_kontrol = -1;
                        }


                        if(hata_kontrol != 0)
                        {
                            printf("Hatali dosya\n");
                            fprintf(sonuc,"Hatali dosya\n");
                            goto git;
                        }

                        if(hata_kontrol == 0)
                        {
                            printf("Dosyada hata yok.\n");
                            fprintf(sonuc,"Dosyada hata yok.\n");
                        }


                        fclose(sonuc);
                    }
                    break;
                    case 2:
                    {
                        if(hata_kontrol != 0)
                        {
                            printf("Islem yapilamaz!!");
                            goto git;
                        }

                        FILE *sonuc = fopen("output.nkt","a");
                        if(sonuc == NULL)
                        {
                            exit(1);
                        }


                        float uzaklik;

                        float min = sqrt(pow((Noktalar[0][0]-Noktalar[1][0]),2)+pow((Noktalar[0][1]-Noktalar[1][1]),2)+pow((Noktalar[0][2]-Noktalar[1][2]),2));
                        float max = sqrt(pow((Noktalar[0][0]-Noktalar[1][0]),2)+pow((Noktalar[0][1]-Noktalar[1][1]),2)+pow((Noktalar[0][2]-Noktalar[1][2]),2));

                        int a,b,c,d;

                        for(i=0; i<nokta_sayisi; i++)
                        {
                            for(k=i+1; k<nokta_sayisi-i; k++)
                            {
                                uzaklik = sqrt((Noktalar[i][0]-Noktalar[k][0])*(Noktalar[i][0]-Noktalar[k][0])+(Noktalar[i][1]-Noktalar[k][1])*(Noktalar[i][1]-Noktalar[k][1])+(Noktalar[i][2]-Noktalar[k][2])*(Noktalar[i][2]-Noktalar[k][2]));

                                if(uzaklik < min)
                                {
                                    min = uzaklik;
                                    a=i;
                                    b=k;
                                }
                                if(uzaklik > max)
                                {
                                    max = uzaklik;
                                    c=i;
                                    d=k;
                                }
                            }
                        }


                        if(syc == 0)
                        {
                            fprintf(sonuc,"%s\n",dosya_isimler[index]);
                            syc++;
                        }


                        fprintf(sonuc,"SECIM 2\n");

                        if(strstr(alanlar,RenkliDosya))
                        {
                            printf("En yakin noktalar: %f %f %f %d %d %d ve %f %f %f %d %d %d",Noktalar[a][0],Noktalar[a][1],Noktalar[a][2],Renkler[a][0],Renkler[a][1],Renkler[a][2],Noktalar[b][0],Noktalar[b][1],Noktalar[b][2],Renkler[b][0],Renkler[b][1],Renkler[b][2]);
                            printf("\n");

                            printf("En uzak noktalar: %f %f %f %d %d %d ve %f %f %f %d %d %d",Noktalar[c][0],Noktalar[c][1],Noktalar[c][2],Renkler[c][0],Renkler[c][1],Renkler[c][2],Noktalar[d][0],Noktalar[d][1],Noktalar[d][2],Renkler[d][0],Renkler[d][1],Renkler[d][2]);
                            printf("\n");

                            fprintf(sonuc,"En yakin noktalar: %f %f %f %d %d %d ve %f %f %f %d %d %d\n",Noktalar[a][0],Noktalar[a][1],Noktalar[a][2],Renkler[a][0],Renkler[a][1],Renkler[a][2],Noktalar[b][0],Noktalar[b][1],Noktalar[b][2],Renkler[b][0],Renkler[b][1],Renkler[b][2]);
                            fprintf(sonuc,"En uzak noktalar: %f %f %f %d %d %d ve %f %f %f %d %d %d\n",Noktalar[c][0],Noktalar[c][1],Noktalar[c][2],Renkler[c][0],Renkler[c][1],Renkler[c][2],Noktalar[d][0],Noktalar[d][1],Noktalar[d][2],Renkler[d][0],Renkler[d][1],Renkler[d][2]);

                        }
                        else
                        {
                            printf("En yakin noktalar: %f %f %f ve %f %f %f",Noktalar[a][0],Noktalar[a][1],Noktalar[a][2],Noktalar[b][0],Noktalar[b][1],Noktalar[b][2]);
                            printf("\n");

                            printf("En uzak noktalar: %f %f %f ve %f %f %f",Noktalar[c][0],Noktalar[c][1],Noktalar[c][2],Noktalar[d][0],Noktalar[d][1],Noktalar[d][2]);
                            printf("\n");

                            fprintf(sonuc,"En yakin noktalar: %f %f %f ve %f %f %f\n",Noktalar[a][0],Noktalar[a][1],Noktalar[a][2],Noktalar[b][0],Noktalar[b][1],Noktalar[b][2]);
                            fprintf(sonuc,"En uzak noktalar: %f %f %f ve %f %f %f\n",Noktalar[c][0],Noktalar[c][1],Noktalar[c][2],Noktalar[d][0],Noktalar[d][1],Noktalar[d][2]);

                        }
                        fclose(sonuc);

                    }
                    break;
                    case 3:
                    {
                        if(hata_kontrol != 0)
                        {
                            printf("Islem yapilamaz!!");
                            goto git;
                        }

                        FILE *sonuc = fopen("output.nkt","a");

                        if(sonuc == NULL)
                        {
                            exit(1);
                        }

                        float maxx = fabs( Noktalar[0][0] - Noktalar[1][0]);
                        float maxy = fabs( Noktalar[0][1] - Noktalar[1][1]);
                        float maxz = fabs( Noktalar[0][2] - Noktalar[1][2]);
                        float kenar;

                        int a,c,d,b,e,f;

                        for(i=0; i<nokta_sayisi; i++)
                        {
                            for(k=i+1; k<nokta_sayisi; k++)
                            {
                                if(fabs(Noktalar[i][0]-Noktalar[k][0]) >= maxx)
                                {
                                    maxx = fabs(Noktalar[i][0]-Noktalar[k][0]);
                                    if(Noktalar[i][0] > Noktalar[k][0])
                                    {
                                        a=i;
                                        b=k;
                                    }
                                    else
                                    {
                                        a=k;
                                        b=i;
                                    }
                                }
                                else if(fabs(Noktalar[i][1]-Noktalar[k][1]) >= maxy)
                                {
                                    maxy = fabs(Noktalar[i][1]-Noktalar[k][1]);
                                    if(Noktalar[i][1] > Noktalar[k][1])
                                    {
                                        c=i;
                                        d=k;
                                    }
                                    else
                                    {
                                        c=k;
                                        d=i;
                                    }

                                }
                                else if(fabs(Noktalar[i][2]-Noktalar[k][2]) >= maxz)
                                {
                                    maxz = fabs(Noktalar[i][2]-Noktalar[k][2]);
                                    if(Noktalar[i][2] > Noktalar[k][2])
                                    {
                                        e=i;
                                        f=k;
                                    }
                                    else
                                    {
                                        e=k;
                                        f=i;
                                    }
                                }
                            }
                        }

                        float kose1,kose2,kose3,kose4,kose5;

                        if(maxx > maxy && maxx > maxz)
                        {
                            kenar = maxx;
                        }
                        if(maxy > maxx && maxy > maxz)
                        {
                            kenar = maxy;
                        }
                        if(maxz > maxy && maxz > maxx)
                        {
                            kenar = maxz;
                        }

                        kose1 = Noktalar[d][1] + kenar;
                        printf("Kose1: %f %f %f\n",Noktalar[b][0],kose1,Noktalar[f][2]);
                        kose2 = Noktalar[b][0] + kenar;
                        printf("Kose2: %f %f %f\n",kose2,Noktalar[d][1],Noktalar[f][2]);
                        kose3 = Noktalar[f][2];
                        printf("Kose3: %f %f %f\n",kose2,kose1,kose3);
                        printf("Kose4: %f %f %f\n",Noktalar[b][0],Noktalar[d][1],Noktalar[f][2]);
                        kose5 = Noktalar[f][2] + kenar;
                        printf("Kose5: %f %f %f\n",kose2,kose1,kose5);
                        printf("Kose6: %f %f %f\n",kose2,Noktalar[d][1],kose5);
                        printf("Kose7: %f %f %f\n",Noktalar[b][0],Noktalar[d][1],kose5);
                        printf("Kose8: %f %f %f\n",Noktalar[b][0],kose2,kose5);

                        if(syc == 0)
                        {
                            fprintf(sonuc,"%s\n",dosya_isimler[index]);
                            syc++;
                        }

                        fprintf(sonuc,"SECIM 3\n");
                        fprintf(sonuc,"Kose1: %f %f %f\n",Noktalar[b][0],kose1,Noktalar[f][2]);
                        fprintf(sonuc,"Kose2: %f %f %f\n",kose2,Noktalar[d][1],Noktalar[f][2]);
                        fprintf(sonuc,"Kose3: %f %f %f\n",kose2,kose1,kose3);
                        fprintf(sonuc,"Kose4: %f %f %f\n",Noktalar[b][0],Noktalar[d][1],Noktalar[f][2]);
                        fprintf(sonuc,"Kose5: %f %f %f\n",kose2,kose1,kose5);
                        fprintf(sonuc,"Kose6: %f %f %f\n",kose2,Noktalar[d][1],kose5);
                        fprintf(sonuc,"Kose7: %f %f %f\n",Noktalar[b][0],Noktalar[d][1],kose5);
                        fprintf(sonuc,"Kose8: %f %f %f\n",Noktalar[b][0],kose2,kose5);

                        fclose(sonuc);
                    }
                    break;
                    case 4:
                    {
                        if(hata_kontrol != 0)
                        {
                            printf("Islem yapilamaz!!");
                            goto git;
                        }

                        FILE *sonuc = fopen("output.nkt","a");
                        if(sonuc == NULL)
                        {
                            exit(1);
                        }

                        float x,y,z,yaricap;

                        printf("Merkez ve yaricap bilgileri giriniz:");
                        scanf("%f %f %f %f",&x,&y,&z,&yaricap);

                        if(syc == 0)
                        {
                            fprintf(sonuc,"%s\n",dosya_isimler[index]);
                            syc++;
                        }

                        fprintf(sonuc,"SECIM 4\n");

                        fprintf(sonuc,"%s",aciklama);
                        fprintf(sonuc,"%s",yer);
                        fprintf(sonuc,"%s",alanlar);
                        fprintf(sonuc,"%s",noktalar);
                        fprintf(sonuc,"%s",data);

                        if(strstr(alanlar,RenkliDosya))
                        {
                            for(i=0; i<nokta_sayisi; i++)
                            {
                                if(yaricap >= sqrt((Noktalar[i][0]-x)*(Noktalar[i][0]-x)+(Noktalar[i][1]-y)*(Noktalar[i][1]-y) + (Noktalar[i][2]-z)*(Noktalar[i][2]-z)))
                                {

                                    printf("%f %f %f %d %d %d\n",Noktalar[i][0],Noktalar[i][1],Noktalar[i][2],Renkler[i][0],Renkler[i][1],Renkler[i][2]);
                                    fprintf(sonuc,"%f %f %f %d %d %d\n",Noktalar[i][0],Noktalar[i][1],Noktalar[i][2],Renkler[i][0],Renkler[i][1],Renkler[i][2]);
                                }

                            }
                        }

                        else
                        {
                            for(i=0; i<nokta_sayisi; i++)
                            {
                                if(yaricap >= sqrt((Noktalar[i][0]-x)*(Noktalar[i][0]-x)+(Noktalar[i][1]-y)*(Noktalar[i][1]-y) + (Noktalar[i][2]-z)*(Noktalar[i][2]-z)))
                                {

                                    printf("%f %f %f\n",Noktalar[i][0],Noktalar[i][1],Noktalar[i][2]);
                                    fprintf(sonuc,"%f %f %f\n",Noktalar[i][0],Noktalar[i][1],Noktalar[i][2]);
                                }

                            }
                        }


                        fclose(sonuc);
                    }
                    break;
                    case 5:
                    {
                        if(hata_kontrol != 0)
                        {
                            printf("Islem yapilamaz!!");
                            goto git;
                        }

                        FILE *sonuc = fopen("output.nkt","a");
                        if(sonuc == NULL)
                        {
                            exit(1);
                        }

                        float uzaklik=0.0;
                        int bolum =0;
                        float ortalama = 0.0;
                        float toplam = 0.0;

                        for(i=0; i<nokta_sayisi; i++)
                        {
                            for(k=i+1; k<nokta_sayisi-i; k++)
                            {
                                uzaklik = sqrt((Noktalar[i][0]-Noktalar[k][0])*(Noktalar[i][0]-Noktalar[k][0])+(Noktalar[i][1]-Noktalar[k][1])*(Noktalar[i][1]-Noktalar[k][1])+(Noktalar[i][2]-Noktalar[k][2])*(Noktalar[i][2]-Noktalar[k][2]));
                                toplam += uzaklik;
                                bolum++;
                            }
                        }
                        ortalama = toplam / bolum;
                        printf("ortalama: %f\n",ortalama);

                        if(syc == 0)
                        {
                            fprintf(sonuc,"%s\n",dosya_isimler[index]);
                            syc++;
                        }

                        fprintf(sonuc,"SECIM 5\n");
                        fprintf(sonuc,"ortalama: %f\n",ortalama);
                        fclose(sonuc);

                    }
                    break;
                    default:
                        break;

                    }

                }

            }
git:
            hata_kontrol = 0;
            sayac=0;
            i=0;
            j=0;
            syc=0;

            fclose(dosya);

        }


        while((dosyalar = readdir(klasor)) != NULL)
        {
            strcpy(kontrol,dosyalar->d_name);

            arama=strstr(kontrol,".nkt");

            if(arama!=NULL)
            {

                strcpy(dosya_isimler[s],kontrol);
                //printf("%s\n",dosya_isimler[i]);
                s++;
            }
        }
        for(index=0; index<s; index++)
        {

            FILE *dosya =fopen(dosya_isimler[index],"rb");

            fgets(aciklama,100,dosya);

            fgets(yer,100,dosya);

            fgets(alanlar,100,dosya);

            fgets(noktalar,100,dosya);

            fgets(data,100,dosya);


            if(strstr(data,DataB))
            {

                sscanf(noktalar,"%s %d",noktalar1,&nokta_sayisi); // NOKTALAR 10000 STRING VE INT OLARAK AYIRIP NIKTA SAYISINI TUTTUK
                sscanf(yer,"%s %d",yer1,&yer_no);

                float binary_noktalar[nokta_sayisi][3];
                int binary_renkli[nokta_sayisi][3];

                if(strstr(alanlar,"ALANLAR x y z r g b"))
                {
                    printf("renkli dosya.\n");
                    while(!feof(dosya))
                    {
                        renk.g = -1;
                        renk.g = -1;
                        renk.b = -1;


                        while(fread(&veri,sizeof(struct Binary),1,dosya)== 1 && fread(&renk,sizeof(struct Renkli),1,dosya)== 1  )
                        {


                            // printf("X:%f Y:%f Z:%f R:%d G:%d B:%d\n",veri.x,veri.y,veri.z,renk.r,renk.g,renk.b);
                            binary_noktalar[i][j] = veri.x;
                           // printf("%f ",binary_noktalar[i][j]);
                            j++;
                            binary_noktalar[i][j] = veri.y;
                            //printf("%f ",binary_noktalar[i][j]);
                            j++;
                            binary_noktalar[i][j] = veri.z;
                            //printf("%f ",binary_noktalar[i][j]);
                            j=0;
                            binary_renkli[i][j] = renk.r;
                            //printf("%d ",binary_renkli[i][j]);
                            j++;
                            binary_renkli[i][j] = renk.g;
                            //printf("%d ",binary_renkli[i][j]);
                            j++;
                            binary_renkli[i][j] = renk.b;
                            //printf("%d ",binary_renkli[i][j]);
                            //printf("\n");
                            sayac++;
                            j=0;
                            i++;

                        }
                    }
                }

                else if (strstr(alanlar,"ALANLAR x y z"))
                {
                    while(fread(&veri,sizeof(struct Binary),1,dosya) == 1)
                    {

                        binary_noktalar[i][j] = veri.x;
                        //printf("%f ",binary_noktalar[i][j]);
                        j++;
                        binary_noktalar[i][j] = veri.y;
                        //printf("%f ",binary_noktalar[i][j]);
                        j++;
                        binary_noktalar[i][j] = veri.z;
                        //printf("%f ",binary_noktalar[i][j]);
                        //printf("\n");
                        sayac++;
                        j=0;
                        i++;

                    }

                }

                while(1)
                {

                    if(yer_no != 1)
                    {
                        hata_kontrol = -1;
                    }

                    if( sayac != nokta_sayisi )
                    {
                        hata_kontrol = -1;
                    }

                    for(i=0; i<nokta_sayisi; i++)
                    {

                        if(binary_renkli[i][0] == -1 || binary_renkli[i][1] == -1 || binary_renkli[i][2] == -1)
                        {
                            hata_kontrol = -1;
                        }
                    }

                    if (strstr(alanlar,"rg b") || strstr(alanlar,"rgb") || strstr(alanlar,"r gb") || strstr(alanlar,"ALANLAR r g b"))
                    {
                        hata_kontrol = -1;
                    }

                    if(strstr(alanlar,"xyz") || strstr(alanlar,"x yz") || strstr(alanlar,"xy z"))
                    {
                        hata_kontrol = -1;
                    }


                  printf("-------------------\n");
                    printf("\n\n1: DOSYA KONTROLU. \n");
                    printf("2: DOSYADAKI EN YAKIN VE EN UZAK NOKTALAR. \n");
                    printf("3: DOSYADAKI NOKTALARI KAPSAYAN EN KUCUK KUP. \n");
                    printf("4: GIRILEN KOORDINATLARA GORE DOSYADAKI NOKTALARI ICINE ALAN KURE. \n");
                    printf("5: DOSYADAKI NOKTALARIN BIRBIRLERINE OLAN UZAKLIKLARININ ORTALAMASI. \n");
                    printf("6: CIKIS. \n\n");
                    printf("-------------------\n");

                    printf("secim: ");

                    scanf("%d",&secim);
                    if(secim==6)
                    {
                        break;
                    }

                    switch(secim)
                    {
                    case 1:
                    {
                        FILE *sonuc = fopen("output.nkt","a");

                        if(syc == 0)
                        {
                            fprintf(sonuc,"%s\n",dosya_isimler[index]);
                            syc++;
                        }

                        if(yer_no != 1)
                        {
                            printf("Dosya versiyonu hatali!\n");
                            fprintf(sonuc,"Dosya versiyonu hatali!\n");
                            hata_kontrol = -1;
                        }

                        if( sayac != nokta_sayisi )
                        {
                            printf("%s dosyasindaki nokta sayisi esit degil.\n",dosya_isimler[index]);
                            fprintf(sonuc,"%s dosyasindaki nokta sayisi esit degil.\n",dosya_isimler[index]);
                            hata_kontrol = -1;

                        }

                        for(i=0; i<nokta_sayisi; i++)
                        {

                            if(binary_renkli[i][0] == -1 || binary_renkli[i][1] == -1 || binary_renkli[i][2] == -1)
                            {
                                printf("%d. noktanin rgb bilgileri eksik girilmistir.\n",i+1);
                                fprintf(sonuc,"%d. noktanin rgb bilgileri eksik girilmistir.\n",i+1);
                                hata_kontrol = -1;
                            }
                        }

                        if (strstr(alanlar,"rg b") || strstr(alanlar,"rgb") || strstr(alanlar,"r gb") || strstr(alanlar,"ALANLAR r g b"))
                        {
                            printf("Alan bilgisi hatali\n");
                            fprintf(sonuc,"Alan bilgisi hatali\n");
                            hata_kontrol = -1;
                        }

                        if(strstr(alanlar,"xyz") || strstr(alanlar,"x yz") || strstr(alanlar,"xy z"))
                        {
                            printf("Alan bilgisi hatali\n");
                            fprintf(sonuc,"Alan bilgisi hatali\n");
                            hata_kontrol = -1;
                        }

                        if(hata_kontrol != 0)
                        {
                            printf("Hatali dosya\n");
                            fprintf(sonuc,"Hatali dosya\n");
                            goto binary_git;
                        }

                        if(hata_kontrol == 0)
                        {
                            printf("dosyada hata yok.\n");
                            fprintf(sonuc,"dosyada hata yok.\n");
                        }


                        fclose(sonuc);
                    }
                    break;
                    case 2:
                    {
                        if(hata_kontrol != 0)
                        {
                            printf("Islem yapilamaz!!");
                            goto binary_git;
                        }

                        FILE *sonuc = fopen("output.nkt","a");
                        if(sonuc == NULL)
                        {
                            exit(1);
                        }


                        float uzaklik;

                        float min = sqrt(pow((binary_noktalar[0][0]-binary_noktalar[1][0]),2)+pow((binary_noktalar[0][1]-binary_noktalar[1][1]),2)+pow((binary_noktalar[0][2]-binary_noktalar[1][2]),2));
                        float max = sqrt(pow((binary_noktalar[0][0]-binary_noktalar[1][0]),2)+pow((binary_noktalar[0][1]-binary_noktalar[1][1]),2)+pow((binary_noktalar[0][2]-binary_noktalar[1][2]),2));

                        int a,b,c,d;

                        for(i=0; i<nokta_sayisi; i++)
                        {
                            for(k=i+1; k<nokta_sayisi-i; k++)
                            {
                                uzaklik = sqrt((binary_noktalar[i][0]-binary_noktalar[k][0])*(binary_noktalar[i][0]-binary_noktalar[k][0])+(binary_noktalar[i][1]-binary_noktalar[k][1])*(binary_noktalar[i][1]-binary_noktalar[k][1])+(binary_noktalar[i][2]-binary_noktalar[k][2])*(binary_noktalar[i][2]-binary_noktalar[k][2]));

                                if(uzaklik < min)
                                {
                                    min = uzaklik;
                                    a=i;
                                    b=k;
                                }
                                if(uzaklik > max)
                                {
                                    max = uzaklik;
                                    c=i;
                                    d=k;
                                }
                            }
                        }

                        if(syc == 0)
                        {
                            fprintf(sonuc,"%s\n",dosya_isimler[index]);
                            syc++;
                        }

                        fprintf(sonuc,"SECIM 2\n");

                        if(strstr(alanlar,RenkliDosya))
                        {
                            printf("En yakin noktalar: %f %f %f %d %d %d ve %f %f %f %d %d %d\n",binary_noktalar[a][0],binary_noktalar[a][1],binary_noktalar[a][2],binary_renkli[a][0],binary_renkli[a][1],binary_renkli[a][2],binary_noktalar[b][0],binary_noktalar[b][1],binary_noktalar[b][2],binary_renkli[b][0],binary_renkli[b][1],binary_renkli[b][2]);
                            printf("\n");

                            printf("En uzak noktalar: %f %f %f %d %d %d ve %f %f %f %d %d %d\n",binary_noktalar[c][0],binary_noktalar[c][1],binary_noktalar[c][2],binary_renkli[c][0],binary_renkli[c][1],binary_renkli[c][2],binary_noktalar[d][0],binary_noktalar[d][1],binary_noktalar[d][2],binary_renkli[d][0],binary_renkli[d][1],binary_renkli[d][2]);
                            printf("\n");

                            fprintf(sonuc,"En yakin noktalar: %f %f %f %d %d %d ve %f %f %f %d %d %d\n",binary_noktalar[a][0],binary_noktalar[a][1],binary_noktalar[a][2],binary_renkli[a][0],binary_renkli[a][1],binary_renkli[a][2],binary_noktalar[b][0],binary_noktalar[b][1],binary_noktalar[b][2],binary_renkli[b][0],binary_renkli[b][1],binary_renkli[b][2]);
                            fprintf(sonuc,"En uzak noktalar: %f %f %f %d %d %d ve %f %f %f %d %d %d\n",binary_noktalar[c][0],binary_noktalar[c][1],binary_noktalar[c][2],binary_renkli[c][0],binary_renkli[c][1],binary_renkli[c][2],binary_noktalar[d][0],binary_noktalar[d][1],binary_noktalar[d][2],binary_renkli[d][0],binary_renkli[d][1],binary_renkli[d][2]);
                        }

                        else
                        {
                            printf("En yakin noktalar: %f %f %f ve %f %f %f\n",binary_noktalar[a][0],binary_noktalar[a][1],binary_noktalar[a][2],binary_noktalar[b][0],binary_noktalar[b][1],binary_noktalar[b][2]);
                            printf("\n");

                            printf("En uzak noktalar: %f %f %f ve %f %f %f\n",binary_noktalar[c][0],binary_noktalar[c][1],binary_noktalar[c][2],binary_noktalar[d][0],binary_noktalar[d][1],binary_noktalar[d][2]);
                            printf("\n");

                            fprintf(sonuc,"En yakin noktalar: %f %f %f ve %f %f %f\n",binary_noktalar[a][0],binary_noktalar[a][1],binary_noktalar[a][2],binary_noktalar[b][0],binary_noktalar[b][1],binary_noktalar[b][2]);
                            fprintf(sonuc,"En uzak noktalar: %f %f %f ve %f %f %f\n",binary_noktalar[c][0],binary_noktalar[c][1],binary_noktalar[c][2],binary_noktalar[d][0],binary_noktalar[d][1],binary_noktalar[d][2]);
                        }


                        fclose(sonuc);



                    }
                    break;
                    case 3:
                    {
                        if(hata_kontrol != 0)
                        {
                            printf("Islem yapilamaz!!");
                            goto binary_git;
                        }

                        FILE *sonuc = fopen("output.nkt","a");
                        if(sonuc == NULL)
                        {
                            exit(1);
                        }

                        float maxx = fabs( binary_noktalar[0][0] - binary_noktalar[1][0]);
                        float maxy = fabs( binary_noktalar[0][1] - binary_noktalar[1][1]);
                        float maxz = fabs( binary_noktalar[0][2] - binary_noktalar[1][2]);

                        float kenar;

                        int a,b,c,d,e,f;

                        for(i=0; i<nokta_sayisi; i++)
                        {
                            for(k=i+1; k<nokta_sayisi; k++)
                            {
                                if(fabs(binary_noktalar[i][0]-binary_noktalar[k][0]) >= maxx)
                                {
                                    maxx = fabs(binary_noktalar[i][0]-binary_noktalar[k][0]);
                                    if(binary_noktalar[i][0] > binary_noktalar[k][0])
                                    {
                                        a=i;
                                        b=k;
                                    }
                                    else
                                    {
                                        a=k;
                                        b=i;
                                    }
                                }
                                else if(fabs(binary_noktalar[i][1]-binary_noktalar[k][1]) >= maxy)
                                {
                                    maxy = fabs(binary_noktalar[i][1]-binary_noktalar[k][1]);
                                    if(binary_noktalar[i][1] > binary_noktalar[k][1])
                                    {
                                        c=i;
                                        d=k;
                                    }
                                    else
                                    {
                                        c=k;
                                        d=i;
                                    }

                                }
                                else if(fabs(binary_noktalar[i][2]-binary_noktalar[k][2]) >= maxz)
                                {
                                    maxz = fabs(binary_noktalar[i][2]-binary_noktalar[k][2]);
                                    if(binary_noktalar[i][2] > binary_noktalar[k][2])
                                    {
                                        e=i;
                                        f=k;
                                    }
                                    else
                                    {
                                        e=k;
                                        f=i;
                                    }
                                }
                            }
                        }


                        float kose1,kose2,kose3,kose4,kose5;

                        if(maxx > maxy && maxx > maxz)
                        {
                            kenar = maxx;
                        }
                        if(maxy > maxx && maxy > maxz)
                        {
                            kenar = maxy;
                        }
                        if(maxz > maxy && maxz > maxx)
                        {
                            kenar = maxz;
                        }
                        printf("kenar: %f\n",kenar);

                        kose1 = binary_noktalar[d][1] + kenar;
                        printf("Kose1: %f %f %f\n",binary_noktalar[b][0],kose1,binary_noktalar[f][2]);
                        kose2 = binary_noktalar[b][0] + kenar;
                        printf("Kose2: %f %f %f\n",kose2,binary_noktalar[d][1],binary_noktalar[f][2]);
                        kose3 = binary_noktalar[f][2];
                        printf("Kose3: %f %f %f\n",kose2,kose1,kose3);
                        printf("Kose4: %f %f %f\n",binary_noktalar[b][0],binary_noktalar[d][1],binary_noktalar[f][2]);
                        kose5 = binary_noktalar[f][2] + kenar;
                        printf("Kose5: %f %f %f\n",kose2,kose1,kose5);
                        printf("Kose6: %f %f %f\n",kose2,binary_noktalar[d][1],kose5);
                        printf("Kose7: %f %f %f\n",binary_noktalar[b][0],binary_noktalar[d][1],kose5);
                        printf("Kose8: %f %f %f\n",binary_noktalar[b][0],kose2,kose5);


                        if(syc == 0)
                        {
                            fprintf(sonuc,"%s\n",dosya_isimler[index]);
                            syc++;
                        }
                        fprintf(sonuc,"SECIM 3\n");
                        fprintf(sonuc,"Kose1: %f %f %f\n",binary_noktalar[b][0],kose1,binary_noktalar[f][2]);
                        fprintf(sonuc,"Kose2: %f %f %f\n",kose2,binary_noktalar[d][1],binary_noktalar[f][2]);
                        fprintf(sonuc,"Kose3: %f %f %f\n",kose2,kose1,kose3);
                        fprintf(sonuc,"Kose4: %f %f %f\n",binary_noktalar[b][0],binary_noktalar[d][1],binary_noktalar[f][2]);
                        fprintf(sonuc,"Kose5: %f %f %f\n",kose2,kose1,kose5);
                        fprintf(sonuc,"Kose6: %f %f %f\n",kose2,binary_noktalar[d][1],kose5);
                        fprintf(sonuc,"Kose7: %f %f %f\n",binary_noktalar[b][0],binary_noktalar[d][1],kose5);
                        fprintf(sonuc,"Kose8: %f %f %f\n",binary_noktalar[b][0],kose2,kose5);
                        fclose(sonuc);


                    }
                    break;
                    case 4:
                    {
                        if(hata_kontrol != 0)
                        {
                            printf("Islem yapilamaz!!");
                            goto binary_git;
                        }

                        FILE *sonuc = fopen("output.nkt","a");
                        if(sonuc == NULL)
                        {
                            exit(1);
                        }

                        float x,y,z,yaricap;

                        printf("Merkez ve yaricap bilgileri giriniz:");
                        scanf("%f %f %f %f",&x,&y,&z,&yaricap);
                        if(syc == 0)
                        {
                            fprintf(sonuc,"%s\n",dosya_isimler[index]);
                            syc++;
                        }
                        fprintf(sonuc,"SECIM 4\n");

                        if(strstr(alanlar,RenkliDosya))
                        {
                            for(i=0; i<nokta_sayisi; i++)
                            {
                                if(yaricap >= sqrt((binary_noktalar[i][0]-x)*(binary_noktalar[i][0]-x)+(binary_noktalar[i][1]-y)*(binary_noktalar[i][1]-y) + (binary_noktalar[i][2]-z)*(binary_noktalar[i][2]-z)))
                                {

                                    printf("%f %f %f %d %d %d\n",binary_noktalar[i][0],binary_noktalar[i][1],binary_noktalar[i][2],binary_renkli[i][0],binary_renkli[i][1],binary_renkli[i][2]);
                                    fprintf(sonuc,"%f %f %f %d %d %d\n",binary_noktalar[i][0],binary_noktalar[i][1],binary_noktalar[i][2],binary_renkli[i][0],binary_renkli[i][1],binary_renkli[i][2]);
                                }

                            }

                        }

                        else
                        {
                            for(i=0; i<nokta_sayisi; i++)
                            {
                                if(yaricap >= sqrt((binary_noktalar[i][0]-x)*(binary_noktalar[i][0]-x)+(binary_noktalar[i][1]-y)*(binary_noktalar[i][1]-y) + (binary_noktalar[i][2]-z)*(binary_noktalar[i][2]-z)))
                                {

                                    printf("%f %f %f\n",binary_noktalar[i][0],binary_noktalar[i][1],binary_noktalar[i][2]);
                                    fprintf(sonuc,"%f %f %f\n",binary_noktalar[i][0],binary_noktalar[i][1],binary_noktalar[i][2]);
                                }

                            }

                        }

                        fclose(sonuc);
                    }
                    break;
                    case 5:
                    {
                        if(hata_kontrol != 0)
                        {
                            printf("Islem yapilamaz!!");
                            goto binary_git;
                        }

                        FILE *sonuc = fopen("output.nkt","a");
                        if(sonuc == NULL)
                        {
                            exit(1);
                        }

                        float uzaklik = 0.0;
                        int bolum=0;

                        float ortalama = 0.0;
                        float toplam = 0.0;

                        for(i=0; i<nokta_sayisi; i++)
                        {
                            for(k=i+1; k<nokta_sayisi-i; k++)
                            {
                                uzaklik = sqrt((fabs(binary_noktalar[i][0]-binary_noktalar[k][0]))*(fabs(binary_noktalar[i][0]-binary_noktalar[k][0]))+(fabs(binary_noktalar[i][1]-binary_noktalar[k][1]))*(fabs(binary_noktalar[i][1]-binary_noktalar[k][1]))+(fabs(binary_noktalar[i][2]-binary_noktalar[k][2]))*(fabs(binary_noktalar[i][2]-binary_noktalar[k][2])));
                                toplam += uzaklik;
                                bolum++;

                            }
                        }

                        ortalama = toplam / bolum;
                        printf("ortalama: %f\n",ortalama);

                        if(syc == 0)
                        {
                            fprintf(sonuc,"%s\n",dosya_isimler[index]);
                            syc++;
                        }

                        fprintf(sonuc,"SECIM 5\n");
                        fprintf(sonuc,"ortalama: %f\n",ortalama);
                        fclose(sonuc);
                    }
                    break;
                    default:
                        break;
                    }
                }
            }
binary_git:
            hata_kontrol = 0;
            sayac=0;
            i=0;
            j=0;
            syc=0;
            fclose(dosya);
        }
    }
    return 0;
}



























