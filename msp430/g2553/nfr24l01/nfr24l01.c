#include "nfr24l01.h"
unsigned char spi_sendbyte(unsigned char byte)
{
  unsigned char bcnt;
  for(bcnt=0;bcnt<8;bcnt++)
  {
  MOSI=(byte&0x80);
  byte=(byte<<1);
  SCLK=1;
  byte|=MISO;
  SCLK=0;
  }
  return byte;
}
unsigned char spi_write_reg(unsigned char reg_addr,unsigned char value)
{
  unsigned char status;
  CSN=0;
  status=spi_sendbyte(WRITE_REG+reg_addr);
  spi_sendbyte(value);
  CSN=1;
  return status;
}
unsigned char spi_read_reg(unsigned char reg_addr)
{
  unsigned char status;
  CSN=0;
  status=spi_sendbyte(READ_REG+reg_addr);
  CSN=1;
  return status;
}
unsigned char spi_read_buf(unsigned char reg_addr,unsigned char buf,unsigned char byte)
{

}
