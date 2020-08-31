//============================================================================
// Name        : a7.cpp
// Author      : zaynab
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
#include "stack.h"
using namespace std;


int main(int argc,char* argv[])
{
	stack my_stack;
	unsigned int dot1=0,dot2=0;
	int frac_carry,frac_borrow;
	unsigned int l1,l2;//,index;
	char num1[50],num2[50];
	int frac1[20], frac2[20],real1[20],real2[20];
	char sign;
	int l;
	bool flag=false,equal=false;
	for(int r=0;r<50;r++)
	{
		num1[r]='\0';
		num2[r]='\0';
	}
	for(int u=0;u<20;u++)
	{
		frac1[u]=0;
		frac2[u]=0;
		real1[u]=0;
		real2[u]=0;
	}


	bool flag1=false,flag2=false,flag3=false,flag4=false;
    string total_num=argv[1];
    int len=total_num.length();
    char str[len+1];
    strcpy(str,total_num.c_str());
   //%%%%%%%%%%%%%%_ERROR_Handling%%%%%%%%%%%%%%%%%%%%%%%%%

    for(int e=0;e<len;e++)
    {
    	if( ((str[e]>=97) && (str[e]<=122)) || ((str[e]>=65) && (str[e]<=90)) )
    	{
    		cout<<"Invalid input"<<endl;
    		return 0;
    	}
       else if( (str[e]=='+') && (str[e+1]=='-'))
    	{
    		flag1=true;
    		//cout<<"hello"<<endl;
    		//cout<<str[e]<<"       "<<str[e+1]<<endl;
    		break;
    	}
    	else if (str[e]=='/' || str[e]=='%' || str[e]=='*' )
    	{
    		flag2=true;
    		//cout<<str[e]<<"   2222222222    "<<str[e+1]<<endl;
    		break;
    	}
    	else if( (str[e]=='.') && ((str[e+1]=='-')||(str[e+1]=='+')))
        	{
        		flag1=true;
        		//cout<<"hello"<<endl;
        		//cout<<str[e]<<"       "<<str[e+1]<<endl;
        		break;
        	}

    }

    if( flag1==true ||flag2==true)
    {
    	cout<<"Invalid input"<<endl;
    	flag1=false;
    	flag2=false;
        return 0;
    }

  //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
   my_stack. xox(str,num1,num2,sign,dot1,dot2);
   unsigned int xox_dot1=dot1;
   unsigned int xox_dot2=dot2;
   //cout<<num1<<" d1    "<<xox_dot1   <<endl;
   //cout<<num2<<"  d2      "<<xox_dot2<<endl;
   //cout<<sign<<"  sign   "<<endl;
   if(num1[0]=='.')
      {
      	cout<<"Invalid input"<<endl;
      	return 0;
      }

  if( (sign!='+')&&(sign!='-') )
  {
	 cout<<"Invalid input"<<endl;
	      	return 0;
  }

//%%%%%%%%%%%%%%_ERROR_Handling%%%%%%%%%%%%%%%%%%%%%5
    int sum_of_dots1=0,sum_of_dots2=0;
    for(unsigned int e=0;e<strlen(num1);e++)
    {
    	if (num1[e]=='.')
    	{
    		sum_of_dots1+=1;
    	}
    	else if(!( (num1[e]>=48) && (num1[e]<=57) ))
    	{
    		flag3=true;
    		//cout<<"1111111111111    "<<num1[e]<<endl;
    		break;
    	}
    }
    if (sum_of_dots1>1 || flag3==true)
    {
    	cout<<"Invalid input"<<endl;
    	return 0;
    }
    for(unsigned int e=0;e<strlen(num2);e++)
        {
        	if (num2[e]=='.')
        	{
        		sum_of_dots2+=1;
        	}
        	else if(!(num2[e]>=48 && num2[e]<=57) )
        	{
        		flag4=true;
        		break;
        	}
        }
        if (sum_of_dots2>1 || flag4==true)
        {
        	cout<<"Invalid input"<<endl;
        	return 0;
        }

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%5
        l1=strlen(num1)-dot1-1;
        l2=strlen(num2)-dot2-1;
        //cout<<l1<<"  "<<l2<<endl;
       // cout<<xox_dot1<<"  "<<xox_dot2<<endl;
    if((l1>l2 )&& ((dot1!=0 && dot2!=0)))
    {

    	//cout<<"**************"<<endl;
    	for(unsigned int i=1;i<=(l1-l2);i++)
    	{
    		num2[dot2+l2+i]='0';
    	}
    		l=l1;
      //cout<<num1<<"       "<<num2<<endl;
    }
    else if((l2>l1 )&& ((dot1!=0 && dot2!=0)))
    {

    	for(unsigned int i=1;i<=(l2-l1);i++)
    	{
    		if(num2[3]=='4')
    		{
    			//cout<<"mmmmmmm"<<endl;
    		}
    		num1[dot1+l1+i]='0';
    	}
    		l=l2;
    		//cout<<num1<<"       "<<num2<<endl;
    }
    else if(l2==l1)
    {
    	l=l2;
    	equal=true;
    }
    else if((dot1==0 && dot2!=0))
    {
    	l=l2;
    }
    else if((dot2==0 && dot1!=0))
    {
        	l=l1;
    }






//%%%%%%%%%%%%%%%%%%55
       // cout<<num1<<"     "<<num2<<endl;
    my_stack.seperate(num1,num2,xox_dot1,xox_dot2,sign,frac1,frac2,real1,real2);
    int sep_dot1=xox_dot1;
    int sep_dot2=xox_dot2;
  // cout<<num1<<"    "<<sep_dot1<<endl;
   // cout<<num2<<"    "<<sep_dot2<<endl;
    int R1[20],R2[20],F1[20],F2[20];
    for (int t=0;t<20;t++)
    {
    	R1[t]=real1[t];
    	R2[t]=real2[t];

    }
    for (int t=0;t<20;t++)
    {
    	F1[t]=frac1[t];
    	F2[t]=frac2[t];
    }


    int summ=0;
    int summ2=0;
    unsigned int fake_dot1;
    //cout<<l<<endl;
    for(int i=0;i<l;i++)
    {
    	  summ+=(F1[i])+(F2[i]);
    	  //cout<<F1[i]<<"======================="<<F2[i]<<endl;
    }
    if(dot1==0)
    {
    	fake_dot1=dot1+strlen(num1);
    }
    else
    {
    	fake_dot1=dot1;
    }
    for(unsigned int i=0;i<fake_dot1;i++)
    {
        summ2+=(R1[i])+(R2[i]);
       //cout<<R1[i]<<"+++++++++++++++++++++"<<R2[i]<<endl;
    }
   // cout<<"summm="<<summ<<endl;
   // cout<<"summm2="<<summ2<<endl;
    if(summ==0 && summ2!=0 && (dot1!=0 && dot2!=0) )
    {
    	//cout<<"33333333"<<endl;
     my_stack.add_sub_real (R1,R2,sign,sep_dot1,sep_dot2,frac_carry,frac_borrow);
     cout<<"."<<summ<<endl;
    }
    else if(dot1==0 && dot2==0)
    {
    	my_stack.add_sub_real (R1,R2,sign,sep_dot1,sep_dot2,frac_carry,frac_borrow);
    	     cout<<endl;
    }
    else if(summ2==0 && summ!=0)
    {
    	cout<<summ2<<'.';
    	flag=true;
    	my_stack.add_sub_frac (F1,F2,sign,frac_carry,frac_borrow,l,flag,equal);
    	cout<<endl;
    }
    else if(summ2==0 && summ==0)
    {
    	cout<<summ2<<'.'<<summ<<endl;
    }
    else
    {
    	//cout<<"11111"<<endl;
    	flag=false;
    	my_stack.add_sub_frac (F1,F2,sign,frac_carry,frac_borrow,l,flag,equal);
    	int j=frac_carry;
    	int w=frac_borrow;
    	my_stack.add_sub_real (R1,R2,sign,sep_dot1,sep_dot2,j,w);
    	cout<<".";
    	my_stack.add_sub_frac (F1,F2,sign,frac_carry,frac_borrow,l,flag,equal);
    	cout<<endl;
    }

return 0;
}

