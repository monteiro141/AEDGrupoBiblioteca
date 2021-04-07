#include <time.h>
long semente = 12345L;

#define IA 16807
#define IM 2147483647
#define AM ((float)1.0/IM)
#define IQ 127773
#define IR 2836
#define MASK 123459876

float ran0 (long *idum){
   long k;
   float ans;
  
   *idum ^= MASK;              // XORing with MASK allows use of zero and other simple bit patterns for idum
   k = (*idum)/IQ; 
   *idum = IA*(*idum-k*IQ)-IR*k; // Compute idum=(IA*idum) % IM without overflows
   if (*idum < 0) 
      *idum += IM;              // by Schrage�fs method.
   ans = AM*(*idum);           // Convert idum to a floating result.
   *idum ^= MASK;              // Unmask before return.
   return ans;
}


int gerarNumeroInteiro (int a, int b){
   float x;
   time_t  seg;
   int inf, sup, k, cardinal;

   inf = a;
   sup = a;
   if (a > b)
      inf = b;
   else
      sup = b;

   seg = time(NULL);
   semente = semente + seg;
   x = ran0(&semente);
   semente = semente + seg;
   x = ran0(&semente);
  
   cardinal = (sup - inf + 1);
   k = (int) (x * cardinal * 10000);
   return  inf + k % cardinal;

}

float gerarNumeroReal (float a, float b){
   float x;
   time_t  seg;
   float inf, sup;

   inf = a;
   sup = a;
   if (a > b)
      inf = b;
   else
      sup = b;

   seg = time(NULL);
   semente = semente + seg;
   x = ran0(&semente);
   semente = semente + seg;
   x = ran0(&semente);

   return  inf + (sup - inf) * x;

}


