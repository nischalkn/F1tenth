## This was written initially when amcl just ran, the outputs didnt make too much sense, but it seemed promising. The tf-tree made sense and amcl didnt give any crazy poses or errors ##

1. Run any bag file with the --clock option
2. launch initScanMatch.launch(make sure the use_sim_time is true)
3. launch amcl_custom_diff.launch. (make sure the use_sim_time is set and if not sure just use rosparam set use_sim ...)
4. visualise with amcl_config.rviz
5. Give the seed position and visualise the particle cloud. It will be better directed after the seed position but will still be quite erroneous. 
6. Probably next step is to make sure we have a good map and do live runs

