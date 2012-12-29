///////////////////////////////////////////////////////////
/*
 * File Name:   Inheritance.h
 * Instructor:  Prof. Benjamin Goldberg
 *              & Prof. Robert Grimm
 * Author:      Shen Li
 * UID:         N14361265
 * Department:  Computer Science
 * Note:        This file includes type definition and
 *              constant size definition.
 */
///////////////////////////////////////////////////////////

//////////Precompiler//////////
#ifndef INHERITANCE_H
#define INHERITANCE_H

//////////Constant Definition//////////
enum    constant_size{
    TELEPHONE_SIZE  = 16,
    NATION_SIZE     = 20,
    NAME_SIZE       = 32,
    TITLE_SIZE      = 48,
    THESIS_SIZE     = 96,
    ADDRESS_SIZE    = 128,
};

//////////Type Definition//////////
typedef unsigned short  u_int16;
typedef unsigned int    u_int32;

//////////Function Declaration//////////
void    dieWithUserMessage(const char *message, const char *detail);
void    dieWithSystemMessage(const char *message);

#endif  //INHERITANCE_H
