///////////////////////////////////////////////////////////
/*
 * File Name:   InterStudent.c
 * Instructor:  Prof. Benjamin Goldberg
 *              & Prof. Robert Grimm
 * Author:      Shen Li
 * UID:         N14361265
 * Department:  Computer Science
 * Note:        This file includes struct InterStudent
 *              function definition.
 */
///////////////////////////////////////////////////////////

//////////Head Files//////////
#include <stdio.h>
#include <string.h>
#include "InterStudent.h"
#include "Student.h"

//////////Function Definition//////////
/*
 * Struct InterStudent Object Constructor Function
 * Variable Definition:
 * -- object: _interstudent_object structure object
 * -- name: international student name
 * -- id: international student id
 * -- gpa: international student gpa
 * -- address: international student address
 * -- telephone: international student telephone
 * -- visa: international student visa
 * -- nation: international student nation
 * Return Value: NULL
 */
void interstudentConstructor(   INTERSTUDENT_OBJECT *object,
                                const char          *name,
                                const u_int32       id,
                                const double        gpa,
                                const char          *address,
                                const char          *telephone,
                                const char          visa,
                                const char          *nation){
    //Check object
    if (object == NULL){
        dieWithUserMessage("INTERSTUDENT_OBJECT NULL", "interstudentConstructor Function!");
    }
    //Constructor INTERSTUDENT_OBJECT structure
    //Calling the parent constructor
    studentConstructor( (STUDENT_OBJECT*)object,
                        name,
                        id,
                        gpa,
                        address,
                        telephone);
    //child members
    object->stu_visa = visa;
    strcpy(object->stu_nation, nation);

    return;
}

/*
 * Struct InterStudent Object Set Address Function
 * Variable Definition:
 * -- object: _interstudent_object structure object
 * -- address: international student new address
 * Return Value: NULL
 */
void interstudentSetAddress(INTERSTUDENT_OBJECT *object, const char *address){
    //Check object
    if (object == NULL){
        dieWithUserMessage("INTERSTUDENT_OBJECT NULL", "interstudentSetAddress Function!");
    }
    //Set new address, but deny it
    fputs("Permission Deny: Cannot set address in struct INTERSTUDENT!", stdout);
    fputc('\n', stdout);

    return;
}

/*
 * Struct InterStudent Object Get Address Function
 * Variable Definition:
 * -- object: _interstudent_object structure object
 * Return Value: international student address
 */
char *interstudentGetAddress(INTERSTUDENT_OBJECT *object){
    //Check object
    if (object == NULL){
        dieWithUserMessage("INTERSTUDENT_OBJECT NULL", "interStudentGetAddress Function!");
    }
    fputs("Get student's address successfully in STUDENT_OBJECT!", stdout);
    fputc('\n', stdout);

    return object->stu_address;
}

/*
 * Struct InterStudent Object Show International Student's Information Function
 * Variable Definition:
 * -- object: _interstudent_object structure object
 * Return Value: NULL
 */
void interstudentStu_display(const INTERSTUDENT_OBJECT *object){
    //Check object
    if (object == NULL){
        dieWithUserMessage("INTERSTUDENT_OBJECT NULL", "interstudentStu_display Function!");
    }
    //Output international student's information
    fputs("**********INTERSTUDENT_OBJECT**********", stdout);
    fputc('\n', stdout);
    printf("Name:       %s\n", object->stu_name);
    printf("ID:         %u\n", object->stu_id);
    printf("GPA:        %.3f\n", object->stu_gpa);
    printf("Visa:       %c\n", object->stu_visa);
    printf("Nation:     %s\n", object->stu_nation);

    return;
}
