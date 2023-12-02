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
	
    printf(ANSI_COLOR_YELLOW "  W   W  EEEEE  L      CCCCC  OOO   M     M  EEEEE  \n");
    printf("  W   W  E      L     C      O   O  MM   MM  E      \n");
    printf("  W W W  EEEE   L     C      O   O  M M M M  EEEE   \n");
    printf("  W W W  E      L     C      O   O  M  M  M  E      \n");
    printf("   W W   EEEEE  LLLLL  CCCCC  OOO   M     M  EEEEE  \n");

    printf("\n");

    printf("  TTTTT  OOO   \n");
    printf("    T   O   O  \n");
    printf("    T   O   O  \n");
    printf("    T   O   O  \n");
    printf("    T    OOO   \n");

    printf("\n");

    printf("  " ANSI_COLOR_GREEN "EEEEE" ANSI_COLOR_RESET "  N     N  " ANSI_COLOR_GREEN "EEEEE" ANSI_COLOR_RESET "  RRRR   GGG   " ANSI_COLOR_GREEN "EEEEE" ANSI_COLOR_RESET "  TTTTT  III  CCCCC  AAAAA \n");
    printf("  " ANSI_COLOR_GREEN "E" ANSI_COLOR_RESET "      NN    N  " ANSI_COLOR_GREEN "E" ANSI_COLOR_RESET "      R   R G   G  " ANSI_COLOR_GREEN "E" ANSI_COLOR_RESET "        T     I   C      A   A \n");
    printf("  " ANSI_COLOR_GREEN "EEEE" ANSI_COLOR_RESET "   N N   N  " ANSI_COLOR_GREEN "EEEE" ANSI_COLOR_RESET "   RRRR  G     " ANSI_COLOR_GREEN "EEEE" ANSI_COLOR_RESET "     T     I   C      AAAAA \n");
    printf("  " ANSI_COLOR_GREEN "E" ANSI_COLOR_RESET "      N  N  N  " ANSI_COLOR_GREEN "E" ANSI_COLOR_RESET "      R  R  G G G  " ANSI_COLOR_GREEN "E" ANSI_COLOR_RESET "        T     I   C      A   A \n");
    printf("  " ANSI_COLOR_GREEN "EEEEE" ANSI_COLOR_RESET "  N   N N  " ANSI_COLOR_GREEN "EEEEE" ANSI_COLOR_RESET "  R   R  GGG   " ANSI_COLOR_GREEN "EEEEE" ANSI_COLOR_RESET "    T    III  CCCCC  A   A \n");
    
    printf("\n\nPress any button to Continue!");
    getch();
    system("cls");
    
    int pil;
    
    while(1) {
	
    printf("  " ANSI_COLOR_GREEN "EEEEE" ANSI_COLOR_RESET "  N     N  " ANSI_COLOR_GREEN "EEEEE" ANSI_COLOR_RESET "  RRRR   GGG   " ANSI_COLOR_GREEN "EEEEE" ANSI_COLOR_RESET "  TTTTT  III  CCCCC  AAAAA \n");
    printf("  " ANSI_COLOR_GREEN "E" ANSI_COLOR_RESET "      NN    N  " ANSI_COLOR_GREEN "E" ANSI_COLOR_RESET "      R   R G   G  " ANSI_COLOR_GREEN "E" ANSI_COLOR_RESET "        T     I   C      A   A \n");
    printf("  " ANSI_COLOR_GREEN "EEEE" ANSI_COLOR_RESET "   N N   N  " ANSI_COLOR_GREEN "EEEE" ANSI_COLOR_RESET "   RRRR  G      " ANSI_COLOR_GREEN "EEEE" ANSI_COLOR_RESET "     T     I   C      AAAAA \n");
    printf("  " ANSI_COLOR_GREEN "E" ANSI_COLOR_RESET "      N  N  N  " ANSI_COLOR_GREEN "E" ANSI_COLOR_RESET "      R  R  G G G  " ANSI_COLOR_GREEN "E" ANSI_COLOR_RESET "        T     I   C      A   A \n");
    printf("  " ANSI_COLOR_GREEN "EEEEE" ANSI_COLOR_RESET "  N   N N  " ANSI_COLOR_GREEN "EEEEE" ANSI_COLOR_RESET "  R   R  GGG   " ANSI_COLOR_GREEN "EEEEE" ANSI_COLOR_RESET "    T    III  CCCCC  A   A \n");
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
		
		system("cls"); break;
    		
    	case 4 : return 0;
    		
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
