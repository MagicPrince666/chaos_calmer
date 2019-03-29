/*
 * Copyright (c) 2010, Atheros Communications Inc.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */
 /*
 * Fortune Zhiyong Liu porting for customers. 11/24/2011. 
 * willyliu@fortune-co.com
 */

#include "athrs_phy.h"
#include "athrs_mac.h"
#include "ar803x_phy.h"

#define ATHR_OUI					0x4d
#define ATHR_PHY_AR8031_8033_ID 	0xd074	
#define ATHR_PHY_AR8035_ID 		0xd072

#define ATHR_PHY_BASE 0x0

BOOL
ar803x_phy_setup(void  *arg)
{
    char *pszAr8031_8033="AR8031/AR8033";
    char *pszAr8035="AR8035";
    char *pszName="Unknown";
    int phyid1, phyid2;
    athr_gmac_t *mac = (athr_gmac_t *)arg;

    phyid1 = phy_reg_read(0, ATHR_PHY_BASE, 2);
    phyid2 = phy_reg_read(0, ATHR_PHY_BASE, 3);
    if (phyid1 == ATHR_OUI)
    {
    	    if (phyid2 == ATHR_PHY_AR8031_8033_ID)
	    {
	    	pszName = pszAr8031_8033;
	    }
	    else if (phyid2 == ATHR_PHY_AR8035_ID)
	    {
	    	pszName = pszAr8035;
	    }
	    printk("Atheros phy: %s\n", pszName);
    }
    else
    {
	    printk("Unknown phy!\n");
    }

    /* delay rx_clk */
    phy_reg_write(0, ATHR_PHY_BASE, 0x1D, 0x0);
    phy_reg_write(0, ATHR_PHY_BASE, 0x1E, 0x82EE); /* 0x02EE - no delay, 0x82EE - rx delay*/
    //printk("Debug reg 0x0 = 0x%x\n", phy_reg_read(0, ATHR_PHY_BASE, 0x1E));

    /* delay tx_clk */
    phy_reg_write(0, ATHR_PHY_BASE, 0x1D, 0x5);
    phy_reg_write(0, ATHR_PHY_BASE, 0x1E, 0x2D47); /* 0x2C47 - no delay, 0x2D47 - tx delay */
    //printk("Debug reg 0x5 = 0x%x\n", phy_reg_read(0, ATHR_PHY_BASE, 0x1E));

    /* Reset PHYs*/
    phy_reg_write(0, ATHR_PHY_BASE, ATHR_PHY_CONTROL,
                  ATHR_CTRL_AUTONEGOTIATION_ENABLE
                  | ATHR_CTRL_SOFTWARE_RESET);
    return 0;
}

int
ar803x_phy_speed(int ethUnit,int phyUnit)
{
    int phyHwStatus;

    phyHwStatus = phy_reg_read(0, ATHR_PHY_BASE, 0x11);

    {    
        phyHwStatus = ((phyHwStatus & ATHER_STATUS_LINK_MASK) >>
                       ATHER_STATUS_LINK_SHIFT);

        switch(phyHwStatus) {
        case 0:
            return ATHR_PHY_SPEED_10T;
        case 1:
            return ATHR_PHY_SPEED_100T;
        case 2:
            return ATHR_PHY_SPEED_1000T;
        default:
            printk("Unkown speed read!\n");
        }
    }

    return ATHR_PHY_SPEED_10T;
}

/******************************************************************************
*
* athrs26_phy_is_fdx - Determines whether the phy ports associated with the
* specified device are FULL or HALF duplex.
*
* RETURNS:
*    1 --> FULL
*    0 --> HALF
*/
int
ar803x_phy_is_fdx(int ethUnit,int phyUnit)
{
    int phyHwStatus;

    phyHwStatus = phy_reg_read(0, ATHR_PHY_BASE, 0x11);

    if (phyHwStatus & ATHER_STATUS_FULL_DEPLEX)
       return 1;

    return 0;
}

/******************************************************************************
*
* athr_phy_is_link_alive - test to see if the specified link is alive
*
* RETURNS:
*    TRUE  --> link is alive
*    FALSE --> link is down
*/
BOOL
ar803x_phy_is_link_alive(int phyUnit)
{
    return TRUE;
}

/*****************************************************************************
*
* athr_phy_is_up -- checks for significant changes in PHY state.
*
* A "significant change" is:
*     dropped link (e.g. ethernet cable unplugged) OR
*     autonegotiation completed + link (e.g. ethernet cable plugged in)
*
* When a PHY is plugged in, phyLinkGained is called.
* When a PHY is unplugged, phyLinkLost is called.
*/
int
ar803x_phy_is_up(int ethUnit)
{
    int phyHwStatus;

    phyHwStatus = phy_reg_read(0, ATHR_PHY_BASE, 0x11);

    if (phyHwStatus & ATHER_STATUS_LINK_PASS)
       return 1;

    return 0;
}

void ar803x_enable_link_intrs(void *arg)
{
}

void ar803x_disable_link_intrs(void *arg) 
{
}

void ar934x_ar803x_intr(void *arg)
{
}

int ar803x_ioctl(struct net_device *dev, void *args, int cmd)
{
        return 0;
}

unsigned int ar803x_rd_phy(int ethUnit,unsigned int phy_addr, unsigned int reg_addr)
{
      return (phy_reg_read(ethUnit,phy_addr,reg_addr));

}

void ar803x_wr_phy(int ethUnit,unsigned int phy_addr, unsigned int reg_addr, unsigned int write_data)
{
      phy_reg_write(ethUnit,phy_addr,reg_addr,write_data);          
}

unsigned int ar803x_reg_read(unsigned int reg_addr)
{
    return 0;   
}

void ar803x_reg_write(unsigned int reg_addr, unsigned int reg_val)
{
}

static int ar803x_reg_init(void *arg)
{
   return 0;
}

int ar803x_register_ops(void *arg)
{
  athr_gmac_t *mac   = (athr_gmac_t *) arg;
  athr_phy_ops_t *ops = mac->phy;

  if(!ops)
     ops = kmalloc(sizeof(athr_phy_ops_t), GFP_KERNEL);

  memset(ops,0,sizeof(athr_phy_ops_t));

  ops->mac            =  mac;
  ops->is_up          =  ar803x_phy_is_up;
  ops->is_alive       =  ar803x_phy_is_link_alive;
  ops->speed          =  ar803x_phy_speed;
  ops->is_fdx         =  ar803x_phy_is_fdx;
  ops->ioctl          =  ar803x_ioctl;
  ops->setup          =  ar803x_phy_setup;
  ops->stab_wr        =  NULL;
  ops->link_isr       =  ar934x_ar803x_intr;
  ops->en_link_intrs  =  ar803x_enable_link_intrs;
  ops->dis_link_intrs =  ar803x_disable_link_intrs;
  ops->read_phy_reg   =  ar803x_rd_phy;
  ops->write_phy_reg  =  ar803x_wr_phy;
  ops->read_mac_reg   =  ar803x_reg_read;
  ops->write_mac_reg  =  ar803x_reg_write;
  ops->init           =  ar803x_reg_init;

  mac->phy = ops;
  return 0;
}
