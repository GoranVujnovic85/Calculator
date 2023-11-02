#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef enum
{
    sabiranje = '+',
    oduzimanje = '-',
    mnozenje = '*',
    deljenje = '/'

} Operation;


int main()
{
    char string[100];
    char *cursor = string;
    int rezultat = 0;
    Operation currentOperator = '+';

    printf("Unesi izraz koji zelis izracunati: ");
    fflush(stdout);
    fgets(string, sizeof(string), stdin);

    string[strcspn(string, "\n")] = '\0';

    while (*cursor != '\0')
    {
        if (*cursor == '+' || *cursor == '-')
        {
            currentOperator = *cursor;

            cursor++;
        }

        int x = strtol(cursor, &cursor, 10);

        while (*cursor != '\0' && (*cursor == '*' || *cursor == '/'))
        {
            char operatorPrioritet = *cursor;

            cursor++;

            int y = strtol(cursor, &cursor, 10);

            switch(operatorPrioritet)
            {
            	case mnozenje:
            	{
            		x *= y;
            		break;
            	}
            	case deljenje:
            	{
            		 if (y != 0)
            		 {
            			 x /= y;
            			 break;
            		 }
            		 else
            		 {
            			 printf("Deljenje nulom nije dozvoljeno.\n");
            		     return 1;
            		 }
            	}
            }
        }

        switch(currentOperator)
        {
        	case sabiranje:
        	{
        		rezultat += x;
        		break;
        	}
        	case oduzimanje:
        	{
        		rezultat -= x;
        		break;
        	}
        }
    }

    printf("Rezultat je: %d\n", rezultat);
    fflush(stdout);
    return 0;
}
