///////////////////////////////////////////////////////////
/*
 * File Name:   Graduate.h
 * Instructor:  Prof. Benjamin Goldberg
 *              & Prof. Robert Grimm
 * Author:      Shen Li
 * UID:         N14361265
 * Department:  Computer Science
 * Note:        This file includes struct Graduate members,
 *              function declarations.
 */
///////////////////////////////////////////////////////////

//////////Precompiler//////////
#ifndef GRADUATE_H
#define GRADUATE_H

//////////Head Files//////////
#include "Inheritance.h"
#include "Student.h"
#include "Professor.h"

//////////Struct Definition//////////
/*Graduate class structure*/
typedef struct _graduate_object{
    STUDENT_VTABLE      *student_vt;        //student object vtable
    char    stu_name[NAME_SIZE];            //graduate student name
    u_int32 stu_id;                         //graduate student id
    double  stu_gpa;                        //graduate student gpa
    char    stu_address[ADDRESS_SIZE];      //graduate student address
    char    stu_telephone[TELEPHONE_SIZE];  //graduate student telephone
    PROFESSOR_VTABLE    *professor_vt;      //professor object vtable
    char    prof_name[NAME_SIZE];           //professor name
    char    prof_title[TITLE_SIZE];         //professor title
    u_int16 prof_office;                    //professor office
    u_int16 stu_credit;                     //graduate student credit
    char    prof_thesis[THESIS_SIZE];       //professor thesis
}GRADUATE_OBJECT;

//////////Global Variable//////////
STUDENT_VTABLE      *graduate_student_vt;   //_student_object structure vtable
PROFESSOR_VTABLE    *graduate_professor_vt; //_professor_object structure vtable

//////////Function Declaration//////////
void    graduateConstructor(GRADUATE_OBJECT *object,
                            const char      *s_name,
                            const u_int32   id,
                            const double    gpa,
                            const char      *address,
                            const char      *telephone,
                            const char      *p_name,
                            const char      *title,
                            const u_int16   office,
                            const u_int16   credit,
                            const char      *thesis);
void    graduateSetAddress(GRADUATE_OBJECT *object, const char *address);
char    *graduateGetAddress(GRADUATE_OBJECT *object);
void    graduateSetOffice(GRADUATE_OBJECT *object, const u_int16 office);
u_int16 graduateGetOffice(GRADUATE_OBJECT *object);
void    graduateStu_display(const GRADUATE_OBJECT *object);
void    graduateProf_display(const GRADUATE_OBJECT *object);
void    graduateProf_displayFromProfessorthunk(const PROFESSOR_OBJECT *object);

#endif  //GRADUATE_H
