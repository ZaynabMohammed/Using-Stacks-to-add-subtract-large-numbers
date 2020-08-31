#include <iostream>
#include <string.h>
#ifndef STACK_H_
#define STACK_H_
class stack
{
   public:
	void xox (char arg[],char n1[],char n2[],char & s,unsigned int & d1,unsigned int &d2);
	void seperate(char n1[],char n2[],unsigned int& d11,unsigned int& d22,char s,int frac1[20],int frac2[20],int real1[20],int real2[20]);
	void add_sub_real (int real1[20],int real2[20],char s,int d1,int d2,int frac_carry,int frac_borrow);
	void add_sub_frac (int frac1[20],int frac2[20],char s,int &frac_carry,int &frac_borrow,int l,bool & flag,bool equal);




};

#endif /* STACK_H_ */
