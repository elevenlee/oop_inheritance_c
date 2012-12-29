///////////////////////////////////////////////////////////
/*
 * File Name:   Student.h
 * Instructor:  Prof. Benjamin Goldberg
 *              & Prof. Robert Grimm
 * Author:      Shen Li
 * UID:         N14361265
 * Department:  Computer Science
 * Note:        This file includes struct Student members,
 *              function declarations.
 */
///////////////////////////////////////////////////////////

//////////Precompiler//////////
#ifndef STUDENT_H
#define STUDENT_H

//////////Head Files//////////
#include "Inheritance.h"

//////////Struct Definition//////////
struct  _student_vtable;

/*Student class structure*/
typedef struct _student_object{
    struct _student_vtable  *vt;            //vtable structure
    char    stu_name[NAME_SIZE];            //student name
    u_int32 stu_id;                         //student id
    double  stu_gpa;                        //student gpa
    char    stu_address[ADDRESS_SIZE];      //student address
    char    stu_telephone[TELEPHONE_SIZE];  //student telephone
}STUDENT_OBJECT;

/*Student class vtable structure*/
typedef struct _student_vtable{
    void (*display)(const STUDENT_OBJECT *object);  //virtual function pointer
}STUDENT_VTABLE;

//////////Global Variable//////////
STUDENT_VTABLE  *student_vt;    //_student_object structure vtable pointer

//////////Function Declaration//////////
void    studentConstructor( STUDENT_OBJECT  *object,
                            const char      *name,
                            const u_int32   id,
                            const double    gpa,
                            const char      *address,
                            const char      *telephone);
void    studentSetAddress(STUDENT_OBJECT *object, const char *address);
char    *studentGetAddress(STUDENT_OBJECT *object);
void    studentStu_display(const STUDENT_OBJECT *object);

#endif  //STUDENT_H
