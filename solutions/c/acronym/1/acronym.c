// #include "colour.h"
#include <ctype.h>
#include <regex.h>
#include <stdlib.h>
#include <string.h>

char* abbreviate(const char* lng);

char* any(const char *s, const char *rm);

char* any(const char *s, const char *rm) {
  char *spc = 0;
  spc = malloc(10);
  int i,k;
  for(i=k=0; s[i] != '\0'; i++) {
    for(int j=0; rm[j] != '\0'; j++)
      if(s[i] == rm[j]) {
        // printf(BLU" %c" BOLD_GRN" loc8ed "BROWN"@"MAG" idx %d\n",s[i],i);
        spc[k++] = i;
        j++;
      }
  }
  spc[k] = '\0';
  return spc;
}

char* abbreviate(const char* lng) {
  if (lng == NULL || strcmp(lng, "") == 0)
    return NULL;

  const char* idx = any(lng," -"); //quirky _'s??

  char *s; s = malloc(21);
  s[0] = lng[0]; // strcat(s, &lng[0]);strcat(s, &lng[t]);

  for (int i = 1, j = 0; idx[j] != '\0';) {
    int t = idx[j++]+1;
    if (lng[t] == '_')
      t++;
    // if (lng[t] != (' ' || '-'))
    if (lng[t] != ' ' && lng[t] != '-')
      s[i++] = lng[t];
  }

  for (int i = 0; *(s+i) != '\0'; i++) {
    if (isalpha(*(s+i)))
      *(s+i) = toupper(*(s+i));
  }
  return s;
}
