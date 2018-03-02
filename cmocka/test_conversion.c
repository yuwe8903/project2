#include <stdarg.h>
#include <cmocka.h>
#include <stdint.h>
#include "conversion.h"
#define PASS (0)
#define FAILED (1)

uint8_t str[] = "10110";
uint8_t * ptr_atoi = str;
uint8_t  itoa[50];
uint8_t * ptr_itoa = &itoa;
int8_t atoi_tests(void *ptr_atoi)
{
  if(ptr == NULL)
  {
     return FAILED;
  }
  uint8_t digits = 6;
  uint32_t base_atoi = 2;
  int8_t value;
  value =  my_atoi(ptr_atoi, digits, base_atoi);
  return PASS;
}

int8_t itoa_tests(void *ptr_itoa)
{
  if(ptr == NULL)
  {
     return FAILED;
  }
  uint32_t number = -1234;
  uint8_t n;
  n = my_itoa(number, ptr_itoa, 10);
  return PASS;
}

int8_t main(void)
{
  const struct CMUnitTest test[]={
     cmocka_unit_test(atpi_tests),
     cmocka_unit_test(itoa_tests),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}

