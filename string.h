#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <fstream>
#include <ostream>
using namespace std;

class String
{
  friend int operator==(char*,const String&);
  //friend int operator==(const String&,const String&);
  int operator==(const String& two);
  friend int operator==( String&,char*);
  friend ostream& operator<<(ostream&,String&);
  friend istream& operator>>(istream&,String&);
public:
  //  constructors and destructor
  String() : len(0), dummy(0),theChars(NULL) { }
  String(const char *);
  String(String&);
  ~String();
  //  accessors
  int length() const { return len; }
  int at(int, char&) const;
  int find(char) const;
  int substring(String&,int,int) const;
  String& operator+(const String&) ;
  //  mutators
  String& operator=( String&);
  char& operator[] (int);
  char operator[] (int) const;
private:
  char *theChars;
  int len;
  int dummy;
};

#endif
