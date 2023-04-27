#include <iostream>
#include <algorithm>
using namespace std;

struct stack {
	int max;
};

bool isEmpty(int top){
    if(top == 0){
        return true;
    } else {
        return false;
    }
}

bool isFull(int top, int max){
    if(top >= max){
        return true;
    } else {
        return false;
    }
}

void display(int data[],int top,int max){
    if(!isEmpty(top)){
        cout << "Data Tersimpan :" << endl;
        for(int a =0; a< top; a++){
            cout << a+1 << ". " << data[a] << endl;
        }
    } else {
        cout << "Data tidak tersedia" << endl;
    }
    
    if(isFull(top,max)){
        cout << "stack Penuh" << endl;
    }
    cout << endl;
}

void push(int data[],int&top, int max){
    if(!isFull(top,max)){
        cout << "Masukkan Data : ";
        cin >> data[top];
        top++;
    }
}

void pop(int &top){
    if(!isEmpty(top)){
        top--;
    } else {
    	cout << "stack kosong" << endl;
	}
}

void rata(int data[], int top){
    if(!isEmpty(top)){
        float total = 0;
        for(int a =0; a<top; a++){
            total += data[a];
        }
        cout << "Nilai rata-rata: " << total / top << endl;
    }
}

void modus(int data[], int top){
    if(!isEmpty(top)){
        sort(data, data + top);
        int counter = 1;
        int max_count = 0;
        int mode = data[0];
        for (int i = 1; i < top; i++){
            if (data[i] == data[i-1]){
                counter++;
            } else {
                if (counter >= max_count){
                    max_count = counter;
                    mode = data[i-1];
                }
                counter = 1;
            }
        }
        if (counter >= max_count){
            max_count = counter;
            mode = data[top-1];
        }
        if (max_count == 1) {
            cout << "Tidak ada modus" << endl;
        } else {
            cout << "Nilai modus: " << mode << endl;
        }
    }
}

void median(int data[], int top){
    if(!isEmpty(top)){
        sort(data, data + top);
        int mid = top / 2;
        if (top % 2 == 0){
            cout << "Nilai median: " << (data[mid-1] + data[mid]) / 2 << endl;
        } else {
            cout << "Nilai median: " << data[mid] << endl;
        }
    }
}

void statistika(){
	stack stk;

	cout << "ukuran stack : ";
	cin >> stk.max;
	if(cin.fail()){
	cin.ignore();
	cin.clear();
		}

	int data[stk.max];
	int top = 0;
    int pil;
    int isi;
    
    stack :
        system("cls");
        display(data,top,stk.max);
        cout << "Menu utama\n1. Push\n2. Pop\n3. Rata-rata, Modus, Median\n4. kembali ke login\nPilih: ";
        cin >> pil;
        if(!cin){
            cin.clear();
            cin.ignore();
            goto stack;
        }
        else if(pil == 1){
            system("cls");
            push(data, top, stk.max);
            goto stack;
        } else if (pil == 2){
            system("cls");
            pop(top);
            goto stack;
        } else if (pil == 3){
            
                rata(data, top);

            if(!isEmpty(top)){
            modus(data, top);  
            median(data, top);
            }else {
                cout << "Belum mencapai data maksimum" << endl;

            }
        } else if(pil == 4){
        	exit(0);
		}else {
    		goto stack;
        }
}
int main(){
	statistika();
}

