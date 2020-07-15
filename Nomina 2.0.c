#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/*Este programa calcula los  sueldos de una nomina de empleados 
Al finalizar el programa captura de la nómina y generar un reporte con lo
siguiente :
* Total de nómina de la empresa
* Los sueldos ordenados de menor a mayor
* Cantidad de empleados capturados
* Promedio de sueldo de la nómina
* Cantidad de empleados con un sueldo superior al promedio*/

int main()
{
int sueldo[100];
	char op;
	int i,j, D, arc, empleados=0;
	float promedio, suma=0;

	printf("\nCuantos sueldos desea ingresar?: ");
	scanf("%i", &D);

	if (D > 0 && D <= 100) {
		do {
			for (i = 0; i < D; i++) {

				system("cls");

				printf("Ingresa el sueldo del empleado %i: ", i + 1);
				scanf("%i", &sueldo[i]);
				suma += sueldo[i];

				printf("\nDesea introducir un sueldo? [s/n]: ");
				fflush(stdin);
				while (getchar() != '\n');
				scanf("%c", &op);
				if (op == 'n' || op == 'N') {
					break;
				}

			}

		} while (op == 's'||op == 'S');

		system("cls");

		//-------------------------Total de nómina de la empresa-----------------------
		printf("\nTOTAL DE NOMINA: %.2f", suma);
		//-----------------------------------------------------------------------------

		//------------------------Sueldos ordenados de menor a mayor------------------
		for (i = 0; i < D; i++)
		for(j = i + 1; j < D; j++)
			if (sueldo[i] > sueldo[j]) {
				arc = sueldo[i];
				sueldo[i] = sueldo[j];
				sueldo[j] = sueldo[i];
		}

		printf("\nLISTA ORDENADA DE SUELDOS");
		for (i = 0; i < D; i++) {
			printf("\n%i", sueldo[i]);
		}
		//-----------------------------------------------------------------------------

		//-----------------------Cantidad de empleados capturados----------------------
		empleados = empleados + i;
		printf("\nCANTIDAD DE EMPLEADOS: %i", empleados);
		//-----------------------------------------------------------------------------

		//---------------------Promedio de sueldo de la nómina-------------------------
		promedio = suma / D;
		printf("\nPROMEDIO DE SUELDO: %.2f", promedio);
		//-----------------------------------------------------------------------------

		//----------Cantidad de empleados con un sueldo superior al promedio--------
		if (sueldo[i] > promedio) {
			printf("\nCANTIDAD DE EMPLEADOS CON SUELDO SUPERIOR AL PROMEDIO: %i", sueldo[i]);
		}
		//-----------------------------------------------------------------------------

	}
	else {
		printf("\nNumero de sueldos a ingresar no valido.\n\nSolo se permite ingresar hasta 100 sueldos.");
	}

	system("pause>null");
	return 0;
}
