/*
 * QEMU RISC-V Quard Star Board
 *
 * Copyright (c) 2021 qiao qiming
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2 or later, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef HW_RISCV_SANYUJOJO__H
#define HW_RISCV_SANYUJOJO__H

#include "hw/cpu/cluster.h"
#include "hw/riscv/riscv_hart.h"
#include "hw/sysbus.h"
#include "hw/block/flash.h"
#include "qom/object.h"
#include "hw/i2c/i2c.h"
#include "hw/i2c/imx_i2c.h"


#define SANYUJOJO_MANAGEMENT_CPU_COUNT    1
#define SANYUJOJO_COMPUTE_CPU_COUNT       8

#define TYPE_RISCV_SANYUJOJO_MACHINE MACHINE_TYPE_NAME("sanyujojo")
typedef struct SanyuJoJo_States RISVSanyuJoJoStates;
DECLARE_INSTANCE_CHECKER(RISVSanyuJoJoStates, RISCV_VIRT_MACHINE,
                         TYPE_RISCV_SANYUJOJO_MACHINE)

struct SanyuJoJo_States {
    /*< private >*/
    MachineState parent;
    /*< public >*/

    CPUClusterState r_cluster;
    CPUClusterState c_cluster;
    RISCVHartArrayState r_cpus[SANYUJOJO_MANAGEMENT_CPU_COUNT];
    RISCVHartArrayState c_cpus[SANYUJOJO_COMPUTE_CPU_COUNT];
    DeviceState *plic;
    PFlashCFI01 *flash;
    IMXI2CState i2c[3];
    FWCfgState *fw_cfg;
    I2CSlave *at24c_dev;
    I2CSlave *wm8750_dev;
};

enum {
    QUARD_STAR_MROM,
    QUARD_STAR_SRAM,
    QUARD_STAR_CLINT,
    QUARD_STAR_PLIC,
    QUARD_STAR_UART0,
    QUARD_STAR_UART1,
    QUARD_STAR_UART2,
    SANYU_PCIE_PIO,
    SANYUJOJO_RTC,
    SANYUJOJO_TEST,
    SANYUJOJO_I2C0,
    SANYUJOJO_I2C1,
    SANYUJOJO_I2C2,
    SANYUJOJO_VIRTIO0,
    SANYUJOJO_VIRTIO1,
    SANYUJOJO_VIRTIO2,
    SANYUJOJO_VIRTIO3,
    SANYUJOJO_VIRTIO4,
    SANYUJOJO_VIRTIO5,
    SANYUJOJO_VIRTIO6,
    SANYUJOJO_VIRTIO7,
    QUARD_STAR_FW_CFG,
    QUARD_STAR_FLASH,
    QUARD_STAR_DRAM,
    SANYU_PCIE_ECAM,
    SANYU_PCIE_MMIO,
};

enum {
    SANYUJOJO_VIRTIO0_IRQ = 1,         /* 1 to 8 */
    SANYUJOJO_VIRTIO1_IRQ = 2,  
    SANYUJOJO_VIRTIO2_IRQ = 3,  
    SANYUJOJO_VIRTIO3_IRQ = 4,  
    SANYUJOJO_VIRTIO4_IRQ = 5,  
    SANYUJOJO_VIRTIO5_IRQ = 6,  
    SANYUJOJO_VIRTIO6_IRQ = 7,  
    SANYUJOJO_VIRTIO7_IRQ = 8,  
    QUARD_STAR_UART0_IRQ = 10,
    QUARD_STAR_UART1_IRQ = 11,
    QUARD_STAR_UART2_IRQ = 12,
    SANYUJOJO_RTC_IRQ = 13,
    SANYUJOJO_I2C0_IRQ    = 14,
    SANYUJOJO_I2C1_IRQ    = 15,
    SANYUJOJO_I2C2_IRQ    = 16,
    SANYU_PCIE_IRQ = 0x20, /* 32 to 35 */
};

#define TYPE_SANYU_HOST "sanyu"

#define QUARD_STAR_PLIC_HART_CONFIG    "MS"
#define QUARD_STAR_PLIC_NUM_SOURCES    127
#define QUARD_STAR_PLIC_NUM_PRIORITIES 7
#define QUARD_STAR_PLIC_PRIORITY_BASE  0x04
#define QUARD_STAR_PLIC_PENDING_BASE   0x1000
#define QUARD_STAR_PLIC_ENABLE_BASE    0x2000
#define QUARD_STAR_PLIC_ENABLE_STRIDE  0x80
#define QUARD_STAR_PLIC_CONTEXT_BASE   0x200000
#define QUARD_STAR_PLIC_CONTEXT_STRIDE 0x1000

#endif