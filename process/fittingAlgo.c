
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int first_fit(int blocks[], int processes[], int m, int n, int result[]) {

	//local variables & arrays
	int number_of_used_blocks = 0;
	int number_of_used_processes = 0;
	int free_mem = 0;
	int *allocating = NULL;
	int *cloneblocks = NULL;

	//initializing arrays
	allocating = (int*)malloc(n * sizeof(int));
	cloneblocks = (int*)malloc(m * sizeof(int));

	//copying array of blocks
	for (int i = 0; i < m; i++) {
		cloneblocks[i] = blocks[i];
	}


	//first_fit algorithm
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < m; i++) {
			if (processes[j] <= cloneblocks[i]) {
				cloneblocks[i] = cloneblocks[i] - processes[j];
				allocating[j] = i;
				break;
			}
		}
	}



	//process measurement
	for (int i = 0; i < n; i++) {
		if (allocating[i] >= 0)
			number_of_used_processes++;
	}

	//block measurement
	for (int i = 0; i < m; i++) {
		if (cloneblocks[i] != blocks[i])
			number_of_used_blocks++;
	}

	//memory measurement
	for (int i = 0; i < m; i++) {
		free_mem += cloneblocks[i];
	}

	//return of results
	result[0] = free_mem;
	result[1] = number_of_used_blocks;
	result[2] = number_of_used_processes;

	return result;
}

int next_fit(int blocks[], int processes[], int m, int n, int result[]) {


	//local variables & arrays
	int number_of_used_blocks = 0;
	int number_of_used_processes = 0;
	int free_mem = 0;
	int *allocating = NULL;
	int *cloneblocks = NULL;

	//initializing arrays
	allocating = (int*)malloc(n * sizeof(int));
	cloneblocks = (int*)malloc(m * sizeof(int));

	//copying array of blocks
	for (int i = 0; i < m; i++) {
		cloneblocks[i] = blocks[i];
	}


	//next_fit algorithm
	int flag = 0;
	for (int j = 0; j < n; j++) {
		int i = 0;

		if (cloneblocks[flag] != blocks[flag])
			i = flag;

		if (flag == m - 1)
			i = 0;

		while (i < m) {
			if (processes[j] <= cloneblocks[i]) {
				cloneblocks[i] = cloneblocks[i] - processes[j];
				allocating[j] = i;
				flag = i;
				break;
			}
			i++;
		}
	}


	//process measurement
	for (int i = 0; i < n; i++) {
		if (allocating[i] >= 0)
			number_of_used_processes++;
	}

	//block measurement
	for (int i = 0; i < m; i++) {
		if (cloneblocks[i] != blocks[i])
			number_of_used_blocks++;
	}

	//memory measurement
	for (int i = 0; i < m; i++) {
		free_mem += cloneblocks[i];
	}

	//return of results
	result[0] = free_mem;
	result[1] = number_of_used_blocks;
	result[2] = number_of_used_processes;

	return result;
}



int worst_fit(int blocks[], int processes[], int m, int n, int result[]) {


	//local variables & arrays
	int number_of_used_blocks = 0;
	int number_of_used_processes = 0;
	int free_mem = 0;
	int *allocating = NULL;
	int *cloneblocks = NULL;

	//initializing arrays
	allocating = (int*)malloc(n * sizeof(int));
	cloneblocks = (int*)malloc(m * sizeof(int));

	//copying array of blocks
	for (int i = 0; i < m; i++) {
		cloneblocks[i] = blocks[i];
	}


	//worst_fit algorithm
	for (int j = 0; j < n; j++) {
		int Max_block = -1;
		for (int i = 0; i < m; i++) {
			if (cloneblocks[i] >= processes[j]) {
				if (Max_block == -1)
					Max_block = i;
				else if (cloneblocks[i] > cloneblocks[Max_block])
					Max_block = i;
			}
		}
		if (Max_block != -1) {
			allocating[j] = Max_block;
			cloneblocks[Max_block] = cloneblocks[Max_block] - processes[j];
		}
	}


	//process measurement
	for (int i = 0; i < n; i++) {
		if (allocating[i] >= 0)
			number_of_used_processes++;
	}

	//block measurement
	for (int i = 0; i < m; i++) {
		if (cloneblocks[i] != blocks[i])
			number_of_used_blocks++;
	}

	//memory measurement
	for (int i = 0; i < m; i++) {
		free_mem += cloneblocks[i];
	}

	//return of results
	result[0] = free_mem;
	result[1] = number_of_used_blocks;
	result[2] = number_of_used_processes;

	return result;
}


int best_fit(int blocks[], int processes[], int m, int n, int result[]) {


	//local variables & arrays
	int number_of_used_blocks = 0;
	int number_of_used_processes = 0;
	int free_mem = 0;
	int *allocating = NULL;
	int *cloneblocks = NULL;

	//initializing arrays
	allocating = (int*)malloc(n * sizeof(int));
	cloneblocks = (int*)malloc(m * sizeof(int));

	//copying array of blocks
	for (int i = 0; i < m; i++) {
		cloneblocks[i] = blocks[i];
	}


	//best_fit algorithm
	for (int j = 0; j < n; j++) {
		int Best_block = -1;
		for (int i = 0; i < m; i++) {
			if (cloneblocks[i] >= processes[j]) {
				if (Best_block == -1)
					Best_block = i;
				else if (cloneblocks[i] < cloneblocks[Best_block])
					Best_block = i;
			}
		}
		if (Best_block != -1) {
			allocating[j] = Best_block;
			cloneblocks[Best_block] = cloneblocks[Best_block] - processes[j];
		}
	}


	//process measurement
	for (int i = 0; i < n; i++) {
		if (allocating[i] >= 0)
			number_of_used_processes++;
	}

	//block measurement
	for (int i = 0; i < m; i++) {
		if (cloneblocks[i] != blocks[i])
			number_of_used_blocks++;
	}

	//memory measurement
	for (int i = 0; i < m; i++) {
		free_mem += cloneblocks[i];
	}

	//return of results
	result[0] = free_mem;
	result[1] = number_of_used_blocks;
	result[2] = number_of_used_processes;

	return result;
}



int main(int argc, char *argv[]) {

	//initializing array of blocks with random values(200-600)
	int blocks[10000];

	for (int f = 0; f < 10000; f++) {
		blocks[f] = (rand() % 400) + 200;
	}

	int m = sizeof(blocks) / sizeof(blocks[0]);

	//initializing array of processes with random values(100-300)
	int processes[14000];

	for (int l = 0; l < 14000; l++) {
		processes[l] = (rand() % 200) + 100;
	}


	//local variables & arrays
	double avg_timespent = 0.0;
	int avg_mem = 0, avg_num_blocks = 0, avg_num_processes = 0;
	int result[3] = { 0,0,0 };


	//demonstration of first fit
	for (int j = 5000; j <= 14000; j += 1000) {
		for (int k = 0; k < 5; k++) {

			clock_t begin = clock();
			first_fit(blocks, processes, m, j, result);
			clock_t end = clock();
			double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

			avg_timespent += time_spent;
			avg_mem += result[0];
			avg_num_blocks += result[1];
			avg_num_processes += result[2];

		}

		printf("Average time for FIRST_FIT with dimension: blocks[%d] & processes[%d] is: %.32f\n", m, j, avg_timespent / 5);
		printf("Average number of memory for FIRST_FIT with dimension: blocks[%d] & processes[%d] is: %.d\n", m, j, avg_mem / 5);
		printf("Average number of blocks for FIRST_FIT with dimension: blocks[%d] & processes[%d] is: %.d\n", m, j, avg_num_blocks / 5);
		printf("Average number of processes for FIRST_FIT with dimension: blocks[%d] & processes[%d] is: %.d\n\n\n", m, j, avg_num_processes / 5);

		avg_timespent = 0.0;
		avg_mem = 0;
		avg_num_blocks = 0;
		avg_num_processes = 0;
		result[0] = 0;
		result[1] = 0;
		result[2] = 0;
	}


	//demonstration of next fit
	for (int j = 5000; j <= 14000; j += 1000) {
		for (int k = 0; k < 5; k++) {

			clock_t begin = clock();
			next_fit(blocks, processes, m, j, result);
			clock_t end = clock();
			double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

			avg_timespent += time_spent;
			avg_mem += result[0];
			avg_num_blocks += result[1];
			avg_num_processes += result[2];

		}

		printf("Average time for NEXT_FIT with dimension: blocks[%d] & processes[%d] is: %.32f\n", m, j, avg_timespent / 5);
		printf("Average number of memory for NEXT_FIT with dimension: blocks[%d] & processes[%d] is: %.d\n", m, j, avg_mem / 5);
		printf("Average number of blocks for NEXT_FIT with dimension: blocks[%d] & processes[%d] is: %.d\n", m, j, avg_num_blocks / 5);
		printf("Average number of processes for NEXT_FIT with dimension: blocks[%d] & processes[%d] is: %.d\n\n\n", m, j, avg_num_processes / 5);

		avg_timespent = 0.0;
		avg_mem = 0;
		avg_num_blocks = 0;
		avg_num_processes = 0;
		result[0] = 0;
		result[1] = 0;
		result[2] = 0;
	}


	//demonstration of best fit
	for (int j = 5000; j <= 14000; j += 1000) {
		for (int k = 0; k < 5; k++) {

			clock_t begin = clock();
			best_fit(blocks, processes, m, j, result);
			clock_t end = clock();
			double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

			avg_timespent += time_spent;
			avg_mem += result[0];
			avg_num_blocks += result[1];
			avg_num_processes += result[2];

		}

		printf("Average time for BEST_FIT with dimension: blocks[%d] & processes[%d] is: %.32f\n", m, j, avg_timespent / 5);
		printf("Average number of memory for BEST_FIT with dimension: blocks[%d] & processes[%d] is: %.d\n", m, j, avg_mem / 5);
		printf("Average number of blocks for BEST_FIT with dimension: blocks[%d] & processes[%d] is: %.d\n", m, j, avg_num_blocks / 5);
		printf("Average number of processes for BEST_FIT with dimension: blocks[%d] & processes[%d] is: %.d\n\n\n", m, j, avg_num_processes / 5);

		avg_timespent = 0.0;
		avg_mem = 0;
		avg_num_blocks = 0;
		avg_num_processes = 0;
		result[0] = 0;
		result[1] = 0;
		result[2] = 0;
	}


	//demonstration of worst fit
	for (int j = 5000; j <= 14000; j += 1000) {
		for (int k = 0; k < 5; k++) {

			clock_t begin = clock();
			worst_fit(blocks, processes, m, j, result);
			clock_t end = clock();
			double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

			avg_timespent += time_spent;
			avg_mem += result[0];
			avg_num_blocks += result[1];
			avg_num_processes += result[2];

		}

		printf("Average time for WORST_FIT with dimension: blocks[%d] & processes[%d] is: %.32f\n", m, j, avg_timespent / 5);
		printf("Average number of memory for WORST_FIT with dimension: blocks[%d] & processes[%d] is: %.d\n", m, j, avg_mem / 5);
		printf("Average number of blocks for WORST_FIT with dimension: blocks[%d] & processes[%d] is: %.d\n", m, j, avg_num_blocks / 5);
		printf("Average number of processes for WORST_FIT with dimension: blocks[%d] & processes[%d] is: %.d\n\n\n", m, j, avg_num_processes / 5);

		avg_timespent = 0.0;
		avg_mem = 0;
		avg_num_blocks = 0;
		avg_num_processes = 0;
		result[0] = 0;
		result[1] = 0;
		result[2] = 0;
	}

	return 0;
}
