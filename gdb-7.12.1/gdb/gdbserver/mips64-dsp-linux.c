/* *INDENT-OFF* */ /* THIS FILE IS GENERATED */

/* A register protocol for GDB, the GNU debugger.
   Copyright (C) 2001-2013 Free Software Foundation, Inc.

   This file is part of GDB.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* This file was created with the aid of ``regdat.sh'' and ``./../regformats/mips64-dsp-linux.dat''.  */

#include "server.h"
#include "regdef.h"
#include "tdesc.h"

static struct reg regs_mips64_dsp_linux[] = {
  { "r0", 0, 64 },
  { "r1", 64, 64 },
  { "r2", 128, 64 },
  { "r3", 192, 64 },
  { "r4", 256, 64 },
  { "r5", 320, 64 },
  { "r6", 384, 64 },
  { "r7", 448, 64 },
  { "r8", 512, 64 },
  { "r9", 576, 64 },
  { "r10", 640, 64 },
  { "r11", 704, 64 },
  { "r12", 768, 64 },
  { "r13", 832, 64 },
  { "r14", 896, 64 },
  { "r15", 960, 64 },
  { "r16", 1024, 64 },
  { "r17", 1088, 64 },
  { "r18", 1152, 64 },
  { "r19", 1216, 64 },
  { "r20", 1280, 64 },
  { "r21", 1344, 64 },
  { "r22", 1408, 64 },
  { "r23", 1472, 64 },
  { "r24", 1536, 64 },
  { "r25", 1600, 64 },
  { "r26", 1664, 64 },
  { "r27", 1728, 64 },
  { "r28", 1792, 64 },
  { "r29", 1856, 64 },
  { "r30", 1920, 64 },
  { "r31", 1984, 64 },
  { "status", 2048, 64 },
  { "lo", 2112, 64 },
  { "hi", 2176, 64 },
  { "badvaddr", 2240, 64 },
  { "cause", 2304, 64 },
  { "pc", 2368, 64 },
  { "f0", 2432, 64 },
  { "f1", 2496, 64 },
  { "f2", 2560, 64 },
  { "f3", 2624, 64 },
  { "f4", 2688, 64 },
  { "f5", 2752, 64 },
  { "f6", 2816, 64 },
  { "f7", 2880, 64 },
  { "f8", 2944, 64 },
  { "f9", 3008, 64 },
  { "f10", 3072, 64 },
  { "f11", 3136, 64 },
  { "f12", 3200, 64 },
  { "f13", 3264, 64 },
  { "f14", 3328, 64 },
  { "f15", 3392, 64 },
  { "f16", 3456, 64 },
  { "f17", 3520, 64 },
  { "f18", 3584, 64 },
  { "f19", 3648, 64 },
  { "f20", 3712, 64 },
  { "f21", 3776, 64 },
  { "f22", 3840, 64 },
  { "f23", 3904, 64 },
  { "f24", 3968, 64 },
  { "f25", 4032, 64 },
  { "f26", 4096, 64 },
  { "f27", 4160, 64 },
  { "f28", 4224, 64 },
  { "f29", 4288, 64 },
  { "f30", 4352, 64 },
  { "f31", 4416, 64 },
  { "fcsr", 4480, 64 },
  { "fir", 4544, 64 },
  { "hi1", 4608, 64 },
  { "lo1", 4672, 64 },
  { "hi2", 4736, 64 },
  { "lo2", 4800, 64 },
  { "hi3", 4864, 64 },
  { "lo3", 4928, 64 },
  { "dspctl", 4992, 32 },
  { "restart", 5024, 64 },
};

static const char *expedite_regs_mips64_dsp_linux[] = { "r29", "pc", 0 };
static const char *xmltarget_mips64_dsp_linux = "mips64-dsp-linux.xml";

const struct target_desc *tdesc_mips64_dsp_linux;

void
init_registers_mips64_dsp_linux (void)
{
  static struct target_desc tdesc_mips64_dsp_linux_s;
  struct target_desc *result = &tdesc_mips64_dsp_linux_s;

  result->reg_defs = regs_mips64_dsp_linux;
  result->num_registers = sizeof (regs_mips64_dsp_linux) / sizeof (regs_mips64_dsp_linux[0]);
  result->expedite_regs = expedite_regs_mips64_dsp_linux;
  result->xmltarget = xmltarget_mips64_dsp_linux;

  init_target_desc (result);

  tdesc_mips64_dsp_linux = result;
}
