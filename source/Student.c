///////////////////////////////////////////////////////////
/*
 * File Name:   Student.c
 * Instructor:  Prof. Benjamin Goldberg
 *              & Prof. Robert Grimm
 * Author:      Shen Li
 * UID:         N14361265
 * Department:  Computer Science
 * Note:        This file includes struct Student function
 *              definition.
 */
///////////////////////////////////////////////////////////

//////////Head Files//////////
#include <stdio.h>
#include <string.h>
#include "Student.h"

//////////Function Definition//////////
/*
 * Struct Student Object Constructor Function
 * Variable Definition:
 * -- object: _student_object structure object
 * -- name: student name
 * -- id: student id
 * -- gpa: student gpa
 * -- address: student address
 * -- telephone: student telephone
 * Return Value: NULL
 */
void studentConstructor(STUDENT_OBJECT  *object,
                        const char      *name,
                        const u_int32   id,
                        const double    gpa,
                        const char      *address,
                        const char      *telephone){
    //Check object
    if (object == NULL){
        dieWithUserMessage("STUDENT_OBJECT NULL", "studentConstructor Function!");
    }
    //Constructor STUDENT_OBJECT structure
    strcpy(object->stu_name, name);
    object->stu_id = id;
    object->stu_gpa = gpa;
    strcpy(object->stu_address, address);
    strcpy(object->stu_telephone, telephone);

    return;
}

/*
 * Struct Student Object Set Address Function
 * Variable Definition:
 * -- object: _student_object structure object
 * -- address: student new address
 * Return Value: NULL
 */
void studentSetAddress(STUDENT_OBJECT *object, const char *address){
    //Check object
    if (object == NULL){
        dieWithUserMessage("STUDENT_OBJECT NULL", "studentSetAddress Function!");
    }
    //Set new address
    strcpy(object->stu_address, address);
    fputs("Set student's address successfully in STUDENT_OBJECT!", stdout);
    fputc('\n', stdout);

    return;
}

/*
 * Struct Student Object Get Address Function
 * Variable Definition:
 * -- object: _student_object structure object
 * Return Value: student address
 */
char *studentGetAddress(STUDENT_OBJECT *object){
    //Check object
    if (object == NULL){
        dieWithUserMessage("STUDENT_OBJECT NULL", "studentGetAddress Function!");
    }
    fputs("Get student's address successfully in STUDENT_OBJECT!", stdout);
    fputc('\n', stdout);

    return object->stu_address;
}

/*
 * Struct Student Object Show Student's Information Function
 * Variable Definition:
 * -- object: _student_object structure object
 * Return Value: NULL
 */
void studentStu_display(const STUDENT_OBJECT *object){
    //Check object
    if (object == NULL){
        dieWithUserMessage("STUDENT_OBJECT NULL", "studentStu_display Function!");
    }
    //Output student's information
    fputs("**********STUDENT_OBJECT**********", stdout);
    fputc('\n', stdout);
    printf("Name:       %s\n", object->stu_name);
    printf("ID:         %u\n", object->stu_id);
    printf("GPA:        %.3f\n", object->stu_gpa);
    printf("Address:    %s\n", object->stu_address);
    printf("Telephone:  %s\n", object->stu_telephone);

    return;
}
