#include <stdarg.h>
#include <cmocka.h>
#include <stdint.h>
#include "circbuf.h"
#define PASS (0)
#define FAILED (1)

CB_t buf;
CB_t *cbuf = &buf;
int8_t CB_tests(void *cbuf)
{
  if(cbuf == NULL)
  {
     return FAILED;
  }
  CB_init(cbuf, 16);
  uint8_t data1 = 3;  
  CB_buffer_add_item(cbuf, data1);
  CB_buffer_add_item(cbuf, data1);
  uint8_t data2 = 4;
  CB_buffer_add_item(cbuf, data2);
  CB_is_full(cbuf);
  CB_is_empty(cbuf);
  uint8_t * data = &data2;
  CB_buffer_remove_item(cbuf, data);
  CB_e CB_destroy(cbuf);
  return PASS;
}
int8_t main(void)
{
  const struct CMUnitTest test[]={  
    cmocka_unit_test(CB_tests),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}

