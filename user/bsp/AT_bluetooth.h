#ifndef __AT_BLUETOOTH_H
#define __AT_BLUETOOTH_H

#ifdef __cplusplus
extern "C" {
#endif
 
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned int u32;

//  define cmd character
#define NAME                  "NAME?"
#define PIN                   "PIN?"
#define AUTH                  "AUTH?"
#define DISC                  "DISC?"
#define SECH                  "SECH?"
#define APCH                  "APCH?"
#define ROLE                  "ROLE?"
      //uart
#define BAUD                  "BAUD?"
#define CHK                   "CHK?"
#define STOP                  "STOP?"
#define UART                  "UART?"
     //master
#define CLEAR                 "CLEAR"  
#define SEARCH                "SEARCH"
#define CONLAST               "CONLAST"
#define WORK                  "WORK"
#define START                 "START"

#define CONN                  "CONN"

#define TCON                  "TCON?"
#define RADD                  "RADD?"
     // misc
#define LADD                  "LADD?"
#define IMME                  "IMME?"

#define KEY                   "KEY?"
#define LED                   "LED?"
#define TYPE                  "TYPE?"
#define FILT                  "FILT?"
#define TEMP                  "TEMP?"
#define COD                   "COD?"

#define DEFAULT               "DEFAULT"
#define RESTART               "RESTART"

//  CMD end

#define BAUD_1200             "BAUD1"
#define BAUD_2400             "BAUD2"
#define BAUD_4800             "BAUD3"
#define BAUD_9600             "BAUD4"
#define BAUD_19200            "BAUD5"
#define BAUD_38400            "BAUD6"
#define BAUD_57600            "BAUD7"
#define BAUD_115200           "BAUD8"
#define BAUD_230400           "BAUD9"
#define BAUD_460800           "BAUDA"
#define BAUD_921600           "BAUDB"
#define BAUD_1382400          "BAUDC"

#define AUTH1                 "1"
#define AUTH0                 "0"

#define CHK_NULL              "0"
#define CHK_ODD               "1"
#define CHK_EVEN              "2"

#define STOPBIT1              "1"
#define STOPBIT2              "2"

#define DISC_DIS_LNK          "0"
#define DISC_DIS              "1"
#define DISC_LNK              "2"

#define LED_FLASH             "0"
#define LED_OFFON             "1"

#define TIMEOUT                3000

#define LINKOK                 1
#define LINKLOST               0

typedef struct BLUETOOTH_INIT_
{
  char *BT_Name;
  char *BT_Auth;
  char *BT_PIN;  
  char *BT_Disc;
  char *BT_LED;

//  BT_MasterTypedef *BT_Master;
//  BT_SlaveTypedef  *BT_Slave;
  u8    BT_State;

  char *(*BT_ReadData)(u16 *Num,u8 swait);
  u8 (*BT_SendData)(char *pData,u32 Num);
}BT_InitTypedef;

/*
 typedef struct BT_MASTERINIT_
{


}BT_MasterTypedef;

typedef struct BT_SLAVEINIT_
{


}BT_SlaveTypedef;
**/

//  static char Cmd_buffer[50];

  
extern u8 BT_SendData(char *Data);
extern char *BT_ReadData(u16 *Num);

extern char *BT_ReadLData(char *Sta_link,u16 *Num);
extern char BT_Init(BT_InitTypedef *BT_Config);
//  u8   BT_MasterInit(BT_InitTypedef *BT_Config);
//  u8   BT_SlaveInit(BT_InitTypedef *BT_Config);
extern char BT_Set(char *cmd,char *p_value);

//  u8   BT_Set();
//  u8   BT_RState();
//  u8   BT_GetStater();
static u8 BT_SendCmd(char *pData);
  


#ifdef __cplusplus
}
#endif

#endif
