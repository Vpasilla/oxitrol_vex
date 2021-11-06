#line 1 "F:/Trabajo/proyectos/2019/oxitrol/Firmware/Oxitrol_VEX/Oxitrol_VEX.c"
#line 1 "f:/trabajo/proyectos/2019/oxitrol/firmware/oxitrol_vex/def_pines.h"
#line 20 "f:/trabajo/proyectos/2019/oxitrol/firmware/oxitrol_vex/def_pines.h"
 sbit SAL_POT at PORTA0_bit;
 sbit SAL_POT_dir at DDA0_bit;
 sbit SAL_digital at PORTA2_bit;
 sbit SAL_digital_dir at DDA2_bit;

 sbit CS at PORTB0_bit;
 sbit SCK at PORTB1_bit;
 sbit MOSI at PORTB2_bit;
 sbit MISO at PORTB3_bit;
 sbit PWM1 at PORTB5_bit;
 sbit PWM2 at PORTB7_bit;
 sbit S_pulso at PING3_bit;

 sbit CS_dir at DDB0_bit;
 sbit SCK_dir at DDB1_bit;
 sbit MOSI_dir at DDB2_bit;
 sbit MISO_dir at DDB3_bit;
 sbit PWM1_dir at DDB5_bit;
 sbit PWM2_dir at DDB7_bit;
 sbit S_pulso_dir at DDG3_bit;


 sbit SAL_OD at PORTE2_bit;

 sbit SAL_OD_dir at DDE2_bit;
#line 1 "f:/trabajo/proyectos/2019/oxitrol/firmware/oxitrol_vex/funciones.h"
#line 73 "f:/trabajo/proyectos/2019/oxitrol/firmware/oxitrol_vex/funciones.h"
void Inicia_timer0(){

  TIMSK0 |= (1 << 0) ;
}
#line 85 "f:/trabajo/proyectos/2019/oxitrol/firmware/oxitrol_vex/funciones.h"
 void Detiene_timer0(){

  TIMSK0 &= ~(1 << 0) ;

 }
#line 101 "f:/trabajo/proyectos/2019/oxitrol/firmware/oxitrol_vex/funciones.h"
void configuraTIMER0(int parametros){


 switch(parametros){
 case  1 :

  TCCR0A |= (1 << 0) ;
  TCCR0A &= ~(1 << 1) ;
  TCCR0A &= ~(1 << 2) ;

 break;
 case  2 :
  TCCR0A &= ~(1 << 0) ;
  TCCR0A |= (1 << 1) ;
  TCCR0A &= ~(1 << 2) ;

 break;
 case  3 :
  TCCR0A |= (1 << 0) ;
  TCCR0A |= (1 << 1) ;
  TCCR0A &= ~(1 << 2) ;

 break;
 case  4 :
  TCCR0A &= ~(1 << 0) ;
  TCCR0A &= ~(1 << 1) ;
  TCCR0A |= (1 << 2) ;
 break;
 case  5 :
  TCCR0A |= (1 << 0) ;
  TCCR0A &= ~(1 << 1) ;
  TCCR0A |= (1 << 2) ;
 break;
 }

}
#line 146 "f:/trabajo/proyectos/2019/oxitrol/firmware/oxitrol_vex/funciones.h"
void Set_timer0(unsigned char valor ){

 TCNT0= valor;

}
#line 159 "f:/trabajo/proyectos/2019/oxitrol/firmware/oxitrol_vex/funciones.h"
void configuraTIMER1(int parametros){


 switch(parametros){
 case  1 :

  TCCR1B |= (1 << 0) ;
  TCCR1B &= ~(1 << 1) ;
  TCCR1B &= ~(1 << 2) ;

 break;
 case  2 :
  TCCR1B &= ~(1 << 0) ;
  TCCR1B |= (1 << 1) ;
  TCCR1B &= ~(1 << 2) ;

 break;
 case  3 :
  TCCR1B |= (1 << 0) ;
  TCCR1B |= (1 << 1) ;
  TCCR1B &= ~(1 << 2) ;

 break;
 case  4 :
  TCCR1B &= ~(1 << 0) ;
  TCCR1B &= ~(1 << 1) ;
  TCCR1B |= (1 << 2) ;
 break;
 case  5 :
  TCCR1B |= (1 << 0) ;
  TCCR1B &= ~(1 << 1) ;
  TCCR1B |= (1 << 2) ;
 break;

 }
}
#line 205 "f:/trabajo/proyectos/2019/oxitrol/firmware/oxitrol_vex/funciones.h"
void Inicia_timer1(){

  TIMSK1 |= (1 << 0) ;
}
#line 218 "f:/trabajo/proyectos/2019/oxitrol/firmware/oxitrol_vex/funciones.h"
void Set_timer1(unsigned int valor ){

 TCNT1H= valor>>8;
 TCNT1L= valor& 0xFF;
}
#line 231 "f:/trabajo/proyectos/2019/oxitrol/firmware/oxitrol_vex/funciones.h"
void Detiene_timer1(){

  TIMSK1 &= ~(1 << 0) ;
}
#line 247 "f:/trabajo/proyectos/2019/oxitrol/firmware/oxitrol_vex/funciones.h"
void Configura_contador1(int Parametros){

 switch(Parametros){

 case  1 :
  TCCR1B |= (1 << ICNC1) ;
 break;
 case  2 :
  TCCR1B &= ~(1 << ICNC1) ;
 break;
 case  3 :
  TCCR1B |= (1 << ICES1) ;
 break;
 case  4 :
  TCCR1B &= ~(1 << ICES1) ;
 break;

 }
}
#line 275 "f:/trabajo/proyectos/2019/oxitrol/firmware/oxitrol_vex/funciones.h"
 void Habilita_Interrupcion(int Num_int){
  EIMSK |= (1 << Num_int)  ;


 }
#line 288 "f:/trabajo/proyectos/2019/oxitrol/firmware/oxitrol_vex/funciones.h"
 void Desabilita_Interrupcion(int Num_int){
  EIMSK &= ~(1 << Num_int)  ;


 }
#line 326 "f:/trabajo/proyectos/2019/oxitrol/firmware/oxitrol_vex/funciones.h"
void Configura_adc(int parametros){

 switch (parametros){

 case  1 :
  ADCSRA |= (1 << ADPS0) ;
  ADCSRA &= ~(1 << ADPS1) ;
  ADCSRA &= ~(1 << ADPS2) ;
 break;

 case  2 :
  ADCSRA &= ~(1 << ADPS0) ;
  ADCSRA |= (1 << ADPS1) ;
  ADCSRA &= ~(1 << ADPS2) ;
 break;
 case  3 :
  ADCSRA |= (1 << ADPS0) ;
  ADCSRA |= (1 << ADPS1) ;
  ADCSRA &= ~(1 << ADPS2) ;
 break;
 case  4 :
  ADCSRA &= ~(1 << ADPS0) ;
  ADCSRA &= ~(1 << ADPS1) ;
  ADCSRA |= (1 << ADPS2) ;
 break;
 case  5 :
  ADCSRA |= (1 << ADPS0) ;
  ADCSRA &= ~(1 << ADPS1) ;
  ADCSRA |= (1 << ADPS2) ;
 break;
 case  6 :
  ADCSRA &= ~(1 << ADPS0) ;
  ADCSRA |= (1 << ADPS1) ;
  ADCSRA |= (1 << ADPS2) ;
 break;
 case  7 :
  ADCSRA |= (1 << ADPS0) ;
  ADCSRA |= (1 << ADPS1) ;
  ADCSRA |= (1 << ADPS2) ;
 break;

 case  9 :
  ADCSRA |= (1 << ADSC) ;
 break;
 case  8 :
  ADCSRA |= (1 << ADEN) ;
 break;
 case  10 :
  ADCSRA |= (1 << ADEN) ;
 break;
 case  11 :
  ADCSRA |= (1 << ADATE) ;
 break;
 case  12 :
  ADCSRA |= (1 << ADIE) ;
 break;

 case  13 :
  ADMUX &= ~(1 << MUX0) ;
  ADMUX &= ~(1 << MUX1) ;
  ADMUX &= ~(1 << MUX2) ;
  ADMUX &= ~(1 << MUX3) ;
 break;

 case  14 :
  ADMUX |= (1 << MUX0) ;
  ADMUX &= ~(1 << MUX1) ;
  ADMUX &= ~(1 << MUX2) ;
  ADMUX &= ~(1 << MUX3) ;
 break;
 case  15 :
  ADMUX &= ~(1 << MUX0) ;
  ADMUX |= (1 << MUX1) ;
  ADMUX &= ~(1 << MUX2) ;
  ADMUX &= ~(1 << MUX3) ;
 break;
 case  16 :
  ADMUX |= (1 << MUX0) ;
  ADMUX |= (1 << MUX1) ;
  ADMUX &= ~(1 << MUX2) ;
  ADMUX &= ~(1 << MUX3) ;
 break;
 case  17 :
  ADMUX &= ~(1 << MUX0) ;
  ADMUX &= ~(1 << MUX1) ;
  ADMUX |= (1 << MUX2) ;
  ADMUX &= ~(1 << MUX3) ;

 break;
 case  18 :
  ADMUX |= (1 << MUX0) ;
  ADMUX &= ~(1 << MUX1) ;
  ADMUX |= (1 << MUX2) ;
  ADMUX &= ~(1 << MUX3) ;

 break;
 case  19 :
  ADMUX &= ~(1 << MUX0) ;
  ADMUX |= (1 << MUX1) ;
  ADMUX |= (1 << MUX2) ;
  ADMUX &= ~(1 << MUX3) ;

 break;
 case  21 :
  ADMUX |= (1 << REFS1) ;
  ADMUX |= (1 << REFS0) ;
 break;
 case  20 :
  ADMUX &= ~(1 << REFS1) ;
  ADMUX |= (1 << REFS0) ;
 break;
 case  22 :
  ADMUX &= ~(1 << REFS1) ;
  ADMUX &= ~(1 << REFS0) ;
 break;
 case  23 :
  ADMUX |= (1 << ADLAR) ;
 break;
 case  24 :
  ADMUX &= ~(1 << ADLAR) ;
 break;
 }
}
#line 462 "f:/trabajo/proyectos/2019/oxitrol/firmware/oxitrol_vex/funciones.h"
void USART_init(){




 UBRR1H = 0;
 UBRR1L = 8;

 UCSR1B = (1<<RXEN1)|(1<<TXEN1);

  UCSR1C |= (1 << UCSZ10) ;
  UCSR1C |= (1 << UCSZ11) ;

}


void USART_send( char dato){

 while(!(UCSR1A & (1<<UDRE1)));
 UDR1 = dato;

}
#line 491 "f:/trabajo/proyectos/2019/oxitrol/firmware/oxitrol_vex/funciones.h"
 void PrintHandler(char c){

 USART_send(c);

}
#line 503 "f:/trabajo/proyectos/2019/oxitrol/firmware/oxitrol_vex/funciones.h"
int Lee_canal_AD (char canal){

 int resultado=0;
 char ByteL,ByteH;

 Configura_ADC (canal);
 Configura_ADC ( 9 );
 do {

 }while ( ADCSRA & (1 << ADSC) );
 ByteL= ADCL;
 ByteH = ADCH;
 resultado= ByteH<<8 | ByteL;

 return (resultado);
}
#line 1 "f:/trabajo/proyectos/2019/oxitrol/firmware/oxitrol_vex/funciones_vex.h"
#line 38 "f:/trabajo/proyectos/2019/oxitrol/firmware/oxitrol_vex/funciones_vex.h"
void inicializar_puertos(){

 SAL_POT_dir=  1 ;
 SAL_digital_dir= 1 ;
 PWM1_dir =  1  ;
 PWM2_dir =  1  ;
 S_pulso_dir = 0 ;
 SAL_OD_dir =  1 ;
 SAL_POT =0;

 PWM1_dir=  1 ;
 PWM2_dir=  1 ;
 CS_dir =  0 ;
 MOSI_dir=  1 ;
 MISO_dir= 1  ;
 SCK_dir =  1 ;

}
#line 63 "f:/trabajo/proyectos/2019/oxitrol/firmware/oxitrol_vex/funciones_vex.h"
void Abrir_valvula_1(int PWM1){

 OCR1AH =0;
 OCR1AL=PWM1;

 }
#line 73 "f:/trabajo/proyectos/2019/oxitrol/firmware/oxitrol_vex/funciones_vex.h"
void Abrir_valvula_2(int PWM2){

 OCR1CH =0;
 OCR1CL=PWM2;
 }
#line 106 "f:/trabajo/proyectos/2019/oxitrol/firmware/oxitrol_vex/funciones_vex.h"
void pwm_init(void)
{

 TCCR1A =0xA9;
 TCCR1B =0x02;
}
#line 122 "f:/trabajo/proyectos/2019/oxitrol/firmware/oxitrol_vex/funciones_vex.h"
float Leer_Presion_prox(){
int i_lectura_ADC;
float f_Presion;

 i_lectura_ADC = Lee_canal_AD( 13  );
 f_Presion =i_lectura_ADC * 0.0166;
 return ( f_Presion);

}
#line 1 "f:/trabajo/proyectos/2019/oxitrol/firmware/oxitrol_vex/config_can.h"
#line 5 "f:/trabajo/proyectos/2019/oxitrol/firmware/oxitrol_vex/config_can.h"
 unsigned char Can_Init_Flags, Can_Send_Flags, Can_Rcv_Flags;
unsigned char Rx_Data_Len;
char RxTx_Data[8];
char Msg_Rcvd = 0;
long ID_1st = 0x100, ID_2nd = 0x200,ID_3er = 0x300,ID_4to = 0x400,ID_5to = 0x500;
long Rx_ID;
#line 41 "f:/trabajo/proyectos/2019/oxitrol/firmware/oxitrol_vex/config_can.h"
const unsigned int SJW = 1;
const unsigned int BRP = 2;
const unsigned int PHSEG1 = 4;
const unsigned int PHSEG2 = 3;
const unsigned int PROPSEG = 8;
const unsigned int CAN_CONFIG_FLAGS =
 _CAN_CONFIG_SAMPLE_ONCE &
 _CAN_CONFIG_XTD_MSG;
#line 64 "f:/trabajo/proyectos/2019/oxitrol/firmware/oxitrol_vex/config_can.h"
void ConfiguraCAN(){
 Can_Send_Flags = _CAN_IDE_XTD_FRAME
 & _CAN_NO_RTR_FRAME;

 Can_Init_Flags = _CAN_CONFIG_SAMPLE_THRICE
 & _CAN_CONFIG_XTD_MSG;

 CANInitialize(SJW, BRP, PHSEG1, PHSEG2, PROPSEG, CAN_CONFIG_FLAGS);
 CANSetOperationMode(_CAN_MODE_STANDBY,0xFF);


 CANSetFilter(CAN_RX_FILTER_3, -1, _CAN_CONFIG_XTD_MSG);
 CANSetFilter(CAN_RX_FILTER_4, ID_5to, _CAN_CONFIG_XTD_MSG);
 CANSetFilter(CAN_RX_FILTER_5, ID_4to, _CAN_CONFIG_XTD_MSG);
 CANSetFilter(CAN_RX_FILTER_6, ID_3er, _CAN_CONFIG_XTD_MSG);
 CANSetFilter(CAN_RX_FILTER_7, ID_1st, _CAN_CONFIG_XTD_MSG);
 CANSetFilter(CAN_RX_FILTER_8, ID_2nd, _CAN_CONFIG_XTD_MSG);
 CANSetFilter(CAN_RX_FILTER_9, 0x700, _CAN_CONFIG_XTD_MSG);
 CANSetFilter(CAN_RX_FILTER_10, 0x300, _CAN_CONFIG_XTD_MSG);
 CANSetFilter(CAN_RX_FILTER_11, -1, _CAN_CONFIG_XTD_MSG);
 CANSetFilter(CAN_RX_FILTER_12, -1, _CAN_CONFIG_XTD_MSG);
 CANSetFilter(CAN_RX_FILTER_13, -1, _CAN_CONFIG_XTD_MSG);
 CANSetFilter(CAN_RX_FILTER_14, -1, _CAN_CONFIG_XTD_MSG);



 CANSetMask(CAN_RX_MASK_3, -1, _CAN_CONFIG_XTD_MSG);
 CANSetMask(CAN_RX_MASK_4, -1, _CAN_CONFIG_XTD_MSG);
 CANSetMask(CAN_RX_MASK_5, -1, _CAN_CONFIG_XTD_MSG);
 CANSetMask(CAN_RX_MASK_6, -1, _CAN_CONFIG_XTD_MSG);
 CANSetMask(CAN_RX_MASK_7, -1, _CAN_CONFIG_XTD_MSG);
 CANSetMask(CAN_RX_MASK_8, -1, _CAN_CONFIG_XTD_MSG);
 CANSetMask(CAN_RX_MASK_9, -1, _CAN_CONFIG_XTD_MSG);
 CANSetMask(CAN_RX_MASK_10, -1, _CAN_CONFIG_XTD_MSG);
 CANSetMask(CAN_RX_MASK_11, -1, _CAN_CONFIG_XTD_MSG);
 CANSetMask(CAN_RX_MASK_12, -1, _CAN_CONFIG_XTD_MSG);
 CANSetMask(CAN_RX_MASK_13, -1, _CAN_CONFIG_XTD_MSG);
 CANSetMask(CAN_RX_MASK_14, -1, _CAN_CONFIG_XTD_MSG);


 CANSetOperationMode(_CAN_MODE_ENABLE,0xFF);

}
#line 66 "F:/Trabajo/proyectos/2019/oxitrol/Firmware/Oxitrol_VEX/Oxitrol_VEX.c"
int i_PWM_Valvula1;
int i_PWM_Valvula2;


 float Pres_CPAP_deseada,Pres_CPAP_Med;
 float error_cpap, Error_CPAP_accu;


 int BIPAP_TA;
 int BIPAP_TB;
 bit TA;
 int contador_TA;
 int contador_TB;
 float Pres_BIPAP_deseada;
 float Presion_EPAP;
 float Presion_IPAP;



 bit Pulso_apnea,pulso_apnea_anterior;
 bit Apnea_detectada;
 int Cont_Bipap_apnea_seg;
 int Limite_contador_apnea_seg;
 int Cont_apnea_ticks;
 int Cont_apnea_seg;


 bit Tick;
 bit Tick2;
 int Contador_ticks, Contador_ticks2;
 unsigned char Codigo_control;
#line 104 "F:/Trabajo/proyectos/2019/oxitrol/Firmware/Oxitrol_VEX/Oxitrol_VEX.c"
 void Iniciar_comando (int codigo);
 void Servo_presion(float pres_deseada);
 void Timing_BIPAP(int T1,int T2);
 void Timing_SNIPPV(int T1,int T2);
#line 116 "F:/Trabajo/proyectos/2019/oxitrol/Firmware/Oxitrol_VEX/Oxitrol_VEX.c"
void Timer0Overflow_ISR() org IVT_ADDR_TIMER0_OVF {
 Contador_ticks++ ;
 if (Contador_ticks >= 5){
 Tick= 1 ;
 Contador_ticks=0;
 }
 Contador_ticks2++ ;
 if (Contador_ticks2 >= 10){
 Tick2= 1 ;
 Contador_ticks2=0;
 }
 Set_timer0(100);
}

void main() {



 inicializar_puertos();
 Configura_ADC ( 7 );
 Configura_ADC ( 13 );
 Configura_ADC ( 20 );
 Configura_ADC ( 8 );
 ConfiguraCAN();
 pwm_init();
 SAL_POT = 1;
 USART_init ();
 configuraTIMER0( 5 );
 SREG_I_bit = 1 ;
 Inicia_timer0();

 i_PWM_Valvula1=0;
 i_PWM_Valvula2=0;
 Pres_CPAP_deseada=0;
 Contador_ticks =0;
 Contador_ticks2 =0;
 Abrir_valvula_1( i_PWM_Valvula1);
 PrintOut(PrintHandler, "\n\r\n\rControlador VEX"
 "\n\r Versión 1.0"
 "\n\r>Iniciando sistema\n\r ");
 Codigo_control= 1 ;
#line 169 "F:/Trabajo/proyectos/2019/oxitrol/Firmware/Oxitrol_VEX/Oxitrol_VEX.c"
 while(1){
 if (Tick) {
 Tick = 0 ;
 SAL_digital= ~SAL_digital;
 Msg_Rcvd = CANRead(&Rx_ID, &RxTx_Data, &Rx_Data_Len, &Can_Rcv_Flags);
 if (Msg_Rcvd){
 if (Rx_ID ==0x200){
 Codigo_control= RxTx_Data[0];
 Iniciar_comando(Codigo_control);

 }
 }
 switch ( Codigo_control){
 case  1  :


 break;
 case  2  :
 PrintOut(PrintHandler, "\n\rVerf modulo ");
 break;
 case  3  :
 PrintOut(PrintHandler, "\n\rcalibracion ");
 break;
 case  4  :

 Servo_presion(Pres_CPAP_deseada);
 break;
 case  5  :



 Timing_BIPAP(BIPAP_TA,BIPAP_TB);
 Servo_presion(Pres_BIPAP_deseada);
 break;
 case  6  :



 if ( Apnea_detectada ) {
 Cont_apnea_ticks++;
 if (Cont_apnea_ticks >=20 ){
 Cont_Bipap_apnea_seg++;

 if (Cont_Bipap_apnea_seg >= 120 ){
 Cont_apnea_ticks= 0;
 Cont_apnea_seg= 0;
 Apnea_detectada=  0 ;
 PrintOut(PrintHandler, "\n\r modoBipap terminado ");
 PrintOut(PrintHandler, "\n\r regresando a CPAP ");

 }
 Cont_apnea_ticks= 0;
 }
 Timing_BIPAP(BIPAP_TA,BIPAP_TB);
 Servo_presion(Pres_BIPAP_deseada);

 }
 else {
 Pulso_apnea =S_pulso;
 if (Pulso_apnea == pulso_apnea_anterior ){
 Cont_apnea_ticks++;
 if (Cont_apnea_ticks >=20 ){
 Cont_apnea_seg++;

 if (Cont_apnea_seg >= Limite_contador_apnea_seg ){
 Apnea_detectada=  1 ;
 Cont_Bipap_apnea_seg=0;
 PrintOut(PrintHandler, "\n\r Apnea detectada ");
 PrintOut(PrintHandler, "\n\r Pasando a modo bipap ");


 }
 Cont_apnea_ticks=0;
 }
 }
 else {
 Cont_apnea_ticks= 0;
 Cont_apnea_seg= 0;
 PrintOut(PrintHandler, "\n\r Pulso: ");
 }
 pulso_apnea_anterior=Pulso_apnea;
 Servo_presion(Pres_CPAP_deseada);

 }
 break;
 case  7  :


 if ( Apnea_detectada ){
 Cont_apnea_ticks++;
 if (Cont_apnea_ticks >=20 ){
 Cont_Bipap_apnea_seg++;

 if (Cont_Bipap_apnea_seg >= 120 ){
 Cont_apnea_ticks= 0;
 Cont_apnea_seg= 0;
 Apnea_detectada=  0 ;
 PrintOut(PrintHandler, "\n\r modoBipap terminado ");
 PrintOut(PrintHandler, "\n\r regresando a SNIPPV ");
 }
 Cont_apnea_ticks= 0;
 }




 Timing_BIPAP(BIPAP_TA,BIPAP_TB);
 Servo_presion(Pres_BIPAP_deseada);

 }
 else {
 Pulso_apnea =S_pulso;
 if ( Pulso_apnea && !pulso_apnea_anterior ){
 Cont_apnea_ticks= 0;
 Cont_apnea_seg= 0;



 }
 else{
 Cont_apnea_ticks++;
 if (Cont_apnea_ticks >=20 ){
 Cont_apnea_seg++;

 if (Cont_apnea_seg >= Limite_contador_apnea_seg ){
 Apnea_detectada=  1 ;
 Cont_Bipap_apnea_seg=0;
 PrintOut(PrintHandler, "\n\r Apnea detectada ");
 PrintOut(PrintHandler, "\n\r Pasando a modo bipap ");
 }
 Cont_apnea_ticks=0;
 }
 }
 pulso_apnea_anterior=Pulso_apnea;




 Timing_SNIPPV(BIPAP_TA,BIPAP_TB);
 Servo_presion(Pres_BIPAP_deseada);

 }

 break;
 }
 }
 }
}
#line 327 "F:/Trabajo/proyectos/2019/oxitrol/Firmware/Oxitrol_VEX/Oxitrol_VEX.c"
 void Iniciar_comando (int codigo) {

 switch ( Codigo_control){
 case  1  :
 PrintOut(PrintHandler, "\n\rCAN Standby ");
 Abrir_valvula_1 ( 0);
 break;
 case  2  :
 PrintOut(PrintHandler, "\n\rCAN Verf modulo ");
 break;
 case  3  :
 PrintOut(PrintHandler, "\n\rCAN calibracion ");
 break;
 case  4  :


 PrintOut(PrintHandler, "\n\r Iniciando Modo CPAP ");
 Pres_CPAP_deseada = RxTx_Data[1]/10.0;
 Error_CPAP_accu=0.0;
 Error_CPAP=0.0;
 break;
 case  5  :
 PrintOut(PrintHandler, "\n\rModo Bipap ");
 Presion_EPAP=RxTx_Data[1]/10.0;
 Presion_IPAP=RxTx_Data[2]/10.0;
 BIPAP_TA=RxTx_Data[3];
 BIPAP_TB=RxTx_Data[4];
 Pres_BIPAP_deseada =Presion_EPAP ;
 contador_TA=0;
 contador_TB=0;
 Error_CPAP_accu=0.0;
 Error_CPAP=0.0;
 break;
 case  6  :



 PrintOut(PrintHandler, "\n\rModo A+CPAP ");
 TA= 1 ;

 Presion_EPAP=RxTx_Data[1]/10.0;
 Presion_IPAP=RxTx_Data[2]/10.0;
 BIPAP_TA=RxTx_Data[3];
 BIPAP_TB=RxTx_Data[4];
 Limite_contador_apnea_seg = RxTx_Data[5];
 Apnea_detectada = 0 ;
 Pres_BIPAP_deseada =Presion_EPAP ;
 Pres_CPAP_deseada = Presion_EPAP;

 contador_TA=0;
 contador_TB=0;
 Cont_apnea_ticks= 0;
 Cont_apnea_seg= 0;
 Cont_Bipap_apnea_seg=0;
 Error_CPAP_accu=0.0;
 Error_CPAP=0.0;

 break;
 case  7  :


 PrintOut(PrintHandler, "\n\rModo SNIPPV ");
 TA= 0 ;

 Presion_EPAP=RxTx_Data[1]/10.0;
 Presion_IPAP=RxTx_Data[2]/10.0;
 BIPAP_TA=RxTx_Data[3];
 BIPAP_TB=RxTx_Data[4];
 Limite_contador_apnea_seg = RxTx_Data[5];
 Apnea_detectada =  0 ;
 Pres_BIPAP_deseada =Presion_EPAP ;
 Pres_CPAP_deseada = Presion_EPAP;
 Cont_apnea_ticks= 0;
 Cont_Bipap_apnea_seg=0;
 Error_CPAP_accu=0.0;
 Error_CPAP=0.0;

 break;
 }
 }
#line 417 "F:/Trabajo/proyectos/2019/oxitrol/Firmware/Oxitrol_VEX/Oxitrol_VEX.c"
 void Servo_presion(float pres_deseada){
 int PWM_salida;
 float Pot_salida;

 PrintOut(PrintHandler, "\n\rPD= %3.2f PM = %3.2f  ",pres_deseada,Pres_CPAP_Med);
 Pres_CPAP_Med= Leer_Presion_prox();
 error_cpap= pres_deseada - Pres_CPAP_Med ;
 Pot_salida= error_cpap * 11.0+ Error_CPAP_accu *2.0 +120;
 Error_CPAP_accu =Error_CPAP_accu + error_cpap;
 if (Pot_salida > 0.0 ) {
 PWM_salida = (int) Pot_salida;
 } else{
 PWM_salida=0;
 }
 if (Pot_salida > 255.0 ) {
 PWM_salida = 255;
 }

 PrintOut(PrintHandler, " PWM= %d ",PWM_salida );
 if (S_pulso) {
 PrintOut(PrintHandler, " 1");
 }
 else{
 PrintOut(PrintHandler, " 0" );
 }
 Abrir_valvula_1 ( PWM_salida);

 }
#line 457 "F:/Trabajo/proyectos/2019/oxitrol/Firmware/Oxitrol_VEX/Oxitrol_VEX.c"
 void Timing_BIPAP(int T1,int T2){
 if (Tick2){
 if (TA) {

 contador_TA++;
 if (contador_TA >= T1){
 TA= 0 ;
 SAL_OD=0;
 contador_TA=0;
 Pres_BIPAP_deseada= Presion_EPAP;
 Error_CPAP_accu=0.0;
 Error_CPAP=0.0;
 }
 }
 else{
 contador_TB++;
 if (contador_TB >= T2){
 TA= 1 ;
 SAL_OD=1;
 contador_TB=0;
 Pres_BIPAP_deseada= Presion_IPAP;
 Error_CPAP_accu=0.0;
 Error_CPAP=0.0;
 }
 }
 Tick2= 0 ;
 }
 }
#line 493 "F:/Trabajo/proyectos/2019/oxitrol/Firmware/Oxitrol_VEX/Oxitrol_VEX.c"
 void Timing_SNIPPV(int T1,int T2){
 if (Tick2){
 if (S_pulso) {

 Pres_BIPAP_deseada= Presion_IPAP;
 }
 else{

 Pres_BIPAP_deseada= Presion_EPAP;
 }
 Tick2= 0 ;
 }
 }
