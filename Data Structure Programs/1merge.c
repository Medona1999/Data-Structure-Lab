#include <stdio.h>
void main()
{
int ARRAY1[20], ARRAY2[20], ARRAY3[60], m, n, i, j, k = 0;
printf("\n ENTER SIZE OF ARRAY 1 : ");
scanf("%d", &m);
printf("\n ENTER SORTED ELEMENTS OF ARRAY 1: \n");
for (i = 0; i < m; i++)
{
scanf("%d", &ARRAY1[i]);
}
printf("\n ENTER SIZE OF ARRAY 2: ");
scanf("%d", &n);13
printf("\n ENTER SORTED ELEMENTS OF ARRAY 2: \n");
for (i = 0; i < n; i++)
{
scanf("%d", &ARRAY2[i]);
}
i=0; j=0;
while (i < m && j < n)
{
if (ARRAY1[i] < ARRAY2[j])
{
ARRAY3[k] = ARRAY1[i];
i++;
}
else
{
ARRAY3[k] = ARRAY2[j];
j++;
}
k++;
}
if (i >= m)
{
while (j < n)
{
ARRAY3[k] = ARRAY2[j];
j++;
k++;
}
}
if (j >= n)
{
while (i < m)
{
ARRAY3[k] = ARRAY1[i]; i++;
k++;
}
}
printf("\n ARRAY 1 : "); for(int i=0;i<m;i++)
{
printf(" %d ",ARRAY1[i]);
}
printf("\n ARRAY 2 : "); for(int i=0;i<n;i++)
{14
printf(" %d ",ARRAY2[i]);
}
printf("\n ARRAY AFTER MERGING: \n"); for (i = 0; i < m + n; i++)
{
printf(" %d ", ARRAY3[i]);
}
}