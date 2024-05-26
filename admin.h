#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "utils.h"
#include "mahasiswa.h"
#include "dosen.h"

using namespace std;

struct Admin {
    bool authenticate(const string& username, const string& password) {
        ifstream file("data/admin.txt");
        string line;
        while (getline(file, line)) {
            vector<string> tokens = split(line, ',');
            if (tokens[0] == username && tokens[1] == password) {
                return true;
            }
        }
        return false;
    }

    void crudMahasiswa() {
        int choice;
        while (true) {
            cout << "1. Tambah Mahasiswa\n2. Lihat Mahasiswa\n3. Update Mahasiswa\n4. Hapus Mahasiswa\n5. Kembali\n";
            cout << "Choose an option: ";
            cin >> choice;
            switch (choice) {
                case 1:
                    tambahMahasiswa();
                    break;
                case 2:
                    lihatMahasiswa();
                    break;
                case 3:
                    updateMahasiswa();
                    break;
                case 4:
                    hapusMahasiswa();
                    break;
                case 5:
                    return;
                default:
                    cout << "Invalid choice, please try again.\n";
            }
        }
    }

    void crudDosen() {
        int choice;
        while (true) {
            cout << "1. Tambah Dosen\n2. Lihat Dosen\n3. Update Dosen\n4. Hapus Dosen\n5. Kembali\n";
            cout << "Choose an option: ";
            cin >> choice;
            switch (choice) {
                case 1:
                    tambahDosen();
                    break;
                case 2:
                    lihatDosen();
                    break;
                case 3:
                    updateDosen();
                    break;
                case 4:
                    hapusDosen();
                    break;
                case 5:
                    return;
                default:
                    cout << "Invalid choice, please try again.\n";
            }
        }
    }

private:
    void tambahMahasiswa() {
        ofstream file("data/mahasiswa.txt", ios::app);
        string nama, npm;
        cout << "Nama: ";
        cin >> nama;
        cout << "NPM: ";
        cin >> npm;
        file << nama << "," << npm << "\n";
        cout << "Mahasiswa berhasil ditambahkan.\n";
    }

    void lihatMahasiswa() {
        ifstream file("data/mahasiswa.txt");
        string line;
        while (getline(file, line)) {
            vector<string> tokens = split(line, ',');
            cout << "Nama: " << tokens[0] << ", NPM: " << tokens[1] << "\n";
        }
    }

    void updateMahasiswa() {
        string nama, npm;
        cout << "Masukkan NPM Mahasiswa yang ingin diupdate: ";
        cin >> npm;
        ifstream file("data/mahasiswa.txt");
        ofstream temp("data/temp.txt");
        string line;
        bool found = false;
        while (getline(file, line)) {
            vector<string> tokens = split(line, ',');
            if (tokens[1] == npm) {
                found = true;
                cout << "Nama Baru: ";
                cin >> nama;
                temp << nama << "," << npm << "\n";
            } else {
                temp << line << "\n";
            }
        }
        file.close();
        temp.close();
        remove("data/mahasiswa.txt");
        rename("data/temp.txt", "data/mahasiswa.txt");
        if (found) {
            cout << "Mahasiswa berhasil diupdate.\n";
        } else {
            cout << "Mahasiswa tidak ditemukan.\n";
        }
    }

    void hapusMahasiswa() {
        string npm;
        cout << "Masukkan NPM Mahasiswa yang ingin dihapus: ";
        cin >> npm;
        ifstream file("data/mahasiswa.txt");
        ofstream temp("data/temp.txt");
        string line;
        bool found = false;
        while (getline(file, line)) {
            vector<string> tokens = split(line, ',');
            if (tokens[1] == npm) {
                found = true;
            } else {
                temp << line << "\n";
            }
        }
        file.close();
        temp.close();
        remove("data/mahasiswa.txt");
        rename("data/temp.txt", "data/mahasiswa.txt");
        if (found) {
            cout << "Mahasiswa berhasil dihapus.\n";
        } else {
            cout << "Mahasiswa tidak ditemukan.\n";
        }
    }

    void tambahDosen() {
        ofstream file("data/dosen.txt", ios::app);
        string nama, nidn, mataKuliah;
        cout << "Nama: ";
        cin >> nama;
        cout << "NIDN: ";
        cin >> nidn;
        cout << "Mata Kuliah: ";
        cin >> mataKuliah;
        file << nama << "," << nidn << "," << mataKuliah << "\n";
        cout << "Dosen berhasil ditambahkan.\n";
    }

    void lihatDosen() {
        ifstream file("data/dosen.txt");
        string line;
        while (getline(file, line)) {
            vector<string> tokens = split(line, ',');
            cout << "Nama: " << tokens[0] << ", NIDN: " << tokens[1] << ", Mata Kuliah: " << tokens[2] << "\n";
        }
    }

    void updateDosen() {
        string nama, nidn, mataKuliah;
        cout << "Masukkan NIDN Dosen yang ingin diupdate: ";
        cin >> nidn;
        ifstream file("data/dosen.txt");
        ofstream temp("data/temp.txt");
        string line;
        bool found = false;
        while (getline(file, line)) {
            vector<string> tokens = split(line, ',');
            if (tokens[1] == nidn) {
                found = true;
                cout << "Nama Baru: ";
                cin >> nama;
                cout << "Mata Kuliah Baru: ";
                cin >> mataKuliah;
                temp << nama << "," << nidn << "," << mataKuliah << "\n";
            } else {
                temp << line << "\n";
            }
        }
        file.close();
        temp.close();
        remove("data/dosen.txt");
        rename("data/temp.txt", "data/dosen.txt");
        if (found) {
            cout << "Dosen berhasil diupdate.\n";
        } else {
            cout << "Dosen tidak ditemukan.\n";
        }
    }

    void hapusDosen() {
        string nidn;
        cout << "Masukkan NIDN Dosen yang ingin dihapus: ";
        cin >> nidn;
        ifstream file("data/dosen.txt");
        ofstream temp("data/temp.txt");
        string line;
        bool found = false;
        while (getline(file, line)) {
            vector<string> tokens = split(line, ',');
            if (tokens[1] == nidn) {
                found = true;
            } else {
                temp << line << "\n";
            }
        }
        file.close();
        temp.close();
        remove("data/dosen.txt");
        rename("data/temp.txt", "data/dosen.txt");
        if (found) {
            cout << "Dosen berhasil dihapus.\n";
        } else {
            cout << "Dosen tidak ditemukan.\n";
        }
    }
};

#endif