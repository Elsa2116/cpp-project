#include<iostream>
using namespace std;
class queue{
private:
    int front;
    int rear;
    int arr[5];
public:
 queue()
 {
     front = -1;
     rear = -1;
     for(i=0;i<5;i++)
        {
            arr[i]=0;
        }

 }
};
int main(){
    queue q1;
int option,value;

do{
    cout<<"\n what operation do you want to perform.enter 0 to exit\n"<<endl;
    cout<<"\n 1.enqueue()"<<endl;
    cout<<"\n 2.dequeue()"<<endl;
    cout<<"\n 3.isFull()"<<endl;
    cout<<"\n 4.isEmpty()"<<endl;
    cout<<"\n 5.count()"<<endl;
    cout<<"\n 6.display()"<<endl;
    cout<<"\n 7.clear screen()"<<endl;
    cin>>option;
  switch(option)
   case1:
       if()
}
}
while()
return 0;
}

