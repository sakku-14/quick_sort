#include <stdio.h>

void
	display(int x[], int len)
{
	int i = 0;
	while (i < len)
		printf("%d-", x[i++]);
	printf("\n");
}

void
	swap(int x[], int l, int r)
{
	int tmp;

	tmp = x[l];
	x[l] = x[r];
	x[r] = tmp;
}

void
	q_sort(int x[], int left, int right)
{
	int pivot, l, r;

	l = left;
	r = right;
	pivot = x[l];
	while (1)
	{
		while (x[l] < pivot)
			l++;
		while (x[r] > pivot)
			r--;
		if (l >= r)
			break ;
		swap(x, l, r);
		l++;
		r--;
	}
	display(x, 16);

	if (left < l - 1)
		q_sort(x, left, l - 1);
	if (r + 1 < right)
		q_sort(x, r + 1, right);
}

int
	main(void)
{
	int x[] = {55, 66, 32, 90, 1, 6, 33, 41, 38, 54, 1, 11, 1, 0, 34, 22};
	display(x, 16);
	q_sort(x, 0, 15);
	display(x, 16);
}
