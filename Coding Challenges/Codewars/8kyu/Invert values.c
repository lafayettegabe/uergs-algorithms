#include <stddef.h>

void invert(int *values, size_t values_size)
{
  int i = 0;
  if (values_size != 0)
    while(i <= values_size)
    {
      values[i] *= -1;
      i++;
    }
}
