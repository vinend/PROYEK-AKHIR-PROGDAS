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
        float listrikTerbaharui;
        float maxValue;
        float skalaHistogram;
        float indeksListrik;
		
	} listrik;
	
	struct kebersihanRumahTangga {
		float efisiensiEnergi;
		float wasteManagement;
		float alatKebersihanSustainable;
		float skalaHistogram;
		float indeksKebersihanRT;
	}kebersihanRumahTangga;
	
	struct aksesEnergiBersih {
		float kemudahanAkses;
		float kebersihan;
		float energiTerbarukan;
		float maxValue;
        float skalaHistogram;
        float indeksAksesEnergi;
	}energiBersih;
	
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
		float indeksGasRumahKaca;
		int inc;
		
	} emisiGas;
	
} kota;

//CODE KIMUSU
//Sekarang baru bisa buat akses listrik bersubsidi
//Error handling belum gitu jelas
//Kriteria masih harus diperhitungkan lagi

void definisiListrik(kota *energetica) {

        energetica[0].listrik.listrikSubsidi = 0;
        energetica[1].listrik.listrikSubsidi = 0;
        energetica[2].listrik.listrikSubsidi = 0;
        energetica[3].listrik.listrikSubsidi = 0;

        energetica[0].listrik.listrikUmum = 0;
        energetica[1].listrik.listrikUmum = 0;
        energetica[2].listrik.listrikUmum = 0;
        energetica[3].listrik.listrikUmum = 0;

        energetica[0].listrik.listrikTerbaharui = 0;
        energetica[1].listrik.listrikTerbaharui = 0;
        energetica[2].listrik.listrikTerbaharui = 0;
        energetica[3].listrik.listrikTerbaharui = 0;
}

void changeSubsidi(kota *energetica, float listrikSubsidi, int i) {
    float inc = 0;
    float biaya = 1500000 * (i+1);
    float incIndeks = 0.1 * (i+1);

    printf("\nBiaya : %.0f / poin", biaya);
    printf("\n      : %.1f%% / poin", incIndeks);
    printf("\n\nMasukkan penambahan akses listrik bersubsidi: ");
    
    while (inc <= 0) {
        scanf("%f", &inc);
        if (inc <= 0) {
            printf("Masukkan angka yang valid!\n");
        }
    }
        energetica[i].listrik.listrikSubsidi += inc;
        energetica[i].indeksKota += incIndeks * inc;
        energetica[i].budget -= biaya * inc;
        energetica[i].hari -= 1;
}

void aturListrik(kota *energetica, int i) {
    int pil, hari;
	float budget = 100000000;

	printf("\nO P S I\n");
	printf("========================\n");
	printf("1. Menyediakan listrik bersubsidi\n");
	printf("2. Penambahan listrik untuk fasilitas umum\n");
	printf("3. Penyediaan listrik dari energi terbaharukan\n");

    printf("\nMasukkan OPSI: "); 
	scanf("%d",&pil);
	
	switch(pil) {
		case 1 : 
			changeSubsidi(energetica,energetica[i].listrik.listrikSubsidi, i);
			system("cls");	
			break;
		case 2 : 
			break;
		case 3 : 
			break;
		default : 
			printf("Input anda tidak valid!\n\nPress any key to continue!");
			getch();
			system("cls");	
	}
}


//CODE MEERDJAH

void definisiAturEmisi(kota *energetica){
	 energetica[0].emisiGas.priceCO2 = 20000.00;
 	 energetica[1].emisiGas.priceCO2 = 25000.00;
	 energetica[2].emisiGas.priceCO2 = 30000.00;
	 energetica[3].emisiGas.priceCO2 = 35000.00;

	 energetica[0].emisiGas.priceCH4 = 20000.00;
 	 energetica[1].emisiGas.priceCH4 = 25000.00;
	 energetica[2].emisiGas.priceCH4 = 30000.00;
	 energetica[3].emisiGas.priceCH4 = 35000.00;

	 energetica[0].emisiGas.priceN2O = 20000.00;
 	 energetica[1].emisiGas.priceN2O = 25000.00;
	 energetica[2].emisiGas.priceN2O = 30000.00;
	 energetica[3].emisiGas.priceN2O = 35000.00;
	 
	 energetica[0].emisiGas.gasCO2 = 20;
 	 energetica[1].emisiGas.gasCO2 = 30;
	 energetica[2].emisiGas.gasCO2 = 25;
	 energetica[3].emisiGas.gasCO2 = 20;

	 energetica[0].emisiGas.gasCH4 = 25;
 	 energetica[1].emisiGas.gasCH4 = 30;
	 energetica[2].emisiGas.gasCH4 = 20;
	 energetica[3].emisiGas.gasCH4 = 25;

	 energetica[0].emisiGas.gasN2O = 30;
 	 energetica[1].emisiGas.gasN2O = 25;
	 energetica[2].emisiGas.gasN2O = 25;
	 energetica[3].emisiGas.gasN2O = 35;
	 
	 energetica[0].emisiGas.indeksGasRumahKaca = 35;
	 energetica[1].emisiGas.indeksGasRumahKaca = 50;
	 energetica[2].emisiGas.indeksGasRumahKaca = 20;
	 energetica[3].emisiGas.indeksGasRumahKaca = 25;
	 
	 energetica[0].emisiGas.levelMod = 0.25;
	 energetica[1].emisiGas.levelMod = 0.10;
	 energetica[2].emisiGas.levelMod = 0.25;
	 energetica[3].emisiGas.levelMod = 0.10;
}

void changeCO2(kota *energetica, float gasCO2, int i) {
	float inc;
	printf("Masukkan penurunan CO2 yang diinginkan: ");
	scanf("%f", &inc);
	
	if(inc > 0 ) {
		energetica[i].emisiGas.gasCO2 -= inc;
		energetica[i].emisiGas.indeksGasRumahKaca += inc * energetica[i].emisiGas.levelMod;
		if(energetica[i].emisiGas.indeksGasRumahKaca > 100.00) {
			energetica[i].emisiGas.indeksGasRumahKaca = 100.00;
		}
		printf("Berhasil menurunkan CO2\n");
		energetica[i].emisiGas.priceCO2 = energetica[i].emisiGas.priceCO2 + (energetica[i].emisiGas.priceCO2 * 0.5);
	} else {
		printf("TIdak ada yang berubah!");
	}
}

void changeCH4(kota *energetica, float gasCH4, int i) {
	float inc;
	printf("Masukkan penurunan CH4 yang diinginkan: ");
	scanf("%f", &inc);
	
	if(inc > 0 ) {
		energetica[i].emisiGas.gasCO2 -= inc;
		energetica[i].emisiGas.indeksGasRumahKaca += inc * energetica[i].emisiGas.levelMod;
		if(energetica[i].emisiGas.indeksGasRumahKaca > 100.00) {
			energetica[i].emisiGas.indeksGasRumahKaca = 100.00;
		}
		printf("Berhasil menurunkan CH4\n");
		energetica[i].emisiGas.priceCH4 = energetica[i].emisiGas.priceCH4 + (energetica[i].emisiGas.priceCH4 * 0.5);
	} else {
		printf("TIdak ada yang berubah!");
	}
}

void changeN2O(kota *energetica, float gasN2O, int i) {
	float inc;
	printf("Masukkan penurunan N2O yang diinginkan: ");
	scanf("%f", &inc);
	
	if(inc > 0 ) {
		energetica[i].emisiGas.gasCO2 -= inc;
		energetica[i].emisiGas.indeksGasRumahKaca += inc * energetica[i].emisiGas.levelMod;
		if(energetica[i].emisiGas.indeksGasRumahKaca > 100.00) {
			energetica[i].emisiGas.indeksGasRumahKaca = 100.00;
		}
		printf("Berhasil menurunkan N2O\n");
		energetica[i].emisiGas.priceN2O = energetica[i].emisiGas.priceN2O + (energetica[i].emisiGas.priceN2O * 0.15);
	} else {
		printf("TIdak ada yang berubah!");
	}
}

void aturEmisi(kota *energetica, int i) {
	int pil, hari;
	
	printf("\n\nO P S I\n");
	printf("========================\n");
	printf("1. Gas CO2\n");
	printf("2. Gas CH4\n");
	printf("3. Gas N20\n");
	scanf("%d",&pil);
	
	switch(pil) {
		case 1 : 
			if(energetica[i].budget < energetica[i].emisiGas.priceCO2){
				printf("Budget tidak cukup!\n");
				break;
			} else {
				changeCO2(energetica,energetica[i].emisiGas.gasCO2, i);
				break;
			}
		case 2 : 
			if(energetica[i].budget < energetica[i].emisiGas.priceCH4){
				printf("Budget tidak cukup!\n");
				break;
			} else {
				changeCH4(energetica,energetica[i].emisiGas.gasCH4, i);
				break;
			}
		case 3 : 
			if(energetica[i].budget < energetica[i].emisiGas.priceN2O){
				printf("Budget tidak cukup!\n");
				break;
			} else {
				changeN2O(energetica,energetica[i].emisiGas.gasN2O, i);
				break;
			}
		default : 
			printf("Masukkan Variabel Yang Valid!");
			getch();
			system("cls");	
	}
	
}

//CODE ALVIN
void definisiKebersihanRumahTangga (kota *energetica) {
	int i;
	
	energetica[0].kebersihanRumahTangga.alatKebersihanSustainable = 40;
	energetica[1].kebersihanRumahTangga.alatKebersihanSustainable = 65;
	energetica[2].kebersihanRumahTangga.alatKebersihanSustainable = 45;
	energetica[3].kebersihanRumahTangga.alatKebersihanSustainable = 50;
	
	energetica[0].kebersihanRumahTangga.efisiensiEnergi = 40;
	energetica[1].kebersihanRumahTangga.efisiensiEnergi = 65;
	energetica[2].kebersihanRumahTangga.efisiensiEnergi = 45;
	energetica[3].kebersihanRumahTangga.efisiensiEnergi = 50;
	
	energetica[0].kebersihanRumahTangga.wasteManagement = 40;
	energetica[1].kebersihanRumahTangga.wasteManagement = 65;
	energetica[2].kebersihanRumahTangga.wasteManagement = 45;
	energetica[3].kebersihanRumahTangga.wasteManagement = 50;
	
	for (i=0;i<4;i++)
	{
		energetica[i].kebersihanRumahTangga.indeksKebersihanRT += (energetica[i].kebersihanRumahTangga.alatKebersihanSustainable * 0.33) + (energetica[i].kebersihanRumahTangga.efisiensiEnergi * 0.33) + (energetica[i].kebersihanRumahTangga.wasteManagement * 0.33);
	}
}


void alatKebersihan(kota *energetica, int i) {
    float alatYangDipakai, biayaUrusAlat, totalAlatDipakai, totalBiaya;

    printf("\nMasukkan jumlah alat kebersihan yang dipakai: ");
    scanf("%f", &alatYangDipakai);

  
    biayaUrusAlat = 50000;  

    totalAlatDipakai = alatYangDipakai * biayaUrusAlat;
    totalBiaya = totalAlatDipakai; 
    
    if(totalBiaya > energetica[i].budget) {
    	printf("Maaf Biaya Anda Tidak Memenuhi");
	}

    else {
	
    energetica[i].kebersihanRumahTangga.alatKebersihanSustainable += alatYangDipakai;
    energetica[i].budget -= totalBiaya;
	}
	
}


void efisiensiEnergi(kota *energetica, int i) {
    float outputEnergi, kehilanganEnergi, totalKonsumsiEnergi, pengurusanEnergi;

    printf("\nMasukkan output energi rumah tangga: ");
    scanf("%f", &outputEnergi);

    
    kehilanganEnergi = outputEnergi * 0.1;  

    totalKonsumsiEnergi = outputEnergi + kehilanganEnergi;
    pengurusanEnergi = totalKonsumsiEnergi * 0.05;
	
	 if(pengurusanEnergi > energetica[i].budget) {
    	printf("Maaf Biaya Anda Tidak Memenuhi");
	}  

    else {
	
    energetica[i].kebersihanRumahTangga.efisiensiEnergi = outputEnergi - pengurusanEnergi;
    energetica[i].budget -= pengurusanEnergi;
	}
	
}


void manajemenWaste(kota *energetica, int i) {
    float pengumpulanWaste, totalWaste, hargaPembuanganWaste;

    printf("\nMasukkan jumlah waste yang dikumpulkan: ");
    scanf("%f", &pengumpulanWaste);

    
    hargaPembuanganWaste = pengumpulanWaste * 10000;  

    totalWaste = pengumpulanWaste + hargaPembuanganWaste;
    
    if(hargaPembuanganWaste > energetica[i].budget) {
    	printf("Maaf Biaya Anda Tidak Memenuhi");
	}
	
	else{
	
    energetica[i].kebersihanRumahTangga.wasteManagement += totalWaste;
    energetica[i].budget -= hargaPembuanganWaste;
	}
}

void aturKebersihanRumahTangga(kota *energetica, int i) {
	int pil;
	
	printf("O P S I\n");
	printf("==============\n");
	printf("1. Penggunaan Alat Kebersihan Rumah Tangga\n");
	printf("2. Keefisienan Penggunaan Energi Rumah Tangga\n");
	printf("3. Manajemen Waste\n");
	scanf("%d", &pil);
	
	switch(pil) {
		case 1 : 
			alatKebersihan(energetica, energetica[i].kebersihanRumahTangga.alatKebersihanSustainable); printf("\nPress Any Button to Continue"); getch(); system("cls"); break;
			
		case 2 : 
			efisiensiEnergi(energetica, energetica[i].kebersihanRumahTangga.efisiensiEnergi); printf("\nPress Any Button to Continue"); getch(); system("cls"); break;
			
		case 3 : 
			manajemenWaste(energetica, energetica[i].kebersihanRumahTangga.wasteManagement); printf("\nPress Any Button to Continue"); getch(); system("cls"); break;
			
		default : 
			printf("Tolong masukkan input yang valid!\n"); printf("Press Any Button to Continue"); getch(); system("cls");
			aturKebersihanRumahTangga(energetica,  i);
		
	}
	
	energetica[i].kebersihanRumahTangga.indeksKebersihanRT = (energetica[i].kebersihanRumahTangga.alatKebersihanSustainable * 0.33) + (energetica[i].kebersihanRumahTangga.efisiensiEnergi * 0.33) + (energetica[i].kebersihanRumahTangga.wasteManagement * 0.33); 
	
	if(energetica[i].kebersihanRumahTangga.indeksKebersihanRT > 100) {
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
	int i;
	for (i=0;i<4;i++)
	{
		energetica[i].energiBersih.kemudahanAkses = 0;
		energetica[i].energiBersih.kebersihan = 0;
		energetica[i].energiBersih.energiTerbarukan = 0;
	}
}

void kemudahanAkses (kota *energetica, int i, int nilaiKemudahan, float budget)
{
	energetica[i].energiBersih.kemudahanAkses += nilaiKemudahan;
	energetica[i].budget -= budget;
}

void kebersihan (kota *energetica, int i, int nilaiKebersihan, float budget)
{
	energetica[i].energiBersih.kebersihan += nilaiKebersihan;
	energetica[i].budget -= budget;
}

void penambahanEnergi (kota *energetica, int i, int nilaiPenambahan, float budget)
{
	energetica[i].energiBersih.energiTerbarukan += nilaiPenambahan;
	energetica[i].budget -= budget;
}

void aturAksesEnergi(kota *energetica, int i)
{
	int opsi;
	printf("Apa yang ingin diubah pada Akses Energi Bersih?\n");
	printf("1. Pembangunan PLTA\n");
	printf("2. Membuat kebijakan dan regulasi energi bersih\n");
	printf("3. Memberikan edukasi kepada warga\n");
	printf("4. Pembangunan infrasruktur yang lebih baik\n");
	printf("5. Peningkatan akses di daerah terpencil\n");
	scanf("%d", &opsi);
	
	switch (opsi)
	{
		case 1:
			printf("Budget yang dibutuhkan : %f\nValue efektifitas : %d", 100000, 30);
			penambahanEnergi (energetica, i, 30 , 100000);
			break;
		case 2 :
			printf("Budget yang dibutuhkan : %f\nValue efektifitas : %d", 50000, 20);
			kemudahanAkses (energetica, i, 20 , 50000);
			break;
		case 3 :
			printf("Budget yang dibutuhkan : %f\nValue efektifitas : %d", 5000, 10);
			kebersihan (energetica, i, 10 , 5000);
			break;
		case 4 :
			printf("Budget yang dibutuhkan : %f\nValue efektifitas : %d", 100000, 30);
			penambahanEnergi (energetica, i, 30 , 100000);
			break;
		case 5 :
			printf("Budget yang dibutuhkan : %f\nValue efektifitas : %d", 100000, 30);
			penambahanEnergi (energetica, i, 30 , 100000);
			break;
		default :
			printf("Input tidak valid. Mohon melakukan input ulang!");
			aturAksesEnergi(energetica, i);
	}
}

//CODE BERSAMA

void definisiKota(kota *energetica) {
	
    strcpy(energetica[0].nama, "Dea-Tae-AE");
    strcpy(energetica[1].nama, "Elegger City");
    strcpy(energetica[2].nama, "Tekkompolis");
    strcpy(energetica[3].nama, "Biotopia");
    
    strcpy(energetica[0].desc, "Ini deskripsi kota Dea-Tae-AE");
    strcpy(energetica[1].desc, "Ini deskripsi kota Elegger City");
    strcpy(energetica[2].desc, "Ini deskripsi kota Tekkompolis");
    strcpy(energetica[3].desc, "Ini deskripsi kota Biotopia");
    
    energetica[0].budget = 250000000;
    energetica[1].budget = 200000000;
    energetica[2].budget = 150000000;
    energetica[3].budget = 100000000;

	//indeks dte = 55
	//indeks elegger = 55
	//indeks tekkompolis = 48,75
	//indeks biotopia = 43,75
	energetica[0].listrik.indeksListrik = 55;
	energetica[1].listrik.indeksListrik = 60;
	energetica[2].listrik.indeksListrik = 65;
	energetica[3].listrik.indeksListrik = 40;
	
	definisiKebersihanRumahTangga(energetica);
	
	energetica[0].energiBersih.indeksAksesEnergi = 65;
	energetica[1].energiBersih.indeksAksesEnergi = 40;
	energetica[2].energiBersih.indeksAksesEnergi = 40;
	energetica[3].energiBersih.indeksAksesEnergi = 55;
	
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
	
	int i, pil, trig = 0;
	 
	for(i = 0; i < 4; i++) {
        definisiListrik(energetica);
        
        if(trig > 0) {
        	printf("Maaf anda gagal!\n");
        	printf("Press Any Button to Continue");
        	getch();
        	system("cls");
        	break;
		}

		printf("L E V E L   %d || %s\n", i + 1, energetica[i].nama);
		printf("==================================\n");
		printf("%s\n\n", energetica[i].desc);
		printf("Press any key to continue!");
		getch();
		system("cls");
		
		while(energetica[i].indeksKota < 75) {
			
			energetica[i].indeksKota = (energetica[i].listrik.indeksListrik * 0.25) + (energetica[i].energiBersih.indeksAksesEnergi * 0.25) + (energetica[i].emisiGas.indeksGasRumahKaca * 0.25) + (energetica[i].kebersihanRumahTangga.indeksKebersihanRT * 0.25);
            printf("Berikut adalah informasi mengenai kota %s sejauh ini\n", energetica[i].nama);
            printf("Budget kota : %.2f\n", energetica[i].budget);
            printf("Sisa hari   : %.d\n\n", energetica[i].hari);

            printf("||================================\n");
            printf("|| Statistik\n");
            printf("||================================\n");
            printf("|| Status Indeks        : %.2f%%\n", energetica[i].indeksKota);
            printf("|| Status Listrik       : %.2f%%\n", energetica[i].listrik.indeksListrik );
            printf("|| Status Kebersihan    : %.2f%%\n", energetica[i].kebersihanRumahTangga.indeksKebersihanRT);
            printf("|| Status Energi Bersih : %.2f%%\n", energetica[i].energiBersih.indeksAksesEnergi);
            printf("|| Status Emisi Gas     : %.2f%%\n", energetica[i].emisiGas.indeksGasRumahKaca);

            printf("\nSektor yang dapat dipilih:\n");
            printf("1. Akses Listrik\n");
            printf("2. Kebersihan Rumah Tangga\n");
            printf("3. Akses Energi Bersih\n");
            printf("4. Emisi Gas Rumah Kaca\n\n");

            printf("Masukkan sektor yang ingin diubah: ");
			scanf("%d", &pil);
			switch(pil) {
						
				case 1 : 
                    aturListrik(energetica, i);
					break;
				case 2 :
					aturKebersihanRumahTangga(energetica, i);
					break;
				case 3 :
					aturAksesEnergi(energetica, i);
					break;
				case 4 :
					aturEmisi(energetica, i);
					break;
				default : 
                    printf("Input anda tidak valid!\n\nPress any key to continue!");
                    continue;
				
				if(energetica[i].budget == 0 || energetica[i].hari == 0 ) {
					trig++;
					break;
				}
			}
			
		}

		printf("B E R H A S I L - L E V E L   %d || %s\n", i + 1, energetica[i].nama);
		
		getch();
		system("cls");
	}
}


int main() {
	
	kota energetica[4];
	
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
    
    	int pil;
    
    	while(1) {
	
    	printf(ANSI_COLOR_GREEN"    ______"ANSI_COLOR_RESET"_   __"ANSI_COLOR_GREEN"______"ANSI_COLOR_RESET"____  ______"ANSI_COLOR_GREEN"______"ANSI_COLOR_RESET"___________________\n");
    	printf(ANSI_COLOR_GREEN"   / ____/"ANSI_COLOR_RESET" | / "ANSI_COLOR_GREEN"/ ____/"ANSI_COLOR_RESET" __ \\/ ____"ANSI_COLOR_GREEN"/ ____/"ANSI_COLOR_RESET"_  __/  _/ ____/   |\n");
    	printf(ANSI_COLOR_GREEN"  / __/ "ANSI_COLOR_RESET"/  |/ "ANSI_COLOR_GREEN"/ __/ "ANSI_COLOR_RESET"/ /_/ / / __"ANSI_COLOR_GREEN"/ __/   "ANSI_COLOR_RESET"/ /  / // /   / /| |\n");
    	printf(ANSI_COLOR_GREEN" / /___"ANSI_COLOR_RESET"/ /|  "ANSI_COLOR_GREEN"/ /___"ANSI_COLOR_RESET"/ _, _/ /_/ "ANSI_COLOR_GREEN"/ /___  "ANSI_COLOR_RESET"/ / _/ // /___/ ___ |\n");
    	printf(ANSI_COLOR_GREEN"/_____/"ANSI_COLOR_RESET"_/ |_"ANSI_COLOR_GREEN"/_____/"ANSI_COLOR_RESET"_/ |_|\\____"ANSI_COLOR_GREEN"/_____/"ANSI_COLOR_RESET" /_/ /___/\\____/_/  |_|\n");
    	printf("\n\n");
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
    	
    			printf(ANSI_COLOR_GREEN "ENERGETICA" ANSI_COLOR_RESET " adalah negara yang kecil, namun memiliki potensi yang besar. Saat ini " ANSI_COLOR_GREEN "ENERGETICA" ANSI_COLOR_RESET" dalam rangka janji kampanye yang telah dibuat,");
    			printf("kamu bertekad untuk membawa negara ini dan kota-kotanya untuk mencapai tujuan dari" ANSI_COLOR_CYAN " SDG 7 " ANSI_COLOR_RESET "yang memiliki indeks capaian tersebut. Majukanlah kota-kota Energetica untuk mencapai\n");
                printf("tujuan SDG 7 dan mencapai tujuan indeks kalian!");
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
	
   				printf(ANSI_COLOR_CYAN "\n===================================================================================================================================================================================================================\n"ANSI_COLOR_RESET);
   				printf("THE GOAL OF SDG 7 FROM THE UN IS TO ENSURE ACCESS TO AFFORDABLE, RELIABLE, SUSTAINABLE, AND MODERN ENERGY FOR ALL!\n");
   				printf("Renewable energy solutions are becoming cheaper, more reliable and more efficient every day.Our current reliance on fossil fuels is unsustainable and harmful to the planet, which is why we have to change the way we produce and consume energy. Implementing these new energy solutions as fast as possible is essential to counter climate change, one of the biggest threats to our own survival.\n");
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
				printf(ANSI_COLOR_GREEN "______________ ___    _____    _______   ____  __. _____.___.________   ____ ___  ._.\n");
    			printf("\\__    ___/   |   \\  /  _  \\   \\      \\ |    |/ _| \\__  |   |\\_____  \\ |    |   \\ | |\n");
    			printf("  |    | /    ~    \\/  /_\\  \\  /   |   \\|      <    /   |   | /   |   \\|    |   / | |\n");
    			printf("  |    | \\    Y    /    |    \\/    |    \\    |  \\   \\____   |/    |    \\    |  /   \\|\n");
   				printf("  |____|  \\___|_  /\\____|__  /\\____|__  /____|__ \\  / ______|\\_______  /______/    __\n");
    			printf("                \\/         \\/         \\/        \\/  \\/               \\/            \\/" ANSI_COLOR_RESET "\n");
				return 0;
    		
    		default : 
				system("cls");
				printf("T Y P E   A   V A L I D   N U M B E R !!\n\n");
				printf("Press any key to Continue");
				getch();
				system("cls");
		}
	}
    

    return 0;
}
