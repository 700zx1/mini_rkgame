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

/* This file was created with the aid of ``regdat.sh'' and ``./../regformats/mips-linux.dat''.  */

#include "server.h"
#include "regdef.h"
#include "tdesc.h"

static struct reg regs_mips_linux[] = {
  { "r0", 0, 32 },
  { "r1", 32, 32 },
  { "r2", 64, 32 },
  { "r3", 96, 32 },
  { "r4", 128, 32 },
  { "r5", 160, 32 },
  { "r6", 192, 32 },
  { "r7", 224, 32 },
  { "r8", 256, 32 },
  { "r9", 288, 32 },
  { "r10", 320, 32 },
  { "r11", 352, 32 },
  { "r12", 384, 32 },
  { "r13", 416, 32 },
  { "r14", 448, 32 },
  { "r15", 480, 32 },
  { "r16", 512, 32 },
  { "r17", 544, 32 },
  { "r18", 576, 32 },
  { "r19", 608, 32 },
  { "r20", 640, 32 },
  { "r21", 672, 32 },
  { "r22", 704, 32 },
  { "r23", 736, 32 },
  { "r24", 768, 32 },
  { "r25", 800, 32 },
  { "r26", 832, 32 },
  { "r27", 864, 32 },
  { "r28", 896, 32 },
  { "r29", 928, 32 },
  { "r30", 960, 32 },
  { "r31", 992, 32 },
  { "status", 1024, 32 },
  { "lo", 1056, 32 },
  { "hi", 1088, 32 },
  { "badvaddr", 1120, 32 },
  { "cause", 1152, 32 },
  { "pc", 1184, 32 },
  { "f0", 1216, 32 },
  { "f1", 1248, 32 },
  { "f2", 1280, 32 },
  { "f3", 1312, 32 },
  { "f4", 1344, 32 },
  { "f5", 1376, 32 },
  { "f6", 1408, 32 },
  { "f7", 1440, 32 },
  { "f8", 1472, 32 },
  { "f9", 1504, 32 },
  { "f10", 1536, 32 },
  { "f11", 1568, 32 },
  { "f12", 1600, 32 },
  { "f13", 1632, 32 },
  { "f14", 1664, 32 },
  { "f15", 1696, 32 },
  { "f16", 1728, 32 },
  { "f17", 1760, 32 },
  { "f18", 1792, 32 },
  { "f19", 1824, 32 },
  { "f20", 1856, 32 },
  { "f21", 1888, 32 },
  { "f22", 1920, 32 },
  { "f23", 1952, 32 },
  { "f24", 1984, 32 },
  { "f25", 2016, 32 },
  { "f26", 2048, 32 },
  { "f27", 2080, 32 },
  { "f28", 2112, 32 },
  { "f29", 2144, 32 },
  { "f30", 2176, 32 },
  { "f31", 2208, 32 },
  { "fcsr", 2240, 32 },
  { "fir", 2272, 32 },
  { "restart", 2304, 32 },
};

static const char *expedite_regs_mips_linux[] = { "r29", "pc", 0 };
static const char *xmltarget_mips_linux = "mips-linux.xml";

const struct target_desc *tdesc_mips_linux;

void
init_registers_mips_linux (void)
{
  static struct target_desc tdesc_mips_linux_s;
  struct target_desc *result = &tdesc_mips_linux_s;

  result->reg_defs = regs_mips_linux;
  result->num_registers = sizeof (regs_mips_linux) / sizeof (regs_mips_linux[0]);
  result->expedite_regs = expedite_regs_mips_linux;
  result->xmltarget = xmltarget_mips_linux;

  init_target_desc (result);

  tdesc_mips_linux = result;
}
