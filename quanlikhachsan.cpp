#include<iostream>
#include<fstream>
#include<iomanip>
#include<windows.h>
using namespace std ;

void menu();

class ManageMenu {
	protected :
		string userName ;
	public :
		ManageMenu () 
		{
			cout << "\n\n\n\n\n\n\n\n\t Nhap ten cua ban de tiep tuc lam quan tri vien :" ;
			getline ( cin , userName ) ;
			system ("CLS");
			menu();
		}
};

class Customers{
	public :
		string name , gender , address ;
		int age , mobileNo ;
		static int  cusID ;
		char all[999]; 
		
		void getDetails () {
			ofstream out("old-customers.txt" , ios::app);
			{
				cout << "Nhap id khach hang: ";
				cin >> cusID ;
				cout << "Nhap ten: ";
				cin >> name ;
				getline( cin , name ) ;
				cout << "Nhap tuoi  ";
				cin >> age ;
				cout << "Nhap so dien thoai: ";
				cin >> mobileNo ;
				cin.ignore() ;
				cout << "Nhap dia chi: ";
				getline ( cin , address ) ;
				cout << "Nhap gioi tinh: ";
				cin >> gender ;
				
			}
			out << "\nID khach hang: " << cusID << "\nTen : " << name << "\nTuoi: " << age << 	"\nMoblie Number: " << mobileNo << "\nAdress: " << address  << "\nGender" << gender << endl ;
			out.close()	;
			cout << "\n save \n NOTE :chung toi luu ho so cua ban cho cac muc dich sau nay \n " << endl;		    
			
		}	
		void showDetails()
		{
				ifstream in ( "old-customers.txt" ) ;
				{
					if (!in)
					{
						cout <<"loi tap tin!" << endl ;
					}
					while (!(in.eof()))
					{
						in.getline(all , 999);
						cout << all << endl ;
					}
					in.close() ;
			}
		}
};

int Customers::cusID;
class Cabs 
{
public :
	int cabChoice ;
	int kilometers ;
	float cabCost ;
	static float lastcabCost ;
	
	
	void cabDetails()
	{
		cout << "Chung toi da hop tac voi dich vu taxi nhanh nhat an toan nhat va thong minh nhat tren toan quoc" <<  endl ;
		cout << "------------ABC cabs------------\n" << endl ;
		cout << "1. thue 1 chiec taxi tieu chuan - rs.15 for 1km" << endl ;
		cout << "2. thue 1 chiec taxi sang trong - rs.25 per 1km" << endl ;
		
		cout << "\nDe tinh chi phi cho hanh trinh cua ban:" << endl ;
		cout << "Hay nhap loai taxi ma ban can:" ;
		cin >> cabChoice ;
		cout << "Nhap so km ban muon di: " ;
		cin >> kilometers ;
		
		int hireCab ;
		
		if ( cabChoice == 1) {
			cabCost = kilometers  * 15 ;
			cout << "\n Chi phi tham quan cua ban " << cabCost  << "rupees cho 1 chiec taxi tieu chuan" << endl ;
			cout << "nhan phim 1 de thue taxi hoac :" ;
			cout << "nhan phim 2 de chon taxi khac :";
			cin >> hireCab  ;
			
			system ("CLS");
			
			if (hireCab == 1) {
				lastcabCost = cabCost ;
				cout << "\nBan da thue thanh cong 1 chiec taxi tieu chuan" << endl ;
				cout << "Vao menu va lay bien lai " << endl ;
			}
			else if ( hireCab == 2) 
			{
				cabDetails() ;
			}
			else {
				cout << "dau vao khong hop le , dang chuyen huong den menu truoc ! vui long doi !!!" << endl ;
				Sleep(999);
				system("CLS");
				cabDetails() ;
			}
			
		}
		
		else if (cabChoice == 2) 
		{
			cabCost = kilometers * 25 ;
			cout << "\nChi phi tham quan cua ban " << cabCost << "rupess cho 1 chiec taxi sang trong \n" << endl ;
			cout << "nhan phim 1 de thue taxi hoac :" ;
			cout << "nhan phim 2 de chon taxi khac :";	
			cin >> hireCab  ;
			system ("CLS");
			
				
			if (hireCab == 1) {
				lastcabCost = cabCost ;
				cout << "\nBan da thue thanh cong 1 chiec taxi sang trong " << endl ;
				cout << "Vao menu va lay bien lai " << endl ;
			}
			else if ( hireCab == 2) 
			{
				cabDetails() ;
			}
			else {
				cout << "dau vao khong hop le , dang chuyen huong den menu truoc ! vui long doi" << endl ;
				Sleep(1100);
				system("CLS");
				cabDetails() ;
			}
	}
		else {
			cout << "dau vao khong hop le , dang chuyen huong den menu truoc ! vui long doi!" << endl ;
				Sleep(1100);
				system("CLS");
			//	menu() ;
		}
		
		cout << "\nNhan phim 1 de chuyen huong den menu chinh: " ;
		cin >> hireCab ;
		system ("CLS");
		if ( hireCab == 1) {
			menu();
		}
		else {
			menu() ;
			// khong co dau cham phay 
		}
	}
};

float Cabs::lastcabCost ;

class Booking 
{
	
public :
	int choiceHotel ;
	int packChoice ;
	static float hotelCost ;
	
	void hotels () 
	{
		string hotelNo[] = {"Avendra" , "Choiceyou" , " ElephantBay"} ;
		for ( int i = 0 ; i < 3 ; i++) {
			cout << (i+1) << ".Hotel" << hotelNo[i] << endl ; 
		}
		
		cout << "\n Hien tai chung toi da hop tac voi cac khach san tren!" << endl ;
		
		cout << "Nhan phim bat ki de quay lai hoac  \n Nhap so khach san ban muon dat: " ;
		cin >> choiceHotel ;
		
		system("CLS") ;
		
		
		if ( choiceHotel == 1) {
			cout << "--------WELCOME TO HOTEL AVENDRA-------\n" << endl ;
			
			cout << "The Garden , food and beverage. Enjoy all you can drink, stay cool and get chilled  in the summer sun." << endl ;
 			// the garden do an thuc va thuc uong . Hay tan huong tat ca nhung gi ban co the uong , mat lanh va giai nhiet trong nang he 
 			
 			cout << "Cac dich vu duoc cung cap boi Avendra:\n " << endl ;
 			
 			cout << "1. Goi tieu chuan " << endl ;
 			cout << "\t tat ca cac dich vu co ban chi can co : rs.5000.00 " << endl ;
 			cout << "2. goi cao cap  " << endl ;
 			cout << "\t Thuong thuc cao cap : rs.10000.00" << endl ;
 			cout << "3. Goi Sang Chanh  " << endl ;
 			cout << "\t Song sang trong tai avendra: rs.15000.00" << endl ;
 			
 			cout << "\nNhan mot phim khac de quay lai hoac nhap so goi ban muon dat : " ;
 			cin >> packChoice ;
 			
 			if ( packChoice == 1) {
 				hotelCost = 5000.00 ;
 				// standard : tieu chuan 
 				cout << " \n Ban da dat thanh cong goi tieu chuan tai avendra " << endl ;
 				cout << "Vao menu va lay bien lai " << endl ;
			 }
			else if ( packChoice == 2 ) {
				hotelCost = 10000.00 ;
				// premium : cao cap 
				cout << " \n Ban da dat thanh cong goi cao cap tai avendra " << endl ;
 				cout << "Vao menu va lay bien lai " << endl ;
			}
			else if ( packChoice == 3 ) {
				hotelCost = 15000.00 ;
				// luxury : sang trong 
				cout << " \n Ban da dat thanh cong goi sang trong tai avendra " << endl ;
 				cout << "Vao menu va lay bien lai " << endl ;	
			}
			else {
				cout <<"\nDau vao khong hop le !!!dang chuyen den menu truoc vui long doi!!" << endl ;
				Sleep (1100);
				system ("CLS") ;
				hotels();
				
			}
			
			int gotoMenu ;
			cout << "\nNhan phim 1 de chuyen huong menu chinh " ;
			cin >> gotoMenu ;
			if ( gotoMenu == 1) {
				menu() ;
			}
			else {
				menu ();
			}
		}
		
		else if (choiceHotel == 2) {
			cout << "--------WELCOME TO HOTEL CHOICEYOU -------\n" << endl ;
			
			cout << "Khach san danh cho Ban ---- !!!! @@@ -.-.-.-." << endl ;
 			// the garden do an thuc va thuc uong . Hay tan huong tat ca nhung gi ban co the uong , mat lanh va giai nhiet trong nang he 
 			
 			cout << "Cac goi dich vu duoc cung cap boi Choiceyou:\n " << endl ;
 			
 			cout << "1. goi phuc vu Gia Dinh " << endl ;
 			cout << "\t ban chi can bo ra : rs.15000.00 " << endl ;
 			cout << "2. goi danh cho cac cap doi  " << endl ;
 			cout << "\t ban chi can bo ra : rs.10000.00" << endl ;
 			cout << "3. goi don " << endl ;
 			cout << "\t ban chi can bo ra:  rs.5000.00" << endl ;
 			
 			cout << "\nNhan 1 phim khac de quay lai hoac \n nhap so goi ban muon dat: " ;
 			cin >> packChoice ;
 			
 			
 			if ( packChoice == 1) {
 				hotelCost = 15000.00 ;
 				// standard : tieu chuan 
 				cout << " \n Ban da dat thanh cong goi gia dinh tai choiceyou  " << endl ;
 				cout << "goto menu and take the receipt " << endl ;
			 }
			else if ( packChoice == 2 ) {
				hotelCost = 10000.00 ;
				// premium : cao cap 
				cout << " \n Ban da dat thanh cong goi cap doi tai choiceyou " << endl ;
 				cout << "Vao menu va nhan bien lai " << endl ;
			}
			else if ( packChoice == 3 ) {
				hotelCost = 5000.00 ;
				// luxury : sang trong 
				cout << " \n Ban da dat thanh cong goi don tai choiceyou " << endl ;
 				cout << "goto menu and take the receipt " << endl ;	
			}
			else {
				cout <<"\nInvalid Input ! redirecting to previous Menu \n please wait !" << endl ;
				Sleep (1100);
				system ("CLS") ;
				hotels();
			}
			
				
			int gotoMenu ;
			cout << "\nPress 1 to redirect main menu: " ;
			cin >> gotoMenu ;
			if ( gotoMenu == 1) {
				menu() ;
			}
			else {
				menu ();
			}
		}
		else if (choiceHotel == 3) {
			cout << "--------WELCOME TO HOTEL ELEPHANTBAY-------\n" << endl ;
			
			cout << "dat trong khu rung nhiet doi ben bo song maha oya khi nhin thay nhung chu vui" << endl ;
 			cout << "uu dai tuyet voi trong mua he nay rs.5000.00 trong 1 ngay !!!!" << endl ;
 			
 			cout << "\n Nhan phim bat ki de quay lai hoac \n nhan 1 de dat goi dac biet nay:" ;
 			
 			cin >> packChoice ;
			
			if ( packChoice == 1) {
 				hotelCost = 5000.00 ;
 				// standard : tieu chuan 
 				cout << " \n ban da dat thanh cong goi dac biet tai elphantbay" << endl ;
 				cout << "goto menu and take the receipt " << endl ;
			 }
			 else {
			 	cout <<"\nInvalid Input ! redirecting to previous Menu \n please wait !" << endl ;
				Sleep (1100);
				system ("CLS") ;
				hotels();
			 }
			int gotoMenu ;
			cout << "\nPress 1 to redirect main menu: " ;
			cin >> gotoMenu ;
			if ( gotoMenu == 1) {
				menu() ;
			}
			else {
			menu ();
			}
		}
		else {
				cout <<"\nInvalid Input ! redirecting to previous Menu \n please wait !" << endl ;
				Sleep (1100);
				system ("CLS") ;
				menu();
		}
		
	}
};

float Booking::hotelCost ;


class Charges :public Booking , Cabs , Customers 
{
	public :
		void printBill () 
		{
			
			ofstream outf("receipt.txt");
			{
				outf <<"---------ABC Dai ly du lich*--------" << endl ;
				outf <<"-------------Bien Lai---------------" << endl ;
				outf <<"-----------------------------------" << endl ;
				
				outf <<"ID Khach hang : " << Customers::cusID << endl << endl  ;
				outf <<"Bao gom:  \t \t Tong cong" << endl ;
				outf <<"Chi phi khach san : \t \t " << fixed << setprecision(2) << Booking::hotelCost <<  endl ;
				outf <<"Chi phi di lai (taxi) : \t " << fixed << setprecision(2) << Cabs::lastcabCost << endl ;
				
				outf <<"-------------------------- " << endl ;
				outf <<"Tong phi : \t\t " << fixed <<setprecision(2) << Booking::hotelCost + Cabs::lastcabCost << endl ;
				outf <<"-------------------------- " << endl ;
				outf <<"---------Thank You-------- " << endl ;	
			}
			
			outf.close();
			
		}
		
		void showBill () 
		{
			ifstream inf ("receipt.txt") ;
			{
				if (!inf) 
				{
					cout << "file opening error! " << endl ;
				}
				while (!(inf.eof())) 
				{
					inf.getline(all , 999) ;
					cout << all << endl ;
				}
			}
			inf.close() ;
		}
		
};

void menu () 
{
	int mainChoice ;
	int inChoice ;	
	int gotoMenu ;
	
	
	cout << "\t \t     *Khu Du lich ABC *\n*" << endl ;
	cout <<  " ------------------Main menu ----------------" << endl ;
	
	
	cout << "\t _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ " << endl ;
	cout << "\t|\t\t\t\t\t " << endl ;
	cout << "\t|\tQuan li khach hang -> 1\t|" << endl ;
	cout << "\t|\tquan li taxi       -> 2\t|" << endl ;
	cout << "\t|\tquan li dat phong   ->3\t|" << endl ;
	cout << "\t|\tPhi & Hoa don      -> 4\t|" << endl ;
	cout << "\t|\tExit             -> 5\t|" << endl ;
	cout << "\t|\t\t\t\t\t " << endl ;
	cout << "\t _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ " << endl ;
	
	cout <<"\nNhap su lua chon cua ban : " ;
	cin >> mainChoice ;
	
	
	system ("CLS");
	
	Customers a2 ;
	Cabs a3 ;
	Booking a4 ;
	Charges a5 ;
	
	if ( mainChoice == 1)
	{
		cout <<"------Khach Hang-------\n" << endl ;
		cout <<"1. Nhap khach hang moi " << endl ;
		cout <<"2. Xem khach hang cu " << endl ;
		
		cout <<"\nNhap lua chon : ";
		cin >> inChoice ;
		
		system("CLS");
		if ( inChoice == 1)
		{
			a2.getDetails();
		}
		else if ( inChoice == 2) {
			a2.showDetails();
		}
		else {
			cout <<"Dau vao khong hop le , dang chuyen huong den menu truoc\n Vui long doi!!! " << endl ;
			Sleep(1100);
			system ("CLS") ;
			menu() ;
		}
			
		cout << "\nNhan phim 1 de chuyen menu : " ;
		cin >> gotoMenu ; 
		
		system ("CLS");
		if (gotoMenu == 1) {
			menu ();
		}
		else {
			menu() ;
		}
	}
	else if ( mainChoice == 2) {
		a3.cabDetails();
	}
	else if ( mainChoice == 3) {
		cout <<" ----> Dat 1 khach san sang trong trong he thong <---" << endl ;
		a4.hotels();
	}
	else if ( mainChoice == 4 ) {
		cout << "---> Nhan bien lai cua ban  <---" << endl ;
		a5.printBill() ;
		
		cout << "Bien lai cua ban da duoc in , ban co the lay ngay bay gio\n " << endl ;
		cout << "De hien thi bien lai len man hinh hay nhap phim 1 \nHoac nhap phim bat ki de quay lai menu chinh : " << endl ;
		
		cin >> gotoMenu ;
		if ( gotoMenu == 1){
			system("CLS") ;
			a5.showBill();
			cout << "Nhap phim 1 de quay lai menu chinh: " ;
			cin >> gotoMenu ;
			system("CLS");
			if ( gotoMenu == 1) {
				menu();
			}	
			else {
				menu();
			}
		}	
		else {
			system("CLS");
			Sleep(999);
			menu();
		}
	}
	else if (mainChoice == 5 ) {
		cout << "----GOODBYE------" << endl ;
		Sleep (999) ;
		system("CLS");
		menu();
	}
	else {
			cout <<"Invalid Input! Redirecting to previous Menu \n Please  Wait! " << endl ;
			Sleep(1100);
			system ("CLS") ;
			menu() ;
	}
	
	
}


int main () 
{
	ManageMenu a ;
	return 0;
}

