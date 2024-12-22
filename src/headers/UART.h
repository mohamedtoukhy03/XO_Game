#define CR   0x0D
#define LF   0x0A
#define BS   0x08
#define ESC  0x1B
#define SP   0x20
#define DEL  0x7F

void UART_Init(void);
void UART_Interrupt_Init(void);
unsigned char UART_InChar(void);
unsigned char UART_InCharNonBlocking(void);
void UART_OutChar(unsigned char data);
unsigned long UART_InUDec(void);
void UART_OutString(unsigned char buffer[]);
void UART_ConvertUDec(unsigned long n);
void UART_OutUDec(unsigned long n);
void UART_ConvertDistance(unsigned long n);
void UART_OutDistance(unsigned long n);




