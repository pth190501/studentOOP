#include <iostream>
#include <string>
#include <vector>
using namespace std;


class SV
{
    private:
    
        string id;
        string name;
        string inClass;
        
    public:
        SV(){}
        SV(string msv, string ten, string lop) : id(msv), name(ten), inClass(lop) {}
        void setName(string ten)
        {
            name = ten;
        }
        
        void setInclass(string lop)
        {
            inClass = lop;
        }
        friend class L;
};

class L
{
    private:
        vector<SV> listSV;
    public:
        void addStudent();
        void delStudent(string msv);
        void editStudent(string msv);
        void showStudent();
        void searchName(string name);
        void sortName();
};


int main()
{
    int input;
    string id;
    L l;
    while (true)
    {
        cout << "CHUONG TRINH QUAN LY SINH VIEN\n";
        cout << "CHUC NANG : \n";
        cout << "1. Them thong tin sinh vien.\n";
        cout << "2. Sua thong tin sinh vien.\n";
        cout << "3. Xoa thong tinh sinh vien.\n";
        cout << "4. Dua ra thong tin sinh vien.\n";
        cout << "5. Xep sinh vien theo ten.\n";
        cout << "6. Tim sinh vien them ten.\n";
        cout << "0. Thoat.\n";
        cout << "Ban chon : " ;
        cin >> input;

        switch (input)
        {
        case 1:
            {
                cout << "Ban da chon them thong tin sinh vien!\n";
                l.addStudent();
                break;
            }
        case 2:
            {
                cin.ignore();
                cout << "Ban da chon sua thong tin sinh vien!\n";
                cout << "Nhap id sinh vien : "; getline(cin, id);
                l.editStudent(id);
                break;
            }
        case 3:
            {
                cout << "Ban da chon xoa thong tin sinh vien!\n";
                cout << "Nhap id sinh vien : "; cin >> id;
                l.delStudent(id);
                break;
                
            }
        case 4:
            {
                cout << "Ban da chon dua ra thong tin sinh vien!\n";
                l.showStudent();
                break;
            }
        case 5:
            {
                cout << "Ban da chon xep sinh vien theo ten!\n";
                l.sortName();
                break;
            }
        case 6:
            {
            string name;
            cout << "Ban da chon tim sinh vien theo ten!\n";
            cout << "Nhap ten sinh vien can tim : "; getline(cin, name);
            l.searchName(name);
            break;
            }
        case 0:
            return 0;
        }
    }
}

void L::addStudent()
{
    string msv, hoTen, lop;
    cin.ignore(32767, '\n');
    cout << "Nhap ma sinh vien: " ; getline(cin, msv);
    for (int i=0; i<listSV.size();i++){
        if (listSV[i].id == msv ){
            cout << "id sinh vien da ton tai";
            return;
        }
    }
    cout << "Nhap ten sinh vien: "; getline(cin, hoTen);
    cout << "Nhap lop : "; getline(cin, lop);
    listSV.push_back(SV(msv, hoTen, lop));
}
    

void L::showStudent()
{
    for (int i=0; i<listSV.size(); i++)
    {
        cout << "MSV : " << listSV[i].id << "     ";
        cout << "Ten SV: " << listSV[i].name << "     ";
        cout << "Lop : " << listSV[i].inClass << endl;
    }
}

void L::delStudent(string msv)
{
    bool isExisted = false;
    for (int i=0; i<listSV.size(); i++)
    {
        if (listSV[i].id == msv)
        {
            isExisted = true;
            listSV.erase(listSV.begin() + i);
            cout << "Da xoa sinh vien" << endl;
            break;
        }
    }
    if (!isExisted)
    {
        cout << "MSVV khong ton tai" << endl;
    }
}

void L::editStudent(string msv)
{
    bool isExisted = false;
    for (int i=0; i<listSV.size(); i++)
    {
        if (listSV[i].id == msv)
        {
            string ten, lop;
            cout << "Nhap lai ten SV: "; getline(cin, ten);
            cout << "Nhap lai lop SV: "; getline(cin, lop);
            listSV[i].setName(ten);
            listSV[i].setInclass(lop);
            break;
        }
    }
    if (!isExisted)
    {
        cout << "MSSV khong ton tai!" << endl;
    }
}
void L::searchName(string name)
{
    bool isExisted = false;
    for (int i = 0; i < listSV.size(); i++){
        if (listSV[i].name == name){
            isExisted = true;
            cout << "Thong tin sinh vien " << name << " la" << endl;
            cout << "MSV : " << listSV[i].id << endl;
            cout << "Ten SV: " << listSV[i].name << endl;
            cout << "Lop : " << listSV[i].inClass << endl;
            break;
        }
    }
    if (!isExisted)
    {
        cout << "Ten sinh vien khong ton tai!" << endl;
    }
}
void L::sortName()
{
    SV tmp;
    string nameSV1;
    string nameSV2;
    for (int i=0; i<listSV.size(); i++){
        nameSV1 = listSV[i].name;
        for (int j=i+1; j<listSV.size(); j++){
            nameSV2 = listSV[j].name;
            if(nameSV1.compare(nameSV2) > 0) { // chuoi 1 lon hon chuoi 2
                            tmp = listSV[j];
                            listSV[j] = listSV[i];
                            listSV[i] = tmp;
            }
        }
    }
    cout << "Da sap xep sinh vien theo ten!\n";
}
