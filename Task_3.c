#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Person Person;
typedef struct Person* position;
struct Person
{
	char name[128];
	char surname[128];
	int BirthYear;
	position next;
};



void InsertFirst(position);
void InsertEnd(position);
void PrintList(position);
void FindElement(position);
void DeleteElement(position);
void AddBehind(position);
void AddBefore(position);
void SortList(position);
void WriteInFile(position);
void ReadFromFile(position);
void DeleteAll(position);
void DeleteFirst(position);

int main()
{
	Person Head;
	Head.next = NULL;
	int mainChoice = 1;
	while (mainChoice != NULL) {
		printf("\n\n\t\t\t ~ MENU ~ \n");
		printf("\n\t Unesite broj uz zeljenu operaciju. ~\n\n");
		printf("0) End program. \n");
		printf("1) Dodaj element na pocetak liste. \n");
		printf("2) Dodaj elemnt na kraj liste. \n");
		printf("3) Ispis liste. \n");
		printf("4) Pronadi element (potrebno unijeti prezime). \n");
		printf("5) Izbrisi element (potrebno unijeti prezime). \n");
		printf("6) Dodaj novi element iza odredenog elementa (unijeti prezime). \n");
		printf("8) Dodaj novi element prije odredenog elementa (unijeti prezime). \n");
		printf("9) Upisati listu u datoteku. \n");
		printf("10) Citati listu iz datoteke. \n");
		printf("11) ");
		printf("12) ");

	}

	return 0;
}

void InsertFirst(position p) {
	position temp;
	temp = (position)malloc(sizeof(Person));
	temp->next = p->next;
	p->next = temp;
	printf("Upisite ime, prezime i godinnu rodenja. \n");
	scanf_s("%s %s %d", temp->name, 128, temp->surname, 128, &temp->BirthYear);

}

void InsertEnd(position p) {
	position temp;
	temp = (position)malloc(sizeof(Person));
	while (p->next != NULL) {
		p = p->next;
		temp->next = p->next;
		p->next = temp;
		printf("Unesite ime, prezime i godinu rodenja. \n");
		scanf_s("%s %s %d", temp->name, 128, temp->surname, 128, &temp->BirthYear);

	}

}


void PrintList(position p) {
	if (p == NULL)
		printf("\n Lista je prazna. \n");
	else {
		printf("\n\t ~ Sadrzaj liste: ~\n");
		while (p != NULL)
		{
			printf("\n%s %s %d", p->name, p->surname, p->BirthYear);
			p = p->next;
		}
	}
}
void FindElement(position p) {
	position temp;
	char srnm[128];
	printf("\nUnesite prezime. \t");
	scanf_s("%s", srnm, 128);
	while (p != NULL) {
		if (_strcmpi(p->surname, srnm) == 0)
			temp = p;
		p = p->next;
	}
	return temp;
}

void DeleteElement(position p) {
	position temp;
	char srnm[128];
	printf("\n Unesite prezime. \t");
	scanf_s("%s", srnm, 128);
	while (p != NULL) {
		if (_strcmpi(p->next->surname, srnm) == 0) {
			temp = p->next;
			p->next = temp->next;
			free(temp);
		}
		p = p->next;
	}

}


void AddBehind(position p) {
	char srnm[128];
	printf("\n Unesite prezime osobe iz akoje zelite da ovaj elemnt bude. \t");
	scanf_s("%s", srnm, 128);

	position temp;
	temp = (position)malloc(sizeof(Person));
	while (p != NULL) {
		if (_strcmpi(p->surname, srnm) == 0) {
			temp->next = p->next;
			p->next = temp;
			printf("\n Unesite ime, prezime i godinu rodenja. \n");
			scanf_s("°%s %s %d", temp->name, 128, temp->surname, 128, &temp->BirthYear);
		}
		p = p->next;
	}
}

void AddBefore(position p) {

}
void SortList(position p) {

}

void WriteInFile(position p) {

}

void ReadFromFile(position p) {

}
