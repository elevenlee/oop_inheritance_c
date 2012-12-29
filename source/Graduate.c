///////////////////////////////////////////////////////////
/*
 * File Name:   Graduate.c
 * Instructor:  Prof. Benjamin Goldberg
 *              & Prof. Robert Grimm
 * Author:      Shen Li
 * UID:         N14361265
 * Department:  Computer Science
 * Note:        This file includes struct Graduate function
 *              definition.
 */
///////////////////////////////////////////////////////////

//////////Head Files//////////
#include <stdio.h>
#include <string.h>
#include "Graduate.h"

//////////Function Definition////////
/*
 * Struct Graduate object Constructor Function
 * Variable Definition:
 * -- object: _graduate_object structure object
 * -- s_name: graduate student name
 * -- id: graduate student id
 * -- gpa: graduate student gpa
 * -- address: graduate student address
 * -- telephone: graduate student telephone
 * -- p_name: professor name
 * -- title: professor title
 * -- office: professor office
 * -- credit: graduate student credit
 * -- thesis: graduate student thesis for his/her professor
 * Return Value: NULL
 */
void graduateConstructor(   GRADUATE_OBJECT *object,
                            const char      *s_name,
                            const u_int32   id,
                            const double    gpa,
                            const char      *address,
                            const char      *telephone,
                            const char      *p_name,
                            const char      *title,
                            const u_int16   office,
                            const u_int16   credit,
                            const char      *thesis){
    //Check object
    if (object == NULL){
        dieWithUserMessage("GRADUATE_OBJECT NULL", "graduateConstructor Function!");
    }
    //Constructor GRADUATE_OBJECT structure
    //Calling the _student_object parent constructor
    studentConstructor( (STUDENT_OBJECT*)object,
                        s_name,
                        id,
                        gpa,
                        address,
                        telephone);
    //Calling the _professor_object parent constructor
    //Need to plus OFFSET = sizeof(STUDENT_OBJECT)
    professorConstructor(   (PROFESSOR_OBJECT*)((char*)object + sizeof(STUDENT_OBJECT)),
                            p_name,
                            title,
                            office);
    //child members
    object->stu_credit = credit;
    strcpy(object->prof_thesis, thesis);

    return;
}

/*
 * Struct Graduate Object Set Address Function
 * Varaible Definition:
 * -- object: _graduate_object structure object
 * -- address: graduate student new addres
 * Return Value: NULL
 */
void graduateSetAddress(GRADUATE_OBJECT *object, const char *address){
    //Check object
    if (object == NULL){
        dieWithUserMessage("GRADUATE_OBJECT NULL", "graduateSetAddress Function!");
    }
    //Set new address
    strcpy(object->stu_address, address);
    fputs("Set student's address successfully in STUDENT_OBJECT!", stdout);
    fputc('\n', stdout);

    return;
}

/*
 * Struct Graduate Object Get Address Function
 * Varaible Definition:
 * -- object: _graduate_object structure object
 * Return Value: graduate student address
 */
char *graduateGetAddress(GRADUATE_OBJECT *object){
    //Check object
    if (object == NULL){
        dieWithUserMessage("GRADUATE_OBJECT NULL", "graduateGetAddress Function!");
    }
    fputs("Get student's address successfully in STUDENT_OBJECT!", stdout);
    fputc('\n', stdout);

    return object->stu_address;
}

/*
 * Struct Graduate Object Set Office Function
 * Variable Definition:
 * -- object: _graduate_object structure object
 * -- office: professor new office
 * Return Value: NULL
 */
void graduateSetOffice(GRADUATE_OBJECT *object, const u_int16 office){
    //Check object
    if (object == NULL){
        dieWithUserMessage("GRADUATE_OBJECT NULL", "graduateSetOffice Function!");
    }
    //Set new office
    object->prof_office = office;
    fputs("Set professor's office successfully in PROFESSOR_OBJECT!", stdout);
    fputc('\n', stdout);

    return;
}

/*
 * Struct Graduate Object Get Office Function
 * Variable Definition:
 * -- object: _graduate_object structure object
 * Return Value: professor office
 */
u_int16 graduateGetOffice(GRADUATE_OBJECT *object){
    //Check object
    if (object == NULL){
        dieWithUserMessage("GRADUATE_OBJECT NULL", "graduateGetOffice Function!");
    }
    fputs("Get professor's office successfully in PROFESSOR_OBJECT!", stdout);
    fputc('\n', stdout);

    return object->prof_office;
}

/*
 * Struct Graduate Object Show Graduate Student's Information Function
 * Variable Definition:
 * -- object: _graduate_object structure object
 * Return Value: NULL
 */
void graduateStu_display(const GRADUATE_OBJECT *object){
    //Check object
    if (object == NULL){
        dieWithUserMessage("GRADUATE_OBJECT NULL", "graduateStu_display Function!");
    }
    //Output graduate student's information
    fputs("**********GRADUATE_OBJECT**********", stdout);
    fputc('\n', stdout);
    printf("Student Name:   %s\n", object->stu_name);
    printf("ID:             %u\n", object->stu_id);
    printf("GPA:            %.3f\n", object->stu_gpa);
    printf("Credit:         %u\n", object->stu_credit);

    return;
}

/*
 * Struct Graduate Object Show Professor's Information Function
 * Variable Definition:
 * -- object: _graduate_object structure object
 * Return Value: NULL
 */
void graduateProf_display(const GRADUATE_OBJECT *object){
    //Check object
    if (object == NULL){
        dieWithUserMessage("GRADUATE_OBJECT NULL", "graduateProf_display Function!");
    }
    //Output graduate's professor information
    fputs("*********GRADUATE_OBJECT**********", stdout);
    fputc('\n', stdout);
    printf("Professor Name: %s\n", object->prof_name);
    printf("Title:          %s\n", object->prof_title);
    printf("Thesis:         %s\n", object->prof_thesis);

    return;
}

/*
 * Struct Graduate Object From Professor Object Thunk Function
 * Variable Definition:
 * -- object: _professor_object structure object
 * Return Value: NULL
 */
void graduateProf_displayFromProfessorthunk(const PROFESSOR_OBJECT *object){
    GRADUATE_OBJECT *grad_this = (GRADUATE_OBJECT*)((char*)object - sizeof(STUDENT_OBJECT));    //_graduate_object structure object

    //Call the actual graduateProf_display function
    graduateProf_display(grad_this);

    return;
}
