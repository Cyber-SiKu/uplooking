//有40个人围程1圏  编号1～40
#include <stdio.h>

#define NUM	40

static void traval_arr(int *arr, int n)
{
	int i;

	for (i = 0; i < n; i++)	
		printf("%d ", arr[i]);
	printf("\n");
}

int main(void)
{
	int array[NUM] = {};//0	live	1 quit
	int quitnr = 0;
	int i, count = 0;

	for (i = 0; quitnr < NUM-1; i = (i+1)%NUM) {
		if (array[i] == 0) {
			count ++;
			if (count == 3) {
				array[i] = 1;
				traval_arr(array, NUM);
				quitnr ++;
				count = 0;
				sleep(1);
			}	
		}	
	}

	for (i = 0; i < NUM; i++)
		if (array[i] == 0) {
			printf("*******%d alive******\n", i+1);
			break;
		}


	return 0;
}




