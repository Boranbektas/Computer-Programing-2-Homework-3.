#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	char petname[20];
	char pettype[20];
	int age;
	char operation[30];
	int payment;
}patient;


void F1(patient a[],int *p){
	FILE *fp=fopen("patient data.txt","r");
	int i=0;
	while(!feof(fp)){
		fscanf(fp,"%s %s %d %d %s",a[i].petname,a[i].pettype,&a[i].age,&a[i].payment,a[i].operation);
		i++;
	}
	*p=i-1;										//adding minus 1 because counts excessivley one time//					
										
}	


void F2(patient a[],int size,char pettype[20],int *p,patient b[]){
	int i,j=0;
	for(i=0;i<=size;i++){
		if(!strcmp(a[i].pettype,pettype)){
			strcpy(b[j].petname,a[i].petname);
			strcpy(b[j].pettype,pettype);
			b[j].age=a[i].age;
			strcpy(b[j].operation,a[i].operation);
			b[j].payment=a[i].payment;
			++j;
		}
		
	}
	if(j==0){
		printf("Try a different pettype...\n");
	}
	*p=j;
	
	
}


void F3(patient a[],int size,patient b[],int *p){

	int i,j=0;
	char t[]="transfused";
	
	for(i=0;i<=size;i++){
		if(!strcmp(a[i].operation,t)){
			strcpy(b[j].petname,a[i].petname);
			strcpy(b[j].pettype,a[i].pettype);
			b[j].age=a[i].age;
			strcpy(b[j].operation,a[i].operation);
			b[j].payment=a[i].payment;
			++j;
		}
	}
	if(j==0){
		printf("There is no transfuse operation.\n");
	}
	*p=j;
}


patient F5(void){
	patient a;
	printf("\nEnter Patient information;\n");
	scanf("%s %s %d %d %s",a.petname,a.pettype,&a.age,&a.payment,a.operation);
	return a;	
}


void F6(patient a[],int *p){
	FILE *fp=fopen("patient data.txt","a");
	int size=*p;
	size++;
	patient b=F5();
	strcpy(a[size].petname,b.petname);
	strcpy(a[size].pettype,b.pettype);
	a[size].age=b.age;
	a[size].payment=b.payment;
	strcpy(a[size].operation,b.operation);
	printf("\nPet list is updated...\n");
	fprintf(fp,"\n%s %s %d %d %s",a[size].petname,a[size].pettype,a[size].age,a[size].payment,a[size].operation);
	*p=size;
	fclose(fp);
}


void F7(patient a[],int *p){
	int i,max=-1,index,size;
	size=*p;
	for(i=0;i<=size;i++){
		if(a[i].payment>max){
			max=a[i].payment;
			index=i;
		}
	}
	printf("\nMaximum paying patient info;");
	printf("\n%s %s %d %d %s\n",a[index].petname,a[index].pettype,a[index].age,a[index].payment,a[index].operation);
	*p=size;
}


int F8(void){
	int choice;
	printf("--------------------------------\n");
	printf("Welcome to the pet hospital!!\n");
	printf("--------------------------------\n");
	printf("1. Load patient info from a file.\n");
	printf("2. Find patients.\n");
	printf("3. View patients ''transfused''.\n");
	printf("4. Add new patient info\n");
	printf("5. Find largest payment\n");
	printf("6. Quit.\n");
	printf("Choose 1, 2, 3, 4, 5 or 6:");
	scanf("%d",&choice);
	printf("\n");
	return choice;

}


int main (void){
	
	patient pets[30];
	patient findpet[30];
	patient transfused[30];
	char type[20];
	FILE *fp;
	int size1,i,size2,size3,choice;
	
	do{
	choice=F8();
	switch (choice){
	
		case 1:
			F1(pets,&size1);
			printf("\nData is succsesfuly red...\n");
			break;
		case 2:
			printf("\nEnter a pettype:");
			scanf("%s",type);
			F2(pets,size1,type,&size2,findpet);
			printf("\npets that has the pettype %s are;",type);
			for(i=0;i<size2;i++){
				printf("\n%s %s %d %d %s\n",findpet[i].petname,findpet[i].pettype,findpet[i].age,findpet[i].payment,findpet[i].operation);
			}
			break;
		case 3:
			F3(pets,size1,transfused,&size3);
			printf("Pets that has been transfused are;\n");
			for(i=0;i<size3;i++){
				printf("%s %s %d %d %s\n",transfused[i].petname,transfused[i].pettype,transfused[i].age,transfused[i].payment,transfused[i].operation);
			}
			break;
		case 4:
			F6(pets,&size1);
			break;
			
		case 5:
			F7(pets,&size1);
			break;
		}
	
		
	}while(choice!=6);
		

	
	return 0;
}