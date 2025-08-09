/*
 * Student_function.c
 *
 *  Created on: Aug 4, 2025
 *  Author: Kerolous-Labib
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/********************************** Structure declaration **********************************/
struct student{
	int id; 			/* Student ID */
	char name [50]; 	/* Student Name */
	int age; 			/* Student Age */
	float gpa; 			/* Student GPA */
};

/* Define a structure to represent a node in a linked list */
struct node{
	struct student data;
	struct node *next;
};

struct node *head = NULL;


/********************************** Add Students **********************************/
void addStudent(){
	struct node *current = (struct node*)malloc(1 * sizeof(struct node));			// Make a new node and store its address in the "current" pointer

	// Make sure memory was successfully allocated
	if(current == NULL){
		printf("Memory allocation failed\n");
		printf("----------------------------------------------------------------\n");
		return;
	}

	else{
		// Ask the user to enter student information
		printf("Enter student Name: "); 		// Getting student's Name
		scanf(" %49[^\n]",current->data.name);

		// ===== Update ID with validation =====
		do {
			printf("Enter Student ID: ");
			scanf("%d", &current->data.id);

			if (current->data.id < 0) {
				printf("Invalid ID! Please enter an ID above zero.\n");
			}
		} while (current->data.id < 0);

		// ===== Update age with validation =====
		do {
			printf("Enter Student Age: ");
			scanf("%d", &current->data.age);

			if (current->data.age < 0) {
				printf("Invalid age! Please enter an age above zero.\n");
			}
		} while (current->data.age < 0);

		// ===== Get GPA with validation =====
		do {
			printf("Enter GPA (0.00 to 4.00): ");
			scanf("%f", &current->data.gpa);

			if (current->data.gpa < 0 || current->data.gpa > 4) {
				printf("Invalid GPA! Please enter a value between 0.00 and 4.00.\n");
			}
		} while (current->data.gpa < 0 || current->data.gpa > 4);
		printf("----------------------------------------------------------------\n");
	}

	// Check if this is the first node in the list
	if(head == NULL){						// If list is empty, add as first node (no need to check ID)
		head = current;
		current->next = NULL;
	}
	else{
		// Searching for ID
		struct node *search = head; 		// Pointer for searching the list
		while(search != NULL){
			if((search->data.id)==(current->data.id)){
				printf("The ID is already exist\n");
				printf("----------------------------------------------------------------\n");
				free(current);				// Free memory and stop if ID is duplicate
				return;
			}
			search = search->next;
		}
		// ID is unique, so add the new node at the end of the list
		struct node *link = head;
		while(link->next != NULL){			// Move to the last node
			link = link->next;
		}
		link->next = current;				// Add the new node at the end
		current->next = NULL;
	}
}

/********************************** Display Students informations **********************************/
void displayStudents(void){
	if(head == NULL){						// Check if the list is empty
		printf("The list is empty\n");
		printf("----------------------------------------------------------------\n");
		return;
	}
	else{
		struct node *search = head; 		// Searching pointer
		int i=1;
		while(search != NULL){		// looping to print data
			printf("\n");
			printf("Student[%d]\n",i);
			printf("Name: ");				// printing Student Name
			puts(search->data.name);

			printf("ID: %d",search->data.id);				// Printing Student ID
			printf("\n");

			printf("Student Age: %d",search->data.age);		// Printing Student Age
			printf("\n");

			printf("Student GPA: %.2f",search->data.gpa);	// Printing Student GPA
			printf("\n");


			i++; 					// Incrementing i
			search = search->next;
		}
		printf("----------------------------------------------------------------\n");
	}
}

/********************************** Search Students informations **********************************/
void searchStudentByID(int id){
	struct node *search = head; 		// Searching pointer
	int i=1;
	while(search != NULL){		// looping to print data
		if(id == search->data.id){
			printf("\n");
			printf("Student[%d]\n",i);
			printf("Name: ");				// printing Student Name
			puts(search->data.name);

			printf("ID: %d",search->data.id);				// Printing Student ID
			printf("\n");

			printf("Student Age: %d",search->data.age);		// Printing Student Age
			printf("\n");

			printf("Student GPA: %.2f",search->data.gpa);	// Printing Student GPA
			printf("\n");
			printf("----------------------------------------------------------------\n");
			break;										// to exit the loop when the ID is found
		}
		i++; 											// Incrementing i
		search = search->next;							// Incrementing search pointer
	}

	// the loop is finished and the ID is not found
	if(search == NULL){
		printf("The student is not found\n");
		printf("----------------------------------------------------------------\n");
	}


}

/********************************** Update Student Information **********************************/
void updateStudent(int id){
	struct node *search = head; 		// Searching pointer
	while(search != NULL){
		if(id == search->data.id){
			printf("\n");
			printf("The ID is found updating student data.......\n");

			// filling data
			printf("Enter student Name: "); 		// Getting student Name
			scanf(" %49[^\n]",search->data.name);

			// ===== Update age with validation =====
			do {
				printf("Enter Student Age: ");
				scanf("%d", &search->data.age);

				if (search->data.age < 0) {
					printf("Invalid age! Please enter an age above zero.\n");
				}
			} while (search->data.age < 0);


			// ===== Update GPA with validation =====
			do {
				printf("Enter GPA (0.00 to 4.00): ");
				scanf("%f", &search->data.gpa);

				if (search->data.gpa < 0 || search->data.gpa > 4) {
					printf("Invalid GPA! Please enter a value between 0.00 and 4.00.\n");
				}
			} while (search->data.gpa < 0 || search->data.gpa > 4);

			printf("----------------------------------------------------------------\n");
			printf("Student informations is updated\n");
			printf("----------------------------------------------------------------\n");
			break;								// to exit the loop when the ID is found and data is updated
		}
		search = search->next;							// Incrementing search pointer
	}

	// loop is finished and ID is not found
	if(search == NULL){
		printf("The student is not found\n");
		printf("----------------------------------------------------------------\n");
	}
}

/********************************** Calculate Average GPA **********************************/
float calculateAverageGPA(void){
	float sum = 0,avg;
	int i = 0;
	struct node *search = head; 		// Searching pointer
	// if head is equal to null so there is no list
	if(head == NULL){
		return 0;
	}

	while(search != NULL){
		sum += search->data.gpa;
		i++;											// Incrementing counter to determine the number of nodes
		search = search->next;							// Incrementing search pointer
	}
	avg = (float) sum/i;
	return avg;
}

/********************************** Search Highest GPA **********************************/
void searchHighestGPA(void){
	struct node *search = head; 		// Searching pointer
	float max_gpa=0;
	// check if there is a list
	if(head == NULL){
		printf("No students found\n");
		printf("----------------------------------------------------------------\n");
		return;
	}

	// loop to search for the highest GPA
	while(search != NULL){
		if(search->data.gpa > max_gpa){
			max_gpa = search->data.gpa;
		}
		search = search->next;
	}
	// Now I have the maximum GPA
	search = head;
	while(search != NULL){
		if(search->data.gpa == max_gpa){
			printf("The student %s has the maximum GPA which is: %.2f\n",search->data.name,max_gpa);
			printf("----------------------------------------------------------------\n");
			break;
		}
		search = search->next;
	}
}

/********************************** Delete Student **********************************/
void deleteStudent(int id) {
	struct node *current = head, *prev = NULL;
	while (current != NULL) {
		if (current->data.id == id) {
			if (prev == NULL) {
				head = current->next;
			} else {
				prev->next = current->next;
			}
			free(current);
			printf("The information is deleted successfully\n");
			printf("----------------------------------------------------------------\n");
			return;
		}
		prev = current;
		current = current->next;
	}
	printf("The ID is not found\n");
	printf("----------------------------------------------------------------\n");
}

/********************************** Exit **********************************/
void Exit_app(){
	while(head != NULL){		// loop to free all students before exiting
		struct node *current = head;
		head = head->next;
		free(current);
	}
}
