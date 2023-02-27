#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <string.h>


#define LEFT 75
#define DOWN 80
#define RIGHT 77
#define UP 72
#define SPACE 32



#define MAX_ROW 32
#define MAX_COL 115
#define V_ROW 16
#define V_COL 100

  

void gotoxy(int x, int y)
{
COORD coord;
coord.X = x;
coord.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

/* declaring prototypes */
void oras();
void loading();
void startMenu();
void ViruxMove();
void mazeOutline();	
void displayMaze();
void playerMove();
void characterMove();
void record();



/* initializing variables */
int x, y;
int curr_row=19, curr_col=67;//initialize the current row and column of the character.
int curr_rowx1=24, curr_colx1=78; //1st virux
int curr_rowx2=20, curr_colx2=46; //2nd virux
int curr_rowx3=19, curr_colx3=95; //3rd virux
int curr_rowx4=14, curr_colx4=77; //4th virux
int curr_rowx5=15, curr_colx5=67; //5th virux
int curr_rowx6=20, curr_colx6=57; //6th virux
int curr_rowx7=20, curr_colx7=70; //7th virux
int curr_rowx8=25, curr_colx8=67; //8th virux
int curr_rowx9=14, curr_colx9=57; //9th virux
int curr_rowx10=26, curr_colx10=57; //10th virux
char maze[MAX_ROW][MAX_COL]; 
int Virux = 88;


/* main function () */
int main(){
    time_t start=0;
    time_t currtime=0;
	
	srand(time(NULL));
	
	startMenu();
	loading();
	
	time(&start);
	do{	
	system("cls");
	
	time(&currtime);
	oras(currtime, start);
 		
		mazeOutline();
		displayMaze();
		ViruxMove();
      	playerMove();
	
	} while(maze[curr_row][curr_col]!=Virux);
	system("color 0F");
	
	int score;
	score=currtime-start;
		printf("GAME OVER. You have been infected by the ViruX\n");
		printf("\nScore: %d", score);
        printf("\nPress Enter to Continue.");
	
	int firstInput;
	firstInput = getch();//gets input from user
     
    
     
    while (firstInput!= 13){//will continue looping until the player presses enter(ASCII:13=enter).
    	firstInput = getch();//pressing enter signifies the start of the game.
    	}
	
	record(score);
	
	return 0; //program ended successfully
}

/* startMenu () */
void startMenu(){
		
     int firstInput;
	char o=32, f=219, a=186, b=187, c=188, d=200, e=201, g=205;
	
	char word_V[V_ROW][V_COL]={ //declare "word_V" as 2d array.
    	{o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,e,g,g,g,g,g,g,g,g,g,g,b,o,o,o,o,o,o,e,g,g,g,g,g,g,g,g,g,g,b,},				    	
		{o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,a,f,f,f,f,f,f,f,f,f,f,a,o,o,o,o,o,o,a,f,f,f,f,f,f,f,f,f,f,a,},
   		{o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,d,b,f,f,f,f,f,f,f,f,f,a,o,o,o,o,o,o,a,f,f,f,f,f,f,f,f,f,e,c,}, 
   		{o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,a,f,f,f,f,f,f,f,f,f,d,b,o,o,o,o,e,c,f,f,f,f,f,f,f,f,f,a,o,},
   		{o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,d,b,f,f,f,f,f,f,f,f,f,a,o,o,o,o,a,f,f,f,f,f,f,f,f,f,e,c,o,},
   		{o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,a,f,f,f,f,f,f,f,f,f,d,b,o,o,e,c,f,f,f,f,f,f,f,f,f,a,o,o,},
   		{o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,d,g,b,f,f,f,f,f,f,f,f,d,g,g,c,f,f,f,f,f,f,f,f,e,g,c,o,o,},
   		{o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,a,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,a,o,o,o,o,},
   		{o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,a,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,f,a,o,o,o,o,},
   		{o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,e,g,c,f,f,f,f,f,f,f,f,e,g,g,b,f,f,f,f,f,f,f,f,d,g,b,o,o,},
   		{o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,a,f,f,f,f,f,f,f,f,f,e,c,o,o,d,b,f,f,f,f,f,f,f,f,f,a,o,o,},
   		{o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,e,c,f,f,f,f,f,f,f,f,f,a,o,o,o,o,a,f,f,f,f,f,f,f,f,f,d,b,o,},
   		{o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,a,f,f,f,f,f,f,f,f,f,e,c,o,o,o,o,d,b,f,f,f,f,f,f,f,f,f,a,o,},
   		{o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,e,c,f,f,f,f,f,f,f,f,f,a,o,o,o,o,o,o,a,f,f,f,f,f,f,f,f,f,d,b,},
      	{o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,a,f,f,f,f,f,f,f,f,f,f,a,o,o,o,o,o,o,a,f,f,f,f,f,f,f,f,f,f,a,},
   		{o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,d,g,g,g,g,g,g,g,g,g,g,c,o,o,o,o,o,o,d,g,g,g,g,g,g,g,g,g,g,c,},
	};
	
	printf("\n\n"); 
    printf("                                                   W A R N I N G : Virus detected\n\n");
	system("color 0C");
	
		for(y=0;y<V_ROW; y++){//this loop display the 2d array "word_V"
			for(x=0;x<V_COL; x++){
				printf("%c", word_V[y][x]);
			}
			printf("\n");
		}
	

    printf("\n\n"); 
    printf("                                                                ViruX\n\n");
	printf ("                                                 -------Press Enter to Start-------");
	printf("\n\n");
    printf ("                                                         [GAME INFORMATION]");
    printf("\n\n");
    printf ("                                           The Virus X is spreading all over the place.\n");
	printf ("                                            You are the only one who is not infected.\n ");
	printf ("                                   Your task is not to touch or make any contact with the virus. \n ");
    printf ("                                       Otherwise, you will get infected and lose the game.\n\n");
    printf ("                                             You need to survive as long as possible.\n ");
    printf ("                                                  Good luck and travel safely.\n");
    printf("\n\n");
    printf ("                                                             [CONTROLS]");
    printf("\n\n");
    printf ("                                                       Use arrow keys to move");
    printf("\n\n\n");
    
	 
	firstInput = getch();//gets input from user
     
    
     
    while (firstInput!= 13){//will continue looping until the player presses enter(ASCII:13=enter).
    	firstInput = getch();//pressing enter signifies the start of the game.
    }
     
    system("cls");//clear the screen

}
/* startmenu end */


/* start of loading */
void loading() {
		int row,col,r,c,q,x;
		for (x=0;x<3;x++) {
		
			if (x==0) {
				gotoxy(64,14);
				printf("LOADING WORLD");
			}
		
			else if (x==1) {
				gotoxy(63,14);
				printf("LOADING VIRUXES");
			}
		
			else if (x==2) {
				gotoxy(62,14);
				printf("LOADING CHARACTER");
			}
		
			gotoxy(60,15);
			for(r=1;r<=20;r++){
			for(q=0;q<=30000000;q++);//to display the character loading
			printf("%c",219);
			}
		
		system("cls");
		}
		
		gotoxy(63,14);
		system("color 0C");
		printf("PREPARING GAME");
		
		gotoxy(60,15);
		for(r=1;r<=20;r++){
		for(q=0;q<=30000000;q++);//to display the character slowly
		printf("%c",219);}
		
		gotoxy(58,17);
		printf("Press any key to continue.");
		getch();
		system("cls");
}
/* loading end */


/*START OF "mazeOutline" FUNCTION*/
void mazeOutline(){
	int Virux = 88;
	int WALL_1 = 178;
	int WALL_2 = 219; 
	

	

	for (y = 20; y < MAX_COL; y++) {
  		for (x = 8; x < MAX_ROW; x++) {
  		
  			maze[x][y] = SPACE;//all parts of the maze will have spaces
  			maze[8][y] = WALL_1;//above straight line
         	maze[MAX_ROW - 1][y] = WALL_1;//below straight line
     		maze[x][20] = WALL_1; //left straight line
         	maze[x][MAX_COL-1] = WALL_1;//right straight line
      
  	   	}  		
     } 
     
    
       
   	    /* left side starts here */
    	//  || 
    	//  ||
    	//  || _
    	//  |  _
    	maze[15][39] = WALL_2;
    	maze[16][39] = WALL_2;
    	maze[17][39] = WALL_2;
    	maze[18][39] = WALL_2;
    	maze[19][39] = WALL_2;
        maze[20][39] = WALL_2;
        maze[20][40] = WALL_2;
        maze[20][41] = WALL_2;
        

        maze[20][42] = WALL_2;
        maze[20][43] = WALL_2;
        maze[20][44] = WALL_2;
        maze[20][45] = WALL_2;
        
        /* right side starts here */
        
        //   ||
        //   ||
        // _ ||
        // _  |
       	maze[15][93] = WALL_2;
    	maze[17][93] = WALL_2;
    	maze[16][93] = WALL_2;
    	maze[18][93] = WALL_2;
        maze[19][93] = WALL_2;
        maze[20][92] = WALL_2;
        maze[20][93] = WALL_2;
        
        
        maze[20][91] = WALL_2;
        maze[20][90] = WALL_2;
        maze[20][89] = WALL_2;
        maze[20][88] = WALL_2;
        maze[20][87] = WALL_2;
	
     //  ||
     //  ||___
   
    	maze[25][63] = WALL_2;
    	maze[25][62] = WALL_2;
    	maze[25][61] = WALL_2;
    	maze[25][60] = WALL_2;
    	maze[25][59] = WALL_2;
    	maze[25][58] = WALL_2;
    	maze[25][57] = WALL_2;
    	maze[25][56] = WALL_2;
    	

    	maze[22][57] = WALL_2;
    	maze[22][56] = WALL_2;
    	maze[23][57] = WALL_2;
    	maze[23][56] = WALL_2;
    	maze[24][57] = WALL_2;
    	maze[24][56] = WALL_2;
    	
     //     ||
     //  ___||
		
		
    	maze[25][77] = WALL_2;
    	maze[25][70] = WALL_2;
    	maze[25][71] = WALL_2;
    	maze[25][72] = WALL_2;
    	maze[25][73] = WALL_2;
    	maze[25][74] = WALL_2;
    	maze[25][75] = WALL_2;
    	maze[25][76] = WALL_2;
    
    	

    	maze[22][77] = WALL_2;
    	maze[22][76] = WALL_2;
    	maze[23][77] = WALL_2;
    	maze[23][76] = WALL_2;
    	maze[24][77] = WALL_2;
    	maze[24][76] = WALL_2;
    	
    // |----
    // ||
    // ||
        maze[15][63] = WALL_2;
    	maze[15][62] = WALL_2;
    	maze[15][61] = WALL_2;
    	maze[15][60] = WALL_2;
    	maze[15][59] = WALL_2;
    	maze[15][58] = WALL_2;
    	maze[15][57] = WALL_2;
    	maze[15][56] = WALL_2;
    	

    	maze[16][57] = WALL_2;
    	maze[16][56] = WALL_2;
    	maze[17][57] = WALL_2;
    	maze[17][56] = WALL_2;
    	maze[18][57] = WALL_2;
    	maze[18][56] = WALL_2;
   		
     // ---- |
     //     ||
     //     ||
        maze[15][77] = WALL_2;
    	maze[15][70] = WALL_2;
    	maze[15][71] = WALL_2;
    	maze[15][72] = WALL_2;
    	maze[15][73] = WALL_2;
    	maze[15][74] = WALL_2;
    	maze[15][75] = WALL_2;
    	maze[15][76] = WALL_2;
    	

    	maze[16][77] = WALL_2;
    	maze[16][76] = WALL_2;
    	maze[17][77] = WALL_2;
    	maze[17][76] = WALL_2;
    	maze[18][77] = WALL_2;
    	maze[18][76] = WALL_2;
     
     // left side
        maze[10][29] = WALL_2;
        maze[10][28] = WALL_2;
        maze[10][27] = WALL_2;
        maze[10][26] = WALL_2;
        maze[10][25] = WALL_2;
        maze[10][24] = WALL_2;
        maze[10][23] = WALL_2;
        maze[10][22] = WALL_2;
        maze[11][22] = WALL_2;
        maze[12][22] = WALL_2;
        maze[13][22] = WALL_2;
        maze[14][22] = WALL_2;
        maze[15][22] = WALL_2;
        maze[16][22] = WALL_2;
        maze[17][22] = WALL_2;
        maze[18][22] = WALL_2;
        maze[18][23] = WALL_2;
        maze[18][24] = WALL_2;
        maze[18][25] = WALL_2;
        maze[18][26] = WALL_2;
        maze[18][27] = WALL_2;
        maze[18][28] = WALL_2;
        maze[18][29] = WALL_2;
        maze[18][31] = WALL_2;
        maze[18][32] = WALL_2;
        maze[18][33] = WALL_2;
        maze[18][34] = WALL_2;
        maze[18][35] = WALL_2;
        maze[18][36] = WALL_2;
       
        maze[18][37] = WALL_2;
        maze[17][37] = WALL_2;
        maze[16][37] = WALL_2;
        maze[15][37] = WALL_2;

        maze[13][37] = WALL_2;
        maze[13][38] = WALL_2;
        maze[13][39] = WALL_2;
        maze[13][40] = WALL_2;
        maze[13][41] = WALL_2;
        maze[12][39] = WALL_2;
        
        maze[12][25] = WALL_2;
        maze[13][25] = WALL_2;
        maze[14][25] = WALL_2;
        maze[15][25] = WALL_2;
        maze[16][25] = WALL_2;
        maze[12][26] = WALL_2;
        maze[12][27] = WALL_2;
        maze[12][28] = WALL_2;
        maze[12][29] = WALL_2;
        maze[16][26] = WALL_2;
        maze[16][27] = WALL_2;
        maze[16][28] = WALL_2;
        maze[16][29] = WALL_2;
        maze[16][30] = WALL_2;
        maze[16][31] = WALL_2;
        maze[16][32] = WALL_2;
        maze[16][33] = WALL_2;
        maze[16][34] = WALL_2;
        maze[15][34] = WALL_2;
        maze[14][34] = WALL_2;
        maze[13][34] = WALL_2;
        maze[12][34] = WALL_2;
        maze[11][34] = WALL_2;
        maze[10][34] = WALL_2;
        
        maze[10][36] = WALL_2;
        maze[10][37] = WALL_2;
        maze[10][38] = WALL_2;
        maze[10][39] = WALL_2;
        maze[10][40] = WALL_2;
        maze[10][41] = WALL_2;
        maze[10][42] = WALL_2;
        maze[10][43] = WALL_2;
        maze[10][44] = WALL_2;
        
   	    maze[11][45] = WALL_2;
   	    maze[11][45] = WALL_2;
   	    maze[11][45] = WALL_2;
   	    maze[11][45] = WALL_2;
        maze[10][45] = WALL_2;
    	maze[10][44] = WALL_2;
    	maze[10][43] = WALL_2;
    	maze[10][42] = WALL_2;
    	maze[10][41] = WALL_2;
    	maze[10][40] = WALL_2;

        maze[14][28] = WALL_2;
        maze[14][29] = WALL_2;
        maze[14][30] = WALL_2;
        maze[14][31] = WALL_2;
        maze[13][31] = WALL_2;
        maze[12][31] = WALL_2;
        maze[11][31] = WALL_2;
        maze[10][31] = WALL_2;
        
        maze[12][45] = WALL_2;
        maze[11][45] = WALL_2;
        maze[10][45] = WALL_2;
        
        maze[13][45] = WALL_2;
        maze[14][45] = WALL_2;
        maze[15][45] = WALL_2;
        maze[15][44] = WALL_2;
        maze[15][43] = WALL_2;
        maze[15][42] = WALL_2;
        maze[16][42] = WALL_2;
        maze[17][42] = WALL_2;
        maze[17][43] = WALL_2;
        maze[17][44] = WALL_2;
        maze[17][45] = WALL_2;
        maze[17][46] = WALL_2;
        maze[17][47] = WALL_2;
        maze[16][47] = WALL_2;
        maze[15][47] = WALL_2;
        maze[14][47] = WALL_2;
        maze[12][47] = WALL_2;
        maze[11][47] = WALL_2;
        maze[10][47] = WALL_2;
        maze[10][48] = WALL_2;
        maze[10][49] = WALL_2;
        maze[10][50] = WALL_2;
        maze[10][51] = WALL_2;
        maze[10][52] = WALL_2;
        maze[10][53] = WALL_2;
        maze[10][54] = WALL_2;
        maze[10][56] = WALL_2;
        maze[10][57] = WALL_2;
        maze[10][58] = WALL_2;
        maze[10][59] = WALL_2;
        maze[10][60] = WALL_2;
        maze[10][61] = WALL_2;
        maze[10][62] = WALL_2;
        maze[10][63] = WALL_2;
        
        /* left break stops at entrance */

        maze[20][22] = WALL_2;
        maze[20][23] = WALL_2;
        maze[20][24] = WALL_2;
        maze[20][25] = WALL_2;
        maze[21][25] = WALL_2;
        maze[22][25] = WALL_2;
        maze[22][26] = WALL_2;
        maze[22][27] = WALL_2;
        maze[21][27] = WALL_2;
        maze[20][27] = WALL_2;
        maze[20][28] = WALL_2;
        maze[20][29] = WALL_2;
        maze[20][30] = WALL_2;
        maze[20][31] = WALL_2;
        maze[20][32] = WALL_2;
        maze[20][34] = WALL_2;
        maze[20][35] = WALL_2;
        maze[20][36] = WALL_2;
        maze[20][37] = WALL_2;
        maze[20][38] = WALL_2;
        maze[21][39] = WALL_2;
        maze[22][39] = WALL_2;
        maze[23][39] = WALL_2;
        maze[24][39] = WALL_2;
        maze[24][38] = WALL_2;
        maze[24][37] = WALL_2;
        maze[24][36] = WALL_2;
        maze[23][36] = WALL_2;
        maze[22][36] = WALL_2;
        maze[22][35] = WALL_2;
        maze[22][34] = WALL_2;
        maze[22][33] = WALL_2;
        maze[22][32] = WALL_2;
        maze[22][31] = WALL_2;
        maze[22][30] = WALL_2;
        
        maze[22][22] = WALL_2;
        maze[23][22] = WALL_2;
        maze[24][22] = WALL_2;
        maze[24][23] = WALL_2;
        maze[24][24] = WALL_2;
        maze[24][25] = WALL_2;
        
        maze[24][27] = WALL_2;
        maze[24][28] = WALL_2;
        maze[24][29] = WALL_2;
        maze[24][30] = WALL_2;
        maze[23][30] = WALL_2;

        maze[26][22] = WALL_2;
        maze[26][23] = WALL_2;
        maze[26][24] = WALL_2;
        maze[26][25] = WALL_2;
        maze[26][26] = WALL_2;
        maze[26][27] = WALL_2;
        maze[26][28] = WALL_2;
        maze[26][29] = WALL_2;
        maze[26][30] = WALL_2;
        maze[26][31] = WALL_2;
        maze[27][31] = WALL_2;
        
        maze[28][31] = WALL_2;
        maze[29][31] = WALL_2;
        maze[29][32] = WALL_2;
        maze[29][33] = WALL_2;
        maze[29][34] = WALL_2;
        maze[29][35] = WALL_2;
        maze[29][36] = WALL_2;
        maze[29][37] = WALL_2;
        
        maze[27][22] = WALL_2;
        maze[28][22] = WALL_2;
        maze[29][22] = WALL_2;
        maze[29][23] = WALL_2;
        maze[29][24] = WALL_2;
        maze[28][24] = WALL_2;
        maze[28][25] = WALL_2;
        maze[28][26] = WALL_2;
        maze[28][27] = WALL_2;
        maze[28][28] = WALL_2;
        maze[29][28] = WALL_2;
        
        maze[30][28] = WALL_2;
        maze[28][37] = WALL_2;
        maze[27][37] = WALL_2;
        maze[26][37] = WALL_2;
        maze[26][36] = WALL_2;
        maze[26][35] = WALL_2;
        maze[26][34] = WALL_2;
        maze[26][33] = WALL_2;
        maze[27][33] = WALL_2;
        
        maze[26][39] = WALL_2;
        maze[27][39] = WALL_2;
        maze[26][39] = WALL_2;
        maze[28][39] = WALL_2;
        maze[29][39] = WALL_2;
        maze[29][40] = WALL_2;
        maze[29][41] = WALL_2;
        maze[29][42] = WALL_2;
        maze[28][42] = WALL_2;
        maze[27][42] = WALL_2;
        maze[26][42] = WALL_2;
        maze[25][42] = WALL_2;
        maze[24][42] = WALL_2;
        maze[23][42] = WALL_2;
        maze[22][42] = WALL_2;
        maze[22][43] = WALL_2;
        maze[22][42] = WALL_2;
        maze[22][43] = WALL_2;
        maze[22][44] = WALL_2;
        maze[22][45] = WALL_2;
        maze[23][45] = WALL_2;
        maze[24][45] = WALL_2;
        maze[24][46] = WALL_2;
        maze[24][47] = WALL_2;
        maze[23][47] = WALL_2;
        maze[22][47] = WALL_2;
        maze[21][47] = WALL_2;
        maze[20][47] = WALL_2;
        maze[20][49] = WALL_2;
        maze[21][49] = WALL_2;
        maze[22][49] = WALL_2;
        maze[23][49] = WALL_2;
        maze[24][49] = WALL_2;
        maze[25][49] = WALL_2;
        maze[26][49] = WALL_2;
        maze[26][48] = WALL_2;
        maze[26][47] = WALL_2;
        maze[26][46] = WALL_2;
        maze[26][45] = WALL_2;
        maze[27][45] = WALL_2;
        maze[28][45] = WALL_2;
        maze[29][45] = WALL_2;
        maze[29][47] = WALL_2;
        maze[29][48] = WALL_2;
        maze[29][49] = WALL_2;
        maze[29][50] = WALL_2;
        maze[28][50] = WALL_2;
        
        /* right part starts here */
        maze[10][112] = WALL_2;
        maze[10][111] = WALL_2;
        maze[10][110] = WALL_2;
        maze[10][109] = WALL_2;
        maze[10][108] = WALL_2;
        maze[10][107] = WALL_2;
        maze[10][106] = WALL_2;
        maze[10][105] = WALL_2;
        maze[11][112] = WALL_2;
        maze[12][112] = WALL_2;
        maze[13][112] = WALL_2;
        maze[14][112] = WALL_2;
        maze[15][112] = WALL_2;
        maze[16][112] = WALL_2;
        maze[17][112] = WALL_2;
        maze[18][112] = WALL_2;
        maze[18][105] = WALL_2;
        maze[18][106] = WALL_2;
        maze[18][107] = WALL_2;
        maze[18][108] = WALL_2;
        maze[18][109] = WALL_2;
        maze[18][110] = WALL_2;
        maze[18][111] = WALL_2;
        maze[18][101] = WALL_2;
        maze[18][102] = WALL_2;
        maze[18][103] = WALL_2;
        maze[18][100] = WALL_2;
        maze[18][99] = WALL_2;
        maze[18][98] = WALL_2;
        maze[18][97] = WALL_2;
        maze[18][96] = WALL_2;
        maze[18][95] = WALL_2;
        maze[17][95] = WALL_2;
        maze[16][95] = WALL_2;
        maze[15][95] = WALL_2;
        
        maze[13][91] = WALL_2;
        maze[13][95] = WALL_2;
        maze[13][94] = WALL_2;
        maze[13][93] = WALL_2;
        maze[13][92] = WALL_2;
        maze[12][93] = WALL_2;
        
        maze[12][109] = WALL_2;
        maze[12][108] = WALL_2;
        maze[12][107] = WALL_2;
        maze[12][106] = WALL_2;
        maze[12][105] = WALL_2;
        maze[13][109] = WALL_2;
        maze[14][109] = WALL_2;
        maze[15][109] = WALL_2;
        maze[16][109] = WALL_2;
        maze[16][108] = WALL_2;
        maze[16][107] = WALL_2;
        maze[16][106] = WALL_2;
        maze[16][105] = WALL_2;
        maze[16][104] = WALL_2;
        maze[16][103] = WALL_2;
        maze[16][102] = WALL_2;
        maze[16][101] = WALL_2;
        maze[16][100] = WALL_2;
        maze[16][99] = WALL_2;
        maze[16][98] = WALL_2;
        maze[15][98] = WALL_2;
        maze[14][98] = WALL_2;
        maze[13][98] = WALL_2;
        maze[12][98] = WALL_2;
        maze[11][98] = WALL_2;
        maze[10][98] = WALL_2;
        
        maze[10][102] = WALL_2;
        maze[11][102] = WALL_2;
        maze[12][102] = WALL_2;
        maze[13][102] = WALL_2;
        maze[14][102] = WALL_2;
        maze[14][103] = WALL_2;
        maze[14][104] = WALL_2;
        maze[14][105] = WALL_2;
        maze[14][106] = WALL_2;
        
        maze[10][96] = WALL_2;
        maze[10][95] = WALL_2;
        maze[10][94] = WALL_2;
        maze[10][93] = WALL_2;
        maze[10][92] = WALL_2;
        maze[10][91] = WALL_2;
        maze[10][90] = WALL_2;
        maze[10][89] = WALL_2;
        maze[10][88] = WALL_2;
        maze[10][87] = WALL_2;
   	    maze[11][87] = WALL_2;
   	    maze[12][87] = WALL_2;
   	    maze[13][87] = WALL_2;
   	    maze[14][87] = WALL_2;
   	    maze[15][87] = WALL_2;
   	    maze[15][88] = WALL_2;
   	    maze[15][89] = WALL_2;
   	    maze[15][90] = WALL_2;
   	    maze[16][90] = WALL_2;
   	    maze[17][90] = WALL_2;
   	    maze[17][89] = WALL_2;
   	    maze[17][88] = WALL_2;
   	    maze[17][87] = WALL_2;
   	    maze[17][86] = WALL_2;
   	    maze[17][85] = WALL_2;
   	    maze[16][85] = WALL_2;
   	    maze[15][85] = WALL_2;
   	    maze[14][85] = WALL_2;
   	    
   	    maze[12][85] = WALL_2;
   	    maze[11][85] = WALL_2;
   	    maze[10][85] = WALL_2;
   	    maze[10][84] = WALL_2;
   	    maze[10][83] = WALL_2;
   	    maze[10][82] = WALL_2;
   	    maze[10][81] = WALL_2;
   	    maze[10][80] = WALL_2;
   	    maze[10][79] = WALL_2;
   	    maze[10][78] = WALL_2;
   	    
   	    maze[10][76] = WALL_2;
   	    maze[10][75] = WALL_2;
   	    maze[10][74] = WALL_2;
   	    maze[10][73] = WALL_2;
   	    maze[10][72] = WALL_2;
   	    maze[10][71] = WALL_2;
   	    maze[10][70] = WALL_2;
   	    
   	    maze[20][112] = WALL_2;
   	    maze[20][111] = WALL_2;
   	    maze[20][110] = WALL_2;
   	    maze[20][109] = WALL_2;
   	    maze[21][109] = WALL_2;
   	    maze[22][109] = WALL_2;
   	    maze[22][108] = WALL_2;
   	    maze[22][107] = WALL_2;
   	    maze[21][107] = WALL_2;
   	    maze[20][107] = WALL_2;
   	    maze[20][106] = WALL_2;
   	    maze[20][105] = WALL_2;
   	    maze[20][104] = WALL_2;
   	    maze[20][103] = WALL_2;
   	    maze[20][102] = WALL_2;
   	    maze[20][100] = WALL_2;
   	    maze[20][99] = WALL_2;
   	    maze[20][98] = WALL_2;
   	    maze[20][97] = WALL_2;
   	    maze[20][96] = WALL_2;
   	    maze[20][95] = WALL_2;
   	    maze[20][94] = WALL_2;
   	    
   	    maze[22][112] = WALL_2;
   	    maze[23][112] = WALL_2;
   	    maze[24][112] = WALL_2;
   	    maze[24][111] = WALL_2;
   	    maze[24][110] = WALL_2;
   	    maze[24][109] = WALL_2;
   	    maze[24][107] = WALL_2;
   	    maze[24][106] = WALL_2;
   	    maze[24][105] = WALL_2;
   	    maze[24][104] = WALL_2;
   	    maze[23][104] = WALL_2;
   	    maze[22][104] = WALL_2;
   	    maze[22][103] = WALL_2;
   	    maze[22][102] = WALL_2;
   	    maze[22][101] = WALL_2;
   	    maze[22][100] = WALL_2;
   	    maze[22][99] = WALL_2;
   	    maze[22][98] = WALL_2;
   	    maze[22][97] = WALL_2;
   	    maze[22][96] = WALL_2;
   	    maze[23][96] = WALL_2;
   	    maze[24][96] = WALL_2;
   	    maze[24][95] = WALL_2;
   	    maze[24][94] = WALL_2;
   	    maze[24][93] = WALL_2;
   	    maze[23][93] = WALL_2;
   	    maze[22][93] = WALL_2;
   	    maze[21][93] = WALL_2;
   	    maze[20][93] = WALL_2;
   	    
   	    maze[20][85] = WALL_2;
   	    maze[21][85] = WALL_2;
   	    maze[22][85] = WALL_2;
   	    maze[23][85] = WALL_2;
   	    maze[24][85] = WALL_2;
   	    maze[24][86] = WALL_2;
   	    maze[24][87] = WALL_2;
   	    maze[24][88] = WALL_2;
   	    maze[23][88] = WALL_2;
   	    maze[22][88] = WALL_2;
   	    maze[22][89] = WALL_2;
   	    maze[22][90] = WALL_2;
   	    maze[23][90] = WALL_2;
   	    maze[25][90] = WALL_2;
   	    maze[24][90] = WALL_2;
   	    maze[26][90] = WALL_2;
   	    maze[27][90] = WALL_2;
   	    maze[28][90] = WALL_2;
   	    maze[29][90] = WALL_2;
   	    maze[29][91] = WALL_2;
   	    maze[29][92] = WALL_2;
   	    maze[29][93] = WALL_2;
   	    maze[28][93] = WALL_2;
   	    maze[27][93] = WALL_2;
   	    maze[26][93] = WALL_2;
   	    
   	    maze[20][83] = WALL_2;
   	    maze[21][83] = WALL_2;
   	    maze[22][83] = WALL_2;
   	    maze[23][83] = WALL_2;
   	    maze[24][83] = WALL_2;
   	    maze[25][83] = WALL_2;
   	    maze[26][83] = WALL_2;
   	    maze[26][84] = WALL_2;
   	    maze[26][85] = WALL_2;
   	    maze[26][86] = WALL_2;
   	    maze[26][87] = WALL_2;
   	    maze[26][88] = WALL_2;
   	    maze[27][88] = WALL_2;
   	    maze[28][88] = WALL_2;
   	    maze[29][88] = WALL_2;
   	    
   	    maze[29][86] = WALL_2;
   	    maze[29][85] = WALL_2;
   	    maze[29][84] = WALL_2;
   	    maze[29][83] = WALL_2;
   	    maze[29][82] = WALL_2;
   	    maze[28][82] = WALL_2;
   	    
   	    maze[26][112] = WALL_2;
   	    maze[26][111] = WALL_2;
   	    maze[26][110] = WALL_2;
   	    maze[26][109] = WALL_2;
   	    maze[26][108] = WALL_2;
   	    maze[26][107] = WALL_2;
   	    maze[26][106] = WALL_2;
   	    maze[26][105] = WALL_2;
   	    maze[26][104] = WALL_2;
   	    maze[26][103] = WALL_2;
   	    maze[27][103] = WALL_2;
   	    maze[28][103] = WALL_2;
   	    maze[29][103] = WALL_2;
   	    maze[29][102] = WALL_2;
   	    maze[29][101] = WALL_2;
   	    maze[29][100] = WALL_2;
   	    maze[29][99] = WALL_2;
   	    maze[29][98] = WALL_2;
   	    maze[29][97] = WALL_2;
   	    maze[29][96] = WALL_2;
   	    maze[29][95] = WALL_2;
   	    maze[28][95] = WALL_2;
   	    maze[27][95] = WALL_2;
   	    maze[26][95] = WALL_2;
   	    maze[26][96] = WALL_2;
   	    maze[26][97] = WALL_2;
   	    maze[26][98] = WALL_2;
   	    maze[26][99] = WALL_2;
   	    maze[26][100] = WALL_2;
   	    maze[26][101] = WALL_2;
   	    maze[27][101] = WALL_2;
   	    
   	    maze[27][112] = WALL_2;
   	    maze[28][112] = WALL_2;
   	    maze[29][112] = WALL_2;
   	    maze[29][111] = WALL_2;
   	    maze[29][110] = WALL_2;
   	    maze[28][110] = WALL_2;
   	    maze[28][109] = WALL_2;
   	    maze[28][108] = WALL_2;
   	    maze[28][107] = WALL_2;
   	    maze[28][106] = WALL_2;
   	    maze[29][106] = WALL_2;
   	    maze[30][106] = WALL_2;
   	    
}
/*END OF "mazeOutline" FUNCTION*/



/*START OF "displayMaze" FUNCTION*/
void displayMaze(){
	
	char user = 5;//symbol of the chracter
	maze[curr_row][curr_col]= user;//displays the current row and column of the character
	maze[curr_rowx1][curr_colx1] = 'X'; //displays the current row and column of the viruxes starting here:
	maze[curr_rowx2][curr_colx2] = 'X';
	maze[curr_rowx3][curr_colx3] = 'X';
	maze[curr_rowx4][curr_colx4] = 'X';
	maze[curr_rowx5][curr_colx5] = 'X';
	maze[curr_rowx6][curr_colx6] = 'X';
	maze[curr_rowx7][curr_colx7] = 'X';
	maze[curr_rowx8][curr_colx8] = 'X';
	maze[curr_rowx9][curr_colx9] = 'X';
	maze[curr_rowx10][curr_colx10] = 'X'; //and ends here.
	
	for(y=0;y<MAX_ROW; y++){//displays the outline of the maze
		for(x=0;x<MAX_COL; x++){
			printf("%c", maze[y][x]);
		}
		printf("\n");
	}
	
}
/* END of displayMaze */


/*START of playerMove */
void playerMove(){
	int inputMove;
	
	if (kbhit()) {
		
		
	inputMove=getch();//get the chosen movement of the player
	
	switch(inputMove){
	
		case LEFT:
	
			if (maze[curr_row][curr_col-1] == SPACE || maze[curr_row][curr_col-1] == Virux){ 
				curr_col--;//decreases the current column by 1(for the character to go left)
			}
			break;
				
		case RIGHT:
	
			if (maze[curr_row][curr_col+1] == SPACE || maze[curr_row][curr_col+1] == Virux){ 
				curr_col++;//increases the current column by 1(for the character to go right)
			}
			break;
			
		case DOWN:
			
			if (maze[curr_row+1][curr_col] == SPACE || maze[curr_row+1][curr_col] == Virux){ 
				curr_row++;//increases the current row by 1(for the character to go down)
			}
			break;
				
		case UP:
			
			if (maze[curr_row-1][curr_col] == SPACE || maze[curr_row-1][curr_col] == Virux){
				curr_row--;//decreases the current row by 1(for the character to go up)
			}
			break;		
	
	}
	}
	else
	inputMove=' ';
	
}	
	

void record(score){
char name[20], cname[20], cha, c;
int i, j, px;
FILE *info;
info=fopen("record.txt","a+");

system("cls");
printf("Enter your name:\n");
gets(name);

for(j=0;name[j]!='\0';j++){ //to convert the first letter after space to capital
cname[0]=toupper(name[0]);
if(name[j-1]==' '){
cname[j]=toupper(name[j]);
cname[j-1]=name[j-1];}
else cname[j]=name[j];
}
cname[j]='\0';

fprintf(info,"Player Name :%s\n", cname);
fprintf(info,"Score :%d\n",score);

//for date and time
time_t mytime;
mytime = time(NULL);

fprintf(info,"Played Date:%s",ctime(&mytime));

for(i=0;i<=50;i++)
fprintf(info,"%c",'_'); //seperates previous score and present score by the character: _
fprintf(info,"\n");
fclose(info);

printf("\nWant to see past Scores? Press (y/n)\n");
cha=getch();
system("cls");

	if(cha=='y'){
		info=fopen("record.txt","r");
		do{
			putchar(c=getc(info));
		}while(c!=EOF);

	printf("Press Enter to exit.");
		int firstInput;
			
			firstInput = getch();//gets input from user
     
	 
	 	while (firstInput!= 13){//will continue looping until the player presses enter(ASCII:13=enter).
    		firstInput = getch();//pressing enter signifies the start of the game.
    	}
	}

fclose(info);
}

void ViruxMove(){
	

	int inputMove;
	
	inputMove=rand()%4+1;//get the chosen movement of the player
	
	//Virux1
	
	switch(inputMove){
	
		case 1:
	
			if (maze[curr_rowx1][curr_colx1-1] == SPACE || maze[curr_rowx1][curr_colx1-1] == maze[curr_row][curr_col]){
				curr_colx1--;
			}
			break;
				
		case 2:
	
			if (maze[curr_rowx1][curr_colx1+1] == SPACE || maze[curr_rowx1][curr_colx1+1] == maze[curr_row][curr_col]){
				curr_colx1++;
			}
			break;
			
		case 3:
			
			if (maze[curr_rowx1+1][curr_colx1] == SPACE || maze[curr_rowx1+1][curr_colx1] == maze[curr_row][curr_col]){
				curr_rowx1++;
			}
			break;
				
		case 4:
			
			if (maze[curr_rowx1-1][curr_colx1] == SPACE || maze[curr_rowx1-1][curr_colx1] == maze[curr_row][curr_col]){
				curr_rowx1--;
			}
			break;		
	}	
	
	//Virux2
	
	switch(inputMove){
	
		case 2:
	
			if (maze[curr_rowx2][curr_colx2-1] == SPACE || maze[curr_rowx2][curr_colx2-1] == maze[curr_row][curr_col]){
				curr_colx2--;
			}
			break;
				
		case 1:
	
			if (maze[curr_rowx2][curr_colx2+1] == SPACE || maze[curr_rowx2][curr_colx2+1] == maze[curr_row][curr_col]){
				curr_colx2++;
			}
			break;
			
		case 3:
			
			if (maze[curr_rowx2+1][curr_colx2] == SPACE || maze[curr_rowx2+1][curr_colx2] == maze[curr_row][curr_col]){
				curr_rowx2++;
			}
			break;
				
		case 4:
			
			if (maze[curr_rowx2-1][curr_colx2] == SPACE || maze[curr_rowx2-1][curr_colx2] == maze[curr_row][curr_col]){
				curr_rowx2--;
			}
			break;		
	}	
	
	//Virux3
	
	switch(inputMove){
	
		case 1:
	
			if (maze[curr_rowx3][curr_colx3-1] == SPACE || maze[curr_rowx3][curr_colx3-1] == maze[curr_row][curr_col]){ 
				curr_colx3--; 
			}
			break;
				
		case 2:
	
			if (maze[curr_rowx3][curr_colx3+1] == SPACE || maze[curr_rowx3][curr_colx3+1] == maze[curr_row][curr_col]){ 
				curr_colx3++;
			}
			break;
			
		case 4:
			
			if (maze[curr_rowx3+1][curr_colx3] == SPACE || maze[curr_rowx3+1][curr_colx3] == maze[curr_row][curr_col]){ 
				curr_rowx3++;
			}
			break;
				
		case 3:
			
			if (maze[curr_rowx3-1][curr_colx3] == SPACE || maze[curr_rowx3-1][curr_colx3] == maze[curr_row][curr_col]){ 
				curr_rowx3--;
			}
			break;		
	}
	
	//Virux4
	
	switch(inputMove){
	
		case 3:
	
			if (maze[curr_rowx4][curr_colx4-1] == SPACE || maze[curr_rowx4][curr_colx4-1] == maze[curr_row][curr_col]){ 
				curr_colx4--; 
			}
			break;
				
		case 2:
	
			if (maze[curr_rowx4][curr_colx4+1] == SPACE || maze[curr_rowx4][curr_colx4+1] == maze[curr_row][curr_col]){ 
				curr_colx4++;
			}
			break;
			
		case 1:
			
			if (maze[curr_rowx4+1][curr_colx4] == SPACE || maze[curr_rowx4+1][curr_colx4] == maze[curr_row][curr_col]){
				curr_rowx4++;
			}
			break;
				
		case 4:
			
			if (maze[curr_rowx4-1][curr_colx4] == SPACE || maze[curr_rowx4-1][curr_colx4] == maze[curr_row][curr_col]){
				curr_rowx4--;
			}
			break;		
	}
	
	//virux5
	
	switch(inputMove){
	
		case 1:
	
			if (maze[curr_rowx5][curr_colx5-1] == SPACE || maze[curr_rowx5][curr_colx5-1] == maze[curr_row][curr_col]){
				curr_colx5--;
			}
			break;
				
		case 4:
	
			if (maze[curr_rowx5][curr_colx5+1] == SPACE || maze[curr_rowx5][curr_colx5+1] == maze[curr_row][curr_col]){
				curr_colx5++;
			}
			break;
			
		case 3:
			
			if (maze[curr_rowx5+1][curr_colx5] == SPACE || maze[curr_rowx5+1][curr_colx5] == maze[curr_row][curr_col]){
				curr_rowx5++;
			}
			break;
				
		case 2:
			
			if (maze[curr_rowx5-1][curr_colx5] == SPACE || maze[curr_rowx5-1][curr_colx5] == maze[curr_row][curr_col]){
				curr_rowx5--;
			}
			break;		
	}
	
	//virux6
	
	switch(inputMove){
	
		case 4:
	
			if (maze[curr_rowx6][curr_colx6-1] == SPACE || maze[curr_rowx6][curr_colx6-1] == maze[curr_row][curr_col]){
				curr_colx6--;
			}
			break;
				
		case 2:
	
			if (maze[curr_rowx6][curr_colx6+1] == SPACE || maze[curr_rowx6][curr_colx6+1] == maze[curr_row][curr_col]){
				curr_colx6++;
			}
			break;
			
		case 3:
			
			if (maze[curr_rowx6+1][curr_colx6] == SPACE || maze[curr_rowx6+1][curr_colx6] == maze[curr_row][curr_col]){
				curr_rowx6++;
			}
			break;
				
		case 1:
			
			if (maze[curr_rowx6-1][curr_colx6] == SPACE || maze[curr_rowx6-1][curr_colx6] == maze[curr_row][curr_col]){
				curr_rowx6--;
			}
			break;		
	}
	
	//virux7
	
	switch(inputMove){
	
		case 1:
	
			if (maze[curr_rowx7][curr_colx7-1] == SPACE || maze[curr_rowx7][curr_colx7-1] == maze[curr_row][curr_col]){
				curr_colx7--;
			}
			break;
				
		case 3:
	
			if (maze[curr_rowx7][curr_colx7+1] == SPACE || maze[curr_rowx7][curr_colx7+1] == maze[curr_row][curr_col]){
				curr_colx7++;
			}
			break;
			
		case 2:
			
			if (maze[curr_rowx7+1][curr_colx7] == SPACE || maze[curr_rowx7+1][curr_colx7] == maze[curr_row][curr_col]){
				curr_rowx7++;
			}
			break;
				
		case 4:
			
			if (maze[curr_rowx7-1][curr_colx7] == SPACE || maze[curr_rowx7-1][curr_colx7] == maze[curr_row][curr_col]){
				curr_rowx7--;
			}
			break;		
	}
	
	//virux8
	
	switch(inputMove){
	
		case 2:
	
			if (maze[curr_rowx8][curr_colx8-1] == SPACE || maze[curr_rowx8][curr_colx8-1] == maze[curr_row][curr_col]){
				curr_colx8--;
			}
			break;
				
		case 1:
	
			if (maze[curr_rowx8][curr_colx8+1] == SPACE || maze[curr_rowx8][curr_colx8+1] == maze[curr_row][curr_col]){
				curr_colx8++;
			}
			break;
			
		case 4:
			
			if (maze[curr_rowx8+1][curr_colx8] == SPACE || maze[curr_rowx8+1][curr_colx8] == maze[curr_row][curr_col]){
				curr_rowx8++;
			}
			break;
				
		case 3:
			
			if (maze[curr_rowx8-1][curr_colx8] == SPACE || maze[curr_rowx8-1][curr_colx8] == maze[curr_row][curr_col]){
				curr_rowx8--;
			}
			break;		
	}
	
	//virux9
	
	switch(inputMove){
	
		case 3:
	
			if (maze[curr_rowx9][curr_colx9-1] == SPACE || maze[curr_rowx9][curr_colx9-1] == maze[curr_row][curr_col]){
				curr_colx9--;
			}
			break;
				
		case 4:
	
			if (maze[curr_rowx9][curr_colx9+1] == SPACE || maze[curr_rowx9][curr_colx9+1] == maze[curr_row][curr_col]){
				curr_colx9++;
			}
			break;
			
		case 1:
			
			if (maze[curr_rowx9+1][curr_colx9] == SPACE || maze[curr_rowx9+1][curr_colx9] == maze[curr_row][curr_col]){
				curr_rowx9++;
			}
			break;
				
		case 2:
			
			if (maze[curr_rowx9-1][curr_colx9] == SPACE || maze[curr_rowx9-1][curr_colx9] == maze[curr_row][curr_col]){
				curr_rowx9--;
			}
			break;		
	}
	
	//virux10
	
	switch(inputMove){
	
		case 2:
	
			if (maze[curr_rowx10][curr_colx10-1] == SPACE || maze[curr_rowx10][curr_colx10-1] == maze[curr_row][curr_col]){
				curr_colx10--;
			}
			break;
				
		case 4:
	
			if (maze[curr_rowx10][curr_colx10+1] == SPACE || maze[curr_rowx10][curr_colx10+1] == maze[curr_row][curr_col]){
				curr_colx10++;
			}
			break;
			
		case 3:
			
			if (maze[curr_rowx10+1][curr_colx10] == SPACE || maze[curr_rowx10+1][curr_colx10] == maze[curr_row][curr_col]){
				curr_rowx10++;
			}
			break;
				
		case 1:
			
			if (maze[curr_rowx10-1][curr_colx10] == SPACE || maze[curr_rowx10-1][curr_colx10] == maze[curr_row][curr_col]){
				curr_rowx10--;
			}
			break;		
	}
	
	Sleep(20);
}

void oras(t,t2) {
	
	gotoxy(1,1);
	
	printf("Score: %d", t-t2);
}


