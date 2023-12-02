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
	
   printf(ANSI_COLOR_YELLOW" _       __________    __________  __  _________                   "ANSI_COLOR_BLUE"________\n"ANSI_COLOR_YELLOW);
    printf("| |     / / ____/ /   / ____/ __ \\/  |/  / ____/                  "ANSI_COLOR_BLUE"/////////\n"ANSI_COLOR_YELLOW);
    printf("| | /| / / __/ / /   / /   / / / / /|_/ / __/                    "ANSI_COLOR_BLUE"/////////\n"ANSI_COLOR_YELLOW);
    printf("| |/ |/ / /___/ /___/ /___/ /_/ / /  / / /___                   "ANSI_COLOR_BLUE"/////////\n"ANSI_COLOR_YELLOW);
    printf("|__/|__/_____/_____/\\____/\\____/_/  /_/_____/                  "ANSI_COLOR_BLUE"/////////___\n"ANSI_COLOR_YELLOW);

    printf("\t\t\t\t\t\t\t" "      "ANSI_COLOR_BLUE"/_____///////\n"ANSI_COLOR_YELLOW);

    printf("  __________                                                       "ANSI_COLOR_BLUE"///////\n"ANSI_COLOR_YELLOW);
    printf(" /_  __/ __ \\                                                     "ANSI_COLOR_BLUE"///////__\n"ANSI_COLOR_YELLOW);
    printf("  / / / / / /                                                    "ANSI_COLOR_BLUE"//////////\n"ANSI_COLOR_YELLOW);
    printf(" / / / /_/ /                                                    "ANSI_COLOR_BLUE"/____/////\n"ANSI_COLOR_YELLOW);
    printf("/_/  \\____/                                                         "ANSI_COLOR_BLUE"/////\n"ANSI_COLOR_YELLOW);

    printf("\t\t\t\t\t\t\t\t" "   "ANSI_COLOR_BLUE"/////\n");

    printf(ANSI_COLOR_GREEN"    ______"ANSI_COLOR_RESET"_   __"ANSI_COLOR_GREEN"______"ANSI_COLOR_RESET"____  ______"ANSI_COLOR_GREEN"______"ANSI_COLOR_RESET"___________________\n");
    printf(ANSI_COLOR_GREEN"   / ____/"ANSI_COLOR_RESET" | / "ANSI_COLOR_GREEN"/ ____/"ANSI_COLOR_RESET" __ \\/ ____"ANSI_COLOR_GREEN"/ ____/"ANSI_COLOR_RESET"_  __/  _/ ____/   |\n");
    printf(ANSI_COLOR_GREEN"  / __/ "ANSI_COLOR_RESET"/  |/ "ANSI_COLOR_GREEN"/ __/ "ANSI_COLOR_RESET"/ /_/ / / __"ANSI_COLOR_GREEN"/ __/   "ANSI_COLOR_RESET"/ /  / // /   / /| |\n");
    printf(ANSI_COLOR_GREEN" / /___"ANSI_COLOR_RESET"/ /|  "ANSI_COLOR_GREEN"/ /___"ANSI_COLOR_RESET"/ _, _/ /_/ "ANSI_COLOR_GREEN"/ /___  "ANSI_COLOR_RESET"/ / _/ // /___/ ___ |\n");
    printf(ANSI_COLOR_GREEN"/_____/"ANSI_COLOR_RESET"_/ |_"ANSI_COLOR_GREEN"/_____/"ANSI_COLOR_RESET"_/ |_|\\____"ANSI_COLOR_GREEN"/_____/"ANSI_COLOR_RESET" /_/ /___/\\____/_/  |_|\n");
    
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
    		
    	case 2 : system("cls"); break;
    	
    	case 3 : system("cls"); break;
    		
    	case 4 : system("cls"); break;
    		
    	default : system("cls"); break;
	}
}
    

    return 0;
}
