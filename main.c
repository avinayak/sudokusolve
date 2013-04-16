#include<stdio.h>
//530070000600195000098000060800060003400803001700020006060000280000419005000080079
//4209 steps

int i[82], s[81], v[9], n, p,f;
int main()
{
 for (n = 0; n < 81;) i[n++]= getchar()-48;
 i[81] = 0;
 p = -1;
  while(1){
	f=0;
    for(n=0;n<9;v[n++]=0);
    for(n=0;n<81;n++)
	if(i[n])
	{
		if(v[n % 9]&1<<i[n])
		for(;;)
		{
			if(p<0)goto d;
			if(i[p]++<9) {f++;break;}
			i[p]=0;
			p=s[p];
		}
		if(f)break;
		v[n % 9]|=1<<i[n];;
	}
	if(f)continue;
    for(n=0;n<9;v[n++]=0);
    for(n=0;n<81;n++)
	if(i[n])
	{
		if(v[n / 9]&1<<i[n])
		for(;;)
		{
			if(p<0)goto d;
			if(i[p]++<9){f++;break;}
			i[p]=0;
			p=s[p];
		}
		if(f)break;
		v[n / 9]|=1<<i[n];
	} 
	if(f)continue;
   for(n=0;n<9;v[n++]=0);
   for(n=0;n<81;n++)
	if(i[n])
	{
		if(v[n % 9 / 3 + n / 27 * 3]&1<<i[n])
		for(;;)
		{
			if(p<0)goto d;
			if(i[p]++<9){f++;break;}
			i[p]=0;
			p=s[p];
		}
		if(f)break;
		v[n % 9 / 3 + n / 27 * 3]|=1<<i[n];
	}
	if(f)continue;
     if(p > 80) goto d;
 for (n = p; i[++p];);
 s[p] = n;
 i[p] = 1;
}

//for(j=0;j<81;printf("%d",i[j++]));printf(" - ");for(j=0;j<82;printf("%d",s[j++]));
//printf("\n");

  d:
 for (n = 0; n < 81;printf("%d",p=i[n++]));
}
