#include <iostream>
#include <string>
#include <algorithm> 
#include <cmath>

using namespace std;

int main()
{
   string runstr;
   cout << endl << "     Please, type RUN (or r) to start the program: ";
   getline (cin, runstr);
   
   unsigned int inputNum = 0;
   if(runstr=="RUN" or runstr=="r"){
     while(inputNum == 0){
       cout << endl << ">>> Please, specify the LENGTH of the fence in meters, " << endl << "    type only ONE POSITIVE INTEGER number, which is greater than 2: ";
       getline (cin, runstr);

       unsigned int charcounter = 0;
       for(unsigned int i = 0; i < runstr.length(); i++){
         if(isdigit(runstr[i]) == false or isblank(runstr[i]) == true or runstr=="0" or runstr=="1" or runstr=="2"  or runstr=="\n"){ //cut on the non-digital characters, zero, blank space, non-integer numbers, negative numbers, 1 & 2 
           cout << endl << "*** Warning! This is NOT a single positive number, which is greater than 2!" << endl;
           break;
         }
         else
           charcounter++;
       }
       
       if(charcounter == runstr.length()){ //if our input number is Ok, convert it from string to int value
         inputNum = stoi(runstr);
         cout << endl << "Great!!! Length of the fence = " << inputNum << " and is a positive integer number!" << endl;
       }
        
     }//while
  
     double smax=0;//max area
     unsigned int ismax=0; //iteration at which s = smax
     const unsigned int L=inputNum;//length of the fence
     unsigned int *a = new unsigned int[1000000], *b = new unsigned int[1000000];//sides of the rectangle
     double *s = new double[1000000];//area at each stage of checking
     unsigned int *aAlternative = new unsigned int[1000000], *smaxAlternative = new unsigned int[1000000];
     a[0]=1;
     unsigned long k=1000000000000;
//     cout << endl << "-----CALCULATIONs for Rectangle----" << endl;
//     cout << "  i    a    b    s    smax  ismax" << endl;
//     cout << "-----------------------------------" << endl;
     for(unsigned int i=0; i<k; i++){
       b[i]= L-2*a[i];
       s[i]=a[i]*b[i];
       if(s[i]>smax){
         smax = s[i];
         ismax=i;
       }
       if(s[i]==smax){
           aAlternative[i] = a[i];
           smaxAlternative[i] = smax; 
       }
//       cout << "  " << i << "    " << a[i] << "    " << b[i] << "    " << s[i] << "    " << smax << "      " << ismax << "   " << aAlternative[i] << endl;
       a[i+1]=a[i]+1;


       if(b[i]==1 || b[i]==0){
         k=0;
         cout << endl << "CASE A: If uncle McDonald would like to make a fence in the shape of RECTANGLE (as shown in the picture): " << endl;
         cout << "     a = " << a[ismax] << " m,   b = " << b[ismax] << " m,   area S = " << smax << " m2" << endl;

         for(unsigned int j=0; j<i; j++)
           if(aAlternative[j]>0 && smaxAlternative[j]==smax && aAlternative[j] != a[ismax])
             cout << "Or:  a = " << aAlternative[j] << " m,   b = " << (L-2*aAlternative[j]) << " m,   area S = " << smax << " m2" << endl;
         
       }
     }
   
     double smaxT=0;//max area for trapezoid
     unsigned int aT, bT;//sides of the trapezoid
     double Lfract, intpart;//Fractional & integer parts

     Lfract = modf(float(L)/3, &intpart);// if Lfract=0 L/3 without rest part, so all 3 sides of trapezoid are the same

     aT=intpart;

     if(Lfract==0){ 
       unsigned int dif = L-3*aT;  // difference between L and 3*side
       if(dif==0){                 // dif = 0
         bT= aT;
         smaxT= 3*sqrt(3)*pow(aT, 2) / 4;
       }
     }
     else{
       unsigned int dif = L-3*aT;
       if(dif==1){                // dif = 1  
         bT= aT+1;
         double cosAlfa = 0.5*sqrt(pow(bT, 2)/(4*pow(aT, 2)) + 2) - 0.5*bT/aT;
         smaxT= aT*sqrt(1-pow(cosAlfa, 2))*(bT + aT*cosAlfa);
       }
       if(dif==2){                // dif = 2
         bT= aT;
         aT++;
         double cosAlfa = 0.5*sqrt(pow(bT, 2)/(4*pow(aT, 2)) + 2) - 0.5*bT/aT;
         smaxT= aT*sqrt(1-pow(cosAlfa, 2))*(bT + aT*cosAlfa);
       }
     }
     
     
     
     if(smaxT>smax){
       cout << endl << "CASE B: If uncle McDonald would like to make a fence in the shape of TRAPEZOID: " << endl;
       cout << "     a = " << aT << " m,   b = " << bT << " m,   area S = " << smaxT << " m2" << endl;
     } 
   }//if RUN
   
}//main

