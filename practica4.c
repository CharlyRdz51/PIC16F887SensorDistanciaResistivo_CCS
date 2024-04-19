//Universidad de Guadalajara
//Centro Universitario de Ciencias Exactas e Ingenierias
//Aguilar Rodriguez Carlos Adolfo 215860049
//Seminario de Solucion de Problemas de Sensores y Acondicionamiento de Señal D-09
//Practica 4 Sensor Resistivo
// ----------------------Configuracion del LCD-------------------------
#define LCD_RS_PIN PIN_D0
#define LCD_RW_PIN PIN_D1
#define LCD_ENABLE_PIN PIN_D2
#define LCD_DATA4 PIN_D3
#define LCD_DATA5 PIN_D4
#define LCD_DATA6 PIN_D5
#define LCD_DATA7 PIN_D6
// ------------------Configuraciones de Microcontrolador---------------
#include <18F4550.h>
#device adc=10
#fuses NOMCLR INTRC_IO MCLR NOWDT NOPROTECT PUT XT 
#use delay(clock=2000000)
#include <lcd.c>
float Medida=0;
int32 Medicion=0;
float cm=0;
// ---------------------------Funcion Principal------------------------
void main () {
setup_adc (ADC_CLOCK_DIV_16);
setup_adc_ports (ALL_ANALOG);
//Inicializacion del LCD
lcd_init ();
lcd_putc('\f');
lcd_gotoxy (1, 1);
lcd_putc("AguilarRodriguez");
lcd_gotoxy (5, 2);
lcd_putc("215860049");
delay_ms (3000);
lcd_putc('\f');
lcd_gotoxy (4, 1);
lcd_putc("Practica 4");
lcd_gotoxy (2, 2);
lcd_putc("Sensor Resistivo");
delay_ms (3000);
lcd_putc('\f');
while(1){
set_adc_channel (0);
delay_us (20);
//Leer puerto analogico y depositar el valor en medicion
medicion=read_adc();
delay_us (20);
medida=medicion;
//Transformar a gramos
cm=(0.01*(medida));
lcd_gotoxy(1,1);
//Imprimir los gramos en el lcd
printf(lcd_putc,"Distancia=%fcm", cm);
delay_us(20);
}
}
