#ifndef MAHASISWA_H
#define MAHASISWA_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <utility>
#include "utils.h"
#include "akademik.h"

using namespace std;

struct Mahasiswa
{
    bool auth(const string &username, const string &password)
    {
        ifstream file("data/mahasiswa.txt");
        string line;
        while (getline(file, line))
        {
            vector<string> tokens = split(line, ',');
            if (tokens[0] == username && tokens[1] == password)
            {
                mahasiswa = tokens[0];
                return true;
            }
        }
        return false;
    }

    void lihatTugasDanAbsen()
    {
        ::lihatTugasDanAbsen();
    }

    void absen()
    {
        ::absen();
    }

    void kumpulTugas()
    {
        ::kumpulTugas();
    }

    void lihatMateri()
    {
        ::lihatMateri();
    }

    void pilihMataKuliah()
    {
        vector<pair<string, string>> mataKuliahList = getMataKuliahList();
        if (mataKuliahList.empty())
        {
            cout << "Tidak ada mata kuliah tersedia.\n";
            return;
        }

        cout << "Pilih Mata Kuliah:\n";
        for (size_t i = 0; i < mataKuliahList.size(); ++i)
        {
            cout << i + 1 << ". " << mataKuliahList[i].second << " - Diajar oleh: " << mataKuliahList[i].first << "\n";
        }

        int choice;
        cout << "Pilihan: ";
        cin >> choice;

        if (choice < 1 || choice > mataKuliahList.size())
        {
            cout << "Pilihan tidak valid.\n";
            return;
        }

        namaDosen = mataKuliahList[choice - 1].first;
        mataKuliah = mataKuliahList[choice - 1].second;
        cout << "Mata kuliah " << mataKuliah << " dipilih.\n";
    }

    void pilihMinggu()
    {
        vector<string> mingguList = getMingguList();
        if (mingguList.empty())
        {
            cout << "Belum ada minggu yang dibuat.\n";
            return;
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
            return;
        }

        minggu = mingguList[choice - 1];
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

    vector<pair<string, string>> getMataKuliahList()
    {
        vector<pair<string, string>> mataKuliahList;
        ifstream dosenFile("data/dosen.txt");
        string line;

        while (getline(dosenFile, line))
        {
            vector<string> tokens = split(line, ',');
            string namaDosen = tokens[0];
            string mataKuliah = tokens[2];
            mataKuliahList.push_back(make_pair(namaDosen, mataKuliah));
        }

        return mataKuliahList;
    }
};

#endif
