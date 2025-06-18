#include <stdio.h>

int main()
{
	int x, y, z;
	int *px, *py, *pz, *tmp;

	px = &x;
	py = &y;
	pz = &z;

	scanf("%d %d %d", px, py, pz);
	x = *px;
	y = *py;
	z = *pz;
	tmp = px;
	px = pz;

	pz = py;
	py = tmp;

	printf("%d %d %d", *px, *py, *pz);
	return 0;
}