#include <stdbool.h>

bool is_uppercase(const char *source) 
{ 
  int i = 0;
  while (source[i] != '\0')
  {
    if ((int)source[i] >= 97 && (int)source[i] <= 122)
      return false;
    i++;
    
    if(source[i] == ' ')
      i++;
  }
  return true;
}
