#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void menu()
{
   puts("\nTentukan arah translate");
   puts("1. Batak-English");
   puts("2. English-Bahasa Batak");
   puts("3. Tambahkan Kata Baru");
   puts("4. Keluar");
}

int main()
{
   FILE *its;
   char msg[1000][30];
   char ind[30];
   char name[50];
   char course[50];
   int a, b;
   int found;

   do {
      if ((its = fopen("KAMUS.txt", "r+")) == NULL) {
         printf("ERROR!!! file KAMUS.txt corrupt");
         getch();
         exit(1);
      }
      menu();
      b = getch();

      switch (b) {
      case '1':
      {
         rewind(its);
         for (a = 0; a < 1000; a++) {
            if (fgets(msg[a], sizeof(msg[a]), its) == NULL) {
               break;
            }
         }
         printf("batak : ");
         gets(ind);
         strcat(ind, "\n");
         found = 0;
         printf("english   : ");
         for (a = 0; a < 1000 && msg[a][0] != '\0'; a++) {
            if (strcmp(ind, msg[a]) == 0) {
               printf("%s", msg[a + 1]);
               found = 1;
               break;
            }
         }
         if (!found) {
            printf("Terjemahan tidak ditemukan. Silakan menambahkan.\n");
         }
         fclose(its);
         break;
      }
      case '2':
      {
         rewind(its);
         for (a = 0; a < 1000; a++) {
            if (fgets(msg[a], sizeof(msg[a]), its) == NULL) {
               break;
            }
         }
         printf("English : ");
         gets(ind);
         strcat(ind, "\n");
         found = 0;
         printf("batak : ");
         for (a = 0; a < 1000 && msg[a][0] != '\0'; a++) {
            if (strcmp(ind, msg[a]) == 0) {
               printf("%s", msg[a - 1]);
               found = 1;
               break;
            }
         }
         if (!found) {
            printf("Terjemahan tidak ditemukan. Silakan menambahkankannya.\n");
         }
         fclose(its);
         break;
      }
      case '3':
      {
         fclose(its); // Close the file opened in read mode
         if ((its = fopen("KAMUS.txt", "a")) == NULL) {
            printf("ERROR!!! file KAMUS.txt corrupt");
            getch();
            exit(1);
         }
         printf("batak: ");
         scanf("%s", name);
         printf("english: ");
         scanf("%s", course);
         fprintf(its, "%s\n%s\n", name, course);
         printf("Data berhasil Ditambahkan\n");
         fclose(its);
         break;
      }
      }
   } while (b != '4');

   return 0;
}
