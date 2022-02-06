#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,d,m;
    scanf("%d\n",&n);
    int arr[n];
    for(int i=1;i<=n;i++)
    {
        scanf("%d\n",&arr[i]);
    }
    scanf("%d\n",&d);
    scanf("%d",&m);
    int x;
    int y=0;
    if(m==2)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                x=arr[i]+arr[j];
                if(x==d)
                {
                    y+=1;

                }

            }
        }
        printf("%d",y);
    }

    return 0;
}
