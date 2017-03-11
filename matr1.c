#include <stdio.h>
#include <stdlib.h>
/*Представление матриц на си*/

void set_elem(double **matr, int row, int col, double elem)
	{
	matr[row][col]=elem;
	}

double get_elem(double **matr, int row, int col)
	{
	return matr[row][col]; 
	}

int scanfile(char filename[], int *n_rows, int *n_cols, int *n_real)
	{
	FILE *file1;
	file1=fopen(filename, "r");
	if (file1==NULL) {
		 printf("File opening error(scanfile)\n");
		 return -1;
		 }

	fscanf(file1, "%3d %3d %6d", n_rows, n_cols, n_real);
	if ((*n_rows==0)|(*n_cols==0)|(*n_real==0)) {
		printf("Invalid matrix info\n");
		return -1;
		}
	
	fclose(file1);
	return 0;
	}

int scanmatrix(char filename[], double *matr[], int n_rows, int n_cols, int n_real)
	{
	double *elem;
	int *col;
	int *row;
	int *helper;
	int i;

	elem=malloc(sizeof(double));
	col=malloc(sizeof(int));
	row=malloc(sizeof(int));
	helper=malloc(sizeof(helper));

	if ((elem==NULL)|(col==NULL)|(row==NULL)|(helper==NULL)) {
		printf("Memory allocation error(scanmatrix)\n");
		return -1;
		}


	FILE *file1;
	file1=fopen(filename, "r");
	if (file1==NULL) {
		printf("File opening error(scanmatrix)\n");
		return -1;
		}

	/*Пропускаем все то, что до количества ненулевых элем.*/
	do {
		fscanf(file1, "%6d ", helper);
	} while (*helper!=n_real);

	free(helper); 
	
	for (i=0; i<=n_real; i++) {
		fscanf(file1, "%3d", row);

		if (*row>n_rows) {
			printf("Row value error\n");
			return -1;
			}

		fscanf(file1, "%3d", col);

		if (*col>n_cols) {
			printf("Col value error\n");
			return -1;
			}

		fscanf(file1, "%7le", elem);
		set_elem(matr, *row, *col, *elem);
		}

	fclose(file1);

	free(row);
	free(col);
	free(elem);
	
	return 0;
	}
	
/*Вычисление Л-нормы*/
int l_norm(double **matr, int n_cols, int n_rows, double *l)
	{
	int i,j;
	double *sum;
	sum=malloc(sizeof(double));
	if (sum==NULL) {
		printf("Memorry allocation error(l_norm)\n");
		return -1;
		}

	for (i=0; i<=n_cols; i++) {
		for (j=0; j<=n_rows; j++) {
			*sum+=get_elem(matr, j, i);
			}
		if (*l<*sum) 
			{*l=*sum;}
		*sum =0;
		}

	free(sum);
	
	return 0;
	}
	

int main(int argc, char *argv[])
	{
	if (argc!=2) {
		printf("Wrong number of arguments\n");
		return 1;
		}

	/*Считывание информации о матрице*/

	int *n_rows;
	int *n_cols;
	int *n_real;

	n_rows=malloc( sizeof(int) );
	n_cols=malloc( sizeof(int) );
	n_real=malloc( sizeof(int) );

	if ((n_real==NULL)|(n_rows==NULL)|(n_cols==NULL)) {
		printf("Memory allocation error (main)\n");
		return 1;
		}
	
	int err;
	err=scanfile(argv[1], n_rows, n_cols, n_real);
	if (err == -1) 
		return 1;
	
	/*Считывание матрицы*/
	
	double **matr;
	double *l;
	int i;
	
	matr=malloc( (sizeof(double)) * (*n_rows));
	for(i=0; i<=*n_rows; i++) {
		matr[i]=malloc(sizeof(double) * (*n_cols));
		}

	l=malloc( sizeof(double) );

	if ((l==NULL)|(matr==NULL)) {
		printf("Memory allocation error(main)\n");
		return 1;
		}

	err=scanmatrix(argv[1], matr, *n_rows, *n_cols, *n_real);	
	if (err == -1)
		return 1;
	/*Работа функций*/

	err=l_norm(matr, *n_cols, *n_rows, l);
	if (err == -1)
		return 1;

	free(matr);
	for(i=0; i<=*n_rows; i++) {
		free(matr[i]);
		}
	free(n_cols);
	free(n_rows);
	free(n_real);

	printf("L norm =%le",*l);

	free(l);
	return 0;
	}


