/*
** EPITECH PROJECT, 2017
** my_sort_int_array.c
** File description:
** sort the array
*/

void	my_sort_int_array(int *array, int size)
{
	int i = 0;
	int tmp = 0;
	int sort = 1;

	for (int j = 1; j < size; ++j) {
		if (array[i] > array[j]) {
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			sort = 0;
		}
		i++;
	}
	if (sort == 1)
		return;
	else
		my_sort_int_array(array, size);
}
