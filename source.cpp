#include "iostream"
#include<string>
#include<vector>
using namespace std;

class cycle {
    string Brand;
    string Model;
    float MRP;
    bool Gear;      //true for gear and false for non gear
//    bool Carrier;
    int Type;
    int Category;
    int Total;
    int Available;
    void Edit();
    bool Issue(){
        if(Available>0) {
            Available--;
            return true;
        }
        else
            return false;
    };
    bool Return() {
        if (Available+1 > Total) {
            return false;
        }
        else {
            Available++;
            return true;
        }
    };
    friend cycle Create();
    friend cycle* Search(vector<vector<cycle> >);
};

void cycle::Edit() {
    reedit:
    cout<<"What do you want to edit?"<<endl
    <<"1 - MRP"<<endl
    <<"2 - Total"<<endl
    int choice;
    cin>>choice;
    switch(choice) {
        case 1:
            cout<<"\nEnter new MRP: ";
            cin>>MRP;
            break;
        case 2:
            int temp;
            cout<<"\nEnter new Total: ";
            cin>>temp;
            if (temp<Total-Avilable)
                cout<<"\nERROR: No. of cycles issued are more than the new Total!";
            else {
                Available += temp - Total;
                Total = temp;
            }
            break;
        default:
            cout<<"\nChoice entered in not valid please enter '1' or '2' only!";
            goto reedit;
    }
};

cycle Create() {
    cycle temp;
    cout<<"Enter Brand Name: ";
    cin>>temp.Brand;
    cout<<"\nEnter Model Name: ";
    cin>>temp.Model;
    cout<<"\nEnter MRP of the cycle: ";
    cin>>temp.MRP;
    cout<<"\nEnter Gear(1)/NonGear(0): ";
    cin>>temp.Gear;
    cout<<"\nEnter type of cycle as follows:"<<endl
    <<"1 - Road Bicycle"<<endl
    <<"2 - Racing Bicycle"<<endl
    <<"3 - Mountain Bike"<<endl
    <<"4 - BMX"<<endl;
    cin>>temp.Type;
    cout<<"\nEnter the Category as follows:"<<endl
    <<"1 - Male"<<endl
    <<"2 - Female"<<endl
    <<"3 - Kids"<<endl;
    cin>>temp.Category;
    cout<<"\nEnter the total no. of cycles: ";
    cin>>temp.Total;
    temp.Available = temp.Total;
    return temp;
};
int main(){
    vector<vector<cycle> > cycles;
    //read from text file and populate the vector

}
