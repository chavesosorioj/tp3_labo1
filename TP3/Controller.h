/** \brief Load the data from the file data.csv (text mode).
 * param path char*                                - Direction / Name where the data is load.
 * param pArrayListEmployee LinkedList*            - List where data is load.
 * 	return - -1 NULL
 * 	        or the data
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
/** \brief Load the data from the file data.csv (bin mode).
 *
 * \param path char*                                - Direction / Name where the data is load.
 * \param pArrayListEmployee LinkedList*            - List where data is load.
 * 	return - -1 NULL
 * 	        0 if its ok
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
/*
 * breif Adds and employee
 * 	param LinkedList* pArrayListEmployee - pointer to the employee list
 * 	return - -1 NULL
 * 	        0 if its ok
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);
/*
 * breif edits and employee
 * 	param LinkedList* pArrayListEmployee - pointer to the employee list
 * 	return - -1 NULL
 * 	        0 ok
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);
/*
 * breif removes and employee
 * 	param LinkedList* pArrayListEmployee - pointer to the employee list
 * 	return - -1 NULL
 * 	        0 ok
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);
/*
 * breif list all the employees
 * 	param LinkedList* pArrayListEmployee - pointer to the employee list
 * 	return - -1 NULL
 * 	         0 ok
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);
/** \brief sorts the employees as requested by the user
 *
 * \param pArrayListEmployee LinkedList*            - List where the employee will be sorted.
 * \return int                                      - (-1) NULL // (0) Employee sorted.
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);
/** \brief Saves the data of the employee in the file data.csv (text mode).
 *
 * \param path char*                     - Direction / Name where the data is save.
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

/** \brief Saves the data of the employee in the file data.csv (binary mode).
 *
 * \param path char*               - Direction / Name where the data is save.
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
/*
 * breif finds the index of and id
 * 	param LinkedList* pArrayListEmployee - pointer to the list
 * 	param int - id to find
 * 	param int - index that found
 * 	return - -1 NULL
 * 	         0 is it was ok
 */
int controller_findId(LinkedList* pArrayListEmployee, int id, int* index);

/*
 * brief Ask the users if they want to keep adding employees
 * param void
 * return 1 - Yes
 *       2 - No
 */
int controller_keepAddEmp(void);

