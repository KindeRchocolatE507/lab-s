#include <stdio.h>
float min(float a, float b){
    return (a<=b)?a:b;
}
float max(float a, float b){
    return (a>=b)?a:b;
}
float mod(float a, float b){
    if(b>0){
    if(a>=0){
        while(a>=b){
            a-=b;
        }
    }
    else if(a<0){
        while(a<0){
            a+=b;
        }
    }
    return a;
    }else{
    if(a>=0){
        a=-a;
        b=-b;
        while(a>=b){
            a-=b;
        }
    }
    else if(a<0){
        while(a<0){
            a+=b;
        }
    }
    return -a;}
}
float sign(float a){
    return (a>0)?1:(a<0)?-1:0;
}
float abss(float a){
    return (a>0)?a:(-a);
}
int main(){
    float i=-22, j=29, l=4, ipred, jpred;
    int  k, popal=0; 
    if((i+20)*(i+20)+(j+20)*(j+20)<=100&&(i+10)*(i+10)+(j+10)*(j+10)<=100){
        printf("Точка изначально попала в\nпересечение окружностей с радиусом 10\nс центрами в (-10;-10) и (-20;-20)\nи попала в точку (%f, %f)\nв момент %d с параметром %f\n",i,j,0,l);
        return 0;
    }
    for(k=0;k<50;k++){
        ipred=i;
        jpred=j;
        i=sign(min(ipred,jpred))*max(mod((ipred+k),20),mod((jpred+l),20));
        j=abss(max(ipred,jpred))-k*min(jpred,l);
        l=(k-l)/((ipred+jpred+l)*mod((ipred+jpred+l),5)+1);
        if((i+20)*(i+20)+(j+20)*(j+20)<=100&&(i+10)*(i+10)+(j+10)*(j+10)<=100){
            popal=1;
            break;
        }
    }
    if(popal){
        printf("Точка попала в\nпересечение окружностей с радиусом 10\nс центрами в (-10;-10) и (-20;-20)\nи попала в точку (%f, %f)\nв момент %d с параметром %f\n",i,j,k,l);
    }else{
        printf("Точка не попала в\nпересечение окружностей с радиусом 10\nс центрами в (-10;-10) и (-20;-20)\nи попала в точку (%f, %f)\nв момент %d с параметром %f\n",i,j,k,l);
    }
    return 0;
}