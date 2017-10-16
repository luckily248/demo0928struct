// ZHIYING LIANG
//  main.cpp
//  demo0928struct
//
//  Created by lucky on 9/28/17.
//  Copyright © 2017 luck. All rights reserved.
//

#include <iostream>
using namespace std;

struct student{
    string name;
    int age;
    string major;
    string state;//ft/pt
    int ids;
    bool enable;
};

int main(int argc, const char * argv[]) {
    student list[1000];
    int curid=0;
    int choice=0;
    do{
        cout<<"Student data center\n";
        cout<<"------------------------\n";
        cout<<"1.add a student\n";
        cout<<"2.delete a student\n";
        cout<<"3.change a student's states\n";
        cout<<"4.print all\n";
        cout<<"5.quit\n";
        cin>>choice;
        
        if (choice==1) {
            cout<<"name:\n";
            cin>>list[curid].name;
            cout<<"age:\n";
            cin>>list[curid].age;
            cout<<"major:\n";
            cin>>list[curid].major;
            cout<<"state:\n";
            cin>>list[curid].state;
            list[curid].ids=curid+1;
            list[curid].enable=true;
            curid++;
            
            cout<<"DONE\n";
        }
        else if(choice==2){
            int id;
            cout<<"which student you want to delete?\n id=\n";
            cin>>id;
            if(id>0){
                list[id-1].enable=false;
                cout<<"student ";
                cout<<list[id-1].name;
                cout<<" delete!\n";
            }else{
                cout<<"no such id\n";
            }
        }
        else if(choice==3){
            int id;
            cout<<"which student you want to change?\n id=\n";
            cin>>id;
            if(id>0){
                int mc;
                do{
                    cout<<"which state you want to change?\n";
                    cout<<"1.major\n";
                    cout<<"2.student state\n";
                    cout<<"3.quit\n";
                    cin>>mc;
                    if (mc==1) {
                        string major;
                        cout<<"what major he/she choose?\n";
                        cin>>major;
                        list[id-1].major=major;
                        cout<<"student "<<list[id-1].name<<"'s major is "<<major<<" now\n";
                    }else if(mc==2){
                        string state;
                        cout<<"what state he/she is?(fulltime/parttime)\n";
                        cin>>state;
                        list[id-1].state=state;
                        cout<<"student "<<list[id-1].name<<"'s state is "<<state<<" now\n";
                    }
                }while (mc!=3);
            }else{
                cout<<"no such id\n";
            }
        }
        else if (choice==4){
            if (curid>=0) {
                for (int i=0; i<curid; i++) {
                    if(list[i].enable){
                         cout<<list[i].ids<<".name:"<<list[i].name<<" age:"<<list[i].age<<" major:"<<list[i].major<<" state:"<<list[i].state<<"\n";
                    }
                }
                cout<<"\n\n";
            }
        }

    }while (choice!=5);
        
    return 0;
}
