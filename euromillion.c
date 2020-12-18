#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int check_prev_grids(int	*tab);

void	ft_putnbr(int nb)
{
	char		c;
	long int	n;

	n = nb;
	if (n < 0)
	{
		n = n * (-1);
		write(1, "-", 1);
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
	}
	c = (n % 10) + 48;
	write(1, &c, 1);
}

void	tab_init(int *tabnum, int *tabstar)
{
	int		i;

	i = 0;
	while (i < 50)
	{
		tabnum[i] = 0;
		i++;
	}
	i = 0;
	while (i < 12)
	{
		tabstar[i] = 0;
		i++;
	}
}

int		check_if_unique(int	*tab)
{
	int		i;
	int		j;

	i = 0;
	while (i < 5)
	{
		j = i + 1;;
		while (j < 5)
		{
				if (tab[i] == tab[j])
					return (0);
				j++;
		}
		i++;
	}
	return (1);
}

void	get_numbers(int	*tabnum, int *tabstar)
{
	int		minnum;
	int		maxnum;
	int		minstar;
	int		maxstar;
	int		numarray[5];
	int		s1;
	int		s2;
	int		i;
	int		j;

	minnum = 1;
	maxnum = 50;
	minstar = 1;
	maxstar = 12;
	i = 0;
	srand((int)time(NULL));
	while (i < 5)
	{
		numarray[i] = 0;
		i++;
	}
	s1 = (rand() % (maxstar - minstar + 1)) + minstar;
	s2 = (rand() % (maxstar - minstar + 1)) + minstar;
	while (check_if_unique(numarray) == 0)
	{
		i = 0;
		while (i < 5)
		{
			numarray[i] = (rand() % (maxnum - minnum + 1)) + minnum;
			i++;
		}
	}
	while (s1 == s2)
	{
		s1 = (rand() % (maxstar - minstar + 1)) + minstar;
		s2 = (rand() % (maxstar - minstar + 1)) + minstar;
	}
	i = 0;
	while (i < 50)
	{
		j = 0;
		while (j < 5)
		{
			if (i == numarray[j] - 1)
				tabnum[i] = numarray[j];
			j++;
		}
		i++;
	}
	i = 0;
	while (i < 12)
	{
		if (i == s1 - 1)
			tabstar[i] = s1;
		if (i == s2 - 1)
			tabstar[i] = s2;
		i++;
	}
}

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	print_numbers(int *tabnum, int *tabstar)
{
	int		i;
	int		line;

	i = 0;
	ft_putstr("*** Voici les numéros gagnants du prochain tirage de l'Euromillion ***\n");
	ft_putstr("--> La grille avec les 5 numéros de 1 à 50 :\n");
	while (i < 50)
	{
		line = 0;
		ft_putstr("\n\t\t\t");
		while (line < 5)
		{
			if (tabnum[i] != 0 && tabnum[i] < 10)
			{
				ft_putstr("  ");
				ft_putnbr(tabnum[i]);
			}
			else if (tabnum[i] != 0 && tabnum[i] >= 10)
			{
				ft_putstr(" ");
				ft_putnbr(tabnum[i]);
			}
			else
				ft_putstr("  •");

			line++;
			i++;
		}
	}
	i = 0;
	ft_putstr("\n\n--> La grille des numéros étoile : \n");
	while (i < 12)
	{
		line = 0;
		ft_putstr("\n\t\t\t");
		while (line < 4)
		{
			if (tabstar[i] != 0 && tabstar[i] < 10)
			{
				ft_putstr("  ");
				ft_putnbr(tabstar[i]);
			}
			else if (tabstar[i] != 0 && tabstar[i] >= 10)
			{
				ft_putstr(" ");
				ft_putnbr(tabstar[i]);
			}
			else
				ft_putstr("  •");
			line++;
			i++;
		}
	}
	ft_putstr("\n\n*€€ €€€ €€€.€€*|Tous les gagnants ont joués|*€€ €€€ €€€.€€*");
}

int main ()
{
	int		tabnum[50];
	int		tabstar[12];
	int		tab[8];
	int		i;
	int		j;

	i = 0;
	j = 0;
	tab_init(tabnum, tabstar);
	get_numbers(tabnum, tabstar);
	while (i < 5)
	{
		while (tabnum[j] == 0)
			j++;
		tab[i] = tabnum[j];
			i++;
			j++;
	}
	tab[i] = 0;
	i++;
	j = 0;
	while (i < 8)
	{
		while (tabstar[j] == 0)
			j++;
		tab[i] = tabstar[j];
		i++;
		j++;
	}
	if (check_prev_grids(tab) == 1)
		print_numbers(tabnum, tabstar);
	else
		ft_putstr("La grille générée à l'execution du programme n'a pas pus s'afficher, car elle est déjà sortie lors d'un tirage dans le passé. Veuillez ré-executer le programme pour générer une nouvelle grille.");
	return (0);
}
