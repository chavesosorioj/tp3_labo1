#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#define TAM_NAME 50

typedef struct
{
    int id;
    char name[128];
    int workedHours;
    int salary;
}Employee;
/*
 * brief reserve space in memorie for one employee
 * param void
 * return void
 */
Employee* employee_new();

/*
 * brief charge the employee with the paramethers
 * param idStr - char id
 * param nameStr - char name
 * param workHoursStr -char worked hours
 * param salary - char salary
 * return struct employee
 */
Employee* employee_newParametros(char* idStr,char* nameStr,char* workedHoursStr, char* salary);

/*
 * brief deletes and employee
 * param this, pointer to the employee
 * return void
 */
void employee_delete(Employee* this);

/*
 * breif set a new id of an employee
 * param this, pointer to the employee
 * param id - int that sets
 * return -1 NULL
 *         0 OK
 */
int employee_setId(Employee* this,int id);
/*
 * brief gets the id of an employee
 * param this, pointer to the employee
 * param id, pointer to the id that gets
 * return -1 NULL
 *         0 OK
 */
int employee_getId(Employee* this,int* id);
/*
 * brief set the name of an employee
 * param this, pointer to the employee
 * param name, char pointer to the name that sets
 * return -1 NULL
 *         0 OK
 */
int employee_setName(Employee* this,char* name);
/*
 * brief set the name of an employee
 * param this, pointer to the employee
 * param name, char pointer to the name that gets
 * return -1 NULL
 *         0 OK
 */
int employee_getName(Employee* this,char* name);
/*
 * brief set the works hours of an employee
 * param this, pointer to the employee
 * param workedHours, int to the WK that sets
 * return -1 NULL
 *         0 OK
 */
int employee_setWorkedHours(Employee* this,int workedHours);
/*
 * brief gets the works hours of an employee
 * param this, pointer to the employee
 * param workedHours, int pointer to the wk that gets
 * return -1 NULL
 *         0 OK
 */
int employee_getWorkedHours(Employee* this,int* workedHours);
/*
 * brief set the salary of an employee
 * param this, pointer to the employee
 * param salary, int to the salary that sets
 * return -1 NULL
 *         0 OK
 */
int employee_setSalary(Employee* this,int salary);
/*
 * brief gets the salary of an employee
 * param this, pointer to the employee
 * param salary, int pointer to the salary that gets
 * return -1 NULL
 *         0 OK
 */
int employee_getSalary(Employee* this,int* salary);
/*
 * brief order employess by name
 *  param void
 *  param void
 *  return 0 - if they are the same
 *         1 - if the firt is bigger
 *         -1 - if the second is bigger
 */
int employee_orderByName(void* auxP1, void* auxP2);
/*
 * brief order employess by salary
 *  param void
 *  param void
 *  return 0 - if they are the same
 *         1 - if the firt is bigger
 *         -1 - if the second is bigger
 */
int employee_orderBySalary(void* auxP1, void* auxP2);
/*
 * brief order employess by salary
 *  param void
 *  param void
 *  return 0 - if they are the same
 *         1 - if the firt is bigger
 *         -1 - if the second is bigger
 */
int employee_orderById(void* auxP1, void* auxP2);
/*
 * brief order employess by salary
 *  param void
 *  param void
 *  return 0 - if they are the same
 *         1 - if the firt is bigger
 *         -1 - if the second is bigger
 */
int employee_orderByWH(void* auxP1, void* auxP2);

#endif // employee_H_INCLUDED
