#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATA_SIZE 1000

int main() {
	char *data, *ders;
	int devam = 1, soru = 1, yeni = 1;
	FILE *fptr;
	
  	printf("Test soru cevap kaydedicisi\nV:0.1.0 Alpha\n\n");
  	printf("Cikis icin x yaz\nBaska derse gecmek icin y yaz\n\n");
  	
  	fptr = fopen("cevaplar.txt", "w+");
  	
  	if(fptr == NULL) {
  		printf("HATA: 01\nDosya acilamiyor!");
  		exit(EXIT_FAILURE);
	}
	
	//strncat(totalData, &ders, 1);
	
	while(devam == 1) {
		if(yeni == 1) {
			printf("Ders adini gir => ");
  			scanf("%s", &ders);
  			fprintf(fptr, "%s\n", &ders);
  			yeni = 0;
  			soru = 1;
		}
		printf("\n%d.soru => ", soru);
		scanf("%s", &data);
		if(data == 'x') {
			devam = 0;
		} else if(data == 'y') {
			yeni = 1;
		} else {
			//strncat(totalData, &data, 1);
			fprintf(fptr, "%d => %c\n", soru, data);
			soru ++;
		}
	}
	
	//fprintf(fptr, "%c", totalData);
	
	printf("\nCevaplar kaydedildi!");
	
	fclose(fptr);
	
  	return 0;
}
