﻿#file (MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/resources)
#configure_file ("my_file1.jpg" ${CMAKE_BINARY_DIR}/resources COPYONLY)
#configure_file ("my_file2.jpg" ${CMAKE_BINARY_DIR}/resources COPYONLY)
configure_file ("resized_cat.png" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file ("Side Of Monster.ttf" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file ("level_up.jpg" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file ("lost.jpg" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file ("game_over.jpg" ${CMAKE_BINARY_DIR} COPYONLY)
