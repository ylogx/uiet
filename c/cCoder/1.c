//Shubham Chaudhary
#include <stdio.h>
#include <math.h>   //!use gcc flag -lm   

struct point{
    int x;
    int y;
};

float dist(struct point a, struct point b);
float area(struct point a, struct point b, struct point c);

int main(){
    struct point a,b,c;
    struct point key;
    
    printf("Enter a.x: ");
    scanf("%d",&(a.x));
    printf("Enter a.y: ");
    scanf("%d",&(a.y));
    printf("Enter b.x: ");
    scanf("%d",&(b.x));
    printf("Enter b.y: ");
    scanf("%d",&(b.y));
    printf("Enter c.x: ");
    scanf("%d",&(c.x));
    printf("Enter c.y: ");
    scanf("%d",&(c.y));
    printf("\ndist: %f\n",dist(c,b));
    printf("Area: %f\n",area(a,b,c));
    printf("Enter c.x: ");
    scanf("%d",&(key.x));
    printf("Enter c.y: ");
    scanf("%d",&(key.y));
    printf("\n%d\n",isInside(key,a,b,c));
    return 0;
}
float dist(struct point a, struct point b){
    return ( sqrt( (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) ) );
}

float area(struct point a, struct point b, struct point c){
    float da,db,dc;
    float p;
    float area;
    dc=dist(a,b);
    db=dist(a,c);
    da=dist(b,c);
    //p=(da+db+dc)<1;
    p=(da+db+dc)/2;
    area= sqrt(p * (p-da) * (p-db) * (p-dc) );
    return(area);
    
}

int isInside(struct point key,struct point a, struct point b, struct point c){
    float are;
    float areaa,areab,areac;
    are=area(a,b,c);
    areaa=area(key,b,c);
    areab=area(a,key,c);
    areac=area(a,b,key);
    return (are == (areaa + areab + areac));
}
