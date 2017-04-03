//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#include <stack>

//---------------------------------------------------------------------------

#pragma argsused
struct Stack
{				// Декларация структурного типа
   int info;
   Stack * next;
} *begin, *t, *b;


//------------ Декларации прототипов функций пользователя ----------
Stack* InStack(Stack*, int);
void View(Stack*);
void Task1(Stack*, int*, int);
void Del_All(Stack **);

//--------------- Функция добавления элемента в Стек ------------------------
Stack* InStack(Stack *p, int in)
{
   Stack *t = new Stack;
   t -> info = in;
   t -> next = p;
   return t;
}
//----------------- Функция просмотра Стека----------------------------------
void View(Stack *p)
{
   Stack *t = p;
   while( t != NULL)
   {
      cout << "   " << t->info << endl;
      t = t -> next;
   }
}
//----------------------- Функция освобождения памяти -----------------------
void Del_All(Stack **p)
{
   while(*p != NULL)
   {
      t = *p;
      *p = (*p) -> next;
      delete t;
   }
}
//----------------------Найти числа, заканчивающиеся на 5, и удалить их
void Task1(Stack *p, int *mas, int size)
   {
      int j = 0, m, k;
      Stack *t = p;
      while( t != NULL)
         {
            mas[j] = t->info;
            j++;
            t = t -> next;
          }
      for (k = j = 0; j < size; j++)
      {
          if (mas[j]%10 != 5)
          {
              mas[k++] = mas[j];
          }
      }
      Del_All(&begin);
      for (int v = --k; v >= 0; v--)
          begin = InStack(begin, mas[v]);
      View(begin);
      delete []mas;
   }

//---------------------------------------------------------


int main(int argc, char* argv[])
{
   int i, in, n, kod, zapolnen;
   while(true){
   cout << "\n\t\----- Menu -----\n\tCreate stack - 1.\n\tAdd elements - 2.\n\tView - 3.\n\tDelete stack - 4.\n\tTask - 0.\n\tExit - else.  :  " ;
   cin >> kod;
   switch(kod)
   {
      case 1: case 2:
         if(kod == 1 && begin != NULL)
         {
         // Если создаем новый стек, должны освободить память, занятую предыдущим
            cout << "Stack is already created!" << endl;
            break;
         }
         cout << "Input the number of elements: ";
         cin >> n;
         cout << "\nDo you want to fill the stack by yourself? 1 - Yes, else - No : ";
         cin >> zapolnen;
         for(i = 1; i <= n; i++)
         {
            if (zapolnen == 1)

               cin >> in;
            else
               in = random(20);
            begin = InStack(begin, in);
         }
         if (kod == 1) cout << "Create " << n << " elements" << endl;
         else cout << "Add " << n << " elements" << endl;
      break;
      case 3:
         if(!begin)
         {
            cout << "Stack is free!" << endl;
            break;
         }
         cout << "------ Stack ------" << endl;
         View(begin);
      break;
      case 4:    
         Del_All(&begin);
         cout<<"Stack deleted!"<<endl;
      break;
      default:
         if(begin != NULL)
            Del_All(&begin);
         return 0;		// Выход - EXIT
      case 0:
         int size=0;
         t = begin;
         while( t != NULL)
         {
            size++;
            t = t -> next;
          }
         int *mas = new int[size];

         Task1(begin, mas, size);

         break;

   }
}
}



//---------------------------------------------------------------------------
 