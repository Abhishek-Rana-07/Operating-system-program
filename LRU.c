#include<stdio.h>
#include<limits.h>
int arr[100];
int f=0,r=0;
int  checking(int val)
{
    for(int i=0;i<r;i++)
    {
           if(arr[i]==val)
                return 1; 
    } 
    return 0;
}   
int fault(int *pages,int n,int nf,int *ind)
{
    int pagefault=0;
    for(int i=0;i<n;i++)
    {
    if(r<nf)
    {
        if(!checking(pages[i]))
        { 
                arr[r]=pages[i];
                r++;
                pagefault++;
               
        } 
        ind[pages[i]]=i;
     } 
     else
     {
             if(!checking(pages[i]))
            {    
                int t=INT_MAX,pos=-1;
                for(int i=0;i<nf;i++)
                {
                        if(ind[arr[i]]<t)
                        {
                            t=ind[arr[i]];
                            pos=i;
                         }
                  }
                  arr[pos]=pages[i];
                 pagefault++;
            }
            ind[pages[i]]=i;
       }
        for(int i=0;i<r;i++)
                    printf("%d ",arr[i]);
               printf("\n");
    }
    return pagefault;
}       
int main()
{
    printf("Abhishek Rana\n");
    printf("20011351\n");
    int n,nf;
    printf("Enter the number of pages: ");
    scanf("%d",&n);
    int pages[n];
    printf("Enter the pages: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&pages[i]);
    }
      printf("Enter the number of frames: ");
    scanf("%d",&nf);
    arr[nf];
    int ind[n];
    printf("Total Number of Page Faults: %d\n",fault(pages,n,nf,ind));
    return 0;
}