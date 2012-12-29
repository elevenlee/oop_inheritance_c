///////////////////////////////////////////////////////////
/*
 * File Name:   DieWithMessage.c
 * Instructor:  Prof. Benjamin Goldberg
 *              & Prof. Robert Grimm
 * Author:      Shen Li
 * UID:         N14361265
 * Department:  Computer Science
 * Note:        This file includes error message functions.
 */
///////////////////////////////////////////////////////////

//////////Head Files//////////
#include <stdio.h>
#include <stdlib.h>

//////////Function Definition//////////
/*
 * User Error Message Function
 * Variable Definition:
 * -- message: summary of error message
 * -- detail: detail error message based on error code
 * Return Value: NULL
 */
void dieWithUserMessage(const char *message, const char *detail){
    fputs(message, stderr);
    fputs(": ", stderr);
    fputs(detail, stderr);
    fputc('\n', stderr);
    exit(1);
}

/*
 * System Error Message Function
 * Variable Definition:
 * -- message: summary of error message
 * Return Value: NULL
 */
void dieWithSystemMessage(const char *message){
    perror(message);
    exit(1);
}
