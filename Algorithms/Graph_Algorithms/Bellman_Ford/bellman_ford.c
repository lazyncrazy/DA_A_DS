#include <stdio.h>
long long int cost[305];
long long int a[305][305];
long long int special[305];
long long int infi=1000000000;
int main()
{
	long long int i,j,k,n,m,p,x,z,y,min;
	scanf("%lld %lld %lld",&n,&m,&k);
	for (i=1;i<=k;i++)
	{
		scanf ("%lld",&special[i]);
	}
	for (i=1;i<=m;i++)
	{
		scanf ("%lld %lld %lld",&x,&y,&z);
		a[x][y]=z;
	}
	for (i=1;i<=304;i++)
	{
		for (j=1;j<=304;j++)
		{
			a[i][j]=infi;
		}
	}
	min=infi;
	for (p=1;p<=k;p++)
	{
		cost[special[p]]=0;
		for (i=1;i<=n;i++)
		{
			if (special[p]!=i)
			{
				cost[i]=infi;
			}
		}
		for (i=1;i<=n;i++)
		{
			for (j=1;j<=n;j++)
			{
				if (i==j)
				{
					continue;
				}
				else
				{
					if (cost[j]>cost[i]+a[i][j])
					{
						cost[j]=cost[i]+a[i][j];
					}
				}
			}
		}
		for (i=1;i<=k;i++)
		{
			if(cost[special[i]]<min)
			{
				if (i!=p)
				{
					min=cost[special[i]];
				}
			}
		}
	}
	printf ("%lld\n",min);
return 0;
}
	
