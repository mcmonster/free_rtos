###################################################################################################
# @author R. Matt McCann
# @brief Build script for the FreeRTOS library and its port components
# @subsection Copyright Notice
# &copy; 2014 Battelle Memorial Institute
#
# One may inject configuration into the build from a higher-order project by exporting a build
# environment called 'free_rtos_env'.
#
# One must add an inclusion path that includes the FreeRTOSConfig.h header and the desired port 
# in the exported build environment. 
#
# When linking, use the following linkage flags:
#
# -lfree_rtos -l[port_of_your_choicing]
###################################################################################################

import build_helper

# Name of the produced library
target_name = "free_rtos"

# Inclusion paths for the build
includes = [
    'include'
]

# Source files to be built
sources = Split("""
croutine.c
list.c
queue.c
tasks.c
timers.c
portable/MemMang/heap_4.c
""")

###################################################################################################
# Nothing below this should need to be edited!
###################################################################################################

###################################################################################################
# GCC ARM CM4F Build
###################################################################################################
def build_GCC_ARM_CM4F():
    env = Environment()

    try:
        Import('free_rtos_arm_cm4f_env')
        env = free_rtos_arm_cm4f_env.Clone()

    except:
        print "Skipping ARM CM4F build because 'free_rtos_arm_cm4f_env' environment " + \
              "was not exported!"
        return

    # Configure the build directory
    build_dir = '#.build/%s/arm_cm4f/' % target_name
    VariantDir(build_dir, '.')

    # Add the build settings
    env.Append(CPPPATH = includes)
    env.Append(CPPPATH = ['%s/portable/GCC/ARM_CM4F' % Dir('.').abspath])

    # Update the build settings
    my_sources = []
    my_sources.extend(sources)
    my_sources.extend(['portable/GCC/ARM_CM4F/port.c'])
    
    # Build the library
    target = env.Library(
            target = '#lib/%s_arm_cm4f' % target_name,
            source = build_helper.decorateSource(my_sources, build_dir)
        )
    env.Alias('%s_arm_cm4f' % target_name, target)

###################################################################################################
# GCC Posix Build
###################################################################################################
def build_GCC_POSIX():
    env = Environment()

    try:
        Import('free_rtos_posix_env')
        env = free_rtos_posix_env.Clone()

    except:
        print "Skipping POSIX build because 'free_rtos_posix_env' environment was not exported!"
        return    

    # Configure the build directory
    build_dir = '#.build/%s/posix/' % target_name
    VariantDir(build_dir, '.')

    # Add the build settings
    env.Append(CPPPATH = includes)
    env.Append(CPPPATH = ['%s/portable/GCC/Posix' % Dir('.').abspath])

    # Update the build settings
    my_sources = []
    my_sources.extend(sources)
    my_sources.extend(['portable/GCC/Posix/port.c'])

    # Build the library
    target = env.Library(
            target = '#lib/%s_posix' % target_name,
            source = build_helper.decorateSource(my_sources, build_dir)
        )
    env.Alias('%s_posix' % target_name, target)

build_GCC_ARM_CM4F()
build_GCC_POSIX()
