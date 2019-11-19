#include <iostream>
#include <string>

using namespace std;

class tulisan{
	private :
	string kata;
	public :
		void set(string masuk){
			this->kata=masuk;
		}
		string get(){
			return this->kata;
		}
};

tulisan ku;

void masuk(){
	string in;
	
	do{
		cout<<"Input your string : ";
		getline(cin,in);
	}while(in.length()==0);
	ku.set(in);
};

void cetak(){
	cout<<"Your String : ";
	cout<<ku.get();
	cout<<endl;
};

void tambah(){
	string in,temp;
	
	temp=ku.get();
	cout<<"Input append string : ";
	getchar();
	getline(cin,in);
	temp.append(in);
	ku.set(temp);
	cout<<"Your string after append : ";
	cout<<ku.get();
};

void hapus(){
	int posisi,hapus;
	string temp;
	
	temp=ku.get();
	do{
		cout<<"Input start index [0..";
		cout<<temp.length();
		cout<<"] : ";
		cin>>posisi;
	}while(posisi<0||posisi>temp.length());
	do{
		cout<<"Input count to erase [1..";
		cout<<(temp.length()-posisi);
		cout<<"] : ";
		cin>>hapus;
	}while(hapus<1||hapus>(temp.length()-posisi));
	temp.erase(posisi,hapus);
	ku.set(temp);
	cout<<"Your string after erase : ";
	cout<<ku.get();
};

void ganti(){
	int posisi,ganti;
	string temp,in;
	
	temp=ku.get();
	cout<<"Input string to replace : ";
	getchar();
	getline(cin,in);
	do{
		cout<<"Input start index [0..";
		cout<<temp.length();
		cout<<"] : ";
		cin>>posisi;
	}while(posisi<0||posisi>temp.length());
	do{
		cout<<"Input count to replace [1..";
		cout<<(temp.length()-posisi);
		cout<<"] : ";
		cin>>ganti;
	}while(ganti<1||ganti>(temp.length()-posisi));
	temp.replace(posisi,ganti,in);
	ku.set(temp);
	cout<<"Your string after replace : ";
	cout<<ku.get();
};

void cabut(){
	int posisi,cabut;
	string temp;
	
	temp=ku.get();
	do{
		cout<<"Input start index [0..";
		cout<<temp.length();
		cout<<"] : ";
		cin>>posisi;
	}while(posisi<0||posisi>temp.length());
	do{
		cout<<"Input count to substring [1..";
		cout<<(temp.length()-posisi);
		cout<<"] : ";
		cin>>cabut;
	}while(cabut<1||cabut>(temp.length()-posisi));
	temp=temp.substr(posisi,cabut);
	ku.set(temp);
	cout<<"Your string after substring : ";
	cout<<ku.get();
};

int jumlahkata(string hitung){
    int jumlah=1;
    for(int i=0;i<hitung.length();i++){
    	if(hitung[i]==' '){
    		jumlah++;
		}
	}
    return jumlah;
}

void menu1(){
    cout<<"======================================="<<endl;
    cout<<"1. Manipulate your string"<<endl;
    cout<<"2. View your string status"<<endl;
    cout<<"3. Exit"<<endl;
    cout<<"Choose : ";
};

void menu2(){
    cout<<"======================================="<<endl;
    cout<<"1. Append your string"<<endl;
    cout<<"2. Erase your string"<<endl;
    cout<<"3. Replace your string"<<endl;
    cout<<"4. Substring your string"<<endl;
    cout<<"5. Back to Main Menu"<<endl;
    cout<<"Choose : ";
};

int main(){
	int choice;
	
	masuk();
	do{
		system("cls");
		cetak();
		menu1();
		cin>>choice;
		switch(choice){
			case 1 : do{
						system("cls");
						cetak();
						menu2();
						cin>>choice;
						switch(choice){
					 		case 1 : tambah(); getchar();break;
					 		case 2 : hapus(); getchar();getchar();break;
					 		case 3 : ganti(); getchar();getchar();break;
					 		case 4 : cabut(); getchar();getchar();break;
					 	}
					 }while(choice!=5); break;
			
			case 2 : system("cls");
					 cetak();
					 cout<<"Length size : ";
					 cout<<ku.get().length()<<endl;
					 cout<<"Capacity : ";
					 cout<<ku.get().capacity()<<endl;
					 cout<<"Amount of Words : ";
					 cout<<jumlahkata(ku.get())<<endl;
					 cout<<"Press Enter to Back Main Menu ...";
					 getchar();getchar();break;
			
			case 3 : cout<<"=-= Open Our Vision and Encourage Ourself =-=";
					 getchar();getchar();break;
		}
	}while(choice!=3);
}
