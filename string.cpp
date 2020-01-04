#include <iostream>
#include <fstream>
#include "String.h"

//  constructor that initializes from an array of char
String::String(const char *init)
{
//  find the length of the initializing array (look
//  for null byte)
   len = 0;
   while (init[len] != '\0')
   {  cout<<init[len]<<"\n";
	   len++;


   }

//  allocate space and copy chars into invoking obj
   theChars = new char[len];
   for (int i = 0 ; i < len ; i++)
      theChars[i] = init[i];
}

//  copy constructor
String::String(String& old)
{
//  check whether we are copying the empty string
   len = old.len;
   if (len == 0)
      theChars = NULL;

//  if not, copy the chars into the new array and
//  copy the length
   else
   {
      theChars = new char[len];
      for (int i = 0 ; i < len ; i++)
         theChars[i] = old.theChars[i];
   }
}

//  destructor
String::~String()
{
   if (len > 0)
      delete [] theChars;
}

//  overloaded << operator to print a String
ostream& operator<<(ostream& out, String& prt)
{
   for (int i = 0 ; i < prt.len ; i++)
      out << prt.theChars[i];
   return out;
}

istream& operator>>(istream &in,String& s)
{
	char holder[100];
	in.getline(holder,100);
	cout<<"Just read "<<in.gcount()<<" chaarcters\n";
	cout<<"You Entered "<<holder<<"<<<and storing this\n";
	String tmp(holder);
	s=tmp;
	return in;
}

//  concatenate the parm and the invoking String and
//  return the resulting String
String& String::operator+(const String& two)
{
   cout<<"opersator +\n";
	String result;
   int i;

//  if both Strings are empty, result is empty too
   if (len == 0 && two.len == 0)
   {
      cout<<"both zero";
	   result.len = 0;
      result.theChars = NULL;
   }
   else
   {

//  find length of the result and get space for it

	   result.len = len + two.len;
      result.theChars = new char[result.len];
      cout<<"result len->"<<result.len<<endl;

//  copy the invoking String into the new String
      for (i = 0 ; i < len ; i++)
      {
	     cout<<"copying the item from FIRST"<<theChars[i];
    	  result.theChars[i] = theChars[i];
      }

//  copy the parm at the end of the new String
      int j = 0;
      while (j < two.len)
	  {
    	  cout<<"copying the item from FIRST"<<two.theChars[j];
    	  result.theChars[i] = two.theChars[j];
	     i++;
	     j++;
	  }
   }
   cout<<"result is in operator +"<<result<<endl;
   return result;
}

//  return the character at the given position in the
//  parm ch. if position is invalid return false;
//  otherwise return true
int String::at(int position, char& ch) const
{
   int returnCode = 0;
   if (position >= 0 && position < len)
   {
      ch = theChars[position];
      returnCode = 1;
   }
   return returnCode;
}

int String::operator==(const String& two)
{
   int ret = 1;
   if (this->len != two.len)
      ret = 0;
   else
      for (int i = 0 ; i < this->len && ret == 1 ; i++)
         if (this->theChars[i] != two.theChars[i])
	        ret = 0;
  return ret;
}

//  test whether two Strings are equal; return true if
//  so, false if not
/*
int operator==(const String &one, const String& two)
{
   int ret = 1;
   if (one.len != two.len)
      ret = 0;
   else
      for (int i = 0 ; i < one.len && ret == 1 ; i++)
         if (one.theChars[i] != two.theChars[i])
	        ret = 0;
  return ret;
}
*/

//  test whether a String object contains the same
//  string as an array of char
/*int operator==(const String& one, char *chstr)
{
   int equal = 1;
   int stlen = 0;

//  find the length of the array of characters
   while (chstr[stlen] != '\0')
      stlen++;

//  if the lengths are equal, check whether all the
//  characters are equal
   if (one.len == stlen)
      for (int i = 0 ; i < one.len ; i++)
      {
	     if (one.theChars[i] != chstr[i])
	        equal = 0;
      }
   else
      equal = 0;
  return equal;
}*/

int operator==( String &one,char* two)
		{
	String tmp(two);
	return (one==two);

		}
//  test whether a String object contains the same
//  string as an array of char
int operator==(char *chstr,const String& one)
{
   int equal = 1;
   int stlen = 0;

//  find the length of the array of characters
   while (chstr[stlen] != '\0')
      stlen++;

//  if the lengths are equal, check whether all the
//  characters are equal
   if (one.len == stlen)
      for (int i = 0 ; i < one.len ; i++)
      {
	     if (one.theChars[i] != chstr[i])
	        equal = 0;
      }
   else
      equal = 0;
   return equal;
}

//  copy the parm into the invoking object
String& String::operator=( String& two)
{
	cout<<"opersator =\n";
	cout<<"two->"<<two;
	int a;
	cin>>a;
	if (theChars > 0)
      delete [] theChars;
   len = two.len;

   cout<<"op=  len->"<<len  <<endl;
   int b;
   cin>>b;
   theChars = new char[len];
   for (int i = 0 ; i < len ; i++)
   {
      theChars[i] = two.theChars[i];
      cout<<"copying "<<two.theChars[i];
   }
   cout<<"\n*this->"<<*this;
   return *this;
}

int String::find(char ch) const
{

	for(int i=0;i<len;i++)
	{
		if(theChars[i]==ch)
			return i;
	}
	return -1;
}

int String::substring(String &s,int start,int length) const
{
	cout<<"substring...\n"<<start<<"len->"<<length;
	cout<<"s->"<<s<<endl;
	cout<<"this->"<<this<<endl;
	if(start<0 || len<(start+length))
		return -1;
	int j=0;
	char holder[length];
	for(int i=start;i<length;i++,j++)
	{	//s.theChars[j]=this->theChars[i];
		cout<<".\n";
		holder[j]=this->theChars[i];
	}
	holder[j]='\0';

	String tmp(holder);
	s=tmp;
	return 0;



}
char String::operator[] (int index) const
{
	cout<<"uisng const one\n";
	if(index>0 && index<len)
		return theChars[index];
		else
			return '0';
}
char& String::operator[] (int index)
{
	if(index>0 && index<len)
		return theChars[index];
		else
			throw "BAD INDEX";
			//return '0';
}
/*

String String::operator+(const String &two) const
{
	if(this->len==0)
		return two;
	else
	{
		int totallength=this->len+two.len;
		char *newstr=new char[totallength];
		for(int i=0;i<len;i++)
			newstr[i]=this->theChars[i];
		for(int i=0;i<two.len;i++)
			newstr[len+i]=two.theChars[i];
		return String(newstr);
	}
}


String& String::operator=(const String& two)
{
	if(two.theChars!=this->theChars)
	{


		char *newptr=new char[two.len];
		for(int i=0;i<two.len;i++)
			newptr[i]=two[i];
		if(this->theChars!=NULL)
			delete[] this->theChars;
		this->theChars=newptr;
		this->len=two.len;
	}
		return *this;
}*/

