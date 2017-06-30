/**
 *bubble sort----->int
 *function
 *15 ^ 0 == 1111 ^ 0000
 *
 *		a b
 *	a = a ^ b;
 *	b = a ^ b; // == a ^ (b ^ b); == a ^ 0;
 *	a = a ^ b;// == (a ^ a) ^ b
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM 	10

static void bubbule_sort(int *arr, int n)
{
	int i, j;		
//	int tmp;

	for (i = 0; i < n-1; i++) {//times
		for (j = 0; j < n-i-1; j++) {
			if (arr[j] > arr[j+1]) {
				//swap
				arr[j] = arr[j] ^ arr[j+1];
				arr[j+1] = arr[j] ^ arr[j+1];
				arr[j] = arr[j] ^ arr[j+1];
			}
		}
	}
}

typedef int (*fun_t)(const void *, const void *);
static void bubble_another(void *arr, int size, int n, fun_t f)
{
	int i, j;
	char *buf = malloc(size);

	for (i = 0; i < n-1; i++) {
		for (j = 0; j < n-i-1; j++) {
			if (f((char *)arr+j*size, (char *)arr+(j+1)*size) > 0) {
				memcpy(buf, (char *)arr+j*size, size);	
				memcpy((char *)arr+j*size,(char *)arr+(j+1)*size, size);
				memcpy((char *)arr+(j+1)*size, buf, size);
			}
		}
	}

}

//compare function
int number_cmp(const void *data1, const void *data2)
{
	const int *d1 = data1; 
	const int *d2 = data2;

	return *d2-*d1;
}

int str_cmp(const void *data1, const void *data2)
{
	char **d1 = (char **)data1;
	char **d2 = (char **)data2;
	
	return strcmp(*d2,*d1);
}

//./a.out hello world everyone NULL
int main(int argc, char **argv/*char *argv[]*/)
{
	int i;

	bubble_another(argv, sizeof(char *), argc, str_cmp);

	for (i = 0; i < argc; i++) {
		puts(argv[i]);
	}


#if 0
	int arr[NUM] = {};
	int i;

	srand(getpid());
	//srand(time(NULL));

	for (i = 0; i < NUM; i++) {
		arr[i] = rand() % 100;
		printf("%d ", arr[i]);	
	}
	printf("\n");

	//bubbule_sort(arr, NUM);
	bubble_another(arr, sizeof(int), NUM, number_cmp);

	//traval
	printf("************after sort************\n");
	for (i = 0; i < NUM; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
#endif
	return 0;
}





