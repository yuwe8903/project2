#include <stdarg.h>
#include <cmocka.h>
#include <stdint.h>
#include "data.h"
#define PASS (0)
#define FAILED (1)

int8_t endianness_tests(void)
{
  int8_t ret;
  uint32_t da = 0x1234567;
  uint32_t * ptr = &da;
  if(ptr == NULL)
  {
     return FAILED;
  }
  ret = swap_data_endianness((uint8_t*)ptr, sizeof(da));
  uint32_t * ptr = &ret;
  ret = swap_data_endianness((uint8_t*)ptr, sizeof(da));
  return PASS;
}

int8_t main(void)
{
  const struct CMUnitTest test[]={
     cmocka_unit_test(endianness_tests),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}

