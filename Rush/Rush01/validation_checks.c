void	reverse_int_array(int *array, int size);
int		array_element(int *row);
void	get_column(int column_array[4], int array[4][4], int column_index);

/*
1. Checks if the row passed contains the correct number of visible boxes
2. "value" is the number obtain from the clues
3. "tab" can represent either a row or a column
 */
int	check(int *tab, int value)
{
	int	max_seen;
	int	index;
	int	visible_count;

	index = 1;
	max_seen = tab[0];
	visible_count = 1;
	while (visible_count < 4)
	{
		if (tab[visible_count] > max_seen)
		{
			index++;
			max_seen = tab[visible_count];
		}
		visible_count++;
	}
	if (index == value && is_element_in_array(tab) == 0)
		return (1);
	else
		return (0);
}

/*
1. Reverses the row/column, checks it, and then reverses it back to its original order.
2. Allows the same check function to be used to verify both directions of a row/column
*/
int	check_reverse(int *row, int value)
{
	int	result;

	reverse_int_array(row, 4);
	result = check(row, value);
	reverse_int_array(row, 4);
	return (result);
}

/*
 * Calls the check and check_reverse functions on each row
 * value[n] is the value passed by the user for this row
 */
int	verify_rows(int array[4][4], int *values)
{
	if (check(array[0], values[8]) == 0 || check_reverse(array[0], values[12]) == 0)
		return (0);
	if (check(array[1], values[9]) == 0 || check_reverse(array[1], values[13]) == 0)
		return (0);
	if (check(array[2], values[10]) == 0 || check_reverse(array[2], values[14]) == 0)
		return (0);
	if (check(array[3], values[11]) == 0 || check_reverse(array[3], values[15]) == 0)
		return (0);
	return (1);
}

/*
 * Calls the check and check_reverse functions on each column
 * value[n] is the value passed by the user for this column
 * get_column is used to populate test_array with all the values
 * of the column.
 */
int	verify_columns(int array[4][4], int *values)
{
	int	test_array[4];

	get_column(test_array, array, 0);
	if (check(test_array, values[0]) == 0 || check_reverse(test_array, values[4]) == 0)
		return (0);
	get_column(test_array, array, 1);
	if (check(test_array, values[1]) == 0 || check_reverse(test_array, values[5]) == 0)
		return (0);
	get_column(test_array, array, 2);
	if (check(test_array, values[2]) == 0 || check_reverse(test_array, values[6]) == 0)
		return (0);
	get_column(test_array, array, 3);
	if (check(test_array, values[3]) == 0 || check_reverse(test_array, values[7]) == 0)
		return (0);
	return (1);
}

/*
 * Main function that calls the row verification function
 * followed by the column verification function
 */
int	verify(int array[4][4], int *values)
{
	if (verify_rows(array, values) == 0 || verify_columns(array, values) == 0)
		return (0);
	return (1);
}
