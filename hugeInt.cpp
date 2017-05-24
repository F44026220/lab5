#include "hugeInt.h"

HugeInt::HugeInt(long int input)
{
 int i;
 
 for (i=0; i<SIZE_ARR; ++i)
     ptr[i]=0;  //initialize

 if (input<0) {
    sign=-1;
    input=-input;
   }
 else
    sign=1;

 for (i=0; i<SIZE_ARR; ++i) {
     ptr[i]=(int)(input%10);
     input=(int)(input/10);
    }
}

HugeInt::HugeInt(string input)
{
 int i, lengh;

 for (i=0; i<SIZE_ARR; ++i)
     ptr[i]=0;  //initialize

 lengh=input.size();

 if (input[0]=='-') {
    sign=-1;
    for (i=0; i<lengh-1; ++i)
        ptr[i]=input[lengh-1-i]-'0'; //char to int
   }
 else {
    sign=1;  
    for (i=0; i<lengh; ++i)
        ptr[i]=input[lengh-1-i]-'0'; //char to int
   }
}

HugeInt HugeInt::operator + (HugeInt input)
{
 int i, current, carry=0;
 HugeInt New;

 if (sign==input.sign) {
    if (sign==1) {
       for (i=0; i<SIZE_ARR; ++i) {
           current=ptr[i]+input.ptr[i]+carry;
           New.ptr[i]=current%10;
           carry=current/10;
          }
       New.sign=1;
      }
    else {
       for (i=0; i<SIZE_ARR; ++i) {
           current=ptr[i]+input.ptr[i]+carry;
           New.ptr[i]=current%10;
           carry=current/10;
          }
       New.sign=-1;
      }      
   }
 else {
    if (sign==1) 
       input.sign=1;
    else 
       input.sign=-1;
    return *this-input;
   }

 return New;
}

HugeInt HugeInt::operator - (HugeInt input)
{
 int i, borrow=0;
 HugeInt New;

 if (sign==input.sign) {
    if (sign==1) {
       if (*this>=input) {
          for (i=0; i<SIZE_ARR; ++i) {
              New.ptr[i]=ptr[i]-input.ptr[i]-borrow;
              if (New.ptr[i]<0) {
                 New.ptr[i] += 10;
                 borrow=1;
                }
              else
                borrow=0;
             }
          New.sign=1;
         }
       else {
          for (i=0; i<SIZE_ARR; ++i) {
              New.ptr[i]=input.ptr[i]-ptr[i];
              if (ptr[i]<0) {
                 New.ptr[i] += 10;
                 borrow=1;
                }
              else
                borrow=0;
             }
          New.sign=-1;
         }
      }
    else {
       New=*this;
       New.sign=1;
       input.sign=1;
       return input-New;
      }
   }
 else {
    if (sign==1)
       input.sign=1;
    else
       input.sign=-1;
    return *this+input;
   }

 return New;
}

const HugeInt & HugeInt::operator = (const HugeInt & input)
{
 int i;

 for (i=0; i<SIZE_ARR; ++i)
     ptr[i]=input.ptr[i];

 return *this;
}

bool HugeInt::operator >= (const HugeInt & input)
{
 int i;

 for (i=SIZE_ARR-1; i>=0; --i) {
     if (ptr[i]!=input.ptr[i])
        break;
    }

 if (sign==input.sign) {
    if (i>=0) {
       if (sign==1) {
          if (ptr[i]>input.ptr[i])
             return true;
          else
             return false;
         }
       else {
          if (ptr[i]>input.ptr[i])
             return false;
          else
             return true;
         }
      }
    else
      return true;
   }
 else {
   if (sign=1)
      return true;
   else
      return false;   
  }
}

istream & operator >> (istream & in, HugeInt & input)
{
 long int buf;
 int i;

 in >> buf;

 if (buf<0) {
    input.sign=-1;
    buf=-buf;
   }
 else
    input.sign=1;

 for (i=0; i<SIZE_ARR; ++i) {
     input.ptr[i]=(int)(buf%10);
     buf=(int)(buf/10);
    }

 return in;
}

ostream & operator << (ostream & out, const HugeInt & output)
{
 int i, j;

 if (output.sign==-1)
    cout << '-';

 i=SIZE_ARR-1; 
 while (i>=0 && output.ptr[i]==0)
     --i;
 for (j=i; j>=0; --j)
     cout << output.ptr[j];

 return out;
}
