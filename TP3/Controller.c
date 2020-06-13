#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <stdio_ext.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"
#include "menu.h"

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int ret=-1;
	FILE* pFile = fopen(path,"r");

	if(pFile !=NULL && pArrayListEmployee !=NULL)
	{
		parser_EmployeeFromText(pFile, pArrayListEmployee);
		ret=0;
	}
	else
	{
		printf("\nThe file doesn't exit");
	}
	if((fclose(pFile))==-1)
	{
		printf("\nThe file could not be closed\n");
	}
	else
	{
		printf("\nFile closed successtully\n");
	}
    return ret;
}
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int ret	=-1;
	FILE* pFile = fopen(path,"rb");

	if(pFile !=NULL && pArrayListEmployee !=NULL)
	{
		parser_EmployeeFromBinary(pFile, pArrayListEmployee);
		ret=0;
	}
	else
	{
		printf("\nThe file doesn't exit");
	}
	if((fclose(pFile))==-1)
	{
		printf("\nThe file could not be closed");
	}
	else
	{
		printf("\nFile closed successtully\n");
	}
    return ret;
}

int controller_getId(LinkedList* pArrayListEmployee)
{
	int maxId=-1;
	Employee* auxEmployee=NULL;
	int length;
	int id=0;
	int i;

	if(pArrayListEmployee != NULL)
	{
		length =ll_len(pArrayListEmployee);

		for(i=0;i<length;i++)
		{
			auxEmployee= ll_get(pArrayListEmployee, i);
			if(auxEmployee !=NULL)
			{
				employee_getId(auxEmployee, &id);
				if(id>maxId)
				{
					maxId=id;
					break;
				}
			}
			id++;
		}
	}
	maxId+=1;
	return maxId;
}


int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int ret=-1;
	Employee* auxEmployee;
	int auxId;
	char auxName[51];
	int auxSalary;
	int auxWH;

	auxEmployee= employee_new();
	if(pArrayListEmployee != NULL && auxEmployee !=NULL)
	{
		printf("\n****Register Employee****\n");

			getName(auxName, TAM_NAME);
			auxSalary= validInt("\nEnter the employee's salary");
			auxWH = validInt("\nEnter the employee's worked hours");
			auxId = ll_len(pArrayListEmployee)+1;

			employee_setId(auxEmployee, auxId);
			employee_setName(auxEmployee, auxName);
			employee_setWorkedHours(auxEmployee, auxWH);
			employee_setSalary(auxEmployee, auxSalary);

			printf("\n\tID\tNAME\tHOURS WORKED\tSALARY");
			printf("\n\t%d\t%s\t\t%d\t%d", auxId, auxName, auxWH, auxSalary);

			ret=0;
			ll_add(pArrayListEmployee, auxEmployee);
			printf("\n****Employee was registered successfully****\n");
	}
	else
	{
		free(auxEmployee);
	}
    return ret;
}

int controller_findId(LinkedList* pArrayListEmployee, int id, int* index)
{
	int ret=-1;
	Employee* auxEmployee=NULL;
	int lenthg;
	int i;
	int auxId=1;

	if(pArrayListEmployee !=NULL && id>0)
	{
		lenthg= ll_len(pArrayListEmployee);
		for(i=0;i<lenthg;i++)
		{
			auxEmployee = ll_get(pArrayListEmployee, i);
			if(auxEmployee !=NULL)
			{
				employee_getId(auxEmployee, &auxId);
				if(id==auxId)
				{
					*index=i;
					ret=0;
					break;
				}
			}
			auxId++;
		}
	}
	return ret;
}

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int ret=-1;
	Employee* auxEmployee=NULL;
	int auxId, buffer, findId;
	char auxName[51];
	int auxWH;
	int auxSalary;

	if(pArrayListEmployee !=NULL && ll_len(pArrayListEmployee)>0)
	{
		printf("\n****EDIT EMPLOYEE****\n");
		auxId = validInt("\nEnter de ID of the employee\n");
		findId= controller_findId(pArrayListEmployee, auxId, &buffer);
		if(findId==-1)
		{
			printf("\n**Error, the ID wasn't found**\n");
			free(auxEmployee);
		}
		else
		{
			auxEmployee = ll_get(pArrayListEmployee, buffer);
			if(auxEmployee !=NULL)
			{
				printf("ID: %d - Name: %s \n", auxEmployee->id, auxEmployee->name);
				switch(menuOne())
				{
					case 1:
						printf("\n**Change name**\n");
						getName(auxName, TAM_NAME);
						employee_setName(auxEmployee, auxName);
						ret=0;
						printf("\n The change was succesfulled\n");
						break;
					case 2:
						printf("\n**Change worked hours**\n");
						auxWH = validInt("\nEnter the new number of worked hours for the employee selected");
						employee_setWorkedHours(auxEmployee, auxWH);
						ret=0;
						printf("\n\tThe change was succesfulled\t\n");
						break;
					case 3:
						printf("\nChange salary\n");
						auxSalary =validInt("\nEnter the new salary for the selected employee");
						employee_setSalary(auxEmployee, auxSalary);
						ret=0;
						printf("\n\tThe change was succesfulled\t\n");
						break;
					case 4:
						printf("\n**Edit was cancelled**");
						break;
				}
			}
		}
	}
	else
	{
		printf("Error\n");
	}
    return ret;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	Employee* auxEmployee =NULL;
	int ret=-1;
	int auxId, findId, buffer;

	if(pArrayListEmployee !=NULL)
	{
		printf("\n****REMOVE EMPLOYEE****\n");
		auxId = validInt("\nEnter de ID of the employee\n");
		findId= controller_findId(pArrayListEmployee, auxId, &buffer);
		if(findId==-1)
		{
			printf("\n**Error, the ID wasn't found**\n");
			free(auxEmployee);
		}
		else
		{
			auxEmployee = ll_get(pArrayListEmployee, buffer);
			printf("ID: %d - Name: %s", auxEmployee->id, auxEmployee->name);
			if(validConfir()==2)
			{
				printf("\n**Remove was cancel**\n");
			}
			else
			{
				auxEmployee =ll_pop(pArrayListEmployee, buffer);
				if(auxEmployee !=NULL)
				{
					employee_delete(auxEmployee);
					printf("\n**Delete successfull**\n");
					ret=0;
				}
			}
		}
	}
    return ret;
}

int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	Employee* auxEmployee=NULL;
	int i;
	char auxName[TAM_NAME];
	int auxSalary=0;
	int auxId=0;
	int auxWH=0;
	int ret=-1;

	if(pArrayListEmployee !=NULL)
	{

		if(ll_len(pArrayListEmployee)==0)
		{
			printf("The list is empty\n");
			free(auxEmployee);
		}
		else
		{
			printf("\n\tID\tNAME\tHOURS WORKED\tSALARY");
			for(i=0;i<ll_len(pArrayListEmployee);i++)
			{
				auxEmployee =ll_get(pArrayListEmployee, i);
				if(auxEmployee !=NULL)
				{
					if(!employee_getId(auxEmployee, &auxId) &&
							!employee_getName(auxEmployee, auxName) &&
							!employee_getWorkedHours(auxEmployee,&auxWH) &&
							!employee_getSalary(auxEmployee, &auxSalary))
					{

						printf("\n\t%d\t%s\t%d\t\t%d",auxId, auxName, auxWH, auxSalary);
						ret=0;
					}
				}
			}
		}
	}
    return ret;
}

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int ret=-1;

	if(pArrayListEmployee !=NULL)
	{
		switch(menuTwo())
		{
			case 1:
				ll_sort(pArrayListEmployee, employee_orderByName, 1);
				break;
			case 2:
				ll_sort(pArrayListEmployee, employee_orderByName, 0);
				break;
			case 3:
				ll_sort(pArrayListEmployee, employee_orderById, 1);
				break;
			case 4:
				ll_sort(pArrayListEmployee, employee_orderById, 0);
				break;
			case 5:
				ll_sort(pArrayListEmployee, employee_orderByWH, 1);
				break;
			case 6:
				ll_sort(pArrayListEmployee, employee_orderByWH, 0);
				break;
			case 7:
				ll_sort(pArrayListEmployee, employee_orderBySalary, 1);
				break;
			case 8:
				ll_sort(pArrayListEmployee, employee_orderBySalary, 0);
				break;
		}
		ret=0;
	}
	return ret;
}

int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int ret=-1;
	Employee* auxEmployee=NULL;
	FILE* pFile=NULL;
	int auxId;
	char auxName[51];
	int auxSalary;
	int auxWH;
	int length;
	int i;

	if(path !=NULL && pArrayListEmployee !=NULL)
	{
		pFile = fopen(path, "w+");
		if(pFile !=NULL)
		{
			length = ll_len(pArrayListEmployee);
			for(i=0; i<length;i++)
			{
				auxEmployee = ll_get(pArrayListEmployee, i);
				//fseek(pFile, 0L, SEEK_END);
				if(!employee_getId(auxEmployee, &auxId) &&
					!employee_getName(auxEmployee, auxName) &&
					!employee_getWorkedHours(auxEmployee,&auxWH) &&
					!employee_getSalary(auxEmployee, &auxSalary))
					{
					fprintf(pFile, "%d,  %s,  %d, %d\n", auxId, auxName, auxWH, auxSalary);
					}
				else
				{
					employee_delete(auxEmployee);
				}
			}
			ret =0;
			printf("File saved successfully");
			if((fclose(pFile))==-1)
			{
				printf("The file could not be closed");
			}
			else
			{
				printf("File closed successtully\n");
				ret=0;
			}
		}
		else
		{
			printf("File doesnt exits");
		}
	}
    return ret;
}

int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int ret=-1;
	FILE* pFile =NULL;
	Employee* auxEmployee=NULL;
	int length;
	int i;
	int c;

	if(pArrayListEmployee !=NULL && path !=NULL)
	{

		pFile = fopen(path, "w+b");
		if(pFile != NULL)
		{
			length = ll_len(pArrayListEmployee);
			for(i=0;i<length;i++)
			{
				auxEmployee= ll_get(pArrayListEmployee, i);
				if(auxEmployee !=NULL)
				{
					c = fwrite(auxEmployee, sizeof(Employee),1, pFile);
				}
				if(c !=1)
				{
					printf("\nError, file could not be written");
					break;
				}
			}
			ret=0;
		}
		printf("File saved successfully");
		if((fclose(pFile))==-1)
		{
			printf("The file could not be closed");
		}
		else
		{
			printf("File closed successtully\n");
		}
	}

	return ret;
}

int controller_keepAddEmp(void)
{
	int buffer;

	buffer =validInt("\nDo you want to add another employee? Enter:\n1 - Yes\n2 - No\n");
	while(buffer != 1 && buffer != 2)
	{
		buffer=	validInt("\nError. Must enter\n 1 - Yes\n2 - No");
	}
	return buffer;
}
