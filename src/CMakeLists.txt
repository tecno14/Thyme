# Build and link the DLL.
set(GAMEENGINE_INCLUDES
    editor
    game
    game/client
    game/client/gui
    game/client/input
    game/client/system/particlesystem
    game/client/videoplayer
    game/common
    game/common/audio
    game/common/compression
    game/common/ini
    game/common/modules
    game/common/rts
    game/common/system
    game/common/thing
    game/logic/object
    game/logic/scriptengine
    game/logic/system
    game/network
    platform
    platform/audio/
    platform/directx/
    platform/video/
    platform/w3dengine/common/thing
    w3d/lib
    w3d/math
    w3d/renderer
)

set(HOOKER_SRC
    hooker/dllmain.cpp
    hooker/hooker.cpp
    hooker/setupglobals_zh.cpp
)

set(HOOKER_WB_SRC
    hooker/setuphooks_wb.cpp
)

set(HOOKER_GAME_SRC
    hooker/setuphooks_zh.cpp
)

set(GAMEENGINE_SRC
    game/copyprotect.cpp
    game/force_nocd.cpp
    game/maputil.cpp
    game/weather.cpp
    game/client/display.cpp
    game/client/displaystring.cpp
    game/client/displaystringmanager.cpp
    game/client/drawgroupinfo.cpp
    game/client/gameclient.cpp
    game/client/gametext.cpp
    game/client/globallanguage.cpp
    game/client/optionpreferences.cpp
    game/client/terrainroads.cpp
    game/client/view.cpp
    game/client/water.cpp
    game/client/gui/gamefont.cpp
    game/client/input/keyboard.cpp
    game/client/input/mouse.cpp
    game/client/system/particlesystem/particle.cpp
    game/client/system/particlesystem/particleinfo.cpp
    game/client/system/particlesystem/particlesys.cpp
    game/client/system/particlesystem/particlesysinfo.cpp
    game/client/system/particlesystem/particlesysmanager.cpp
    game/client/system/particlesystem/particlesystemplate.cpp
    game/client/videoplayer/videobuffer.cpp
    game/client/videoplayer/videoplayer.cpp
    game/client/videoplayer/videostream.cpp
    game/common/bitflags.cpp
    game/common/commandline.cpp
    game/common/commandlist.cpp
    game/common/crc.cpp
    game/common/dict.cpp
    game/common/gameengine.cpp
    game/common/gamelod.cpp
    game/common/gamemain.cpp
    game/common/gamemessage.cpp
    game/common/gamemessagelist.cpp
    game/common/globaldata.cpp
    game/common/namekeygenerator.cpp
    game/common/messagestream.cpp
    game/common/multiplayersettings.cpp
    game/common/randomvalue.cpp
    game/common/registry.cpp
    game/common/staticnamekey.cpp
    game/common/terraintypes.cpp
    game/common/userpreferences.cpp
    game/common/version.cpp
    game/common/audio/audioeventinfo.cpp
    game/common/audio/audioeventrts.cpp
    game/common/audio/audiomanager.cpp
    game/common/audio/audiomisc.cpp
    game/common/audio/audiosettings.cpp
    game/common/audio/musicmanager.cpp
    game/common/audio/soundmanager.cpp
    game/common/compression/compressionmanager.cpp
    game/common/compression/refpack.cpp
    game/common/ini/ini.cpp
    game/common/ini/inidrawgroupinfo.cpp
    game/common/modules/modulefactory.cpp
    game/common/rts/buildinfo.cpp
    game/common/rts/handicap.cpp
    game/common/rts/money.cpp
    game/common/rts/player.cpp
    game/common/rts/playerlist.cpp
    game/common/rts/playertemplate.cpp
    game/common/rts/productionprerequisite.cpp
    game/common/rts/science.cpp
    game/common/rts/sidesinfo.cpp
    game/common/rts/sideslist.cpp
    game/common/rts/teamsinfo.cpp
    game/common/system/archivefile.cpp
    game/common/system/archivefilesystem.cpp
    game/common/system/asciistring.cpp
    game/common/system/cachedfileinputstream.cpp
    game/common/system/datachunk.cpp
    game/common/system/datachunktoc.cpp
    game/common/system/file.cpp
    game/common/system/filesystem.cpp
    game/common/system/functionlexicon.cpp
    game/common/system/gamememory.cpp
    game/common/system/gamememoryinit.cpp
    game/common/system/gamestate.cpp
    game/common/system/gametype.cpp
    game/common/system/geometry.cpp
    game/common/system/kindof.cpp
    game/common/system/localfile.cpp
    game/common/system/localfilesystem.cpp
    game/common/system/memblob.cpp
    game/common/system/memdynalloc.cpp
    game/common/system/mempool.cpp
    game/common/system/mempoolfact.cpp
    game/common/system/ramfile.cpp
    game/common/system/snapshot.cpp
    game/common/system/stackdump.cpp
    game/common/system/streamingarchivefile.cpp
    game/common/system/subsysteminterface.cpp
    game/common/system/unicodestring.cpp
    game/common/system/xfer.cpp
    game/common/system/xfercrc.cpp
    game/common/thing/moduleinfo.cpp
    game/common/thing/thing.cpp
    game/common/thing/thingtemplate.cpp
    game/logic/object/armortemplateset.cpp
    game/logic/object/weapon.cpp
    game/logic/object/weapontemplateset.cpp
    game/logic/scriptengine/script.cpp
    game/logic/scriptengine/scriptaction.cpp
    game/logic/scriptengine/scriptcondition.cpp
    game/logic/scriptengine/scriptgroup.cpp
    game/logic/scriptengine/scriptlist.cpp
    game/logic/scriptengine/scriptparam.cpp
    game/logic/system/rankinfo.cpp
    game/logic/system/cavesystem.cpp
    game/network/filetransfer.cpp
    game/network/lanapi.cpp
    game/network/lanapiinterface.cpp
    game/network/transport.cpp
    game/network/udp.cpp
    platform/fpusetting.cpp
    platform/w3dfilesystem.cpp
    platform/w3dfunctionlexicon.cpp
    platform/win32bigfile.cpp
    platform/win32bigfilesystem.cpp
    platform/win32localfile.cpp
    platform/win32localfilesystem.cpp
    platform/w3dengine/common/thing/w3dmodulefactory.cpp
    w3d/lib/bufffileclass.cpp
    w3d/lib/chunkio.cpp
    w3d/lib/cpudetect.cpp
    w3d/lib/critsection.cpp
    w3d/lib/ffactory.cpp
    w3d/lib/fileclass.cpp
    w3d/lib/filestraw.cpp
    w3d/lib/iniclass.cpp
    w3d/lib/multilist.cpp
    w3d/lib/nstrdup.cpp
    w3d/lib/mutex.cpp
    w3d/lib/rawfileclass.cpp
    w3d/lib/readline.cpp
    w3d/lib/refcount.cpp
    w3d/lib/straw.cpp
    w3d/lib/systimer.cpp
    w3d/lib/targa.cpp
    w3d/lib/thread.cpp
    w3d/lib/threadtrack.cpp
    w3d/lib/wwstring.cpp
    w3d/lib/hash.cpp
    w3d/math/gamemath.cpp
    w3d/math/matrix3.cpp
    w3d/math/matrix3d.cpp
    w3d/math/matrix4.cpp
    w3d/math/quaternion.cpp
    w3d/math/vp.cpp
    w3d/renderer/bitmaphandler.cpp
    w3d/renderer/colorspace.cpp
    w3d/renderer/ddsfile.cpp
    w3d/renderer/dx8caps.cpp
    w3d/renderer/dx8texman.cpp
    w3d/renderer/dx8wrapper.cpp
    w3d/renderer/mapper.cpp
    w3d/renderer/missing.cpp
    w3d/renderer/render2d.cpp
    w3d/renderer/shader.cpp
    w3d/renderer/surfaceclass.cpp
    w3d/renderer/synctextureloadtasklist.cpp
    w3d/renderer/texture.cpp
    w3d/renderer/texturebase.cpp
    w3d/renderer/textureloader.cpp
    w3d/renderer/textureloadtask.cpp
    w3d/renderer/textureloadtasklist.cpp
    w3d/renderer/thumbnail.cpp
    w3d/renderer/thumbnailmanager.cpp
    w3d/renderer/w3d.cpp
    w3d/renderer/w3dformat.cpp
)

# Game binary only source
set(GAMEENGINE_GAME_SRC
    game/main.cpp
    platform/win32gameengine.cpp
)

set(GAMEENGINE_WB_SRC
    editor/editmain.cpp
)

# Don't try and build the miles sound system when not building to link to the original game.
if(NOT STANDALONE AND NOT OPENAL_FOUND AND NOT FFMPEG_FOUND)
    list(APPEND GAMEENGINE_SRC 
    platform/audio/milesaudiofilecache.cpp
    platform/audio/milesaudiomanager.cpp
    platform/video/binkvideoplayer.cpp
    platform/video/binkvideostream.cpp)
endif()

if(DINPUT8_FOUND)
    list(APPEND GAMEENGINE_GAME_SRC
        platform/directx/dinputkeybd.cpp
    )
endif()

if(CMAKE_CONFIGURATION_TYPES)
    # Glob all the header files together to add to the project for msvc/xcode.
    # Not ideal as CMake won't notice if you add any until something else prompts a CMake run
    # but this is largely a convenience feature for MSVC/XCode users.
    file(GLOB_RECURSE GAMEENGINE_HEADERS "*.h")
    set(_GAMEENGINE_SOURCES ${GAMEENGINE_SRC} ${GAMEENGINE_GAME_SRC} ${GAMEENGINE_WB_SRC})

    if(NOT STANDALONE)
        list(APPEND _GAMEENGINE_SOURCES ${HOOKER_SRC} ${HOOKER_GAME_SRC} ${HOOKER_WB_SRC})
    endif()

    # Filter out headers from included 3rd party libraries like STLPort or gamemath.
    list(FILTER GAMEENGINE_HEADERS EXCLUDE REGEX "libs/.*")
    list(FILTER GAMEENGINE_HEADERS EXCLUDE REGEX "base/.*")

    foreach(_GAMEENGINE_SOURCE IN ITEMS ${_GAMEENGINE_SOURCES})
        get_filename_component(_GAMEENGINE_SOURCE_PATH "${_GAMEENGINE_SOURCE}" PATH)
        string(REPLACE "${CMAKE_CURRENT_SOURCE_DIR}" "" _GAMEENGINE_GROUP_PATH "${_GAMEENGINE_SOURCE_PATH}")
        string(REPLACE "/" "\\" _GAMEENGINE_GROUP_PATH "${_GAMEENGINE_GROUP_PATH}")
        source_group("Source Files\\${_GAMEENGINE_GROUP_PATH}" FILES "${_GAMEENGINE_SOURCE}")
    endforeach()

    foreach(_GAMEENGINE_HEADER IN ITEMS ${GAMEENGINE_HEADERS})
        get_filename_component(_GAMEENGINE_HEADER_PATH "${_GAMEENGINE_HEADER}" PATH)
        string(REPLACE "${CMAKE_CURRENT_SOURCE_DIR}" "" _GAMEENGINE_HGROUP_PATH "${_GAMEENGINE_HEADER_PATH}")
        string(REPLACE "/" "\\" _GAMEENGINE_HGROUP_PATH "${_GAMEENGINE_HGROUP_PATH}")
        source_group("Header Files\\${_GAMEENGINE_HGROUP_PATH}" FILES "${_GAMEENGINE_HEADER}")
    endforeach()
endif()

# Enable Thyme debug logging.
if(LOGGING)
    set(CAPTNLOG_LEVEL $<$<CONFIG:Debug>:5>$<$<CONFIG:RelWithDebInfo>:3>$<$<CONFIG:Release>:3>$<$<CONFIG:MinSizeRel>:3>)
else()
    set(CAPTNLOG_LEVEL 0)
endif()

# Enable Thyme debug assertions.
if(ASSERTIONS)
    set(CAPTNASSERT_LEVEL $<$<CONFIG:Debug>:2>$<$<CONFIG:RelWithDebInfo>:1>$<$<CONFIG:Release>:1>$<$<CONFIG:MinSizeRel>:1>)
else()
    set(CAPTNASSERT_LEVEL 0)
endif()

# Setup various included libraries
add_subdirectory(libs/captnlog EXCLUDE_FROM_ALL)

if(NOT OPENAL_FOUND AND NOT FFMPEG_FOUND)
    add_subdirectory(libs/bink EXCLUDE_FROM_ALL)
    add_subdirectory(libs/miles EXCLUDE_FROM_ALL)
endif()

if(USE_GAMEMATH)
    add_subdirectory(libs/gamemath EXCLUDE_FROM_ALL)
endif()

# Gather needed link libraries and compile defintions
list(APPEND GAME_LINK_LIBRARIES base captnlog)

if (MSVC AND NOT STANDALONE)
    list(APPEND GAME_COMPILE_OPTIONS THYME_USE_STLPORT=1)
endif()

if(STANDALONE)
    list(APPEND GAME_COMPILE_OPTIONS "ALLOW_HOOKING=")
else()
    list(APPEND GAME_COMPILE_OPTIONS "ALLOW_HOOKING=friend void Setup_Hooks()\\\;" GAME_DLL=1)

    if(NOT OPENAL_FOUND AND NOT FFMPEG_FOUND)
        list(APPEND GAME_LINK_LIBRARIES binkstub milesstub)
        list(APPEND GAME_COMPILE_OPTIONS BUILD_WITH_BINK=1 BUILD_WITH_MILES=1)
    endif()
endif()

if(WIN32 OR "${CMAKE_SYSTEM}" MATCHES "Windows")
    list(APPEND GAME_LINK_LIBRARIES winmm)
endif()

if(USE_GAMEMATH)
    list(APPEND GAME_LINK_LIBRARIES gamemath_static_lib)
    list(APPEND GAME_COMPILE_OPTIONS BUILD_WITH_GAMEMATH=1)
endif()

if(ICU_FOUND)
    list(APPEND GAME_LINK_LIBRARIES ICU::data ICU::i18n ICU::io ICU::tu ICU::uc)
    list(APPEND GAME_COMPILE_OPTIONS BUILD_WITH_ICU=1)
endif()

if(D3D8_FOUND)
    if(STANDALONE)
        list(APPEND GAME_LINK_LIBRARIES DirectX::d3d8)
    else()
        list(APPEND GAME_LINK_LIBRARIES ${DirectX_LIBRARIES})
    endif()
    list(APPEND GAME_COMPILE_OPTIONS BUILD_WITH_D3D8=1)
endif()

if(DINPUT8_FOUND)
    list(APPEND GAME_LINK_LIBRARIES ${DirectX_LIBRARIES})
    list(APPEND GAME_COMPILE_OPTIONS BUILD_WITH_DINPUT=1)
endif()

if(STANDALONE)
    add_executable(thyme ${GAMEENGINE_GAME_SRC} ${GAMEENGINE_SRC} ${GAMEENGINE_HEADERS})
    target_include_directories(thyme BEFORE PUBLIC ${GAMEENGINE_INCLUDES})
else()
    add_library(thyme SHARED ${HOOKER_SRC} ${HOOKER_GAME_SRC} ${GAMEENGINE_GAME_SRC} ${GAMEENGINE_SRC} ${GAMEENGINE_HEADERS})
    target_include_directories(thyme BEFORE PUBLIC libs/stlport libs/olddx hooker ${GAMEENGINE_INCLUDES})
    target_compile_definitions(thyme PRIVATE GAME_DLL=1)
endif()

target_link_libraries(thyme ${GAME_LINK_LIBRARIES})
target_compile_definitions(thyme PRIVATE ${GAME_COMPILE_OPTIONS})
target_compile_definitions(thyme PUBLIC $<$<CONFIG:DEBUG>:GAME_DEBUG=1>)

# Note that we don't care about which math lib we link against for worldbuilder.
# Since worldbuilder isn't multiplayer we don't need to worry about sources of indeterminancy
if(BUILD_EDITOR)
    set(CMAKE_MFC_FLAG 2) #Enable MFC
    if(STANDALONE)
        add_executable(thymeedit ${GAMEENGINE_WB_SRC} ${GAMEENGINE_SRC} ${GAMEENGINE_HEADERS})
        target_include_directories(thymeedit BEFORE PUBLIC ${GAMEENGINE_INCLUDES})
    else()
        add_library(thymeedit SHARED ${HOOKER_SRC} ${HOOKER_WB_SRC} ${GAMEENGINE_WB_SRC} ${GAMEENGINE_SRC} ${GAMEENGINE_HEADERS})
        target_include_directories(thymeedit BEFORE PUBLIC libs/stlport libs/olddx hooker ${GAMEENGINE_INCLUDES})
        target_compile_definitions(thymeedit PRIVATE GAME_DLL=1 GAME_DEBUG_STRUCTS=1 BUILD_EDITOR=1)
    endif()

    target_link_libraries(thymeedit ${GAME_LINK_LIBRARIES})
    target_compile_definitions(thymeedit PRIVATE ${GAME_COMPILE_OPTIONS})
    target_compile_definitions(thymeedit PUBLIC $<$<CONFIG:DEBUG>:GAME_DEBUG=1>)
endif()
