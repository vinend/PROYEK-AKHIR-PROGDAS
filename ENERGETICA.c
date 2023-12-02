#include <stdio.h>
#include <math.h>
#include <stdlib.h>
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
	
	char nama[50];
	float indeksKota;
	float nilaiKeseluruhan;
	float budget;
	
	struct aksesListrik {
		
	};
	
	struct kebersihanRumahTangga {
		
	};
	
	struct aksesEnergiBersih {
		
	};
	
	struct emisiGasRumahKaca {
		
	};
	
} kota;



int main() {
	
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
    
    printf("\n\nPress any button to Continue!");
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
    	case 1 : system("cls"); break;
    		
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
		printf("\nPress Any Button To Continue");
		getch();
		system("cls"); break;
    	
    	case 3 : 
		system("cls");
		printf(ANSI_COLOR_CYAN" ________  ________  ________                ________  \n");
    	printf("|\\   ____\\|\\   ___ \\|\\   ____\\              |\\_____  \\ \n");
    	printf("\\ \\  \\___|\\ \\  \\_|\\ \\ \\  \\___|               \\|___/  /|\n");
    	printf(" \\ \\_____  \\ \\  \\ \\\\ \\ \\  \\  ___                 /  / / \n");
    	printf("  \\|____|\\  \\ \\  \\_\\\\ \\ \\  \\|\\  \\               /  / /  \n");
    	printf("    ____\\_\\  \\ \\_______\\ \\_______\\             /__/ /   \n");
    	printf("   |\\_________\\|_______|\\|_______|             |__|/    \n");
   	 	printf("   \\|_________|                                        \n");
   	 	
   	 	
   	 	printf("  ___  ____________ _________________  ___  ______ _      _____   _____ _   _ _____ _____ ___  _____ _   _   ___  ______ _      _____  ______ _____ _     _____  ___  ______ _      _____ \n");
    	printf(" / _ \\ |  ___|  ___|  _  | ___ \\  _  \\/ _ \\ | ___ \\ |    |  ___| /  ___| | | /  ___|_   _/ _ \\|_   _| \\ | | / _ \\ | ___ \\ |    |  ___| | ___ \\  ___| |   |_   _|/ _ \\ | ___ \\ |    |  ___|\n");
   	 	printf("/ /_\\ \\| |_  | |_  | | | | |_/ / | | / /_\\ \\| |_/ / |    | |__   \\ `--.| | | \\ `--.  | |/ /_\\ \\ | | |  \\| |/ /_\\ \\| |_/ / |    | |__   | |_/ / |__ | |     | | / /_\\ \\| |_/ / |    | |__  \n");
    	printf("|  _  ||  _| |  _| | | | |    /| | | |  _  || ___ \\ |    |  __|   `--. \\ | | |`--. \\ | ||  _  | | | | . ` ||  _  || ___ \\ |    |  __|  |    /|  __|| |     | | |  _  || ___ \\ |    |  __| \n");
    	printf("| | | || |   | |   \\ \\_/ / |\\ \\| |/ /| | | || |_/ / |____| |___  /\\__/ / |_| /\\__/ / | || | | |_| |_| |\\  || | | || |_/ / |____| |___  | |\ \\| |___| |_____| |_| | | || |_/ / |____| |___ \n");
    	printf("\\_| |_/\\_|   \\_|    \\___/\\_| \\_|___/ \\_| |_/\\____/\\_____/\\____/  \\____/ \\___/\\____/  \\_/\\_| |_/\\___/\\_| \\_/\\_| |_/\____/\\_____/\\____/  \\_| \\_\\____/\\_____/\\___/\\_| |_/\\____/\\_____/\n");
    
   	 	printf("\n===================================================================================================================================================================================================================\n" ANSI_COLOR_RESET);
   	 	
    	getch();
		system("cls"); break;
    		
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
		printf("Press Any Button To Continue");
		getch();
		system("cls"); break;
	}
}
    

    return 0;
}
