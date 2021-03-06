#include "mpu6050.h"
#include "includes.h"


unsigned char *(*Single_read)(unsigned char *pBuffer,unsigned char PartAddr,      \
										unsigned char WriteAddr,unsigned char NumByteToWrite);
unsigned char *(*Single_write)(unsigned char *pBuffer,unsigned char PartAddr,     \
										 unsigned char WriteAddr,unsigned char NumByteToWrite);


void Init_MPU6050(MPU6050Init_Typedef *MPU6050_Config){
  
  unsigned char Rdata[5]={0};
  
  Single_read = MPU6050_Config->Read_Data;
  Single_write= MPU6050_Config->Write_Data;

  //test 
  Rdata[0] = MPU6050_sread(PWR_MGMT_1);
  MPU6050_swrite(PWR_MGMT_1,0x07);
  Rdata[1] = MPU6050_sread(PWR_MGMT_1);
  Rdata[2]=Rdata[0]+Rdata[1];
  //test
  MPU6050_swrite(PWR_MGMT_1,0x00);
  MPU6050_swrite(SMPLRT_DIV,0x07);
  MPU6050_swrite(CONFIG,0x06);
  MPU6050_swrite(GYRO_CONFIG,0x18);
  MPU6050_swrite(ACCEL_CONFIG,0x01);
}

void MPU6050_swrite(unsigned char WriteAddr,unsigned char Data){

  Single_write(&Data,MPU6050_Addr,WriteAddr,1);
}

unsigned char MPU6050_sread(unsigned char WriteAddr){
  unsigned char Data;
  Single_read(&Data,MPU6050_Addr,WriteAddr,1);
  return Data;
}

void Read_MPU6050AG(MPU6050AGVALUE_Typedef *pAg_value){
  unsigned char tData[12]={0};
  
  tData[0]=MPU6050_sread(ACCEL_XOUT_H);
  tData[1]=MPU6050_sread(ACCEL_XOUT_L);
  tData[2]=MPU6050_sread(ACCEL_YOUT_H);
  tData[3]=MPU6050_sread(ACCEL_YOUT_L);
  tData[4]=MPU6050_sread(ACCEL_ZOUT_H);
  tData[5]=MPU6050_sread(ACCEL_ZOUT_L);

  tData[6]=MPU6050_sread(GYRO_XOUT_H);
  tData[7]=MPU6050_sread(GYRO_XOUT_L);
  tData[8]=MPU6050_sread(GYRO_YOUT_H);
  tData[9]=MPU6050_sread(GYRO_YOUT_L);
  tData[10]=MPU6050_sread(GYRO_ZOUT_H);
  tData[11]=MPU6050_sread(GYRO_ZOUT_L);

  pAg_value->AccelX = (tData[0]<<8)|tData[1];
  pAg_value->AccelY = (tData[2]<<8)|tData[3];
  pAg_value->AccelZ = (tData[4]<<8)|tData[5];
  pAg_value->GYROX  = (tData[6]<<8)|tData[7];
  pAg_value->GYROY  = (tData[8]<<8)|tData[9];
  pAg_value->GYROZ  = (tData[10]<<8)|tData[11];
}


/*
void Set_MPU6050_REG(unsigned char reg,unsigned char *pdata){

}

unsigned char Read_MPU6050_REG(unsigned char reg);
*/
