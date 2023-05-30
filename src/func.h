#ifndef FUNC_H
#define FUNC_H

/******************************************************************************/
/* Includes                                                                   */
/******************************************************************************/
#include "header.h"

/******************************************************************************/
/* FUNCTIONS                                                                  */
/******************************************************************************/

/** Werte definieren **/
void queryvalues(uint32_t *num_rows, uint32_t *num_cols)
{
        printf("Bitte gebe die gewünschten Datensätze ein (mind. 1 ):\n");
        scanf("%u", num_rows);
        printf("Bitte gebe die gewünschten Messwerte ein (mind. 1 ):\n");
        scanf("%u", num_cols);
}

/** Konsolen Output **/

void printWert(DataBase_t **array, unsigned int num_rows, unsigned int num_cols)
    {
        for(unsigned int i = 0; i < num_rows; i++)
        {

        printf("---Datensatz---:\n");
        printf("Der Sensor: %s an Position ",  array[i]->infovalue.SensorName);
        switch (array[i]->infovalue.machinecomponent)
        {
            case MACHINE_COMPONENT_FRONT:
            {
             printf("Vorne");
             break;
             }
            case MACHINE_COMPONENT_MIDDLE:
            {
             printf("Mitte");
             break;
             }
             case MACHINE_COMPONENT_BACK:
             {
             printf("Hinten");
             break;
             }
             default:
            {
             printf("Unbekannt!");
             break;
            }
        }
        printf(" wurde mit dem Wert %s am %u.%u.%u kalibriert\n",   array[i]->infovalue.SensorCalibration,
                                                                    array[i]->infovalue.checkdate.CheckDay,
                                                                    array[i]->infovalue.checkdate.CheckMonth,
                                                                    array[i]->infovalue.checkdate.CheckYear);

            for(unsigned int j = 0; j < num_cols; j++)
            {
               printf("Bei der Messung wurde folgender Wert erzielt: %u\n", array[i][j].SensorValue);
            }
        printf("--- Ende Datensatz ---\n");
        }
    }

/** Array für Matrix [i], als Speicher für Sensorinformationen **/
DataBase_t *createInfoBase(uint32_t num_rows)
    {

    DataBase_t *InfoBase = (DataBase_t*)malloc(num_rows * sizeof(DataBase_t));

    DataBase_t info;
    printf("Bitte gebe einen Sensor-Namen ein:\n");
    scanf("%s", (char *)&info.infovalue.SensorName);
    printf("Bitte gebe eine Sensor-Position ein (1=Vorne ; 2=Mitte ; 3=Hinten):\n");
    scanf("%u", (unsigned int *)&info.infovalue.machinecomponent);
    printf("Bitte gebe einen Kalibrierungswert ein:\n");
    scanf("%s", (char *)&info.infovalue.SensorCalibration);
    printf("Bitte gebe einen Kalibrierungs-Tag ein:\n");
    scanf("%u", (uint32_t *)&info.infovalue.checkdate.CheckDay);
    printf("Bitte gebe einen Kalibrierungs-Monat ein:\n");
    scanf("%u", (uint32_t *)&info.infovalue.checkdate.CheckMonth);
    printf("Bitte gebe einen Kalibrierungs-Jahr ein:\n");
    scanf("%u", (uint32_t *)&info.infovalue.checkdate.CheckYear);

    *InfoBase = info;

    return InfoBase;
    }

/** Array für Matrix [j], als Speicher für alle Datenwerte **/
DataBase_t *CreateArrayValue(uint32_t num_cols)
    {
    DataBase_t *DataBase = (DataBase_t*)malloc(num_cols * sizeof(DataBase_t));

            printf("Bitte gebe den Wert ein\n");
            DataBase_t SensorValue;
            scanf("%d", (int*)&SensorValue);
            *DataBase= SensorValue;

    return DataBase;
    }

/** free Array **/
DataBase_t *freeInfoBase(DataBase_t *InfoBase)
{
    if (NULL != InfoBase)
    {
        free(InfoBase);
    }

    return NULL;
}

/** Matrix für [i]= InfoBase und [j]= DataBase**/
DataBase_t **createDataBase(unsigned int num_rows, unsigned int num_cols)
    {

        DataBase_t **DataBook = (DataBase_t**)malloc(num_rows * sizeof(DataBase_t*));

         for(unsigned int i = 0; i < num_rows; i++)
        {
                DataBook[i] = createInfoBase(num_rows);
                 for(unsigned int j = 0; j < num_cols; j++)
                 {
                 DataBook[i][j] = *CreateArrayValue(num_cols);
                 }
        }

         return DataBook;
}

/** free Matrix **/
DataBase_t **freeDataBook(DataBase_t **DataBook, unsigned int num_rows, unsigned int num_cols)
{
    if (NULL != DataBook)
    {
        for (unsigned int i = 0; i < num_rows; i++)
        {
             for (unsigned int j = 0; j < num_cols; j++)
             {
                free(&DataBook[i][j]);
             }
             free(&DataBook[i]);
        }
    }
    return NULL;
}

#endif
