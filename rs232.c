/*			GCEM - LUCAS DIEGO					*/
/*	A APLICACAO CONSISTE EM UMA COMUNICACAO 	*/
/*	DA PLACA COM O COMPUTADOR ATRAVES DO 		*/
/*	PERIFERICO UART(PORTA SERIAL), NA QUAL		*/
/*	O QUE E DIGITADO NO TECLADO DA PLACA 		*/
/*	APARECE NO TERMINAL SERIAL(DOCKLIGHT)		*/
/*	E O CARACTERE QUE SE DIGITA NO TERMINAL		*/
/*	APARECE NO DISPLAY ALFANUMERICO				*/
/*												*/
/*		REQUISITOS PARA A UTILIZACAO			*/
/*			DA APLICACAO NA PLACA:				*/
/*		JUMPERS JP21 E JP22 NA POSICAO 1		*/
/*		DIG1 A DIG4 DESABILITADOS				*/
/*		APOS A GRAVACAO REMOVER O GRAVADOR 		*/
/*		PARA EVITAR CONFLITOS NOS PINOS			*/
/*		PGD E PGC								*/



// Bibliotecas
#include <P18F4550.h>
#include <usart.h>
#include <stdio.h>

#pragma udata images
    unsigned char input_image_line[200];
    unsigned char output_image_line[400][2];
#pragma udata

// Oscilador e outras definicoes de registradores	
#pragma config FOSC     = HS     // (8 MHz)
#pragma config IESO     = OFF
#pragma config PWRT     = OFF
#pragma config BORV     = 3
#pragma config WDT      = OFF
#pragma config WDTPS    = 32768
#pragma config MCLRE    = OFF
#pragma config LPT1OSC  = OFF
#pragma config PBADEN   = OFF
#pragma config STVREN   = ON
#pragma config LVP      = OFF

// Definições 
#define OUT 0		// definição de direção de I/O
#define IN 1		// definição de direção de I/O

// Definições de Hardware
// Para LCD
#define RS PORTEbits.RE0
#define EN PORTEbits.RE1
#define DISPLAY PORTD
#define RS_DIR DDREbits.RE0
#define EN_DIR DDREbits.RE1
#define DISPLAY_DIR DDRD

// Para Teclado
// Pinos
#define C0 	PORTBbits.RB0 
#define C1 	PORTBbits.RB1
#define C2 	PORTBbits.RB2
#define C3 	PORTBbits.RB3
#define L3 	PORTBbits.RB7
#define L2 	PORTBbits.RB6
#define L1 	PORTBbits.RB5
#define L0	PORTBbits.RB4

// Direção de dados dos pinos
#define C0_DIR	DDRBbits.RB0
#define C1_DIR	DDRBbits.RB1
#define C2_DIR	DDRBbits.RB2
#define C3_DIR	DDRBbits.RB3
#define L0_DIR	DDRBbits.RB4
#define L1_DIR	DDRBbits.RB5
#define L2_DIR	DDRBbits.RB6
#define L3_DIR	DDRBbits.RB7

void main (void)
{
    
    //Declarando ponteiros pras regiões de buffer de imagem.
    // Recomendado nos documentos de PIC
    
    unsigned char *input_buffer = input_image_line;
    unsigned char **output_buffer = output_image_line;
    
	LATD = 0x00;
	DDRD = 0x00;	
        
    input_buffer[0] = 2;
    

	OpenUSART(	USART_TX_INT_OFF & 
				USART_RX_INT_OFF & 
				USART_ASYNCH_MODE & 
				USART_EIGHT_BIT &
				USART_CONT_RX &
				USART_BRGH_HIGH,50);
    
	while(1) {
        //TODO Ler uma linha de 200 bytes via serial
        //TODO Calcular categoria do halftone
        //TODO Preencher matriz output_image_line com halftone
        //TODO Por matriz como output na serial.
	}
}