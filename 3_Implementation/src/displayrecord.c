#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "baseinfo.h"
#include "displayrecord.h"

int displayrecord(FILE *fp,int flag)
{
	if(flag!=1)
	{
	    struct employee emp;
        long int size = sizeof(emp);
	    system("cls");

	    // sets pointer to start5
	    // of the file
	    rewind(fp);
	    printf("\n==========================================================");
	    printf("\nNAME\t\tAGE\t\tSALARY\t\t\tID\n");
	    printf("==========================================================\n");

	    while (fread(&emp, size, 1, fp) == 1)
	    {
		    printf("\n%s\t\t%d\t\t%.2f\t%10d",emp.name, emp.age, emp.salary, emp.id);
	    }

	    printf("\n\n\n\t");	
	    system("pause");
	}
	else
	{
		return 0;
	}
}

