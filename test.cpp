#include <iostream>
#include <fstream>
#include "String.h"


//  test the String class

int main()
{
   String first;
   cout<<sizeof(String);
   cout<<"sizeof(first)->"<<sizeof(first);

   int *p;
   cout<<"sizeofpointer->"<<sizeof(p);
   cout<<"sizeofint->"<<sizeof(int);
   String second;
   String third;
   String c1("ABCD");
   String c2("EF");
   String c3(c1+c2);
   cout<<"c3->"<<c3<<endl;
   cout<<sizeof(c1);
   cout<<"Cmapring c1(ABCD) and char abcd->(c1==\"ABCD\")->"<<(c1=="ABCD")<<std::endl;
   int len;
   int end;
   int ok;
   char ch;
   const String cFour("Hello Constant");
   cout<<cFour.length();
   cFour.at(0,ch);
   cout<<"char at 0th place in cFour->"<<ch<<endl;
   cout<<cFour[2]<<endl;
   String five("Five");
   cout<<five[2]<<endl;
   five[2]='S';
   cout<<five[2]<<endl;
   cout<<five<<endl;
   //cFour=second; ->gives error since cFour is constant and = modifes this;
   cout << "Enter a string: \n";
   cin >> first;
   len = first.length();
   end = len / 2;
   ok = first.substring(second,0,end);

   ok = first.substring(third,end+1,len-1);
   first = (third + second);

   cout << "\nNew version of string: ";
   cout << endl << first << endl << endl;
   ok = first.at(4,ch);
   if (ok)
      cout << "The 5th char of the new string is "
                             << ch << endl;
   else
      cout << "The new string has less than 5 char\n";
   ok = first.find('a');
   if (ok != -1)
      cout << "The first place a was found is loc "
                             << ok << endl;
   else
      cout << "There was no a in the new string\n";
   cout << endl;
   if (first == "how about it")
      cout << "The strings match\n";
   else
      cout << "The strings don't match\n";
}
