 //Buton a bas�ld���nda 1 saniyelik d�� kesme i�lemi yap�l�yor. ve LCD yard�m� ile ekrana kesme olu�turuldu mesaj� g�nderiyor...
#include<16f877.h>
#fuses XT,NOWDT
#use delay(clock=1M)
#include <lcd.c>                            //2 satir lcd k�t�phanesi eklendi
#int_ext                                    //Kesme oldu�unda hemen alttaki sat�rdan itibaren devam eder.
void ext_kesmesi() {
      lcd_init();                            //LCD kullan�m� i�in gerekli
      lcd_putc('\f');                        //bu �ekilde ba�lang�ca cursor al�nd�
      printf(lcd_putc,"kesme olustu ..." ); //printf ile lcd ye karakter karakter 
                                             //verilen de�er g�nderilir 
      delay_ms(1000);
      lcd_putc('\f');                        //bu �ekilde ba�lang�ca cursor al�nd�
       }
void main() {
     enable_interrupts(INT_EXT);     //D�s kesmeyi etkin hale getirir.
     enable_interrupts(GLOBAL);      //T�m kesme i�lemlerine izin verir.
       while(1) {                    //Kesme yokken sonsuz d�ng� i�erisinde LED yan�p s�ner. Kesme d���ndaki esas g�rev.
       output_high(PIN_D3);  
       delay_ms(100);
       output_low(PIN_D3);
       delay_ms(100);
     }
     
     while(1);

}
