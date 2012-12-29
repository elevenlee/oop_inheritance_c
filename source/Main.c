///////////////////////////////////////////////////////////
/*
 * File Name:   Main.c
 * Instructor:  Prof. Benjamin Goldberg
 *              & Prof. Robert Grimm
 * Author:      Shen Li
 * UID:         14361265
 * Department:  Computer Science
 * Note:        This file includes Main Function.
 */
///////////////////////////////////////////////////////////

//////////Head Files//////////
#include <stdio.h>
#include <stdlib.h>
#include "Student.h"
#include "Professor.h"
#include "InterStudent.h"
#include "Graduate.h"

//////////Function Declaration//////////
void    allocateSharedVTables();
void    testStudent(STUDENT_OBJECT *object);
void    testProfessor(PROFESSOR_OBJECT *object);
void    testInterStudent(INTERSTUDENT_OBJECT *object);
void    testGraduate(GRADUATE_OBJECT *object);

//////////Function Definition//////////
/*
 * Main Function
 * Variable Definition:
 * -- argc: number of arguments
 * -- argv[]: arguments
 * Return Value: exit number
 */
int main(int argc, char *argv[]){
    //Allocate vtables
    allocateSharedVTables();

    STUDENT_OBJECT      *stu = (STUDENT_OBJECT*)malloc(sizeof(STUDENT_OBJECT));                 //Student Object
    PROFESSOR_OBJECT    *prof = (PROFESSOR_OBJECT*)malloc(sizeof(PROFESSOR_OBJECT));            //Professor Object
    INTERSTUDENT_OBJECT *inter_stu = (INTERSTUDENT_OBJECT*)malloc(sizeof(INTERSTUDENT_OBJECT)); //InterStudent Object
    GRADUATE_OBJECT     *grad = (GRADUATE_OBJECT*)malloc(sizeof(GRADUATE_OBJECT));              //Graduate Object

    //Set vtable pointer
    stu->vt = student_vt;
    prof->vt = professor_vt;
    inter_stu->vt = interstudent_vt;
    grad->student_vt = graduate_student_vt;
    grad->professor_vt = graduate_professor_vt;

    //Constructor
    studentConstructor( stu,                        //_student_object
                        "Shen Li",                  //student name
                        14361265,                   //student id
                        3.850,                      //student gpa
                        "112 Avenue T Brooklyn",    //student address
                        "646-620-5666");            //student telephone
    professorConstructor(   prof,                   //_professor_object
                            "Benjamin Goldberg",    //professor name
                            "Associate Professor",  //professor title
                            401);                   //professor office
    interstudentConstructor(inter_stu,                  //_interstudent_object
                            "Bruce Eckel",              //international student name
                            54129027,                   //international student id
                            3.100,                      //international student gpa
                            "West 181st Street Bronx",  //international student address
                            "718-295-1630",             //international student telephone
                            'F',                        //international student visa
                            "France");                  //international student nation
    graduateConstructor(grad,                           //_graduate_object
                        "Thomas Cormen",                //graduate student name
                        98123897,                       //graduate student id
                        3.950,                          //graduate student gpa
                        "5 Metrotech Ctr Brooklyn",     //graduate student address
                        "718-260-3884",                 //graduate student telephone
                        "Robert Grimm",                 //graduate student advisor
                        "Associate Professor",          //advisor title
                        324,                            //advisor office
                        24,                             //graduate student credit
                        "Object-Oriented Programming"); //advisor thesis
    
    //Start test inheritance
    fputs("**********Calling testStudent on Student Object**********", stdout);
    fputc('\n', stdout);
    testStudent(stu);
    fputs("**********Calling testStudent on InterStudent Object**********", stdout);
    fputc('\n', stdout);
    testStudent((STUDENT_OBJECT*)inter_stu);
    fputs("**********Calling testStudent on Graduate Object**********", stdout);
    fputc('\n', stdout);
    testStudent((STUDENT_OBJECT*)grad);

    fputs("**********Calling testProfessor on Professor Object**********", stdout);
    fputc('\n', stdout);
    testProfessor(prof);
    fputs("**********Calling testProfessor on Graduate Object**********", stdout);
    fputc('\n', stdout);
    testProfessor((PROFESSOR_OBJECT*)((char*)grad + sizeof(STUDENT_OBJECT)));

    fputs("**********Calling testInterStudent on InterStudent Object**********", stdout);
    fputc('\n', stdout);
    testInterStudent(inter_stu);

    fputs("**********Calling testGraduate on Graduate Object**********", stdout);
    fputc('\n', stdout);
    testGraduate(grad);

    //Deallocate
    free(stu);
    free(prof);
    free(inter_stu);
    free(grad);

    return 0;
}

/*
 * Allocate Shared VTable Function
 * Variable Definition:
 * -- NULL
 * Return Value: NULL
 */
void allocateSharedVTables(){
    //STUDENT_OBJECT vtable
    student_vt = (STUDENT_VTABLE*)malloc(sizeof(STUDENT_VTABLE));
    student_vt->display = studentStu_display;
    //PROFESSOR_OBJECT vtable
    professor_vt = (PROFESSOR_VTABLE*)malloc(sizeof(PROFESSOR_VTABLE));
    professor_vt->display = professorProf_display;
    //INTERSTUDENT_OBJECT vtable
    interstudent_vt = (INTERSTUDENT_VTABLE*)malloc(sizeof(INTERSTUDENT_VTABLE));
    interstudent_vt->display = interstudentStu_display;
    //GRADUATE_OBJECT vtable
    graduate_student_vt = (STUDENT_VTABLE*)malloc(sizeof(STUDENT_VTABLE));
    graduate_student_vt->display = (void (*)(const STUDENT_OBJECT*))graduateStu_display;
    graduate_professor_vt = (PROFESSOR_VTABLE*)malloc(sizeof(PROFESSOR_VTABLE));
    graduate_professor_vt->display = graduateProf_displayFromProfessorthunk;

    return;
}

/*
 * Test Student Object Function
 * Variable Definition:
 * -- object: _student_object structure object
 * Return Value: NULL
 */
void testStudent(STUDENT_OBJECT *object){
    char    *temp = "44 West 4th Street, New York"; //new address

    fputs("**********In testStudent Function**********", stdout);
    fputc('\n', stdout);
    //Show information of student
    object->vt->display(object);
    //Set new address
    studentSetAddress(object, temp);
    //Get student's address
    temp = studentGetAddress(object);

    return;
}

/*
 * Test Professor Object Function
 * Variable Definition:
 * -- object: _professor_object structure object
 * Return Value: NULL
 */
void testProfessor(PROFESSOR_OBJECT *object){
    u_int16 temp = 1305;    //new office

    fputs("**********In testProfessor Function**********", stdout);
    fputc('\n', stdout);
    //Show information of professor
    object->vt->display(object);
    //Set new office
    professorSetOffice(object, temp);
    //Get professor's office
    temp = professorGetOffice(object);

    return;
}

/*
 * Test InterStudent Object Function
 * Variable Definition:
 * -- object: _interstudent_object structure object
 * Return Value: NULL
 */
void testInterStudent(INTERSTUDENT_OBJECT *object){
    char    *temp = "44 West 4th Street, New York"; //new address

    fputs("**********In testInterStudent Function**********", stdout);
    fputc('\n', stdout);
    //Show information of international student
    object->vt->display(object);
    //Set new address
    interstudentSetAddress(object, temp);
    //Get international student's address
    temp = interstudentGetAddress(object);

    return;
}

/*
 * Test Graduate Object Function
 * Variable Definition:
 * -- object: _graduate_object structure object
 * Return Value: NULL
 */
void testGraduate(GRADUATE_OBJECT *object){
    char    *s_temp = "1 E 78th Street New York";   //new address
    u_int16 o_temp = 711;                           //new office

    fputs("**********In testGraduate Function**********", stdout);
    fputc('\n', stdout);
    //Show information of graduate student
    object->student_vt->display((STUDENT_OBJECT*)object);
    //Need to plus OFFSET = sizeof(STUDENT_OBJECT)
    object->professor_vt->display((PROFESSOR_OBJECT*)((char*)object + sizeof(STUDENT_OBJECT)));
    //Set new address
    graduateSetAddress(object, s_temp);
    //Get graduate's address
    s_temp = graduateGetAddress(object);
    //Set new office
    graduateSetOffice(object, o_temp);
    //Get professor's office
    o_temp = graduateGetOffice(object);

    return;
}
