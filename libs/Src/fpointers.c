#include "fpointers.h"
#include "stdio.h"
/* ***************************************************************** */
#define MAX_NUM_FUNC 10
static ftype ar_gfp[MAX_NUM_FUNC];
static int gcount = 0;
/* ***************************************************************** */

/**
 * @brief gfp işaretçisi, neco fonksiyonunu işaret eder.
 */
ftype gfp = &neco;

/**
 * @brief neco fonksiyonunun tanımı
 *
 * Bu fonksiyon ekrana "neco cagirildi." mesajını yazdırır.
 */
void neco(void)
{
    printf("neco cagirildi.\n");
}


/**
 * @brief foo fonksiyonu
 *
 * Varsayılan olarak gfp işaretçisini kullanarak neco fonksiyonunu çağırır.
 */
void foo(void)
{
    gfp();
}

/**
 * @brief foo'nun davranışını değiştiren fonksiyon
 *
 * @param fp Yeni fonksiyon işaretçisi.
 * @return ftype Eski fonksiyon işaretçisini döndürür.
 *
 * Bu fonksiyon, hangi fonksiyon adresi verilirse, foo fonksiyonunun
 * davranışını değiştirecek şekilde gfp işaretçisini günceller.
 */
ftype set_foo(ftype fp)
{
    ftype ret = gfp;

    gfp = fp;

    return ret;
}


void reg_func(ftype f){
    if(gcount == MAX_NUM_FUNC){
        return;
    }
    ar_gfp[gcount++] = f;

}

void reg_foo(void){
    for(int i = 0; i < MAX_NUM_FUNC; ++i){
        ar_gfp[i]();
    }
}