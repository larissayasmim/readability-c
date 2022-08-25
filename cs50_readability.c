#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main (void)

{
    string text = get_string("Text: ");

   int letters= 0;
   int words=1;
   int sentences=0;

   for(int i = 0; i < strlen (text);i++)
    {

        //uppercase                      lowercase
   //if ((text[i]>65 && (text[i]<90) || (text [i]>97 && (text[i]<122)) este pode ser substituído por isalpha/isupper/islower

   //letters ++;
     if (isalpha (text[i]))
      {
          letters++;
      }


      else if (text[i]==' ')
      {
        words++;
      }

      else if(text[i]=='.' || text [i]==',' || text [i]=='!' || text [i]== '?')
   {
      sentences ++;
   }
   }

  //Índice Coleman-Liau
  float L=(float)letters / (float) words * 100;
  float S=(float)sentences / (float) words *100;

  int index = round (0.0588*L-0.296*S-15.8);

  
  //Determinar o nível escolar
  if (index <1)
  {
      printf("Before grade 1\n");

  }
  else if(index >=16)
  {
      printf("Grade +16\n");
  }
   else
  {
      printf("Grade %i \n", index);
  }

}

  
