#ifndef FILE_H
#define FILE_H


#include "header.h"

void saveDataBook(unsigned int num_rows, unsigned int num_cols, DataBase_t **DataBook)
{

char PROJECT_DIR[] = "C:/temp/C/Code/LearnC-Project/LearnC/";
char output_filepath[100] = {'\0'};
strncpy(output_filepath, PROJECT_DIR, 100);
strncat(output_filepath, "/filesystem/Output.txt", 50);

FILE *fp_out = fopen(output_filepath, "w");

        for (unsigned int i = 0; i < num_rows; i++)
        {
            fprintf(fp_out, "Datensatz Nummer %u wurde mit folgenden Daten angelegt\n", i);
            fprintf(fp_out, "----\n");
            fprintf(fp_out, "Sensor-Name: %s\n", DataBook[i]->infovalue.SensorName);

            switch (DataBook[i]->infovalue.machinecomponent)
            {
                case MACHINE_COMPONENT_FRONT:
                {
                    fprintf(fp_out, "Sensor-Position: Vorne\n");
                    break;
                }
                case MACHINE_COMPONENT_MIDDLE:
                {
                    fprintf(fp_out, "Sensor-Position: Mitte\n");
                    break;
                }
                case MACHINE_COMPONENT_BACK:
                {
                    fprintf(fp_out, "Sensor-Position: Hinten\n");
                    break;
                }
                default:
                {
                    fprintf(fp_out, "Sensor-Position: Unbekannt\n");
                    break;
                }
            }

            fprintf(fp_out, "Sensor-Kalibrierungswert: %s\n", DataBook[i]->infovalue.SensorCalibration);

                fprintf(fp_out, "Mit folgenden Werten:\n");
                for (unsigned int j = 0; j < num_cols; j++)
                {
                    fprintf(fp_out, "Wert %u: %d\n", j, DataBook[i][j].SensorValue);
                }
            fprintf(fp_out, "----\n\n");
        }

    fclose(fp_out);
}

#endif
