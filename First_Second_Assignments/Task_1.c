#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS

typedef struct osoba{
	char ime[50];
	char prezime[50];
	int bodovi;
}student;

int main(){
	student* studenti;
	FILE* fp;
	int broj = 0;
	fp = fopen("Untitled.txt", "r");
	char ret;
	while (feof(fp) != 1){
		ret = fgetc(fp);
		if (ret == '\n'){
			broj++;
		}
	}
	studenti = (student*)malloc(sizeof(student) * broj);
	rewind(fp);
	for (int i = 0; i < broj; i++){
		fscanf(fp, "%s %s %d", studenti[i].ime, studenti[i].prezime, &studenti[i].bodovi);
	}
	for (int i = 0; i < broj; i++) {
		printf("%s %s %d %f\n", studenti[i].ime, studenti[i].prezime, studenti[i].bodovi, (float)studenti[i].bodovi / (100 * 100));
	}
	free(studenti);
	fclose(fp);
	return 0;
}