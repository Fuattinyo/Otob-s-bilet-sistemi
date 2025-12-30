#include <stdio.h>
#include <ctype.h>

int main(){
   char koltuk[10] [4];
   char girdi[100];
   char cinsiyet,yer,cikis ='H';
   
   
   //Baslıyoruz!!!! Tüm koltukları bos yap;
   for (int i=0;i<10;i++)
     for (int j=0;j<4;j++)
     koltuk[i][j]='-';
     
     do
     {
         printf("Cinsiyeti Giriniz (E/K) : ");
         fgets(girdi,sizeof(girdi),stdin);
         cinsiyet = toupper(girdi[0]);
         
         printf("Koridor/Cam (K/C)");
         fgets(girdi,sizeof(girdi),stdin);
         yer = toupper(girdi[0]);
         
         int yerVerildi=0;
         
         
         for (int i=0; i<10 && (yerVerildi ==0) ; i++)
         {
               if ( yer== 'C')
               {
                  //sol cam
                  if (koltuk[i][0] == '-' && (koltuk[i][1] == '-' || koltuk[i][1]==cinsiyet))
                  {
                      koltuk[i][0]=cinsiyet;
                      yerVerildi = 1;
                      break;
                  }
                  //sağ cam
                  if (koltuk[i][3] == '-' && (koltuk[i][2] == '-' || koltuk[i][2]==cinsiyet))
                  {
                      koltuk[i][3] = cinsiyet;
                      yerVerildi = 1;
                      break; 
                  }
                  
                  
               }else
               {
                   if (koltuk[i][1]=='-' && (koltuk[i][0]=='-' || koltuk[i][0] == cinsiyet))
                   {
                       koltuk[i][1]=cinsiyet;
                       yerVerildi=1;
                       break;
                   }
                   //sag koridor
                   if (koltuk[i][2]=='-' && (koltuk[i][3]=='-' || koltuk[i][3] == cinsiyet))
                   {
                       koltuk[i][2]=cinsiyet;
                       yerVerildi=1;
                       break;
                   }  //if kapanış
               } //if kapanış
         }//for kapanış
         printf("\n=====KOLTUKLAR=====\n");
         for (int i=0;i<10;i++)
         {
            for (int j=0;j<4;j++)
            {
             printf("%c" ,koltuk[i][j]);
            }
             printf("\n");
         }
         
         printf("Çıkış(E/H) :");
         fgets(girdi,sizeof(girdi),stdin);
         cikis = girdi[0];
         
     } while (cikis != 'E');
   
     return 0;
}