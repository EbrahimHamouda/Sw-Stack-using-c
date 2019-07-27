#ifndef SW_STACK_ARRAY_H_INCLUDED
#define SW_STACK_ARRAY_H_INCLUDED
#include "common.h"

    // ERRORS DEFINES :
typedef enum
{
	NO_ERRORS = 0,
	INVALID_PARAMTERS = 5,
	STACK_FULL=6,
	STACK_EMPTY=7,
	INTERNAL_MEM_ERROR=8,
}genum_sw_stack_error_t;

        /*USER IMP */
typedef struct
{
	char name[100];
	int salary;
	double GPA;
}gStrData_t;


typedef struct
{
	gStrData_t* p_stack;
	ecore_u8 current_stack_size;
	ecore_u8 u8_max_size;
}gStrStack_t;


genum_sw_stack_error_t create_stack(gStrStack_t * p_stk, ecore_u8 max_size);  //  max size -> already define in array IMP

/*
 *	in[p_stack] :
 *  in[p_data]
 *
 */
genum_sw_stack_error_t sw_push(gStrStack_t * p_stk ,gStrData_t * p_data);
/*
 *	in[p_stack] :
 *  out[p_data]
 *
 */
genum_sw_stack_error_t sw_pop(gStrStack_t * p_stk ,gStrData_t * p_data);

#endif // SW_STACK_ARRAY_H_INCLUDED
