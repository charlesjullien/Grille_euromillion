#include <string.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int	compare_arrays(int	*array, int	*tab)
{
	int	i;
	int	verif;
	
	i = 0;
	verif = 8;
	while (array[i] == tab[i])
		i++;
	if (i == verif)
		return (0);
	else
		return (1);
}

int check_prev_grids(int	*tab)
{
    FILE* fichier = NULL;
    int    c = 0;
    int        array[8];
    char     *str;
    int        i = 0;
    int        j = 0;
    int			count = 0;
	int			digit = 0;
    if (!(str = malloc(sizeof(char)* 28)))
        return (0);
 
    fichier = fopen("resultats.txt", "r");
 
    if (fichier != NULL)
    {
		while (c != EOF)
		{
			j = 0;
			i = 0;
			count = 0;
        	while (c != 'S')
        	{
            	c = fgetc(fichier);
            	str[j] = c;
            	j++;
        	}
        	str[j] = '\0';
			j = 0;
			while (count < 8)
			{
				while (str[j] >= '0' && str[j] <= '9')
				{
					digit = digit * 10 + str[j] - 48;
					j++;
				}
				array[i] = digit;
				digit = 0;
				i++;
				j++;
				count++;
			}
            c = fgetc(fichier);
            c = fgetc(fichier);
			if (compare_arrays(array, tab) == 0)
				return (0);
		}
		fclose(fichier);
    }
	return (1);
}
