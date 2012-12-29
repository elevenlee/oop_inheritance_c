oop_inheritance_c
=================

Implementing dynamic dispatch using explicit vtables in C.


1. The code was written under the Ubuntu Linux System (Version 11.10)
2. The Compiler version is GCC 4.6.1
3. I have written a "makefile" document
   So just type "make" command under current directory to compile .cc source code
   Also, type "make clean" under current directory to remove .cc & execution files.
4. The format of running source code is as below

    ./Inheritance

5. Four structs relationship
   Base struct: STUDENT_OBJECT, PROFESSOR_OBJECT;
   Single Inheritance: INTERSTUDENT_OBJECT----->STUDENT_OBJECT
   Multiple Inheritance: GRADUATE_OBJECT----->STUDENT & PROFESSOR
6. structs member information

                        private         public          protected           virtual                 non-virtual

    STUDENT_OBJECT      stu_address     all functions   stu_name            studentStu_display      studentSetAddress
                        stu_telephone                   stu_id                                      studentGetAddress
                                                        stu_gpa

    PROFESSOR_OBJECT    prof_office     all functions   prof_name           professorProf_display   professorSetOffice
                                                        prof_title                                  professorGetOffice

    INTERSTUDENT_OBJECT stu_nation      all functions   stu_name(Inherit)   interstudentStu_display interstudentSetAddress
                                                        stu_id(Inherit)                             interstudentGetAddress(Inherit)
                                                        stu_gpa(Inherit)
                                                        stu_visa

    GRADUATE_OBJECT     prof_thesis     all functions   stu_name(Inherit)   graduateStu_display     graduateSetAddress(Inherit)
                                                        stu_id(Inherit)     graduateProf_display    graduateGetAddress(Inherit)
                                                        stu_gpa(Inherit)                            graduateSetOffice(Inherit)
                                                        stu_credit                                  graduateGetOffice(Inherit)
                                                        prof_name(Inherit)
                                                        prof_title(Inherit)
