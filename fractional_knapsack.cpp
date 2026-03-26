#include<iostream>
#include<algorithm>
using namespace std;
struct Item {
    int value,weight;
};
int main() {
    int n,W;
    cin>>n;
    Item a[n];
    for(int i=0;i<n;i++)
        cin>>a[i].value>>a[i].weight;
    cin>>W;
    sort(a,a+n,[](Item x,Item y){
        return (double)x.value/x.weight > (double)y.value/y.weight;
    });
    double total=0;
    for(int i=0;i<n;i++) {
        if(W>=a[i].weight) {
            total+=a[i].value;
            W-=a[i].weight;
        } else {
            total+=(double)a[i].value/a[i].weight * W;
            break;
        }
    }
    cout<<"Maximum value = "<< total;
    return 0;
}
