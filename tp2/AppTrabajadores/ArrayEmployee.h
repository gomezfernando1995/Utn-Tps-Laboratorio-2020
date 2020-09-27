#ifndef ARRAYEMPLOYEE_H_INCLUDED
#define ARRAYEMPLOYEE_H_INCLUDED

typedef struct
{
	int id;
	char name[50];
    char lastName[50];
    float salary;
    char sector[50];
	int isEmpty;

}eEmployee;

int initializeArrayEmployee(eEmployee arrayEmployee[],int quantityEmployee);
int searchIsEmpty(eEmployee arrayEmployee[],int quantityEmployee);
int idRandom(int indexFree,eEmployee arrayEmployee[],int quantityEmployee);
int searchIdEmployee(eEmployee arrayEmployee[],int quantityEmployee,int auxiliaryId);
int removeEmployee(eEmployee arrayEmployee[], int quantityEmployee, int idForClear);



#endif // ARRAYEMPLOYEE_H_INCLUDED
