/*
  Copyright (C) 2020 Conative Labs
  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  You should have received a copy of the GNU General Public License
  along with this program. If not, see <https://www.gnu.org/licenses/>
*/

#ifndef lib_cur_h
#define lib_cur_h

#include <stdint.h>

typedef float lib_cur_current_t;
typedef int lib_cur_ac_freq_t;
typedef lib_cur_current_t lib_cur_reading_t;

typedef struct lib_cur_params_t {
  uint8_t magic_number; //TODO: rename it to integrity_check_number ?
  lib_cur_current_t no_current_shift;
  lib_cur_ac_freq_t ac_freq;
}lib_cur_params_t;

typedef enum lib_cur_cmd_t {
                           cur_read,
                           cur_set_ac_freq,
                           cur_get_ac_freq,
                           cur_reset,
} lib_cur_cmd_t;

void lib_cur_init(lib_cur_params_t *params_struct);
void lib_cur_cmd(lib_cur_cmd_t command, void *output_buffer);

#endif
