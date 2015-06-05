/*  RetroArch - A frontend for libretro.
 *  Copyright (C) 2011-2015 - Daniel De Matteis
 *
 *  RetroArch is free software: you can redistribute it and/or modify it under the terms
 *  of the GNU General Public License as published by the Free Software Found-
 *  ation, either version 3 of the License, or (at your option) any later version.
 *
 *  RetroArch is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 *  without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *  PURPOSE.  See the GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along with RetroArch.
 *  If not, see <http://www.gnu.org/licenses/>.
 */

#include "menu.h"
#include "menu_entries_cbs.h"

static int action_info_default(unsigned type, const char *label)
{
   menu_displaylist_info_t info = {0};
   menu_handle_t *menu    = menu_driver_get_ptr();
   if (!menu)
      return 0;
   info.list = menu->menu_list->menu_stack;
   strlcpy(info.label, "info_screen", sizeof(info.label));
   info.directory_ptr = menu->navigation.selection_ptr;

   return menu_displaylist_push_list(&info, DISPLAYLIST_HELP);
}

void menu_entries_cbs_init_bind_info(menu_file_list_cbs_t *cbs,
      const char *path, const char *label, unsigned type, size_t idx,
      const char *elem0, const char *elem1,
      uint32_t label_hash, uint32_t menu_label_hash)
{
   if (!cbs)
      return;

   cbs->action_info = action_info_default;
}
