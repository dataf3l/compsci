#include<iostream>
using namespace std;


int bsearch(int n[],int start, int end, int tgt){
  int mid = (start + end)/2;
  cout << " ST:"<<start<<" END:"<<end<<" mid:"<<mid<<endl;
  if(start == end || start == end-1){
    return -1;
  }
  if( n[mid] == tgt){
    return 1;
  }else if(tgt > n[mid]){
     return bsearch(n, mid,end, tgt);
  }else if(tgt < n[mid]){
     return bsearch(n, start, mid, tgt);
  }
  return -2;
}
int main(){
  int n[] = {100,200,300,400,500,800,900,1000,1100,1200};
  int r = bsearch(n,0,10,6);
  cout << r<< endl;

}
