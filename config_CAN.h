  /*
  *   archivo para configuracion  de la comunicacion CAN
  */
//// Variables para la comunicación CAN
 unsigned char Can_Init_Flags, Can_Send_Flags, Can_Rcv_Flags;     // can flags
unsigned char Rx_Data_Len;                                       // received data length in bytes
char RxTx_Data[8];                                               // can rx/tx data buffer
char Msg_Rcvd = 0;                                               // reception flag
long ID_1st = 0x100, ID_2nd = 0x200,ID_3er = 0x300,ID_4to = 0x400,ID_5to = 0x500;                      // modificar ID segun necesidades
long Rx_ID;



//*******
//// configuracion para el cristal de 16 MHz para la comunicacíon CAN  a 50Kb

/*
const unsigned int SJW = 1;
const unsigned int BRP = 20;
const unsigned int PHSEG1 = 5;
const unsigned int PHSEG2 = 2;
const unsigned int PROPSEG = 8;
const unsigned int CAN_CONFIG_FLAGS =
                                       _CAN_CONFIG_SAMPLE_ONCE &
                                       _CAN_CONFIG_XTD_MSG;
 */
//*******
//// configuracion para el cristal de 16 MHz para la comunicacíon CAN  a 125Kb
/*
const unsigned int SJW = 2;
const unsigned int BRP = 8;
const unsigned int PHSEG1 = 4;
const unsigned int PHSEG2 = 3;
const unsigned int PROPSEG = 8;
const unsigned int CAN_CONFIG_FLAGS =
                                       _CAN_CONFIG_SAMPLE_ONCE &
                                       _CAN_CONFIG_XTD_MSG;
                                       
  */
/*configuracion para cristal de 16 y comunicacion CAN a 500 KB*/
const unsigned int SJW = 1;
const unsigned int BRP = 2;
const unsigned int PHSEG1 = 4;
const unsigned int PHSEG2 = 3;
const unsigned int PROPSEG = 8;
const unsigned int CAN_CONFIG_FLAGS =
                                       _CAN_CONFIG_SAMPLE_ONCE &
                                       _CAN_CONFIG_XTD_MSG;


//*******
//// configuracion para el cristal de 8 MHz para la comunicacíon CAN  a 125 Kb
/*
const unsigned int SJW = 1;
const unsigned int BRP = 4;
const unsigned int PHSEG1 = 5;
const unsigned int PHSEG2 = 2;
const unsigned int PROPSEG = 8;
const unsigned int CAN_CONFIG_FLAGS =
                                       _CAN_CONFIG_SAMPLE_ONCE &
                                       _CAN_CONFIG_XTD_MSG;

 */
void ConfiguraCAN(){
  Can_Send_Flags = _CAN_IDE_XTD_FRAME                            // form value to be used
                 & _CAN_NO_RTR_FRAME;                            // with CANWrite

  Can_Init_Flags = _CAN_CONFIG_SAMPLE_THRICE                     // form value to be used
                 & _CAN_CONFIG_XTD_MSG;                          // with CANInit

  CANInitialize(SJW, BRP, PHSEG1, PHSEG2, PROPSEG, CAN_CONFIG_FLAGS);   // inicializar el puerto CAN
  CANSetOperationMode(_CAN_MODE_STANDBY,0xFF);                   // set STANDBY mode

  //----------------------------------------------------------//
  CANSetFilter(CAN_RX_FILTER_3,  -1, _CAN_CONFIG_XTD_MSG);    //
  CANSetFilter(CAN_RX_FILTER_4,  ID_5to, _CAN_CONFIG_XTD_MSG);    //
  CANSetFilter(CAN_RX_FILTER_5,  ID_4to, _CAN_CONFIG_XTD_MSG);    //
  CANSetFilter(CAN_RX_FILTER_6,  ID_3er, _CAN_CONFIG_XTD_MSG);    //
  CANSetFilter(CAN_RX_FILTER_7, ID_1st, _CAN_CONFIG_XTD_MSG); // set ID filter of 7th filter to 2nd node ID
  CANSetFilter(CAN_RX_FILTER_8, ID_2nd, _CAN_CONFIG_XTD_MSG);    // and ones to other filters
  CANSetFilter(CAN_RX_FILTER_9,  0x700, _CAN_CONFIG_XTD_MSG);
  CANSetFilter(CAN_RX_FILTER_10, 0x300, _CAN_CONFIG_XTD_MSG);
  CANSetFilter(CAN_RX_FILTER_11, -1, _CAN_CONFIG_XTD_MSG);
  CANSetFilter(CAN_RX_FILTER_12, -1, _CAN_CONFIG_XTD_MSG);
  CANSetFilter(CAN_RX_FILTER_13, -1, _CAN_CONFIG_XTD_MSG);
  CANSetFilter(CAN_RX_FILTER_14, -1, _CAN_CONFIG_XTD_MSG);
  //----------------------------------------------------------//

  //----------------------------------------------------------//
  CANSetMask(CAN_RX_MASK_3,  -1, _CAN_CONFIG_XTD_MSG);        // set all mask bits of masks[3..14] to all ones
  CANSetMask(CAN_RX_MASK_4,  -1, _CAN_CONFIG_XTD_MSG);
  CANSetMask(CAN_RX_MASK_5,  -1, _CAN_CONFIG_XTD_MSG);
  CANSetMask(CAN_RX_MASK_6,  -1, _CAN_CONFIG_XTD_MSG);
  CANSetMask(CAN_RX_MASK_7,  -1, _CAN_CONFIG_XTD_MSG);
  CANSetMask(CAN_RX_MASK_8,  -1, _CAN_CONFIG_XTD_MSG);
  CANSetMask(CAN_RX_MASK_9,  -1, _CAN_CONFIG_XTD_MSG);
  CANSetMask(CAN_RX_MASK_10, -1, _CAN_CONFIG_XTD_MSG);
  CANSetMask(CAN_RX_MASK_11, -1, _CAN_CONFIG_XTD_MSG);
  CANSetMask(CAN_RX_MASK_12, -1, _CAN_CONFIG_XTD_MSG);
  CANSetMask(CAN_RX_MASK_13, -1, _CAN_CONFIG_XTD_MSG);
  CANSetMask(CAN_RX_MASK_14, -1, _CAN_CONFIG_XTD_MSG);
  //----------------------------------------------------------//

  CANSetOperationMode(_CAN_MODE_ENABLE,0xFF);               // set ENABLE mode

}