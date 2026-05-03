#ifndef __VPNHIDE_COMPAT_H__
#define __VPNHIDE_COMPAT_H__

#include <linux/version.h>
#include <linux/types.h>
#include <linux/proc_fs.h>
#include <linux/ptrace.h>
#include <asm/ptrace.h>

// 1. Fix the struct name
// If the compiler thinks it's a 'file_operations' but the code says 'proc_ops'
#define proc_ops file_operations

// 2. Fix the field designators (The "Translation Layer")
// This maps the new proc_ops names back to the file_operations names
#define proc_lseek    llseek
#define proc_read     read
#define proc_write    write
#define proc_open     open
#define proc_release  release

// 3. Register fix for arm64
#ifndef regs_set_return_value
static inline void regs_set_return_value(struct pt_regs *regs, unsigned long rc)
{
    regs->regs[0] = rc;
}
#endif

#endif
