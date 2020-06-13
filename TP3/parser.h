/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* - file to open
 * \param pArrayListEmployee LinkedList*
 * \return 1 - null
 *         0 - OK
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *\param path char* - file to open
 * \param pArrayListEmployee LinkedList*
 * \return 1 - null
 *         0 - OK
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
