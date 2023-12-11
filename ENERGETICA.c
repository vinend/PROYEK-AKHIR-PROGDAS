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
	char desc[800];
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
		float indeksKebersihanRT;
	} kebersihanRumahTangga;
	
	struct aksesEnergiBersih {
		float kemudahanAkses;
		float kebersihan;
		float energiTerbarukan;
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
		int sdmGas;
		int levelMod;
		float indeksGasRumahKaca;
		int inc;
		
	} emisiGas;
	
} kota;

//CODE HAKIM

void definisiListrik(kota *energetica) { //fungsi definisi (inisialisasi tiap variabel yang terkait)
	
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
    float incPoin = -1, residu = 0, totalBiaya, totalSDM, usedBiaya, usedSDM; //incPoin diinisialisasi -1 supaya bisa mulai input dalam syarat while loop
    float biaya = 900000 + (500000 * i); // 900000 1400000 1900000 2400000 
	float sdmCost = floor(3 - (0.5 * i)); // 3 2 2 1

    printf("\nBiaya               : $ %.0f / poin", biaya);
	printf("\nSDM yang diperlukan : %.0f / poin", sdmCost);
    printf("\n\nMasukkan penambahan poin listrik bersubsidi: ");
    
    while (incPoin < 0) {
        scanf("%f", &incPoin);
        if (incPoin < 0) { //error handling jika input negatif
            printf(ANSI_COLOR_RED"Angka yang dimasukkan tidak valid, silahkan masukkan angka lagi\n"ANSI_COLOR_RESET);
        }
    }

	totalBiaya = biaya * incPoin;
	totalSDM = sdmCost * incPoin;

	energetica[i].aksesListrik.listrikSubsidi += incPoin;
	if (energetica[i].aksesListrik.listrikSubsidi > 100) { //handling jika poin melebihi seratus
		residu = energetica[i].aksesListrik.listrikSubsidi - 100;
		energetica[i].aksesListrik.listrikSubsidi = 100;
		incPoin = 100 - residu;
	}
	usedBiaya = totalBiaya - (residu * biaya); //biaya final
	usedSDM = totalSDM - (residu * sdmCost); //SDM final

	if (usedBiaya > energetica[i].budget || usedSDM > energetica[i].aksesListrik.sdmListrik) { //handling jika suplai (budget dan SDM) habis
		printf(ANSI_COLOR_RED"Budget/SDM Anda tidak memenuhi. Tidak ada yang berubah.\n"ANSI_COLOR_RESET);
		energetica[i].aksesListrik.listrikSubsidi -= incPoin; //poin kembali ke saat sebelum ditambah
		energetica[i].hari++; //hari tidak akan berubah
	} else {
		energetica[i].budget -=  usedBiaya;
		energetica[i].aksesListrik.sdmListrik -= usedSDM;
		printf("Poin overflow = %.0f\n", residu); //tampilan poin yang overflow
	}
}

void changeUmum(kota *energetica, float listrikUmum, int i) {
    float incPoin = -1, residu = 0, totalBiaya, totalSDM, usedBiaya, usedSDM; //incPoin diinisialisasi -1 supaya bisa mulai input dalam syarat while loop
    float biaya = 1500000 + (400000 * i); // 1500000 1900000 2300000 2700000
	float sdmCost = 1; // 1 1 1 1

    printf("\nBiaya               : $ %.0f / poin", biaya);
	printf("\nSDM yang diperlukan : %.0f / poin", sdmCost);
    printf("\n\nMasukkan penambahan poin listrik fasilitas umum: ");
    
    while (incPoin < 0) {
        scanf("%f", &incPoin);
        if (incPoin < 0) { //error handling jika input negatif
            printf(ANSI_COLOR_RED"Angka yang dimasukkan tidak valid, silahkan masukkan angka lagi\n"ANSI_COLOR_RESET);
        }
    }

	totalBiaya = biaya * incPoin;
	totalSDM = sdmCost * incPoin;

	energetica[i].aksesListrik.listrikUmum += incPoin;
	if (energetica[i].aksesListrik.listrikUmum > 100) { //handling jika poin melebihi seratus
		residu = energetica[i].aksesListrik.listrikUmum - 100;
		energetica[i].aksesListrik.listrikUmum = 100;
		incPoin = 100 - residu;
	}
	usedBiaya = totalBiaya - (residu * biaya); //biaya final
	usedSDM = totalSDM - (residu * sdmCost); //SDM final

	if (usedBiaya > energetica[i].budget || usedSDM > energetica[i].aksesListrik.sdmListrik) { //handling jika suplai (budget dan SDM) habis
		printf(ANSI_COLOR_RED"Budget/SDM Anda tidak memenuhi. Tidak ada yang berubah.\n"ANSI_COLOR_RESET);
		energetica[i].aksesListrik.listrikUmum -= incPoin; //poin kembali ke saat sebelum ditambah
		energetica[i].hari++; //hari tidak akan berubah
	} else {
		energetica[i].budget -=  usedBiaya;
		energetica[i].aksesListrik.sdmListrik -= usedSDM;
		printf("Poin overflow = %.0f\n", residu); //tampilan poin overflow
	}
}

void changeTerbaharukan(kota *energetica, float listrikTerbaharukan, int i) {
    float incPoin = -1, residu = 0, totalBiaya, totalSDM, usedBiaya, usedSDM; //incPoin diinisialisasi -1 supaya bisa mulai input dalam syarat while loop
    float biaya = 1000000; // 1000000 1000000 1000000 1000000
	float sdmCost = 2; // 2 2 2 2

    printf("\nBiaya               : $ %.0f / poin", biaya);
	printf("\nSDM yang diperlukan : %.0f / poin", sdmCost);
    printf("\n\nMasukkan penambahan poin akses listrik terbaharukan: ");
    
    while (incPoin < 0) {
        scanf("%f", &incPoin);
        if (incPoin < 0) { //error handling jika input negatif
            printf(ANSI_COLOR_RED"Angka yang dimasukkan tidak valid, silahkan masukkan angka lagi\n"ANSI_COLOR_RESET);
        }
    }

	totalBiaya = biaya * incPoin; //biaya final
	totalSDM = sdmCost * incPoin; //SDM final

	energetica[i].aksesListrik.listrikTerbaharukan += incPoin;
	if (energetica[i].aksesListrik.listrikTerbaharukan > 100) {
		residu = energetica[i].aksesListrik.listrikTerbaharukan - 100;
		energetica[i].aksesListrik.listrikTerbaharukan = 100;
		incPoin = 100 - residu;
	}
	usedBiaya = totalBiaya - (residu * biaya);
	usedSDM = totalSDM - (residu * sdmCost);

	if (usedBiaya > energetica[i].budget || usedSDM > energetica[i].aksesListrik.sdmListrik) {  //handling jika suplai (budget dan SDM) habi
		printf(ANSI_COLOR_RED"Budget/SDM Anda tidak memenuhi. Tidak ada yang berubah.\n"ANSI_COLOR_RESET);
		energetica[i].aksesListrik.listrikTerbaharukan -= incPoin; //poin kembali ke saat sebelum ditambah
		energetica[i].hari++; //hari tidak akan berubah
	} else {
		energetica[i].budget -=  usedBiaya;
		energetica[i].aksesListrik.sdmListrik -= usedSDM;
		printf("Poin overflow = %.0f\n", residu); //tampilan poin overflow
	}
}

void aturListrik(kota *energetica, int i) {
    int pil, hari;

	printf("||=============================================\n"); //Tabel statistik
    printf("|| Statistik Listrik\n");
    printf("||=============================================\n");
	printf("|| Status Listrik           : %.2f%%\n", energetica[i].aksesListrik.indeksListrik);
	printf("|| Poin Listrik Subsidi     : %.0f out of 100\n", energetica[i].aksesListrik.listrikSubsidi);
	printf("|| Poin Fasilitas Umum      : %.0f out of 100\n", energetica[i].aksesListrik.listrikUmum);
	printf("|| Poin Energi terbaharukan : %.0f out of 100\n", energetica[i].aksesListrik.listrikTerbaharukan);
	printf("||=============================================\n");

	printf("\nBudget Kota : $ %.2f\n", energetica[i].budget); //tampilan suplai
	printf("SDM Listrik : %.0f\n", energetica[i].aksesListrik.sdmListrik);

	printf("\n  O P S I  \n"); //tampilan opsi
	printf("============\n");
	printf("1. Menyediakan listrik bersubsidi\n");
	printf("2. Penambahan listrik untuk fasilitas umum\n");
	printf("3. Penyediaan listrik dari energi terbaharukan\n");

    printf("\nMasukkan OPSI: "); //input opsi
	scanf("%d",&pil);
	
	switch(pil) { //switch case pemanggilan tiap fungsi
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
			printf(ANSI_COLOR_RED"Input anda tidak valid. Tidak ada yang berubah.\n"ANSI_COLOR_RESET);
	}

	//pendefinisian kembali nilai indeks setelah value setiap variabel berubah
	energetica[i].aksesListrik.indeksListrik = (energetica[i].aksesListrik.listrikSubsidi + energetica[i].aksesListrik.listrikUmum + energetica[i].aksesListrik.listrikTerbaharukan) / 3;
	
	printf("\n||=============================================\n"); //tampilan statistik yang telah diupdate
    printf("|| Statistik Listrik (Updated)\n");
    printf("||=============================================\n");
	printf("|| Status Listrik           : %.2f%%\n", energetica[i].aksesListrik.indeksListrik);
	printf("|| Poin Listrik Subsidi     : %.0f out of 100\n", energetica[i].aksesListrik.listrikSubsidi);
	printf("|| Poin Fasilitas Umum      : %.0f out of 100\n", energetica[i].aksesListrik.listrikUmum);
	printf("|| Poin Energi terbaharukan : %.0f out of 100\n", energetica[i].aksesListrik.listrikTerbaharukan);
	printf("||=============================================\n\n");

	printf("\nBudget Kota : $ %.2f\n", energetica[i].budget); //tampilan suplai setelah diupdate
	printf("SDM Listrik : %.0f\n", energetica[i].aksesListrik.sdmListrik);

	energetica[i].hari--; //hari berkurang 1
	printf("\nPress any key to continue!");
	getch();
	system("cls");
}

//CODE ALVIN

void definisiKebersihanRumahTangga (kota *energetica) {
	int i;
	
	//Pendefinsian Nilai-Nilai Indeks lokal dari Indeks Kebersihan Rumah Tangga
	
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
    int confirm = 0;
	
	//Tampilan tentang pengaruh poin terhadap budget dan penambahan poin
    printf("Pengaruh Budget dan Poin\n");
    printf("=================================================================================\n");
    printf("|| Biaya Pengurusan Alat\t=\tPoin x 500000 $ (Biaya per Alat)\n");
    printf("|| Pengaruh Pada Index\t\t=\tAkan naik 1 per 4 poin\n");
    printf("=================================================================================\n");
	
	//Scan atau input data tentang berapa poin alat akan dipakai
    printf("\nMasukkan jumlah alat kebersihan yang dipakai: ");
    scanf("%f", &alatYangDipakai);

    biayaUrusAlat = 500000;

	//Perhitungan Total Biaya
    totalAlatDipakai = alatYangDipakai * biayaUrusAlat;
    totalBiaya = totalAlatDipakai;

	//Pemeriksaan apakah biaya melebihi budget tersedia
    if (totalBiaya > energetica[i].budget) {

	    //Pilihan untuk menghabiskan budget atau tidak
        printf("Budget anda tidak cukup!\n");
        printf("Apakah anda ingin  menggunakan seluruh budget dan merisikokan? [1 - YES] [0 - NO] : ");
        scanf("%d", &confirm);

	    //Menggunakan Seluruh Budget yang tersedia
        if (confirm == 1) {
            printf("Menggunakan seluruh budget yang tersedia.\n");

		//Perhitungan jumlah alat yang dapat diebli sesuai dengan budget yang tersedia
            float buyoutCost = energetica[i].budget / biayaUrusAlat;

		//Penambahan poin kebersihan rumah tangga sustainable
            energetica[i].kebersihanRumahTangga.alatKebersihanSustainable += buyoutCost * 0.25;
            energetica[i].budget = 0;  

		//Pemeriksaan apakah indeks kebersihan melebihi batas atau tidak
            if (energetica[i].kebersihanRumahTangga.alatKebersihanSustainable > 100) {
                printf("Indeks Melebihi Batas! Luar biasa\n");
                energetica[i].kebersihanRumahTangga.alatKebersihanSustainable = 100;
            }
        } else {
		//Ketika user menolak penggunaan seluruh budget yang tersedia
            printf("Kembali ke menu!\n");
            energetica[i].hari++;
        }
    } else {
        	//Penyimpanan pengurangan budget dan penambahan poin kebersihan sustainable
        energetica[i].budget -= totalBiaya;
        energetica[i].kebersihanRumahTangga.alatKebersihanSustainable += alatYangDipakai * 0.25;

	    //Pemeriksaan apakah indeks kebersihan melebihi batas atau tidak
        if (energetica[i].kebersihanRumahTangga.alatKebersihanSustainable > 100) {
            printf("Indeks Melebihi Batas! Luar biasa\n");
            energetica[i].kebersihanRumahTangga.alatKebersihanSustainable = 100;
        }
    }
}


void efisiensiEnergi(kota *energetica, int i) {
    float outputEnergi, kehilanganEnergi, totalKonsumsiEnergi, pengurusanEnergi;
    int confirm = 0;

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
        printf("Apakah anda ingin  menggunakan seluruh budget dan merisikokan? [1 - YES] [0 - NO] : ");
        scanf("%d", &confirm);
        
        if (confirm == 1) {
            printf("Menggunakan seluruh budget yang tersedia.\n");

            
            float buyoutCost = energetica[i].budget / 400000.0;
            
            
            energetica[i].kebersihanRumahTangga.efisiensiEnergi += buyoutCost;
            energetica[i].budget = 0;
            energetica[i].kebersihanRumahTangga.efisiensiEnergi += buyoutCost * 0.25;

            if (energetica[i].kebersihanRumahTangga.efisiensiEnergi > 100) {
                printf("Indeks melebihi batas! Luar biasa\n");
                energetica[i].kebersihanRumahTangga.efisiensiEnergi = 100;
            }
        } else {
            printf("Kembali ke menu!\n");
            energetica[i].hari++;
        }
    } else {
       
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
    int confirm = 0;

    printf("Pengaruh Budget dan Poin\n");
    printf("=================================================================================\n");
    printf("|| Budget yang terpakai\t=\tPoin x 1000000 $ (Biaya per waste dikumpulkan)\n");
    printf("|| Pengaruh Pada Index\t=\tAkan naik 1 per 4 Poin\n");
    printf("=================================================================================\n");

    printf("\nMasukkan jumlah waste yang dikumpulkan: ");
    scanf("%f", &pengumpulanWaste);

    hargaPembuanganWaste = pengumpulanWaste * 1000000;

    totalWaste = pengumpulanWaste;

   
    if (hargaPembuanganWaste > energetica[i].budget) {
        printf("Budget anda tidak cukup!\n");
        printf("Apakah anda ingin  menggunakan seluruh budget dan merisikokan? [1 - YES] [0 - NO] : ");
        scanf("%d", &confirm );
        
        if(confirm == 1) {
		
        	printf("Menggunakan seluruh budget yang tersedia.\n");

        
        	totalWaste = energetica[i].budget / 1000000;  
        	hargaPembuanganWaste = energetica[i].budget;
        	energetica[i].kebersihanRumahTangga.wasteManagement += totalWaste;
    		energetica[i].budget -= hargaPembuanganWaste;
    		energetica[i].kebersihanRumahTangga.wasteManagement += totalWaste * 0.25;
		}
		
		else {
			printf("Kembali ke menu!");
			energetica[i].hari++;
		}
    }
    
    else {
	
    energetica[i].kebersihanRumahTangga.wasteManagement += totalWaste;
    energetica[i].budget -= hargaPembuanganWaste;
    energetica[i].kebersihanRumahTangga.wasteManagement += totalWaste * 0.25;

    if (energetica[i].kebersihanRumahTangga.wasteManagement > 100) {
        printf("Indeks melebihi batas! Luar biasa\n");
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
void definisiEnergiBersih(kota *energetica)	//mendefinisikan nilai dari variable struct member dari masing-masing kota energiBersih
{
	//indeks energi bersih di kota Dea-Tae-AE = 65 
	//indeks energi bersih di kota Elegger = 40
	//indeks energi bersih di kota Tekkompolis = 40 
	//indeks energi bersih di kota Biotopia = 55
	
	energetica[0].energiBersih.energiTerbarukan = 70;
	energetica[0].energiBersih.kebersihan = 70;
	energetica[0].energiBersih.kemudahanAkses = 55;
	
	energetica[1].energiBersih.energiTerbarukan = 60; 
	energetica[1].energiBersih.kebersihan = 20;
	energetica[1].energiBersih.kemudahanAkses = 40; 
	
	energetica[2].energiBersih.energiTerbarukan = 35;
	energetica[2].energiBersih.kebersihan = 50;
	energetica[2].energiBersih.kemudahanAkses = 35;
	
	energetica[3].energiBersih.energiTerbarukan = 55;
	energetica[3].energiBersih.kebersihan = 80;
	energetica[3].energiBersih.kemudahanAkses = 30;
	
	//banyaknya sesuai dengan sdm di fungsi lain
	energetica[0].energiBersih.sdmAkses = 300;
	energetica[1].energiBersih.sdmAkses = 250;
	energetica[2].energiBersih.sdmAkses = 180;
	energetica[3].energiBersih.sdmAkses = 90;
}

void kemudahanAkses (kota *energetica, int i, int nilaiKemudahan, float budget, int hari, int sdm)
//fungsi menerima info kota, nilaiKemudahan, budget, hari, dan sdm dari masing-masing opsi
{
	if (energetica[i].budget>budget && energetica[i].hari>hari && energetica[i].energiBersih.sdmAkses>sdm)
	//sebagai error handling, jika budget, hari, ataupun sdm yang dimiliki user lebih banyak/sedikit
	//dibandingkan dengan biaya yang diperlukan untuk melakukan salah satu opsi
	//ini akan melanjutkan jika biaya mencukupi
	{
		if (energetica[i].energiBersih.kemudahanAkses + nilaiKemudahan <=100)
		//error handling jika nilai indeks dari salah satu variabel berniali >100
		//kode yang dieksekusi ini jika masih belum diatas 100
		{
			energetica[i].energiBersih.kemudahanAkses += nilaiKemudahan;
			//penambahan nilai variabel
		}
		else energetica[i].energiBersih.kemudahanAkses = 100;//jika nilai indeks melebihi 100, akan diset untuk tetap 100
		
		energetica[i].budget -= budget;	//pengurangan budget sesuai opsi
		energetica[i].hari -= hari;	//pengurangan budget sesuai opsi
		energetica[i].energiBersih.sdmAkses -= sdm;	//pengurangan sdm sesuai opsi
		printf("Sukses untuk melakukan perubahan\n");	//memberitahu user fungsi berhasil diimplementasikan
	}
	else printf("Salah satu biaya tidak memenuhi!");
	//jika tidak mencukupi maka penambahan akan diabaikan dan hanya menampilkan kesalahan
}

void kebersihan (kota *energetica, int i, int nilaiKebersihan, float budget, int hari, int sdm)
//fungsi menerima info kota, nilaiKebersihan, budget, hari, dan sdm dari masing-masing opsi
{
	if (energetica[i].budget>budget && energetica[i].hari>hari && energetica[i].energiBersih.sdmAkses>sdm)
	//sebagai error handling, jika budget, hari, ataupun sdm yang dimiliki user lebih banyak/sedikit
	//dibandingkan dengan biaya yang diperlukan untuk melakukan salah satu opsi
	//ini akan melanjutkan jika biaya mencukupi
	{
		if (energetica[i].energiBersih.kebersihan + nilaiKebersihan <=100)
		//error handling jika nilai indeks dari salah satu variabel berniali >100
		//kode yang dieksekusi ini jika masih belum diatas 100
		{
			energetica[i].energiBersih.kebersihan += nilaiKebersihan;
			//penambahan nilai variabel
		}
		else energetica[i].energiBersih.kebersihan = 100;	//diset menjadi 100 jika nilai variabel >100
		
		energetica[i].budget -= budget;	//pengurangan budget sesuai opsi
		energetica[i].hari -= hari;	//pengurangan budget sesuai opsi
		energetica[i].energiBersih.sdmAkses -= sdm;	//pengurangan sdm sesuai opsi
		printf("Sukses untuk melakukan perubahan\n");	//memberitahu user fungsi berhasil diimplementasikan
	}
	else printf("Salah satu biaya tidak memenuhi!");
	//jika tidak mencukupi maka penambahan akan diabaikan dan hanya menampilkan kesalahan
}

void penambahanEnergi (kota *energetica, int i, int nilaiPenambahan, float budget, int hari, int sdm)
//fungsi menerima info kota, nilaiKebersihan, budget, hari, dan sdm dari masing-masing opsi
{
	if (energetica[i].budget>budget && energetica[i].hari>hari && energetica[i].energiBersih.sdmAkses>sdm)
	//sebagai error handling, jika budget, hari, ataupun sdm yang dimiliki user lebih banyak/sedikit
	//dibandingkan dengan biaya yang diperlukan untuk melakukan salah satu opsi
	//ini akan melanjutkan jika biaya mencukupi
	{
		if (energetica[i].energiBersih.energiTerbarukan + nilaiPenambahan <=100)
		//error handling jika nilai indeks dari salah satu variabel berniali >100
		//kode yang dieksekusi ini jika masih belum diatas 100
		{
			energetica[i].energiBersih.energiTerbarukan += nilaiPenambahan;
			//penambahan nilai variabel
		}
		else energetica[i].energiBersih.energiTerbarukan = 100;	//diset menjadi 100 jika nilai variabel >100
		
		energetica[i].budget -= budget;	//pengurangan budget sesuai opsi
		energetica[i].hari -= hari;	//pengurangan budget sesuai opsi
		energetica[i].energiBersih.sdmAkses -= sdm;	//pengurangan sdm sesuai opsi
		printf("Sukses untuk melakukan perubahan\n");	//memberitahu user fungsi berhasil diimplementasikan
	}
	else printf("Salah satu biaya tidak memenuhi!");
	//jika tidak mencukupi maka penambahan akan diabaikan dan hanya menampilkan kesalahan
}

void displayAkses (kota *energetica, int i, int nilaiPenambahan, float budget, int hari, int sdm)
//menampilkan informasi mengenai biaya yang diperlukan untuk melaksanakan salah satu opsi
//dibuat fungsi karena pemakaian berulang
{
	printf("===============Status Perubahan==============\n");
	printf("||Nilai dari variabel yang bertambah %d\n", nilaiPenambahan);
	printf("||Budget yang dibutuhkan %.2f\n", budget);
	printf("||Hari yang dibutuhkan %d\n", hari);
	printf("||SDM yang dibutuhkan %d\n", sdm);
	printf("||Budget tersisa %.2f\n", energetica[i].budget - budget);
	printf("||Hari tersisa : %d hari\n", energetica[i].hari - hari);
	printf("=============================================\n");
	printf("Apakah Anda ingin melanjutkan pembangunan?\n");
	printf("1. Ya\n");
	printf("0. Tidak\n");
	//setelah kode ini, akan diminta konfirmasi dengan input dari user
}

void aturAksesEnergi(kota *energetica, int i)
{
	int opsi, confirm;	//opsi untuk case dari switch, confirm untuk melanjutkan/membatalkan eksekusi
	printf("================Status Indeks================\n");
	printf("||Kemudahan akses energi 	: %.2f / 100\n", energetica[i].energiBersih.kemudahanAkses);
	printf("||Kebersihan energi 		: %.2f / 100\n", energetica[i].energiBersih.kebersihan);
	printf("||Kuantitas energi terbarukan 	: %.2f / 100\n", energetica[i].energiBersih.energiTerbarukan);
	printf("||Kuantitas SDM Akses Energi 	: %.2f\n", energetica[i].energiBersih.sdmAkses);
	printf("=============================================\n");
	printf("\nApa yang ingin diubah pada Akses Energi Bersih?\n");
	printf("1. Pembangunan Pembangkit Listrik (Pasokan+++)\n");
	printf("2. Membuat kebijakan dan regulasi energi bersih (Kebersihan+)\n");
	printf("3. Memberikan edukasi kepada warga (Pasokan/Kebersihan+)\n");
	printf("4. Pembangunan infrasruktur yang lebih baik(Akses/Kebersihan+)\n");
	printf("5. Penyediaan akses energi untuk desa terpencil (Akses++)\n");
	printf("6. Pengembangan teknologi dan penelitian (Pasokan/Akses+)\n");
	printf("7. Pengalihan subsidi bahan bakar fosil menjadi energi terbarukan (Pasokan+)\n");
	printf("8. Menyerukan penggunaan transportasi umum (Akses+)\n");
	scanf("%d", &opsi);
	
	switch (opsi)
	{
		case 1:
			displayAkses (energetica, i, 30 , 20000000, 3, 50);
			scanf("%d",&confirm);
			if (confirm == 1) penambahanEnergi (energetica, i, 30 , 20000000, 3, 50);
			else printf("Gagal untuk melakukan perubahan\n");
			break;
		case 2 :
			displayAkses (energetica, i, 10 , 6000000, 3, 20);
			scanf("%d",&confirm);
			if (confirm == 1) kebersihan (energetica, i, 10 , 6000000, 3, 20);
			else printf("Gagal untuk melakukan perubahan\n");
			break;
		case 3 :
			displayAkses (energetica, i, 20 , 12000000, 4,20);	//terdiri dari 2 nilai fungsi yang dijumlah
			scanf("%d",&confirm);
			if (confirm == 1) 
			{
				kebersihan (energetica, i, 8 , 7000000, 2, 10);
				penambahanEnergi (energetica, i, 12 , 5000000, 2, 10);
			}
			else printf("Gagal untuk melakukan perubahan\n");
			break;
		case 4 :
			displayAkses (energetica, i, 25 , 14000000, 3,30);
			scanf("%d",&confirm);
			if (confirm == 1) 
			{
				kemudahanAkses (energetica, i, 10 , 4000000, 2, 10);
				kebersihan (energetica, i, 15 , 10000000, 1, 20);
			}
			else printf("Gagal untuk melakukan perubahan\n");
			break;
		case 5 :
			displayAkses (energetica, i, 30 , 21000000, 2, 40);
			scanf("%d",&confirm);
			if (confirm == 1)	kemudahanAkses (energetica, i, 30 , 21000000, 2,40);
			else printf("Gagal untuk melakukan perubahan\n");
			break;
		case 6 :
			displayAkses (energetica, i, 15 , 10000000, 2, 10);
			scanf("%d",&confirm);
			if (confirm == 1) 
			{
				penambahanEnergi (energetica, i, 9 , 6000000, 1, 5);
				kemudahanAkses (energetica, i, 6 , 4000000, 1,5);
			}
			else printf("Gagal untuk melakukan perubahan\n");
			break;
		case 7 :
			displayAkses (energetica, i, 5 , 3500000, 1, 2);
			scanf("%d",&confirm);
			if (confirm == 1) penambahanEnergi (energetica, i, 5 , 3500000, 1, 2);
			else printf("Gagal untuk melakukan perubahan\n");
			break;
		case 8 :
			displayAkses (energetica, i, 10 , 6000000, 2,7);
			scanf("%d",&confirm);
			if (confirm == 1) kemudahanAkses (energetica, i, 10 , 6000000, 2,7);
			else printf("Gagal untuk melakukan perubahan\n");
			break;
		default :
			printf("Input tidak valid. Tidak terjadi perubahan!");
	}
	energetica[i].energiBersih.indeksAksesEnergi = (energetica[i].energiBersih.energiTerbarukan + energetica[i].energiBersih.kebersihan + energetica[i].energiBersih.kemudahanAkses) / 3;
	//untuk merefresh nilai dari indeksAksesEnergi setelah dilakukannya penambahan nilai
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
	energetica[2].emisiGas.gasCH4 = 55;
	energetica[3].emisiGas.gasCH4 = 70;
	
	energetica[0].emisiGas.gasN2O = 50;
	energetica[1].emisiGas.gasN2O = 55;
	energetica[2].emisiGas.gasN2O = 60;
	energetica[3].emisiGas.gasN2O = 60;
	
	energetica[0].emisiGas.sdmGas = 300;
	energetica[1].emisiGas.sdmGas = 260;
	energetica[2].emisiGas.sdmGas = 240;
	energetica[3].emisiGas.sdmGas = 200;
	
	energetica[0].emisiGas.levelMod = 2;
	energetica[1].emisiGas.levelMod = 2;
	energetica[2].emisiGas.levelMod = 3;
	energetica[3].emisiGas.levelMod = 3;
}

void changeCO2(kota *energetica, float gasCO2, int i) {
	float inc;
	printf("Masukkan kenaikan skor CO2 yang diinginkan: ");
	scanf("%f", &inc);
	
	if(inc > 0 ) {
		if(inc > (100.00 - energetica[i].emisiGas.gasCO2)){
			inc = (100.00 - energetica[i].emisiGas.gasCO2);
			printf("\nPerubahan melebihi batas skor, menyesuaikan nilai...\n");
			getch();
		}
		if(energetica[i].emisiGas.sdmGas < inc * energetica[i].emisiGas.levelMod){
			inc = energetica[i].emisiGas.sdmGas / energetica[i].emisiGas.levelMod;
			printf("\nSDM tidak cukup untuk perubahan yang diinginkan, menyesuaikan nilai...\n");
			getch();
		}
		energetica[i].emisiGas.gasCO2 += inc;
		energetica[i].budget -= inc * energetica[i].emisiGas.priceCO2;
		energetica[i].emisiGas.sdmGas -= inc * energetica[i].emisiGas.levelMod;
		if(energetica[i].emisiGas.indeksGasRumahKaca > 100.00) {
			energetica[i].emisiGas.indeksGasRumahKaca = 100.00;
		}
		printf("\nBerhasil menaikan skor CO2\n");
		energetica[i].emisiGas.priceCO2 = energetica[i].emisiGas.priceCO2 + (energetica[i].emisiGas.priceCO2 * 0.5);
	} else if (energetica[i].emisiGas.gasCO2 == 100) {
		printf("Skor sudah maksimal!");
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
			printf("\nPerubahan melebihi batas skor, menyesuaikan nilai...\n");
			getch();
		}
		if(energetica[i].emisiGas.sdmGas < inc * energetica[i].emisiGas.levelMod){
			inc = energetica[i].emisiGas.sdmGas / energetica[i].emisiGas.levelMod;
			printf("\nSDM tidak cukup untuk perubahan yang diinginkan, menyesuaikan nilai...\n");
			getch();
		}
		energetica[i].emisiGas.gasCH4 += inc;
		energetica[i].budget -= inc * energetica[i].emisiGas.priceCH4;
		energetica[i].emisiGas.sdmGas -= inc * energetica[i].emisiGas.levelMod;
		if(energetica[i].emisiGas.indeksGasRumahKaca > 100.00) {
			energetica[i].emisiGas.indeksGasRumahKaca = 100.00;
		}
		printf("\nBerhasil menaikan skor CH4\n");
		energetica[i].emisiGas.priceCH4 = energetica[i].emisiGas.priceCH4 + (energetica[i].emisiGas.priceCH4 * 0.5);
	} else if (energetica[i].emisiGas.gasCH4 == 100) {
		printf("Skor sudah maksimal!");
	} else {
		printf("Tidak ada yang berubah!");
	}
}

void changeN2O(kota *energetica, float gasN2O, int i) {
	float inc;
	printf("Masukkan kenaikan skor N2O yang diinginkan: ");
	scanf("%f", &inc);
	
	if(inc > 0 ) {
		if(inc > (100.00 - energetica[i].emisiGas.gasN2O)){
			inc = (100.00 - energetica[i].emisiGas.gasN2O);
			printf("\nPerubahan melebihi batas skor, menyesuaikan nilai...\n");
			getch();
		}
		if(energetica[i].emisiGas.sdmGas < inc * energetica[i].emisiGas.levelMod){
			inc = energetica[i].emisiGas.sdmGas / energetica[i].emisiGas.levelMod;
			printf("\nSDM tidak cukup untuk perubahan yang diinginkan, menyesuaikan nilai...\n");
			getch();
		}
		energetica[i].emisiGas.gasN2O += inc;
		energetica[i].budget -= inc * energetica[i].emisiGas.priceN2O;
		energetica[i].emisiGas.sdmGas -= inc * energetica[i].emisiGas.levelMod;
		if(energetica[i].emisiGas.indeksGasRumahKaca > 100.00) {
			energetica[i].emisiGas.indeksGasRumahKaca = 100.00;
		}
		printf("\nBerhasil menaikan skor N2O\n");
		energetica[i].emisiGas.priceN2O = energetica[i].emisiGas.priceN2O + (energetica[i].emisiGas.priceN2O * 0.15);
	} else if (energetica[i].emisiGas.gasN2O == 100) {
		printf("Skor sudah maksimal!");
	} else {
		printf("Tidak ada yang berubah!");
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
			printf("\nSDM : %d/poin\n", energetica[i].emisiGas.levelMod);
			if(energetica[i].budget < energetica[i].emisiGas.priceCO2 || energetica[i].emisiGas.sdmGas < energetica[i].emisiGas.levelMod){
				printf("Budget/SDM tidak cukup!\n");
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
			printf("\nSDM : %d/poin\n", energetica[i].emisiGas.levelMod);
			if(energetica[i].budget < energetica[i].emisiGas.priceCH4 || energetica[i].emisiGas.sdmGas < energetica[i].emisiGas.levelMod){
				printf("Budget/SDM tidak cukup!\n");
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
			printf("\nSDM : %d/poin\n", energetica[i].emisiGas.levelMod);
			if(energetica[i].budget < energetica[i].emisiGas.priceN2O || energetica[i].emisiGas.sdmGas < energetica[i].emisiGas.levelMod){
				printf("Budget/SDM tidak cukup!\n");
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

void definisiKota(kota *energetica, char *username) {
	
	//indeks dte = 55
	//indeks elegger = 55
	//indeks tekkompolis = 48,75
	//indeks biotopia = 43,
	
	definisiListrik(energetica);
	definisiEnergiBersih(energetica);
	definisiKebersihanRumahTangga(energetica);
	definisiAturEmisi(energetica);
	
    strcpy(energetica[0].nama, "Dea-Tae-AE");
    strcpy(energetica[1].nama, "Elegger City");
    strcpy(energetica[2].nama, "Tekkompolis");
    strcpy(energetica[3].nama, "Biotopia");
    
    sprintf(energetica[0].desc, "Selamat datang di Dea-Tae-AE, di mana kemajuan energi bersih bertabrakan dengan realitas sehari-hari rumah tangga yang memerlukan sentuhan kebersihan yang lebih tajam. Bagaimana kota ini bisa menjadi model holistik untuk keberlanjutan? Itu adalah pertanyaan yang menggantung di udara, sementara penduduk Dea-Tae-AE terus menjelajahi keseimbangan antara teknologi tinggi dan kebutuhan dasar domestik. Sebagai pemimpin negara " ANSI_COLOR_GREEN "ENERGETICA" ANSI_COLOR_RESET ", " ANSI_COLOR_MAGENTA "%s" ANSI_COLOR_RESET ", memilih kota ini sebagai kota yang akan dibenahi pertama.", username);
    sprintf(energetica[1].desc, "Selamat datang di Elegger City! Kota yang terang benderang oleh ledakan kreativitas para inovator muda teknik elektro. Dengan akses listrik yang mengalir melalui jalanan dan bangunan-bangunan yang canggih, kota ini benar-benar menjadi laboratorium kehidupan bagi anak-anak teknik elektro yang berbakat. Namun dibalik keramaian teknologi yang memukau, tersembunyi ketidakseimbangan terhadap pengurangan emisi gas rumah kaca yang menjadi bagian yang terpinggirkan! Setelah keberhasilan di kota Dea-Tae-AE, Anda, "ANSI_COLOR_MAGENTA"%s"ANSI_COLOR_RESET", melanjutkan untuk menyelesaikan permasalahan emisi gas rumah kaca di Elegger City.", username);
    sprintf(energetica[2].desc, "Selamat datang di Tekkompolis! Meski jendela-jendela ruang server bersinar terang, lantai-lantai apartemen masih menyimpan tantangan kebersihan yang menghadang. Dalam dunia Tekkompolis, di mana kode-kode dan algoritma berkembang pesat, kenyataannya adalah bahwa keseimbangan antara teknologi dan kebersihan rumah tangga belum sepenuhnya tercapai. Apakah para pemikir muda di Tekkompolis dapat meretas solusi untuk membangun masa depan yang bersih dan berkelanjutan? Pertanyaan ini menciptakan ketegangan menarik antara kemajuan teknologi dan tanggung jawab lingkungan di kota ini. Tak hanya diam begitu saja. Anda, "ANSI_COLOR_MAGENTA"%s"ANSI_COLOR_RESET", ikut serta untuk membangun Tekkompolis menjadi kota yang bersih dan berkelanjutan.", username);
    strcpy(energetica[3].desc, "Selamat datang di Biotopia, kota yang dibanjiri oleh kecerdasan anak-anak muda yang menggali potensi luar biasa di bidang teknik biomedik dan teknologi kesehatan. Di kota ini, laboratorium-laboratorium inovatif dan pusat riset medis menjadi pusat kegiatan, dengan anak-anak cerdas ini membentuk masa depan kesehatan global. Meskipun kebersihan rumah tangga mencapai tingkat unggul, Biotopia berada di persimpangan tantangan yang menarik: akses listrik yang terbatas, pengurangan emisi gas rumah kaca yang kurang memadai, dan akses energi bersih yang masih terkendala. Biotopia akan menjadi kota terakhir yang akan Anda sebagai Kepala Negara benahi, pastikan untuk mengambil langkah yang benar! Karena resourcement yang semakin sedikit.");
    
    energetica[0].budget = 250000000;
    energetica[1].budget = 200000000;
    energetica[2].budget = 250000000;
    energetica[3].budget = 300000000;

	energetica[0].hari = 30;
	energetica[1].hari = 25;
	energetica[2].hari = 25;
	energetica[3].hari = 25;	
}

void gameplay(kota *energetica, char *username) {
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
        	printf("Maaf anda "ANSI_COLOR_RED"gagal"ANSI_COLOR_RESET"!\n");
        	printf("Press Any Button to Continue");
        	getch();
        	system("cls");
        	break;
		}
	
		printf("B E R H A S I L - L E V E L   %d || %s\n", i + 1, energetica[i].nama);
		
		if (i==3)
		{
			printf("Selamat kepada "ANSI_COLOR_MAGENTA"%s"ANSI_COLOR_RESET" karena telah menyelesaikan semua level di game "ANSI_COLOR_GREEN"ENERGETICA"ANSI_COLOR_RESET" dan telah "ANSI_COLOR_CYAN"BERHASIL"ANSI_COLOR_RESET" dalam membawa negara "ANSI_COLOR_GREEN"ENERGETICA"ANSI_COLOR_RESET" mencapai target SDG 7.", username);
		}
		
		getch();
		system("cls");
	}
}


int main() {
	
	kota *energetica;
	energetica = (struct kotaEnergetica *)malloc(4 * sizeof(struct kotaEnergetica));
	if (energetica == NULL) 
	{
        printf("Alokasi memori gagal.\n");
        return 1;
    }
	
	char *username;
	username = (char *)malloc(50 * sizeof(char));
    if (username == NULL) 
	{
        printf("Alokasi memori gagal.\n");
        return 1;
    }
	
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

	printf("Sebelum Anda bermain, mohon masukkan username : ");
	if (scanf(" %[^\n]", username) != 1) 
	{
        printf("Gagal membaca input.\n");
        return 1;
    }
    
	printf("\nSelamat bermain"ANSI_COLOR_MAGENTA" %s"ANSI_COLOR_RESET, username);
	printf("\n\nPress any key to Continue!");
	getch();
	system("cls");
	
	definisiKota(energetica, username);
	
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
    			printf("  S E L A M A T!  \n");
    			printf("==================\n");
    			printf("Anda, "ANSI_COLOR_MAGENTA"%s"ANSI_COLOR_RESET", terpilih menjadi presiden dari negara" ANSI_COLOR_GREEN " ENERGETICA" ANSI_COLOR_RESET "!", username);
    			printf("\n\nPress any key to continue!");
    			getch();
			    system("cls");
    	
    			printf(ANSI_COLOR_GREEN "ENERGETICA" ANSI_COLOR_RESET " adalah negara yang kecil, namun memiliki potensi yang besar. Saat ini " ANSI_COLOR_GREEN "ENERGETICA" ANSI_COLOR_RESET" dalam rangka janji kampanye yang telah dibuat, kamu bertekad untuk membawa negara ini dan\n");
				printf("kota-kotanya untuk mencapai tujuan dari" ANSI_COLOR_CYAN " SDG 7 " ANSI_COLOR_RESET "yang memiliki indeks capaian tersebut. Majukanlah kota-kota Energetica untuk mencapai tujuan SDG 7 dan mencapai tujuan indeks kalian!");
    			printf("\n\nPress any key to continue!");
    			getch();
                system("cls");
    	
    			gameplay(energetica, username);
    		
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
	
	free(username);
	free(energetica);

    return 0;
}
