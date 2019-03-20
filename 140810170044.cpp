#include<iostream>
#include<time.h>
using namespace std;

void merge(int a[],int x,int y,int z)
    {
        int n1=y-x+1;
        int n2=z-y;
        int L[n1+1];
        int R[n2+1];
        for(int i=1;i<=n1;i++)
        {
            L[i]=a[x+i-1];
        }
        for(int j=1;j<=n2;j++)
        {
            R[j]=a[y+j];
        }
        L[n1+1]=999;
        R[n2+1]=999;
        int i=1, j=1;
        for(int k=x;k<=z;k++)
        {
            if(L[i]<=R[j])
            {
                a[k]=L[i];
                i=i+1;
            }
            else
            {
                a[k]=R[j];
                j=j+1;
            }
        }
    }

void mergeSort(int a[],int x,int z)
    {
        int y;
        if(x<z)
        {
         y=(x+z)/2;
         mergeSort(a,x,y);
         mergeSort(a,y+1,z);
         merge(a,x,y,z);
        }
    }



int main()
{	
	int n;
    cout<<"Masukkan besar array : ";
    cin>>n;
    int a[n];
    cout<<"Masukkan elemen array : "<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<"Data ke-"<<i<<" : ";
		cin>>a[i];
    }

    int x=1,z=n;
    clock_t t1,t2;
    t1=clock();

    mergeSort(a,x,z);


    cout<<"Hasil"<<endl;
   	for(int i=1;i<=n;i++)
   	{
       cout<<a[i]<<",";
   	}cout<<endl;

	
	    
    t2=clock();
    float diff ((float)t2-(float)t1);
    float second=diff/CLOCKS_PER_SEC;
    cout<<"Run Time : "<<second<<endl;
    system ("pause"); 
	
	return 0;    
}

