#include<stdio.h>
#include<string.h>

int search(int num,int* frame,int m){
    for(int i=0;i<m;i++){
        if(num==frame[i]){
            return 1;
        }
    }
    return 0;
}
int main(){
    
    int n,m;
    printf("Abhishek Rana\n");
    printf("20011351\n");
    printf("Enter the no's of Pages ");
    scanf("%d",&n);
    printf("\nEnter the size of frame ");
    scanf("%d",&m);

    int pages[n],frame[m],idx=0,page_f=0;
    memset(frame,-1,m*sizeof(frame[0]));

    for(int i=0;i<n;i++){
        printf("Enter the page number: ");
        scanf("%d",&pages[i]);

        if(!search(pages[i],frame,m)){
            page_f++;
            frame[idx]=pages[i];
            idx=(idx+1)%m;
        }

        printf("Frame after insertion of page no: %d\n",pages[i]);
        for(int i=0;i<m;i++){
            printf("%d\t",frame[i]);
        }
        printf("\n");
    }
    printf("Total Page Fault: %d\n",page_f);
}