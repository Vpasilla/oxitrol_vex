
/*
 * Nombre del Proyecto:
    Controlador SMG
 * Copyright:
     Dr. Victor Pasilla Campos
     creado : 25 de enero de 2019
 * Descripción:
     este es el archivo de definiciones los pines  de control de la tarjeta Vex

   PA0   -------->  salidas de potencia controlada por Mosfet
   PA1   -------->  salida digital
   PB5   -------->  salida PWM1
   PA6   -------->  salida PWM2
   PG3   -------->  señal de pulso de salida  hacia el micro pequeño
   PE2   -------->  salida opendrain


  */
   sbit SAL_POT           at PORTA0_bit;
   sbit SAL_POT_dir       at DDA0_bit;
   sbit SAL_digital       at PORTA2_bit;
   sbit SAL_digital_dir   at DDA2_bit;

   sbit CS          at PORTB0_bit;
   sbit SCK         at PORTB1_bit;
   sbit MOSI        at PORTB2_bit;
   sbit MISO        at PORTB3_bit;
   sbit PWM1        at PORTB5_bit;   //
   sbit PWM2        at PORTB7_bit;   //
   sbit S_pulso     at PING3_bit;   //

   sbit CS_dir            at DDB0_bit;
   sbit SCK_dir           at DDB1_bit;
   sbit MOSI_dir          at DDB2_bit;
   sbit MISO_dir          at DDB3_bit;
   sbit PWM1_dir          at DDB5_bit;   //
   sbit PWM2_dir          at DDB7_bit;   //
   sbit S_pulso_dir       at DDG3_bit;   //


   sbit SAL_OD            at PORTE2_bit;

   sbit SAL_OD_dir        at DDE2_bit;

   #define  ENTRADA           0
   #define  SALIDA            1
   #define  OK                1



   //   termina archivo de definiciones