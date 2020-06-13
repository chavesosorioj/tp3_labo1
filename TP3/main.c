#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "menu.h"
#define FILETEXT "data.csv"
#define FILEBINARY "data.csv"

int main()
{
	int option;
	int add=0;
     LinkedList* listEmployee = ll_newLinkedList();

    do{
    	option =menu();
        switch(option)
        {
            case 1:
                controller_loadFromText(FILETEXT,listEmployee);
                break;
            case 2:
            	controller_loadFromBinary(FILEBINARY, listEmployee);
            	break;
            case 3:
            	while(add!=2)
            	{
            		controller_addEmployee(listEmployee);
            		add=controller_keepAddEmp();
            	}

            	break;
            case 4:
            	controller_editEmployee(listEmployee);
            	break;
            case 5:
            	controller_removeEmployee(listEmployee);
            	break;
            case 6:
            	controller_ListEmployee(listEmployee);
            	break;
            case 7:
            	controller_sortEmployee(listEmployee);
            	break;
            case 8:
            	controller_saveAsText(FILETEXT, listEmployee);
            	break;
            case 9:
            	controller_saveAsBinary(FILEBINARY, listEmployee);
            	break;
            case 10:
            	ll_deleteLinkedList(listEmployee);
           }
    }while(option !=10);
    return 0;

}

