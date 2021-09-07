//Selection - sort
#include<iostream>
#include<iomanip>
using namespace std;
void print(int *a, int n, int dem){
	cout<< setw(5)<<dem;
	for(int i =0;i< n; i++){
		cout<<setw(7)<<a[i];
	}
	cout<<endl;
}
void selection_sort (int *a, int n){
	int min;
	int dem= 0;
	for(int i = 0; i< n-1;i++){
		min = i;
		for(int j=i+1;j<n;j++){
			if(a[j]<a[min]){
				min = j;
			}
		}
		if(min!=i){
		   int temp = a[min];
		   a[min]=a[i];
		   a[i]= temp;
		}
		dem = dem + 1;
	    print(a,n,dem);
	}
}
void insertion_sort(int *a,int n){
	int dem =0;
	for(int i = 1; i<n;i++){
		int temp = a[i];
		int j = i-1;
		while((temp<a[j])&&(j>=0)){
			a[j+1]=a[j];
			j--;
		}
		a[j + 1]= temp;
		dem = dem + 1;
		print(a,n,dem);
	}
}
void bubble_sort(int *a, int n){
	int dem = 0;
	for(int i=0; i<=n-2; i++){
		for(int j=n-1;j>i;j--){
			if(a[j]<a[j-1]){
				int temp = a[j];
				a[j]= a[j-1];
				a[j-1]= temp;
			}
		}
	    dem = dem + 1;
	    print(a,n,dem);
	}
}
void Partition(int *a, int first, int last,int n,int &dem){
if (first>=last) return;
int c=a[first];
int i=first+1,j=last;
while (i<=j){
while (a[i]<=c && i<=j) 
i++;
while (a[j]>c && i<=j) 
j--;
if (i<j) {
swap(a[i],a[j]);
 }
}
swap(a[first],a[j]);
dem = dem + 1;
print(a,n,dem);
Partition(a, first,j-1,n,dem);
Partition(a, j+1,last,n,dem);
}
void heapify(int arr[], int n, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  if (left < n && arr[left] > arr[largest])
    largest = left;
  if (right < n && arr[right] > arr[largest])
    largest = right;
    if (largest != i) {
    int temp =arr[i];
    arr[i]=arr[largest];
    arr[largest]=temp;
    heapify(arr, n, largest);
  }
}

int main(){
	int n;
	cout<<"Nhap so luong phan tu: ";
	cin >> n;
	int *a = new int[n];
	for(int i =0; i< n; i++){
		cout<<"a["<<i+1<<"]= ";
		cin>> a[i];
	}
	
	// sao chep mang
	int *b =new int[n];
	for(int i =0; i<n; i++){
		b[i]=a[i];
	}
	int *c =new int[n];
	for(int i =0; i<n; i++){
		c[i]=a[i];
	}
	int *d = new int[n];
	for(int i =0; i<n;i++){
		d[i]=a[i];
	}
	int *e = new int[n];
	for(int i =0; i<n;i++){
		e[i]=a[i];
	}
	//sap xep chon
	cout<<"*** SELECTION SORT***"<<endl;
	cout<<setw(7)<<"NO.";
	for(int i =0; i<n; i++){
		cout<<setw(5)<<"a["<<i<<"]";
	}
	cout<<endl;
	selection_sort(a,n);
	cout<<endl;
	// sap xep chen
	cout<<"*** ISERTION SORT***"<<endl;
		cout<<setw(7)<<"NO.";
	for(int i =0; i<n; i++){
		cout<<setw(5)<<"a["<<i<<"]";
	}
	cout<<endl;
	insertion_sort(b,n);
	// sap xep noi bot
	cout<<"*** BUBBLE SORT***"<<endl;
	cout<<setw(7)<<"NO.";
	for(int i =0; i<n; i++){
		cout<<setw(5)<<"a["<<i<<"]";
	}
	cout<<endl;
	bubble_sort(c, n);
	// Phan doan
	cout<<"*** Phan doan***"<<endl;
	cout<<setw(7)<<"NO.";
	for(int i =0; i<n; i++){
		cout<<setw(5)<<"a["<<i<<"]";
	}
	cout<<endl;
	int dem =0;
	Partition(d,0,n-1,n,dem);
	// vun dong
    cout<<endl<<"Tao dong ban dau: "<<endl;
    for (int i = n / 2 - 1; i >= 0; i--){
         heapify(e, n, i);
     }
    	for(int i =0;i<n;i++){
		cout<<e[i]<<"   ";
	}
}
