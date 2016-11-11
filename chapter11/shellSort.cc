/*
file name: shellsort.cpp
purpose: 
	希尔排序（或“递减增量排序”）类似于插入排序，但它将元素向后移动h个位置而不是1个位置。
	h的值开始很大，然后慢慢缩小。
creator: Guangwei Jiang
create time: 2012-08-06

modify history:

notes:
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE		50

// notes: bigrand should at least 64bits

void shellsort(int *array_data, int array_size){
    size_t h = array_size;
    while(h > 0){
        if (h < 3){
            h--;
        } else {
            h /= 3;
        }
        for (int i = h; i < array_size; i++) {
            for (j = i; j >= h; j -= h) {
                if (array_data[j-h] < array_data[j])
                    break;
                swap(array_data+j-h, array_data+j);
            }
        }
    }
}


int main()
{
	clock_t start, finish;
	double duration;	
	int *array_data;

	array_data = (int*) malloc (sizeof(int)*ARRAY_SIZE);
	if (array_data == NULL)
	{
		printf("memory(array_bitmap) allocate failed\n");
		goto _free_mem;
	}
	
	printf("Generate the test data...\n");
	gen_random_array(array_data, ARRAY_SIZE);
	//gen_equal_array(array_data, ARRAY_SIZE);
	//gen_increasing_array(array_data, ARRAY_SIZE);

	printf("Sorting data...\n");
	start = clock();
	shellsort(array_data, ARRAY_SIZE);
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;

	// print the data after sorting
	print_array(array_data, ARRAY_SIZE);

	printf("Test data number is %d\n", ARRAY_SIZE);
	printf("the duration is %f seconds\n\n", duration);

_free_mem:
	if (array_data != NULL)
	{
		free(array_data);
		array_data = NULL;
	}

	return 0;
}
