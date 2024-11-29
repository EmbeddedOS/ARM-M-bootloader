
volatile unsigned int * const UART0DR = (unsigned int *)0x40007804;

void print_uart0(const char *s) {
 while(*s != '\0') { /* Loop until end of string */
 *UART0DR = (unsigned int)(*s); /* Transmit char */
 s++; /* Next char */
 }
}

int main()
{
    print_uart0("Hi there uart1\n");
}