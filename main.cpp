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
        cout << "1. Admin\n2. Dosen\n3. Mahasiswa\n4. Exit\n";
        cout << "Choose your role: ";
        cin >> choice;
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
            cout << "Invalid choice, please try again.\n";
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

    if (!admin.authenticate(username, password))
    {
        cout << "Login failed!\n";
        return;
    }

    int choice;
    while (true)
    {
        cout << "1. CRUD Mahasiswa\n2. CRUD Dosen\n3. Logout\n";
        cout << "Choose an option: ";
        cin >> choice;
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
            cout << "Invalid choice, please try again.\n";
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

    if (!dosen.authenticate(username, password))
    {
        cout << "Login failed!\n";
        return;
    }

    int choice;
    while (true)
    {
        cout << "1. Buat Minggu\n2. Buat Tugas\n3. Buat Absen\n4. Buat Materi\n5. Lihat Tugas\n6. Lihat Absensi\n7. Lihat Mahasiswa Absen dan Tugas\n8. Keluar\nPilihan: ";
        cout << "Choose an option: ";
        cin >> choice;
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
            cout << "Invalid choice, please try again.\n";
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

    if (!mahasiswa.authenticate(username, password))
    {
        cout << "Login failed!\n";
        return;
    }

    mahasiswa.pilihMataKuliah();

    int choice;
    while (true)
    {
        cout << "1. Lihat Tugas dan Absen\n2. Lihat Materi\n3. Kumpul Tugas\n4. Absen\n5. Kumpul Tugas\n";
        cout << "Choose an option: ";
        cin >> choice;
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
            return;
        default:
            cout << "Invalid choice, please try again.\n";
        }
    }
}