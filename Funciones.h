

#define SETBIT(ADD,BIT) ADD |= (1 << BIT)
#define CLRBIT(ADD,BIT) ADD &= ~(1 << BIT)
#define CHKBIT(ADD,BIT) ADD & (1 << BIT)
#define GLOBAL                        SREG |= (1 << 7)
#define NOGLOBAL                SREG &= ~(1 << 7)
//#define        TOGGLE(ADD,BIT);        {if((ADD & (1 << BIT))) ADD &= (1 << BIT); else ADD |= (1 << BIT);}

/*
*      Definiciones para el timer 0 y 1
*
*/


#define Preescaler_1           1      // valores de configuracion del timer 
#define Preescaler_8           2
#define Preescaler_64          3
#define Preescaler_256         4
#define Preescaler_1024        5

/*
*      Definiciones para el ADC
*
*/
#define Preescaler_ADC_2         1      // valores de configuracion del timer
#define Preescaler_ADC_4         2
#define Preescaler_ADC_8         3
#define Preescaler_ADC_16        4
#define Preescaler_ADC_32        5
#define Preescaler_ADC_64        6
#define Preescaler_ADC_128       7
#define INICIA_ADC               8
#define INICIA_CONVERSION_ADC    9
#define DETEN_ADC                10
#define FREE_RUN_ADC             11
#define ACTIVA_INTERRUPCION_ADC  12
#define  CANAL_0                 13
#define  CANAL_1                 14
#define  CANAL_2                 15
#define  CANAL_3                 16
#define  CANAL_4                 17
#define  CANAL_5                 18
#define  CANAL_6                 19
#define  VREF_AVCC               20
#define  VREF_11                 21
#define  NO_AVCC                 22
#define         ADC_IZQUIERDA    23
#define  ADC_DERECHA             24

// definiciones para el contador y captura
#define Filtro_entrada_on        1
#define Filtro_entrada_off       2
#define Entrada_Flanco_pos       3
#define  Entrada_flanco_neg      4


/*
*      Definiciones para el PWM
*
*/
 #define    FAST_PWM             1
 #define    FASE_PWM             2
 
 
 /**************************************************
 *
 *      Función para arrancar el timer 0 de 8 bits 
 *      Parametros permitidos:
 *      
 *
 */
void Inicia_timer0(){
        
        SETBIT(TIMSK0,0);        
}

 /**************************************************
 *
 *      Función para detener el timer 0 de 8 bits 
 *      Parametros permitidos:
 *      
 *
 */
  void Detiene_timer0(){
         
         CLRBIT(TIMSK0,0);

 }
  
 
 /**************************************************
 *
 *      Función para configurar el timer 0 de 8 bits
 *      Parametros permitidos:
 *      Preescaler1, Preescales8, Preescaler64, Preescaler256,Preescaler1024
 *
 */
 

void configuraTIMER0(int parametros){
        
        
        switch(parametros){
                case Preescaler_1:
                
                        SETBIT(TCCR0A,0);                  // reloj con preescalamiento de 1
                        CLRBIT(TCCR0A,1);
                        CLRBIT(TCCR0A,2);
                        //CS02=1;//
                break;
                case Preescaler_8:
                        CLRBIT(TCCR0A,0);                  // reloj con preescalamiento de 8
                        SETBIT(TCCR0A,1);
                        CLRBIT(TCCR0A,2);
                        
                break;
                case Preescaler_64:
                        SETBIT(TCCR0A,0);                  // reloj con preescalamiento de 64
                        SETBIT(TCCR0A,1);
                        CLRBIT(TCCR0A,2);
                        
                break;        
                case Preescaler_256:
                        CLRBIT(TCCR0A,0);                  // reloj con preescalamiento de 256
                        CLRBIT(TCCR0A,1);
                        SETBIT(TCCR0A,2);
                break;                
                case Preescaler_1024:
                        SETBIT(TCCR0A,0);                  // reloj con preescalamiento de 1024
                        CLRBIT(TCCR0A,1);
                        SETBIT(TCCR0A,2);
                break;                
        }
                
}

   /**************************************************
 *
 *      Función para arrancar el timer 0 de 8 bits en un valor
 *      Parametros permitidos:
 *      valor de inicio
 *
 */

void Set_timer0(unsigned char valor ){

      TCNT0= valor;

}
 /**************************************************
 *
 *      Función para configurar el timer 1 de 16 bits 
 *      Parametros permitidos:
 *      Preescaler1, Preescales8, Preescaler64, Preescaler256,Preescaler1024
 *
 */

void configuraTIMER1(int parametros){
        

        switch(parametros){
                case Preescaler_1:
                //        TCCR1B=0;
                        SETBIT(TCCR1B,0);                  // reloj con preescalamiento de 1
                        CLRBIT(TCCR1B,1);
                        CLRBIT(TCCR1B,2);

                break;
                case Preescaler_8:
                CLRBIT(TCCR1B,0);                  // reloj con preescalamiento de 8
                        SETBIT(TCCR1B,1);
                        CLRBIT(TCCR1B,2);

                break;
                case Preescaler_64:
                        SETBIT(TCCR1B,0);                  // reloj con preescalamiento de 64
                        SETBIT(TCCR1B,1);
                        CLRBIT(TCCR1B,2);
        
                break;
                case Preescaler_256:
                        CLRBIT(TCCR1B,0);                  // reloj con preescalamiento de 256
                        CLRBIT(TCCR1B,1);
                        SETBIT(TCCR1B,2);
                break;
                case Preescaler_1024:
                        SETBIT(TCCR1B,0);                  // reloj con preescalamiento de 1024
                        CLRBIT(TCCR1B,1);
                        SETBIT(TCCR1B,2);
                break;
                
        }        
}


 /**************************************************
 *
 *      Función para arrancar el timer 1 16 bits 
 *      Parametros permitidos:
 *      
 *
 */
 
void Inicia_timer1(){
                
        SETBIT(TIMSK1,0);        // habilita interrupcion timer 1
}

  /**************************************************
 *
 *      Función para arrancar el timer 1 16 bits
 *      Parametros permitidos:
 *       valor de inicio
 *
 */

void Set_timer1(unsigned int valor ){

      TCNT1H= valor>>8;
      TCNT1L= valor& 0xFF;
}
 /**************************************************
 *
 *      Función para detener el timer 1 de 16 bits 
 *      Parametros permitidos:
 *      
 *
 */
 
void Detiene_timer1(){
        
        CLRBIT(TIMSK1,0);        // detiene interrupcion timer 1
}
 
 
 /**************************************************
 *
 *      Función para configurar el contador del timer1 
 *      Parametros permitidos:
 *      Filtro_entrada_on: filtro de entrada activado
 *                Filtro_entrada_off:  filtro de entrada desactivado
 *      Entrada_Flanco_pos : captura en el flanco positivo
 *                Entrada_Flanco_neg : captura en el flanco negativo
 */
 
void Configura_contador1(int Parametros){
        
        switch(Parametros){
                
                case Filtro_entrada_on:
                        SETBIT(TCCR1B,ICNC1);     
                break;
                case Filtro_entrada_off:
                        CLRBIT(TCCR1B,ICNC1); 
                break;        
                case Entrada_Flanco_pos:
                        SETBIT(TCCR1B,ICES1); 
                break;
                case Entrada_flanco_neg:
                        CLRBIT(TCCR1B,ICES1);
                break;        
                
        }
}

 /**************************************************
 *
 *      Función para configurar las interrupciones externas
 *      Parametros permitidos:  numero de interrupcion a habilitar
 *
 *
 *
 */
  void Habilita_Interrupcion(int Num_int){
       SETBIT(EIMSK,Num_int) ;   // 10.1.3  EIMSK  es el registro de habilitación 
                                 //   de las interrupciones externas
                                 // habilito solo la que necesito
  }
 /**************************************************
 *
 *      Función para configurar las interrupciones externas
 *      Parametros permitidos:  numero de interrupcion a habilitar
 *
 *
 *
 */
  void Desabilita_Interrupcion(int Num_int){
       CLRBIT(EIMSK,Num_int) ;   // 10.1.3  EIMSK  es el registro de habilitación
                                 //   de las interrupciones externas
                                 // desabilito solo la que necesito
  }

 /**************************************************
 *
 *      Función para configurar el ADC
 *      Parametros permitidos:
 *       int Parametros :
 *                        Preescaler_ADC_2                :   preescalar por 2
 *                        Preescaler_ADC_4                :   preescalar por 4
 *                        Preescaler_ADC_8                :   preescalar por 8
 *                        Preescaler_ADC_16                :  preescalar por 16
 *                        Preescaler_ADC_32                :  preescalar por 32
 *                        Preescaler_ADC_64                :  preescalar por 64
 *                        Preescaler_ADC_128                 : preescalar por 128
 *                        INICIA_CONVERSION_ADC        :inicia una conversion AD
 *                        INICIA_ADC                                : inicia el modulo AD
 *                        DETEN_ADC                                : detiene el modulo AD
 *                        FREE_RUN_ADC                          : Ad en modo Freerun
 *                        ACTIVA_INTERRUPCION_ADC : inicia la interrupcion del AD
 *                        CANAL_0                                        : selecciona el canal 0 del AD
 *                        CANAL_1                                        : selecciona el canal 1 del AD
 *                        CANAL_2                                        : selecciona el canal 2 del AD
 *                        CANAL_3                                        : selecciona el canal 3 del AD
 *                        CANAL_4                                        : selecciona el canal 4 del AD
                        CANAL_5                                        : selecciona el canal 4 del AD
                        CANAL_6                                        : selecciona el canal 4 del AD
 *                        VREF_11                                        : selecciona referencia interna de 1.1 V
 *                        VREF_AVCC                                : selecciona referencia de Avcc
 *                        NO_AVCC                                        : selecciona sin referencia interna
 *                        ADC_IZQUIERDA                        : selecciona justificacion izquierda
 *                        ADC_DERECHA                                : Selecciona justificacion Derecha
 */


void Configura_adc(int parametros){

        switch (parametros){

                case Preescaler_ADC_2:
                        SETBIT(ADCSRA,ADPS0);
                        CLRBIT(ADCSRA,ADPS1);
                        CLRBIT(ADCSRA,ADPS2);
                break;

                case Preescaler_ADC_4:
                        CLRBIT(ADCSRA,ADPS0);
                        SETBIT(ADCSRA,ADPS1);
                        CLRBIT(ADCSRA,ADPS2);
                break;
                case Preescaler_ADC_8:
                        SETBIT(ADCSRA,ADPS0);
                        SETBIT(ADCSRA,ADPS1);
                        CLRBIT(ADCSRA,ADPS2);
                break;
                case Preescaler_ADC_16:
                        CLRBIT(ADCSRA,ADPS0);
                        CLRBIT(ADCSRA,ADPS1);
                        SETBIT(ADCSRA,ADPS2);
                break;
                case Preescaler_ADC_32:
                        SETBIT(ADCSRA,ADPS0);
                        CLRBIT(ADCSRA,ADPS1);
                        SETBIT(ADCSRA,ADPS2);
                break;
                case Preescaler_ADC_64:
                        CLRBIT(ADCSRA,ADPS0);
                        SETBIT(ADCSRA,ADPS1);
                        SETBIT(ADCSRA,ADPS2);
                break;
                case Preescaler_ADC_128:
                        SETBIT(ADCSRA,ADPS0);
                        SETBIT(ADCSRA,ADPS1);
                        SETBIT(ADCSRA,ADPS2);
                break;

                case INICIA_CONVERSION_ADC:
                        SETBIT(ADCSRA,ADSC);
                break;
                case INICIA_ADC:
                        SETBIT(ADCSRA,ADEN);
                break;
                case DETEN_ADC:
                        SETBIT(ADCSRA,ADEN);
                break;
                case FREE_RUN_ADC:
                        SETBIT(ADCSRA,ADATE);
                break;
                case ACTIVA_INTERRUPCION_ADC:
                        SETBIT(ADCSRA,ADIE);
                break;
                // seleccion de canales AD
                case CANAL_0:
                        CLRBIT(ADMUX,MUX0);
                        CLRBIT(ADMUX,MUX1);
                        CLRBIT(ADMUX,MUX2);
                        CLRBIT(ADMUX,MUX3);
                break;

                case CANAL_1:
                        SETBIT(ADMUX,MUX0);
                        CLRBIT(ADMUX,MUX1);
                        CLRBIT(ADMUX,MUX2);
                        CLRBIT(ADMUX,MUX3);
                break;
                case CANAL_2:
                        CLRBIT(ADMUX,MUX0);
                        SETBIT(ADMUX,MUX1);
                        CLRBIT(ADMUX,MUX2);
                        CLRBIT(ADMUX,MUX3);
                break;
                case CANAL_3:
                        SETBIT(ADMUX,MUX0);
                        SETBIT(ADMUX,MUX1);
                        CLRBIT(ADMUX,MUX2);
                        CLRBIT(ADMUX,MUX3);
                break;
                case CANAL_4:
                        CLRBIT(ADMUX,MUX0);
                        CLRBIT(ADMUX,MUX1);
                        SETBIT(ADMUX,MUX2);
                        CLRBIT(ADMUX,MUX3);
                        //SETBIT(DIDR0,ADC4D);    // deshabilita el buffer de entrada digital
                break;
                case CANAL_5:
                        SETBIT(ADMUX,MUX0);
                        CLRBIT(ADMUX,MUX1);
                        SETBIT(ADMUX,MUX2);
                        CLRBIT(ADMUX,MUX3);
                        //SETBIT(DIDR0,ADC4D);    // deshabilita el buffer de entrada digital
                break;
                case CANAL_6:
                        CLRBIT(ADMUX,MUX0);
                        SETBIT(ADMUX,MUX1);
                        SETBIT(ADMUX,MUX2);
                        CLRBIT(ADMUX,MUX3);
                        //SETBIT(DIDR0,ADC4D);    // deshabilita el buffer de entrada digital
                break;
                case VREF_11:
                        SETBIT(ADMUX,REFS1);
                        SETBIT(ADMUX,REFS0);
                break;
                case VREF_AVCC:
                        CLRBIT(ADMUX,REFS1);
                        SETBIT(ADMUX,REFS0);
                break;
                case NO_AVCC:
                        CLRBIT(ADMUX,REFS1);
                        CLRBIT(ADMUX,REFS0);
                break;
                case ADC_IZQUIERDA:
                        SETBIT(ADMUX,ADLAR); // justificacion a la izquierda
                break;
                case ADC_DERECHA:
                        CLRBIT(ADMUX,ADLAR); // justificacion a la DERECHA
                break;
        }
}

  /**************************************************


*
 *      Función para configurar el puerto serial
 *      configura el puerto 1 debido a que el puerto 0 esta siendo usado por
 *      el puerto de programacion
 *      Parametros permitidos:
 *
 *
 */

void USART_init(){

//        UBRR1H = (char)(BAUD_PREESCALER>>8);
//        UBRR1L = (char)(BAUD_PREESCALER & 0xFF);

        UBRR1H = 0;
        UBRR1L = 8;   // para 115200 con 16 Mhz
       // UBRR1L = 51;      // este valor es para 9600 con 8 Mhz
        UCSR1B = (1<<RXEN1)|(1<<TXEN1);
        //UCSR0C = (3<<UCSZ00);
        SETBIT(UCSR1C,UCSZ10);    // configuracion de 8 bits
        SETBIT(UCSR1C,UCSZ11);

}


void USART_send( char dato){

        while(!(UCSR1A & (1<<UDRE1)));
        UDR1 = dato;

}


  /*  función para asignar un manejador para las funciones de impresión al puerto serial
*    lo uso para debug en el puerto serial, es parte de las funciones de
*     MikroC  pero la cambie por una función propia
*/

 void PrintHandler(char c){

  USART_send(c);

}
 /*   funcion Lee_canal_AD
 *    Lee el valor analogico y lo regresa
 *    parametros de entrada : canal,    canal analogico a leer puede ser 0-7
 *    parametros de salida  : resultado  : entero de 16 bits contieniendo el resultado de la conversion AD
*/


int Lee_canal_AD (char canal){

    int resultado=0;
    char ByteL,ByteH;

    Configura_ADC (canal);
    Configura_ADC (INICIA_CONVERSION_ADC);
    do {
        // esperar que termine la conversion
    }while (CHKBIT(ADCSRA,ADSC));
    ByteL= ADCL;
    ByteH = ADCH;
    resultado= ByteH<<8 | ByteL;

    return (resultado);
}

