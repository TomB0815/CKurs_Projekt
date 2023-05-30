/******************************************************************************/
/* Projekt-Name:    Messwerte von Sensoren speichern                          */
/* Ersteller:       Tom                                                       */
/* Bemerkung:       Erstellt auf Basis des Udemy-C-Kurses                     */
/* Start-Datum:     04. Mai 2023                                              */
/* Version:         2          Änderungsdatum: 24.05.2023                     */
/******************************************************************************/

#include "header.h"
#include "func.h"
#include "file.h"

int main()
{
    uint32_t num_rows = 0;
    uint32_t num_cols = 0;

    queryvalues(&num_rows, &num_cols);
    DataBase_t **DataBook = createDataBase(num_rows, num_cols);
    printWert(DataBook, num_rows, num_cols);

    saveDataBook(num_rows, num_cols, DataBook);

    DataBook = freeDataBook(DataBook, num_rows, num_cols);

    return 0;
}
