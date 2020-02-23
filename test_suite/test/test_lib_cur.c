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

#include "unity.h"
#include "lib_cur.h"

#include "mock_lib_cur_config_test.h"

#define MAGIC_NUMBER_DEFAULT 0x65


void setUP(void)
{
}

void tearDown(void)
{
}

void test_lib_cur_init_withMagicNumberAlreadySet(void)
{
  lib_cur_params_t params;

  params.ac_freq = 13221;
  params.magic_number = MAGIC_NUMBER_DEFAULT; // mock the magic number 
  lib_cur_init(&params);

  TEST_ASSERT_EQUAL_FLOAT(13221, params.ac_freq);
}

void test_lib_cur_init_withoutMagicNumberAlreadySet(void)
{
  lib_cur_params_t params;

  params.ac_freq = 13221;
  lib_cur_init(&params);

  TEST_ASSERT_EQUAL_FLOAT(50, params.ac_freq);
}

void test_lib_cur_cmd_ReadMax(void)
{
  lib_cur_params_t params;
  lib_cur_reading_t reading;
  sensor_mv_IgnoreAndReturn(1000);
  
  lib_cur_init(&params);

  lib_cur_cmd(cur_read, &reading);

  TEST_ASSERT_EQUAL_FLOAT(30, reading);
}

void test_lib_cur_cmd_ReadZero(void)
{
  lib_cur_params_t params;
  lib_cur_reading_t reading;
  sensor_mv_IgnoreAndReturn(0);
  
  lib_cur_init(&params);

  lib_cur_cmd(cur_read, &reading);

  TEST_ASSERT_EQUAL_FLOAT(0, reading);
}

void test_lib_cur_cmd_ACFreqSetAndGet(void)
{
  lib_cur_params_t params;
  lib_cur_ac_freq_t temp = 60, temp_val;
  lib_cur_init(&params);

  lib_cur_cmd(cur_set_ac_freq, &temp);
  lib_cur_cmd(cur_get_ac_freq, &temp_val);

  TEST_ASSERT_EQUAL_FLOAT(60, temp_val);
}


void test_lib_cur_cmd_Reset(void)
{
  lib_cur_params_t params;

  lib_cur_init(&params);
  params.ac_freq = 13221;
  params.magic_number = 0x50;
  lib_cur_cmd(cur_reset, NULL);

  TEST_ASSERT_EQUAL(0x65, params.magic_number);
  TEST_ASSERT_EQUAL_FLOAT(50, params.ac_freq);
}
