#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// k

//------------------------------------------------------------------
unsigned long long r_next = 1;

/*
 *  int rand()
 *      Taken from the K&R C programming language book. Page 46.
 *      returns a pseudo-random integer of 0..32767. Note that
 *      this is compatible with the System V function rand(), not
 *      with the bsd function rand() that returns 0..(2**31)-1.
 */
unsigned long int lrand ()
{
	r_next = r_next * 1103515245ULL + 12345ULL;
	return ((unsigned int)(r_next / 4294967296ULL) % 2147483648ULL);
}

/*
 *  srand(seed)
 *      companion routine to rand(). Initializes the seed.
 */
void
lsrand(unsigned long int seed)
{
	r_next = seed;
}
//------------------------------------------------------------------




double randoom() {
	double zz=lrand();
	double ww=zz/2147483648ULL;
	return ww;
}

//main
int main() {
//input

int flag;    
int n; // количество итераций 
int m; //mem
int s;
int k1;
int i,j,k, i_max, j_max;
int index_x, index_y, light_x, light_y;

double p1, q1, q2, q12, pq12, r; //val.prob
double T, T_max;
double p_rand;



printf("\n p1 = "); 
scanf("%lf", &p1);
printf("\n q1 = ");
scanf("%lf", &q1);
printf("\n q2 = ");
scanf("%lf", &q2);
printf("\n q12 = ");
scanf("%lf", &q12);
printf("\n pq12 = ");
scanf("%lf", &pq12);

r = 1- p1-q1-q2-q12-pq12;


printf(" \n p1 = %lf, q1= %lf, q2 = %lf, q12 = %lf, pq12= %lf, r = %lf \n", p1, q1, q2, q12, pq12, r);


for(k1=1;k1<=1;k1++){
    
    printf("\n k = %i",k1); //size of m scanf("%i", &k1);
    for(m=4;m<=16;m=m+4){
        
        

printf("\n m = %i",m); //size of m scanf("%i", &m);


T_max=0; 
 
i_max=0;
j_max=0;

n=1000000; //

lsrand(time(NULL)); 
for(i=0;i<=m;i++){ // i - размер x
    //  printf(" \n i = %i", i);
    
    for(j=0;j<=m;j++){ // j - размер y
   if((i+j)<=m){     
    T=1;    
        
        
        for(k=1;k<n+1;k++){ // k - итераций
            

light_x=i;
light_y=j;
flag=1;

while(flag==1){
       
p_rand=randoom(); //rand()%s;


if(p_rand<p1){ // p1
 
    light_x=light_x+1;

    
    if((light_x+light_y)>m) flag = 0;
    else T=T+1;
}else{
    if(p_rand<(p1+q1)){//q1

        light_x=light_x-1;
 
    
    
        
        if(light_x<0) flag=0;
        else         T=T+1;
    }else{
        if(p_rand<(p1+q1+q2)){ //q2
           
          
        
            light_y=light_y-k1;
               
    
            if(light_y<0) flag=0;
           else             T=T+1;
        }else{
            if(p_rand<(p1+q1+q2+q12)){//q12
                
             

                light_x=light_x-1;
                
    
                light_y=light_y-k1;
        
              

            if(light_x<0) flag=0;
           else{                if(light_y<0) flag=0;
           else T=T+1;
           }
               
        //}
                
            }
            else{
                if(p_rand<(p1+q1+q2+q12+pq12)){//pq12
                    
                 
            
                light_x=light_x+1;
            
                light_y=light_y-k1;
             
    
                  
                
            if(light_y<0){ flag=0;}
           else{
               T=T+1;
                    
             //   }
            }}
            else{ //r
                T=T+1;
                  //     printf("r\n");
    

            }
            
        }
    }
}

} 




//printf("T: %lf, flag = %i\n", T, flag);
      
    //flag=0;
}//while
        
   
    } //k
    T=T/n; //среднее для данного i,j - для таких длин x,y
    
  if(i==j) {printf("\n T: %4.2lf, i= %i, j= %i", T, i,j);
  }
    
    if(T>T_max){T_max=T;
        i_max=i;
        j_max=j;
        
    }

   }//if
    
}//j

} //i


printf("\n \n T_max: %4.2lf, x= %i, y= %i", T_max, i_max,j_max);

  //  }
}

}

}
