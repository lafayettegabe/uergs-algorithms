#include <stddef.h>

int find_smallest_int(int *vec, size_t len)
{
    int a = vec[0];
    for (int i = 0; i < len; i++)
    {
      if (a >= vec[i])
            a = vec[i];
    }
  
    return a;
}
