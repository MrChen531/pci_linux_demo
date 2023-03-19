#ifndef __DIO_PCI_COMMON_H__
#define __DIO_PCI_COMMON_H__

#define DIO_DEBUG

uint32_t g_dio_debug_level = 0xff;


#ifdef DIO_DEBUG
#define DIO_GPIO_DEBUG      (1 << 0)
#define DIO_UART_DEBUG      (1 << 1)
#define DIO_ENET_DEBUG      (1 << 2)
#define DIO_UPDATE_DEBUG    (1 << 3)
#define DIO_ALL_DEBUG       (0xff)

#define assert(expr) \
	if (!(expr)) {					\
		printk( "Assertion failed! %s,%s,%s,line=%d\n",	\
		#expr,__FILE__,__func__,__LINE__);		\
	}
#define dprintk(fmt, args...) \
	do { printk(KERN_DEBUG PFX fmt, ## args); } while (0)

#define DIO_DEBUG_LOG(type,fmt,args...) \
	do { \
	if ((g_dio_debug_level & (uint32_t)type)) {\
		printk(KERN_INFO PFX fmt, ## args); \
	}} while (0)

#else
#define assert(expr) do {} while (0)
#define dprintk(fmt, args...)	do {} while (0)
#define DIO_DEBUG_LOG(type,fmt,args...) do {} while (0)
#endif /* DIO_DEBUG */



#endif
