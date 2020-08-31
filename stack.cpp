#include<fstream>
#include<string.h>
#include "stack.h"
using namespace std;

void stack::xox (char arg[],char n1[],char n2[],char &s,unsigned int & d1,unsigned int &d2)
{
    unsigned int i=0;
   unsigned int index=0;
    int j=0;

   for(i=0;i<strlen(arg);i++)
   {

       if((arg[i]=='+')||(arg[i]=='-'))
        {
    	    s=arg[i];
            index=i+1;
            //cout<<"index=="<<index<<endl;

        }
        else if( (index==0) && (arg[i]=='.') )
        {
           d1=i;
        }
        else if( (index>0) && (arg[i]=='.') )
        {
        	d2=i-index;
        }

   }
    //cout<<arg<<endl;
     if((s=='+')||(s=='-'))
     {
    	 for(unsigned int k=0;k<index-1;k++)
    	 {
	   //int x=arg[k];
	   n1[k]=arg[k];


    	 }
    	 //n1[i-1]='\0';

    	 for(unsigned int c=index;c<=strlen(arg);c++)
    	 {
    		 //int y=arg[c];
        n2[j]=arg[c];
       // cout<<n2[j]<<" ASCII "<<int(n2[j])<<endl;;
         j++;
    	 }
    	 // cout<<j<<endl;
    	 //  for(unsigned int c=0;c<j;c++)
    	 //  {
    	 //  	cout<<n2[c]<<"  "<<c<<endl;;
    	 //  }
    	 // cout<<endl;
     }

}
void stack::seperate(char n1[],char n2[],unsigned int& d11,unsigned int& d22,char s,int frac1[20],int frac2[20],int real1[20],int real2[20])
{
	//cout<<n1<<"   "<<n2<<endl;



		int f1=0,f2=0;
        // cout<<strlen (n2)<<endl;
		if(d11==0)
			{
			    //cout<<"here"<<endl;
				d11+=strlen(n1);
				//d11++;
			}
			if(d22==0)
			{
				d22+=strlen(n2);
				//d22++;
			}
			//cout<<d22<<endl;

		for(unsigned int x=0;x<d11;x++)
		{
			int u=int(n1[x]);
			//cout<<u<<" num1 "<<n1[x]<<"  ^O^" <<endl;
			real1[x]=u-48;

			//cout<<u<<" ascii re1 "<<real1[x]<<"  ^O^" <<endl;
		}
		//cout<<endl;
		for(unsigned int x=0;x<d22;x++)
		{
			int u=int(n2[x]);
			//cout<<u<<" num2 "<<n2[x]<<"  ^O^" <<endl;
			real2[x]=u-48;
			//cout<<u<<" ascii re2 "<<real2[x]<<"  ^O^" <<endl;
		}

		for(unsigned int x=d11+1;x<strlen(n1);x++)
		{
			int u=int(n1[x]);
			frac1[f1]=u-48;
			//cout<<u<<" ascii  fr1 "<<frac1[x]<<"  ^O^" <<endl;
			f1++;
		}
		for(unsigned int x=d22+1;x<strlen(n2);x++)
		{
			int u=int(n2[x]);
			frac2[f2]=u-48;
			//cout<<u<<" ascii fr2 "<<frac2[x]<<"  ^O^" <<endl;
			f2++;
		}

}



void stack::add_sub_real (int real1[20],int real2[20],char s,int d1,int d2,int frac_carry,int frac_borrow)
{
       //////////real_sum///////////
	int sum_real[30];
	for(int u=0;u<20;u++)
	{
		sum_real[u]=0;
	}
   // int sum_frac[30];
    int z1=d1;
    int z2=d2;
    int index,len;
    int carry=0;
    //int frac_carry=0;
    int borrow=0;//,frac_borrow=0;
    if(d1>d2)
    {
    	index=d1+1;
    	len=d1+1;
    }
    else
    {
    	index=d2+1;
    	len=d2+1;
    }

 //%%%%%%%%%%%%%%%%%%%%%%%

	while((z1>0)&&(z2>0))
	{
		z1-=1;
		z2-=1;
		index-=1;
		//cout<<s<<endl;
		if(s=='+')
		{
			   if(frac_carry==1 && (index==d1 ||index==d2))
			   {
				   real1[z1]=real1[z1]+frac_carry;
				   frac_carry=0;
			   }
			 //cout<<real1[z1]<<"   z1="<<z1<<"********"<<real2[z2]<<"  z2="<<z2<<endl;
			sum_real[index]= real1[z1]+real2[z2]+carry;
			carry=0;
			if(sum_real[index]-10>=0)
				{
				carry=1;
				sum_real[index]=sum_real[index]-10;
				}
			 // cout<<sum_real[index]<<"index"<<index<<endl;
	       }
		else
			{
			 	 if(frac_borrow==1 && (index==d1 ||index==d2))
			 	 {
			 		//cout<<real1[z1]<<"    z1      "<<z1<<endl;
			 		 real1[z1]=real1[z1]-frac_borrow;
			 		// cout<<frac_borrow<<"    "<<real1[z1]<<endl;
			 		 frac_borrow=0;
			 	 }
				sum_real[index]= real1[z1]-real2[z2]-borrow;
				//cout<<real1[z1]<<"********"<<real2[z2]<<endl;
				borrow=0;
				if(sum_real[index]<0)
				{
					borrow=1;
					sum_real[index]=sum_real[index]+10;
				}
				//cout<<sum_real[index]<<"index"<<index<<endl;
			}
	}
    if((z1==0)&&(z2!=0))
    {
    	//cout<<"////"<<endl;
    	while(z2>=0)
    	{
    		z2--;
    		index--;
    		if(s=='+')
    		{
    			if(carry==1)
    			{
    			  // cout<<"jjjjjj"<<endl;
    			   real2[z2]=real2[z2]+1;
    				if(real2[z2]-10>=0)
    				{
    					carry=1;
    					real2[z2]=real2[z2]-10;
    				}
    				else
    				{
        			    carry=0;
    				}
    			}
    		  sum_real[index]=real2[z2]+0 ;
    		 // cout<<"real2[z2]"<<real2[z2]<<endl;
    		 // cout<<sum_real[index]<<endl;
    		}
    		else
    		{
    			if(borrow==1)
    			{
    				real2[z2]=real2[z2]-1;
    				if(real2[z2]<0)
    				{
    					borrow=1;
    					real2[z2]=real2[z2]+10;
    				}
    				else
                    {
    					borrow=0;
                    }
    			}
    		   sum_real[index]=real2[z2]-0;
    		}
    	}
    }


   // cout<<z1<< "  "<<index<<"  "<<z2<<endl;
    if((z2==0)&&(z1!=0))
    {
    	//cout<<"////"<<endl;
    	while(z1>=0)
    	{
    		//cout<<"here"<<endl;
    		z1--;
    		index--;

    		if(s=='+')
    		{
    			if(carry==1)
    			{
    			   //cout<<"jjjjjj"<<endl;
    			   real1[z1]=real1[z1]+1;
    				if(real1[z1]-10>=0)
    				{
    					carry=1;
    					real1[z1]=real1[z1]-10;
    				}
    				else
    				{
        			    carry=0;
    				}
    			}
    			sum_real[index]=real1[z1]+0;
    			//cout<<sum_real[index]<<"index****  "<<index<<endl;
    		}
    		else
    		{
    			if(borrow==1)
    			{
    				real1[z1]=real1[z1]-1;
    				if(real1[z1]<0)
    				{
    					borrow=1;
    					real1[z1]=real1[z1]+10;
    				}
    				else
                    {
    					borrow=0;
                    }
    			}
    			sum_real[index]=real1[z1]-0;
    		}

    	}
    }


    //cout<<sum_real[0]<<endl;
    if(carry==1)
    {
    	//cout<<"///"<<endl;
    	sum_real[0]=1;
    }
    if(borrow==1)
    {
      sum_real[0]=0;
    }
    	if(sum_real[0]==1)
    	{
    		//cout<<"iiiiiiii"<<endl;
    		for(int i=0;i<len;i++)
    		cout<<sum_real[i];

    	}
    	else
    	{
    		int p=1;
    		for(int i=1;i<len;i++)
    			{
    				if(sum_real[i]==0)
    				{
    					 p++;
    					continue;
    				}

    			}
    		//cout<<p<<"  "<<len<<endl;
    		if((p!=len) && (sum_real[1]==0))
    		{
    			for(int i=p-1;i<len;i++)//************************have a  P-1
    			{
    				if((sum_real[p-1]==0)&&(i==p-1))
    				{
    					continue;
    				}
    				cout<<sum_real[i];
    			}
    		}
    		else if(p==len)
    		{
    			for(int i=len-1;i<len;i++)
    			cout<<sum_real[i];
    		}
    		else
    		{
    			for(int i=1;i<len;i++)
    			 cout<<sum_real[i];
    		}
    	}

}


void stack::add_sub_frac (int frac1[20],int frac2[20],char s,int &frac_carry,int &frac_borrow,int l,bool & flag,bool equal)
{

	int sum_frac [20];
	frac_carry=0;
	frac_borrow=0;
	 /////////////////frac_sum/////////////////
	  for(int i=l-1;i>=0;i--)
	  {

		 if(s=='+')
		 {
		 		  sum_frac[i]=frac1[i]+frac2[i]+frac_carry;
		 		// cout<<frac1[i]<<"   "<<frac2[i]<<endl;
		 	     frac_carry=0;
		 	   if(sum_frac[i]-10>=0)
		 	 	 {
		 		 frac_carry=1;
		 		 sum_frac[i]=sum_frac[i]-10;
		 	 	 }
		 }
		 else
		 {
		 		  sum_frac[i]=frac1[i]-frac2[i]-frac_borrow;
		 		  frac_borrow=0;
		 		  if(sum_frac[i]<0)
		 		  {
		 		 		 frac_borrow=1;
		 		 		 sum_frac[i]=sum_frac[i]+10;
		 		  }
		 }
	  }
	  if(flag==true)
	  {


		  if( (sum_frac[l-1]==0) && (equal==false) )
		  {
			  int p;
			  for(int i=l-1;i>=0;i--)
			  {
			    if(sum_frac[i]==0)
			    {
			    	p=i;
			    	continue;
			 	}
			    else if(sum_frac[i]!=0)
			    {
			    	break;
			    }
			  }
			  //cout<<endl;
			 // cout<<p<<"hhhhhhhhhhhh"<<endl;
			  if(p!=0)
			      {
				  	  for(int i=0;i<p;i++)
			 		 	{
			 		 		 cout<<sum_frac[i];
			 		 	}
			      }
			  else if(p==0)
			  {
				  for(int i=0;i<l;i++)
				  {
					  cout<<sum_frac[i];
				 }
			  }
		  }
		  else
		  {
			  for(int i=0;i<l;i++)
			  {
				  cout<<sum_frac[i];
			  }
		  }
	  }
	  flag=true;
}



