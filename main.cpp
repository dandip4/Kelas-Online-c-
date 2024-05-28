#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "admin.h"
#include "dosen.h"
#include "mahasiswa.h"
#include "utils.h"

using namespace std;

void adminMenu();
void dosenMenu();
void mahasiswaMenu();

int main()
{
    int choice;
    while (true)
    {
        cout << "Dashboard\n";
        cout << "1. Admin\n2. Dosen\n3. Mahasiswa\n4. Exit\n";
        cout << "Pilih role: ";
        cin >> choice;
        cout << "\n";

        switch (choice)
        {
        case 1:
            adminMenu();
            break;
        case 2:
            dosenMenu();
            break;
        case 3:
            mahasiswaMenu();
            break;
        case 4:
            return 0;
        default:
            cout << "Pilihan gagal.\n";
        }
    }
    return 0;
}

void adminMenu()
{
    Admin admin;
    string username, password;
    cout << "Admin Login\nUsername: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;
    cout << "\n";

    if (!admin.auth(username, password))
    {
        cout << "Login gagal\n";
        return;
    }

    int choice;
    while (true)
    {
        cout << "Menu Admin\n";
        cout << "1. CRUD Mahasiswa\n2. CRUD Dosen\n3. Logout\n";
        cout << "pilih opsi: ";
        cin >> choice;
        cout << "\n";

        switch (choice)
        {
        case 1:
            admin.crudMahasiswa();
            break;
        case 2:
            admin.crudDosen();
            break;
        case 3:
            return;
        default:
            cout << "Pilihan gagal\n";
        }
    }
}

void dosenMenu()
{
    Dosen dosen;
    string username, password;
    cout << "Dosen Login\nNama: ";
    cin >> username;
    cout << "NIDN: ";
    cin >> password;
    cout << "\n";
    if (!dosen.auth(username, password))
    {
        cout << "Login gagal!\n";
        return;
    }

    int choice;
    while (true)
    {
        cout << "Menu Admin\n";
        cout << "1. Buat Minggu\n2. Buat Tugas\n3. Buat Absen\n4. Buat Materi\n5. Lihat Tugas\n6. Lihat Absensi\n7. Lihat Mahasiswa Absen dan Tugas\n8. Keluar\nPilihan: ";
        cout << "pilih opsi: ";
        cin >> choice;
        cout << "\n";
        switch (choice)
        {
        case 1:
            dosen.createMinggu();
            break;
        case 2:
            dosen.createTugas();
            break;
        case 3:
            dosen.createAbsen();
            break;
        case 4:
            dosen.createMateri();
            break;
        case 5:
            dosen.viewTugas();
            break;
        case 6:
            dosen.viewAbsensi();
            break;
        case 7:
            dosen.viewMahasiswaAbsenDanTugas();
            break;
        case 8:
            return;
        default:
            cout << "pilhan gagal\n";
        }
    }
}

void mahasiswaMenu()
{
    Mahasiswa mahasiswa;
    string username, password;
    cout << "Mahasiswa Login\nUsername: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;
    cout << "\n";
    if (!mahasiswa.auth(username, password))
    {
        cout << "Login gagal!\n";
        return;
    }

    mahasiswa.pilihMataKuliah();

    int choice;
    while (true)
    {
        cout << "\n";
        cout << mataKuliah << " Minggu ke: " << minggu << "\n";
        cout << "1. Lihat Tugas dan Absen\n2. Lihat Materi\n3. Kumpul Tugas\n4. Absen\n5. Pilih Minggu\n6. Pilih Matakuliah\n7. Logout\n";
        cout << "pilih opsi: ";
        cin >> choice;
        cout << "\n";
        switch (choice)
        {
        case 1:
            mahasiswa.lihatTugasDanAbsen();
            break;
        case 2:
            mahasiswa.lihatMateri();
            break;
        case 3:
            mahasiswa.kumpulTugas();
            break;
        case 4:
            mahasiswa.absen();
            break;
        case 5:
            mahasiswa.pilihMinggu();
            break;
        case 6:
            mahasiswa.pilihMataKuliah();
            break;
        case 7:
            return;
        default:
            cout << "pilihan gagal\n";
        }
    }
}
// D:\FILE ISO