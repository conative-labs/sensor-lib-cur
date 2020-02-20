#include <math.h>
#include <stdlib.h>

#include "lib_cur.h"
#ifdef TEST
#include "lib_cur_config_test.h"
#else
#include "lib_cur_config.h"
#endif

//TODO: compute it..
#define MAX_SAMPLES_PER_CYCLE 600
#define AC_FREQ_DEFAULT 50
#define SCT013_30A_VTOA_FACTOR 30
#define MAGIC_NUMBER_DEFAULT 0x65

static lib_cur_params_t *params;


static void params_set_default(void) {
	params->magic_number = MAGIC_NUMBER_DEFAULT;
	params->ac_freq = AC_FREQ_DEFAULT;
}

void lib_cur_init(lib_cur_params_t *ext_params){
  params = ext_params;
  if(params->magic_number != MAGIC_NUMBER_DEFAULT)
    params_set_default();
}

static float calculate_current_rms(int num_of_samples){
  float value;
  int i;
  float mean_res = 0;
  for(i =0 ; i < num_of_samples; i++){
    value = sensor_mv();
    mean_res += (value * value);
  }
  mean_res = sqrt(mean_res/num_of_samples);
  return ((mean_res * SCT013_30A_VTOA_FACTOR)/ 1000.0);
}


void lib_cur_cmd(lib_cur_cmd_t cmd, void *buffer)
{
  int samples_per_cycle;
  lib_cur_current_t cur_value;
  switch(cmd) {
  case cur_read:
    samples_per_cycle = ADC_THROUGHPUT_PUT / params->ac_freq;
    cur_value = calculate_current_rms(5 * samples_per_cycle);
    *(lib_cur_current_t *)buffer = cur_value;
    break;

  case cur_set_ac_freq:
    params->ac_freq = *(lib_cur_ac_freq_t *) buffer;
    break;

  case cur_get_ac_freq:
    *(lib_cur_ac_freq_t *)buffer = params->ac_freq;
    break;

  case cur_reset:
    params_set_default();
    break;
  }
}
