#include<stdio.h>
#include<stdlib.h>
#include<time.h>
unsigned char far *vidmem=0xB8000000;
void write(unsigned char,unsigned char,unsigned char);
unsigned char read(unsigned char,unsigned char);
void main()
{
	unsigned char far *keybmem=0x417;
	unsigned char counter=0,destroyed=0,speed=0,bombposx=0,bombposy=0,temp=0,sleeper=250,row,col,curcol=40;
	unsigned char bombactive='n';
	/*make it boolean later*/
	int i,j=0;
	clrscr();
	printf("REQUEST for all game players :\n\nKEEP NUM LOCK , CAPS , SCROLL LOCK OFF\nLft Shift ==> Move left\nRht Shift ==> Move right\nAny Ctrl ==> Fire on Bomb on path.\n\n\tPress any key to Continue...");
	getch();
	clrscr();
	for(i=0;i<25;i++)
	{
		write(0,i,32);
		write(79,i,32);
	}
	write(curcol,0,30);
	write(0,23,1);
	write(79,23,1);
	*keybmem=0;
	for(;;)
	{
		if(bombactive=='n'&&counter<26)
		{
			counter=0;
			temp=counter;
			for(;;)
			{
				bombposx=random(80);
				if(bombposx>curcol&&bombposx-curcol<20)
					break;
				else
					if(curcol>bombposx&&curcol-bombposx<20)
						break;
			}
			if(bombposx!=0&&bombposx!=79)
			{
				write(bombposx-1,0,'_');
				write(bombposx+1,0,'_');
			}
			bombposy=24;
			write(bombposx,bombposy,31);
			bombactive='y';
			counter++;
		}
		if(bombactive=='y'&&counter>25)
		{
			bombactive='n';
			write(bombposx,bombposy,32);
			if(bombposx!=0&&bombposx!=79)
			{
				write(bombposx-1,0,32);
				write(bombposx+1,0,32);
			}
			sound(100);/*UNDESTROYED BOMB HITTING GROUND*/
			delay(50);
			nosound();
			counter=0;
		}
		if(bombactive=='y'&&counter<26)
		{
			if((counter-temp)==1)
			{
				temp=counter;
				write(bombposx,bombposy,32);
				write(bombposx,bombposy-1,31);
				bombposy--;
				/*IF ANY PROPAGATION SOUND NEEDED IN MID AIR
				But It would become too noisy Hope u dont burn up
				your PC's small speaker.*/
/*
				sound(16000);
				delay(25);
				nosound();
*/
			}
			counter++;
		}
		for(i=0;i<24;i++)
		{
			write(0,i,read(0,i+1));
			write(79,i,read(79,i+1));
		}
		if(j==0)
		{
			write(0,24,2);
			write(79,24,2);
			j++;
		}
		else
		{
			j=0;
			write(0,24,1);
			write(79,24,1);
		}
		if(*keybmem==2&&curcol>1)
		{
			write(curcol,0,32);
			write(curcol-1,0,30);
			curcol--;
			sound(150);/*GUN ON GROUND MOVING LEFT SOUND*/
			delay(20);
			nosound();
		}
		if(*keybmem==1&&curcol<78)
		{
			write(curcol,0,32);
			write(curcol+1,0,30);
			curcol++;
			sound(150);/*GUN ON GROUND MOVING RIGHT SOUND*/
			delay(20);
			nosound();
		}
		if((*keybmem==4)&&(bombposx==curcol))
		{
			counter=0;
			bombactive='n';
			if(bombposx!=0&&bombposx!=79)
			{
				write(bombposx-1,0,32);
				write(bombposx+1,0,32);
			}
			write(bombposx,bombposy,32);
			sound(40);/*BOMB SUCCESSFULLY BLASTED/INTERCEPTED IN MID AIR SOUND*/
			delay(50);
			nosound();
			destroyed++;
			if(destroyed>2)
			{
				clrscr();
				speed++;
				destroyed=0;
				if(speed>4)
				{
					sleeper=255;
					speed=0;
				}
				else
				{
					sleeper=255-(speed*50);
				}
				printf("\t%c GREAT Going... Time to Change speed ... %c Speed Level : %u of %u ms.",2,2,speed,sleeper);
				getch();
				clrscr();
				curcol=40;
				write(curcol,0,30);
			}
		}
		delay(sleeper);
	}
}
void write(unsigned char col,unsigned char row,unsigned char ch)
{
	*(vidmem+(24-row)*160+col*2)=ch;
}
unsigned char read(unsigned char col,unsigned char row)
{
	return *(vidmem+(24-row)*160+col*2);
}
