#include<stdlib.h> 
#include<stdio.h> 
#include<string.h> 
void pt3(FILE* pt1, char* file1, FILE* pt2, char* file2) 
{ 
	FILE  *pt3; 
	char file3[20]; 
	int vet[10]; 
	int i; 
	//............................ 
	pt1=fopen(file1,"r"); 
	if(pt1==NULL) 
	{ 
		printf("file non trovato "); 
		exit(EXIT_FAILURE); 
	} 
	else 
	{ 
		i=0; 
		while(i<5) 
		{ 
			fscanf(pt1, "%d\t", &vet[i]); 
			i++; 
		} 
	} 
	fclose(pt1); 
	//............................ 
	pt2=fopen(file2,"r"); 
	if(pt2==NULL) 
	{ 
		printf("file non trovato "); 
		exit(EXIT_FAILURE); 
	} 
	else 
	{ 
		i=0; 
		while(i<5) 
		{ 
			fscanf(pt2, "%d\t", &vet[i+5]); 
			i++; 
		} 
	} 
	fclose(pt2); 
	//............................ 
	printf("inserire nome del file\n"); 
	scanf("\n%s", file3); 
	pt3=fopen(file3,"w"); 
	if(pt3==NULL) 
	{ 
		printf("file non trovato "); 
		exit(EXIT_FAILURE); 
	} 
	else 
	{ 
		i=0; 
		while(i<10) 
		{ 
			fprintf(pt3, "%d\t", vet[i]); 
			i++; 
		} 
	} 
	fclose(pt3); 
} 
int main() 
{ 
	FILE *pt1,*pt2; 
	char file1[20], file2[20]; 
	int v1[5], v2[5]; 
	int i; 
	//------------------------------------------------ 
	printf("inserire nome del file\n"); 
	scanf("\n%s", file1); 
	pt1=fopen(file1,"w"); 
	if(pt1==NULL) 
	{ 
		printf("file non trovato "); 
		exit(EXIT_FAILURE); 
	} 
	else 
	{ 
		i=0; 
		while(i<5) 
		{ 
			printf("%d) inserisci numero ", i); 
			scanf("%d", &v1[i]); 
			fprintf(pt1, "%d\t", v1[i]); 
			i++; 
		} 
	} 
	fclose(pt1); 
	//------------------------------------------------ 
	printf("inserire nome del file\n"); 
	scanf("\n%s", file2); 
	pt2=fopen(file2,"w"); 
	if(pt2==NULL) 
	{ 
		printf("file non trovato "); 
		exit(EXIT_FAILURE); 
	} 
	else 
	{ 
		i=0; 
		while(i<5) 
		{ 
			printf("%d) inserisci numero ", i); 
			scanf("%d", &v2[i]); 
			fprintf(pt1, "%d\t", v2[i]); 
			i++; 
		} 
	} 
	fclose(pt2); 
	//------------------------------------------------ 
	pt3(pt1, file1, pt2, file2);	 
}