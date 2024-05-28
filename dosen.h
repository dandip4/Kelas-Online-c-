#ifndef DOSEN_H
#define DOSEN_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include "utils.h"

using namespace std;

struct Dosen
{

    bool auth(const string &username, const string &password)
    {
        ifstream file("data/dosen.txt");
        string line;
        while (getline(file, line))
        {
            vector<string> tokens = split(line, ',');
            if (tokens[0] == username && tokens[1] == password)
            {
                dosen = tokens[0];
                mataKuliah = tokens[2];
                return true;
            }
        }
        return false;
    }
    void createMinggu()
    {
        string minggu;
        cout << "Minggu (misal: 1, 2, 3, ...): ";
        cin >> minggu;

        ofstream file("data/minggu.txt", ios::app);
        file << mataKuliah << "," << minggu << "\n";
        cout << "Minggu berhasil dibuat.\n";
    }
    void createMateri()
    {
        string minggu = pilihMinggu();
        if (minggu.empty())
            return;
        ofstream file("data/materi/materi_" + mataKuliah + "_" + minggu + ".txt", ios::app);

        string judul, isi;
        cout << "Judul materi: ";
        cin.ignore();
        getline(cin, judul);
        cout << "Isi materi: ";
        getline(cin, isi);

        file << minggu << "\n";
        file << "Mata Kuliah: " << mataKuliah << "\n";
        file << "Judul: " << judul << "\n";
        file << "Isi:\n"
             << isi << "\n\n";
        cout << "Materi berhasil dibuat.\n";
    }
    void createTugas()
    {
        string minggu = pilihMinggu();
        if (minggu.empty())
            return;

        vector<string> tugasData;
        ifstream file("data/tugas.txt");
        string line;
        while (getline(file, line))
        {
            tugasData.push_back(line);
        }

        string judul, deskripsi, deadline;
        cout << "Judul: ";
        cin >> judul;
        cout << "Deskripsi: ";
        cin.ignore();
        getline(cin, deskripsi);
        cout << "Deadline (YYYY-MM-DD): ";
        cin >> deadline;

        string newData = mataKuliah + "," + minggu + "," + judul + "," + deskripsi + "," + deadline;

        tugasData.push_back(newData);

        sort(tugasData.begin(), tugasData.end(), [](const string &a, const string &b)
             {
                    vector<string> tokensA = split(a, ',');
                    vector<string> tokensB = split(b, ',');
                    if (tokensA.size() < 2 || tokensB.size() < 2) 
                        return false; 
                    if (tokensA[0] != tokensB[0]) 
                        return tokensA[0] < tokensB[0];
                    else 
                        return tokensA[1] < tokensB[1]; });

        ofstream outFile("data/tugas.txt");
        for (const auto &tugas : tugasData)
        {
            outFile << tugas << "\n";
        }
        cout << "Tugas berhasil dibuat.\n";
    }

    void createAbsen()
    {
        string minggu = pilihMinggu();
        if (minggu.empty())
            return;

        ofstream file("data/absen.txt", ios::app);
        string tanggal;
        cout << "Tanggal (YYYY-MM-DD): ";
        cin >> tanggal;
        file << mataKuliah << "," << minggu << "," << tanggal << "," << dosen << "\n";
        cout << "Absen berhasil dibuat.\n";
    }

    void viewAbsensi()
    {
        string minggu = pilihMinggu();
        if (minggu.empty())
            return;

        ifstream file("data/absen.txt");
        string line;
        while (getline(file, line))
        {
            vector<string> tokens = split(line, ',');
            if (tokens[0] == mataKuliah && tokens[1] == minggu)
            {
                cout << "Tanggal: " << tokens[2] << "\n";
            }
        }
    }

    void viewTugas()
    {
        string minggu = pilihMinggu();
        if (minggu.empty())
            return;

        ifstream file("data/tugas.txt");
        string line;
        while (getline(file, line))
        {
            vector<string> tokens = split(line, ',');
            if (tokens[0] == mataKuliah && tokens[1] == minggu)
            {
                cout << "Judul: " << tokens[2] << ", Deskripsi: " << tokens[3] << ", Deadline: " << tokens[4] << "\n";
            }
        }
    }

    void viewMahasiswaAbsenDanTugas()
    {
        string minggu = pilihMinggu();
        if (minggu.empty())
            return;

        cout << "Daftar Mahasiswa yang sudah absen di minggu " << minggu << ":\n";
        ifstream absenFile("data/absensi/absensi_" + mataKuliah + ".txt");
        string line;
        while (getline(absenFile, line))
        {
            vector<string> tokens = split(line, ',');
            if (tokens[0] == minggu)
            {
                cout << "Mahasiswa: " << tokens[1] << "Status: " << tokens[2] << "\n";
            }
        }

        cout << "Daftar Mahasiswa yang sudah mengumpulkan tugas di minggu " << minggu << ":\n";
        ifstream tugasFile("data/kumpul_tugas/kumpul_tugas_" + mataKuliah + ".txt");
        while (getline(tugasFile, line))
        {
            vector<string> tokens = split(line, ',');
            if (tokens[0] == minggu)
            {
                cout << "Mahasiswa: " << tokens[1] << ", Tugas: " << tokens[2] << "\n";
            }
        }
    }

    string dosen;
    string mataKuliah;

    string pilihMinggu()
    {
        vector<string> mingguList = getMingguList();
        if (mingguList.empty())
        {
            cout << "Belum ada minggu yang dibuat. Silakan buat minggu terlebih dahulu.\n";
            return "";
        }

        cout << "Pilih Minggu:\n";
        for (size_t i = 0; i < mingguList.size(); ++i)
        {
            cout << i + 1 << ". " << mingguList[i] << "\n";
        }

        int choice;
        cout << "Pilihan: ";
        cin >> choice;

        if (choice < 1 || choice > mingguList.size())
        {
            cout << "Pilihan tidak valid.\n";
            return "";
        }

        return mingguList[choice - 1];
    }

    vector<string> getMingguList()
    {
        vector<string> mingguList;
        ifstream file("data/minggu.txt");
        string line;
        while (getline(file, line))
        {
            vector<string> tokens = split(line, ',');
            if (tokens[0] == mataKuliah)
            {
                mingguList.push_back(tokens[1]);
            }
        }
        return mingguList;
    }
};

#endif
