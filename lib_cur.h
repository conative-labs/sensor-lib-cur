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
