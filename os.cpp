#include<iostream>
#include<windows.h>
#include<cstring>
#include<fstream>
#include<algorithm>
using namespace std;
//SUPPORTING FUNCTIONS
int space(string &s1)
{
int l=s1.length();
int pos=(int)((80-l)/2);
for(int i=0;i<pos;i++)
cout<<" ";
cout<<s1<<endl;
}
int line_break()
{
for(int i=0;i<80;i++)
{
cout<<"-";
}
cout<<endl;
}
int heading()
{
system("color B");
string s="";
string s1="DISK SCHEDULING ALGORITHMS";
line_break();
space(s1);
cout<<"\n";
line_break();
}
//ALGORITHMS(PRE-DEFINED)
int fcfs(int a1,int b,int ar[])
{
cout<<"\n\n FCFS \n\n";
int n=a1;
int disk1=b;
int sum=0;
for(int i=0;i<n;i++)
{
cout<<"Disk Head = "<<disk1<<endl;
cout<<max(ar[i],disk1);
cout<<" - ";
cout<<min(ar[i],disk1);
cout<<" = ";
cout<<max(disk1,ar[i])-min(disk1,ar[i])<<endl;
sum=sum+max(disk1,ar[i])-min(disk1,ar[i]);
disk1=ar[i];
}
cout<<"\nTotal Seek Time = "<<sum<<endl;
return sum;
}
int scan(int a1,int b,int d[])
{
cout<<"\n\n SCAN \n\n";
int n=a1;
int a=b;
int sum=0,pos=0;
for(int i=0;i<n;i++)
{
for(int j=0;j<n-1-i;j++)
{
if(d[j]>=d[j+1])
{
int temp=d[j];
d[j]=d[j+1];
d[j+1]=temp;
}
}
if(d[i]==a)
pos=i;
}
int disk=a;
for(int i=pos-1;i>=0;i--)
{
cout<<"Disk Head = "<<disk<<endl;
cout<<disk;
cout<<" - ";
cout<<d[i];
cout<<" = ";
cout<<disk-d[i]<<endl;
sum=sum+disk-d[i];
disk=d[i];
}
cout<<"Disk Head = "<<disk<<endl;
cout<<disk<<" - 0 = "<<disk<<endl;
sum=sum+disk;
disk=0;
cout<<"Disk Head = "<<disk<<endl;
cout<<d[pos+1]<<" - 0 = "<<d[pos+1]<<endl;
sum=sum+d[pos+1];
disk=d[pos+1];
for(int i=pos+2;i<n;i++)
{
cout<<"Disk Head = "<<disk<<endl;
cout<<d[i];
cout<<" - ";
cout<<disk;
cout<<" = ";
cout<<d[i]-disk<<endl;
sum=sum+d[i]-disk;
disk=d[i];
}
cout<<"Total Seek Time = "<<sum<<endl;
return sum;
}
int clook(int a1,int b,int d[])
{
cout<<"\n\n C-LOOK \n\n";
int n=a1;
int a=b;
int sum=0,pos=0;
for(int i=0;i<n;i++)
{
for(int j=0;j<n-1-i;j++)
{
if(d[j]>=d[j+1])
{
int temp=d[j];
d[j]=d[j+1];
d[j+1]=temp;
}
}
if(d[i]==a)
pos=i;
}
int disk=a;
for(int i=pos-1;i>=0;i--)
{
cout<<"Disk Head = "<<disk<<endl;
cout<<disk;
cout<<" - ";
cout<<d[i];
cout<<" = ";
cout<<disk-d[i]<<endl;
sum=sum+disk-d[i];
disk=d[i];
}
cout<<"Disk Head = "<<disk<<endl;
cout<<d[n-1]<<" - "<<disk<<" = "<<d[pos+1]<<endl;
sum=sum+d[n-1]-disk;
disk=d[n-1];
for(int i=n-2;i>pos;i--)
{
cout<<"Disk Head = "<<disk<<endl;
cout<<disk;
cout<<" - ";
cout<<d[i];
cout<<" = ";
cout<<disk-d[i]<<endl;
sum=sum+disk-d[i];
disk=d[i];
}
cout<<"Total Seek Time = "<<sum<<endl;
return sum;
}
//LEFT
int sstf(int a1,int b,int ar[])
{ cout<<"\n\n FCFS \n\n"; int t[a1],i,j,temp,seek=0; float avg; int n=a1; int disk1=b; for(i=0;i<n;i++) t[i]=abs(disk1-ar[i]); for(i=0;i<n;i++) { for(j=i+1;j<n;j++) { if(t[i]>t[j]) { temp=t[i]; t[i]=t[j]; t[j]=temp; temp=ar[i]; ar[i]=ar[j]; ar[j]=temp; } } } for(i=0;i<n;i++) { seek=seek+abs(disk1-ar[i]); disk1=ar[i]; } cout<<"\nTotal Seek Time is = "<<seek<<endl; return seek;
}
int look(int a1,int b,int ar[])
{ cout<<"\n\n LOOK \n\n";
int n=a1; int disk1=b; int sum=0,i,j,pos=0; for(i=0;i<n;i++) { for(j=0;j<n-1-i;j++) { if(ar[j]>=ar[j+1]) { int temp=ar[j]; ar[j]=ar[j+1]; ar[j+1]=temp; } } } for(i=0;i<n;i++) { if(ar[i]>disk1) { pos=i; break; } } pos=pos-1; if((pos-0)<(n-pos-1)) { int tt=disk1; sum=sum+(tt-ar[0])+(ar[n-1]-ar[0]); } else { int tt=disk1; sum=sum+(ar[n-1]-tt)+(ar[pos]-ar[0]); } cout<<"\nTotal Seek Time = "<<sum<<endl; return sum;
}
int cscan(int a1,int b,int ar[])
{ cout<<"\n\n SCAN \n\n";
int n=a1; int disk1=b; int sum=0,i,j,pos=0; for(i=0;i<n;i++) { for(j=0;j<n-1-i;j++) { if(ar[j]>=ar[j+1]) { int temp=ar[j]; ar[j]=ar[j+1]; ar[j+1]=temp; } } } for(i=0;i<n;i++) { if(ar[i]>disk1) { pos=i; break; } } pos=pos-1; if((pos-0)<(n-pos-1)) { int tt=disk1; sum=sum+tt+ar[n-1]+ar[n-1]-ar[pos+1]; } else { int tt=disk1; sum=sum+(ar[n-1]-tt)+ar[n-1]+ar[pos]; } cout<<"\nTotal Seek Time = "<<sum<<endl; return sum;
}
int ssedo(int a,int b,int arr[])
{
cout<<"Enter the deadline of each of the following\n";
int deadline[a];
for(int i=0;i<a;i++)
{
cin>>deadline[i];
}
for(int i=0;i<a;i++)
{
for(int j=0;j<a-1-i;j++)
{
if(deadline[j]*arr[j]>deadline[j+1]*arr[j])
{
int temp=deadline[j];
deadline[j]=deadline[j+1];
deadline[j+1]=temp;
int temp1=arr[j];
arr[j]=arr[j+1];
arr[j+1]=temp1;
}
}
}
//SORTED BY PRIORITY OF DEADLINE VALUE
for(int i=0;i<a;i++)
{
cout<<arr[i]<<" -> "<<i<<endl;
}
int sum=0;
sum=sum+(abs(b-arr[0]));
//cout<<b<<" - "<<arr[0]<<" = "<<sum<<endl;
for(int i=0;i<a-1;i++)
{
//cout<<arr[i]<<" - "<<arr[i+1]<<endl;
sum=sum+(abs(arr[i]-arr[i+1]));
}
cout<<"TOTAL SEEK TIME : "<<sum<<endl;
return 100000;
}
int ssedv(int a,int b,int arr[])
{
cout<<"Enter the deadline of each of the following\n";
int deadline[a];
for(int i=0;i<a;i++)
{
cin>>deadline[i];
}
for(int i=0;i<a;i++)
{
for(int j=0;j<a-1-i;j++)
{
if(deadline[j]>=deadline[j+1])
{
int temp=deadline[j];
deadline[j]=deadline[j+1];
deadline[j+1]=temp;
int temp1=arr[j];
arr[j]=arr[j+1];
arr[j+1]=temp1;
}
}
}
//SORTED BY PRIORITY OF DEADLINE VALUE
for(int i=0;i<a;i++)
{
cout<<arr[i]<<" -> "<<deadline[i]<<endl;
}
int sum=0;
sum=sum+(abs(b-arr[0]));
//cout<<b<<" - "<<arr[0]<<" = "<<sum<<endl;
for(int i=0;i<a-1;i++)
{
//cout<<arr[i]<<" - "<<arr[i+1]<<endl;
sum=sum+(abs(arr[i]-arr[i+1]));
}
cout<<"TOTAL SEEK TIME : "<<sum<<endl;
return 100000;
}
//PROGRAM FUNCTIONS
int indAnalysis()
{
system("cls");
heading();
cout<<"1.FCFS\n2.SSTF\n3.SCAN\n4.CSCAN\n5.LOOK\n6.CLOOK\n7.SSEDO\n8.SSEDV\nENTER YOUR CHOICE : ";
int choice=0;
cin>>choice;
int nOfLoc=0;
int hdPos=0;
system("cls");
heading();
cout<<"Enter Number Of Locations : ";
cin>>nOfLoc;
cout<<"Enter Position Of Head : ";
cin>>hdPos;
int ar[nOfLoc];
cout<<"Enter Elements In The Disk : ";
for(int i=0;i<nOfLoc;i++)
{
cin>>ar[i];
}
if(choice==1)
{
fcfs(nOfLoc,hdPos,ar);
system("PAUSE");
}
else if(choice==1)
{
fcfs(nOfLoc,hdPos,ar);
system("PAUSE");
}
else if(choice==3)
{
scan(nOfLoc,hdPos,ar);
system("PAUSE");
}
else if(choice==1)
{
fcfs(nOfLoc,hdPos,ar);
system("PAUSE");
}
else if(choice==1)
{
fcfs(nOfLoc,hdPos,ar);
system("PAUSE");
}
else if(choice==6)
{
clook(nOfLoc,hdPos,ar);
system("PAUSE");
}
else if(choice==7)
{
ssedo(nOfLoc,hdPos,ar);
system("PAUSE");
}
else if(choice==1)
{
fcfs(nOfLoc,hdPos,ar);
system("PAUSE");
}
else
{
cout<<"Wrong Choice\n";
}
}
int comparison()
{
system("cls");
heading();
cout<<"1.FCFS\n2.SSTF\n3.SCAN\n4.CSCAN\n5.LOOK\n6.CLOOK\n";
int choice=0;
int choice1=0;
cout<<"Enter two algorithms to be compared : ";
cin>>choice;
cin>>choice1;
int nOfLoc=0;
int hdPos=0;
system("cls");
heading();
cout<<"Enter Number Of Locations : ";
cin>>nOfLoc;
cout<<"Enter Position Of Head : ";
cin>>hdPos;
int ar[nOfLoc];
cout<<"Enter Elements In The Disk : ";
for(int i=0;i<nOfLoc;i++)
{
cin>>ar[i];
}
if(choice==1 || choice1==1)
{
fcfs(nOfLoc,hdPos,ar);
}
if(choice==2 || choice1==2)
{
sstf(nOfLoc,hdPos,ar);
}
if(choice==3 || choice1==3)
{
scan(nOfLoc,hdPos,ar);
}
if(choice==4 || choice1==4)
{
cscan(nOfLoc,hdPos,ar);
}
if(choice==5 || choice1==5)
{
look(nOfLoc,hdPos,ar);
}
if(choice==6 || choice1==6)
{
clook(nOfLoc,hdPos,ar);
}
system("PAUSE");
}
int best()
{
system("cls");
heading();
int nOfLoc=0;
int hdPos=0;
system("cls");
heading();
cout<<"Enter Number Of Locations : ";
cin>>nOfLoc;
cout<<"Enter Position Of Head : ";
cin>>hdPos;
int ar[nOfLoc];
cout<<"Enter Elements In The Disk : ";
string answer[]={"FCFS","SSTF","SCAN","C-SCAN","LOOK","C-LOOK"};
for(int i=0;i<nOfLoc;i++)
{
cin>>ar[i];
}
int min1[8];
min1[0]=fcfs(nOfLoc,hdPos,ar);
min1[1]=sstf(nOfLoc,hdPos,ar);
min1[2]=scan(nOfLoc,hdPos,ar);
min1[3]=cscan(nOfLoc,hdPos,ar);
min1[4]=look(nOfLoc,hdPos,ar);
min1[5]=clook(nOfLoc,hdPos,ar);
int pos=0,mmin=min1[0];
for(int i=0;i<6;i++)
{
if(min1[i]<mmin)
{
mmin=min1[i];
pos=i;
}
}
cout<<"\n\n\n\n"<<answer[pos];
cout<<" performed the best job with a seek time of ";
cout<<min1[pos]<<endl;
system("PAUSE");
}
int own()
{
system("cls");
heading();
int a=0;
int b=0;
cout<<"Enter Number Of Locations : ";
cin>>a;
cout<<"Enter Position Of Head : ";
cin>>b;
int arr[a];
cout<<"Enter Elements In The Disk : ";
for(int i=0;i<a;i++)
{
cin>>arr[i];
}
cout<<"Enter the deadline of each of the following\n";
int deadline[a];
for(int i=0;i<a;i++)
{
cin>>deadline[i];
}
int avg=0;
for(int i=0;i<a;i++)
{
avg=avg+(arr[i]*deadline[i]);
}
avg=(int)avg/a;
for(int i=0;i<a;i++)
{
for(int j=0;j<a-1-i;j++)
{
if(deadline[j]*arr[j]/avg>deadline[j+1]*arr[j]/avg)
{
int temp=deadline[j];
deadline[j]=deadline[j+1];
deadline[j+1]=temp;
int temp1=arr[j];
arr[j]=arr[j+1];
arr[j+1]=temp1;
}
}
}
//SORTED BY PRIORITY OF DEADLINE VALUE
for(int i=0;i<a;i++)
{
cout<<arr[i]<<" -> "<<i<<endl;
}
int sum=0;
sum=sum+(abs(b-arr[0]));
//cout<<b<<" - "<<arr[0]<<" = "<<sum<<endl;
for(int i=0;i<a-1;i++)
{
//cout<<arr[i]<<" - "<<arr[i+1]<<endl;
sum=sum+(abs(arr[i]-arr[i+1]));
}
cout<<"TOTAL SEEK TIME : "<<sum<<endl;
system("PAUSE");
return 100000;
}
//MAIN FUNCTION
int main()
{
int ch=10;
while(ch)
{
heading();
cout<<"1.Individual Analysis\n2.Comparison\n3.Check Best\n4.Own Algorithm\n0.EXIT\nENTER YOUR CHOICE : ";
cin>>ch;
if(ch==1)
indAnalysis();
else if(ch==2)
comparison();
else if(ch==3)
best();
else if(ch==4)
own();
else if(ch==0)
cout<<"\nTHANKYOU FOR USING OUR APPLICATION"<<endl;
else
{
cout<<"\n\nINVALID INPUT"<<endl;
Sleep(2000);
system("cls");
}
system("cls");
}
system("pause");
}
