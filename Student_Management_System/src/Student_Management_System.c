/*
 ============================================================================
 Name        : Student_Management_System.c
 Author      : Kerolous-Labib-Georgy
 Version     : V1.1
 Description : Learning Management System
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Student_function.h"


/********************************** main function **********************************/
int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int i;
	int id;
	// Menu options
	printf("1. Add a Student:\n");
	printf("2. Display All Students:\n");
	printf("3. Search for a Student by ID:\n");
	printf("4. Update Student Information:\n");
	printf("5. Calculate Average GPA:\n");
	printf("6. Find Student with Highest GPA:\n");
	printf("7. Delete a Student:\n");
	printf("8. Exit:\n");
	printf("============================================================");
	printf("\nEnter the number: ");
	scanf("%d",&i);

	// switch case to select option
	switch(i){
	case 1:
		addStudent();
		main();
		break;
	case 2:
		displayStudents();
		main();
		break;
	case 3:
		printf("Enter the ID: ");
		scanf("%d",&id);
		searchStudentByID(id);
		main();
		break;
	case 4:
		printf("Enter the ID: ");
		scanf("%d",&id);
		updateStudent(id);
		main();
		break;
	case 5:
		printf("The average GPA of the students is: %.2f\n",calculateAverageGPA());
		printf("----------------------------------------------------------------\n");
		main();
		break;
	case 6:
		searchHighestGPA();
		main();
		break;
	case 7:
		printf("Enter the ID: ");
		scanf("%d",&id);
		deleteStudent(id);
		main();
		break;
	case 8:
		Exit_app();
		printf("Exiting......");
		return 0;
	default:
		printf("False input!\n");
		printf("----------------------------------------------------------------\n");
		main();
	}

}
