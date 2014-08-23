#ifndef USART_atmega1284_H
#define USART_atmega1284_H

void USART_Init( unsigned int baud )
{
  /* Set baud rate */
  UBRRnH = (unsigned char)(baud>>8);
  UBRRnL = (unsigned char)baud;
  /* Enable receiver and transmitter */
  UCSRnB = (1<<RXENn)|(1<<TXENn);
  /* Set frame format: 8data, 2stop bit */
  UCSRnC = (1<<USBSn)|(3<<UCSZn0);
}

unsigned char USART_Receive( void )
{
  /* Wait for data to be received */
  while ( !(UCSRnA & (1<<RXCn)) )
  ;
  /* Get and return received data from buffer */
  return UDRn;
}


#endif
