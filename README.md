![Jenkins](https://img.shields.io/jenkins/build?jobUrl=https%3A%2F%2Fbuild.conativelabs.com%2Fjob%2Fsensor-lib-cur%2Fjob%2Fmaster&style=plastic)
![Jenkins Coverage](https://img.shields.io/jenkins/coverage/cobertura?jobUrl=https%3A%2F%2Fbuild.conativelabs.com%2Fjob%2Fsensor-lib-cur%2Fjob%2Fmaster%2F&style=plastic)
# CUR Sensor library
This library is made to manage the usage of a Current Sensor.

# How it works!
The cur value is measured by reading the voltage across the current sensor in millivolts, and using the formula and ampere/mv factor to get the current.

The `lib_cur_cmd` is used to recieve cmds from the *parser or any caller library* and return the required output, To read sensor data, use `cur_read` command, you can change AC freqency using `cur_set_ac_freq`, and get the current AC freq using `cur_get_ac_freq`, lastly `cur_reset` resets all the device params back to default.

Notice: `MAGIC_NUMBER_DEFAULT` is used for data integrity check.

# How to use!
Copy lib_cur_config.template.h to lib_cur_config.h and implement the sensor_mv function, and put a valid `ADC_THROUGHPUT` value.
sensor_mv should return the voltage accross the probe in millitvolts.

License
----

GNU General Public License v3.0

***Copyright (C) 2020 Conative Labs***
