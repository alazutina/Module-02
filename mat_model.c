#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mkl.h>

void inverse(double* A, int N1) {
	lapack_int *IPIV = (lapack_int *)malloc(N1 * sizeof(lapack_int));
	int LWORK = N1*N1;

	int INFO;

	LAPACKE_dgetrf(LAPACK_ROW_MAJOR,N1,N1,A,N1,IPIV);
	LAPACKE_dgetri(LAPACK_ROW_MAJOR,N1,A,N1,IPIV);

	free(IPIV);

}

int main(){
    
int m;


double p1,q1,q2,q12,pq12,r;
int i,j;
FILE* fp;


fp=fopen("f.out","w");



printf ("m\n");
scanf ("%i", &m);

printf ("p1\n");
scanf ("%lf", &p1);

printf ("q1\n");
scanf ("%lf", &q1);
printf ("q2\n");
scanf ("%lf", &q2);
printf ("q12\n");
scanf ("%lf", &q12);
printf ("pq12\n");
scanf ("%lf", &pq12);

r = 1-p1-q1-q2-q12-pq12;




printf("\n p1 = %fl", p1); //ins 

printf("\n q1 =  %fl", q1);

printf("\n q2 = %fl", q2);

printf("\n q12 =  %fl", q12);

printf("\n pq12 =  %fl", pq12);

printf("\n r =  %fl", r);

int s; //кол-во состояний

s=(m+1)*(m+2)/2;


    double A1 [1000*1000];
    double A [s*s];

//for(m=5;m<=15;m=m+2){
    
    

    
    for (i=0; i<s; i++) {
        for (j=0; j<s; j++) {
            A1[i*s+j]=0;
            if (i==j) A1[i*s+j]=r;
        }
        
    }

    // q1 p1 r
      int s1,s2;
      s1=m;
      s2=m;
      
      for (i=0; i<s; i++) {
    
          if(i== (s1)) { 
                  printf("s1=%i\n", s1);
              A1[i*s+i+1]=0;
              A1[(i+1)*s+i]=0;
              A1[(i+s2)*s+i]=0; 
               A1[(i+s2+1)*s+i-1]=0; 
              s1=s1+s2;
             s2--;
        }
          
            else{
                A1[i*s+i+1]=p1;
                
                A1[(i+1+s2)*s+i]=q2;
                
                A1[(i+1+s2)*s+i+1]=pq12;
                
                A1[(i+1+s2+1)*s+i]=q12;
                
                A1[(i+1)*s+i]=q1;
        }
        
      }
  
    
    
    
    
     
     for (i=0; i<s; i++) {
      for (j=0; j<s; j++) {
          A[i*s+j]=A1[i*s+j];
    fprintf(fp," %f ", A[i*s+j]);
            
       }
        
       fprintf(fp,"\n");
        
    
        
    }
   
    for (i=0; i<s; i++) {
  //     fprintf(fp,"%d",i);
        for (j=0; j<s; j++) {
          if(i==j){ A[i*s+j]=1-A[i*s+j];}
           else{A[i*s+j]=0-A[i*s+j];}
      //  fprintf(fp," %f ", A[i*6+j]);
            
        }
      //  
     //  fprintf(fp,"\n");
        
    //
        
    }
fprintf(fp,"\n");
//printf("inverse");
fprintf(fp,"\n");
    inverse(A, s);
    
     for (i=0; i<s; i++) {
      for (j=0; j<s; j++) {
          
    fprintf(fp," %f ", A[i*s+j]);
            
       }
        
       fprintf(fp,"\n");
        
    
        
    }
        
printf("\n");
    

    double t, t_max;
    t=0;
    t_max=0;
    int i_max, j_max;
    i_max=0;
    j_max=0;
    

     printf("t = %f x = %i y = %i\n", t, i, j);
   for (i=0; i<s; i++) {
    t=0;
        for (j=0; j<s; j++) {
            
            t=t+A[i*s+j];
            
         
        }
        if (i==m+2){    printf("t = %f, i= m+2= (1,1) = %i\n", t,i);}
        
    if(t>t_max){t_max = t;
         i_max = i;
   
    }  
    //    printf("t = %f i=%i\n", t, i);
    
   }
    
    
      printf("imax%i\n", i_max);

    
    i=0;
    s1=m+1;
    int flag;
    flag=1;
    i_max=i_max+1;
    


    
    
    
    do{
        
    if(i_max>s1){   i_max = i_max - s1;
                    i++ ;
                    s1--;
        
        
    } else { j = i_max-1;
        flag=0;
    }
    }
    
    
    while(flag==1);
   
    
    
    
    printf("m =%i tmax = %f x=%i, y=%i\n", m, t_max, j,i);

  
    return 0;
}
