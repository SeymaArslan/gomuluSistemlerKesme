 //Buton a basýldýðýnda 1 saniyelik dýþ kesme iþlemi yapýlýyor. ve LCD yardýmý ile ekrana kesme oluþturuldu mesajý gönderiyor...
#include<16f877.h>
#fuses XT,NOWDT
#use delay(clock=1M)
#include <lcd.c>                            //2 satir lcd kütüphanesi eklendi
#int_ext                                    //Kesme olduðunda hemen alttaki satýrdan itibaren devam eder.
void ext_kesmesi() {
      lcd_init();                            //LCD kullanýmý için gerekli
      lcd_putc('\f');                        //bu þekilde baþlangýca cursor alýndý
      printf(lcd_putc,"kesme olustu ..." ); //printf ile lcd ye karakter karakter 
                                             //verilen deðer gönderilir 
      delay_ms(1000);
      lcd_putc('\f');                        //bu þekilde baþlangýca cursor alýndý
       }
void main() {
     enable_interrupts(INT_EXT);     //Dýs kesmeyi etkin hale getirir.
     enable_interrupts(GLOBAL);      //Tüm kesme iþlemlerine izin verir.
       while(1) {                    //Kesme yokken sonsuz döngü içerisinde LED yanýp söner. Kesme dýþýndaki esas görev.
       output_high(PIN_D3);  
       delay_ms(100);
       output_low(PIN_D3);
       delay_ms(100);
     }
     
     while(1);

}
