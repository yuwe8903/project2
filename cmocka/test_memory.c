#include <stdarg.h>
#include <cmocka.h>
#include <stdint.h>
#include "memory.h"
#define PASS (0)
#define FAILED (1)
#define SIZE (6)

int8_t memmove_tests(void)
{
 /*move "know how" to the destination pointer1, 2, 3*/
  uint8_t arry[3][32] = {"I don't know how to code in C.", /*first column*/
			 "I don't know how to code in C.", /*second column*/
			 "I don't know how to code in C."};/*third column*/
  uint8_t move_length = 8;            /*"know how" takes 8 spaces*/ 
  uint8_t * dst_prt1 = arry[0] + 17;  /*destination pointer1 no overlap   */
  uint8_t * dst_prt2 = arry[1] + 13;  /*destination pointer2 overlap start
				      of destination and the end of source*/
  uint8_t * dst_prt3 = arry[2] + 2;   /*destination pointer3 overlap the end 
				      of destination and start of source  */
  uint8_t * src_prt1 = arry[0] + 8;   /*source pointer to the first column*/
  if(src_ptr1 == NULL || dst_prt1==NULL)
  {
     return FAILED;
  }
  my_memmove(src_prt1, dst_prt1, move_length);/*test No Overlap*/
  
  src_prt1 = arry[1] + 8;		/*source pointer to the second column*/
  if(src_ptr1 == NULL || dst_prt2==NULL)
  {
     return FAILED;
  }
  my_memmove(src_prt1, dst_prt2, move_length);/*test  Overlap start of destination 
						and the end of source*/
 
  src_prt1 = arry[2] + 8;		/*source pointer to the third column*/
  if(src_ptr1 == NULL || dst_prt3==NULL)
  {
     return FAILED;
  }
  my_memmove(src_prt1, dst_prt3, move_length);/*test  Overlap end of destination 
						and start of source */
  return PASS;
}

int8_t memset_tests(void)
{
  /*declare an array and a pointer to test my_memset and my_memzero*/
  uint8_t arry1[SIZE] = {15, 19, 14, 13, 11, 2};
  uint8_t * prt1 = arry1;
  if(ptr1 == NULL)
  {
     return FAILED;
  }
  /*testing my_memset function*/
  uint8_t x = 3;
  my_memset(prt1, SIZE, x);
  return PASS;
}
int8_t memzero_tests(void)
{ 
  uint8_t arry1[SIZE] = {15, 19, 14, 13, 11, 2};
  uint8_t * prt1 = arry1;
  if(ptr1 == NULL)
  {
     return FAILED;
  }
  my_memzero(prt1, SIZE);
  return PASS;
}
int8_t reverse_tests(void)
{
  if(ptr == NULL)
  {
     return FAILED;
  }
   /*declare an array and a pointer to test my_reverse*/
  uint8_t arry1_reverse[SIZE] = {15, 19, 14, 13, 11, 2};
  uint8_t arry2_reverse[SIZE-1] = {1, 20, 135, 2, 43};
  uint8_t * prt1_reverse = arry1_reverse;
  uint8_t * prt2_reverse = arry2_reverse;
  if(prt1_reverse == NULL || prt2_reverse == NULL  )
  {
     return FAILED;
  }
  /*testing my_reverse even function*/
  my_reverse(prt1_reverse, SIZE);
  /*testing my_reverse odd function*/
  my_reverse(prt2_reverse, SIZE-1);
  return PASS;
}


int8_t main(void)
{
  const struct CMUnitTest test[]={
     cmocka_unit_test(memmove_tests),
     cmocka_unit_test(memset_tests),
     cmocka_unit_test(memzero_tests),
     cmocka_unit_test(reverse_tests),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}

