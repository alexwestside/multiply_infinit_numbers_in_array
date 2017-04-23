#include <iostream>

void ft_error(int id)
{
	if (id == 1)
	{
		std::cout << "Please give me 2 files!";
		exit(0);
	}
	if (id == 2)
	{
		std::cout << "Can't open FILE!";
		exit(0);
	}
	if (id == 3)
	{
		std::cout << "Can't allocate MEMORY!";
		exit(0);
	}
}

/**
 * Function convert character to integer
 */

int atoi_char(char c)
{
	int num = 0;
	num = c - '0';
	return (num);
}

void mult_infinit(int *arr, char *s1, char *s2, size_t len)
{
	int i;
	int j;
	int k;
	int num;
	int n;
	size_t len1;
	size_t len2;

	i = -1;
	n = 0;
	len1 = strlen(s1);
	len2 = strlen(s2);
	size_t sl1 = len1 - 1;
	size_t sl2 = len2 - 1;
	while (++i < len1)
	{
		j = -1;
		k = n;
		sl1 = len1 - 1;
		while (++j < len2)
		{
			num = atoi_char(s1[sl1]) * atoi_char(s2[sl2]);
			if (arr[k] + num >= 10)
			{
				if ((arr[k + 1] + (arr[k] + num) / 10) >= 10)
				{
					arr[k + 2] = (arr[k + 1] + (arr[k] + num) / 10) / 10;
					arr[k + 1] = (arr[k + 1] + (arr[k] + num) / 10) % 10;
				}
				else
				{
					arr[k + 1] = arr[k + 1] + (arr[k] + num) / 10;
					arr[k] = (arr[k] + num) % 10;

				}
			}
			else
				arr[k] = arr[k] + num;
			k++;
			sl1--;
		}
		n++;
		sl2--;
	}
}

void read_file(char **str, char*path)
{
	FILE *fp;
	size_t len = 0;

	fp = fopen(path, "r");
	if (fp)
		getline(&(*str), &len, fp);
	else
		ft_error(2);
}

int main(int ac, char **av)
{
	char *s1;
	char *s2;
	size_t len;
	int *arr;

	if (ac == 3)
	{
		read_file(&s1, av[1]);
		read_file(&s2, av[2]);
		len = strlen(s1) + strlen(s2);
		arr = (int *)malloc(sizeof(int) * len);
		bzero(arr, len * sizeof(int));
//		memset(arr, 0, len * sizeof(int));
		mult_infinit(arr, s1, s2, len);

	}
	else
		ft_error(1);





}