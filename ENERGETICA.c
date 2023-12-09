#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_COLOR_BLACK   "\x1b[30m"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_WHITE   "\x1b[37m"

typedef struct kotaEnergetica {
	
	char desc[500];
	char nama[50];
	
	float budget;
    float indeksKota;
	int hari;
	
	struct aksesListrik {
        float listrikSubsidi;
        float listrikUmum;
        float listrikTerbaharukan;
        float indeksListrik;
		float sdmListrik;
	} aksesListrik;
	
	struct kebersihanRumahTangga {
		float efisiensiEnergi;
		float wasteManagement;
		float alatKebersihanSustainable;
		float skalaHistogram;
		float indeksKebersihanRT;
	} kebersihanRumahTangga;
	
	struct aksesEnergiBersih {
		float kemudahanAkses;
		float kebersihan;
		float energiTerbarukan;
		float maxValue;
        float skalaHistogram;
        float indeksAksesEnergi;
        float sdmAkses;
	} energiBersih;
	
	struct emisiGasRumahKaca {
		float gasCO2;
		float gasCH4;
		float gasN2O;
		float priceCO2;
		float priceCH4;
		float priceN2O;
		float levelMod;
		float maxValue;
		int skalaHistogram;
		int sdmGas;
		float indeksGasRumahKaca;
		int inc;
		
	} emisiGas;
	
} kota;

//CODE HAKIM

void definisiListrik(kota *energetica) {
	
	energetica[0].aksesListrik.listrikSubsidi = 30;
    energetica[1].aksesListrik.listrikSubsidi = 55;
    energetica[2].aksesListrik.listrikSubsidi = 75;
    energetica[3].aksesListrik.listrikSubsidi = 45;

    energetica[0].aksesListrik.listrikUmum = 45;
    energetica[1].aksesListrik.listrikUmum = 45;
    energetica[2].aksesListrik.listrikUmum = 60;
    energetica[3].aksesListrik.listrikUmum = 35;

    energetica[0].aksesListrik.listrikTerbaharukan = 90;
    energetica[1].aksesListrik.listrikTerbaharukan = 80;
    energetica[2].aksesListrik.listrikTerbaharukan = 60;
    energetica[3].aksesListrik.listrikTerbaharukan = 40;

	energetica[0].aksesListrik.sdmListrik = 250;
	energetica[1].aksesListrik.sdmListrik = 210;
	energetica[2].aksesListrik.sdmListrik = 150;
	energetica[3].aksesListrik.sdmListrik = 90;
}

void changeSubsidi(kota *energetica, float listrikSubsidi, int i) {
    float incPoin = -1, residu = 0, totalBiaya, totalSDM, usedBiaya, usedSDM;
    float biaya = 900000 + (500000 * i); // 900000 1400000 1900000 2400000 
	float sdmCost = floor(3 - (0.5 * i)); // 3 2 2 1

    printf("\nBiaya               : $ %.0f / poin", biaya);
	printf("\nSDM yang diperlukan : %.0f / poin", sdmCost);
    printf("\n\nMasukkan penambahan poin listrik bersubsidi: ");
    
    while (incPoin < 0) {
        scanf("%f", &incPoin);
        if (incPoin < 0) {
            printf("Angka yang dimasukkan tidak valid, silahkan masukkan angka lagi\n");
        }
    }

	totalBiaya = biaya * incPoin;
	totalSDM = sdmCost * incPoin;

	energetica[i].aksesListrik.listrikSubsidi += incPoin;
	if (energetica[i].aksesListrik.listrikSubsidi > 100) {
		residu = energetica[i].aksesListrik.listrikSubsidi - 100;
		energetica[i].aksesListrik.listrikSubsidi = 100;
	}
	usedBiaya = totalBiaya - (residu * biaya);
	usedSDM = totalSDM - (residu * sdmCost);

	if (usedBiaya > energetica[i].budget || usedSDM > energetica[i].aksesListrik.sdmListrik) {
		printf("Budget/SDM Anda tidak memenuhi. Tidak ada yang berubah.");
		energetica[i].aksesListrik.listrikSubsidi -= incPoin;
		energetica[i].hari++;
	} else {
		energetica[i].budget -=  usedBiaya;
		energetica[i].aksesListrik.sdmListrik -= usedSDM;
		printf("Poin overflow = %.0f\n", residu);
	}
}

void changeUmum(kota *energetica, float listrikUmum, int i) {
    float incPoin = -1, residu = 0, totalBiaya, totalSDM, usedBiaya, usedSDM;
    float biaya = 1500000 + (400000 * i); // 1500000 1900000 2300000 2700000
	float sdmCost = 1; // 1 1 1 1

    printf("\nBiaya               : $ %.0f / poin", biaya);
	printf("\nSDM yang diperlukan : %.0f / poin", sdmCost);
    printf("\n\nMasukkan penambahan poin listrik fasilitas umum: ");
    
    while (incPoin < 0) {
        scanf("%f", &incPoin);
        if (incPoin < 0) {
            printf("Angka yang dimasukkan tidak valid, silahkan masukkan angka lagi\n");
        }
    }

	totalBiaya = biaya * incPoin;
	totalSDM = sdmCost * incPoin;

	energetica[i].aksesListrik.listrikUmum += incPoin;
	if (energetica[i].aksesListrik.listrikUmum > 100) {
		residu = energetica[i].aksesListrik.listrikUmum - 100;
		energetica[i].aksesListrik.listrikUmum = 100;
	}
	usedBiaya = totalBiaya - (residu * biaya);
	usedSDM = totalSDM - (residu * sdmCost);

	if (usedBiaya > energetica[i].budget || usedSDM > energetica[i].aksesListrik.sdmListrik) {
		printf("Budget/SDM Anda tidak memenuhi. Tidak ada yang berubah.");
		energetica[i].aksesListrik.listrikUmum -= incPoin;
		energetica[i].hari++;
	} else {
		energetica[i].budget -=  usedBiaya;
		energetica[i].aksesListrik.sdmListrik -= usedSDM;
		printf("Poin overflow = %.0f\n", residu);
	}
}

void changeTerbaharukan(kota *energetica, float listrikTerbaharukan, int i) {
    float incPoin = -1, residu = 0, totalBiaya, totalSDM, usedBiaya, usedSDM;
    float biaya = 1000000; // 1000000 1000000 1000000 1000000
	float sdmCost = 2; // 2 2 2 2

    printf("\nBiaya               : $ %.0f / poin", biaya);
	printf("\nSDM yang diperlukan : %.0f / poin", sdmCost);
    printf("\n\nMasukkan penambahan poin akses listrik terbaharukan: ");
    
    while (incPoin < 0) {
        scanf("%f", &incPoin);
        if (incPoin < 0) {
            printf("Angka yang dimasukkan tidak valid, silahkan masukkan angka lagi\n");
        }
    }

	totalBiaya = biaya * incPoin;
	totalSDM = sdmCost * incPoin;

	energetica[i].aksesListrik.listrikTerbaharukan += incPoin;
	if (energetica[i].aksesListrik.listrikTerbaharukan > 100) {
		residu = energetica[i].aksesListrik.listrikTerbaharukan - 100;
		energetica[i].aksesListrik.listrikTerbaharukan = 100;
	}
	usedBiaya = totalBiaya - (residu * biaya);
	usedSDM = totalSDM - (residu * sdmCost);

	if (usedBiaya > energetica[i].budget || usedSDM > energetica[i].aksesListrik.sdmListrik) {
		printf("Budget/SDM Anda tidak memenuhi. Tidak ada yang berubah.");
		energetica[i].aksesListrik.listrikTerbaharukan -= incPoin;
		energetica[i].hari++;
	} else {
		energetica[i].budget -=  usedBiaya;
		energetica[i].aksesListrik.sdmListrik -= usedSDM;
		printf("Poin overflow = %.0f\n", residu);
	}
}

void aturListrik(kota *energetica, int i) {
    int pil, hari;

	printf("||=============================================\n");
    printf("|| Statistik Listrik\n");
    printf("||=============================================\n");
	printf("|| Status Listrik           : %.2f%%\n", energetica[i].aksesListrik.indeksListrik);
	printf("|| Poin Listrik Subsidi     : %.0f out of 100\n", energetica[i].aksesListrik.listrikSubsidi);
	printf("|| Poin Fasilitas Umum      : %.0f out of 100\n", energetica[i].aksesListrik.listrikUmum);
	printf("|| Poin Energi terbaharukan : %.0f out of 100\n", energetica[i].aksesListrik.listrikTerbaharukan);
	printf("||=============================================\n");

	printf("\nBudget Kota : $ %.2f\n", energetica[i].budget);
	printf("SDM Listrik : %.0f\n", energetica[i].aksesListrik.sdmListrik);

	printf("\nO P S I\n");
	printf("========================\n");
	printf("1. Menyediakan listrik bersubsidi\n");
	printf("2. Penambahan listrik untuk fasilitas umum\n");
	printf("3. Penyediaan listrik dari energi terbaharukan\n");

    printf("\nMasukkan OPSI: "); 
	scanf("%d",&pil);
	
	switch(pil) {
		case 1 : 
			changeSubsidi(energetica,energetica[i].aksesListrik.listrikSubsidi, i);	
			break;
		case 2 : 
			changeUmum(energetica,energetica[i].aksesListrik.listrikSubsidi, i);
			break;
		case 3 : 
			changeTerbaharukan(energetica,energetica[i].aksesListrik.listrikSubsidi, i);
			break;
		default : 
			printf("Input anda tidak valid. Tidak ada yang berubah.\n");
	}

	energetica[i].aksesListrik.indeksListrik = (energetica[i].aksesListrik.listrikSubsidi + energetica[i].aksesListrik.listrikUmum + energetica[i].aksesListrik.listrikTerbaharukan) / 3;
	
	printf("\n||=============================================\n");
    printf("|| Statistik Listrik (Updated)\n");
    printf("||=============================================\n");
	printf("|| Status Listrik           : %.2f%%\n", energetica[i].aksesListrik.indeksListrik);
	printf("|| Poin Listrik Subsidi     : %.0f out of 100\n", energetica[i].aksesListrik.listrikSubsidi);
	printf("|| Poin Fasilitas Umum      : %.0f out of 100\n", energetica[i].aksesListrik.listrikUmum);
	printf("|| Poin Energi terbaharukan : %.0f out of 100\n", energetica[i].aksesListrik.listrikTerbaharukan);
	printf("||=============================================\n\n");

	printf("\nBudget Kota : $ %.2f\n", energetica[i].budget);
	printf("SDM Listrik : %.0f\n", energetica[i].aksesListrik.sdmListrik);

	energetica[i].hari--;
	printf("\nPress any key to continue!");
	getch();
	system("cls");
}

//CODE ALVIN

void definisiKebersihanRumahTangga (kota *energetica) {
	int i;
	
	energetica[0].kebersihanRumahTangga.alatKebersihanSustainable = 40;
	energetica[1].kebersihanRumahTangga.alatKebersihanSustainable = 55;
	energetica[2].kebersihanRumahTangga.alatKebersihanSustainable = 35;
	energetica[3].kebersihanRumahTangga.alatKebersihanSustainable = 30;
	
	energetica[0].kebersihanRumahTangga.efisiensiEnergi = 40;
	energetica[1].kebersihanRumahTangga.efisiensiEnergi = 55;
	energetica[2].kebersihanRumahTangga.efisiensiEnergi = 35;
	energetica[3].kebersihanRumahTangga.efisiensiEnergi = 30;
	
	energetica[0].kebersihanRumahTangga.wasteManagement = 40;
	energetica[1].kebersihanRumahTangga.wasteManagement = 55;
	energetica[2].kebersihanRumahTangga.wasteManagement = 35;
	energetica[3].kebersihanRumahTangga.wasteManagement = 30;

}


void alatKebersihan(kota *energetica, int i) {
    float alatYangDipakai, biayaUrusAlat, totalAlatDipakai, totalBiaya;
    
    printf("Pengaruh Budget dan Poin\n");
    printf("=================================================================================\n");
    printf("|| Biaya Pengurusan Alat\t=\tPoin x 500000 $ (Biaya per Alat)\n");
    printf("|| Pengaruh Pada Index\t\t=\tAkan naik 1 per 4 poin\n");
    printf("=================================================================================\n");

    printf("\nMasukkan jumlah alat kebersihan yang dipakai: ");
    scanf("%f", &alatYangDipakai);

  
    biayaUrusAlat = 500000;  

    totalAlatDipakai = alatYangDipakai * biayaUrusAlat;
    totalBiaya = totalAlatDipakai;
	
	if(totalBiaya > energetica[i].budget) {
		printf("Budget anda tidak cukup!\n");
		energetica[i].hari++;
	} 

    else {
    energetica[i].budget -= totalBiaya;
    energetica[i].kebersihanRumahTangga.alatKebersihanSustainable += alatYangDipakai * 0.25;
    
    if (energetica[i].kebersihanRumahTangga.alatKebersihanSustainable > 100) {
    	printf("Indeks Melebihi Batas! Luar biasa");
    	energetica[i].kebersihanRumahTangga.alatKebersihanSustainable = 100;
	} 
    
	}
	
}


void efisiensiEnergi(kota *energetica, int i) {
    float outputEnergi, kehilanganEnergi, totalKonsumsiEnergi, pengurusanEnergi;

    printf("Pengaruh Budget dan Poin\n");
    printf("=================================================================================\n");
    printf("|| Biaya Penghematan Energi\t=\tPoin x 400000 $ (Biaya per Penghematan Energi)\n");
    printf("|| Pengaruh Pada Index\t\t=\tAkan naik 1 per poin\n");
    printf("=================================================================================\n");

    printf("\nMasukkan output energi rumah tangga: ");
    scanf("%f", &outputEnergi);

    kehilanganEnergi = outputEnergi * 0.1;
    totalKonsumsiEnergi = outputEnergi + kehilanganEnergi;
    pengurusanEnergi = totalKonsumsiEnergi;

    if (pengurusanEnergi * 400000 > energetica[i].budget) {
        printf("Budget anda tidak cukup!\n");
        energetica[i].hari++;  
    } 
	
	else {
        
        energetica[i].kebersihanRumahTangga.efisiensiEnergi += totalKonsumsiEnergi;
        energetica[i].budget -= pengurusanEnergi * 400000; 
   
        if (energetica[i].kebersihanRumahTangga.efisiensiEnergi > 100) {
            printf("Indeks melebihi batas! Luar biasa\n");
            energetica[i].kebersihanRumahTangga.efisiensiEnergi = 100;
        }
    }
}



void manajemenWaste(kota *energetica, int i) {
    float pengumpulanWaste, totalWaste, hargaPembuanganWaste;

	printf("Pengaruh Budget dan Poin\n");
	printf("=================================================================================\n");
	printf("||Budget yang terpakai\t=\tPoin x 1000000 $ (Biaya per waste dikumpulkan)\n");
	printf("||Pengaruh Pada Index\t=\tAkan naik 1 per 4 Poin\n");
	printf("=================================================================================\n");
	
    printf("\nMasukkan jumlah waste yang dikumpulkan: ");
    scanf("%f", &pengumpulanWaste);

    
    hargaPembuanganWaste = pengumpulanWaste * 1000000;  

    totalWaste = pengumpulanWaste;
    
    if(hargaPembuanganWaste > energetica[i].budget) {
    	printf("Budget anda tidak cukup!");
    	energetica[i].hari++;
	}

    else {
	
    energetica[i].kebersihanRumahTangga.wasteManagement += totalWaste;
    energetica[i].budget -= hargaPembuanganWaste;
    energetica[i].kebersihanRumahTangga.wasteManagement += totalWaste * 0.25;
    
    if(energetica[i].kebersihanRumahTangga.wasteManagement > 100) {
    		printf("Indeks melebihi batas! Luar biasa");
    		energetica[i].kebersihanRumahTangga.wasteManagement = 100;
		}
	
	}
}

void aturKebersihanRumahTangga(kota *energetica, int i) {
	int pil;

	printf("DISPLAY\n");
	printf("============================================================\n");
	printf("||TOTAL : %.2f\n", energetica[i].kebersihanRumahTangga.indeksKebersihanRT);
	printf("||1. Penggunaan Alat Rumah Tangga = %.2f\n", energetica[i].kebersihanRumahTangga.alatKebersihanSustainable);
	printf("||2. Keefesienan Penggunaan Energi Rumah Tangga = %.2f\n", energetica[i].kebersihanRumahTangga.efisiensiEnergi);
	printf("||3. Manajamen Waste = %.2f\n", energetica[i].kebersihanRumahTangga.wasteManagement);
	printf("============================================================\n\n");
	
	printf("O P S I\n");
	printf("==========================================================\n");
	printf("||1. Penggunaan Alat Kebersihan Rumah Tangga\n");
	printf("||2. Keefisienan Penggunaan Energi Rumah Tangga\n");
	printf("||3. Manajemen Waste\n");
	printf("==========================================================\n");
	scanf("%d", &pil);
	
	switch(pil) {
		case 1 : 
			alatKebersihan(energetica, i); printf("\nPress Any Button to Continue"); getch(); system("cls"); break;
			
		case 2 : 
			efisiensiEnergi(energetica, i); printf("\nPress Any Button to Continue"); getch(); system("cls"); break;
			
		case 3 : 
			manajemenWaste(energetica, i); printf("\nPress Any Button to Continue"); getch(); system("cls"); break;
			
		default : 
			printf("Tolong masukkan input yang valid!\n"); printf("Press Any Button to Continue"); getch(); system("cls");
			aturKebersihanRumahTangga(energetica,  i);
		
	}
	
	energetica[i].kebersihanRumahTangga.indeksKebersihanRT = (energetica[i].kebersihanRumahTangga.alatKebersihanSustainable * 0.33) + (energetica[i].kebersihanRumahTangga.efisiensiEnergi * 0.33) + (energetica[i].kebersihanRumahTangga.wasteManagement * 0.33);
	
	if(energetica[i].kebersihanRumahTangga.indeksKebersihanRT > 100) {
		printf("Indeks Kebersihan Rumah Tangga Sudah Maksimum!\n");
		energetica[i].kebersihanRumahTangga.indeksKebersihanRT = 100;
	}
	
	energetica[i].hari--;
	
}

//CODE MUSTOF
//Implementasinya agak beda jadi dipertanyakan
//error handling masih kurang
//budget dan efektifitas tiap opsi masih belum diperhitungkan
void definisiEnergiBersih(kota *energetica)
{
	energetica[0].energiBersih.energiTerbarukan = 70;
	energetica[0].energiBersih.kebersihan = 70;
	energetica[0].energiBersih.kemudahanAkses = 55;
	
	energetica[1].energiBersih.energiTerbarukan = 60; 
	energetica[1].energiBersih.kebersihan= 20;
	energetica[1].energiBersih.kemudahanAkses = 40; 
	
	energetica[2].energiBersih.energiTerbarukan = 35;
	energetica[2].energiBersih.kebersihan = 50;
	energetica[2].energiBersih.kemudahanAkses = 35;
	
	energetica[3].energiBersih.energiTerbarukan = 55;
	energetica[3].energiBersih.kebersihan = 80;
	energetica[3].energiBersih.kemudahanAkses = 30;
	
	energetica[0].energiBersih.sdmAkses = 300;
	energetica[1].energiBersih.sdmAkses = 250;
	energetica[2].energiBersih.sdmAkses = 180;
	energetica[3].energiBersih.sdmAkses = 90;
}

void kemudahanAkses (kota *energetica, int i, int nilaiKemudahan, float budget, int hari, int sdm)
{
	if (energetica[i].budget>budget && energetica[i].hari>hari && energetica[i].energiBersih.sdmAkses>sdm)
	{
		energetica[i].energiBersih.kemudahanAkses += nilaiKemudahan;
		energetica[i].budget -= budget;
		energetica[i].hari -= hari;
		energetica[i].energiBersih.sdmAkses -= sdm;
		printf("Sukses untuk melakukan perubahan\n");
	}
	else printf("Salah satu biaya tidak memenuhi!");
}

void kebersihan (kota *energetica, int i, int nilaiKebersihan, float budget, int hari, int sdm)
{
	if (energetica[i].budget>budget && energetica[i].hari>hari && energetica[i].energiBersih.sdmAkses>sdm)
	{
		energetica[i].energiBersih.kebersihan += nilaiKebersihan;
		energetica[i].budget -= budget;
		energetica[i].hari -= hari;
		energetica[i].energiBersih.sdmAkses -= sdm;
		printf("Sukses untuk melakukan perubahan\n");
	}
	else printf("Salah satu biaya tidak memenuhi!");
}

void penambahanEnergi (kota *energetica, int i, int nilaiPenambahan, float budget, int hari, int sdm)
{
	if (energetica[i].budget>budget && energetica[i].hari>hari && energetica[i].energiBersih.sdmAkses>sdm)
	{
		energetica[i].energiBersih.energiTerbarukan += nilaiPenambahan;
		energetica[i].budget -= budget;
		energetica[i].hari -= hari;
		energetica[i].energiBersih.sdmAkses -= sdm;
		printf("Sukses untuk melakukan perubahan\n");
	}
	else printf("Salah satu biaya tidak memenuhi!");
}

void displayAkses (int i, int nilaiPenambahan, float budget, int hari, int sdm)
{
	printf("===============Status Perubahan==============\n");
	printf("||Nilai dari variabel yang bertambah %d\n", nilaiPenambahan);
	printf("||Budget yang dibutuhkan %.2f\n", budget);
	printf("||Hari yang dibutuhkan %d\n", hari);
	printf("||SDM yang dibutuhkan %d\n", sdm);
	printf("=============================================\n");
	printf("Apakah Anda ingin melanjutkan pembangunan?\n");
	printf("1. Ya\n");
}

void aturAksesEnergi(kota *energetica, int i)
{
	int opsi, confirm;
	printf("================Status Indeks================\n");
	printf("||Kemudahan akses energi 	: %.2f / 100\n", energetica[i].energiBersih.kemudahanAkses);
	printf("||Kebersihan energi 		: %.2f / 100\n", energetica[i].energiBersih.kebersihan);
	printf("||Kuantitas energi terbarukan 	: %.2f / 100\n", energetica[i].energiBersih.energiTerbarukan);
	printf("||Kuantitas SDM Akses Energi 	: %.2f\n", energetica[i].energiBersih.sdmAkses);
	printf("=============================================\n");
	printf("\nApa yang ingin diubah pada Akses Energi Bersih?\n");
	printf("1. Pembangunan PLTA\n");
	printf("2. Membuat kebijakan dan regulasi energi bersih\n");
	printf("3. Memberikan edukasi kepada warga\n");
	printf("4. Pembangunan infrasruktur yang lebih baik\n");
	printf("5. Peningkatan akses di daerah terpencil\n");
	scanf("%d", &opsi);
	
	switch (opsi)
	{
		case 1:
			displayAkses (i, 30 , 100000, 10,20);
			scanf("%d",&confirm);
			if (confirm == 1) penambahanEnergi (energetica, i, 30 , 10000000000, 10, 20);
			else printf("Gagal untuk melakukan perubahan\n");
			break;
		case 2 :
			displayAkses (i, 20 , 50000, 5, 10);
			scanf("%d",&confirm);
			if (confirm == 1) kemudahanAkses (energetica, i, 20 , 50000, 5, 10);
			else printf("Gagal untuk melakukan perubahan\n");
			break;
		case 3 :
			displayAkses (i, 10 , 50000, 2, 10);
			scanf("%d",&confirm);
			if (confirm == 1) kebersihan (energetica, i, 10 , 50000, 2, 10);
			else printf("Gagal untuk melakukan perubahan\n");
			break;
		case 4 :
			displayAkses (i, 30 , 100000, 15, 10);
			scanf("%d",&confirm);
			if (confirm == 1) kemudahanAkses (energetica, i, 30 , 100000, 15, 10);
			else printf("Gagal untuk melakukan perubahan\n");
			break;
		case 5 :
			displayAkses (i, 30 , 100000, 10, 10);
			scanf("%d",&confirm);
			if (confirm == 1)	kemudahanAkses (energetica, i, 30 , 100000, 10, 10);
			else printf("Gagal untuk melakukan perubahan\n");
			break;
		default :
			printf("Input tidak valid. Mohon melakukan input ulang!");
			aturAksesEnergi(energetica, i);
	}
	energetica[i].energiBersih.indeksAksesEnergi = (energetica[i].energiBersih.energiTerbarukan + energetica[i].energiBersih.kebersihan + energetica[i].energiBersih.kemudahanAkses) / 3;
	printf("\n\nPress any key to Continue!");
    getch();
    system("cls");
}

//CODE MEERDJAH

void definisiAturEmisi(kota *energetica){
	energetica[0].emisiGas.priceCO2 = 20000;
	energetica[1].emisiGas.priceCO2 = 25000;
	energetica[2].emisiGas.priceCO2 = 30000;
	energetica[3].emisiGas.priceCO2 = 35000;
	
	energetica[0].emisiGas.priceCH4 = 20000;
	energetica[1].emisiGas.priceCH4 = 25000;
	energetica[2].emisiGas.priceCH4 = 30000;
	energetica[3].emisiGas.priceCH4 = 35000;
	
	energetica[0].emisiGas.priceN2O = 20000;
	energetica[1].emisiGas.priceN2O = 25000;
	energetica[2].emisiGas.priceN2O = 30000;
	energetica[3].emisiGas.priceN2O = 35000;
	 
	energetica[0].emisiGas.gasCO2 = 55;
	energetica[1].emisiGas.gasCO2 = 60;
	energetica[2].emisiGas.gasCO2 = 50;
	energetica[3].emisiGas.gasCO2 = 45;
	
	energetica[0].emisiGas.gasCH4 = 75;
	energetica[1].emisiGas.gasCH4 = 80;
	energetica[2].emisiGas.gasCH4 = 65;
	energetica[3].emisiGas.gasCH4 = 70;
	
	energetica[0].emisiGas.gasN2O = 50;
	energetica[1].emisiGas.gasN2O = 55;
	energetica[2].emisiGas.gasN2O = 55;
	energetica[3].emisiGas.gasN2O = 60;
	
	energetica[0].emisiGas.sdmGas = 300;
	energetica[1].emisiGas.sdmGas = 250;
	energetica[2].emisiGas.sdmGas = 180;
	energetica[3].emisiGas.sdmGas = 90;
}

void changeCO2(kota *energetica, float gasCO2, int i) {
	float inc;
	printf("Masukkan kenaikan skor CO2 yang diinginkan: ");
	scanf("%f", &inc);
	
	if(inc > 0 ) {
		if(inc > (100.00 - energetica[i].emisiGas.gasCO2)){
			inc = (100.00 - energetica[i].emisiGas.gasCO2);
		}
		energetica[i].emisiGas.gasCO2 += inc;
		energetica[i].budget -= inc * energetica[i].emisiGas.priceCO2;
		energetica[i].emisiGas.sdmGas -= inc * 3;
		if(energetica[i].emisiGas.indeksGasRumahKaca > 100.00) {
			energetica[i].emisiGas.indeksGasRumahKaca = 100.00;
		}
		printf("Berhasil menaikan skor CO2\n");
		energetica[i].emisiGas.priceCO2 = energetica[i].emisiGas.priceCO2 + (energetica[i].emisiGas.priceCO2 * 0.5);
	} else {
		printf("Tidak ada yang berubah!");
	}
}

void changeCH4(kota *energetica, float gasCH4, int i) {
	float inc;
	printf("Masukkan kenaikan skor CH4 yang diinginkan: ");
	scanf("%f", &inc);
	
	if(inc > 0 ) {
		if(inc > (100.00 - energetica[i].emisiGas.gasCH4)){
			inc = (100.00 - energetica[i].emisiGas.gasCH4);
		}
		energetica[i].emisiGas.gasCH4 += inc;
		energetica[i].budget -= inc * energetica[i].emisiGas.priceCH4;
		energetica[i].emisiGas.sdmGas -= inc * 3;
		printf("Berhasil menaikan skor CH4\n");
		energetica[i].emisiGas.priceCH4 = energetica[i].emisiGas.priceCH4 + (energetica[i].emisiGas.priceCH4 * 0.5);
	} else {
		printf("TIdak ada yang berubah!");
	}
}

void changeN2O(kota *energetica, float gasN2O, int i) {
	float inc;
	printf("Masukkan kenaikan skor N2O yang diinginkan: ");
	scanf("%f", &inc);
	
	if(inc > 0 ) {
		if(inc > (100.00 - energetica[i].emisiGas.gasN2O)){
			inc = (100.00 - energetica[i].emisiGas.gasN2O);
		}
		energetica[i].emisiGas.gasN2O += inc;
		energetica[i].budget -= inc * energetica[i].emisiGas.priceN2O;
		energetica[i].emisiGas.sdmGas -= inc * 3;
		if(energetica[i].emisiGas.indeksGasRumahKaca > 100.00) {
			energetica[i].emisiGas.indeksGasRumahKaca = 100.00;
		}
		printf("Berhasil menaikan skor N2O\n");
		energetica[i].emisiGas.priceN2O = energetica[i].emisiGas.priceN2O + (energetica[i].emisiGas.priceN2O * 0.15);
	} else {
		printf("TIdak ada yang berubah!");
	}
}

void aturEmisi(kota *energetica, int i) {
	int pil, hari;

	energetica[i].emisiGas.indeksGasRumahKaca = (energetica[i].emisiGas.gasCO2 + energetica[i].emisiGas.gasCH4 + energetica[i].emisiGas.gasN2O) / 3;
	
	printf("||=============================================\n");
    printf("|| Statistik Emisi\n");
    printf("||=============================================\n");
	printf("|| Status Emisi    : %.2f%%\n", energetica[i].emisiGas.indeksGasRumahKaca);
	printf("|| Lebih tinggi skornya, lebih baik kualitas udaranya!\n");
	printf("|| CO2 Score       : %.0f out of 100\n", energetica[i].emisiGas.gasCO2);
	printf("|| CH4 Score       : %.0f out of 100\n", energetica[i].emisiGas.gasCH4);
	printf("|| N2O Score	   : %.0f out of 100\n", energetica[i].emisiGas.gasN2O);
	printf("||=============================================\n");

	printf("\nBudget Kota : $ %.2f\n", energetica[i].budget);
	printf("SDM Gas     : %d\n", energetica[i].emisiGas.sdmGas);
	
	printf("\n\nO P S I\n");
	printf("========================\n");
	printf("1. Gas CO2\n");
	printf("2. Gas CH4\n");
	printf("3. Gas N2O\n");
	printf("\nMasukkan Opsi yang dipilih! : ");
	scanf("%d",&pil);
	
	switch(pil) {
		case 1 :
			printf("\nBiaya : %.2f/poin", energetica[i].emisiGas.priceCO2);
			printf("\nSDM : 3/poin\n");
			if(energetica[i].budget < energetica[i].emisiGas.priceCO2){
				printf("Budget tidak cukup!\n");
				getch();
				system("cls");
				break;
			} else {
				changeCO2(energetica,energetica[i].emisiGas.gasCO2, i);
				getch();
				system("cls");
				break;
			}
		case 2 : 
			printf("\nBiaya : %.2f/poin", energetica[i].emisiGas.priceCH4);
			printf("\nSDM : 3/poin\n");
			if(energetica[i].budget < energetica[i].emisiGas.priceCH4){
				printf("Budget tidak cukup!\n");
				getch();
				system("cls");
				break;
			} else {
				changeCH4(energetica,energetica[i].emisiGas.gasCH4, i);
				getch();
				system("cls");
				break;
			}
		case 3 : 
			printf("\nBiaya : %.2f/poin", energetica[i].emisiGas.priceN2O);
			printf("\nSDM : 3/poin\n");
			if(energetica[i].budget < energetica[i].emisiGas.priceN2O){
				printf("Budget tidak cukup!\n");
				getch();
				system("cls");
				break;
			} else {
				changeN2O(energetica,energetica[i].emisiGas.gasN2O, i);
				getch();
				system("cls");
				break;
			}
		default : 
			printf("Masukkan Variabel Yang Valid!");
			getch();
			system("cls");	
	}
	energetica[i].emisiGas.indeksGasRumahKaca = (energetica[i].emisiGas.gasCO2 + energetica[i].emisiGas.gasCH4 + energetica[i].emisiGas.gasN2O) / 3;
	
	printf("||=============================================\n");
    printf("|| Statistik Emisi (UPDATED)\n");
    printf("||=============================================\n");
	printf("|| Status Emisi    : %.2f%%\n", energetica[i].emisiGas.indeksGasRumahKaca);
	printf("|| CO2 Levels      : %.0f out of 100\n", energetica[i].emisiGas.gasCO2);
	printf("|| CH4 Levels      : %.0f out of 100\n", energetica[i].emisiGas.gasCH4);
	printf("|| N2O Levels	   : %.0f out of 100\n", energetica[i].emisiGas.gasN2O);
	printf("||=============================================\n");

	printf("\nBudget Kota : $ %.2f\n", energetica[i].budget);
	printf("SDM Gas     : %d\n", energetica[i].emisiGas.sdmGas);

	energetica[i].hari--;
	printf("\nPress any key to continue!");
	getch();
	system("cls");
	
}

//CODE BERSAMA

void definisiKota(kota *energetica) {
	
    strcpy(energetica[0].nama, "Dea-Tae-AE");
    strcpy(energetica[1].nama, "Elegger City");
    strcpy(energetica[2].nama, "Tekkompolis");
    strcpy(energetica[3].nama, "Biotopia");
    
    strcpy(energetica[0].desc, "Selamat datang di Dea-Tae-AE, di mana kemajuan energi bersih bertabrakan dengan realitas sehari-hari rumah tangga yang memerlukan sentuhan kebersihan yang lebih tajam. Bagaimana kota ini bisa menjadi model holistik untuk keberlanjutan? Itu adalah pertanyaan yang menggantung di udara, sementara penduduk Dea-Tae-AE terus menjelajahi keseimbangan antara teknologi tinggi dan kebutuhan dasar domestik.");
    strcpy(energetica[1].desc, "Selamat datang di Elegger City! Kota yang terang benderang oleh ledakan kreativitas para inovator muda teknik elektro. Dengan akses listrik yang mengalir melalui jalanan dan bangunan-bangunan yang canggih, kota ini benar-benar menjadi laboratorium kehidupan bagi anak-anak teknik elektro yang berbakat. Namun dibalik keramaian teknologi yang memukau, tersembunyi ketidakseimbangan terhadap pengurangan emisi gas rumah kaca yang menjadi bagian yang terpinggirkan!");
    strcpy(energetica[2].desc, "Selamat datang di Tekkompolis! Meski jendela-jendela ruang server bersinar terang, lantai-lantai apartemen masih menyimpan tantangan kebersihan yang menghadang. Dalam dunia Tekkompolis, di mana kode-kode dan algoritma berkembang pesat, kenyataannya adalah bahwa keseimbangan antara teknologi dan kebersihan rumah tangga belum sepenuhnya tercapai. Apakah para pemikir muda di Tekkompolis dapat meretas solusi untuk membangun masa depan yang bersih dan berkelanjutan? Pertanyaan ini menciptakan ketegangan menarik antara kemajuan teknologi dan tanggung jawab lingkungan di kota ini.");
    strcpy(energetica[3].desc, "Selamat datang di Biotopia, kota yang dibanjiri oleh kecerdasan anak-anak muda yang menggali potensi luar biasa di bidang teknik biomedik dan teknologi kesehatan. Di kota ini, laboratorium-laboratorium inovatif dan pusat riset medis menjadi pusat kegiatan, dengan anak-anak cerdas ini membentuk masa depan kesehatan global. Meskipun kebersihan rumah tangga mencapai tingkat unggul, Biotopia berada di persimpangan tantangan yang menarik: akses listrik yang terbatas, pengurangan emisi gas rumah kaca yang kurang memadai, dan akses energi bersih yang masih terkendala.");
    
    energetica[0].budget = 250000000;
    energetica[1].budget = 200000000;
    energetica[2].budget = 150000000;
    energetica[3].budget = 100000000;
	
	//indeks dte = 55
	//indeks elegger = 55
	//indeks tekkompolis = 48,75
	//indeks biotopia = 43,
	
	definisiListrik(energetica);
	definisiEnergiBersih(energetica);
	definisiKebersihanRumahTangga(energetica);
	definisiAturEmisi(energetica);
	
	energetica[0].emisiGas.indeksGasRumahKaca = 60;
	energetica[1].emisiGas.indeksGasRumahKaca = 55;
	energetica[2].emisiGas.indeksGasRumahKaca = 50;
	energetica[3].emisiGas.indeksGasRumahKaca = 40;
	
	energetica[0].hari = 30;
	energetica[1].hari = 25;
	energetica[2].hari = 20;
	energetica[3].hari = 15;
		
}

void gameplay(kota *energetica) {
	int i, j, pilihan, loseTrigger = 0;

	for(i = 0; i < 4; i++) {
        energetica[i].kebersihanRumahTangga.indeksKebersihanRT = (energetica[i].kebersihanRumahTangga.alatKebersihanSustainable + energetica[i].kebersihanRumahTangga.efisiensiEnergi + energetica[i].kebersihanRumahTangga.wasteManagement) / 3;
		energetica[i].aksesListrik.indeksListrik = (energetica[i].aksesListrik.listrikSubsidi + energetica[i].aksesListrik.listrikUmum + energetica[i].aksesListrik.listrikTerbaharukan) / 3;
		energetica[i].emisiGas.indeksGasRumahKaca = (energetica[i].emisiGas.gasCO2 + energetica[i].emisiGas.gasCH4 + energetica[i].emisiGas.gasN2O) / 3;
		energetica[i].energiBersih.indeksAksesEnergi = (energetica[i].energiBersih.energiTerbarukan + energetica[i].energiBersih.kebersihan + energetica[i].energiBersih.kemudahanAkses) / 3;

		printf("L E V E L   %d || %s\n", i + 1, energetica[i].nama);
		printf("==================================\n");
		printf("%s\n\n", energetica[i].desc);
		printf("Press any key to continue!");
		getch();
		system("cls");
		
		while(energetica[i].indeksKota < 75) {
			energetica[i].indeksKota = (energetica[i].aksesListrik.indeksListrik + energetica[i].energiBersih.indeksAksesEnergi + energetica[i].emisiGas.indeksGasRumahKaca + energetica[i].kebersihanRumahTangga.indeksKebersihanRT) * 0.25;
			
			if(energetica[i].indeksKota > 75) {
				break;
			}
			
			if(energetica[i].budget == 0 || energetica[i].hari == 0 ) {
				loseTrigger++;
				break;
			}
			
			printf(ANSI_COLOR_CYAN"============================================================\n");
            printf("Berikut adalah informasi mengenai kota %s sejauh ini\n", energetica[i].nama);
            printf("Budget kota : $ %.2f\n", energetica[i].budget);
            printf("Sisa hari   : %d\n", energetica[i].hari);
            printf("============================================================\n\n"ANSI_COLOR_RESET);

            printf("||=====================================================\n");
            printf("|| Statistik\n");
            printf("||=====================================================\n");
            printf("|| Status Indeks        	: %.2f%% ", energetica[i].indeksKota);
			printf("[");
			for(j = 0; j < (int)(energetica[i].indeksKota / 10); j++) {
				printf("#");
			}
			for(j = 0; j < 10 - (int)(energetica[i].indeksKota / 10); j++) {
				printf(" ");
			}
			printf("]\n");
			printf("||\n");
            printf("|| Status Listrik       	: %.2f%% ", energetica[i].aksesListrik.indeksListrik );
			printf("[");
			for(j = 0; j < (int)(energetica[i].aksesListrik.indeksListrik / 10); j++) {
				printf("#");
			}
			for(j = 0; j < 10 - (int)(energetica[i].aksesListrik.indeksListrik / 10); j++) {
				printf(" ");
			}
			printf("]\n");
            printf("|| Status Kebersihan    	: %.2f%% ", energetica[i].kebersihanRumahTangga.indeksKebersihanRT);
			printf("[");
			for(j = 0; j < (int)(energetica[i].kebersihanRumahTangga.indeksKebersihanRT / 10); j++) {
				printf("#");
			}
			for(j = 0; j < 10 - (int)(energetica[i].kebersihanRumahTangga.indeksKebersihanRT / 10); j++) {
				printf(" ");
			}
			printf("]\n");
            printf("|| Status Energi Bersih 	: %.2f%% ", energetica[i].energiBersih.indeksAksesEnergi);
			printf("[");
			for(j = 0; j < (int)(energetica[i].energiBersih.indeksAksesEnergi / 10); j++) {
				printf("#");
			}
			for(j = 0; j < 10 - (int)(energetica[i].energiBersih.indeksAksesEnergi / 10); j++) {
				printf(" ");
			}
			printf("]\n");
            printf("|| Status Kebersihan Udara	: %.2f%% ", energetica[i].emisiGas.indeksGasRumahKaca);
			printf("[");
			for(j = 0; j < (int)(energetica[i].emisiGas.indeksGasRumahKaca / 10); j++) {
				printf("#");
			}
			for(j = 0; j < 10 - (int)(energetica[i].emisiGas.indeksGasRumahKaca / 10); j++) {
				printf(" ");
			}
			printf("]\n");
			printf("||=====================================================\n");

            printf("\nSektor yang dapat dipilih:\n");
            printf("1. Akses Listrik\n");
            printf("2. Kebersihan Rumah Tangga\n");
            printf("3. Akses Energi Bersih\n");
            printf("4. Emisi Gas Rumah Kaca\n\n");

            printf("Masukkan sektor yang ingin diubah: ");
			scanf("%d", &pilihan);
			switch(pilihan) {
						
				case 1 : 
					system("cls");
					printf(ANSI_COLOR_MAGENTA"||======================================||\n");
					printf("||         SEKTOR AKSES LISTRIK         ||\n");
					printf("||======================================||\n\n"ANSI_COLOR_RESET);
                    aturListrik(energetica, i);
					break;
				case 2 :
					system("cls");
					printf(ANSI_COLOR_MAGENTA"||======================================||\n");
					printf("||    SEKTOR KEBERSIHAN RUMAH TANGGA    ||\n");
					printf("||======================================||\n\n"ANSI_COLOR_RESET);
					aturKebersihanRumahTangga(energetica, i);
					break;
				case 3 :
					system("cls");
					printf(ANSI_COLOR_MAGENTA"||======================================||\n");
					printf("||      SEKTOR AKSES ENERGI BERSIH      ||\n");
					printf("||======================================||\n\n"ANSI_COLOR_RESET);
					aturAksesEnergi(energetica, i);
					break;
				case 4 :
					system("cls");
					printf(ANSI_COLOR_MAGENTA"||======================================||\n");
					printf("||     SEKTOR EMISI GAS RUMAH KACA      ||\n");
					printf("||======================================||\n\n"ANSI_COLOR_RESET);
					aturEmisi(energetica, i);
					break;
				default : 
                    printf("Input anda tidak valid!\n\nPress any key to continue!");
                    continue;
				
			}
			
		}

		if(loseTrigger > 0) {
        	printf("Maaf anda gagal!\n");
        	printf("Press Any Button to Continue");
        	getch();
        	system("cls");
        	break;
		}
	
		printf("B E R H A S I L - L E V E L   %d || %s\n", i + 1, energetica[i].nama);
		
		getch();
		system("cls");
	}
}


int main() {
	
	kota *energetica;

	energetica = (struct kotaEnergetica *)malloc(4 * sizeof(struct kotaEnergetica));
	
	definisiListrik(energetica);
	definisiKebersihanRumahTangga (energetica);
	definisiEnergiBersih(energetica);
	definisiAturEmisi(energetica);
	definisiKota(energetica);
	
    printf(ANSI_COLOR_YELLOW " _       __________    __________  __  _________                   " ANSI_COLOR_BLUE "________\n" ANSI_COLOR_YELLOW);
    printf("| |     / / ____/ /   / ____/ __ \\/  |/  / ____/                  " ANSI_COLOR_BLUE "/////////\n" ANSI_COLOR_YELLOW);
    printf("| | /| / / __/ / /   / /   / / / / /|_/ / __/                    " ANSI_COLOR_BLUE "/////////\n" ANSI_COLOR_YELLOW);
	printf("| |/ |/ / /___/ /___/ /___/ /_/ / /  / / /___                   " ANSI_COLOR_BLUE "/////////\n" ANSI_COLOR_YELLOW);
	printf("|__/|__/_____/_____/\\____/\\____/_/  /_/_____/                  " ANSI_COLOR_BLUE "/////////___\n" ANSI_COLOR_YELLOW);

	printf("\t\t\t\t\t\t\t" "      "ANSI_COLOR_BLUE"/_____///////\n"ANSI_COLOR_YELLOW);

	printf("  __________                                                       " ANSI_COLOR_BLUE "///////\n" ANSI_COLOR_YELLOW);
	printf(" /_  __/ __ \\                                                     " ANSI_COLOR_BLUE "///////__\n" ANSI_COLOR_YELLOW);
	printf("  / / / / / /                                                    " ANSI_COLOR_BLUE "//////////\n" ANSI_COLOR_YELLOW);
	printf(" / / / /_/ /                                                    " ANSI_COLOR_BLUE "/____/////\n" ANSI_COLOR_YELLOW);
    printf("/_/  \\____/                                                         " ANSI_COLOR_BLUE "/////\n" ANSI_COLOR_YELLOW);

	printf("\t\t\t\t\t\t\t\t" "   "ANSI_COLOR_BLUE"/////\n");

	printf(ANSI_COLOR_GREEN"    ______"ANSI_COLOR_RESET"_   __"ANSI_COLOR_GREEN"______"ANSI_COLOR_RESET"____  ______"ANSI_COLOR_GREEN"______"ANSI_COLOR_RESET"___________________        "ANSI_COLOR_BLUE"////\n"ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN"   / ____/"ANSI_COLOR_RESET" | / "ANSI_COLOR_GREEN"/ ____/"ANSI_COLOR_RESET" __ \\/ ____"ANSI_COLOR_GREEN"/ ____/"ANSI_COLOR_RESET"_  __/  _/ ____/   |      "ANSI_COLOR_BLUE"////\n"ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN"  / __/ "ANSI_COLOR_RESET"/  |/ "ANSI_COLOR_GREEN"/ __/ "ANSI_COLOR_RESET"/ /_/ / / __"ANSI_COLOR_GREEN"/ __/   "ANSI_COLOR_RESET"/ /  / // /   / /| |      "ANSI_COLOR_BLUE"///\n"ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN" / /___"ANSI_COLOR_RESET"/ /|  "ANSI_COLOR_GREEN"/ /___"ANSI_COLOR_RESET"/ _, _/ /_/ "ANSI_COLOR_GREEN"/ /___  "ANSI_COLOR_RESET"/ / _/ // /___/ ___ |     "ANSI_COLOR_BLUE"///\n"ANSI_COLOR_RESET);
	printf(ANSI_COLOR_GREEN"/_____/"ANSI_COLOR_RESET"_/ |_"ANSI_COLOR_GREEN"/_____/"ANSI_COLOR_RESET"_/ |_|\\____"ANSI_COLOR_GREEN"/_____/"ANSI_COLOR_RESET" /_/ /___/\\____/_/  |_|     "ANSI_COLOR_BLUE"//\n"ANSI_COLOR_RESET);

	printf("\n\nPress any key to Continue!");
	getch();
	system("cls");

	int pil, loop = 1;

	while(loop == 1) {
		printf(ANSI_COLOR_GREEN"    ______"ANSI_COLOR_RESET"_   __"ANSI_COLOR_GREEN"______"ANSI_COLOR_RESET"____  ______"ANSI_COLOR_GREEN"______"ANSI_COLOR_RESET"___________________\n");
		printf(ANSI_COLOR_GREEN"   / ____/"ANSI_COLOR_RESET" | / "ANSI_COLOR_GREEN"/ ____/"ANSI_COLOR_RESET" __ \\/ ____"ANSI_COLOR_GREEN"/ ____/"ANSI_COLOR_RESET"_  __/  _/ ____/   |\n");
		printf(ANSI_COLOR_GREEN"  / __/ "ANSI_COLOR_RESET"/  |/ "ANSI_COLOR_GREEN"/ __/ "ANSI_COLOR_RESET"/ /_/ / / __"ANSI_COLOR_GREEN"/ __/   "ANSI_COLOR_RESET"/ /  / // /   / /| |\n");
		printf(ANSI_COLOR_GREEN" / /___"ANSI_COLOR_RESET"/ /|  "ANSI_COLOR_GREEN"/ /___"ANSI_COLOR_RESET"/ _, _/ /_/ "ANSI_COLOR_GREEN"/ /___  "ANSI_COLOR_RESET"/ / _/ // /___/ ___ |\n");
		printf(ANSI_COLOR_GREEN"/_____/"ANSI_COLOR_RESET"_/ |_"ANSI_COLOR_GREEN"/_____/"ANSI_COLOR_RESET"_/ |_|\\____"ANSI_COLOR_GREEN"/_____/"ANSI_COLOR_RESET" /_/ /___/\\____/_/  |_|\n");
		printf("\n");
		printf("                M   A   I   N       M   E   N   U      \n");
		printf(" " ANSI_COLOR_GREEN "========================================================================\n" ANSI_COLOR_RESET);
		printf("1.   P L A Y   T H E   G A M E\n");
		printf("2.   H O W   T O   P L A Y\n");
		printf("3.   I N F O R M A T I O N   A B O U T   S D G  7\n");
		printf("4.   E X I T   T H E   G A M E\n");
	
		printf("P I L I H A N  :  "); scanf("%d", &pil);
	
		switch(pil) {
    		case 1 :
				system("cls"); 
    			printf("S E L A M A T!\n");
    			printf("===================\n");
    			printf("Anda terpilih menjadi presiden dari negara" ANSI_COLOR_GREEN " ENERGETICA" ANSI_COLOR_RESET "!");
    			printf("\n\nPress any key to continue!");
    			getch();
			    system("cls");
    	
    			printf(ANSI_COLOR_GREEN "ENERGETICA" ANSI_COLOR_RESET " adalah negara yang kecil, namun memiliki potensi yang besar. Saat ini " ANSI_COLOR_GREEN "ENERGETICA" ANSI_COLOR_RESET" dalam rangka janji kampanye yang telah dibuat, kamu bertekad untuk membawa negara ini dan\n");
				printf("kota-kotanya untuk mencapai tujuan dari" ANSI_COLOR_CYAN " SDG 7 " ANSI_COLOR_RESET "yang memiliki indeks capaian tersebut. Majukanlah kota-kota Energetica untuk mencapai tujuan SDG 7 dan mencapai tujuan indeks kalian!");
    			printf("\n\nPress any key to continue!");
    			getch();
                system("cls");
    	
    			gameplay(energetica);
    		
    		    getch();
			    system("cls"); 
                break;
    		
    		case 2 : 
    			system("cls");
    			printf("C A R A   B E R M A I N\n");
    			printf("==============================\n");
    			printf("1. Anda akan diberikan suatu senario dimana anda harus memecahkan masalah pada kota\n\n");
				printf("2. Pada game ini terdapat 4 kota yang harus anda selesaikan masalahnya : Dea Tae-AE, Elegger City, Tekkompolis, dan Biotopia\n\n");
				printf("3. Tiap kota memiliki indeks pencapaian yang meliputi 4 aspek yaitu Akses Listrik, Kebersihan Rumah Tangga, Akses Energi Bersih, dan Pengurangan Emisi Gas Rumah Kaca\n\n");
				printf("4. Kita akan diberikan budget yang berbeda-beda setiap kota untuk memecahkan masalah-masalah ini, semua aspek yang mempengaruhi indeks harus harmonis dan saling balanced\n\n");
				printf("5. Jika Indeks tidak tercapai, batas hari sudah habis, atau budget melebihi batas maka anda gagal\n\n");
				printf("6. Jika Indeks tercapai dalam batas hari yang diinginkan maka anda lanjut ke level berikutnya sampai game selesai!\n\n");
				printf("\nPress any key to continue!");
				getch();
				system("cls"); 
				break;
    	
    		case 3 : 
				system("cls");
				printf(ANSI_COLOR_CYAN" ________  ________  ________                ________  \n");
    			printf("|\\   ____\\|\\   ___ \\|\\   ____\\              |\\_____  \\ \n");
    			printf("\\ \\  \\___|\\ \\  \\_|\\ \\ \\  \\___|               \\|___/  /|\n");
    			printf(" \\ \\_____  \\ \\  \\ \\\\ \\ \\  \\  ___                 /  / / \n");
    			printf("  \\|____|\\  \\ \\  \\_\\\\ \\ \\  \\|\\  \\               /  / /  \n");
    			printf("    ____\\_\\  \\ \\_______\\ \\_______\\             /__/ /   \n");
    			printf("   |\\_________\\|_______|\\|_______|             |__|/    \n");
   	 			printf("   \\|_________|                                        \n" ANSI_COLOR_RESET);

   				printf( ANSI_COLOR_WHITE"  ___  ____________ _________________  ___  ______ _      _____   _____ _   _ _____ _____ ___  _____ _   _   ___  ______ _      _____  ______ _____ _     _____  ___  ______ _      _____ \n");
    			printf(" / _ \\ |  ___|  ___|  _  | ___ \\  _  \\/ _ \\ | ___ \\ |    |  ___| /  ___| | | /  ___|_   _/ _ \\|_   _| \\ | | / _ \\ | ___ \\ |    |  ___| | ___ \\  ___| |   |_   _|/ _ \\ | ___ \\ |    |  ___|\n");
   				printf("/ /_\\ \\| |_  | |_  | | | | |_/ / | | / /_\\ \\| |_/ / |    | |__   \\ `--.| | | \\ `--.  | |/ /_\\ \\ | | |  \\| |/ /_\\ \\| |_/ / |    | |__   | |_/ / |__ | |     | | / /_\\ \\| |_/ / |    | |__  \n");
    			printf("|  _  ||  _| |  _| | | | |    /| | | |  _  || ___ \\ |    |  __|   `--. \\ | | |`--. \\ | ||  _  | | | | . ` ||  _  || ___ \\ |    |  __|  |    /|  __|| |     | | |  _  || ___ \\ |    |  __| \n");
    			printf("| | | || |   | |   \\ \\_/ / |\\ \\| |/ /| | | || |_/ / |____| |___  /\\__/ / |_| /\\__/ / | || | | |_| |_| |\\  || | | || |_/ / |____| |___  | |\\ \\| |___| |_____| |_| | | || |_/ / |____| |___ \n");
    			printf("\\_| |_/\\_|   \\_|    \\___/\\_| \\_|___/ \\_| |_/\\____/\\_____/\\____/  \\____/ \\___/\\____/  \\_/\\_| |_/\\___/\\_| \\_/\\_| |_/\\____/\\_____/\\____/  \\_| \\_\\____/\\_____/\\___/\\_| |_/\\____/\\_____/\\____/\n" ANSI_COLOR_WHITE);
	
   				printf(ANSI_COLOR_CYAN "\n========================================================================================================================================================================================\n"ANSI_COLOR_RESET);
   				printf("THE GOAL OF SDG 7 FROM THE UN IS TO ENSURE ACCESS TO AFFORDABLE, RELIABLE, SUSTAINABLE, AND MODERN ENERGY FOR ALL!\n");
   				printf("Renewable energy solutions are becoming cheaper, more reliable and more efficient every day.Our current reliance on fossil fuels is unsustainable and harmful to the planet, which is why\n");
				printf("we have to change the way we produce and consume energy. Implementing these new energy solutions as fast as possible is essential to counter climate change, one of the biggest threats\n");
				printf("to our own survival.\n");
   	 			printf("\nTHINGS TO DO!\n");
				printf("+Find a Goal 7 charity you want to support. Any donation, big or small, can make a difference!\n");
				printf("+Turn off your air conditioning, especially for sleeping - open a window or use a fan.\n");
				printf("+Don't use multiple devices at the same time. Be mindful about this and only several devices when absolutely necessary.\n");
				printf("+Switch off your appliances at the socket. Turn off the lights when you're not using them.\n");
				printf("+Buy rechargeable electronics. Don't buy or use one-use batteries.\n");
				printf("+Use solar energy sources. Install solar panels in your home for your heating and electricity. Use solar technology - radio, charger, lights etc.\n");
			
				printf("\nPress any key to go back to main menu");
				getch();
				system("cls"); 
				break;
    		
    		case 4 : 
    			system("cls");
				printf(ANSI_COLOR_GREEN "______________ ___    _____    _______   ____  __.    _____.___.________   ____ ___  ._.\n");
    			printf("\\__    ___/   |   \\  /  _  \\   \\      \\ |    |/ _|    \\__  |   |\\_____  \\ |    |   \\ | |\n");
    			printf("  |    | /    ~    \\/  /_\\  \\  /   |   \\|      <       /   |   | /   |   \\|    |   / | |\n");
    			printf("  |    | \\    Y    /    |    \\/    |    \\    |  \\      \\____   |/    |    \\    |  /   \\|\n");
   				printf("  |____|  \\___|_  /\\____|__  /\\____|__  /____|__ \\     / ______|\\_______  /______/    __\n");
    			printf("                \\/         \\/         \\/        \\/     \\/               \\/            \\/" ANSI_COLOR_RESET "\n");
    			loop = 0;
    			break;
    			
    		default : 
				system("cls");
				printf("T Y P E   A   V A L I D   N U M B E R !!\n\n");
				printf("Press any key to Continue");
				getch();
				system("cls");
				break;
		}
	}

	free(energetica);

    return 0;
}
