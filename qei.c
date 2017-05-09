

#include "qei.h"

static void QEI_ISR(void);
static int32_t Round =0;

void qei_config(void)
{

	SysCtlPeripheralEnable(SYSCTL_PERIPH_QEI0);
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);

	HWREG(GPIO_PORTD_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;
	HWREG(GPIO_PORTD_BASE + GPIO_O_CR) = 0x80;
	HWREG(GPIO_PORTD_BASE + GPIO_O_AFSEL) &= ~0x80;
	
	//QEI config
	QEIConfigure(QEI0_BASE , QEI_CONFIG_CAPTURE_A_B |QEI_CONFIG_NO_RESET |QEI_CONFIG_QUADRATURE |QEI_CONFIG_NO_SWAP,0xFFFFFFFF);
	
	ROM_GPIOPinTypeQEI(GPIO_PORTD_BASE, GPIO_PIN_6 | GPIO_PIN_7);

	GPIOPinConfigure(GPIO_PD6_PHA0);
	GPIOPinConfigure(GPIO_PD7_PHB0);
	//GPIOPinConfigure(GPIO_PD3_IDX0);
	/*
	//INT Flag
	ROM_QEIIntEnable(QEI0_BASE,QEI_INTINDEX);
	//Config int void
	QEIIntRegister(QEI0_BASE,&QEI_ISR);
	*/
	//enable QEI module
	QEIEnable(QEI0_BASE);
	
}

//static void QEI_ISR(void)
//{
//	if(QEIIntStatus(QEI0_BASE,true)==QEI_INTINDEX)
//	{
//		if(QEIDirectionGet(QEI0_BASE)==1)
//			Round++;
//		else
//			Round--;
//		QEIPositionSet(QEI0_BASE,0);
//	}
//	QEIIntClear(QEI0_BASE,QEIIntStatus(QEI0_BASE,true));
//}

//int32_t QEIRoundGet(void)
//{
//	return Round;
//}





