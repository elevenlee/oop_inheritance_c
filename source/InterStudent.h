///////////////////////////////////////////////////////////
/*
 * File Name:   InterStudent.h
 * Instructor:  Prof. Benjamin Goldberg
 *              & Prof. Robert Grimm
 * Author:      Shen Li
 * UID:         N14361265
 * Department:  Computer Science
 * Note:        This file includes struct InterStudent
 *              members, function declarations.
 */
///////////////////////////////////////////////////////////

//////////Precompiler//////////
#ifndef INTERSTUDENT_H
#define INTERSTUDENT_H

//////////Head Files//////////
#include "Inheritance.h"

//////////Struct Definition//////////
struct _interstudent_vtable;

/*InterStudent class structure*/
typedef struct _interstudent_object{
    struct _interstudent_vtable *vt;        //vtable structure
    char    stu_name[NAME_SIZE];            //international student name
    u_int32 stu_id;                         //international student id
    double  stu_gpa;                        //international student gpa
    char    stu_address[ADDRESS_SIZE];      //international student address
    char    stu_telephone[TELEPHONE_SIZE];  //international student telephone
    char    stu_visa;                       //international student visa
    char    stu_nation[NATION_SIZE];        //international student nation
}INTERSTUDENT_OBJECT;

/*InterStudent class vtable structure*/
typedef struct _interstudent_vtable{
    void (*display)(const INTERSTUDENT_OBJECT *object); //virtual function
}INTERSTUDENT_VTABLE;

//////////Global Variable//////////
INTERSTUDENT_VTABLE *interstudent_vt;   //_interstudent_object structure vtable pointer

//////////Function Declaration//////////
void    interstudentConstructor(INTERSTUDENT_OBJECT *object,
                                const char          *name,
                                const u_int32       id,
                                const double        gpa,
                                const char          *address,
                                const char          *telephone,
                                const char          visa,
                                const char          *nation);
void    interstudentSetAddress(INTERSTUDENT_OBJECT *object, const char *address);
char    *interstudentGetAddress(INTERSTUDENT_OBJECT *object);
void    interstudentStu_display(const INTERSTUDENT_OBJECT *object);

#endif  //INTERSTUDENT_H
