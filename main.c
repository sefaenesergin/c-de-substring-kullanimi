//SEFA ENES ERGİN-sefaenesergin@gmail.com
/*
 Girilen bir karakter dizisinin istenilen pozisyondan itibaren istenilen karakter sayısı kadar kopyalanmasını sağlayan C kodu.
 */
#include <stdio.h>
#include <string.h>
char *Substring(char *diziKopya, int pozisyon, int uzunluk){
    for (int i=0; i<uzunluk; i++)
        diziKopya[i]=diziKopya[i+pozisyon];
    diziKopya[uzunluk]='\0';
    /*
     NOT: Neden terminated karakter kullandık?
     Eğer kullanmasaydık puts() fonksiyonunda durması gereken yerde durmazdı ve istenmeyen şeyleri de ekrana basardı. Terminated karakter sayesinde fonksiyon durması gereken yeri biliyor.
     */
    diziKopya=(char*)realloc(diziKopya,uzunluk+1);/*diziyi uzunluk boyutuna indirdik.*/
    return diziKopya;
    
}

int main(int argc, const char * argv[]) {
    char dizi[101];
    int pozisyon, uzunluk;
    int *kopya;
    
    printf("Lütfen klavyeden bir karakter dizisi yazınız.\n");
    gets(dizi);
    char *dizi2=(char*)malloc((strlen(dizi)+1)*sizeof(char));
    /*
     Bir üst satırda yedek diziyi tanımladık. Bellekte gereksiz yer tutmaması için dinamik bellek kullandık. strlen(dizi)'nin yanına +1 eklememizin nedeni ise terminated character'i dahil etmemizdir.
     */
    strcpy(dizi2, dizi);// asıl diziyi yedek olana kopyaladık.
    
    
    printf("Kopyalamak istediğiniz pozisyon bilgisini giriniz.\n");
    scanf("%d",&pozisyon);
    
    printf("Kopyalama uzunluğunu giriniz.\n");
    scanf("%d",&uzunluk);
    
    char *gptr=Substring(dizi2, pozisyon, uzunluk);
    
    puts(gptr);
    return 0;
}
