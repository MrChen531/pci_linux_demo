#include <linux/init.h>
#include <linux/module.h>
#include <linux/pci.h>


#include "dio_common.h"

#define MODULENAME "PCI_DIO"
#define PFX MODULENAME ": "


#define DIO_CFG(NAME) DIO_CFG_##NAME

#define DIO_PCI_VENDOR_ID 0x8086 
#define DIO_PCI_DEVICE_ID 0x0001 

#define DIO_DEVICE(id, data) { PCI_DEVICE(DIO_PCI_VENDOR_ID, id), (kernel_ulong_t)data }

static struct pci_device_id dio_pci_tbl[] = {
	DIO_DEVICE(DIO_PCI_DEVICE_ID, 0),
	{0,},
};

MODULE_DEVICE_TABLE(pci, dio_pci_tbl);


// 设备驱动程序的probe函数
static int dio_pci_probe(struct pci_dev *pdev, const struct pci_device_id *id)
{

  DIO_DEBUG_LOG(DIO_ALL_DEBUG,"%s dio pci probe\n",MODULENAME);




    // 在这里实现设备的初始化操作
    return 0;
}


// 设备驱动程序的remove函数
static void dio_pci_remove(struct pci_dev *dev)
{
    // 在这里实现设备的卸载操作
}


// 驱动程序的数据结构
static struct pci_driver dio_pci_driver = {
    .name = "dio_pci_driver",
    .id_table = dio_pci_tbl,
    .probe = dio_pci_probe,
    .remove = dio_pci_remove,
};


static int __init dio_init(void)
{
  pci_register_driver(&dio_pci_driver);
  DIO_DEBUG_LOG(DIO_ALL_DEBUG,"PCI DIO init\n");
  return 0;
}

static void __exit dio_exit(void)
{
  pci_unregister_driver(&dio_pci_driver);
  DIO_DEBUG_LOG(DIO_ALL_DEBUG,"PCI DIO remove\n");
  return ;
}



module_init(dio_init);
module_exit(dio_exit);

MODULE_AUTHOR("CCCLLL");
MODULE_DESCRIPTION("PCI DIO");

MODULE_LICENSE("GPL");

