/*
PROYEK AKHIR DASKOM-02
SMART MAP

Oleh:
Amalia Kumala Dewi (1906384112)
Maharani Jelita Indriati (1906304370)
Shafa Tasya Aulia Putri (1906305303) */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define MAP_SIZE 10 //ukuran map 10 x 10

// Struct koordinat untuk mendeklarasikan variabel koordinat lokasi
typedef struct {
    int x; //row
    int y; //column
} coord;

// Struct bangunan untuk mendeklarasikan variabel lokasi bangunan
typedef struct {
    char* name; //char pointer sebagai string (kumpulan beberapa karakter)
    coord loc; 
} building;

// Array 1D untuk menyimpan lokasi bangunan
const building builds[MAP_SIZE] = {
    {"Dekan",{9,4}},
    {"Gedung DTE",{7,8}},
    {"Gedung K",{5,5}},
    {"Gedung S",{6,3}},
    {"Rotunda",{2,6}},
    {"KanTek (Kantin Teknik)",{1,4}},
    {"MusTek (Musholla Teknik)",{0,4}},
    {"Gedung EC",{2,1}},
    {"Gedung MRPQ",{4,8}},
    {"Tempat Parkir",{9,8}}
};
//Lokasi diatas terletak di koordinat yang tertulis setelahnya

// Array 2D untuk menyimpan lokasi jalan
const int maps[MAP_SIZE][MAP_SIZE] = {
    {0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,1,1,1,0,0,0},
    {0,1,1,1,0,0,1,0,0,0},
    {0,0,0,1,0,0,1,0,1,0},
    {0,0,0,1,0,1,1,0,1,0},
    {0,0,0,1,0,1,0,0,1,0},
    {0,0,0,1,0,1,0,0,1,0},
    {0,0,0,1,0,1,0,0,1,0},
    {0,0,0,1,0,1,0,0,1,0},
    {0,0,0,1,1,1,1,1,1,0}
};
//Angka 1 manandakan jalan, sedangkan angka 0 menandakan bukan jalan

building currentLoc, destination; //variable penyimpan lokasi

// function dengan paramater value (char pointer = value string)
coord getCoord(char* c){
    coord tmp;
    int found = 0, i = 0;
    while (!found && i<MAP_SIZE){
        if (builds[i].name == c){
            found = 1;
            tmp = builds[i].loc;
        }
        i++;
    }
    return tmp;
}
// Untuk menemukan koordinat bangunan yang dipilih user menggunakan loop

// function untuk memindai input apakah sesuai atau tidak
int scanner(){
	char n[30];
	while(1){
		scanf("%s", &n);
		if(strcmp(n, "1")==0) return 1;
		else if(strcmp(n, "2")==0) return 2;
		else if(strcmp(n, "3")==0) return 3;
		else if(strcmp(n, "4")==0) return 4;
		else if(strcmp(n, "5")==0) return 5;
		else if(strcmp(n, "6")==0) return 6;
		else if(strcmp(n, "7")==0) return 7;
		else if(strcmp(n, "8")==0) return 8;
		else if(strcmp(n, "9")==0) return 9;
		else if(strcmp(n, "10")==0) return 10;
		else {
			printf("\n\t\t\t\t\t\tInvalid Input\n");
			printf("\t\t\t\t\t\tNomor lokasi: ");
		}	
	}	
}
//Jika input yang dimasukkan tidak sesuai pilihan, maka program akan meminta input kembali hingga sesuai

// function dengan parameter address
void inputLocation(building* b){
	system("cls");
    int n;
    printf("\n");
    printf("\n\t\t\t\t\t==========================================");
    printf("\n\t\t\t\t\t\t      Pilihan Lokasi\t\t");
    printf("\n\t\t\t\t\t\t\tCHILL MAP\t\t");
    printf("\n\t\t\t\t\t==========================================");
    printf("\n\n");
	printf("\t\t\t\t\t\t[1] Gedung 1: Dekanat\n");
	printf("\t\t\t\t\t\t[2] Gedung 2: DTE\n");
	printf("\t\t\t\t\t\t[3] Gedung 3: Gedung K\n");
	printf("\t\t\t\t\t\t[4] Gedung 4: Gedung S\n");
	printf("\t\t\t\t\t\t[5] Gedung 5: Rotunda\n");
	printf("\t\t\t\t\t\t[6] Gedung 6: KanTek\n");
	printf("\t\t\t\t\t\t[7] Gedung 7: MusTek\n");
	printf("\t\t\t\t\t\t[8] Gedung 8: Gedung EC\n");
	printf("\t\t\t\t\t\t[9] Gedung 9: MRPQ\n");
	printf("\t\t\t\t\t\t[10] Gedung P: Tempat Parkir\n");
	
	printf("\n\t\t\t\t\t------------------------------------------\n");
	printf("\t\t\t\t\t\tNomor lokasi saat ini: ");
	n=scanner(); //Display pilihan lokasi 

    // switch case untuk menentukan lokasi yang dipilih user
    switch (n) {
        case 1:
            b->name = "Dekan";
            b->loc = getCoord("Dekan");
            break;
        case 2:
            b->name = "Gedung DTE";
            b->loc = getCoord("Gedung DTE");
            break;
        case 3:
            b->name = "Gedung K";
            b->loc = getCoord("Gedung K");
            break;
        case 4:
            b->name = "Gedung S";
            b->loc = getCoord("Gedung S");
            break;
        case 5:
            b->name = "Rotunda";
            b->loc = getCoord("Rotunda");
            break;
        case 6:
            b->name = "KanTek (Kantin Teknik)";
            b->loc = getCoord("KanTek (Kantin Teknik)");
            break;
        case 7:
            b->name = "MusTek (Musholla Teknik)";
            b->loc = getCoord("MusTek (Musholla Teknik)");
            break;
        case 8:
            b->name = "Gedung EC";
            b->loc = getCoord("Gedung EC");
            break;
        case 9:
            b->name = "Gedung MRPQ";
            b->loc = getCoord("Gedung MRPQ");
            break;
        case 10:
            b->name = "Tempat Parkir";
            b->loc = getCoord("Tempat Parkir");
            break;
    }
}
//Program menyimpan lokasi yang dipilih user

//function untuk meminta lokasi user yang ingin dituju selanjutnya
void inputDestination(building* b){
	system("cls");
    int n;
    printf("\n");
    printf("\n\t\t\t\t\t==========================================");
    printf("\n\t\t\t\t\t     Pilihan Lokasi Yang Ingin Dituju\t\t");
    printf("\n\t\t\t\t\t\t\tSMART MAP\t\t");
    printf("\n\t\t\t\t\t==========================================");
    printf("\n\n");
	printf("\t\t\t\t\t\t[1] Gedung 1: Dekanat\n");
	printf("\t\t\t\t\t\t[2] Gedung 2: DTE\n");
	printf("\t\t\t\t\t\t[3] Gedung 3: Gedung K\n");
	printf("\t\t\t\t\t\t[4] Gedung 4: Gedung S\n");
	printf("\t\t\t\t\t\t[5] Gedung 5: Rotunda\n");
	printf("\t\t\t\t\t\t[6] Gedung 6: KanTek\n");
	printf("\t\t\t\t\t\t[7] Gedung 7: MusTek\n");
	printf("\t\t\t\t\t\t[8] Gedung 8: Gedung EC\n");
	printf("\t\t\t\t\t\t[9] Gedung 9: MRPQ\n");
	printf("\t\t\t\t\t\t[10] Gedung P: Tempat Parkir\n");
	
	printf("\n\t\t\t\t\t------------------------------------------\n");
	printf("\t\t\t\t\t    Nomor lokasi yang ingin dituju: ");
	n=scanner(); //Display pilihan lokasi berikutnya
	
    //Switch case untuk menentukan lokasi berikutnya
    switch (n) {
        case 1:
            b->name = "Dekan";
            b->loc = getCoord("Dekan");
            break;
        case 2:
            b->name = "Gedung DTE";
            b->loc = getCoord("Gedung DTE");
            break;
        case 3:
            b->name = "Gedung K";
            b->loc = getCoord("Gedung K");
            break;
        case 4:
            b->name = "Gedung S";
            b->loc = getCoord("Gedung S");
            break;
        case 5:
            b->name = "Rotunda";
            b->loc = getCoord("Rotunda");
            break;
        case 6:
            b->name = "KanTek (Kantin Teknik)";
            b->loc = getCoord("KanTek (Kantin Teknik)");
            break;
        case 7:
            b->name = "MusTek (Musholla Teknik)";
            b->loc = getCoord("MusTek (Musholla Teknik)");
            break;
        case 8:
            b->name = "Gedung EC";
            b->loc = getCoord("Gedung EC");
            break;
        case 9:
            b->name = "Gedung MRPQ";
            b->loc = getCoord("Gedung MRPQ");
            break;
        case 10:
            b->name = "Tempat Parkir";
            b->loc = getCoord("Tempat Parkir");
            break;
    }
}
//Program menyimpan koordinat lokasi user yang ingin dituju selanjutnya

//function untuk mencetak MAP
void printMap(){
    // lokasi saat ini disimbolkan oleh 'X'
    // Bukan jalan disimbolkan oleh '#'
    // jalan disimbolkan oleh 'O'
    system("cls");//mereset tampilan pada layar program
    printf("\n");
    printf("\n\t\t\t\t\t\t\t     MAP\t\t\n");
    //for loop untuk mencetak map
    for (int i=0; i<MAP_SIZE; i++){
    	printf("\t\t\t\t     ");
        for (int j=0; j<MAP_SIZE; j++){
            if (currentLoc.loc.x == i && currentLoc.loc.y == j) printf("  X  "); //mencetak simbol 'X' sesuai dengan lokasi awal user
            else if (i==8&&j==4) printf("\033[0;33m  1  \033[30;43m");
            else if (i==7&&j==9) printf("\033[0;33m  2  \033[30;43m");
            else if (i==5&&j==6) printf("\033[0;33m  3  \033[30;43m");
            else if (i==6&&j==2) printf("\033[0;33m  4  \033[30;43m");
            else if (i==2&&j==5) printf("\033[0;33m  5  \033[30;43m");
            else if (i==1&&j==3) printf("\033[0;33m  6  \033[30;43m");
            else if (i==0&&j==3) printf("\033[0;33m  7  \033[30;43m");
            else if (i==2&&j==0) printf("\033[0;33m  8  \033[30;43m");
            else if (i==4&&j==9) printf("\033[0;33m  9  \033[30;43m");
            else if (i==9&&j==9) printf("\033[0;33m  P  \033[30;43m"); //mencetak lokasi gedung sesuai koordinat
            else if (maps[i][j]==1) printf("  O  "); //mencetak jalan
            else printf("  #  "); //mencetak bukan jalan
        } //MAP akan tercetak sesuai dengan simbol yang sudah ditentukan
        printf("\n");
    }
    printf("\n\t\t\t\t\t--------------------------------------------");
    printf("\n\t\t\t\t\tKeterangan:");
    printf("\n\t\t\t\t\tX: lokasi saat ini");
    printf("\n\t\t\t\t\t-: rute");
    printf("\n\t\t\t\t\tO: jalan");
    printf("\n\t\t\t\t\t#: bukan jalan");
    printf("\n\t\t\t\t\t--------------------------------------------");
    printf("\n\t\t\t\t\tGedung 1: Dekanat\tGedung 6: KanTek");
	printf("\n\t\t\t\t\tGedung 2: DTE\t\tGedung 7: MusTek");
	printf("\n\t\t\t\t\tGedung 3: Gedung K\tGedung 8: Gedung EC");
	printf("\n\t\t\t\t\tGedung 4: Gedung S\tGedung 9: MRPQ");
	printf("\n\t\t\t\t\tGedung 5: Rotunda\tGedung P: Tempat Parkir");
	printf("\n\t\t\t\t\t--------------------------------------------");
    printf("\n\t\t\t\t\t    Tekan 'ENTER' untuk kembali ke menu\n");
    getch();//Display keterangan MAP
}

// function untuk mengecek apakah jalan atau bukan
int isStreet(coord c){
    if (c.x>=0 && c.x<MAP_SIZE && c.y>=0 && c.y<MAP_SIZE && maps[c.x][c.y]==1) return 1;
    else return 0;
}

// fungsi rekursif untuk mencari rute hingga tujuan user
int mapRoute(int r[MAP_SIZE][MAP_SIZE], coord dest, coord cl){
    // base case
    if (cl.x == dest.x && cl.y==dest.y && maps[cl.x][cl.y]==1){
        r[cl.x][cl.y] = 1;
        return 1;
    }
    // recurrence
    else if (isStreet(cl)==1){
        if(r[cl.x][cl.y]==1) return 0;
        else {
            r[cl.x][cl.y] = 1;
            coord tmp;
            // bawah
            tmp.x = cl.x+1; tmp.y=cl.y;
            if (mapRoute(r, dest, tmp)==1) return 1;
            // atas
            tmp.x = cl.x-1; tmp.y=cl.y;
            if (mapRoute(r, dest, tmp)==1) return 1;
            // kanan
            tmp.x = cl.x; tmp.y=cl.y+1;
            if (mapRoute(r, dest, tmp)==1) return 1;
            // kiri
            tmp.x = cl.x; tmp.y=cl.y-1;
            if (mapRoute(r, dest, tmp)==1) return 1;
            // jika bukan keempat pilihan diatas, backtrack
            r[cl.x][cl.y] = 0;
        }
    }
    return 0;
}
// menyimpan rute yang sesuai dengan tujuan user

// function untuk mencetak rute baru
void searchRoute(coord dest){
    int route[MAP_SIZE][MAP_SIZE] = { //Array 2d untuk menyimpan rute
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0}
    };
    coord cl = currentLoc.loc;
    if (mapRoute(route, dest, cl)){
        // print map dengan rute yang sudah disimpan di fungsi rekursi mapRoute
        system("cls");
        printf("\n");
        printf("\n\t\t\t\t\t\t\t     MAP\t\t\n");
        for (int i=0; i<MAP_SIZE; i++){
        	printf("\t\t\t\t     ");
            for (int j=0; j<MAP_SIZE; j++){
                if (currentLoc.loc.x == i && currentLoc.loc.y == j) printf("  X  ");
                else if (i==dest.x&&j==dest.y) printf("  X  ");
                else if (route[i][j]==1) printf("\033[6;37m  -  \033[30;43m");//print rute
                else if (i==8&&j==4) printf("\033[0;33m  1  \033[30;43m");
            	else if (i==7&&j==9) printf("\033[0;33m  2  \033[30;43m");
            	else if (i==5&&j==6) printf("\033[0;33m  3  \033[30;43m");
            	else if (i==6&&j==2) printf("\033[0;33m  4  \033[30;43m");
            	else if (i==2&&j==5) printf("\033[0;33m  5  \033[30;43m");
            	else if (i==1&&j==3) printf("\033[0;33m  6  \033[30;43m");
            	else if (i==0&&j==3) printf("\033[0;33m  7  \033[30;43m");
            	else if (i==2&&j==0) printf("\033[0;33m  8  \033[30;43m");
            	else if (i==4&&j==9) printf("\033[0;33m  9  \033[30;43m");
            	else if (i==9&&j==9) printf("\033[0;33m  P  \033[30;43m");
                else if (maps[i][j]==1) printf("  O  ");
                else printf("  #  ");
            }
            printf("\n");
        }
        printf("\n\t\t\t\t\t--------------------------------------------");
    	printf("\n\t\t\t\t\tKeterangan:");
    	printf("\n\t\t\t\t\tX: lokasi saat ini dan destinasi");
    	printf("\n\t\t\t\t\t-: rute");
    	printf("\n\t\t\t\t\tO: jalan");
    	printf("\n\t\t\t\t\t#: bukan jalan");
    	printf("\n\t\t\t\t\t--------------------------------------------");
    	printf("\n\t\t\t\t\tGedung 1: Dekanat\tGedung 6: KanTek");
		printf("\n\t\t\t\t\tGedung 2: DTE\t\tGedung 7: MusTek");
		printf("\n\t\t\t\t\tGedung 3: Gedung K\tGedung 8: Gedung EC");
		printf("\n\t\t\t\t\tGedung 4: Gedung S\tGedung 9: MRPQ");
		printf("\n\t\t\t\t\tGedung 5: Rotunda\tGedung P: Tempat Parkir");
		printf("\n\t\t\t\t\t--------------------------------------------");
    	printf("\n\t\t\t\t\t    Tekan 'ENTER' untuk kembali ke menu\n");
        getch();
    }
}//map akan tercetak dengan lokasi user awal dan tujuan beserta rutenya

//fungsi utama program untuk menampilkan halaman dan menu awal program
int main() {
	system("cls");
	system("Color 60");
	printf("\n\n\n\n\n\n\n");
	printf("\n\t\t\t\t\t==========================================");
	printf("\n\t\t\t\t\t\t\tSMART MAP\t\t");
    printf("\n\t\t\t\t\t\t    Fakultas Teknik UI\t\t");
    printf("\n\t\t\t\t\t==========================================");
    printf("\n\t\t\t\t\t\t      Diprogram oleh:\t\t\n");
    printf("\n\t\t\t\t\t\t    Amalia Kumala Dewi\t\t\n\t\t\t                         Maharani Jelita Indriati\t\t\n\t\t\t                          Shafa Tasya Aulia Putri\n");
    printf("\n\t\t\t\t\t------------------------------------------");
    printf("\n\t\t\t\t\t       Tekan 'ENTER' untuk memulai\n");
    getch();
    
    int i;
    system ("cls");
	printf ("\t\t");
	printf ("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tLoading");// untuk mencetak halaman loading
	printf ("\n\n\t\t\t\t      ");
 	//for loop untuk mencetak animasi loading
	for(i = 0 ; i < 43 ; i++) {
		printf(".");
		Sleep(10);
	}
	
    system("cls");
    inputLocation(&currentLoc);//untuk menjalankan fungsi void tersebut

    int end = 0;
    while (end==0) {
        // Mencetak menu
        system("cls");
        char n[30];
        printf("\n");
        printf("\n\t\t\t\t\t==========================================");
        printf("\n\t\t\t\t\t\t\t  MENU\t\t");
        printf("\n\t\t\t\t\t\t       SMART MAP\t\t");
        printf("\n\t\t\t\t\t==========================================");
        printf("\n\n");
		printf("\t\t\t\t\t\t[1] Lihat map\n");
		printf("\t\t\t\t\t\t[2] Cari rute\n");
		printf("\t\t\t\t\t\t[3] Ganti lokasi saat ini\n");
		printf("\t\t\t\t\t\t[4] Keluar\n");
		printf("\n\t\t\t\t\t------------------------------------------\n");
		printf("\t\t\t\t\t\tPilihan menu: ");
        scanf("%s",&n);
        
        //Meminta input user yang sesuai dengan pilihan
        int pil;
        while (1){
        	if(strcmp(n, "1")==0){
        		pil=1;
        		break;
			} 
			else if(strcmp(n, "2")==0){
        		pil=2;
        		break;
			} 
			else if(strcmp(n, "3")==0){
        		pil=3;
        		break;
			} 
			else if(strcmp(n, "4")==0){
        		pil=4;
        		break;
			} 
			else{
				printf("\n\t\t\t\t\t\tInvalid Input!\n");
    			printf("\t\t\t\t\t\tPilihan menu: ");
    			scanf("%s",&n);
			}
    	}//Jika input yang dimasukkan tidak sesuai pilihan, maka program akan meminta input kembali hingga sesuai
		
		//menjalankan program sesuai dengan input yang diberikan user
        switch (pil) {
            case 1:
                printMap();
                break;
            case 2:
                inputDestination(&destination);
                if (destination.name==currentLoc.name) { //jika lokasi awal sama dengan tujuan, program akan mencetak kalimat dibawah ini
                    printf("\t\t\t\t\t\tAnda sudah berada di lokasi tujuan\n");
                    printf("\t\t\t\t\t\tTekan 'ENTER' untuk kembali ke menu\n");
                    getch();
                }
                else {
                    searchRoute(destination.loc);//menjalankan fungsi tersebut, yaitu mencari rute
                }
                break;
            case 3:
                inputLocation(&currentLoc);//menjalankan fungsi tersebut, yaitu menentukan lokasi baru
                break;
            case 4:
                system("cls");
                printf("\n\n\n\n\n\n\n\n\n\n       __________________________________________________________________________________________________________\n");
				printf("\n\t\t\t\t\t\t     Terimakasih\n\n");
		    	printf("\t\t\t\t\t\t     -SMART MAP-\n");
		    	printf("       __________________________________________________________________________________________________________\n");
				getch();
				end=1;
                break;// mengakhiri program
        }

    }
    return 0;
}
