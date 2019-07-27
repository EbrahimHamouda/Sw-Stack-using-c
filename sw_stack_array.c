#include "common.h"
#include "sw_stack_array.h"
#include <stdlib.h>





static bool_t ecore_mem_copy(ecore_u8*des, ecore_u8*src, ecore_u16 size)
{
    bool_t b_ret_val = E_TRUE;

    if((des != NULL) && (src != NULL) && (size != 0))
    {
        while(size--)
        {
            *des = *src;
            des++;
            src++;
        }
    }


    else
    {
        b_ret_val =  E_FALSE;
    }

    return b_ret_val;
}

genum_sw_stack_error_t create_stack(gStrStack_t * p_stk, ecore_u8 max_size)
{
    genum_sw_stack_error_t b_ret_val = NO_ERRORS;

    if((p_stk != NULL) && (max_size != 0) )
    {
        p_stk->p_stack =(gStrData_t*)malloc(max_size*sizeof(gStrData_t));
        p_stk->current_stack_size = 0;
        p_stk->u8_max_size = max_size;
    }
    else
    {
        b_ret_val = INVALID_PARAMTERS;
    }

    return b_ret_val;
}


/*
 *	in[p_stack] :
 *  in[p_data]
 *
 */
genum_sw_stack_error_t sw_push(gStrStack_t * p_stk,gStrData_t * p_data)
{
    genum_sw_stack_error_t b_ret_val = NO_ERRORS;

    if((p_stk != NULL) && (p_data != NULL) )
    {
        if(p_stk->current_stack_size < p_stk->u8_max_size)
        {
            bool_t ret = ecore_mem_copy((ecore_u8*)p_stk->p_stack, (ecore_u8*)p_data, sizeof(gStrData_t));

            if(ret == E_TRUE)
            {
                (p_stk->p_stack)++;
                (p_stk->current_stack_size)++;
            }
            else
            {
                b_ret_val = INTERNAL_MEM_ERROR;
            }
        }
        else
        {
            b_ret_val = STACK_FULL;
        }

    }
    else
    {
        b_ret_val = INVALID_PARAMTERS;
    }

    return b_ret_val;
}

/*
 *	in[p_stack] :
 *  out[p_data]
 *
 */
genum_sw_stack_error_t sw_pop(gStrStack_t * p_stk,gStrData_t * p_data)
{
    genum_sw_stack_error_t b_ret_val = NO_ERRORS;

    if((p_stk != NULL) && (p_data != NULL))
    {
        if(p_stk->current_stack_size > 0 )
        {
            (p_stk->p_stack)--;
            bool_t ret = ecore_mem_copy((ecore_u8*)p_data,(ecore_u8*)p_stk->p_stack, sizeof(gStrData_t));
            if(ret == E_TRUE)
            {
                p_stk->current_stack_size--;
            }
            else
            {
                b_ret_val = INTERNAL_MEM_ERROR;
            }
        }
        else
        {
            b_ret_val = STACK_EMPTY;
        }
    }
    else
    {
        b_ret_val = INVALID_PARAMTERS;
    }

    return b_ret_val;
}
