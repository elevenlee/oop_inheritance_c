///////////////////////////////////////////////////////////
/*
 * File Name:   Professor.c
 * Instructor:  Prof. Benjamin Goldberg
 *              & Prof. Robert Grimm
 * Author:      Shen Li
 * UID:         N14361265
 * Department:  Computer Science
 * Note:        This file includes struct Professor
 *              function definition.
 */
///////////////////////////////////////////////////////////

//////////Head Files//////////
#include <stdio.h>
#include <string.h>
#include "Professor.h"

//////////Function Definition//////////
/*
 * Struct Professor Object Constructor Function
 * Variable Definition:
 * -- object: _professor_object structure object
 * -- name: professor name
 * -- title: professor title
 * -- office: professor office
 * Return Value: NULL
 */
void professorConstructor(  PROFESSOR_OBJECT    *object,
                            const char          *name,
                            const char          *title,
                            const u_int16       office){
    //Check object
    if (object == NULL){
        dieWithUserMessage("PROFESSOR_OBJECT NULL", "professorConstructor Function!");
    }
    //Constructor PROFESSOR_OBJECT structure
    strcpy(object->prof_name, name);
    strcpy(object->prof_title, title);
    object->prof_office = office;

    return;
}

/*
 * Struct Professor Object Set Office Function
 * Variable Definition:
 * -- object: _professor_object structure object
 * -- office: professor new office
 */
void professorSetOffice(PROFESSOR_OBJECT *object, const u_int16 office){
    //Check object
    if (object == NULL){
        dieWithUserMessage("PROFESSOR_OBJECT NULL", "professorSetOffice Function!");
    }
    //Set new office
    object->prof_office = office;
    fputs("Set professor's office successfully in PROFESSOR_OBJECT!", stdout);
    fputc('\n', stdout);

    return;
}

/*
 * Struct Professor Object Get Office Function
 * Variable Definition:
 * -- object: _professor_object structure object
 * Return Value: professor office
 */
u_int16 professorGetOffice(PROFESSOR_OBJECT *object){
    //Check object
    if (object == NULL){
        dieWithUserMessage("PROFESSOR_OBJECT NULL", "professorGetOffice Function!");
    }
    fputs("Get professor's office successfully in PROFESSOR_OBJECT!", stdout);
    fputc('\n', stdout);

    return object->prof_office;
}

/*
 * Struct Professor Object Show Professor's Information Function
 * Variable Definition:
 * -- object: _professor_object structure object
 * Return Value: NULL
 */
void professorProf_display(const PROFESSOR_OBJECT *object){
    //Check object
    if (object == NULL){
        dieWithUserMessage("PROFESSOR_OBJECT NULL", "professorProf_display Function!");
    }
    //Output professor's information
    fputs("**********PROFESSOR_OBJECT**********", stdout);
    fputc('\n', stdout);
    printf("Name:       %s\n", object->prof_name);
    printf("Title:      %s\n", object->prof_title);
    printf("Office:     %u\n", object->prof_office);

    return;
}
