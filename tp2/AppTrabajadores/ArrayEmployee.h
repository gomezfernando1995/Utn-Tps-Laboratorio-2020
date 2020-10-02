#ifndef ARRAYEMPLOYEE_H_INCLUDED
#define ARRAYEMPLOYEE_H_INCLUDED

typedef struct
{
	int id;
	char name[50];
    char lastName[50];
    float salary;
    int sector;
	int isEmpty;

}eEmployee;

#endif // ARRAYEMPLOYEE_H_INCLUDED

int initializeArrayEmployee(eEmployee arrayEmployee[],int quantityEmployee);
int searchIsEmpty(eEmployee arrayEmployee[],int quantityEmployee);
int searchIdEmployee(eEmployee arrayEmployee[],int quantityEmployee,int auxiliaryId);
int removeEmployee(eEmployee arrayEmployee[], int quantityEmployee, int idForClear);
void toShowInformation(eEmployee arrayEmployees[],int quantityEmployee,float accumualteSalary, float average);


