#ifndef __UDPI_DEVICE
#define __UDPI_DEVICE

#ifdef CUPDI

typedef struct _nvm_info{
    unsigned short nvm_start;
    unsigned short nvm_size;
    unsigned short nvm_pagesize;
}nvm_info_t;

typedef struct _reg_info {
    unsigned short syscfg_address;
    unsigned short nvmctrl_address;
    unsigned short sigrow_address;
}reg_info_t;

typedef struct _chip_info {
    const char *dev_name;
    nvm_info_t flash;
    reg_info_t reg;
    nvm_info_t fuse;
    nvm_info_t userrow;
    nvm_info_t eeprom;
}chip_info_t;

typedef struct _device_info {
    const char *name;
    const chip_info_t *mmap;
}device_info_t;

const device_info_t * get_chip_info(const char *dev_name);

typedef enum _NVM_TYPE { NVM_FLASH, NVM_EEPROM, NVM_USERROW, NVM_FUSES, NUM_NVM_TYPES } NVM_TYPE_T;
int dev_get_nvm_info(const void *dev, NVM_TYPE_T type, nvm_info_t * info);
#endif

#endif
