
cmake_minimum_required(VERSION 2.8)

project(TestGame)

enable_testing()


set(CMAKE_BUILD_TYPE Release)
		set(SFML_ROOT "${CMAKE_SOURCE_DIR}/SFML_LIBS/Visual")
		set(SFML_INCLUDE_DIR "${SFML_ROOT}/include")
		set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/build")
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
		message("## Project patch: " "${CMAKE_SOURCE_DIR}")
		set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ ")
		#set(LIBWINPTHREAD_DLL "${MINGW_BIN_PATH}\\libwinpthread-1.dll")


include_directories(include)
set(SOURCE_FILES
        main.cpp
        src/settings.cpp
        #include/Other/dirent.h
        src/GameStates/MenuState.cpp
        include/GameStates/MenuState.h
        src/Buttoms/BasicButton.cpp
        include/Buttoms/BasicButton.h
        src/Buttoms/Button.cpp
        include/Buttoms/Button.h
        src/GameStates/GameState.cpp
        include/GameStates/GameState.h
        src/GameStates/PlayState.cpp
        include/GameStates/PlayState.h
        src/GameStates/PauseState.cpp
        include/GameStates/PauseState.h
        src/Game.cpp
        include/Game.h
        src/Entity/Entity.cpp
        include/Entity/Entity.h
        src/Entity/Player.cpp
        include/Entity/Player.h
        src/ControllComponent/Controller.cpp
        include/ControllComponent/Controller.h
        src/ControllComponent/PlayerController.cpp
        include/ControllComponent/PlayerController.h
        src/Entity/Brick.cpp
        include/Entity/Brick.h
        src/Level/Level.cpp
        include/Level/Level.h
        src/Room/Room.cpp
        include/Room/Room.h
        src/Room/Test_Room.cpp
        include/Room/Test_Room.h
        src/Level/Test_Level.cpp
        include/Level/Test_Level.h
        include/Systems/CollisionChecker.h
        src/Systems/CollisionChecker.cpp
        include/PhysicComponent/Physics.cpp
        include/PhysicComponent/Physics.h
        src/Entity/SimpleEnemy.cpp
        include/Entity/SimpleEnemy.h
        src/ControllComponent/SimpleCreatureController.cpp
        include/ControllComponent/SimpleCreatureController.h)

set(EXECUTABLE_NAME ${PROJECT_NAME})
#Set Linker flags
add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})
    list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
#set(SFML_STATIC_LIBRARIES ON)
find_package(SFML 2 REQUIRED audio graphics window system)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_DEPENDENCIES})
else()
    message("SFML library not found. Please set SFML_ROOT.")
endif()
