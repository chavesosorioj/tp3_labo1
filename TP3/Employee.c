//---------Labriaries - CHEQUEAR SI ME FALTAN MAS.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <stdio_ext.h>
#include "Employee.h"
#include "LinkedList.h"
#include "utn.h"
#include "Controller.h"



Employee* employee_new()
{
	Employee* this;

	this = (Employee*)malloc(sizeof(Employee));

	if(this !=NULL)
	{
		employee_setId(this, 0);
		employee_setName(this, " ");
		employee_setWorkedHours(this, 0);
		employee_setSalary(this, 0);

	}

	return this;
}
Employee* employee_newParametros(char* idStr,char* nameStr,char* workedHoursStr, char* salary)
{
	Employee* auxEmployee;
	Employee* ret=NULL;
	auxEmployee=employee_new();


	int auxId;
	int auxWorkedHours;
	int auxSalary;

	if(auxEmployee!=NULL && idStr !=NULL && nameStr !=NULL && workedHoursStr!=NULL)
	{
		// verificar que funcione
		auxId= atoi(idStr);
		auxWorkedHours= atoi(workedHoursStr);
		auxSalary= atoi(salary);

		if(!employee_setId(auxEmployee, auxId) &&
		!employee_setName(auxEmployee, nameStr) &&
		!employee_setWorkedHours(auxEmployee, auxWorkedHours) &&
		!employee_setSalary(auxEmployee, auxSalary))
		{
			ret=auxEmployee;
		}
		else
		{
			employee_delete(auxEmployee);
		}
	}
	return ret;
}
void employee_delete(Employee* this)
{
	if(this !=NULL)
	{
		free(this);
	}
}

int employee_setId(Employee* this,int id)
{
	int ret=-1;
	if(this !=NULL && id>0)
	{
		this->id=id;
		ret=0;
	}
	return ret;
}
int employee_getId(Employee* this,int* id)
{
	int ret=-1;
	if(this !=NULL)
	{
		*id= this->id;
		ret=0;
	}
	return ret;
}

int employee_setName(Employee* this,char* name)
{
	int ret=-1;
	if(this !=NULL && name!=NULL)
	{
		strcpy(this->name, name);
		ret=0;
	}
	return ret;
}
int employee_getName(Employee* this,char* name)
{
	int ret=-1;

	if(this !=NULL)
	{
		strcpy(name, this->name);
		ret=0;
	}
	return ret;
}

int employee_setWorkedHours(Employee* this,int workedHours)
{
	int ret=-1;
	if(this !=NULL && workedHours>0)
	{
		this->workedHours=workedHours;
		ret=0;
	}
	return ret;
}
int employee_getWorkedHours(Employee* this,int* workedHours)
{
	int ret=-1;
	if(this !=NULL)
	{
		*workedHours= this->workedHours;
		ret=0;
	}
	return ret;
}

int employee_setSalary(Employee* this,int salary)
{
	int ret=-1;
	if(this !=NULL && salary>0)
	{
		this->salary=salary;
		ret=0;
	}
	return ret;
}
int employee_getSalary(Employee* this,int* salary)
{
	int ret=-1;
	if(this !=NULL)
	{
		*salary= this->salary;
		ret=0;
	}
	return ret;
}


int employee_orderByName(void* auxP1, void* auxP2)
{
	int ret=0;
	Employee* emp1 = NULL;
	Employee* emp2 = NULL;
	char name1[200];
	char name2[200];
	if(auxP1!=NULL && auxP2!=NULL)
	{
		emp1 =(Employee*)auxP1;
		emp2 =(Employee*)auxP2;
		employee_getName(emp1, name1);
		employee_getName(emp2, name2);
		if(strcmp(name1,name2)>0)
		{
			ret=1;
		}
		else if(strcmp(name1,name2)<0)
		{
			ret=-1;
		}
	}
	return ret;
}

int employee_orderBySalary(void* auxP1, void* auxP2)
{
	int ret=0;
	Employee* emp1 = NULL;
	Employee* emp2 = NULL;
	int s1;
	int s2;
	if(auxP1!=NULL && auxP2!=NULL)
	{
		emp1 =(Employee*)auxP1;
		emp2 =(Employee*)auxP2;
		employee_getSalary(emp1, &s1);
		employee_getSalary(emp2, &s2);
		if(s1>s2)
		{
			ret=1;
		}
		else if(s1<s2)
		{
			ret=-1;
		}
	}
	return ret;
}

int employee_orderByWH(void* auxP1, void* auxP2)
{
	int ret=0;
	Employee* emp1 = NULL;
	Employee* emp2 = NULL;
	int wh1;
	int wh2;
	if(auxP1!=NULL && auxP2!=NULL)
	{
		emp1 =(Employee*)auxP1;
		emp2 =(Employee*)auxP2;
		employee_getWorkedHours(emp1, &wh1);
		employee_getWorkedHours(emp2, &wh2);
		if(wh1>wh2)
		{
			ret=1;
		}
		else if(wh1<wh2)
		{
			ret=-1;
		}
	}
	return ret;
}

int employee_orderById(void* auxP1, void* auxP2)
{
	int ret=0;
	Employee* emp1 = NULL;
	Employee* emp2 = NULL;
	int id1;
	int id2;
	if(auxP1!=NULL && auxP2!=NULL)
	{
		emp1 =(Employee*)auxP1;
		emp2 =(Employee*)auxP2;
		employee_getId(emp1, &id1);
		employee_getId(emp2, &id2);
		if(id1>id2)
		{
			ret=1;
		}
		else if(id1<id2)
		{
			ret=-1;
		}
	}
	return ret;
}
