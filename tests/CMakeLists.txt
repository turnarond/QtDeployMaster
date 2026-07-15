find_package(Qt6 REQUIRED COMPONENTS Core Network Test)

set(NETRELAY_DIR ${CMAKE_SOURCE_DIR}/src/tools/NetRelayTool)

add_executable(tst_nrec
    NetRelayTool/tst_nrec.cpp
    ${NETRELAY_DIR}/RelayRecorder.cpp
    ${NETRELAY_DIR}/RelayRecording.cpp
    ${NETRELAY_DIR}/RelayPlayer.cpp
)
target_include_directories(tst_nrec PRIVATE
    ${NETRELAY_DIR}
    ${CMAKE_SOURCE_DIR}/src
)
target_link_libraries(tst_nrec PRIVATE Qt6::Core Qt6::Network Qt6::Test)
add_test(NAME tst_nrec COMMAND tst_nrec)

# 让 ctest 直接运行时能找到 Qt 运行时 DLL（否则 Windows 报 0xc0000135 DLL_NOT_FOUND）
get_target_property(_qt_core_dll Qt6::Core IMPORTED_LOCATION_RELEASE)
if(NOT _qt_core_dll)
    get_target_property(_qt_core_dll Qt6::Core IMPORTED_LOCATION)
endif()
if(_qt_core_dll)
    get_filename_component(_qt_bin_dir "${_qt_core_dll}" DIRECTORY)
    set_tests_properties(tst_nrec PROPERTIES
        ENVIRONMENT_MODIFICATION "PATH=path_list_prepend:${_qt_bin_dir}")
endif()

# ============================================================
# 在线更新 — UpdateChecker 单元测试（Task 7 占位）
# ============================================================
find_library(_CURL_FOR_TEST_LIB
    NAMES libcurl_imp libcurl_imp.lib
    PATHS ${CMAKE_SOURCE_DIR}/lib
    NO_DEFAULT_PATH
)
if(_CURL_FOR_TEST_LIB AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/tst_updatechecker.cpp")
    add_executable(tst_updatechecker
        tst_updatechecker.cpp
        ${CMAKE_SOURCE_DIR}/src/updater/UpdateChecker.cpp
    )
    target_include_directories(tst_updatechecker PRIVATE
        ${CMAKE_SOURCE_DIR}/src
    )
    target_link_libraries(tst_updatechecker PRIVATE
        Qt6::Core Qt6::Network Qt6::Test
        lwserverbase lwlog lwcomm lwevent
        ${_CURL_FOR_TEST_LIB}
    )
    target_compile_definitions(tst_updatechecker PRIVATE
        DEVICEFORGE_VERSION_MAJOR=2
        DEVICEFORGE_VERSION_MINOR=1
        DEVICEFORGE_VERSION_PATCH=0
    )
    add_test(NAME tst_updatechecker COMMAND tst_updatechecker)

    # PATH 注入(避免 0xc0000135 DLL_NOT_FOUND)
    if(_qt_core_dll)
        set_tests_properties(tst_updatechecker PROPERTIES
            ENVIRONMENT_MODIFICATION "PATH=path_list_prepend:${_qt_bin_dir}")
    endif()
endif()
