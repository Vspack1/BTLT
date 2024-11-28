#include <iostream>  
#include <string>  
using namespace std;

const int MAX_KHACH = 100; // Gioi han so luong khach  
const int GIA_PHONG_DON = 500000; // Gia phong don  
const int GIA_PHONG_DOI = 800000; // Gia phong doi  
const int GIA_PHONG_VIP = 1200000; // Gia phong VIP  

int main() {
    string danhSachTen[MAX_KHACH]; // Mang luu ten khach  
    int danhSachDem[MAX_KHACH];      // Mang luu so dem luu tru  
    int soKhach = 0;                 // So khach hien tai  

    int luaChon;
    do {
        cout << "\n--- Menu ---" << endl;
        cout << "1. Tinh tien." << endl;
        cout << "2. Ghi nhan khach thue phong." << endl;
        cout << "3. Thong ke khach thue phong." << endl;
        cout << "4. Tim khach hang luu tru lau nhat." << endl;
        cout << "0. Thoat." << endl;
        cout << "Chon mot tuy chon: ";
        cin >> luaChon;

        switch (luaChon) {
        case 1: { // Tinh tien  
            int loaiPhong, soDem;
            cout << "Chon loai phong (1: Don, 2: Doi, 3: VIP): ";
            cin >> loaiPhong;
            cout << "Nhap so dem thue: ";
            cin >> soDem;

            int tongTien = 0;
            switch (loaiPhong) {
            case 1:
                tongTien = GIA_PHONG_DON * soDem;
                break;
            case 2:
                tongTien = GIA_PHONG_DOI * soDem;
                break;
            case 3:
                tongTien = GIA_PHONG_VIP * soDem;
                break;
            default:
                cout << "Lua chon khong hop le!" << endl;
                continue; // Quay lai menu  
            }

            if (soDem >= 5) {
                tongTien *= 0.9; // Giam 10%  
            }
            else if (soDem >= 3) {
                tongTien *= 0.95; // Giam 5%  
            }

            cout << "Tong tien khach phai thanh toan: " << tongTien << " dong." << endl;
            break;
        }
        case 2: { // Ghi nhan khach  
            if (soKhach >= MAX_KHACH) {
                cout << "Khong the ghi nhan them khach, da day!" << endl;
                break;
            }
            cout << "Nhap ten khach (0 de ket thuc): ";
            cin.ignore(); // Xoa ky tu moi dong  
            getline(cin, danhSachTen[soKhach]); // Nhap ten khach  
            if (danhSachTen[soKhach] == "0") break;

            cout << "Nhap so dem luu tru: ";
            cin >> danhSachDem[soKhach];

            soKhach++; // Tang so luong khach  
            break;
        }
        case 3: { // Thong ke  
            cout << "Tong so khach da thue phong: " << soKhach << endl;
            int soNgayCoKhach = 0;
            for (int i = 0; i < soKhach; i++) {
                if (danhSachDem[i] > 0) {
                    soNgayCoKhach++;
                }
            }
            cout << "So ngay co khach: " << soNgayCoKhach << endl;
            break;
        }
        case 4: { // Tim khach hang luu tru lau nhat  
            if (soKhach == 0) {
                cout << "Chua co khach luu tru nao." << endl;
                break;
            }

            int maxDem = danhSachDem[0];
            string tenKhachLauNhat = danhSachTen[0];
            for (int i = 1; i < soKhach; i++) {
                if (danhSachDem[i] > maxDem) {
                    maxDem = danhSachDem[i];
                    tenKhachLauNhat = danhSachTen[i];
                }
            }

            cout << "Khach hang luu tru lau nhat: " << tenKhachLauNhat
                << " voi " << maxDem << " dem." << endl;
            break;
        }
        case 0: // Thoat  
            cout << "Ket thuc chuong trinh." << endl;
            break;
        default:
            cout << "Lua chon khong hop le!" << endl;
        }
    } while (luaChon != 0);

    return 0;
}