/*
 * Nombre del Proyecto:
    Controlador VEX
 * Copyright:
     Dr. Victor Pasilla Campos
     creado : 7 de mayo de 2018
 * Descripción:
     este es el archivo de funciones  de control de la tarjeta VEX
     
     */
     
     
/*
*     Funcion: inicializar_puertos()
*
*      se utiliza para inicializar los puertos de entrada y salida digital
*      y dejarlos en un estado conocido seguro, por ejemplo apagando todas las salidas
*
*
*/

#define cierto 1
#define falso  0

// definiciones de comandos
#define        Com_StandBy        1
#define        Com_Verf_Modulo    2
#define        Com_Calibracion   3
#define        Com_CPAP           4
#define        Com_BIPAP          5
#define        Com_ACPAP          6
#define        Com_SNIPPV         7





void inicializar_puertos(){

     SAL_POT_dir= SALIDA;
     SAL_digital_dir=SALIDA;
     PWM1_dir  = SALIDA ;
     PWM2_dir  = SALIDA ;
     S_pulso_dir =ENTRADA;
     SAL_OD_dir  = SALIDA;
     SAL_POT =0;

     PWM1_dir= SALIDA;
     PWM2_dir= SALIDA;
     CS_dir = ENTRADA;
     MOSI_dir= SALIDA;
     MISO_dir=SALIDA ;
     SCK_dir = SALIDA;

}



    /*
 *    Funcion para abrir la valvula 1
 *
 */
void  Abrir_valvula_1(int PWM1){

     OCR1AH =0; // siempre es cero ya que se usa solo 8 bits
     OCR1AL=PWM1;

 }
    /*
 *    Funcion para abrir la valvula 2
 *
 */
void  Abrir_valvula_2(int PWM2){

     OCR1CH =0; // siempre es cero ya que se usa solo 8 bits
     OCR1CL=PWM2;
 }
 
 

/************************************************************************/
/*  Funcion de inicializacion del modulo PWM                            */
/*  Parametros de entrada : Ninguno                                                                                */
/*  Valores de Retorno : Ninguno                                                                                */
/*  Timer/Counter1 Control Register A – TCCR1A
* Bit         7       6       5          4         3         2         1         0
*           COM1A1  COM1A0   COM1B1   COM1B0    COM1C1     COM1C0    WGM11     WGM10
*
* COM1A1 =1 y COM1A0 = 0 , clear OC1A on Compare Match set at TOP
* COM1B1 =1 y COM1B0 = 0 , clear OC1B on Compare Match set at top
* COM1C1 =1 y COM1C0 = 0 , clear OC1C on Compare Match set at top
* WGM11 =0 y  WGM10= 1   ,  PWM  CORREGIDO EN FASE  para eliminar glitch
*   TCCR1A=  1010 1001b = 0xA9
*   esta configuracion permite tener tres canales de PWM de 8 bits independientes
*  el CANAL_A , CANAL_B y CANAL_C   aunque el B no se usa
*
*  Timer/Counter2 Control Register B – TCCR1B
* Bit         7       6        5        4       3        2         1      0
*           ICNC1    ICES1     –      WGM13    WGM12    CS12     CS11    CS10
*
* WGM13    =0 y WGM12  = 0 ,
* CS11    =1 y CS10= 0 ,  clk /8
*   TCCR1B = 0000 0010b = 0x02
*
************************************************************************/
void pwm_init(void)
{

        TCCR1A =0xA9;
        TCCR1B =0x02;
}

/*
*    funcion para leer la presion proximal
*    parametros de entrada :ninguno
*    parametros de salida : Valor de la presion en cmH2O
*    utiliza el sensor Mpxv5004, por hardware se resta 1v y se multiplica por 3.0
*   al hacer la conversion a presion la salida del sensor esta es Kpa, se convierte al final multiplicando
*    por un unico factor para obtener cmH2O
*/

float Leer_Presion_prox(){
int i_lectura_ADC;
float f_Presion;

     i_lectura_ADC = Lee_canal_AD(CANAL_0 );
     f_Presion =i_lectura_ADC * 0.0166;      // este factor convierte a cmH2O
     return ( f_Presion);

}