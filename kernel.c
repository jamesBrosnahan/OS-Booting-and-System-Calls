﻿/* ACADEMIC INTEGRITY PLEDGE                                              */
/*                                                                        */
/* - I have not used source code obtained from another student nor        */
/*   any other unauthorized source, either modified or unmodified.        */
/*                                                                        */
/* - All source code and documentation used in my program is either       */
/*   my original work or was derived by me from the source code           */
/*   published in the textbook for this course or presented in            */
/*   class.                                                               */
/*                                                                        */
/* - I have not discussed coding details about this project with          */
/*   anyone other than my instructor. I understand that I may discuss     */
/*   the concepts of this program with other students and that another    */
/*   student may help me debug my program so long as neither of us        */
/*   writes anything during the discussion or modifies any computer       */
/*   file during the discussion.                                          */
/*                                                                        */
/* - I have violated neither the spirit nor letter of these restrictions. */
/*                                                                        */
/*                                                                        */
/*                                                                        */
/* Signed:_____________________________________ Date:_____________        */
/*                                                                        */
/*                                                                        */
/* 3460:4/526 BlackDOS kernel, Version 1.03, Spring 2017.                 */

void printString(char*);
void readString(char*);
void writeInt(int);
void readInt(int*);

void main()
{
   char line[80];
   int x;
   
   /* makeInterrupt21(); */
   clearScreen(0,0);

   printString("___.   .__                 __       .___           \r\n\0");
   printString("\\_ |__ |  | _____    ____ |  | __ __| _/___  ______\r\n\0");
   printString(" | __ \\|  | \\__  \\ _/ ___\\|  |/ // __ |/ _ \\/  ___/\r\n\0");
   printString(" | \\_\\ \\  |__/ /\\ \\\\  \\___|    </ /_/ ( <_> )___ \\ \r\n\0");
   printString(" |___  /____(____  /\\___  >__|_ \\____ |\\___/____  >\r\n\0");
   printString("     \\/          \\/     \\/     \\/    \\/         \\/ \r\n\0");
   printString(" V. 1.03, C. 2017. Based on a project by M. Black. \r\n\0");
   printString(" Author(s): your name(s) here.\r\n\r\n\0");
   
   printString("Hola mondo.\r\n\0");
   printString("Enter a line: \0");
   readString(line);
   printString("\r\nYou typed: \0");
   printString(line);
   printString("\r\n\0");
   /* x = 5; */
   /* printString("Your number is \0"); */
   /* writeInt(x); */
   /* printString("\r\n\0"); */
   while(1);
}

void printString(char* c)
{
   /* Fill this in. */
   const char ah = 14;
   int index = 0;
   while(c[index] != '\0'){
        interrupt(16, ah*256+c[index], 0, 0, 0);
        index++;
   }
   
   return;
}

void readString(char* c)
{
   /* This too. */
   int index = 0;
   while(c[index] != 0xD){
        c[index] = interrupt(22, 0, 0, 0, 0);
        if(c[index] = 0xD){
            printString(c);
        }else if(c[index] = 0x8 && index > 1){
            index -= 2;
        }else{
            interrupt(16, ah*256+c, 0, 0, 0);
            index++;
        }
   }
   return;
}

void clearScreen(int bx, int cx)
{
	/* This too. */
	return;
}

int mod(int a, int b)
{
   int x = a;
   while (x >= b) x = x - b;
   return x;
}

int div(int a, int b)
{
   int q = 0;
   while (q * b <= a) q++;
   return (q - 1);
}

void writeInt(int x)
{
   char number[6], *d;
   int q = x, r;
   if (x < 1)
   {
      d = number; *d = 0x30; d++; *d = 0x0; d--;
   }
   else
   {
      d = number + 5;
      *d = 0x0; d--;
      while (q > 0)
      {
         r = mod(q,10); q = div(q,10);
         *d = r + 48; d--;
      }
      d++;
   }
   printString(d);
}

void readInt(int* number)
{
   /* Fill this in as well. */
   return;
}

