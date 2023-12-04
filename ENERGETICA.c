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
		
	} listrik;
	
	struct kebersihanRumahTangga {
		
	};
	
	struct aksesEnergiBersih {
		
	};
	
	struct emisiGasRumahKaca {
		float gasCO2;
		float gasCH4;
		float gasN2O;
		float maxValue;
		int skalaHistogram;
		
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

void changeCO2(kota *energetica, float gasCO2, int i) {
	float inc;
	printf("Masukkan penurunan CO2 yang diinginkan: ");
	scanf("%f", &inc);
	
	if(inc > 0 ) { //kondisinya ada yang gua apus
		energetica[i].emisiGas.gasCO2 -= inc;
		energetica[i].indeksKota -= 0.1 * inc;
		printf("Berhasil menurunkan CO2\n");
	}
}

void changeCH4(kota *energetica, float gasCH4, int i) {
	float inc;
	printf("Masukkan penurunan CH4 yang diinginkan: ");
	scanf("%f", &inc);
	
	if(inc > 0 ) {
		energetica[i].emisiGas.gasCH4 -= inc;
		energetica[i].indeksKota -= 0.1 * inc;
		printf("Berhasil menurunkan CH4\n");
	}
}

void changeN2O(kota *energetica, float gasN2O, int i) {
	float inc;
	printf("Masukkan penurunan N2O yang diinginkan: ");
	scanf("%f", &inc);
	
	if(inc > 0 ) {
		energetica[i].emisiGas.gasN2O -= inc;
		energetica[i].indeksKota -= 0.1 * inc;
		printf("Berhasil menurunkan CH4\n");
	}
}

void aturEmisi(kota *energetica, int i) {
	int pil, hari;//ini hari belum diganti
	float budget = 100000000;//ini harusnya disesuaikan dengan option
	
	printf("\n\nO P S I\n");
	printf("========================\n");
	printf("1. Gas CO2\n");
	printf("2. Gas CH4\n");
	printf("3. Gas N20\n");
	scanf("%d",&pil);
	
	switch(pil) {
		case 1 : 
			changeCO2(energetica,energetica[i].emisiGas.gasCO2, i);
			break;
		case 2 : 
			changeCH4(energetica,energetica[i].emisiGas.gasCH4, i);
			break;
		case 3 : 
			changeN2O(energetica,energetica[i].emisiGas.gasN2O, i);
			break;
		default : 
			printf("Masukkan Variabel Yang Valid!");
			getch();
			system("cls");	
	}
	
	energetica[i].budget -= budget;	//lebih cocok untuk nanti di function
	
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

	energetica[0].indeksKota = 40;
	energetica[1].indeksKota = 35;
	energetica[2].indeksKota = 30;
	energetica[3].indeksKota = 25;
	
	energetica[0].hari = 30;
	energetica[1].hari = 25;
	energetica[2].hari = 20;
	energetica[3].hari = 15;
		
}

void gameplay(kota *energetica) {
	int i, pil;
	
	for(i = 0; i < 4; i++) {
        definisiListrik(energetica);

		printf("L E V E L   %d || %s\n", i + 1, energetica[i].nama);
		printf("==================================\n");
		printf("%s\n\n", energetica[i].desc);
		printf("Press any key to continue!");
		getch();
		system("cls");
		
		while(energetica[i].hari > 0 && energetica[i].budget > 0) {
			
            printf("Berikut adalah informasi mengenai kota %s sejauh ini\n", energetica[i].nama);
            printf("Budget kota : %.2f\n", energetica[i].budget);
            printf("Sisa hari   : %.d\n\n", energetica[i].hari);

            printf("||================================\n");
            printf("|| Statistik\n");
            printf("||================================\n");
            printf("|| Status Indeks        : %.2f%%\n", energetica[i].indeksKota);
            printf("|| Status Listrik       : %%\n");
            printf("|| Status Kebersihan    : %%\n");
            printf("|| Status Energi Bersih : %%\n");
            printf("|| Status Emisi Gas     : %%\n");

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
					break;
				case 3 :
					break;
				case 4 :
					aturEmisi(energetica, i);
					break;
				default : 
                    printf("Input anda tidak valid!\n\nPress any key to continue!");
                    continue;
				
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
    	
    			printf(ANSI_COLOR_GREEN "ENERGETICA" ANSI_COLOR_RESET " adalah negara yang kecil, namun memiliki potensi yang besar. Saat ini " ANSI_COLOR_GREEN "ENERGETICA" ANSI_COLOR_RESET" dalam rangka janji kampanye yang telah dibuat,\n");
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
