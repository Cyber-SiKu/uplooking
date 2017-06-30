#include <stdio.h>

static void max(int (*arr)[2], int n, int *maxret)
{
	int i, j;	
	int max = arr[0][0];

	for (i = 0; i < n; i++) {
		for (j = 0; j < 2; j++) {
			if (i==0 && j==0)
				continue;
			if (max < arr[i][j])
				max = arr[i][j];
		}
	}
	*maxret = max;
	
}

int main(void)
{
	int arr[3][2] = {
		{1,2},
		{3,4},
		{5,6}
	};
	int i, j;		
	int ret;

	printf("arr[0][3]:%d, *(*arr+3):%d, arr[1][1]:%d\n", \
			arr[0][3], *(*arr+3), arr[1][1]);

	for (i = 0; i < 3; i++)	 {
		for (j = 0; j < 2; j ++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	max(arr, 3, &ret);
	printf("the max element is %d\n", ret);

	return 0;
}



