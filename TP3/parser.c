#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int ret=-1;
	char auxId[50];
	char auxName[150];
	char auxWK[50];
	char auxSalary[50];
	int r;
	Employee* auxEmp;


	if(pFile !=NULL && pArrayListEmployee !=NULL)
	{
		do
		{
			r= fscanf(pFile,"%[^,] , %[^,] , %[^,] , %[^\n]\n",auxId, auxName,auxWK, auxSalary);
			if(r !=4)
			{
				printf("\nError while trying to read the file");
			}
			else
			{
				auxEmp = employee_newParametros(auxId, auxName, auxWK, auxSalary);
				if(auxEmp !=NULL)
				{
					ll_add(pArrayListEmployee, auxEmp);
				}
			}
		}while(!feof(pFile));
		ret=0;
	}
	else
	{
		printf("Error\n");
	}
    return ret;
}

int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int ret=-1;
	Employee* auxEmp;
	int r;

	if(pFile != NULL && pArrayListEmployee !=NULL)
	{
		do
		{
			auxEmp =employee_new();
			r = fread(auxEmp, sizeof(auxEmp),1,pFile);
			if(r != 1)
			{
				printf("\nError while trying to read the file");
			}
			else
			{
				ll_add(pArrayListEmployee, auxEmp);
				ret=0;
			}
		}while(!feof(pFile));
	}
	else
	{
		printf("\nError");
	}


    return ret;
}
