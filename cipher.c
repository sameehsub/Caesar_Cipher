#include "cipher.h"
#include <string.h>
#include <stdlib.h>

/// IN THIS FILE, IMPLEMENT EVERY FUNCTION THAT'S DECLARED IN cipher.h.


// See full documentation in header file
void cipher (char s[], int k)
{
  for (size_t i=0; i < strlen(s) ; i++)
  {
    unsigned char ascii = s[i];
    //int shift_value = k % 26;
    int shift_value = ((k % 26) + 26) % 26;
    if ( ascii>=65 && ascii<=90 )
    {
      s[i] = (char)(65 + (ascii - 65 + shift_value + 26) % 26);
    }
    else if( ascii >= 97 && ascii <= 122 )
    {
      s[i] = (char)(97 + (ascii - 97 + shift_value + 26) % 26);
    }
  }
}

// See full documentation in header file
void decipher (char s[], int k)
{
  for (size_t i=0; i < strlen(s) ; i++)
  {
    unsigned char ascii = s[i];
    int shift_value = k % 26;
    if ( ascii>=65 && ascii<=90 )
    {
      s[i] = (char)(65 + (ascii - 65 - shift_value + 26) % 26);
    }
    else if( ascii >= 97 && ascii <= 122 )
    {
      s[i] = (char)(97 + (ascii - 97 - shift_value + 26) % 26);
    }
  }
}

