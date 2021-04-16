#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "baseinfo.h"
#include "modifyrecord.h"

int modifyrecord(FILE *fp,int temp)
{
	if(temp==1)
	{
		return 0;
	}
	struct employee emp;
    long int size = sizeof(emp);
	system("cls");
	char empname[50];
	char contAnother = 'y';
	int flag=0;
	

	while (contAnother == 'y') 
	{
		char ch;
		printf("\nEnter employee name to modify : ");
		scanf("%s", empname);

		rewind(fp);

		// While File is open
		while (fread(&emp, size, 1, fp) == 1) 
		{
			// Compare the employee name with ename
			if (strcmp(emp.name, empname) == 0) 
			{
				flag=1;
				printf("\nEnter new name:");
				scanf("%s", emp.name);
				printf("\nEnter new age :");
				scanf("%d", &emp.age);
				printf("\nEnter new salary :");
				scanf("%f", &emp.salary);
				printf("\nEnter new EMP-ID :");
				scanf("%d", &emp.id);

				fseek(fp, -size, SEEK_CUR);
				fwrite(&emp, size, 1, fp);
				break;
			}
		}
		if(flag!=1)
		{
			printf("Requested data does not exist\n");
		}

		// Ask for modifying another record
		printf("\nWant to modify another record (Y/N) :");
		while ((ch=(getchar()) )!= '\n');
		scanf("%c", &contAnother);
	}
}

