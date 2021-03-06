/* Properties of Unicode characters.
   Copyright (C) 2002, 2006-2007, 2009-2012 Free Software Foundation, Inc.
   Written by Bruno Haible <bruno@clisp.org>, 2011.

   This program is free software: you can redistribute it and/or modify it
   under the terms of the GNU Lesser General Public License as published
   by the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

#include <config.h>

/* Specification.  */
#include "unictype.h"

#include "bitmap.h"

/* Define u_property_cased table.  */
#include "pr_cased.h"

bool
uc_is_property_cased (ucs4_t uc)
{
  return bitmap_lookup (&u_property_cased, uc);
}

const uc_property_t UC_PROPERTY_CASED =
  { &uc_is_property_cased };
