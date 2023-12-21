#include <iostream>
#include <iomanip>
using namespace std;


class DSinhVien {
private:
    string TenSV;
    string MSV;
    string Lop;
    string gioitinh;
    double DChuyenCan;
    double DThiGiuaKy;
    double DThiCuoiKy;

public:
    void Nhap();
    void In();
    string XepLoai();
    double tinhdiemketthucmon();
};

// Ham nhap thong tin sinh vien:
void DSinhVien::Nhap() {
    cout << "Nhap ten sv: ";
    getline(cin, TenSV);
    cout << "\nNhap MSV: ";
    getline(cin, MSV);
    cout << "\nNhap lop: ";
    getline(cin, Lop);
    cout << "\nNhap gioi tinh: ";
    getline(cin, gioitinh);
    cout << "\nNhap DChuyenCan: ";
    cin >> DChuyenCan;
    cout << "\nNhap DThiGiuaKy: ";
    cin >> DThiGiuaKy;
    cout << "\nNhap DThiCuoiKy: ";
    cin >> DThiCuoiKy;
    cin.ignore();
}

// Ham in thong tin sinh vien:
void DSinhVien::In() {
    cout << left << setw(16) << TenSV
         << setw(20) << MSV
         << setw(15) << Lop
         << setw(17) << gioitinh
         << setw(20) << DChuyenCan
         << setw(23) << DThiGiuaKy
         << setw(26) << DThiCuoiKy
         << setw(20) << tinhdiemketthucmon()
         << XepLoai() << endl;
}

// Ham tinh diem ket thuc mon va xep loai:
double DSinhVien::tinhdiemketthucmon() {
    return DChuyenCan * 0.1 + DThiGiuaKy * 0.4 + DThiCuoiKy * 0.5;
}

string DSinhVien::XepLoai() {
    double DKetthuc = tinhdiemketthucmon();
    if (DKetthuc >= 8.5 && DKetthuc <= 10) {
        return "A";
    } else if (DKetthuc >= 7.0 && DKetthuc <= 8.4) {
        return "B";
    } else if (DKetthuc >= 5.5 && DKetthuc <= 6.9) {
        return "C";
    } else if (DKetthuc >= 4.0 && DKetthuc <= 5.4) {
        return "D";
    } else {
        return "F";
    }
}

void Khung_BNV() {
    string separator(172, '-');
    cout << separator << endl;
    cout << setw(68) << setfill(' ') << ' ' << "BANG DIEM SINH VIEN" << endl;
    cout << separator << endl;
    cout << left
         << setw(16) << "Ho va Ten"
         << setw(20) << "Ma Sinh Vien"
         << setw(15) << "Lop"
         << setw(17) << "Gioi Tinh"
         << setw(20) << "Diem chuyen can"
         << setw(23) << "Diem giua ky"
         << setw(26) << "Diem cuoi ky"
         << setw(20) << "Diem tong ket"
         << "Diem Chu" << endl;
    cout << separator << endl;
}

int main() {
    char x;
    do {
        cout << "_______TINH DIEM CHO SINH VIEN_______";
        cout << endl;
        DSinhVien sinhvien;
        sinhvien.Nhap();
        Khung_BNV();
        sinhvien.In();
        do {
            cout << "Ban co muon nhap tiep khong ?(neu co nhap 'c',neu khong nhap 'k') ";
            cin >> x;
            cin.ignore();
            if (x == 'k') {
                cout << "CHUONG TRINH KET THUC, CAM ON BAN DA TIN TUONG VA SU DUNG!";
                break;
            }
        } while (x != 'c');
    } while (x == 'c');
}

