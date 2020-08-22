//includes.h

/* This files provides address values that exist in the system */

#define BOARD                 "DE1-SoC"

/* Memory */
#define DDR_BASE              0x00000000
#define DDR_END               0x3FFFFFFF
#define A9_ONCHIP_BASE        0xFFFF0000
#define A9_ONCHIP_END         0xFFFFFFFF
#define SDRAM_BASE            0xC0000000
#define SDRAM_END             0xC3FFFFFF
#define FPGA_ONCHIP_BASE      0xC8000000
#define FPGA_ONCHIP_END       0xC803FFFF
#define FPGA_CHAR_BASE        0xC9000000
#define FPGA_CHAR_END         0xC9001FFF

/* Cyclone V FPGA devices */
#define LEDR_BASE             0xFF200000
#define HEX3_HEX0_BASE        0xFF200020
#define HEX5_HEX4_BASE        0xFF200030
#define SW_BASE               0xFF200040
#define KEY_BASE              0xFF200050
#define JP1_BASE              0xFF200060
#define JP2_BASE              0xFF200070
#define PS2_BASE              0xFF200100
#define PS2_DUAL_BASE         0xFF200108
#define JTAG_UART_BASE        0xFF201000
#define JTAG_UART_2_BASE      0xFF201008
#define IrDA_BASE             0xFF201020
#define TIMER_BASE            0xFF202000
#define AV_CONFIG_BASE        0xFF203000
#define PIXEL_BUF_CTRL_BASE   0xFF203020
#define CHAR_BUF_CTRL_BASE    0xFF203030
#define AUDIO_BASE            0xFF203040
#define VIDEO_IN_BASE         0xFF203060
#define ADC_BASE              0xFF204000

/* Cyclone V HPS devices */
#define HPS_GPIO1_BASE        0xFF709000
#define HPS_TIMER0_BASE       0xFFC08000
#define HPS_TIMER1_BASE       0xFFC09000
#define HPS_TIMER2_BASE       0xFFD00000
#define HPS_TIMER3_BASE       0xFFD01000
#define FPGA_BRIDGE           0xFFD0501C

/* ARM A9 MPCORE devices */
#define   PERIPH_BASE         0xFFFEC000    // base address of peripheral devices
#define   MPCORE_PRIV_TIMER   0xFFFEC600    // PERIPH_BASE + 0x0600

/* Interrupt controller (GIC) CPU interface(s) */
#define MPCORE_GIC_CPUIF      0xFFFEC100    // PERIPH_BASE + 0x100
#define ICCICR                0x00          // offset to CPU interface control reg
#define ICCPMR                0x04          // offset to interrupt priority mask reg
#define ICCIAR                0x0C          // offset to interrupt acknowledge reg
#define ICCEOIR               0x10          // offset to end of interrupt reg
/* Interrupt controller (GIC) distributor interface(s) */
#define MPCORE_GIC_DIST       0xFFFED000    // PERIPH_BASE + 0x1000
#define ICDDCR                0x00          // offset to distributor control reg
#define ICDISER               0x100         // offset to interrupt set-enable regs
#define ICDICER               0x180         // offset to interrupt clear-enable regs
#define ICDIPTR               0x800         // offset to interrupt processor targets regs
#define ICDICFR               0xC00         // offset to interrupt configuration regs

#define	EDGE_TRIGGERED        0x1
#define	LEVEL_SENSITIVE       0x0
#define	CPU0		      0x01	    // bit-mask; bit 0 represents cpu0
#define	ENABLE  	      0x1

#define	KEY0  		      0b0001
#define	KEY1 	       	      0b0010
#define	KEY2		      0b0100
#define	KEY3		      0b1000

#define	RIGHT 		      1
#define	LEFT		      2

#define	USER_MODE	      0b10000
#define FIQ_MODE	      0b10001
#define	IRQ_MODE	      0b10010
#define	SVC_MODE	      0b10011
#define	ABORT_MODE	      0b10111
#define	UNDEF_MODE	      0b11011
#define	SYS_MODE	      0b11111

#define	INT_ENABLE	      0b01000000
#define	INT_DISABLE	      0b11000000

/* This files provides interrupt IDs */

/* FPGA interrupts (there are 64 in total; only a few are defined below) */
#define INTERVAL_TIMER_IRQ	 			72
#define KEYS_IRQ 						73
#define FPGA_IRQ2 						74
#define FPGA_IRQ3 						75
#define FPGA_IRQ4 						76
#define FPGA_IRQ5 						77
#define AUDIO_IRQ 						78
#define PS2_IRQ 						79
#define JTAG_IRQ 						80
#define IrDA_IRQ 						81
#define FPGA_IRQ10						82
#define JP1_IRQ							83
#define JP2_IRQ							84
#define FPGA_IRQ13						85
#define FPGA_IRQ14						86
#define FPGA_IRQ15						87
#define FPGA_IRQ16						88
#define PS2_DUAL_IRQ					89
#define FPGA_IRQ18						90
#define FPGA_IRQ19						91

/* ARM A9 MPCORE devices (there are many; only a few are defined below) */
#define MPCORE_GLOBAL_TIMER_IRQ			27
#define MPCORE_PRIV_TIMER_IRQ			29
#define MPCORE_WATCHDOG_IRQ				30

/* HPS devices (there are many; only a few are defined below) */
#define HPS_UART0_IRQ   				194
#define HPS_UART1_IRQ   				195
#define HPS_GPIO0_IRQ	          		196
#define HPS_GPIO1_IRQ	          		197
#define HPS_GPIO2_IRQ	          		198
#define HPS_TIMER0_IRQ	         		199
#define HPS_TIMER1_IRQ	         		200
#define HPS_TIMER2_IRQ	         		201
#define HPS_TIMER3_IRQ	         		202
#define HPS_WATCHDOG0_IRQ     			203
#define HPS_WATCHDOG1_IRQ     			204
	
#define HEX_ZERO						0b0111111
#define HEX_ONE 						0b0000110
#define HEX_TWO 						0b1011011
#define HEX_THREE 						0b1001111
#define HEX_FOUR 						0b1100110
#define HEX_FIVE 						0b1101101
#define HEX_SIX 						0b1111101
#define HEX_SEVEN 						0b0000111
#define HEX_EIGHT 						0b1111111
#define HEX_NINE 						0b1100111
	
//Standard C Library Functions
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <math.h>

//initialize the stack pointers for IRQ mode
void set_A9_IRQ_stack();

//Configures the General Interrupt Controller
void config_GIC();

//Configures the interrupts in the GIC for specific devices
void config_interrupts(int N, int CPU_target);

//Configures KEYs to trigger interrupts
void config_KEYs();

//Configure the PS2 Port to trigger interrupts
void config_PS2();

//Turns on Board to detect interrupts
void enable_A9_interrupts();

//The Interrupt service routine for KEYS
void pushbutton_ISR();

//The Interrupt service routine for the PS2 Keyboard
void keyboard_ISR();

//Waits for the frame buffer to switch back and front
void wait_for_sync();

//Plots on pixel on the screen
void plot_pixel(int x, int y, short int line_color);

//Plots a character on the screen
void plot_character(int x, int y, char letter);

//Sets the entire screen to black
void clear_screen();

//Clears characters on screen
void clear_characters();

//Draws a line on screen using Bresenham's algorithm
void draw_line(int start_x, int start_y, int end_x, int end_y, int colour);

//Draws a circle on screen
void draw_circle(int x_center, int y_center, int radius, int colour);

//Functions related to drawing/erasing the paddles
void draw_initial_paddles();
void draw_paddle(int top_x, int top_y);
void erase_paddle(int top_x, int top_y);

//Functions related to drawing/erasing the puck
void draw_initial_puck();
void draw_puck(int x_center, int y_center);
void erase_puck(int x_center, int y_center);

//Draws the outline and middle circle/diving line
void draw_background();

//Returns a random colour to draw when KEY1 is pressed
short int get_new_colour(int colour_index);

//Global variables that control the pixel and character buffers
volatile int pixel_buffer_start;
volatile int char_buffer_start;

//Which side the puck starts on, random number
int startPosition;

//Direction the paddles are travelling (-1 for up or 1 for down)
volatile int direction_of_paddle_1; 
volatile int direction_of_paddle_2;

//Direction the puck is travelling (-1 for up/left or 1 for down/right)
volatile int direction_of_puck_x = 0, direction_of_puck_y = 0;

//The pixel location of the top of paddles
int paddle_1_top_x = 10, paddle_1_top_y = 100;
int paddle_2_top_x = 299, paddle_2_top_y = 100;

//Pixel location of the center of the puck
int puck_center_x, puck_center_y;

//The score for each player
int score_player_1 = 0, score_player_2 = 0;

//The colour used to draw the paddles and background
//Initially white
short int colour_to_draw = 0xFFFF;

//The colour used to draw the puck
//Initially pink
short int colour_to_draw_puck = 0xF81F;

//Helps create a cycle of colours to draw with
int colour_index;
int puck_colour_index;

//Determines whether the game is paused or active
bool pause_play = false;

//The Main Gameplay 
int main(void)
{
	//Configuring Interrupts
	set_A9_IRQ_stack();
	config_GIC();
	config_KEYs();
	config_PS2();
	enable_A9_interrupts();
	
	//Setting the seed for rand()
	srand(time(0));

	//Sets a random initial direction for paddle 1 and 2
	//Generates a random number between -1 and 1
	direction_of_paddle_1 = (rand() % 3) -1; 
	direction_of_paddle_2 = (rand() % 3) -1;
	
	//Resets the colour indeces
	colour_index = 0;
	puck_colour_index = 1;

	//Base address of frame buffer
	volatile int * pixel_ctrl_ptr = (int *)PIXEL_BUF_CTRL_BASE;

	//Set front pixel buffer to start of FPGA on chip memory (0xC8000000)
	*(pixel_ctrl_ptr + 1) = FPGA_ONCHIP_BASE;
	
	//Swap front and back buffers to set the front buffer location
	wait_for_sync();
	
	/* Read location of the pixel buffer from the pixel buffer controller */
	pixel_buffer_start = *pixel_ctrl_ptr;
	
	//Base address of character buffer
	volatile int * char_ctrl_ptr = (int*)CHAR_BUF_CTRL_BASE;
	
	//Read location of the character buffer
	char_buffer_start = *char_ctrl_ptr;
	
	//Clear any previous drawings
	clear_screen();
	clear_characters();
	draw_background();

	//set back pixel buffer to the start of SDRAM (0xC0000000)
	*(pixel_ctrl_ptr + 1) = SDRAM_BASE;

	//draw on the back buffer
	pixel_buffer_start = *(pixel_ctrl_ptr +1);
	
	//Clear the front buffer
	clear_screen();
	draw_background();

	//Drawing the initial image, the background, paddles in starting locations
	//and the puck on a random side
	draw_initial_paddles();
	draw_initial_puck();

	//Switching front and back buffers
	wait_for_sync();
	
	//Array to store binary values for HEX display
	int hexDigits[10] = {HEX_ZERO, HEX_ONE, HEX_TWO, HEX_THREE, HEX_FOUR, 
						 HEX_FIVE, HEX_SIX, HEX_SEVEN, HEX_EIGHT, HEX_NINE};
	
	//Pointers for HEX displays
	//Setting the initial scores to 00 on HEX0/1
	volatile int * HEX_ptr_0 = (int *)HEX3_HEX0_BASE;
	*(HEX_ptr_0) = hexDigits[0];
	volatile int * HEX_ptr_1 = (int *)(HEX3_HEX0_BASE + 1);
	*(HEX_ptr_1) = hexDigits[0];

	//Setting the initial scores to 00 on HEX4/5
	volatile int * HEX_ptr_4 = (int *)HEX5_HEX4_BASE;
	volatile int * HEX_ptr_5 = (int *)(HEX5_HEX4_BASE + 1);
	*(HEX_ptr_4) = hexDigits[0];
	*(HEX_ptr_5) = hexDigits[0];
	
	//Pointers for LEDs;
	volatile int * LED_ptr_0 = (int *)LEDR_BASE;
	volatile int * LED_ptr_9 = (int*)(0xFF200001);
	
	//If the puck starts on the left
	if(startPosition == 0)
		//Move right
		direction_of_puck_x = 1;
	else
		//Move left
		direction_of_puck_x = -1;

	//Used to ensure the puck is cleared properly off the screen
	bool first_play = true;
	bool changed_y_dir = false, changed_x_dir = false;
	bool erase_initial_move = false;
	
	//Plots the initial scores
	plot_character(18,5,'0');
	plot_character(19,5,'0');
	plot_character(59,5,'0');
	plot_character(60,5,'0');
	
	//Resets the goal lights to zero
	*(LED_ptr_0) = 0;
	*(LED_ptr_9) = 0;	
	
	//Continuous game loop
	while(true)
	{
		//If the game is active
		if(pause_play){
			
			//Reset goal lights
			*(LED_ptr_0) = 0;
			*(LED_ptr_9) = 0;	
			
			//Someone has scored
			if(puck_center_x == 10 || puck_center_x == 309){
				
				//Stop the game, restart the play
				pause_play = false;
				first_play = true;
				
				//Redraw
				clear_screen();
				draw_background();
				wait_for_sync();
				pixel_buffer_start = *(pixel_ctrl_ptr + 1);
				
				//Update score
				//If player two scored
				if(puck_center_x == 10){
					score_player_2++;
					*(LED_ptr_9) = 2;
				}
				
				//If player one scored
				else{
					score_player_1++;
					*(LED_ptr_0) = 1;
				}
				
				//Update score on hex
				*(HEX_ptr_0) = hexDigits[score_player_2];
				if(score_player_2 < 10) *(HEX_ptr_1) = hexDigits[0];
				
				//Player 2 has reached 10 -> game over
				else{
					*(HEX_ptr_0) = hexDigits[0];
					*(HEX_ptr_1) = hexDigits[1];
					break;
				}
				
				//Update score on hex
				*(HEX_ptr_4) = hexDigits[score_player_1];
				if(score_player_1 < 10) *(HEX_ptr_5) = hexDigits[0];
				
				//Player 1 has reached 10 -> game over
				else{
					*(HEX_ptr_4) = hexDigits[0];
					*(HEX_ptr_5) = hexDigits[1];
					break;
				}
				
				//If the game is not over, put the scores on the VGA
				if(score_player_1 < 10 && score_player_2 < 10){
					clear_characters();
					plot_character(18,5,'0');
					plot_character(19,5,score_player_1 + 48);
					plot_character(59,5,'0');
					plot_character(60,5,score_player_2 + 48);
				}
				
				//Redraw the paddles and background
				clear_screen();
				draw_background();	
				draw_initial_paddles();				
				
				//If player two scored, reset the position of the puck
				//to the left paddle
				if(puck_center_x == 10){
					puck_center_x = 29;
					startPosition = 0;
				}	
				
				//Reset the position of the puck to the right padde
				else{
					puck_center_x = 290;
					startPosition = 1;
				}	
				
				//Reset position to middle of screen
				puck_center_y = 125;
				
				//Draw the new puck
				draw_puck(puck_center_x,puck_center_y);				
				
				wait_for_sync();					
				
				//Wait for the user to press the play button
				if(pause_play)
					continue;
			}			
			
			//Set the initial trajectory of the puck
			if(first_play){
				
				//If player 1 starts, initial trajectory = trajectory of paddle 1
				if(startPosition == 0){
					direction_of_puck_y = direction_of_paddle_1;
					direction_of_puck_x = 1;
				}	
				
				//If player 2 starts, initial trajectory = trajectory of paddle 2
				else{
					direction_of_puck_y = direction_of_paddle_2;
					direction_of_puck_x = -1;
				}	
				
				//No longer the first play
				first_play = false;
				
				//We will need to erase the initial puck
				erase_initial_move = true;
			}
				
			//As long as paddle 1 isnt at the top or bottom, move it
			if((paddle_1_top_y + direction_of_paddle_1) != 0 &&
			  ((paddle_1_top_y + direction_of_paddle_1) + 50) != 239)
				paddle_1_top_y += direction_of_paddle_1;

			//As long as paddle 2 isnt at the top or bottom, move it
			if((paddle_2_top_y + direction_of_paddle_2) != 0 &&
			  ((paddle_2_top_y + direction_of_paddle_2) + 50) != 239)
				paddle_2_top_y += direction_of_paddle_2;
			
			//If the puck has reached the top or bottom, switch its y-direction
			if(puck_center_y + direction_of_puck_y + 10 == 239 ||
			   puck_center_y + direction_of_puck_y - 10 == 0){
				direction_of_puck_y *= -1;
				changed_y_dir = true;
			}
			
			//Changing direction if the puck hits paddle 1
			if(puck_center_x + direction_of_puck_x - 10 == 19 && 
			   //The top of the puck is between the top and bottom of the paddle or
			   ((puck_center_y - 10 >= paddle_1_top_y && puck_center_y - 10 <= paddle_1_top_y + 50) ||
				//The bottom of the puck is between the top and bottom of the paddle
				(puck_center_y + 10 >= paddle_1_top_y && puck_center_y + 10 <= paddle_1_top_y + 50))){
				
				direction_of_puck_x *= -1;
				changed_x_dir = true;
				direction_of_puck_y = direction_of_paddle_1;
				changed_x_dir = true;
			}
				
			
			//Changing direction if the puck hits paddle 2
			if(puck_center_x + direction_of_puck_x + 10 > 299 && 
			   //The top of the puck is between the top and bottom of the paddle or
			   ((puck_center_y - 10 >= paddle_2_top_y && puck_center_y - 10 <= paddle_2_top_y + 50) ||
				//The bottom of the puck is between the top and bottom of the paddle
				(puck_center_y + 10 >= paddle_2_top_y && puck_center_y + 10 <= paddle_2_top_y + 50))){
				
				direction_of_puck_x *= -1;
				changed_x_dir = true;
				direction_of_puck_y = direction_of_paddle_2;
				changed_x_dir = true;
			}
			
			//Updating current position of the puck
			puck_center_x += direction_of_puck_x;
			puck_center_y += direction_of_puck_y;
		}
		
		//Erase the previous puck
		erase_puck(puck_center_x - 2*direction_of_puck_x, puck_center_y - 2*direction_of_puck_y);
		
		//If the puck has recently changed direction, over erase to make sure
		//There is no trailing pixels left over
		if(changed_y_dir || erase_initial_move){
			erase_puck(puck_center_x - 10, puck_center_y);
			erase_puck(puck_center_x + 10, puck_center_y);
			changed_y_dir = false;
		}
		
		//If the puck has recently changed direction, over erase to make sure
		//There is no trailing pixels left over
		if(changed_x_dir || erase_initial_move){
			erase_puck(puck_center_x, puck_center_y - 10);
			erase_puck(puck_center_x, puck_center_y + 10);
			changed_x_dir = false;
		}
		
		//Reset the initial move flag
		if(erase_initial_move)
			erase_initial_move = false;
		
		//Erase the previous paddles
		erase_paddle(paddle_1_top_x, paddle_1_top_y - 2*direction_of_paddle_1);
		erase_paddle(paddle_2_top_x, paddle_2_top_y - 2*direction_of_paddle_2);
		   
		//Redraw the background
		draw_background();

		//Draw the paddles in their new locations
		draw_paddle(paddle_1_top_x, paddle_1_top_y);
		draw_paddle(paddle_2_top_x, paddle_2_top_y);
		
		//Draw the puck in its new location
		draw_puck(puck_center_x, puck_center_y);
		
		//Switch the back and front buffers
		wait_for_sync();
		pixel_buffer_start = *(pixel_ctrl_ptr + 1);

	}
	
	//If the game is over, print GAME OVER to the screen
	clear_screen();
	clear_characters();
	plot_character(17,5,'G');
	plot_character(18,5,'A');
	plot_character(19,5,'M');
	plot_character(20,5,'E');
	
	plot_character(58,5,'O');
	plot_character(59,5,'V');
	plot_character(60,5,'E');
	plot_character(61,5,'R');
	
	//The end
}

//Switches the back and front buffers
void wait_for_sync()
{
	//Grab the base address for the front buffer
	volatile int *pixel_ctrl_ptr = (int*)PIXEL_BUF_CTRL_BASE;

	//Grabs the status bit
	int status;

	//Write 1 to the front buffer register
	*(pixel_ctrl_ptr) = 1;

	//Grab the status bit
	status = *(pixel_ctrl_ptr + 3);

	//Keep checking status until it is zero
	while((status & 0x01) != 0)
		status = *(pixel_ctrl_ptr + 3);
}

//Plots one pixel on the screen at (X,Y)
void plot_pixel(int x, int y, short int line_color)
{
    *(short int *)(pixel_buffer_start + (y << 10) + (x << 1)) = line_color;
}

//Plots at character at x,y
void plot_character(int x, int y, char letter)
{
	*(char*)(char_buffer_start + (y << 7) + (x)) = letter;
}	

//Sets all the pixels on screen to black
void clear_screen()
{
	memset((short int*) pixel_buffer_start, 0, 245760);
}

//Clears all the characters on the screen
void clear_characters()
{
	memset((short int*) char_buffer_start, 0, 4800);	
}	

//Draws a line on screen starting at (start_x, start_y) using Bresenham's algorithm
void draw_line(int start_x, int start_y, int end_x, int end_y, int colour)
{
	int isSteep = 0;
	if(abs(end_y - start_y) > abs(end_x - start_x)){
		isSteep = 1;
		//Swap start coordinates
		int s_temp = start_x;
		start_x = start_y;
		start_y = s_temp;
		//Swap end coordinates
		int e_temp = end_x;
		end_x = end_y;
		end_y = e_temp;
	}

	if(start_x > end_x){
		//Swap start_x and end_x
		int x_temp = start_x;
		start_x = end_x;
		end_x = x_temp;
		//Swap start_y and end_y
		int y_temp = start_y;
		start_y = end_y;
		end_y = y_temp;
	}

	int y_step;

	int delta_x = (end_x - start_x);
	int delta_y = (end_y - start_y);

	int error = -1*(delta_x/2);
	if(start_y < end_y) y_step = 1;
	else y_step = -1;
	int y = start_y;
	
	for(int i = start_x; i <= end_x; i++){
		if(isSteep == 1) plot_pixel(y,i,colour);
		else plot_pixel(i,y,colour);

		error = error + abs(delta_y);
		if(error >= 0){
			y += y_step;
			error = error - delta_x;
		}
	}

}

//Draws a circle around (x_center, y_center) with radius
void draw_circle(int x_center, int y_center, int radius, int colour)
{
	int xMin = x_center - radius;
	int xMax = x_center + radius;

	for(int i = xMin; i <= xMax; i++){
		int squareTerm = sqrt(pow(radius,2) - pow(i - x_center, 2));
		
		int yPoint =  squareTerm + y_center;
		plot_pixel(i,yPoint,colour);
		plot_pixel(i,yPoint+1,colour);
		plot_pixel(i,yPoint-1,colour);
		
		int yPoint_2 = -1*squareTerm + y_center;
		plot_pixel(i, yPoint_2,colour);
		plot_pixel(i, yPoint_2+1,colour);
		plot_pixel(i, yPoint_2 -1,colour);

		//FOR X VALUES NEAR THE ENDS, DRAW MORE POINTS
		if(i == xMax || i==xMin || i==xMin+1 || i==xMax -1){
			plot_pixel(i, yPoint+2,colour);
			plot_pixel(i,yPoint-2,colour);
			plot_pixel(i, yPoint+3,colour);
			plot_pixel(i,yPoint-3,colour);
			plot_pixel(i, yPoint+4,colour);
			plot_pixel(i,yPoint-4,colour);
			plot_pixel(i, yPoint+5,colour);
			plot_pixel(i,yPoint-5,colour);

			plot_pixel(i,yPoint_2+2,colour);
			plot_pixel(i,yPoint_2-2,colour);
			plot_pixel(i,yPoint_2+3,colour);
			plot_pixel(i,yPoint_2-3,colour);
			plot_pixel(i,yPoint_2+4,colour);
			plot_pixel(i,yPoint_2-4,colour);
			plot_pixel(i,yPoint_2+5,colour);
			plot_pixel(i,yPoint_2-5,colour);
		}
	}
}

//Draws the paddles starting at top_x, top_y
void draw_paddle(int top_x, int top_y)
{
	for(int i = top_x; i <= top_x + 10 ; i++){
		for(int j = top_y; j <= top_y + 50; j++){
			plot_pixel(i,j,colour_to_draw);
		}
	}
}

//Draws the paddles in the middle of the screen at either edge
void draw_initial_paddles()
{
	paddle_1_top_x = 10;
	paddle_1_top_y = 100;
	paddle_2_top_x = 299;
	paddle_2_top_y = 100;
	draw_paddle(paddle_1_top_x,paddle_1_top_y);
	draw_paddle(paddle_2_top_x,paddle_2_top_y);
}

//Erases the paddle shapes starting at top_x, top_y
void erase_paddle(int top_x, int top_y)
{
	for(int i = top_x; i <= top_x + 10 ; i++){
		for(int j = top_y; j <= top_y + 50; j++){
			plot_pixel(i,j,0);
		}
	}
}

//Draws the intital puck on either the right or left side of the screen
void draw_initial_puck()
{
	//Sets the seed for rand()
	srand(time(0));

	//Random number to choose which side puck starts on at beginning of game
	startPosition = rand()%2;

	//Start on left side
	if(startPosition == 0){
		draw_circle(29,125,8,colour_to_draw_puck);
		draw_circle(29,125,7,colour_to_draw_puck);
		draw_circle(29,125,6,colour_to_draw_puck);
		draw_circle(29,125,5,colour_to_draw_puck);
		draw_circle(29,125,4,colour_to_draw_puck);
		draw_circle(29,125,3,colour_to_draw_puck);
		draw_circle(29,125,2,colour_to_draw_puck);
		draw_circle(29,125,1,colour_to_draw_puck);
		puck_center_x = 29;
		puck_center_y = 125;
	}
	
	//Start on right side
	else if(startPosition == 1){
		draw_circle(290,125,8,colour_to_draw_puck);
		draw_circle(290,125,7,colour_to_draw_puck);
		draw_circle(290,125,6,colour_to_draw_puck);
		draw_circle(290,125,5,colour_to_draw_puck);
		draw_circle(290,125,4,colour_to_draw_puck);
		draw_circle(290,125,3,colour_to_draw_puck);
		draw_circle(290,125,2,colour_to_draw_puck);
		draw_circle(290,125,1,colour_to_draw_puck);
		puck_center_x = 290;
		puck_center_y = 125;
	}
}

//Draws the puck starting at x_center, y_center
void draw_puck(int x_center, int y_center)
{
		draw_circle(x_center,y_center,8,colour_to_draw_puck);
		draw_circle(x_center,y_center,7,colour_to_draw_puck);
		draw_circle(x_center,y_center,6,colour_to_draw_puck);
		draw_circle(x_center,y_center,5,colour_to_draw_puck);
		draw_circle(x_center,y_center,4,colour_to_draw_puck);
		draw_circle(x_center,y_center,3,colour_to_draw_puck);
		draw_circle(x_center,y_center,2,colour_to_draw_puck);
		draw_circle(x_center,y_center,1,colour_to_draw_puck);
}

//Erases the puck
void erase_puck(int x_center, int y_center)
{
		draw_circle(x_center,y_center,9,0x0000);
		draw_circle(x_center,y_center,8,0x0000);
		draw_circle(x_center,y_center,7,0x0000);
		draw_circle(x_center,y_center,6,0x0000);
		draw_circle(x_center,y_center,5,0x0000);
		draw_circle(x_center,y_center,4,0x0000);
		draw_circle(x_center,y_center,3,0x0000);
		draw_circle(x_center,y_center,2,0x0000);
		draw_circle(x_center,y_center,1,0x0000);
}

//Draws the dividing line, outline and the middle circle
void draw_background()
{
	draw_line(155,0,155,239,colour_to_draw);
	draw_line(156,0,156,239,colour_to_draw);
	draw_line(157,0,157,239,colour_to_draw);
	draw_line(158,0,158,239,colour_to_draw);
	draw_line(159,0,159,239,colour_to_draw);
	draw_line(160,0,160,239,colour_to_draw);
	draw_line(161,0,161,239,colour_to_draw);
	draw_line(162,0,162,239,colour_to_draw);
	draw_line(163,0,163,239,colour_to_draw);
	draw_line(164,0,164,239,colour_to_draw);
	draw_circle(159,119,50,colour_to_draw);
	draw_circle(159,119,49,colour_to_draw);
	draw_circle(159,119,48,colour_to_draw);
	draw_circle(159,119,47,colour_to_draw);
	draw_circle(159,119,46,colour_to_draw);
	draw_circle(159,119,45,colour_to_draw);
	draw_circle(159,119,44,colour_to_draw);
	draw_circle(159,119,43,colour_to_draw);
	draw_circle(159,119,42,colour_to_draw);
	draw_circle(159,119,41,colour_to_draw);
}

//initialize the stack pointers for IRQ mode
void set_A9_IRQ_stack()
{
	int stack, mode;

	//Start the stack at the end of on chip memory
	stack = A9_ONCHIP_END - 7;

	//Change to IRQ mode with interrupts disabled
	mode = INT_DISABLE | IRQ_MODE;
	asm("msr cpsr, %[ps]" : : [ps] "r"(mode));

	//set banked stack pointer
	asm("mov sp, %[ps]" : : [ps] "r"(stack));

	//go back to SVC mode before returning
	mode = INT_DISABLE | SVC_MODE;
	asm("msr cpsr, %[ps]" : : [ps] "r"(mode));
}

//Turn on interrupts in the ARM processor
void enable_A9_interrupts()
{
	int status = SVC_MODE | INT_ENABLE;
	asm("msr cpsr, %[ps]" : : [ps] "r"(status));
}

//Configure general interrupt controller
void config_GIC()
{
	int address;

	//Configure the KEYs interrupt
	config_interrupts(73, 1);
	
	//Configure the PS2 interrupts
	config_interrupts(79, 1);

	//Set interrupt priority mask register enable all priorities
	address = MPCORE_GIC_CPUIF + ICCPMR;
	*((int *)address) = 0xFFFF;

	//Set CPU interface control register ICCICR, enable signalling of interrupts
	address = MPCORE_GIC_CPUIF + ICCICR;
	*((int *) address) = ENABLE;

	//Configure the Distributor Control Register ICDDCR to pending interrupts to CPU
	address = MPCORE_GIC_DIST + ICDDCR;
	*((int *) address) = ENABLE;
}

//Configures interrupts in the GIC for a specific device
void config_interrupts(int N, int CPU_target)
{
	int reg_offset, index, value, address;
	
	/* Configure the Interrupt Set-Enable Registers (ICDISERn).
	* reg_offset = (integer_div(N / 32) * 4
	* value = 1 << (N mod 32) */
	reg_offset = (N >> 3) & 0xFFFFFFFC;
	index = N & 0x1F;
	value = 0x1 << index;
	address = 0xFFFED100 + reg_offset;
	
	/* Now that we know the register address and value, set the appropriate bit */
	*(int *)address |= value;
	
	/* Configure the Interrupt Processor Targets Register (ICDIPTRn)
	* reg_offset = integer_div(N / 4) * 4
	* index = N mod 4 */
	reg_offset = (N & 0xFFFFFFFC);
	index = N & 0x3;
	address = 0xFFFED800 + reg_offset + index;
	
	/* Now that we know the register address and value, write to (only) the
	* appropriate byte */
	*(char *)address = (char)CPU_target;
}

//Configure the KEYs to create interrupts
void config_KEYs()
{
	volatile int * KEY_ptr = (int *)KEY_BASE;

	//enable interrupts for KEY0 and KEY1
	*(KEY_ptr + 2) = 0x3;
}

//Configure the PS2 Port to Generate Interrupts
void config_PS2()
{
	volatile int * PS2_ptr = (int *)PS2_BASE;
	
	//Set the RE bit to 1 to generate interrupts
	*(PS2_ptr + 1) = 0xF;
}

//Defines where to go when an interrupt occurs
void __attribute__((interrupt))__cs3_isr_irq()
{
	//Read the interrupt acknowledge register from proc interface
	int address = MPCORE_GIC_CPUIF + ICCIAR;
	int int_id = *((int *)address);

	//If the interrupt is from the keys
	if(int_id == KEYS_IRQ)
		pushbutton_ISR();
	//If the interrupt is from the keyboard
	else if(int_id == PS2_IRQ)
		keyboard_ISR();
	//if unexpected stay here
	else
		while(true)
			; 

	//Write to the End of Interrupt Register
	address = MPCORE_GIC_CPUIF + ICCEOIR;
	*((int *)address) = int_id;
}

// Define the remaining exception handlers (not used)
void __attribute__((interrupt)) __cs3_reset(void)
{
	while (1)
	;
}
void __attribute__((interrupt)) __cs3_isr_undef(void)
{
	while (1)
	;
}
void __attribute__((interrupt)) __cs3_isr_swi(void)
{
	while (1)
	;
}
void __attribute__((interrupt)) __cs3_isr_pabort(void)
{
	while (1)
	;
}

void __attribute__((interrupt)) __cs3_isr_dabort(void)
{
	while (1)
	;
}
void __attribute__((interrupt)) __cs3_isr_fiq(void)
{
	while (1)
	;
}

//Pushbutton interrupt service routine
//Toggles the value of pause/play for KEY0
//Changes the colour for KEY1
void pushbutton_ISR()
{
	//pointer to the key base
	volatile int * KEY_ptr = (int*)KEY_BASE;

	//The value of the key press
	int press;

	//Reads the pushbutton edge capture register
	press = *(KEY_ptr + 3);

	//Clears the interrupt
	*(KEY_ptr + 3) = press;

	//KEY0 is used to start the game/push the puck forward
	//Has no effect while the game is going on
	if(press == 1 && !pause_play)
		//The game begins
		pause_play = true;
	
	//Toggle the pause/play variable
	else if(press == 1 && pause_play)
		pause_play = false;

	//KEY1 is used to switch the colours used to draw in
	else if(press == 2){
		
		//Cycle through the colours
		colour_index++;
		
		puck_colour_index++;

		//Reset back to zero if used all the colours
		if(colour_index == 7)
			colour_index = 0;
		
		//Reset back to zero if used all the colours
		if(puck_colour_index == 7)
			puck_colour_index = 0;
		
		//Gets a new colour
		colour_to_draw = get_new_colour(colour_index);
		colour_to_draw_puck = get_new_colour(puck_colour_index);
	}
}

//The interrupt service routine for the PS2 keyboard
//The right paddle follows I/K keys to move up and down
//The left paddle follows W/S keys to move up and down
void keyboard_ISR()
{
	volatile int * PS2_ptr = (int *)PS2_BASE;
	
	//Grab the valid bit
	bool RVALID = ((*(PS2_ptr) & 0x8000) >> 15) == 1;
	
	//If there are bits to read
	if(RVALID)
	{	
		//Grab the FIFO characters
		volatile int FIFO_read = *(PS2_ptr) & 0xFF;

		//If W is pressed, move paddle 1 up
		if(FIFO_read == 29)	
			direction_of_paddle_1 = -1;
		
		//If S is pressed, move paddle 1 down
		else if(FIFO_read == 27)
			direction_of_paddle_1 = 1;
		

		//If I is pressed, move paddle 2 up
		else if(FIFO_read == 67)
			direction_of_paddle_2 = -1;
			
		//If K is pressed, move padde 2 down
		else if(FIFO_read == 66)
			direction_of_paddle_2 = 1;
			
		else
			;
	}
}

//Cycles through the 6 main colours plus white to draw
//the different elements in
short int get_new_colour(int colour_index)
{	
	//Draw in white
	if(colour_index == 0)
		return 0xFFFF;
	
	//Draw in magenta
	else if(colour_index == 1)
		return 0xF81F;

	//Draw in green
	else if(colour_index == 2)
		return 0x07E0;

	//Draw in blue
	else if(colour_index == 3)
		return 0x001F;

	//Draw in cyan
	else if(colour_index == 4)
		return 0x07FF;

	//Draw in red
	else if(colour_index == 5)
		return 0xF800;

	//Draw in yellow
	else
		return 0xFFE0;
}