///////////////////////////////////////////////////////////
/*
 * File Name:   Professor.h
 * Instructor:  Prof. Benjamin Goldberg
 *              & Prof. Robert Grimm
 * Author:      Shen Li
 * UID:         N14361265
 * Department:  Computer Science
 * Note:        This file includes struct Professor members,
 *              function declarations.
 */
///////////////////////////////////////////////////////////

//////////Precompiler//////////
#ifndef PROFESSOR_H
#define PROFESSOR_H

//////////Head Files//////////
#include "Inheritance.h"

//////////Struct Definition//////////
struct  _professor_vtable;

/*Professor class structure*/
typedef struct _professor_object{
    struct _professor_vtable    *vt;    //vtable structure
    char    prof_name[NAME_SIZE];       //professor name
    char    prof_title[TITLE_SIZE];     //professor title
    u_int16 prof_office;                //professor office
}PROFESSOR_OBJECT;

/*Professor class vtable structure*/
typedef struct _professor_vtable{
    void (*display)(const PROFESSOR_OBJECT *object);    //virtual function
}PROFESSOR_VTABLE;

//////////Global Variable//////////
PROFESSOR_VTABLE    *professor_vt;  //_professor_object structure vtable pointer

//////////Function Declaration//////////
void    professorConstructor(   PROFESSOR_OBJECT    *object,
                                const char          *name,
                                const char          *title,
                                const u_int16       office);
void    professorSetOffice(PROFESSOR_OBJECT *object, const u_int16 office);
u_int16 professorGetOffice(PROFESSOR_OBJECT *object);
void    professorProf_display(const PROFESSOR_OBJECT *object);

#endif  //PROFESSOR_H
