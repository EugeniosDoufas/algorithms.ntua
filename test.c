#include <stdio.h>
#include <stdlib.h>

int compare(const void *pp0, const void *pp1)
{
    int i0 = **(int **)pp0;
    int i1 = **(int **)pp1;
    if(i0 > i1)return -1;
    if(i0 < i1)return  1;
    return 0;
}

int comparator (const void * p1, const void * p2)
{
  return (*(int*)p1 - *(int*)p2);
}



int culc_time(int x,int y,int C, int cf,int cs,int tf,int ts){
     /*printf(" eimai ston ipologismo anamesa se x=%d kai y=%d \n",x,y);*/
    int d=y-x;
    int d1=(C-d*cs)/(cf-cs);
    if(d1<0) return -1;
    if(d1>d)d1=d;
    int time=d1*tf+(d-d1)*ts;
 /*   printf("kai exo san d1=%d kai ts=%d kai tf=%d\n",d1,ts,tf);
    printf("vrika xrono %d\n",time); */
    return time ;
}

int check_car(int* di,int D,int K,int C, int cf,int cs,int tf,int ts ,int T){
    int temp;
    int time=culc_time(0, di[0], C,  cf, cs, tf, ts);
    if(time== -1)return 0;
    for (int i=1;i<K;i++){
        temp=culc_time( di[i-1], di[i], C,  cf, cs, tf, ts);
        if(temp== -1)return 0;
        time=time+temp;
    }
    temp=culc_time( di[K-1], D, C, cf, cs, tf, ts);
    if(temp== -1)return 0;
    time=time+temp;
    if (time<T) return 1;
    else return 0;
}




int main()
{ /*

    int N=2,K=1,D=1000000000,T=2000000000;
    int di[1]={1};
    int ts=2,cs=1,tf=1,cf=2;

    int a[2] = {111, 101};   
    int b[2] = {1000000000-2,1000000000-2};  */

  /*  int N,K,D,T;
    int ts,cs,tf,cf;

    N=2;K=2;D=10;T=18;

    int a[N],b[N],di[D];
    di[0]=5;di[1]=3;
    ts=2;cs=1;tf=1;cf=2;

    a[0]=10; a[1]=20;   
    b[0]=4; b[1]=6; 
*/


    int N,K,D,T;
    int ts,cs,tf,cf;
    

    scanf("%d", &N);    scanf("%d", &K);   scanf("%d", &D);   scanf("%d", &T);
    int a[N],b[N],di[D];
    for(int i=0;i<N;i++){
        scanf("%d", &a[i]);    scanf("%d", &b[i]);
    }
    for(int i=0; i<K; i++){
        scanf("%d", &di[i]);
    }
    scanf("%d", &ts);scanf("%d", &cs);scanf("%d", &tf);scanf("%d", &cf);
  

    /* SORTING THE ARRAYS */

    int *pa[N];
    size_t i, j, k;
    int ta, tb;

    /* create array of pointers to a[] */
    for(i = 0; i < sizeof(a)/sizeof(a[0]); i++)
        pa[i] = &a[i];

    /* sort array of pointers */
    qsort(pa, sizeof(a)/sizeof(a[0]), sizeof(pa[0]), compare);

    /* reorder a[] and b[] according to the array of pointers */
    for(i = 0; i < sizeof(a)/sizeof(a[0]); i++){
        if(i != pa[i]-a){
            ta = a[i];
            tb = b[i];
            k = i;
            while(i != (j = pa[k]-a)){
                a[k] = a[j];
                b[k] = b[j];
                pa[k] = &a[k];
                k = j;
            }
            a[k] = ta;
            b[k] = tb;
            pa[k] = &a[k];
        }
    }


    /*END OF SORTING*/ 


/*


    for(i = 0; i < sizeof(a)/sizeof(a[0]); i++)
        printf("%2d ", a[i]);
    printf("\n");

    for(i = 0; i < sizeof(a)/sizeof(a[0]); i++)
        printf("%2d ", b[i]);
    printf("\n");
*/
    /*STARTING THE DISTANCES*/
    qsort(di, K, sizeof(int), comparator);
/*
    for(i = 0; i < K; i++)
        printf("%2d ", di[i]);
    printf("\n");
*/




/* CALC T */
    int x=0;
    i=N-1;
    while( 1 ){
        int C=b[i];
        x= check_car( di, D, K, C,  cf, cs, tf, ts , T);
        if (x==1)break;
        i--;
        if(i==-1)break;
    }
    if(x==0){
        x=-1;
    }
    else {
        x=a[i];
    }
    printf("%d\n",x);







    return 0;
}