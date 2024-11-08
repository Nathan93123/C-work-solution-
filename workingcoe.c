#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

struct Student{
    char name[20];
    int age;
    int number;
};


int numberofstudents = 0;

int quicksort(int*,int);

/*********************** FILE WRITING FUNCTION ******************************/
void filewrite(struct Student ***p)
{
	int number,ch,age;
  	char name[50];
   	FILE *fp;
   	fp = fopen("student.txt","a");
   	printf("NAME, ENTER STUDENT NUMBER, AGE \n\n");

   	ch =1;
  	while(ch)
  	{
  		scanf("%s%d%d",name,&number,&age);
  		fprintf(fp,"%s %d %d\n",name, number,age);

  		strcpy((*p)[numberofstudents]->name , name );
  		(*p)[numberofstudents]->age = age;
  		(*p)[numberofstudents]->number = number;

  		numberofstudents++;

  		printf("\n\n press 1 to continue,0 to stop \n\n");
  		scanf("%d",&ch);
  	}
}

/******************** OUTPUTING DATA ON SCREEN***************/
void fileprint(struct Student ***p)
{
	printf("\n ---- STUDENT RECORDS LOG ----\n");
	int i;
	for (i = 0; i < numberofstudents; i++) {
		printf("RECORD #%d: \n",i+1);
		printf(" Name : %s \n", (*p)[i]->name);
    	printf(" Age : %d \n", (*p)[i]->age);
    	printf(" Number %d \n", (*p)[i]->number);

	}
}

/******************* SORTING FILE ************************/
void filesort()
{

}

/************************* DATA USING STUDENTNO***************************/
void studentno(struct Student ***p)
{
	int number,ch,i;
  	ch=1;

  printf("\n ---- STUDENT SEARCH ----\n");

  while(ch)
  {

    printf(" \n ENTER STUDENT NUMBER - ");
    scanf("%d",&number);

	for (i = 0; i < numberofstudents; i++) {

		 if((*p)[i]->number == number){
            printf(" \n STUDENT RECORD # %d FOUND \n",i+1);

            printf(" Name : %s \n", (*p)[i]->name);
            printf(" Age : %d \n", (*p)[i]->age);
            printf(" Number %d \n", (*p)[i]->number);
		 }

	}

  	printf("\n\npress 1 to see student info, 0 to return to main menu\n");
  	scanf("%d",&ch);
 	}

}

int main() {

	// allocate 100 pointers, effectively an array
	struct Student **t_array = malloc(100 * sizeof(struct Student *));

	// allocate 100 structs and have the array point to them
	int i;
    for (i = 0; i < 100; i++) {
        t_array[i] = malloc(sizeof(struct Student));
    }

	FILE* file = fopen("student.txt", "r"); /* should check the result */
    char word[50];
    int number, age;

	if( access("student.txt", F_OK ) != -1 ) {
    // file exists

	  	while (fscanf(file, "%s %d %d", word, &number, &age) > 0) {
	  		strcpy(t_array[numberofstudents]->name , word );
	  		t_array[numberofstudents]->age = age;
	  		t_array[numberofstudents]->number = number;

	        numberofstudents++;
	    }
	}


    fclose(file);

int c;

while(c!=5)
   {
     printf("\n STUDENT MANAGER -- GIVE CHOICE--\n");
     printf("   1 TO ENTER STUDENT INFO.\n");
     printf("   2 TO SEE STUDENT.TXT FILE\n");
     printf("   3 TO SORT STUDENT RECORDS IN ALPHABETICAL ORDER\n");
     printf("   4 TO PRINT STUDENT INFO. USING STUDENT NO\n");
     printf("   5 TO EXIT\n\n--");
     scanf("%d",&c);
     switch(c)
     {
     case 1:
     	filewrite(&t_array);
        break;
     case 2:
     	fileprint(&t_array);
        break;
     case 3:
     	filesort();
        break;
     case 4:
        studentno(&t_array);
        break;
     case 5:
          break;
     default:
          break;
     }
    }

   return 0;
}
